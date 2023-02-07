#pragma once

#include <string>
#include <memory>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
private:
    std::string _name;
    const int _id = 0;
    static inline int next_id = 0;
    const Trainer *_trainer = nullptr;

public:
    Pokemon(const std::string &name)
        : _name{name},
          _id{next_id++}
    {
    }
    Pokemon(const Pokemon &other)
        : _name{other._name},
          _id{next_id++}
    {
    }

    const std::string &name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }

    Pokemon &operator=(const Pokemon &other)
    {
        if (this == &other)
        {
            _name = other._name;
        }
        return *this;
    }

    const Trainer *trainer() const
    {
        return _trainer;
    }

    void set_trainer(const Trainer &trainer)
    {
        _trainer = &trainer;
    }
};

using PokemonPtr = std::unique_ptr<Pokemon>;
