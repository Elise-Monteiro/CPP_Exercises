#pragma once
#include "Leaf.hpp"
#include <string>

class StringLeaf : public Leaf
{
public:
    StringLeaf(const std::string& string)
        : _string { string }
    {_type = NodeKind::STRING;}
    std::string print() const override { return "\"" + _string + "\""; }
    const std::string & data() const { return _string; }

private:
    const std::string _string;
};