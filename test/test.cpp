#include <iostream>
#include "test.hpp"

namespace test {

enum_instance(DefEnum, TEST1);
enum_instance(DefEnum, TEST2);

enum_args_instance(ArgsEnum, TEST1, false);
enum_args_instance(ArgsEnum, TEST2, true);

}

using test::DefEnum;
using test::ArgsEnum;

int main() {
	std::cout << "DefEnum test (size: " << DefEnum::size() << ")" << std::endl;
	for (DefEnum* value : DefEnum::values()) {
		std::cout << "\tordinal: " << value->ordinal() << std::endl;
		switch (*value) {
		case DefEnum::enum_type::TEST1:
			std::cout << "\tTEST1 matched" << std::endl;
			break;
		case DefEnum::enum_type::TEST2:
			std::cout << "\tTEST2 matched" << std::endl;
			break;
		default:
			std::cout << "\tNothing matched" << std::endl;
			break;
		}
	}

	std::cout << "ArgsEnum test (size: " << ArgsEnum::size() << ")" << std::endl;
	for (ArgsEnum* value : ArgsEnum::values()) {
		std::cout << "\tordinal: " << value->ordinal() << std::endl;
		switch (*value) {
		case ArgsEnum::enum_type::TEST1:
			std::cout << "\tTEST1 matched -> " << value->value() << std::endl;
			break;
		case ArgsEnum::enum_type::TEST2:
			std::cout << "\tTEST2 matched -> " << value->value() << std::endl;
			break;
		default:
			std::cout << "\tNothing matched" << std::endl;
			break;
		}
	}
	
	return 0;
}