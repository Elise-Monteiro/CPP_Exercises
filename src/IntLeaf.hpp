#pragma once
#include "Leaf.hpp"
#include "Node.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(const int num)
        : _num { num }
    {
        _type = NodeKind::INT;
    }
    std::string                     print() const override { return std::to_string(_num); }
    int                             data() const { return _num; }
    static std::unique_ptr<IntLeaf> make_ptr(const int num) { return std::make_unique<IntLeaf>(num); }

private:
    const int _num;
};