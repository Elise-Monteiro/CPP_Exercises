#pragma once
#include "Node.hpp"

#include <string>

class Leaf : public Node
{
public:
    size_t height() const override { return 0u; }
    size_t node_count() const override { return 1u; }
    /*virtual std::unique_ptr<IntLeaf>    as_IntLeaf() override { return nullptr; }
    virtual std::unique_ptr<StringLeaf> as_StringLeaf() override { return nullptr; }
    virtual std::unique_ptr<ArrayNode>  as_ArrayNode() override { return nullptr; }
    virtual std::unique_ptr<ObjectNode> as_ObjectNode() override { return nullptr; }*/
};