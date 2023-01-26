#include "esphome.hpp"

#include "led_strip.h"
#include "driver/rmt.h"
#include <driver/gpio.h>

#define EXAMPLE_CHASE_SPEED_MS (10)
#define RMT_TX_CHANNEL RMT_CHANNEL_0
#define GPIO_PIXEL_OUTPUT 19

using namespace esphome;
using namespace light;

class MyCustomLightOutput : public Component, public LightOutput {
 public:
  void setup() override {
     rmt_config_t config = RMT_DEFAULT_CONFIG_TX( (gpio_num_t) GPIO_PIXEL_OUTPUT, RMT_TX_CHANNEL);
    // set counter clock to 40MHz
    config.clk_div = 2;

    ESP_ERROR_CHECK(rmt_config(&config));
    ESP_ERROR_CHECK(rmt_driver_install(config.channel, 0, 0));

    // install ws2812 driver
    led_strip_config_t strip_config = LED_STRIP_DEFAULT_CONFIG(12, (led_strip_dev_t)config.channel);
    strip = led_strip_new_rmt_ws2812(&strip_config);
    if (!strip) {
        ets_printf("install WS2812 driver failed");
    }
    // Clear LED strip (turn off all LEDs)
    ESP_ERROR_CHECK(strip->clear(strip, 100));
    for (int j = 0; j < 12; j += 1) {
        ESP_ERROR_CHECK(strip->set_pixel(strip, j, 50, 50, 50));
    }
    // Flush RGB values to LEDs
    ESP_ERROR_CHECK(strip->refresh(strip, 100));
  }

  LightTraits get_traits() override {
    // return the traits this light supports
    auto traits = LightTraits();
    traits.set_supported_color_modes({ColorMode::RGB, ColorMode::BRIGHTNESS});
    return traits;
  }

  void write_state(LightState *state) override {
    // This will be called by the light to get a new state to be written.
    float red, green, blue;
    // use any of the provided current_values methods
    state->current_values_as_rgb(&red, &green, &blue);
    // Write red, green and blue to HW
    
    for (int j = 0; j < 12; j += 1) 
      ESP_ERROR_CHECK(strip->set_pixel(strip, j, 255U * red, 255U * green, 255U * blue));
      // Flush RGB values to LEDs
      ESP_ERROR_CHECK(strip->refresh(strip, 100));
    }
    private:
    led_strip_t *strip = NULL;
};
