#include "Joueur.h"
#include <iostream>

/**
 * @brief Constructeur de Joueur.
 *
 * Initialise le joueur avec son nom.
 */
Joueur::Joueur(const std::string& nom_) : nom(nom_) {}
/**
 * @brief Retourne le nom du joueur.
 */
const std::string& Joueur::getNom() const { return nom; }


/**
 * @brief Ajoute un héros au TABLEAU du joueur.
 *
 * Vérifie que le pointeur n'est pas nul et que
 * le roster ne dépasse pas la limite de 6 héros.
 */
bool Joueur::ajouterHero(Hero* h) {
    if (!h) return false;      // pointeur invalide
    if ((int)roster.size() >= 6) return false;  // roster plein
    roster.push_back(h);
    return true;
}


/**
 * @brief Affiche tous les héros du TABLEAU.
 */
void Joueur::afficherRoster() const {
    std::cout << "Roster de " << nom << ":\n";
    for (int i = 0; i < (int)roster.size(); i++) {
        std::cout << "  [" << i << "] ";
        roster[i]->afficherStats();
    }
}


/**
 * @brief Permet au joueur de sélectionner son équipe.

 * Le joueur choisit jusqu'à 3 héros parmi le roster
 * via leur index. Les doublons sont interdits.
 */

void Joueur::selectionnerEquipe() {
    equipe.clear();  // réinitialisation de l'équipe
    std::cout << "\nSelection equipe (max 3) pour " << nom << "\n";
    afficherRoster();
  
    while ((int)equipe.size() < 3) {
        std::cout << "Choisir index hero (0.."<< (int)roster.size()-1 << ") ou -1 pour finir: ";
        int idx;
        std::cin >> idx;
// vérification des bornes
        if (idx == -1) break;
        if (idx < 0 || idx >= (int)roster.size()) {
            std::cout << "Index invalide.\n";
            continue;
        }

        // éviter les doublons dans l'équipe
        bool deja = false;
        for (Hero* h : equipe) // Vérifie si le héros est déjà présent dans l'équipe

           if (h == roster[idx]) 
                 deja = true;

           if (deja) {
            std::cout << "Deja selectionne.\n";
            continue;
         }

       equipe.push_back(roster[idx]);
        std::cout << "Ajoute: " << roster[idx]->getNom() << "\n";
    }

/**
 * @brief Affiche tous les héros du TABLEAU.
 */
    std::cout << "Equipe finale (" << equipe.size() << "):\n";
    for (Hero* h : equipe) {
        std::cout << "  - ";
        h->afficherStats();
    }
}

const std::vector<Hero*>& Joueur::getEquipe() const { return equipe; }

void Joueur::libererHeros() {
    for (Hero* h : roster) delete h;
    roster.clear();
    equipe.clear();
}
