#ifdef USE_ESP32

#include "esphome/core/hal.hpp"
#include "esphome/core/helpers.hpp"
#include "preferences.hpp"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_idf_version.h>
#include <esp_task_wdt.h>
#include <soc/rtc.h>

#if ESP_IDF_VERSION_MAJOR >= 4
#include <hal/cpu_hal.h>
#endif

#ifdef USE_ARDUINO
#include <esp32-hal.h>
#endif

void setup();
void loop();

namespace esphome {

void IRAM_ATTR HOT yield() { vPortYield(); }
uint32_t IRAM_ATTR HOT millis() { return (uint32_t)(esp_timer_get_time() / 1000ULL); }
void IRAM_ATTR HOT delay(uint32_t ms) { vTaskDelay(ms / portTICK_PERIOD_MS); }
uint32_t IRAM_ATTR HOT micros() { return (uint32_t) esp_timer_get_time(); }
void IRAM_ATTR HOT delayMicroseconds(uint32_t us) { delay_microseconds_safe(us); }
void arch_restart() {
  esp_restart();
  // restart() doesn't always end execution
  while (true) {  // NOLINT(clang-diagnostic-unreachable-code)
    yield();
  }
}

void arch_init() {
  // Enable the task watchdog only on the loop task (from which we're currently running)
#if defined(USE_ESP_IDF)
  esp_task_wdt_add(nullptr);
  // Idle task watchdog is disabled on ESP-IDF
#elif defined(USE_ARDUINO)
  enableLoopWDT();
  // Disable idle task watchdog on the core we're using (Arduino pins the task to a core)
#if defined(CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU0) && CONFIG_ARDUINO_RUNNING_CORE == 0
  disableCore0WDT();
#endif
#if defined(CONFIG_ESP_TASK_WDT_CHECK_IDLE_TASK_CPU1) && CONFIG_ARDUINO_RUNNING_CORE == 1
  disableCore1WDT();
#endif
#endif
}
void IRAM_ATTR HOT arch_feed_wdt() { esp_task_wdt_reset(); }

uint8_t progmem_read_byte(const uint8_t *addr) { return *addr; }
uint32_t arch_get_cpu_cycle_count() {
#if ESP_IDF_VERSION_MAJOR >= 4
  return cpu_hal_get_cycle_count();
#else
  uint32_t ccount;
  __asm__ __volatile__("esync; rsr %0,ccount" : "=a"(ccount));
  return ccount;
#endif
}
uint32_t arch_get_cpu_freq_hz() { return rtc_clk_apb_freq_get(); }

#ifdef USE_ESP_IDF

#endif  // USE_ESP_IDF

#ifdef USE_ARDUINO
extern "C" void init() { esp32::setup_preferences(); }
#endif  // USE_ARDUINO

}  // namespace esphome

#endif  // USE_ESP32
