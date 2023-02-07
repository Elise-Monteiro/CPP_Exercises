#pragma once
#include "Pokemon.h"
#include <memory>

// A ball where a Pokemon sleeps.
class Pokeball
{
private:
    PokemonPtr _pokemon = nullptr;

public:
    bool empty() const
    {
        return _pokemon == nullptr;
    }
    void store(PokemonPtr pokemon)
    {
        _pokemon = std::move(pokemon);
    }
    const Pokemon &pokemon() const
    {
        return *_pokemon;
    }
    PokemonPtr steal()
    {
        return std::move(_pokemon);
    }
};
