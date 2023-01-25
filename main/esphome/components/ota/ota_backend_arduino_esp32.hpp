#pragma once
#include "esphome/core/defines.hpp"
#ifdef USE_ESP32_FRAMEWORK_ARDUINO

#include "ota_component.hpp"
#include "ota_backend.hpp"

namespace esphome {
namespace ota {

class ArduinoESP32OTABackend : public OTABackend {
 public:
  OTAResponseTypes begin(size_t image_size) override;
  void set_update_md5(const char *md5) override;
  OTAResponseTypes write(uint8_t *data, size_t len) override;
  OTAResponseTypes end() override;
  void abort() override;
  bool supports_compression() override { return false; }
};

}  // namespace ota
}  // namespace esphome

#endif  // USE_ESP32_FRAMEWORK_ARDUINO
