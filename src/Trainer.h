#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"

#include <string>
#include <array>
#include <memory>

using Equipe = std::array<Pokeball, 6>;

// A person that captures Pokemons and makes them fight.
class Trainer
{
private:
    const std::string _name;
    PC &_pc;
    Equipe _pokeballs;
    Pokedex _pokedex;

public:
    Trainer(const std::string &name, PC &pc) : _name{name}, _pc{pc}
    {
    }
    const std::string &name() const
    {
        return _name;
    }
    const Equipe &pokeballs() const
    {
        return _pokeballs;
    }
    void capture(PokemonPtr pokemonPtr)
    {
        pokemonPtr->set_trainer(*this);
        _pokedex.add(*pokemonPtr);
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                pokeball.store(std::move(pokemonPtr));
                return;
            }
        }
        _pc.transfer(std::move(pokemonPtr));
    }

    void store_in_pc(const int index)
    {
        if (index < 0 || index > 5 || _pokeballs.empty() || _pokeballs[index].empty())
        {
            return;
        }
        _pc.transfer(_pokeballs[index].steal());
    }

    void fetch_from_pc(const std::string &name)
    {
        auto res = _pc.fetch(this, name);
        if (res == nullptr)
        {
            return;
        }
        for (auto &pokeball : _pokeballs)
        {
            if (pokeball.empty())
            {
                pokeball.store(std::move(res));
                return;
            }
        }
        _pc.transfer(std::move(res));
    }
    const Pokedex &pokedex() const
    {
        return _pokedex;
    }
};
