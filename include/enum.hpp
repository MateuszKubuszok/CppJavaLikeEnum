#ifndef ENUM_HPP_
#define ENUM_HPP_

#include <assert.h>
#include <string>
#include <vector>

/// enum_class template definition

namespace enums {

template<class C, class E>
class enum_class {
public:
  typedef E               enum_type;
  typedef std::vector<C*> values_type;
  typedef enum_class<C,E> enum_parent;

private:
  const E           _enum;
  const std::string _name;
  const std::size_t _ordinal;

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
    _name(name),
    _ordinal(size())
    { values().push_back(c); }

public:
  enum_class(
    const enum_class& e
  ) :
    _enum(e._enum),
    _name(e._name),
    _ordinal(e._ordinal)
    {}

  enum_type get() const { return _enum; }
  std::string name() const { return _name; }
  std::size_t ordinal() const { return _ordinal; }
  operator enum_type() const { return _enum; }
}; // class enum_class

} // namespace enums

/// macro helpers definitions

#define enum_begin(ename,evalues...) \
  enum class ename##_raw_values { evalues }; \
  class ename final : public enums::enum_class<ename,ename##_raw_values> { \
  public: \
    friend enums::enum_class<ename,ename##_raw_values>; \
    static const ename evalues; \
    static std::size_t size() { return enum_parent::size(); } \
    static values_type values() { return enum_parent::values(); } \
    friend ename& operator*(enum_type value) { \
      ename* returned = nullptr; \
      for (ename* checked : values()) \
        if (checked->get() == value) { \
          returned = checked; \
          break; \
        } \
      assert(returned != nullptr); \
      return *returned; \
    } \
  private:

#define enum_constructor(ename) \
  ename( \
    enum_type   enum_choice, \
    const char* name \
  ) : \
    enum_parent(this, enum_choice, name) \
    {}
#define enum_args_constructor(ename,args...) \
  ename( \
    enum_type   enum_choice, \
    const char* name, \
    args \
  ) : \
    enum_parent(this, enum_choice, name), \
    // custom properties and constructor body goes here

#define enum_end() \
  };

#define enum_instance(ename,value) \
  const ename ename::value(ename::enum_type::value, #value)
#define enum_args_instance(ename,value,args...) \
  const ename ename::value(ename::enum_type::value, #value, args)

#define case_of(ename,value) \
  case ename::enum_type::value

#endif
