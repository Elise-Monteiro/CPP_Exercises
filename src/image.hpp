#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>
// i, j (colonne, ligne)
template <typename P, size_t W, size_t H> //
class Image
{
private:
    std::array<std::array<P, W>, H> _image;

public:
    Image() = default;
    Image(const P& pix)
    {
        for (size_t j = 0; j < H; j++)
        { // ligne
            for (size_t i = 0; i < W; i++)
            { // colonne
                _image[j][i] = pix;
            }
        }
    }
    P&       operator()(const size_t i, const size_t j) { return _image[j][i]; } // pour l'opération (x, y)
    const P& operator()(const size_t i, const size_t j) const
    {
        return _image[j][i];
    } // pour l'opération (x, y)
};