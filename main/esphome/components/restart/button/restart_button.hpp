#pragma once

#include "esphome/components/button/button.hpp"
#include "esphome/core/component.hpp"

namespace esphome {
namespace restart {

class RestartButton : public button::Button, public Component {
 public:
  void dump_config() override;

 protected:
  void press_action() override;
};

}  // namespace restart
}  // namespace esphome
