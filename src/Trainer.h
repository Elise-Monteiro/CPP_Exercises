#pragma once
#include <string>
#include <array>
#include "PC.h"
#include "Pokeball.h"

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
};
