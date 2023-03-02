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
    void   insert(std::string key, NodePtr value) { _map.emplace(key, std::move(value)); }
    size_t height() const override
    {
        if (_map.size() == 0)
        {
            return 0u;
        }
        size_t res = 0u;
        for (auto const& set : _map)
        {
            size_t tmp = set.second->height();
            if (tmp > res)
            {
                res = tmp;
            }
        }
        return res + 1u;
    }
    size_t node_count() const override
    {
        size_t res = 1u;
        for (auto const& set : _map)
        {
            res += set.second->node_count();
        }
        return res;
    }

    bool  has_child(const std::string& key) const { return _map.count(key) != 0; }
    Node* at(const std::string& key) const { return has_child(key) ? _map.at(key).get() : nullptr; }

    bool operator==(const Node& other) const override;

private:
    std::map<std::string, NodePtr> _map;
};