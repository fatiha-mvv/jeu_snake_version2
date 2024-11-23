#include "HistoryGame.h"
#include <iostream>

////---------> Constructeur qui prend le nom du fichier pour l'historique
HistoryGame::HistoryGame(const Fichier& fichier)
    : fichierHistorique(fichier) {}



////---------> Ajouter une nouvelle partie à l'historique
void HistoryGame::ajouterPartie(const Partie& partie)
{
    parties.push_back(partie); //ajouter la partie au vecteur 
}



////---------> Enregistrer l'historique des parties dans le fichier
void HistoryGame::enregistrerHistorique()
{
    std::string historique;
    //boucle our parcourir toutes les parties d'historique
    for (const auto& partie : parties) 
    {
        partie.ConcatenerResultat(historique);
    }
    // Écrire l'historique dans le fichier
    fichierHistorique.ecrireDansFichier(historique);
}




////---------> Afficher l'historique des parties (afficher directement sur la console)
void HistoryGame::afficherHistorique() const
{
    std::string contenu = fichierHistorique.lireDuFichier();
    std::cout << "Historique des parties:\n" << contenu << std::endl;
}



