#pragma once

template <int num>
constexpr int fibonacci() // faut le constexpr sinon on peut pas faire std::array<int, fibonacci<1>()>
{
    if constexpr (num < 2) // pour evité que le compilateur le genére pour tous les nombres négatifs
    {
        return 1;
    }
    else
    { // faut mettre forcement le else
        return fibonacci<num - 1>() + fibonacci<num - 2>();
    }
}

template <typename T1, typename T2>
constexpr bool content_of_same_type()
{
    return T1 == T2;
}