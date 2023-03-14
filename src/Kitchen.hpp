#pragma once
#include "../lib/Consumable.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <memory>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <vector>

class Kitchen
{
public:
    // Version set
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

    const Ingredient& register_ingredient(Ingredient ingredient)
    {
        auto [it, emplaced] = _ingredients.emplace(std::move(ingredient));
        return *it;
    }
    const Ingredient* find_ingredient(const std::string& name) const
    {
        const auto it = _ingredients.find(name);
        return it != _ingredients.end() ? &(*it) : nullptr;
    }

    std::optional<const Consumable> make_random_consumable(float f, int i)
    {
        if (_ingredients.empty())
        {
            return std::nullopt;
        }
        return Consumable { *(_ingredients.begin()), f, i };
    }
    // Version vector
    /*const Unit& register_unit(const Unit& unit)
    {
        _units.emplace_back(std::make_unique<Unit>(unit));
        return *(_units.back());
    }

    const Unit* find_unit(const std::string& name) const
    {
        for (const auto& e : _units)
        {
            if (equals_lexico(name, (*e).name))
            {
                return &(*e);
            }
        }
        return nullptr;
    }

    const Ingredient& register_ingredient(const Ingredient& ingredient)
    {
        _ingredients.emplace_back(std::make_unique<Ingredient>(ingredient));
        return *(_ingredients.back());
    }

    const Ingredient* find_ingredient(const std::string& name) const
    {
        for (const auto& e : _ingredients)
        {
            if (equals_lexico(name, (*e).name)) // ==  suffit pas car "test" doit être egal à "Test"
            {
                return &(*e);
            }
        }
        return nullptr;
    }*/

private:
    struct ElementNameComparer
    {
        using is_transparent = bool; // besoin pour pouvoir faire find(name) et non find(Unit{name})

        bool compare_insensitive(const std::string& s1, const std::string& s2) const
        {
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                                [](char c1, char c2) { return tolower(c1) < tolower(c2); });
        }
        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Unit& u, const std::string& name) const { return u.name < name; }
        bool operator()(const std::string& name, const Unit& u) const { return name < u.name; }
        bool operator()(const Ingredient& u1, const Ingredient& u2) const
        {
            return compare_insensitive(u1.name, u2.name);
        }
        bool operator()(const Ingredient& u, const std::string& name) const
        {
            return compare_insensitive(u.name, name);
        }
        bool operator()(const std::string& name, const Ingredient& u) const
        {
            return compare_insensitive(name, u.name);
        }
    };
    std::set<Unit, ElementNameComparer>       _units;
    std::set<Ingredient, ElementNameComparer> _ingredients;
    /*std::vector<std::unique_ptr<Unit>>       _units;
    std::vector<std::unique_ptr<Ingredient>> _ingredients;
    bool                                     equals_lexico(const std::string& s1, const std::string& s2) const
    {
        if (s1.length() != s2.length())
        {
            return false;
        }
        for (size_t i = 0; i < s1.length(); i++)
        {
            if (tolower(s1.at(0)) != tolower(s2.at(0)))
            {
                return false;
            }
        }
        return true;
    }*/
};
