#include <iostream>

#if false
int main()
{
    // In the following, we ask whether some line compiles.
    // We mean, if we put it here.
}
#endif

template <bool b>
class MyClass
{};

void f1(bool b)
{
    if (b)
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<false> my_class {};
        std::cout << my_class.hello() << std::endl:
        // Note that class MyClass<b> has no hello() method;
    }
}
// Q1:
//  - Does line `f1(true)` compiles ? NON
//  - Does line `f1(false)` compiles ? NON

/* ========================================================================= */
template <bool b>
void f2()
{
    if (b)
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<b> my_class {};
        std::cout << my_class.hello() << std::endl;
        // Note that class MyClass<b> has no hello() method;
    }
}

// Q2:
//  - Does line `f2<true>()` compiles ? NON
//  - Does line `f2<false>()` compiles ? NON

/* ========================================================================= */
template <bool b>
void f3()
{
    if constexpr (b) // <- difference with f2 is that `constexpr` here
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<b> my_class {};
        std::cout << my_class.hello() << std::endl;
        // Note that class MyClass<b> has no hello() method;
    }
}
// Q3:
//  - Does line `f3<true>()` compiles ? Oui
//  - Does line `f3<false>()` compiles ? Non

/* ========================================================================= */
void f4(bool b)
{
    if constexpr (b) // <- difference with f1 is that `constexpr` here //on connait pas la valeur de b à la
                     // compilation contrairement à f3 avec le template
        std::cout << "Hello world" << b << std::endl;
    else
    {
        MyClass<false> my_class {};
        std::cout << my_class.hello() << std::endl:
        // Note that class MyClass<b> has no hello() method;
    }
}

// Q4:
//  - Does line `f4(true)` compiles ? NON
//  - Does line `f3(false)` compiles ? NON

/* ========================================================================= */

// Q5: What does `if constexpr` do? What does `constexpr` mean?

// vérifie la valeur à la compilation si on la connait pas ça compile pas

/* ========================================================================= */
bool f6()
{
    return true;
}

// Q6: The line `f3<f6()>()` does not compile, why and how should the function be
// changed so that it does ?

// le compilateur peut pas savoir que f6 renvoie toujours true donc pour lui à la compilation il connait pas
// la valeur de f6 pour régler le probleme il faut faire

constexpr bool f6correction()
{
    return true;
}
// comme ça il évalue f6correction à la compilation