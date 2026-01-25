#pragma once
#include <string>
 /**
 * @brief Représente un héros du jeu.
 *
 * Un héros possède des points de vie, des statistiques de combat
 * et peut subir ou appliquer des effets au cours d’un tour.
 */


class Hero {
       /**
     * @brief Construit un héros avec des statistiques initiales.
     *
     * Les valeurs passées en paramètres sont corrigées afin de garantir
     * des statistiques valides (PV >= 1, attaque >= 1, défense >= 0,
     * vitesse >= 0).
     *
     * @param nom_ Nom du héros
     * @param pvInit_ Points de vie initiaux (minimum 1)
     * @param attaque_ Valeur d’attaque (minimum 1)
     * @param defence_ Valeur de défense (minimum 0)
     * @param vitesse_ Valeur de vitesse (minimum 0)
     */
public:
    Hero(const std::string& nom, int pvInit, int attaque, int defence, int vitesse);
    virtual ~Hero() = default;

    
    /**
     * @brief Affiche les statistiques actuelles du héros.
     */
    void afficherStats() const;

  /// @brief Retourne le nom du héros.
    const std::string& getNom() const;

   /// @brief Retourne les points de vie actuels
    int getPV() const;

    /// @brief Retourne les points de vie maximums
    int getPVInit() const;
    /// @brief Retourne la valeur de l'attaque
    int getAttaque() const;

    /// @brief Retourne la valeur de défense
    int getDefence() const;
      /// @brief Retourne la valeur de la vitesse
    int getVitesse() const;
     /**
     * @brief Indique si le héros est encore en vie.
     *
     * @return true si les PV sont strictement positifs, false sinon
     */
    bool estVivant() const;

     /**
     * @brief Réinitialise les points de vie aux valeurs initiales.
     */
    void resetPVInitiaux();

    
    virtual int getClasse() const = 0;
    virtual int calculerDegats(const Hero& cible) const = 0;


     /**
     * @brief Fait perdre des points de vie au héros.
     *
     * @param montant Quantité de PV perdus (valeur négative ignorée)
     */
    virtual void perdrePV(int montant);
    
    virtual void effetDebutTour(); // optionnel
    virtual void effetFinTour();   // optionnel

protected:
    std::string nom;
    int pv;
    int pvInit;
    int attaque;
    int defence;
    int vitesse;
};
