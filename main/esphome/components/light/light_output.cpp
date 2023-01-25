#include "light_output.hpp"
#include "transformers.hpp"

namespace esphome {
namespace light {

std::unique_ptr<LightTransformer> LightOutput::create_default_transition() {
  return make_unique<LightTransitionTransformer>();
}

}  // namespace light
}  // namespace esphome
