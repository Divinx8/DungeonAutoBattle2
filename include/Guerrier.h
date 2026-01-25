#pragma once
#include "Hero.h"
/**
 * @brief Représente un héros de type Guerrier.
 *
 * Le Guerrier est une classe spécialisée de Hero orientée
 * vers le combat physique, avec des dégâts dépendant
 * principalement de la défense de la cible.
 */
class Guerrier : public Hero {

public:


  /**
     * @brief Construit un Guerrier.
     *
     * Initialise un guerrier avec les statistiques fournies.
     * Les règles de validation des statistiques sont celles
     * définies dans la classe Hero.
     *
     * @param nom Nom du guerrier
     * @param pvInit Points de vie initiaux
     * @param attaque Valeur d’attaque
     * @param defence Valeur de défense
     * @param vitesse Valeur de vitesse
     */
    Guerrier(const std::string& nom, int pvInit, int attaque, int defence, int vitesse)
        : Hero(nom, pvInit, attaque, defence, vitesse) {}



    /**
     * @brief Retourne l’identifiant de la classe du héros.
     *
     * @return 1 correspondant à la classe Guerrier
     */
    int getClasse() const override { return 1; }



       /**
     * @brief Calcule les dégâts infligés à une cible.
     *
     * Le calcul des dégâts dépend des statistiques du guerrier
     * et de celles du héros cible.
     *
     * @param cible Héros recevant l’attaque
     * @return Montant des dégâts infligés
     */
    int calculerDegats(const Hero& cible) const override;
};
