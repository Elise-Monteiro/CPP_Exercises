#pragma once
#include "Node.hpp"
#include <vector>
#include <string>

class ArrayNode : public Node
{
    public:
        ArrayNode() {
            _type = NodeKind::ARRAY;
        }

        virtual std::string print() const override{//non complete
            std::string str = "[";
            return str + "]";
        }
        NodePtr make_ptr() {
        return std::make_unique<ArrayNode>();
    }
    private:
        std::vector<Node> _array;
};