#pragma once
#include "../lib/Unit.hpp"

#include <string>
#include <set>
#include <vector>
#include <utility>

class Kitchen
{
public:
    /*const Unit& register_unit(Unit unit)
    {
        auto [it, emplaced] = units.emplace(std::move(unit));
        return *it;
    }*/
    const Unit& register_unit(const Unit& unit)
    {
        _units.emplace_back(std::move(unit));
        return *(_units.rbegin());
    }
    const Unit* find_unit(const std::string& name) const
    {
        for (const auto& e : _units)
        {
            if (name == e.name)
            {
                return &e;
            }
        }
        return nullptr;
    }
    /*
    bool compare_unit(const Unit& unit1, const Unit& unit2)const {
        return unit1.name.compare(unit2.name);
    }*/

private:
    /*std::set<Unit, compare_unit> _units;*/
    std::vector<Unit> _units;
};
