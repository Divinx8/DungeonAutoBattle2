#include "Mage.h"
#include <algorithm>
#include <cstdlib>

int Mage::calculerDegats(const Hero& cible) const {
    // ignore 30% de la défense ennemie (pdf)
    int defCible = cible.getDefence();
    int defEff = (int)(defCible * 0.70);
    defEff = std::max(1, defEff);

    // dégâts plus variables : facteur 0.80..1.20
    double facteur = 0.80 + (rand() % 41) / 100.0; // 0..40 => 0.80..1.20
    double bonusClasse = 1.10; // bonus simple "mage"

    double degats = ((double)attaque / (double)defEff) * facteur * bonusClasse;

    int res = (int)(degats + 0.5);
    return std::max(1, res);
}
