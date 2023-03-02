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

    bool operator==(const Node& other) const override;

private:
    const std::string _string;
};