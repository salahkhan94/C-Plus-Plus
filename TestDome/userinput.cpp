#include <iostream>
#include <string>

class TextInput
{
public:
    std::string val;
    
    virtual void add(char c) {
        val+=c;
    }

    std::string getValue() { return val; }
    
};

class NumericInput : public TextInput { 
public:
    void add(char c){
        if(c>'/' && c< ':') val+=c;
    }
    
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    input->add('1');
    input->add('a');
    input->add('0');
    std::cout << input->getValue();
}
#endif