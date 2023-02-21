#pragma once
#include "Node.hpp"
#include <string>

class ObjectNode : public Node
{
    public:
        ObjectNode() {
            _type = NodeKind::OBJECT;
        }

        virtual std::string print() const override{
            return "{}";
        }
};