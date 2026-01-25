#include "Mage.h"
#include <algorithm>
#include <cstdlib>

/**
 * @brief Calcule les dégâts infligés par le Mage à une cible.
 *
 * Le Mage ignore partiellement la défense adverse (30%),
 * applique un facteur aléatoire important pour représenter
 * l'instabilité de la magie, ainsi qu'un bonus de classe fixe.
 *
 * La méthode garantit un minimum de 1 point de dégât.
 *
 * @param cible Héros adverse recevant l'attaque.
 * @return Dégâts finaux infligés par le Mage.
 */
int Mage::calculerDegats(const Hero& cible) const {

    // Récupération de la défense totale de la cible
    int defCible = cible.getDefence();

    // Le Mage ne subit que 70% de la défense adverse (ignore 30%)
    int defEff = (int)(defCible * 0.70);

    // Empêche la défense effective d'être nulle (évite division par zéro)
    defEff = std::max(1, defEff);

    // Facteur aléatoire important : dégâts compris entre -20% et +20%
    double facteur = 0.80 + (rand() % 41) / 100.0;

    // Bonus de classe fixe représentant la puissance magique
    double bonusClasse = 1.10;

    // Calcul brut des dégâts en fonction de l'attaque, de la défense,
    // de l'aléatoire et du bonus de classe
    double degats = ((double)attaque / (double)defEff)
                    * facteur
                    * bonusClasse;

    // Arrondi correct des dégâts avant conversion en entier
    int res = (int)(degats + 0.5);

    // Garantie d'infliger au moins 1 point de dégât
    return std::max(1, res);
}
