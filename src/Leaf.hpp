#pragma once
#include "Node.hpp"

#include <string>

class Leaf : public Node
{
public:
    size_t height() const override { return 0u; }
    size_t node_count() const override { return 1u; }
};