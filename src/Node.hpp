#pragma once
#include "InstanceCounter.hpp"
#include <string>
#include "NodeKind.hpp"

class Node : public InstanceCounter
{
    public :
        NodeKind kind() const { return _type; }
        virtual std::string print() const = 0;
        virtual ~Node() = default;
    protected:
        NodeKind _type;
};