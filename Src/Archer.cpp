#include "Archer.h"
#include <algorithm>
#include <cstdlib>

/**
 * @brief Détermine si l'Archer esquive une attaque.
 *
 * La probabilité d'esquive dépend de la vitesse du héros.
 * Chaque tranche de 6 points de vitesse donne +1% de chance,
 * avec un plafond fixé à 15% pour conserver l'équilibrage.
 *
 * @return true si l'attaque est esquivée, false sinon.
 */
bool Archer::esquive() const {
    int chance = vitesse / 6;           // Conversion vitesse -> pourcentage
    chance = std::min(chance, 15);      // Plafond à 15%
    return (rand() % 100) < chance;     // Tirage aléatoire
}

/**
 * @brief Calcule les dégâts infligés par l'Archer à une cible.
 *
 * Les dégâts dépendent :
 * - de l'attaque de l'Archer,
 * - de la défense de la cible,
 * - d'un facteur aléatoire modéré,
 * - d'un bonus de classe basé sur la vitesse,
 * - et d'un coup critique possible (20%).
 *
 * La méthode garantit qu'au moins 1 point de dégât est infligé.
 *
 * @param cible Héros adverse recevant l'attaque.
 * @return Dégâts finaux infligés à la cible.
 */
int Archer::calculerDegats(const Hero& cible) const {
    int defEff = std::max(1, cible.getDefence()); // Défense effective sécurisée

    // Facteur aléatoire compris entre 0.90 et 1.10
    double facteur = 0.90 + (rand() % 21) / 100.0;

    // Bonus de classe basé sur la vitesse (plafonné)
    double bonusClasse = 1.0 + std::min(vitesse, 50) / 250.0;

    // Calcul brut des dégâts
    double degats = ((double)attaque / (double)defEff)
                    * facteur
                    * bonusClasse;

    // Arrondi correct et garantie d'un dégât minimum
    int res = (int)(degats + 0.5);
    res = std::max(1, res);

    // Coup critique : dégâts doublés avec une probabilité de 20%
    if ((rand() % 100) < 20) {
        res *= 2;
    }

    return res;
}