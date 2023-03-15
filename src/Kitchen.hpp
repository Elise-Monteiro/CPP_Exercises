#pragma once
#include "../lib/Consumable.hpp"
#include "../lib/Cupboard.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Recipe.hpp"
#include "../lib/Unit.hpp"

#include <functional>
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
    /*
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

    void register_recipe(const Recipe& recipe) { _recipes.emplace(std::move(recipe)); }

    const Recipe* find_recipe(const std::string& name) const
    {
        const auto it = _recipes.find(name);
        return it != _recipes.end() ? &(*it) : nullptr;
    }*/

    // General
    std::optional<const Consumable> make_random_consumable(float f, int i) const // TODO vrai random a faire
    {
        if (_ingredients.empty())
        {
            return std::nullopt;
        }
        // return Consumable { *(_ingredients.begin()), f, i };// version set
        return Consumable { *(*(_ingredients.begin())), f, i }; // version vector
    }

    const Cupboard& get_cupboard() const { return _cupboard; }

    void store_in_cupboard(const Consumable& consumable)
    {
        _cupboard.consumables.emplace_back(std::move(consumable));
    }
    void wait_time(unsigned int time)
    {
        for (auto& e : _cupboard.consumables)
        {
            if (e.expiration_time != std::nullopt)
            {
                e.expiration_time = e.expiration_time.value() > time ? e.expiration_time.value() - time : 0;
            }
        }
    }

    float compute_quantity(const Ingredient& ingredient) const // TODO acumulate a utilisé
    {
        float res = 0;
        for (const auto& e : _cupboard.consumables)
        {
            if (e.expiration_time != std::nullopt && e.expiration_time.value() != 0 &&
                e.ingredient.get() == ingredient)
            {
                res += e.quantity;
            }
        }
        return res;
    }

    float compute_quantity(std::function<bool(const Consumable& c)> func) const
    {
        float res = 0;
        for (const auto& e : _cupboard.consumables)
        {
            if (func(e))
            {
                res += e.quantity;
            }
        }
        return res;
    }

    void tidy_up()
    {
        for (auto it1 = _cupboard.consumables.begin(); it1 != _cupboard.consumables.end();)
        {
            if ((*it1).expiration_time == 0 || (*it1).quantity == 0)
            {
                _cupboard.consumables.erase(it1);
            }
            else
            {
                for (auto it2 = _cupboard.consumables.begin(); it2 != it1; it2++)
                {
                    if (equals_lexico((*it2).ingredient.get().name, (*it1).ingredient.get().name) &&
                        (*it2).expiration_time == (*it1).expiration_time)
                    {
                        (*it2).quantity += (*it1).quantity;
                        _cupboard.consumables.erase(it1);
                        it1--;
                        break;
                    }
                }
                it1++;
            }
        }
    }

    std::map<const Ingredient*, float>
    compute_missing_quantities(const Recipe& recipe) const // TODO std::transform
    {
        std::map<const Ingredient*, float> map;
        for (const auto& r : recipe.quantity_by_ingredient)
        {
            bool  find     = false;
            float quantite = 0;
            for (const auto& c : _cupboard.consumables)
            {
                if (equals_lexico(r.first->name, c.ingredient.get().name) &&
                    c.expiration_time.value_or(1) != 0)
                {
                    quantite += c.quantity;
                }
            }
            if (quantite < r.second)
            {
                map.emplace(r.first, r.second - quantite);
            }
        }
        return map;
    }
    std::set<const Recipe*> compute_feasible_recipes() const
    {
        std::set<const Recipe*> res;
        for (const auto& recipe : _recipes)
        {
            // version set
            /*
            if (compute_missing_quantities(recipe).empty())//version set
                res.emplace(&recipe);//version set
            */
            if (compute_missing_quantities(*recipe).empty()) // version vector
                res.emplace(&(*recipe));                     // version vector
        }
        return res;
    }

    // Version vector
    const Unit& register_unit(const Unit& unit)
    {
        _units.emplace_back(std::make_unique<Unit>(unit));
        return *(_units.back());
    }

    const Unit* find_unit(const std::string& name) const
    {
        for (const auto& e : _units)
        {
            if (name == (*e).name)
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
    }
    void register_recipe(const Recipe& recipe) { _recipes.emplace_back(std::make_unique<Recipe>(recipe)); }

    const Recipe* find_recipe(const std::string& name) const
    {
        for (const auto& e : _recipes)
        {
            if (name == (*e).name)
            {
                return &(*e);
            }
        }
        return nullptr;
    }

private:
    // Version set
    /*
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

        bool operator()(const Recipe& r1, const Recipe& r2) const { return r1.name < r2.name; }
        bool operator()(const Recipe& r, const std::string& name) const { return r.name < name; }
        bool operator()(const std::string& name, const Recipe& r) const { return name < r.name; }
    };
    std::set<Unit, ElementNameComparer>       _units;
    std::set<Ingredient, ElementNameComparer> _ingredients;
    std::set<Recipe, ElementNameComparer>     _recipes;*/
    // General
    Cupboard _cupboard;
    bool     equals_lexico(const std::string& s1, const std::string& s2) const
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
    }

    // Version vector
    std::vector<std::unique_ptr<Unit>>       _units;
    std::vector<std::unique_ptr<Ingredient>> _ingredients;
    std::vector<std::unique_ptr<Recipe>>     _recipes;
};
