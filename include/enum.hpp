#ifndef ENUM_HPP_
#define ENUM_HPP_

#include <string>
#include <vector>

/// enum_class template definition

template<class C, class E>
class enum_class {
public:
	typedef E               enum_type;
	typedef std::vector<C*> values_type; 

private:
	const E           _enum;
	const std::string _name;

protected:
	static values_type& values() {
		static values_type instance;
		return instance;
	}

	static std::size_t size() {
		return values().size();
	}

	enum_class(
		C*          c,
		E           e,
		const char* name
	) :
		_enum(e),
		_name(name)
		{ values().push_back(c); }

public:
	enum_class(
		const enum_class& e
	) :
		_enum(e._enum),
		_name(e._name)
		{}

	std::string name() const { return _name; }

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

/// macro helpers definitions

#define enum_definition_begin(current_type,values...) \
	enum class current_type##_values_ { values }; \
	class current_type final : public enum_class<current_type,current_type##_values_> { \
	public: \
		friend enum_class; \
		static const current_type values; \
	private:

#define enum_constructor(current_type) \
	current_type(enum_type enum_choice, const char* name) : enum_class(this, enum_choice, name) {}
#define enum_args_constructor(current_type,args...) \
	current_type(enum_type enum_choice, const char* name, args) : enum_class(this, enum_choice, name),

#define enum_definition_end() \
	public: \
		static std::size_t size() { return enum_class::size(); } \
	 	static values_type values() { return enum_class::values(); } \
	};

#define enum_instance(current_type,value) \
	const current_type current_type::value(current_type::enum_type::value, #value);
#define enum_args_instance(current_type,value,args...) \
	const current_type current_type::value(current_type::enum_type::value, #value, args);

#endif
