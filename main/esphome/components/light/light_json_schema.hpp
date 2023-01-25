#pragma once

#include "esphome/core/defines.hpp"

#ifdef USE_JSON

#include "esphome/components/json/json_util.hpp"
#include "light_call.hpp"
#include "light_state.hpp"

namespace esphome {
namespace light {

class LightJSONSchema {
 public:
  /// Dump the state of a light as JSON.
  static void dump_json(LightState &state, JsonObject root);
  /// Parse the JSON state of a light to a LightCall.
  static void parse_json(LightState &state, LightCall &call, JsonObject root);

 protected:
  static void parse_color_json(LightState &state, LightCall &call, JsonObject root);
};

}  // namespace light
}  // namespace esphome

#endif
