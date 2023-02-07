#pragma once
#include "Pokemon.h"
#include <vector>
#include <string>
#include <memory>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
private:
    std::vector<PokemonPtr> _pokemons;

public:
    std::vector<PokemonPtr> &pokemons()
    {
        return _pokemons;
    }
    void transfer(PokemonPtr pokemon)
    {
        _pokemons.emplace_back(std::move(pokemon));
    }
    PokemonPtr fetch(const Trainer *trainer, const std::string &name)
    {
        for (auto it = _pokemons.begin(); it != _pokemons.end(); it++)
        {
            if ((*it)->name() == name && trainer == (*it)->trainer())
            {
                auto res = std::move(*it);
                _pokemons.erase(it);
                return res;
            }
        }
        return nullptr;
    }
};
