#include "Archer.h"
#include <algorithm>
#include <cstdlib>

bool Archer::esquive() const {
    // petite chance basée sur vitesse (plafond 25%)
    int chance = vitesse / 4;
    chance = std::min(chance, 25);
    return (rand() % 100) < chance;
}

int Archer::calculerDegats(const Hero& cible) const {
    int defEff = std::max(1, cible.getDefence());

    // facteur 0.90..1.10
    double facteur = 0.90 + (rand() % 21) / 100.0;

    // bonus classe simple lié à vitesse (cohérent "stat principale")
    double bonusClasse = 1.0 + std::min(vitesse, 50) / 250.0; // +0.20 max

    double degats = ((double)attaque / (double)defEff) * facteur * bonusClasse;

    // critique fixe : dégâts x2 avec proba fixe (pdf)
    int res = (int)(degats + 0.5);
    res = std::max(1, res);

    if ((rand() % 100) < 20) { // 20% fixe (modifiable si ton prof impose une valeur)
        res *= 2;
    }

    return res;
}
