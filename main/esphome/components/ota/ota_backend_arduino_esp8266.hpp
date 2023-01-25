#pragma once
#include "esphome/core/defines.hpp"
#ifdef USE_ARDUINO
#ifdef USE_ESP8266

#include "ota_component.hpp"
#include "ota_backend.hpp"
#include "esphome/core/macros.hpp"

namespace esphome {
namespace ota {

class ArduinoESP8266OTABackend : public OTABackend {
 public:
  OTAResponseTypes begin(size_t image_size) override;
  void set_update_md5(const char *md5) override;
  OTAResponseTypes write(uint8_t *data, size_t len) override;
  OTAResponseTypes end() override;
  void abort() override;
#if USE_ARDUINO_VERSION_CODE >= VERSION_CODE(2, 7, 0)
  bool supports_compression() override { return true; }
#else
  bool supports_compression() override { return false; }
#endif
};

}  // namespace ota
}  // namespace esphome

#endif
#endif
