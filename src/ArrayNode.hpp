#pragma once
#include "Node.hpp"

#include <string>
#include <vector>

class ArrayNode : public Node
{
public:
    ArrayNode() { _type = NodeKind::ARRAY; }

    virtual std::string print() const override
    { // non complete
        std::string str = "[";
        /*for (unsigned i = 0; i < _array.size(); i++)
        {
            if (i != 0)
            {
                str += ",";
            }
            str += _array[i]->print();
        }*/
        bool first = true;
        for (auto const& value : _array)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                str += ",";
            }
            str += value->print();
        }
        return str + "]";
    }
    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); }

    int child_count() const { return _array.size(); }

    void push_back(NodePtr nodePtr) { _array.push_back(std::move(nodePtr)); }

private:
    std::vector<NodePtr> _array;
};