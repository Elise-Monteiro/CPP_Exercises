#pragma once
#include "Leaf.hpp"
#include "Node.hpp"

#include <string>

class StringLeaf : public Leaf
{
public:
    StringLeaf(const std::string& string)
        : _string { string }
    {
        _type = NodeKind::STRING;
    }
    std::string                        print() const override { return "\"" + _string + "\""; }
    const std::string&                 data() const { return _string; }
    static std::unique_ptr<StringLeaf> make_ptr(const std::string& string)
    {
        return std::make_unique<StringLeaf>(string);
    }
    std::unique_ptr<IntLeaf>    as_IntLeaf() override { return nullptr; }
    std::unique_ptr<StringLeaf> as_StringLeaf() override { return std::make_unique<StringLeaf>(_string); }
    std::unique_ptr<ArrayNode>  as_ArrayNode() override { return nullptr; }
    std::unique_ptr<ObjectNode> as_ObjectNode() override { return nullptr; }

private:
    const std::string _string;
};