#include "esphome.hpp"

using namespace esphome;
using namespace light;

class MyCustomLightOutput : public Component, public LightOutput {
 public:
  void setup() override {
    // This will be called by App.setup()
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
    // ...
  }
};
