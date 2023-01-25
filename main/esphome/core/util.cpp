#include "esphome/core/util.hpp"
#include "esphome/core/defines.hpp"
#include "esphome/core/application.hpp"
#include "esphome/core/version.hpp"
#include "esphome/core/log.hpp"

#ifdef USE_API
#include "esphome/components/api/api_server.hpp"
#endif

#ifdef USE_MQTT
#include "esphome/components/mqtt/mqtt_client.hpp"
#endif

namespace esphome {

bool api_is_connected() {
#ifdef USE_API
  if (api::global_api_server != nullptr) {
    return api::global_api_server->is_connected();
  }
#endif
  return false;
}

bool mqtt_is_connected() {
#ifdef USE_MQTT
  if (mqtt::global_mqtt_client != nullptr) {
    return mqtt::global_mqtt_client->is_connected();
  }
#endif
  return false;
}

bool remote_is_connected() { return api_is_connected() || mqtt_is_connected(); }

}  // namespace esphome
