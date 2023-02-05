#include <Pokemon.h>
#include <PC.h>

#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <utility>

TEST_CASE("A Pokemon can be put inside the PC")
{
    auto pc = PC {};

    auto        pikachu         = std::make_unique<Pokemon>("Pikachu");
    const auto* pikachu_address = pikachu.get();

    pc.transfer(std::move(pikachu));

    const auto& pokemons = pc.pokemons();
    REQUIRE(pokemons.empty() == false);
    REQUIRE(pokemons.get() == pikachu_address);
}
