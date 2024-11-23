#pragma once
#include <vector>
#include "Fichier.h"
#include "Partie.h" 

class HistoryGame
{
private:
    Fichier fichierHistorique;  // Fichier associé à l'historique du jeu
    std::vector<Partie> parties;  // Liste des parties enregistrées (composition)
public:
    // Constructeur
    HistoryGame(const Fichier& fichier);

    // Ajouter une partie à l'historique
    void ajouterPartie(const Partie& partie);

    // Enregistrer l'historique dans le fichier
    void enregistrerHistorique();

    // Afficher l'historique des parties
    void afficherHistorique() const;
};

