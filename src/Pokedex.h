#pragma once
#include "Pokemon.h"
#include <string>
#include <map>
#include <vector>

class Pokedex
{
private:
    static inline std::vector<const Pokemon *> empty_list;
    std::map<std::string, std::vector<const Pokemon *>> _pokemons;

public:
    void add(const Pokemon &pokemon)
    {
        _pokemons[pokemon.name()].push_back(&pokemon);
    }
    const std::vector<const Pokemon *> &find(const std::string &name) const
    {
        const auto res = _pokemons.find(name);
        return res == _pokemons.end() ? empty_list : res->second;
    }
};
