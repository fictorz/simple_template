#include "example_class.h"

namespace example::submodule {

ExampleClass::ExampleClass() {}

uint8_t ExampleClass::bitwiseAnd(const uint8_t &leftOperand, const uint8_t &rightOperand) {
  return leftOperand & rightOperand;
}

} // namespace example::submodule
