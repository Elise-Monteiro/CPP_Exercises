#pragma once
#include <string>
#include <sstream>
#include "PlushStore.hpp"

class Kid
{
private:
    const std::string _name;
    int _money;

public:
    Kid(const std::string name, const int money)
        : _name{name}, _money{money}

    {
    }

    std::string get_name() const
    {
        return _name;
    }
    int get_money() const
    {
        return _money;
    }
    void buy_plush(PlushStore &plush_store)
    {
        auto plush = plush_store.buy(_money);
        if (plush != std::nullopt)
        {
            _money -= plush->get_cost();
        }
    }
};

std::ostream &operator<<(std::ostream &stream, const Kid &kid)
{
    return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
}