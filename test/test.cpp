#include <iostream>
#include "enum.hpp"

std::vector<MyEnum> MyEnum::_values;
const MyEnum MyEnum::TEST(MyEnum::value_type::TEST);

int main() {
	MyEnum::size();
	
	switch (MyEnum::TEST) {
		case MyEnum::value_type::TEST:
		break;
	}
	
	std::cout << MyEnum::size() << "\t" << MyEnum::TEST.ordinal() << std::endl;
	
	return 0;
}