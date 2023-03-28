#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

// pour les structures pas besoins de constructeur pour faire attribué la valeur au attribut
struct RGBA
{
public:
    uint8_t r, g, b, a;//unsigned char
};

struct RGB
{
    uint8_t r, g, b;
};

struct Luma
{
    uint8_t gray;
};