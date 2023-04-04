#include "ex1.hpp"
#include "../lib/concatenate.hpp"

void pairwise_concatenate(std::list<std::list<int>>& list1, const std::list<std::list<int>>& list2) {//utilisé les iterator
    auto itL1 = list1.begin();
    auto itL2 = list2.begin();
    for(; itL1 != list1.end() && itL2 != list2.end(); itL1++) {
        concatenate(*itL1, *itL2);//on a le droit d'utiliser concatenate pas obliger d'avoir une seconde boucle
        itL2++;
    }
    return;
}

void pairwise_concatenate(std::list<std::list<int>>& list1, std::list<std::list<int>>&& list2) {//pas oublié d'enlevé le const puisqu'on fait un move
    auto itL1 = list1.begin();
    auto itL2 = list2.begin();
    for(; itL1 != list1.end() && itL2 != list2.end(); itL1++) {
        concatenate(*itL1, std::move(*itL2));//std::move pour pas de copie
        itL2++;
    }
    return;
}