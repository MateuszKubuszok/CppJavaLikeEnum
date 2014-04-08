CppJavaLikeEnum
===============

Short attempt to make a Java-style C++ enum (require C++11).

Simple enum definition
---------------

    // In .hpp file
    enum_definition_begin(SimpleEnum, Value1, Value2, Value3)
    protected:
      enum_constructor(SimpleEnum)
    
    enum_definition_end()
    
    
    // In .cpp file
    enum_instance(SimpleEnum, Value1);
    enum_instance(SimpleEnum, Value2);
    enum_instance(SimpleEnum, Value3);
    
Customized enum definition
---------------

    // In .hpp file
    enum_definition_begin(CustomizedEnum, False True)
      const bool _custom_value;

    protected:
      enum_args_constructor(CustomizedEnum, const bool value)
        _custom_value(value)
        {}

    public:
      bool custom_value() const { return _custom_value; }
    
    enum_definition_end()
    
    
     // In .cpp file
    enum_args_instance(SimpleEnum, False, false);
    enum_args_instance(SimpleEnum, True,  true);
    
Usage
---------------

    std::cout << "Size of SimpleEnum: " << SimpleEnum::size() << std::endl; 
    for(SimpleEnum* e : SimpleEnum::values())
        std::cout << e->name() << " -> " << e->ordinal() << std::endl;
    
    std::cout << "Size of CustomizedEnum: " << CustomizedEnum::size() << std::endl; 
    for(CustomizedEnum* e : CustomizedEnum::values())
        std::cout << e->name() << " -> " << e->ordinal() << ", value: " << e->value() << std::endl;
        

    
    
