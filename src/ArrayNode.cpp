#include "ArrayNode.hpp"

#include <iostream>

bool ArrayNode::operator==(const Node& other) const
{
    if (kind() != other.kind())
    {
        std::cout << "type" << std::endl;
        return false;
    }
    const auto tmp  = other.as_ArrayNode();
    int        size = child_count();
    if (size != tmp->child_count())
    {
        std::cout << "nombre fils" << std::endl;
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (!(*(_array[i].get()) == *(tmp->_array[i].get())))
        {

            std::cout << "fils " << i << std::endl;
            return false;
        }
    }
    std::cout << "array true " << std::endl;
    return true;
}