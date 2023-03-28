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
        for (size_t i = 0; i < W; i++)
        { // colonne
            for (size_t j = 0; j < H; j++)
            { // ligne
                _image[i][j] = pix;
            }
        }
    }
    /*
        P& operator(const size_t i, const size_t j)
        { // colonne ligne
            return _image[i][j];
        }
    const P& operator(const size_t i, const size_t j) const { return _image[i][j]; }*/
};