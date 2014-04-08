#include <iostream>
#include "enum.hpp"

int main() {
	MyEnum::size();
	
	switch (MyEnum::TEST) {
		case MyEnum::case_of::TEST:
		break;
	}
	
	std::cout << MyEnum::size() << "\t" << MyEnum::TEST.ordinal() << std::endl;
	
	return 0;
}