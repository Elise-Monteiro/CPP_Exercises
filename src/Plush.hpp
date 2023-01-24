#pragma once

class Plush
{
private:
    int _cost = 10;

public:
    Plush() 
    {}
    Plush(const int cost) 
        : _cost {cost}
    {}

    int get_cost() const
    {
        return _cost;
    }
    void set_cost(const int cost)
    {
        _cost = cost;
    }
};