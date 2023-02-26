#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class Node;
using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
public:
    NodeKind            kind() const { return _type; }
    virtual std::string print() const = 0;
    virtual ~Node()                   = default;
    virtual size_t height() const        = 0;
    virtual size_t node_count() const    = 0;

protected:
    NodeKind _type;
};