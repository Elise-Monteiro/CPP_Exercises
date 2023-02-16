#pragma once
#include <string>
//
enum CardType {
    Monster, Spell, Trap
};

inline std::string const to_string(const CardType& cardType) {
    switch(cardType) {
        case Monster :
return "Monster";
case Spell:
return "Spell";
case Trap:
return "Trap";
default:
return "";

    }
}