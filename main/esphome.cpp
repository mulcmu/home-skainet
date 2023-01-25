#include "secrets.h"

// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.hpp"
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
#include "my_light.hpp"

using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace binary_sensor;
using namespace button;
using namespace text_sensor;
using namespace light;
logger::Logger *logger_logger;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace sensor;
using namespace number;
StartupTrigger *startuptrigger;
Automation<> *automation;
preferences::IntervalSyncer *preferences_intervalsyncer;
wifi_signal::WiFiSignalSensor *wifi_signal_wifisignalsensor;
adc::ADCSensor *adc_adcsensor;
sensor::MedianFilter *sensor_medianfilter;
sensor::DeltaFilter *sensor_deltafilter;
sensor::ValueRangeTrigger *sensor_valuerangetrigger;
Automation<float> *automation_2;
template_::TemplateBinarySensor *btn_volup;
template_::TemplateBinarySensor *btn_voldwn;
template_::TemplateBinarySensor *btn_set;
template_::TemplateBinarySensor *btn_play;
template_::TemplateBinarySensor *btn_mode;
template_::TemplateBinarySensor *btn_rec;
template_::TemplateBinarySensor *wake_word;
restart::RestartButton *restart_restartbutton;
wifi_info::IPAddressWiFiInfo *wifi_info_ipaddresswifiinfo;
wifi_info::SSIDWiFiInfo *wifi_info_ssidwifiinfo;
wifi_info::BSSIDWiFiInfo *wifi_info_bssidwifiinfo;
wifi_info::MacAddressWifiInfo *wifi_info_macaddresswifiinfo;
template_::TemplateNumber *voice_command;
light::AddressableLightState *light_addressablelightstate;
LambdaAction<> *lambdaaction;
LambdaAction<> *lambdaaction_2;
LambdaAction<> *lambdaaction_3;
LambdaAction<> *lambdaaction_4;
LambdaAction<> *lambdaaction_5;
LambdaAction<> *lambdaaction_6;
LambdaAction<float> *lambdaaction_7;
sensor::ValueRangeTrigger *sensor_valuerangetrigger_2;
Automation<float> *automation_3;
LambdaAction<float> *lambdaaction_8;
sensor::ValueRangeTrigger *sensor_valuerangetrigger_3;
Automation<float> *automation_4;
LambdaAction<float> *lambdaaction_9;
sensor::ValueRangeTrigger *sensor_valuerangetrigger_4;
Automation<float> *automation_5;
LambdaAction<float> *lambdaaction_10;
sensor::ValueRangeTrigger *sensor_valuerangetrigger_5;
Automation<float> *automation_6;
LambdaAction<float> *lambdaaction_11;
sensor::ValueRangeTrigger *sensor_valuerangetrigger_6;
Automation<float> *automation_7;
LambdaAction<float> *lambdaaction_12;
sensor::ValueRangeTrigger *sensor_valuerangetrigger_7;
Automation<float> *automation_8;
LambdaAction<float> *lambdaaction_13;
LambdaAction<float> *lambdaaction_14;
LambdaAction<float> *lambdaaction_15;
LambdaAction<float> *lambdaaction_16;
LambdaAction<float> *lambdaaction_17;
LambdaAction<float> *lambdaaction_18;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin;

// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

