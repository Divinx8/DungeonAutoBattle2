#include "Guerrier.h"
#include <algorithm>
#include <cstdlib>

int Guerrier::calculerDegats(const Hero& cible) const {
    // dégâts "constants" : facteur très serré (0.95..1.05)
    double facteur = 0.95 + (rand() % 11) / 100.0; // 0..10 => 0.95..1.05
    double bonusClasse = 1.0;

    // +20% dégâts si PV < 30% des PV initiaux (pdf)
    if (pv < (int)(0.30 * pvInit)) bonusClasse *= 1.20;

    int defEff = std::max(1, cible.getDefence());
    double degats = ( (double)attaque / (double)defEff ) * facteur * bonusClasse;

    int res = (int)(degats + 0.5);
    return std::max(1, res);
}
