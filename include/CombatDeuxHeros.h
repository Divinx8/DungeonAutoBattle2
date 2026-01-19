#pragma once
#include "Hero.h"

class CombatDeuxHeros {
public:
    // Renvoie une référence vers le gagnant (précondition: au moins un vivant au départ)
    static Hero& duel(Hero& a, Hero& b);

private:
    static void tourAttaque(Hero& attaquant, Hero& defenseur);
};
