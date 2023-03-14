#include "ObjectNode.hpp"

#include "IntLeaf.hpp"

// #include <iostream>

bool ObjectNode::operator==(const Node& other) const
{
    if (_type != other.kind())
    {
        // std::cout << "Obj type " << std::endl;
        return false;
    }
    const auto tmp = other.as_ObjectNode();
    if (tmp->child_count() != child_count())
    {
        // std::cout << "Obj nb child" << std::endl;
        return false;
    }
    for (auto const& set : tmp->_map)
    {
        if (_map.count(set.first) == 0)
        {
            // std::cout << "Obj cle " << std::endl;
            return false;
        }
        auto value = _map.at(set.first).get();
        if (!(*value == *(set.second).get()))
        {
            // auto c = value->as_IntLeaf();
            // std::cout << "Obj pas egale " << std::to_string(c->data()) << std::endl;
            // auto c2 = set.second.get()->as_IntLeaf();
            // std::cout << "Obj pas egale " << std::to_string(c2->data()) << std::endl;
            // if (c->data() == c2->data())
            //{
            // std::cout << "Je comprends rien " << std::endl;
            //}
            return false;
        }
    }
    // std::cout << "Obj true " << std::endl;
    return true;
}