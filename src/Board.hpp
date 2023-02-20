#pragma once

#include <memory>
#include "Card.hpp"
#include "Monster.hpp"
#include "Spell.hpp"
#include "Trap.hpp"
#include <variant>
#include <vector>

using CardPtr = std::unique_ptr<Card>;

class Board
{
public:
    bool put(CardPtr cardPtr)
    {
        if (cardPtr == nullptr)
        {
            return false;
        }
        if (addCmp((*cardPtr).get_type()) == false)
        {
            return false;
        }
        list.emplace_back(std::move(cardPtr));
        return true;
    }

private:
    bool addCmp(CardType cardType)
    {
        switch (cardType)
        {
        case CardType::Monster:
            if (cmpMonster == 5)
            {
                return false;
            }
            cmpMonster++;
            break;
        case CardType::Spell:
            if (cmpSpell + cmpTrap == 5)
            {
                return false;
            }
            cmpSpell++;
            break;
        case CardType::Trap:
            if (cmpSpell + cmpTrap == 5)
            {
                return false;
            }
            cmpTrap++;
            break;
        }
        return true;
    }

    std::vector<CardPtr> list;
    int cmpMonster = 0;
    int cmpSpell = 0;
    int cmpTrap = 0;
};