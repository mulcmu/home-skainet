#pragma once

#include "esphome/core/component.hpp"
#include "esphome/core/helpers.hpp"
#include "esphome/components/sensor/sensor.hpp"
#include "esphome/components/wifi/wifi_component.hpp"

namespace esphome {
namespace wifi_signal {

class WiFiSignalSensor : public sensor::Sensor, public PollingComponent {
 public:
  void update() override { this->publish_state(wifi::global_wifi_component->wifi_rssi()); }
  void dump_config() override;

  std::string unique_id() override { return get_mac_address() + "-wifisignal"; }
  float get_setup_priority() const override { return setup_priority::AFTER_WIFI; }
};

}  // namespace wifi_signal
}  // namespace esphome
