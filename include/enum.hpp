#ifndef ENUM_HPP_
#define ENUM_HPP_

#include <vector>

class MyEnum {
	static std::vector<MyEnum*> _values;
	
public:
	enum class MyEnumType { TEST };
	
	typedef MyEnumType case_of;
		
	operator MyEnumType() const { return _enum; }
	
	static const MyEnum TEST;
	
	int ordinal() const {
		case_of currentValue = *this;
		for (size_t i = 0; i < _values.size(); i++) {
			case_of checkedValue = *(_values[i]);
			if (currentValue == checkedValue)
				return i;
		}
		return -1;
	}

	static int size() { return _values.size(); }
	
	static std::vector<MyEnum*> values() { return _values; }

private:
	const MyEnumType _enum;
	
	MyEnum(MyEnum::MyEnumType Enum) :
		_enum(Enum)
	{
		_values.push_back(this);
	}
};

std::vector<MyEnum*> MyEnum::_values;
const MyEnum MyEnum::TEST(MyEnumType::TEST);

#endif
