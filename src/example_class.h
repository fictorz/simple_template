#ifndef _MODULENAME_SUBMODULE_FILE_H_
#define _MODULENAME_SUBMODULE_FILE_H_

#include <cstdint>

namespace example::submodule {

class ExampleClass {
public:
  explicit ExampleClass();
  ~ExampleClass() = default;

  uint8_t bitwiseAnd(const uint8_t &leftOperand, const uint8_t &rightOperand);
};

} // namespace example::submodule

#endif //_MODULENAME_SUBMODULE_FILE_H_
