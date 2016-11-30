#ifndef REFLECTION_INCLUDED
#define REFLECTION_INCLUDED

#include <string>
#include <iostream>
#include <sstream>


#define FIELDS(...) \
    std::string print() \
    { \
        std::string result ="{\n"; \
        result += dojo::print_class(std::string(#__VA_ARGS__), __VA_ARGS__); \
        result += "\n}"; \
        return result; \
    }

namespace dojo
{

std::string trim(const std::string& text)
{
    int start = 0;
    int end = text.length() - 1;
    while ( text[start] == ' ' && start < end ) ++start;
    while ( text[end] == ' ' && end > 0) --end;

    if (end < start) return std::string("");

    return text.substr(start, end - start + 1);
}

std::string print_class(std::string varName, int& value)
{
    std::stringstream result;
    result << varName << " : " << value;
    return result.str();
}

std::string print_class(std::string varName, double& value)
{
    std::stringstream result;
    result << varName << " : " << value;
    return result.str();
}

std::string print_class(std::string varName, std::string& value)
{
    std::stringstream result;
    result << varName << " : " << value;
    return result.str();
}

std::string print_class(std::string varName, bool& value)
{
    std::stringstream result;
    result << varName << " : " << (value ? "true" : "false");
    return result.str();
}

template<class HEAD>
std::string print_class(std::string varName, HEAD /*head*/)
{
    std::stringstream result;
    result << trim(varName) << " : {\n";
    result << "}";
    return result.str();
}

template<class HEAD, class ... TAIL>
std::string print_class(std::string variableNames, HEAD head, TAIL ... tail)
{
    size_t positionOfComa = variableNames.find_first_of(",");
    std::string variableName = trim(variableNames.substr(0, positionOfComa));

    std::stringstream result;
    std::string value = print_class(variableName, head);
    result << value << ",\n";

    value = print_class(variableNames.substr(positionOfComa + 1),
                        tail ... );
    result << value;

    return result.str();
}

class Reflector
{
public:
    template <class TYPE>
    std::string print_json(TYPE &data)
    {
        return data.print();
    }
};

}
#endif
