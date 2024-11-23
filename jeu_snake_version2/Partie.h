#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include "Food.h"
#include "Snake.h"

class Partie
{
private:
    int score;       // Score de la partie
    std::chrono::duration<int> duree; // Durée de la partie
    std::chrono::time_point<std::chrono::high_resolution_clock> debut; // Moment du début de la partie
    Snake& serpent;  // Le serpent pour cette partie
    Food& nourriture;  // La nourriture pour cette partie

public:
    // pos_x et pos_y ou seront positionnée le snake et food dans cette partie
    Partie(int pos_x, int pos_y,Snake&,Food&); 
    void demarrer(); //pour demarrer le jeu
    void augmenterScore(int val); //augmenter le score a chaque fois
    void terminer();  // pour terminer le jeu
    void afficherDetails() const; 
    void ConcatenerResultat(std::string&)const;
};

