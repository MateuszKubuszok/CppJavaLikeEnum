#include <iostream>
#include "test.hpp"

namespace test {

enum_instance(DefEnum, TEST1);
enum_instance(DefEnum, TEST2);

enum_args_instance(ArgsEnum, TEST1, false);
enum_args_instance(ArgsEnum, TEST2, true);

}

using std::cout;
using std::endl;
using test::DefEnum;
using test::ArgsEnum;

int main() {
  cout << "DefEnum test (size: " << DefEnum::size() << ")" << endl;
  for (DefEnum* value : DefEnum::values()) {
    cout << "\tordinal: " << value->ordinal() << endl;
    switch (*value) {
    case_of(DefEnum,TEST1):
    case_of(DefEnum,TEST2):
      cout << "\t" << value->name() << " matched" << endl;
      break;
    default:
      cout << "\tNothing matched" << endl;
      break;
    }
  }

  cout << "ArgsEnum test (size: " << ArgsEnum::size() << ")" << endl;
  for (ArgsEnum* value : ArgsEnum::values()) {
    cout << "\tordinal: " << value->ordinal() << endl;
    switch (*value) {
    case_of(ArgsEnum,TEST1):
    case_of(ArgsEnum,TEST2):
      cout << "\t" << value->name() << " matched -> " << value->value() << endl;
      break;
    default:
      cout << "\tNothing matched" << endl;
      break;
    }
  }
  
  return 0;
}