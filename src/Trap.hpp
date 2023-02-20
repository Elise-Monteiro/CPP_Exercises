#pragma once
#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter
};

inline std::string const to_string(const TrapType trapType)
{
    switch (trapType)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    default:
        return "";
    }
}

class Trap : public Card
{
public:
    Trap(const std::string &id, const std::string &name, const TrapType &trapType)
        : Card{id, CardType::Trap, name, ""},
          _trapType{trapType}
    {
    }
    TrapType get_trap_type() const
    {
        return _trapType;
    }

private:
    const TrapType _trapType;
};