extern "C" void esphome_setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: korvo-s3
  //   platformio_options:
  //     board_build.flash_mode: dio
  //   includes:
  //   - my_light.h
  //   on_boot:
  //   - then:
  //     - lambda: !lambda |-
  //         id(btn_volup).publish_state(false);
  //       type_id: lambdaaction
  //     - lambda: !lambda |-
  //         id(btn_voldwn).publish_state(false);
  //       type_id: lambdaaction_2
  //     - lambda: !lambda |-
  //         id(btn_set).publish_state(false);
  //       type_id: lambdaaction_3
  //     - lambda: !lambda |-
  //         id(btn_play).publish_state(false);
  //       type_id: lambdaaction_4
  //     - lambda: !lambda |-
  //         id(btn_mode).publish_state(false);
  //       type_id: lambdaaction_5
  //     - lambda: !lambda |-
  //         id(btn_rec).publish_state(false);
  //       type_id: lambdaaction_6
  //     automation_id: automation
  //     trigger_id: startuptrigger
  //     priority: 600.0
  //   build_path: .esphome/build/korvo-s3
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2022.12.3



  App.pre_setup("korvo-s3", __DATE__ ", " __TIME__, false);
  // binary_sensor:
  // button:
  // text_sensor:
  // light:
  // logger:
  //   baud_rate: 115200
  //   id: logger_logger
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  logger_logger = new logger::Logger(115200, 512);
  logger_logger->set_uart_selection(logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // wifi:
  //   manual_ip:
  //     static_ip: 192.168.0.212
  //     gateway: 192.168.0.9
  //     subnet: 255.255.255.0
  //     dns1: 0.0.0.0
  //     dns2: 0.0.0.0
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   enable_btm: false
  //   enable_rrm: false
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_password'
  //     id: wifi_wifiap
  //     priority: 0.0
  //   use_address: 192.168.0.212
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.0.212");
  {
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid(WIFI_AP);
  wifi_wifiap.set_password(WIFI_PW);
  wifi_wifiap.set_manual_ip(wifi::ManualIP{
      .static_ip = network::IPAddress(192, 168, 0, 212),
      .gateway = network::IPAddress(192, 168, 0, 9),
      .subnet = network::IPAddress(255, 255, 255, 0),
      .dns1 = network::IPAddress(0, 0, 0, 0),
      .dns2 = network::IPAddress(0, 0, 0, 0),
  });
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  }
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: !secret 'esp_home_ota_pw'
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 3232
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(3232);
  ota_otacomponent->set_auth_password(WIFI_OTA_PW);
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // sensor:
  // number:
  startuptrigger = new StartupTrigger(600.0f);
  startuptrigger->set_component_source("esphome.coroutine");
  App.register_component(startuptrigger);
  automation = new Automation<>(startuptrigger);
  // esp32:
  //   board: esp32s3box
  //   variant: ESP32S3
  //   framework:
  //     version: 4.4.2
  //     sdkconfig_options: {}
  //     advanced:
  //       ignore_efuse_mac_crc: false
  //     source: ~3.40402.0
  //     platform_version: platformio/espressif32 @ 5.2.0
  //     type: esp-idf
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // sensor.wifi_signal:
  //   platform: wifi_signal
  //   name: WiFi Signal Sensor
  //   update_interval: 60s
  //   disabled_by_default: false
  //   force_update: false
  //   id: wifi_signal_wifisignalsensor
  //   unit_of_measurement: dBm
  //   accuracy_decimals: 0
  //   device_class: signal_strength
  //   state_class: measurement
  //   entity_category: diagnostic
  wifi_signal_wifisignalsensor = new wifi_signal::WiFiSignalSensor();
  App.register_sensor(wifi_signal_wifisignalsensor);
  wifi_signal_wifisignalsensor->set_name("WiFi Signal Sensor");
  wifi_signal_wifisignalsensor->set_disabled_by_default(false);
  wifi_signal_wifisignalsensor->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_signal_wifisignalsensor->set_device_class("signal_strength");
  wifi_signal_wifisignalsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  wifi_signal_wifisignalsensor->set_unit_of_measurement("dBm");
  wifi_signal_wifisignalsensor->set_accuracy_decimals(0);
  wifi_signal_wifisignalsensor->set_force_update(false);
  wifi_signal_wifisignalsensor->set_update_interval(60000);
  wifi_signal_wifisignalsensor->set_component_source("wifi_signal.sensor");
  App.register_component(wifi_signal_wifisignalsensor);
  // sensor.adc:
  //   platform: adc
  //   internal: true
  //   pin:
  //     number: 8
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     drive_strength: 20.0
  //     inverted: false
  //     id: esp32_esp32internalgpiopin
  //   attenuation: 11db
  //   name: Button ADC
  //   update_interval: 15ms
  //   id: adc_adcsensor
  //   unit_of_measurement: V
  //   accuracy_decimals: 2
  //   filters:
  //   - median:
  //       window_size: 5
  //       send_every: 5
  //       send_first_at: 1
  //     type_id: sensor_medianfilter
  //   - delta: 0.1
  //     type_id: sensor_deltafilter
  //   on_value_range:
  //   - below: 0.55
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_volup).publish_state(true);
  //       type_id: lambdaaction_7
  //     automation_id: automation_2
  //     trigger_id: sensor_valuerangetrigger
  //   - above: 0.65
  //     below: 0.92
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_voldwn).publish_state(true);
  //       type_id: lambdaaction_8
  //     automation_id: automation_3
  //     trigger_id: sensor_valuerangetrigger_2
  //   - above: 1.02
  //     below: 1.33
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_set).publish_state(true);
  //       type_id: lambdaaction_9
  //     automation_id: automation_4
  //     trigger_id: sensor_valuerangetrigger_3
  //   - above: 1.43
  //     below: 1.77
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_play).publish_state(true);
  //       type_id: lambdaaction_10
  //     automation_id: automation_5
  //     trigger_id: sensor_valuerangetrigger_4
  //   - above: 1.87
  //     below: 2.15
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_mode).publish_state(true);
  //       type_id: lambdaaction_11
  //     automation_id: automation_6
  //     trigger_id: sensor_valuerangetrigger_5
  //   - above: 2.25
  //     below: 2.56
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_rec).publish_state(true);
  //       type_id: lambdaaction_12
  //     automation_id: automation_7
  //     trigger_id: sensor_valuerangetrigger_6
  //   - above: 2.8
  //     then:
  //     - lambda: !lambda |-
  //         id(btn_volup).publish_state(false);
  //       type_id: lambdaaction_13
  //     - lambda: !lambda |-
  //         id(btn_voldwn).publish_state(false);
  //       type_id: lambdaaction_14
  //     - lambda: !lambda |-
  //         id(btn_set).publish_state(false);
  //       type_id: lambdaaction_15
  //     - lambda: !lambda |-
  //         id(btn_play).publish_state(false);
  //       type_id: lambdaaction_16
  //     - lambda: !lambda |-
  //         id(btn_mode).publish_state(false);
  //       type_id: lambdaaction_17
  //     - lambda: !lambda |-
  //         id(btn_rec).publish_state(false);
  //       type_id: lambdaaction_18
  //     automation_id: automation_8
  //     trigger_id: sensor_valuerangetrigger_7
  //   disabled_by_default: false
  //   force_update: false
  //   device_class: voltage
  //   state_class: measurement
  //   raw: false
  adc_adcsensor = new adc::ADCSensor();
  adc_adcsensor->set_update_interval(15);
  adc_adcsensor->set_component_source("adc.sensor");
  App.register_component(adc_adcsensor);
  App.register_sensor(adc_adcsensor);
  adc_adcsensor->set_name("Button ADC");
  adc_adcsensor->set_disabled_by_default(false);
  adc_adcsensor->set_internal(true);
  adc_adcsensor->set_device_class("voltage");
  adc_adcsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  adc_adcsensor->set_unit_of_measurement("V");
  adc_adcsensor->set_accuracy_decimals(2);
  adc_adcsensor->set_force_update(false);
  sensor_medianfilter = new sensor::MedianFilter(5, 5, 1);
  sensor_deltafilter = new sensor::DeltaFilter(0.1f);
  adc_adcsensor->set_filters({sensor_medianfilter, sensor_deltafilter});
  sensor_valuerangetrigger = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger);
  sensor_valuerangetrigger->set_max(0.55f);
  automation_2 = new Automation<float>(sensor_valuerangetrigger);
  // binary_sensor.template:
  //   platform: template
  //   name: Vol Up
  //   id: btn_volup
  //   disabled_by_default: false
  btn_volup = new template_::TemplateBinarySensor();
  App.register_binary_sensor(btn_volup);
  btn_volup->set_name("Vol Up");
  btn_volup->set_disabled_by_default(false);
  btn_volup->set_component_source("template.binary_sensor");
  App.register_component(btn_volup);
  // binary_sensor.template:
  //   platform: template
  //   name: Vol Down
  //   id: btn_voldwn
  //   disabled_by_default: false
  btn_voldwn = new template_::TemplateBinarySensor();
  App.register_binary_sensor(btn_voldwn);
  btn_voldwn->set_name("Vol Down");
  btn_voldwn->set_disabled_by_default(false);
  btn_voldwn->set_component_source("template.binary_sensor");
  App.register_component(btn_voldwn);
  // binary_sensor.template:
  //   platform: template
  //   name: Set
  //   id: btn_set
  //   disabled_by_default: false
  btn_set = new template_::TemplateBinarySensor();
  App.register_binary_sensor(btn_set);
  btn_set->set_name("Set");
  btn_set->set_disabled_by_default(false);
  btn_set->set_component_source("template.binary_sensor");
  App.register_component(btn_set);
  // binary_sensor.template:
  //   platform: template
  //   name: Play
  //   id: btn_play
  //   disabled_by_default: false
  btn_play = new template_::TemplateBinarySensor();
  App.register_binary_sensor(btn_play);
  btn_play->set_name("Play");
  btn_play->set_disabled_by_default(false);
  btn_play->set_component_source("template.binary_sensor");
  App.register_component(btn_play);
  // binary_sensor.template:
  //   platform: template
  //   name: Mode
  //   id: btn_mode
  //   disabled_by_default: false
  btn_mode = new template_::TemplateBinarySensor();
  App.register_binary_sensor(btn_mode);
  btn_mode->set_name("Mode");
  btn_mode->set_disabled_by_default(false);
  btn_mode->set_component_source("template.binary_sensor");
  App.register_component(btn_mode);
  // binary_sensor.template:
  //   platform: template
  //   name: Record
  //   id: btn_rec
  //   disabled_by_default: false
  btn_rec = new template_::TemplateBinarySensor();
  App.register_binary_sensor(btn_rec);
  btn_rec->set_name("Record");
  btn_rec->set_disabled_by_default(false);
  btn_rec->set_component_source("template.binary_sensor");
  App.register_component(btn_rec);
  // binary_sensor.template:
  //   platform: template
  //   name: Wake Word
  //   id: wake_word
  //   disabled_by_default: false
  wake_word = new template_::TemplateBinarySensor();
  App.register_binary_sensor(wake_word);
  wake_word->set_name("Wake Word");
  wake_word->set_disabled_by_default(false);
  wake_word->set_component_source("template.binary_sensor");
  App.register_component(wake_word);
  // button.restart:
  //   platform: restart
  //   name: Korvo S3 Restart
  //   disabled_by_default: false
  //   entity_category: config
  //   device_class: restart
  //   id: restart_restartbutton
  restart_restartbutton = new restart::RestartButton();
  restart_restartbutton->set_component_source("restart.button");
  App.register_component(restart_restartbutton);
  App.register_button(restart_restartbutton);
  restart_restartbutton->set_name("Korvo S3 Restart");
  restart_restartbutton->set_disabled_by_default(false);
  restart_restartbutton->set_entity_category(::ENTITY_CATEGORY_CONFIG);
  restart_restartbutton->set_device_class("restart");
  // text_sensor.wifi_info:
  //   platform: wifi_info
  //   ip_address:
  //     name: ESP IP Address
  //     disabled_by_default: false
  //     id: wifi_info_ipaddresswifiinfo
  //     entity_category: diagnostic
  //     update_interval: 1s
  //   ssid:
  //     name: ESP Connected SSID
  //     disabled_by_default: false
  //     id: wifi_info_ssidwifiinfo
  //     entity_category: diagnostic
  //     update_interval: 1s
  //   bssid:
  //     name: ESP Connected BSSID
  //     disabled_by_default: false
  //     id: wifi_info_bssidwifiinfo
  //     entity_category: diagnostic
  //     update_interval: 1s
  //   mac_address:
  //     name: ESP Mac Wifi Address
  //     disabled_by_default: false
  //     id: wifi_info_macaddresswifiinfo
  //     entity_category: diagnostic
  wifi_info_ipaddresswifiinfo = new wifi_info::IPAddressWiFiInfo();
  App.register_text_sensor(wifi_info_ipaddresswifiinfo);
  wifi_info_ipaddresswifiinfo->set_name("ESP IP Address");
  wifi_info_ipaddresswifiinfo->set_disabled_by_default(false);
  wifi_info_ipaddresswifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_ipaddresswifiinfo->set_update_interval(1000);
  wifi_info_ipaddresswifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_ipaddresswifiinfo);
  wifi_info_ssidwifiinfo = new wifi_info::SSIDWiFiInfo();
  App.register_text_sensor(wifi_info_ssidwifiinfo);
  wifi_info_ssidwifiinfo->set_name("ESP Connected SSID");
  wifi_info_ssidwifiinfo->set_disabled_by_default(false);
  wifi_info_ssidwifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_ssidwifiinfo->set_update_interval(1000);
  wifi_info_ssidwifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_ssidwifiinfo);
  wifi_info_bssidwifiinfo = new wifi_info::BSSIDWiFiInfo();
  App.register_text_sensor(wifi_info_bssidwifiinfo);
  wifi_info_bssidwifiinfo->set_name("ESP Connected BSSID");
  wifi_info_bssidwifiinfo->set_disabled_by_default(false);
  wifi_info_bssidwifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_bssidwifiinfo->set_update_interval(1000);
  wifi_info_bssidwifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_bssidwifiinfo);
  wifi_info_macaddresswifiinfo = new wifi_info::MacAddressWifiInfo();
  App.register_text_sensor(wifi_info_macaddresswifiinfo);
  wifi_info_macaddresswifiinfo->set_name("ESP Mac Wifi Address");
  wifi_info_macaddresswifiinfo->set_disabled_by_default(false);
  wifi_info_macaddresswifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_macaddresswifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_macaddresswifiinfo);
  // number.template:
  //   platform: template
  //   name: Voice Command ID
  //   id: voice_command
  //   optimistic: true
  //   min_value: 0.0
  //   max_value: 200.0
  //   step: 1.0
  //   disabled_by_default: false
  //   mode: AUTO
  //   update_interval: 60s
  //   initial_value: 0.0
  voice_command = new template_::TemplateNumber();
  voice_command->set_update_interval(60000);
  voice_command->set_component_source("template.number");
  App.register_component(voice_command);
  App.register_number(voice_command);
  voice_command->set_name("Voice Command ID");
  voice_command->set_disabled_by_default(false);
  voice_command->traits.set_min_value(0.0f);
  voice_command->traits.set_max_value(200.0f);
  voice_command->traits.set_step(1.0f);
  voice_command->traits.set_mode(number::NUMBER_MODE_AUTO);
  voice_command->set_optimistic(true);
  voice_command->set_initial_value(0.0f);
  // light.custom:
  //   platform: custom
  //   lambda: !lambda |-
  //     auto light_out = new MyCustomLightOutput();
  //     App.register_component(light_out);
  //     return {light_out};
  //   lights:
  //   - name: Korvo WS2811
  //     disabled_by_default: false
  //     restore_mode: RESTORE_DEFAULT_OFF
  //     gamma_correct: 2.8
  //     default_transition_length: 1s
  //     flash_transition_length: 0s
  //     id: light_addressablelightstate
  //   id: custom_customlightoutputconstructor
  custom::CustomLightOutputConstructor custom_customlightoutputconstructor = custom::CustomLightOutputConstructor([=]() -> std::vector<light::LightOutput *> {
      #line 159 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      auto light_out = new MyCustomLightOutput();
      App.register_component(light_out);
      return {light_out};
  });
  light_addressablelightstate = new light::AddressableLightState(custom_customlightoutputconstructor.get_light(0));
  App.register_light(light_addressablelightstate);
  light_addressablelightstate->set_component_source("light");
  App.register_component(light_addressablelightstate);
  light_addressablelightstate->set_name("Korvo WS2811");
  light_addressablelightstate->set_disabled_by_default(false);
  light_addressablelightstate->set_restore_mode(light::LIGHT_RESTORE_DEFAULT_OFF);
  light_addressablelightstate->set_default_transition_length(1000);
  light_addressablelightstate->set_flash_transition_length(0);
  light_addressablelightstate->set_gamma_correct(2.8f);
  light_addressablelightstate->add_effects({});
  // socket:
  //   implementation: bsd_sockets
  // network:
  //   enable_ipv6: false
  lambdaaction = new LambdaAction<>([=]() -> void {
      #line 8 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_volup->publish_state(false);
  });
  lambdaaction_2 = new LambdaAction<>([=]() -> void {
      #line 9 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_voldwn->publish_state(false);
  });
  lambdaaction_3 = new LambdaAction<>([=]() -> void {
      #line 10 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_set->publish_state(false);
  });
  lambdaaction_4 = new LambdaAction<>([=]() -> void {
      #line 11 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_play->publish_state(false);
  });
  lambdaaction_5 = new LambdaAction<>([=]() -> void {
      #line 12 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_mode->publish_state(false);
  });
  lambdaaction_6 = new LambdaAction<>([=]() -> void {
      #line 13 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_rec->publish_state(false);
  });
  automation->add_actions({lambdaaction, lambdaaction_2, lambdaaction_3, lambdaaction_4, lambdaaction_5, lambdaaction_6});
  lambdaaction_7 = new LambdaAction<float>([=](float x) -> void {
      #line 65 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_volup->publish_state(true);
  });
  automation_2->add_actions({lambdaaction_7});
  sensor_valuerangetrigger_2 = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger_2->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger_2);
  sensor_valuerangetrigger_2->set_min(0.65f);
  sensor_valuerangetrigger_2->set_max(0.92f);
  automation_3 = new Automation<float>(sensor_valuerangetrigger_2);
  lambdaaction_8 = new LambdaAction<float>([=](float x) -> void {
      #line 70 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_voldwn->publish_state(true);
  });
  automation_3->add_actions({lambdaaction_8});
  sensor_valuerangetrigger_3 = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger_3->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger_3);
  sensor_valuerangetrigger_3->set_min(1.02f);
  sensor_valuerangetrigger_3->set_max(1.33f);
  automation_4 = new Automation<float>(sensor_valuerangetrigger_3);
  lambdaaction_9 = new LambdaAction<float>([=](float x) -> void {
      #line 75 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_set->publish_state(true);
  });
  automation_4->add_actions({lambdaaction_9});
  sensor_valuerangetrigger_4 = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger_4->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger_4);
  sensor_valuerangetrigger_4->set_min(1.43f);
  sensor_valuerangetrigger_4->set_max(1.77f);
  automation_5 = new Automation<float>(sensor_valuerangetrigger_4);
  lambdaaction_10 = new LambdaAction<float>([=](float x) -> void {
      #line 80 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_play->publish_state(true);
  });
  automation_5->add_actions({lambdaaction_10});
  sensor_valuerangetrigger_5 = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger_5->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger_5);
  sensor_valuerangetrigger_5->set_min(1.87f);
  sensor_valuerangetrigger_5->set_max(2.15f);
  automation_6 = new Automation<float>(sensor_valuerangetrigger_5);
  lambdaaction_11 = new LambdaAction<float>([=](float x) -> void {
      #line 85 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_mode->publish_state(true);
  });
  automation_6->add_actions({lambdaaction_11});
  sensor_valuerangetrigger_6 = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger_6->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger_6);
  sensor_valuerangetrigger_6->set_min(2.25f);
  sensor_valuerangetrigger_6->set_max(2.56f);
  automation_7 = new Automation<float>(sensor_valuerangetrigger_6);
  lambdaaction_12 = new LambdaAction<float>([=](float x) -> void {
      #line 90 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_rec->publish_state(true);
  });
  automation_7->add_actions({lambdaaction_12});
  sensor_valuerangetrigger_7 = new sensor::ValueRangeTrigger(adc_adcsensor);
  sensor_valuerangetrigger_7->set_component_source("sensor");
  App.register_component(sensor_valuerangetrigger_7);
  sensor_valuerangetrigger_7->set_min(2.8f);
  automation_8 = new Automation<float>(sensor_valuerangetrigger_7);
  lambdaaction_13 = new LambdaAction<float>([=](float x) -> void {
      #line 94 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_volup->publish_state(false);
  });
  lambdaaction_14 = new LambdaAction<float>([=](float x) -> void {
      #line 95 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_voldwn->publish_state(false);
  });
  lambdaaction_15 = new LambdaAction<float>([=](float x) -> void {
      #line 96 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_set->publish_state(false);
  });
  lambdaaction_16 = new LambdaAction<float>([=](float x) -> void {
      #line 97 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_play->publish_state(false);
  });
  lambdaaction_17 = new LambdaAction<float>([=](float x) -> void {
      #line 98 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_mode->publish_state(false);
  });
  lambdaaction_18 = new LambdaAction<float>([=](float x) -> void {
      #line 99 "/home/ryan/esphm/ha_config/esphome/korvo-s3.yaml"
      btn_rec->publish_state(false);
  });
  automation_8->add_actions({lambdaaction_13, lambdaaction_14, lambdaaction_15, lambdaaction_16, lambdaaction_17, lambdaaction_18});
  esp32_esp32internalgpiopin = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin->set_pin(::GPIO_NUM_8);
  esp32_esp32internalgpiopin->set_inverted(false);
  esp32_esp32internalgpiopin->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin->set_flags(gpio::Flags::FLAG_INPUT);
  adc_adcsensor->set_pin(esp32_esp32internalgpiopin);
  adc_adcsensor->set_output_raw(false);
  adc_adcsensor->set_attenuation(ADC_ATTEN_DB_11);
  adc_adcsensor->set_channel(::ADC1_CHANNEL_7);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

extern "C" void esphome_loop() {
  App.loop();
}


extern "C" void esphome_setwakeword(int ww) {
   wake_word->publish_state(ww);
}

extern "C" void esphome_setvoicecommand(int cmd) {
   voice_command->publish_state((float) cmd );
}

TaskHandle_t loop_task_handle = nullptr;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

extern "C" void loop_task(void *pv_params) {
  esphome::esp32::setup_preferences();  
  esphome_setup();
  while (true) {
    esphome_loop();
  }
}

extern "C" void esphome_start() {
    xTaskCreate(loop_task, "loopTask", 8192, nullptr, 1, &loop_task_handle);  
}

