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

    size_t height() const override
    {
        if (_array.size() == 0)
        {
            return 0u;
        }
        size_t res = 0u;
        for (auto const& value : _array)
        {
            size_t tmp = value->height();
            if (tmp > res)
            {
                res = tmp;
            }
        }
        return res + 1u;
    }
    size_t node_count() const override
    {
        size_t res = 1u;
        for (auto const& value : _array)
        {
            res += value->node_count();
        }
        return res;
    }

    std::unique_ptr<IntLeaf>    as_IntLeaf() override { return nullptr; }
    std::unique_ptr<StringLeaf> as_StringLeaf() override { return nullptr; }
    std::unique_ptr<ArrayNode>  as_ArrayNode() override { return std::make_unique<ArrayNode>(); }
    std::unique_ptr<ObjectNode> as_ObjectNode() override { return nullptr; }

private:
    std::vector<NodePtr> _array;
};