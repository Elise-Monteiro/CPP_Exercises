#include "Node.hpp"

#include "ArrayNode.hpp"
#include "IntLeaf.hpp"
#include "ObjectNode.hpp"
#include "StringLeaf.hpp"

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