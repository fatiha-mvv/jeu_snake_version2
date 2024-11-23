#include "Partie.h"
#include "Utilities.h"
#include <iostream>
#include <chrono>
#include <string>


//---------> Constructeur avec parametres de Partie
Partie::Partie(int pos_x, int pos_y,Snake&s,Food&f)
    : score(0), duree(0),serpent(s),nourriture(f)
{
    // debut stocke le moment précis (timestamp) actuel
    debut = std::chrono::high_resolution_clock::now();
    //initialiser 
    s.initialiserPos(Position{pos_x / 2,pos_y / 2 });
    f.initialiserPos(Position{pos_x,pos_y});
}



////---------> demarrer la partie 
void Partie::demarrer()
{
    debut = std::chrono::high_resolution_clock::now(); //initialiser debut de partie
    serpent.grow();  // Initialiser la taille du serpent
    nourriture.generateNewPosition(20,10);  // Générer la nourriture
}


////---------> augmenter le score de la partie
void Partie::augmenterScore(int val)
{
    this->score += val;
}


////---------> mettre fin a  la partie 
void Partie::terminer()
{
    // Enregistrer le moment de fin de la partie
    auto fin = std::chrono::high_resolution_clock::now();
    // Calculer la durée de la partie
    duree = std::chrono::duration_cast<std::chrono::seconds>(fin - debut); 
    std::cout << "Fin de la partie ! Score final : " << score << "\n";
    std::cout << "Duree de la partie : " << duree.count() << " secondes.\n";
}


////---------> afficher les details de la partie (score + duree)
void Partie::afficherDetails() const
{
    std::cout << "Score : " << score << "\n";
    std::cout << "Durée : " << duree.count() << " secondes.\n";
}


////---------> La méthode ajoute au texte h les informations suivantes :
//// Score et Durée en secondes de l'objet Partie
void Partie::ConcatenerResultat(std::string &h)const
{
    h +=
        " | Score: " + std::to_string(this->score) +
        " | Duree: " + std::to_string(this->duree.count()) + " secondes\n";
}

