#ifndef DEBUGGER_HPP_INCLUDED
#define DEBUGGER_HPP_INCLUDED 1
#include <iostream>
#include <string>

class Debugger
{
public:
    Debugger();
    Debugger(std::string target);
    virtual ~Debugger();

    //const std::string get_target() { return this->target; }; // not supposed to be called much

    bool debugging = false;

    bool valid_ptr(short* short_ptr, std::string name);
    bool valid_ptr(int* int_ptr, std::string name);
    bool valid_ptr(float* float_ptr, std::string name);
    void set_target(std::string target);

    // Debug Statements
    std::string inform(std::string info);
    std::string warn(std::string warning);

private:
    // Objects
    std::string target;
    const std::string nilstring = "";
};

#endif
