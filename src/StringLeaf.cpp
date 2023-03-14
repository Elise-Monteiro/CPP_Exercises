#include "StringLeaf.hpp"

#include <iostream>

bool StringLeaf::operator==(const Node& other) const
{
    // std::cout << "String Node" << std::endl;
    if (_type != other.kind())
    {
        return false;
    }
    return _string == other.as_StringLeaf()->data();
}