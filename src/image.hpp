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

    // function = lambda donc fonction
    /*
    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)>& functor)
    {
        for (size_t j = 0; j < H; j++)
        { // ligne
            for (size_t i = 0; i < W; i++)
            { // colonne
                (*this)(i, j) = functor(i, j);
            }
        }
    }*/
};

template <typename P, size_t W, size_t H>
Image<P, W, H> operator+(const Image<P, W, H>& i1, const Image<P, W, H>& i2)
{
    Image<P, W, H> image = {};
    for (size_t j = 0; j < H; j++)
    { // ligne
        for (size_t i = 0; i < W; i++)
        { // colonne
            image(i, j) = i1(i, j) + i2(i, j);
        }
    }
    return image;
}