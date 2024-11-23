#pragma once
#include <vector>
#include "Fichier.h"
#include "Partie.h" 

class HistoryGame
{
private:
    Fichier fichierHistorique;  // Fichier associ� � l'historique du jeu
    std::vector<Partie> parties;  // Liste des parties enregistr�es (composition)
public:
    // Constructeur
    HistoryGame(const Fichier& fichier);

    // Ajouter une partie � l'historique
    void ajouterPartie(const Partie& partie);

    // Enregistrer l'historique dans le fichier
    void enregistrerHistorique();

    // Afficher l'historique des parties
    void afficherHistorique() const;
};

