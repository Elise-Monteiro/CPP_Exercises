#pragma once
#include <string>
//
enum CardType
{
    Monster,
    Spell,
    Trap
};

inline std::string const to_string(const CardType cardType)
{
    switch (cardType)
    {
    case Monster:
        return "Monster";
    case Spell:
        return "Spell";
    case Trap:
        return "Trap";
    default:
        return "";
    }
}

class Card
{
public:
    Card(const std::string &id, const CardType type) : _id{id}, _type{type} {}
    const std::string &get_id() const
    {
        return _id;
    }
    CardType get_type() const
    {
        return _type;
    }
    const std::string &get_name() const
    {
        return _name;
    }
    const std::string &get_description() const
    {
        return _description;
    }
    void set_name(const std::string &name)
    {
        _name = name;
    }
    void set_description(const std::string &description)
    {
        _description = description;
    }

private:
    const std::string _id;
    const CardType _type;
    std::string _name;
    std::string _description;
};