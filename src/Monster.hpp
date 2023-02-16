#pragma once
#include <string>
#include "Card.hpp"

enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind
};

inline std::string const to_symbol(const Attribute attributeType)
{
    switch (attributeType)
    {
    case Attribute::Dark:
        return u8"闇";
    case Attribute::Divine:
        return u8"神";
    case Attribute::Earth:
        return u8"地";
    case Attribute::Fire:
        return u8"炎";
    case Attribute::Light:
        return u8"光";
    case Attribute::Water:
        return u8"水";
    case Attribute::Wind:
        return u8"風";
    default:
        return "";
    }
}
// Monster { "DUSA-FR100", "Magicien Sombre", Attribute::Dark, "Magicien", atk, def };
class Monster : public Card
{
public:
    Monster(const std::string &id, const std::string &name, const Attribute attribute, const std::string &monsterType, const int atk, const int def)
        : Card{id, CardType::Monster, name, ""},
          _attribute{attribute},
          _monsterType{monsterType},
          _atk{atk},
          _def{def}
    {
    }
    Attribute get_attribute() const
    {
        return _attribute;
    }

    int get_atk() const
    {
        return _atk;
    }

    int get_def() const
    {
        return _def;
    }

private:
    const Attribute _attribute;
    const std::string _monsterType;
    const int _atk;
    const int _def;
};