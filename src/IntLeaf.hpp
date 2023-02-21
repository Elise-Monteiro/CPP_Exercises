#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(const int num)
        : _num { num }
    {_type = NodeKind::INT;}
    std::string print() const override { return std::to_string(_num); }
    int data() const { return _num; }

private:
    const int _num;
};