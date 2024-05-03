#include "debugger/Debugger.hpp"

Debugger::Debugger()
{
    this->target = "UNSET";
}

Debugger::Debugger(std::string target)
{
    this->target = target;
}

Debugger::~Debugger()
{
    target.clear();
    target.shrink_to_fit();
}

void Debugger::set_target(std::string target)
{
    this->target = target;
}

bool Debugger::valid_ptr(short* short_ptr, std::string name)
{
    if(short_ptr == nullptr)
    {
        if(debugging)
        {
            std::cout << warn("Short was a nullptr!");
            std::cout << warn(name);
        }

        return false;
    }

    return true;
}

bool Debugger::valid_ptr(int* int_ptr, std::string name)
{
    if(int_ptr == nullptr)
    {
        if(debugging)
        {
            std::cout << warn("Integer was a nullptr!");
            std::cout << warn(name);
        }

        return false;
    }

    return true;
}

bool Debugger::valid_ptr(float* float_ptr, std::string name)
{
    if(float_ptr == nullptr)
    {
        if(debugging)
        {
            std::cout << warn("Float was a nullptr!");
            std::cout << warn(name);
        }

        return false;
    }

    return true;
}

/// @brief Nearly identical to 'warn' but less urgent.
/// @param info
/// @return
std::string Debugger::inform(std::string info)
{
    std::string information;

    information += "DEBUGGER ";
    information += "for ";
    information += target;
    information += ": ";
    information += "[STATEMENT] ";
    information += info;
    information += "\n";

    if(debugging)
    {
        return information;
    }

    return nilstring; // do nothing outside of debug mode
}

/// @brief A statement generator that warns the programmer about a potential problem.
/// @param warning
/// @return
std::string Debugger::warn(std::string warning)
{
    std::string statement;

    statement += "DEBUGGER ";
    statement += "for ";
    statement += target;
    statement += ": ";
    statement += "[WARNING] ";
    statement += warning;
    statement += "\n";

    if(debugging)
    {
        return statement;
    }

    return nilstring;
}
