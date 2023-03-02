#include "Node.hpp"

#include "ArrayNode.hpp"
#include "IntLeaf.hpp"
#include "ObjectNode.hpp"
#include "StringLeaf.hpp"

#include <iostream>

IntLeaf* Node::as_IntLeaf()
{
    return dynamic_cast<IntLeaf*>(this);
}
StringLeaf* Node::as_StringLeaf()
{
    return dynamic_cast<StringLeaf*>(this);
}
ArrayNode* Node::as_ArrayNode()
{
    return dynamic_cast<ArrayNode*>(this);
}
ObjectNode* Node::as_ObjectNode()
{
    return dynamic_cast<ObjectNode*>(this);
}

const IntLeaf* Node::as_IntLeaf() const
{
    return dynamic_cast<const IntLeaf*>(this);
}
const StringLeaf* Node::as_StringLeaf() const
{
    return dynamic_cast<const StringLeaf*>(this);
}
const ArrayNode* Node::as_ArrayNode() const
{
    return dynamic_cast<const ArrayNode*>(this);
}
const ObjectNode* Node::as_ObjectNode() const
{
    return dynamic_cast<const ObjectNode*>(this);
}

bool Node::operator==(const Node& other) const
{
    std::cout << "Node" << std::endl;
    switch (kind())
    {
    case NodeKind::INT:
        return *(this->as_IntLeaf()) == other;
    case NodeKind::STRING:
        return *(this->as_StringLeaf()) == other;
    case NodeKind::OBJECT:
        return *(this->as_ObjectNode()) == other;
    case NodeKind::ARRAY:
        return *(this->as_ArrayNode()) == other;
    }
    return false;
}