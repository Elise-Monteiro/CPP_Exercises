#include "IntLeaf.hpp"

#include "Node.hpp"

#include <iostream>

bool IntLeaf::operator==(const Node& other) const
{
    std::cout << "Int Node" << std::endl;
    if (_type != other.kind())
    {
        return false;
    }
    return data() == other.as_IntLeaf()->data();
}