#pragma once
#include <string>
#include "Card.hpp"

enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field
};

inline std::string const to_string(const SpellType spellType)
{
    switch (spellType)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    default:
        return "";
    }
}

class Spell : public Card
{
public:
    Spell(const std::string &id, const std::string &name, const SpellType &spellType)
        : Card{id, CardType::Spell, name, ""},
          _spellType{spellType}
    {
    }
    SpellType get_spell_type() const
    {
        return _spellType;
    }

private:
    const SpellType _spellType;
};