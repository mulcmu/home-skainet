#pragma once
#ifdef __cplusplus
#include "esphome/core/macros.hpp"
#include "esphome/components/adc/adc_sensor.hpp"
#include "esphome/components/api/api_connection.hpp"
#include "esphome/components/api/api_frame_helper.hpp"
#include "esphome/components/api/api_noise_context.hpp"
#include "esphome/components/api/api_pb2.hpp"
#include "esphome/components/api/api_pb2_service.hpp"
#include "esphome/components/api/api_server.hpp"
#include "esphome/components/api/custom_api_device.hpp"
#include "esphome/components/api/homeassistant_service.hpp"
#include "esphome/components/api/list_entities.hpp"
#include "esphome/components/api/proto.hpp"
#include "esphome/components/api/subscribe_state.hpp"
#include "esphome/components/api/user_services.hpp"
#include "esphome/components/binary_sensor/automation.hpp"
#include "esphome/components/binary_sensor/binary_sensor.hpp"
#include "esphome/components/binary_sensor/filter.hpp"
#include "esphome/components/button/automation.hpp"
#include "esphome/components/button/button.hpp"
#include "esphome/components/custom/light/custom_light_output.hpp"
#include "esphome/components/esp32/gpio.hpp"
#include "esphome/components/esp32/preferences.hpp"
#include "esphome/components/light/addressable_light.hpp"
#include "esphome/components/light/addressable_light_effect.hpp"
#include "esphome/components/light/addressable_light_wrapper.hpp"
#include "esphome/components/light/automation.hpp"
#include "esphome/components/light/base_light_effects.hpp"
#include "esphome/components/light/color_mode.hpp"
#include "esphome/components/light/esp_color_correction.hpp"
#include "esphome/components/light/esp_color_view.hpp"
#include "esphome/components/light/esp_hsv_color.hpp"
#include "esphome/components/light/esp_range_view.hpp"
#include "esphome/components/light/light_call.hpp"
#include "esphome/components/light/light_color_values.hpp"
#include "esphome/components/light/light_effect.hpp"
#include "esphome/components/light/light_json_schema.hpp"
#include "esphome/components/light/light_output.hpp"
#include "esphome/components/light/light_state.hpp"
#include "esphome/components/light/light_traits.hpp"
#include "esphome/components/light/light_transformer.hpp"
#include "esphome/components/light/transformers.hpp"
#include "esphome/components/logger/logger.hpp"
#include "esphome/components/md5/md5.hpp"
#include "esphome/components/mdns/mdns_component.hpp"
#include "esphome/components/network/ip_address.hpp"
#include "esphome/components/network/util.hpp"
#include "esphome/components/number/automation.hpp"
#include "esphome/components/number/number.hpp"
#include "esphome/components/number/number_call.hpp"
#include "esphome/components/number/number_traits.hpp"
#include "esphome/components/ota/automation.hpp"
#include "esphome/components/ota/ota_backend.hpp"
#include "esphome/components/ota/ota_backend_arduino_esp32.hpp"
#include "esphome/components/ota/ota_backend_arduino_esp8266.hpp"
#include "esphome/components/ota/ota_backend_arduino_rp2040.hpp"
#include "esphome/components/ota/ota_backend_esp_idf.hpp"
#include "esphome/components/ota/ota_component.hpp"
#include "esphome/components/preferences/syncer.hpp"
#include "esphome/components/restart/button/restart_button.hpp"
#include "esphome/components/sensor/automation.hpp"
#include "esphome/components/sensor/filter.hpp"
#include "esphome/components/sensor/sensor.hpp"
#include "esphome/components/socket/headers.hpp"
#include "esphome/components/socket/socket.hpp"
#include "esphome/components/template/binary_sensor/template_binary_sensor.hpp"
#include "esphome/components/template/number/template_number.hpp"
#include "esphome/components/text_sensor/automation.hpp"
#include "esphome/components/text_sensor/filter.hpp"
#include "esphome/components/text_sensor/text_sensor.hpp"
#include "esphome/components/voltage_sampler/voltage_sampler.hpp"
#include "esphome/components/wifi/wifi_component.hpp"
#include "esphome/components/wifi_info/wifi_info_text_sensor.hpp"
#include "esphome/components/wifi_signal/wifi_signal_sensor.hpp"
#include "esphome/core/application.hpp"
#include "esphome/core/automation.hpp"
#include "esphome/core/base_automation.hpp"
#include "esphome/core/color.hpp"
#include "esphome/core/component.hpp"
#include "esphome/core/component_iterator.hpp"
#include "esphome/core/controller.hpp"
#include "esphome/core/datatypes.hpp"
#include "esphome/core/defines.hpp"
#include "esphome/core/entity_base.hpp"
#include "esphome/core/gpio.hpp"
#include "esphome/core/hal.hpp"
#include "esphome/core/helpers.hpp"
#include "esphome/core/log.hpp"
#include "esphome/core/macros.hpp"
#include "esphome/core/optional.hpp"
#include "esphome/core/preferences.hpp"
#include "esphome/core/scheduler.hpp"
#include "esphome/core/util.hpp"
#include "esphome/core/version.hpp"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void esphome_loop();
void esphome_setup();
void esphome_setwakeword(int ww);
void esphome_setvoicecommand(int cmd);
void esphome_start();

#ifdef __cplusplus
}
#endif


