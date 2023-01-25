cmake_minimum_required(VERSION 3.5)

set(EXTRA_COMPONENT_DIRS
    ../../components
    $ENV{IDF_PATH}/examples/common_components/led_strip
    )

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esphome_speech_commands)


idf_build_set_property(COMPILE_OPTIONS "-DESPHOME_LOG_LEVEL=ESPHOME_LOG_LEVEL_DEBUG" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DUSE_ESP32" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DUSE_ESP32_FRAMEWORK_ESP_IDF" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DUSE_ESP32_VARIANT_ESP32S3" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-DUSE_ESP_IDF" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-fmax-errors=0" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-error=nonnull-compare" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-nonnull-compare" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-sign-compare" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-unused-but-set-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-Wno-unused-variable" APPEND)
idf_build_set_property(COMPILE_OPTIONS "-fno-exceptions" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-Wno-incompatible-pointer-types" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-fpermissive" APPEND)


