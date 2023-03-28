#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
public:
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
    RGBA(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a)
        : r { _r }
        , g { _g }
        , b { _b }
        , a { _a }
    {}
};

struct RGB
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    RGB(unsigned int _r, unsigned int _g, unsigned int _b)
        : r { _r }
        , g { _g }
        , b { _b }
    {}
};

struct Luma
{
    unsigned int gray;
    Luma(unsigned int _gray)
        : gray { _gray }
    {}
};