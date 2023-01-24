#pragma once
#include <string>
#include <optional>
#include <vector>
#include "Plush.hpp"

class PlushStore
{
private:
    const std::string _name;
    int _wealth = 0;
    int _size = 0;
    int _experience = 0;
    std::vector<Plush> _plush;

public:
    PlushStore(const std::string name)
        : _name{name}
    {
    }

    std::string get_name() const
    {
        return _name;
    }
    int get_wealth_amount() const
    {
        return _wealth;
    }
    int get_stock_size() const
    {
        return _size;
    }
    void loan(const int wealth)
    {
        _wealth += wealth;
    }
    int get_debt_amount() const
    {
        return _wealth + _wealth / 10;
    }
    int make_plush(const int wealth)
    {
        if (!_wealth)
        {
            return 0;
        }
        int value = (_wealth < wealth) ? _wealth : wealth;
        _wealth -= value;
        _size++;
        _experience++;
        _plush.emplace_back(value + _experience);
        return value + _experience;
    }
    std::optional<Plush> buy(const int cost)
    {
        for (std::vector<Plush>::iterator it = _plush.begin(); it != _plush.end();) // je penses posible avec un foreach comme on sort directe
        {
            if ((*it).get_cost() <= cost)
            {
                auto plush = *it;
                _size--;
                _wealth += plush.get_cost();
                _plush.erase(it); // pas besoins de mettre à jour it car on sort directe
                return std::optional<Plush>{plush};
            }
            it++; // pas besoins d'un else puisqu'on sort directe
        }
        return std::nullopt;
    }
};