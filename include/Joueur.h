#pragma once
#include <string>
#include <vector>
#include "Hero.h"

/**
 * @brief Représente un joueur du jeu.
 *
 * Un joueur possède un nom, une liste de héros (roster) et
 * une équipe active sélectionnée parmi ces héros.
 */
class Joueur {
    public:
       /**
     * @brief Construit un joueur.
     *
     * Initialise un joueur avec un nom et un roster vide.
     *
     * @param nom Nom du joueur
     */

    explicit Joueur(const std::string& nom);
    
    /**
     * @brief Retourne le nom du joueur.
     *
     * @return Nom du joueur
     */


    const std::string& getNom() const;
     /**
     * @brief Ajoute un héros au roster du joueur.
     *
     * Le roster est limité à 6 héros maximum.
     *
     * @param h Pointeur vers le héros à ajouter
     * @return true si l’ajout a réussi, false sinon
     */

    bool ajouterHero(Hero* h); 
                      /**
     * @brief Affiche les héros présents dans le roster.
     */
    void afficherRoster() const;
      /**
     * @brief Permet au joueur de sélectionner son équipe active.
     *
     * L’équipe est composée d’au plus 3 héros choisis
     * parmi le roster.
     */
    void selectionnerEquipe(); 
        
     /**
     * @brief Retourne l’équipe active du joueur.
     *
     * @return Vecteur de pointeurs vers les héros de l’équipe
     */
    const std::vector<Hero*>& getEquipe() const;
    /**
     * @brief Libère la mémoire des héros du joueur.
     *
     * Supprime tous les héros du roster.
     * À appeler à la fin du programme.
     */
    void libererHeros();                      

private:
    std::string nom;                      ///< Nom du joueur
    std::vector<Hero*> roster;             ///< Liste des héros possédés (max 6)   
    std::vector<Hero*> equipe;               ///< Équipe active (max 3)
    //std::vector<Hero*> roster;          
    //std::vector<Hero*> equipe;        
};
