#ifndef ENUM_HPP_
#define ENUM_HPP_

#include <vector>

template<class C, class E>
class enum_class {
public:
	typedef E               enum_type;
	typedef std::vector<C*> values_type; 

private:
	const E _enum;

protected:
	static values_type& values() {
		static values_type instance;
		return instance;
	}

	static std::size_t size() {
		return values().size();
	}

	enum_class(
		C* c,
		E  e
	) :
		_enum(e)
		{ values().push_back(c); }

public:
	enum_class(
		const enum_class& e
	) :
		_enum(e._enum)
		{}

	int ordinal() const {
		E currentValue = *this;
		for (size_t i = 0; i < size(); i++) {
			E checkedValue = *(values().at(i));
			if (currentValue == checkedValue)
				return i;
		}
		return -1;
	}

	operator enum_type() const { return _enum; }
};

enum class MyEnumType { TEST };
class MyEnum : public enum_class<MyEnum, MyEnumType> {
	friend enum_class;

protected:
	MyEnum(
		MyEnumType e
	) : 
		enum_class(this, e)
		{}

public:
	static const MyEnum TEST;

	static std::size_t size() { return enum_class::size(); }
	
 	static values_type values() { return enum_class::values(); }
};

#endif
