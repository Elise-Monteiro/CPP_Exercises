#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

// pour les structures pas besoins de constructeur pour faire attribué la valeur au attribut
struct RGBA
{
public:
    unsigned int r, g, b, a;
};

struct RGB
{
    unsigned int r, g, b;
};

struct Luma
{
    unsigned int gray;
};