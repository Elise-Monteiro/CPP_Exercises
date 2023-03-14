#pragma once
#include "../lib/Unit.hpp"

#include <string>
#include <set>
#include <vector>
#include <utility>

class Kitchen
{
public:
    const Unit& register_unit(Unit unit)
    {
        auto [it, emplaced] = _units.emplace(std::move(unit));
        return *it;
    }
    const Unit* find_unit(const std::string& name) const
{
    const auto it = _units.find(Unit { name });
    return it != _units.end() ? &(*it) : nullptr;
}
    /*const Unit& register_unit(const Unit& unit)
    {
        _units.emplace_back(std::move(unit));
        return *(_units.rbegin());
    }*/
    /*
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
    }*/

private:
 struct ElementNameComparer
    {
        bool compare_insensitive(const std::string& s1, const std::string& s2) const
        {
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                                [](char c1, char c2) { return tolower(c1) < tolower(c2); });
        }
        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Unit& unit, const std::string& name) const { return unit.name < name; }
        bool operator()(const std::string& name, const Unit& unit) const { return name < unit.name; }

    };
    /*bool compare_unit(const Unit& unit1, const Unit& unit2)const {
        return unit1.name.compare(unit2.name);
    }*/
    std::set<Unit, ElementNameComparer> _units;
    /*std::vector<Unit> _units;*/
};
