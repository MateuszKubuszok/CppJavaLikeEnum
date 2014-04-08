#include <iostream>
#include "enum.hpp"

const MyEnum MyEnum::TEST(MyEnum::enum_type::TEST);

int main() {
	MyEnum::size();
	
	switch (MyEnum::TEST) {
		case MyEnum::enum_type::TEST:
		break;
	}
	
	std::cout << MyEnum::size() << "\t" << MyEnum::TEST.ordinal() << std::endl;
	
	return 0;
}