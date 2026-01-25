#include "Guerrier.h"
#include <algorithm>
#include <cstdlib>

int Guerrier::calculerDegats(const Hero& cible) const {
    // Facteur aléatoire léger pour éviter des dégâts constants
    // Intervalle : [0.95 ; 1.05]
    double facteur = 0.95 + (rand() % 11) / 100.0; 
    double bonusClasse = 1.0;


    // Bonus de classe : +20 % de dégâts si les PV du guerrier
    // sont inférieurs à 30 % de ses PV initiaux
    if (pv < (int)(0.30 * pvInit)) 
         bonusClasse *= 1.20;


    
   // Défense effective minimale pour éviter une division par zéro
    int defEff = std::max(1, cible.getDefence());
    double degats = ( (double)attaque / (double)defEff ) * facteur * bonusClasse;

    // Arrondi à l’entier le plus proche
      int res = (int)(degats + 0.5);
    
    // Garantit au moins 1 point de dégât
    return std::max(1, res);
}
