#include "restart_button.hpp"
#include "esphome/core/application.hpp"
#include "esphome/core/hal.hpp"
#include "esphome/core/log.hpp"

namespace esphome {
namespace restart {

static const char *const TAG = "restart.button";

void RestartButton::press_action() {
  ESP_LOGI(TAG, "Restarting device...");
  // Let MQTT settle a bit
  delay(100);  // NOLINT
  App.safe_reboot();
}
void RestartButton::dump_config() { LOG_BUTTON("", "Restart Button", this); }

}  // namespace restart
}  // namespace esphome
