#ifndef TEST_HPP_
#define TEST_HPP_

#include "enum.hpp"

namespace test { 

enum_begin(DefEnum, TEST1, TEST2)
protected:
  enum_constructor(DefEnum)
enum_end()

enum_begin(ArgsEnum, TEST1, TEST2)
  const bool __value;

protected:
  enum_args_constructor(ArgsEnum, const bool value)
    __value(value)
    {}

public:
  bool value() const { return __value; }
enum_end()

}

#endif
