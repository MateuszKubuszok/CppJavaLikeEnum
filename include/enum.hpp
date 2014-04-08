#ifndef ENUM_HPP_
#define ENUM_HPP_

#include <vector>

class MyEnum {
public:
	enum class value_type;

private:
	static std::vector<MyEnum> _values;
	
	const value_type _enum;
	
	MyEnum(value_type Enum) :
		_enum(Enum)
	{
		_values.push_back(*this);
	}

public:
	static int size() { return _values.size(); }
	
	static std::vector<MyEnum> values() { return _values; }
	
	operator value_type() const { return _enum; }
	
	int ordinal() const {
		value_type currentValue = *this;
		for (size_t i = 0; i < _values.size(); i++) {
			value_type checkedValue = _values.at(i);
			if (currentValue == checkedValue)
				return i;
		}
		return -1;
	}
	
	enum class value_type { TEST };

	static const MyEnum TEST;
};

#endif
