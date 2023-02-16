#pragma once
#include <string>
//
enum class CardType
{
    Monster,
    Spell,
    Trap
};

inline std::string const to_string(const CardType cardType)
{
    switch (cardType)
    {
    case CardType::Monster:
        return "Monster";
    case CardType::Spell:
        return "Spell";
    case CardType::Trap:
        return "Trap";
    default:
        return "";
    }
}

class Card
{
public:
    Card(const std::string &id, const CardType type)
        : Card{id, type, "", ""}
    {
    }

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

    virtual ~Card() {}

protected:
    Card(const std::string &id, const CardType type, const std::string &name, const std::string &description)
        : _id{id}, _type{type}, _name{name}, _description{description}
    {
    }

private:
    const std::string _id;
    const CardType _type;
    std::string _name;
    std::string _description;
};