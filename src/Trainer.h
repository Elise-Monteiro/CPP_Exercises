#pragma once
#include <string>
#include <array>
#include "PC.h"
#include "Pokeball.h"
#include "Pokemon.h"
#include <memory>

using Equipe = std::array<Pokeball, 6>;

// A person that captures Pokemons and makes them fight.
class Trainer
{
private:
    const std::string _name;
    PC &_pc;
    Equipe _pokeballs;

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
        if (index < 0 || index > 5 || _pokeballs[index].empty())
        {
            return;
        }
        _pc.transfer(_pokeballs[index].steal());
    }
};
