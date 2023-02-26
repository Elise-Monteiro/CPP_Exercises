#pragma once
#include "Node.hpp"

#include <map>
#include <string>
#include <utility>

class ObjectNode : public Node
{
public:
    ObjectNode() { _type = NodeKind::OBJECT; }

    virtual std::string print() const override
    {
        std::string str   = "{";
        bool        first = true;
        for (auto const& set : _map)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                str += ",";
            }
            str += "\"" + set.first + "\":" + set.second->print();
        }
        return str + "}";
    }
    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); }
    int                                child_count() const { return _map.size(); }
    void insert(std::string key, NodePtr value) { _map.emplace(key, std::move(value)); }

private:
    std::map<std::string, NodePtr> _map;
};