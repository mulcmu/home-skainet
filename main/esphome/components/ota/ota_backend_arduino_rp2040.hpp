#pragma once
#include "esphome/core/defines.hpp"
#ifdef USE_ARDUINO
#ifdef USE_RP2040

#include "esphome/core/macros.hpp"
#include "ota_backend.hpp"
#include "ota_component.hpp"

namespace esphome {
namespace ota {

class ArduinoRP2040OTABackend : public OTABackend {
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

#endif  // USE_RP2040
#endif  // USE_ARDUINO
