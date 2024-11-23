// jeu_snake_version2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#pragma once
#include <iostream>
#include "Snake.h"
#include <iostream>
#include <vector>
#include <conio.h> // Pour  _getch()
#include <windows.h> // Pour Sleep()
#include "Food.h"
#include <string>
#include "Joueur.h"
#include <thread>  // Pour std::this_thread::sleep_for
#include <chrono>  // Pour std::chrono
#include "Partie.h"
#include "HistoryGame.h"
#include "Game.h"
using namespace std;
#include "Position.h"

int main()
{
    //pour initialiser la hauteur et largeur de terrain de jeu
    const int largeur = 25, hauteur = 15;

    // Afficher l'introduction
    Game::afficherIntroduction(); // Appel à la méthode statique d'introduction

    // Attendre que le joueur entre "suivant"
    std::string reponse;
    std::getline(std::cin, reponse);
    if (reponse != "suivant" && reponse != "Suivant") 
    {
        Game::afficherCadre();
        Game::afficherCentre("Veuillez entrer 'suivant' pour commencer.");
        Game::afficherFinCadre();
        return 0;
    }

    // Effacer l'écran et demander le nom du joueur
    system("cls");
    std::string nomJoueur;
    std::cout << "Veuillez entrer votre nom : ";
    std::getline(std::cin, nomJoueur);


    // Initialiser le fichier historique
    std::string nomFichierHistorique = nomJoueur + "_historique.txt";

    // Créer une instance de la classe Game
    Game monJeu(nomJoueur, nomFichierHistorique);

    // Créer une instance de `HistoryGame`
    Fichier fichierHistorique(nomFichierHistorique); // Gestionnaire de fichier
    HistoryGame historique(fichierHistorique); // Objet historique

    // Boucle principale
    bool rejouer = false;  
    do {
        //juste pour l'affichage
        monJeu.afficherCadre();
        monJeu.afficherCentre("Le jeu commence dans...");
        monJeu.afficherFinCadre();

        // Compter 1 2 3 pour commencer le jeu
        for (int i = 3; i > 0; --i) 
        {
            std::cout << "\t\t\t\t\t\t" << i << "...\r";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        // Afficher "Gooo !" avant de commencer
        system("cls");
        monJeu.afficherCadre();
        monJeu.afficherCentre("Gooo !");
        monJeu.afficherFinCadre();
        std::this_thread::sleep_for(std::chrono::seconds(1));

        //creation de snake et food
        Snake serpent(Position{ 0,0 }); // Accéder au serpent
        Food nourriture(0,0); // Accéder à la nourriture
        // Créer la partie avec les dimensions du terrain
        Partie partie(largeur, hauteur,serpent,nourriture); 
        
        // ( à chause partie etant associé un food et snake propre à elle )

        // demarrer la partie
        partie.demarrer();


        bool gameOver = false;

        while (!gameOver) 
        {
            // Détecter les entrées clavier pour controler le snake
            if (_kbhit()) 
            {
                switch (_getch()) 
                {
                case 'z': serpent.seDeplacerVersDirection(Direction::UP); break;
                case 's': serpent.seDeplacerVersDirection(Direction::DOWN); break;
                case 'q': serpent.seDeplacerVersDirection(Direction::LEFT); break;
                case 'd': serpent.seDeplacerVersDirection(Direction::RIGHT); break;
                }
            }

            // Déplacer le serpent
            serpent.move();

            // Vérifier les collisions
            // getHead().x == 0 --> le bord gauche de l’écran ou de l’espace de jeu.
            // serpent.getHead().x == largeur - 1 --> le bord droit de l’écran ou de l’espace de jeu
            // serpent.getHead().y == 0 -->   le bord supérieur de l’écran ou de l’espace de jeu.
            //serpent.getHead().y == hauteur - 1 --> le bord inférieur de l’écran ou de l’espace de jeu
            Position Pos1 = { largeur - 1, hauteur - 1 };
            Position Pos2 = { 0, 0 };
            if (serpent.checkSelfCollision() ||
                serpent.comparerHeadou(Pos1) || serpent.comparerHeadou(Pos2))
            {
                gameOver = true;
                partie.terminer(); // Terminer la partie et calculer la durée
                break;
            }

            // Si le serpent mange la nourriture
            Position pNourriture = nourriture.getPosition();
            if (serpent.comparerHeadet(pNourriture))
            {
                serpent.grow(); //le serpent grandit
                partie.augmenterScore(10); // Augmenter le score
                nourriture.generateNewPosition(largeur, hauteur); // donner Nouvelle position pour la nourriture
            }

            // Dessiner le terrain de jeu
            monJeu.draw(serpent, nourriture.getPosition(), largeur, hauteur);

            // Pause pour ajuster la vitesse du serpent
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }

        // Afficher le message de fin de partie
        monJeu.afficherCadre();
        monJeu.afficherCentre("Partie terminee !");
        monJeu.afficherFinCadre();

        // Afficher les détails de la partie
        partie.afficherDetails();

        // Ajouter la partie à l'historique
        historique.ajouterPartie(partie); //ajouté au vecreut de partie dans historique
        historique.enregistrerHistorique(); //enregistrer 

        // Demander au joueur s'il veut rejouer
        std::cout << "\n\nVoulez-vous rejouer ? (o/n) : ";
        char choix;
        std::cin >> choix;
        rejouer = (choix == 'o' || choix == 'O');

        //si rejouer est vrai == true
        if (rejouer) 
        {
            system("cls"); // Effacer l'écran
        }

    } while (rejouer);

    // Afficher le message de fin
    monJeu.afficherCadre();
    monJeu.afficherCentre("Merci d'avoir jouee !");
    monJeu.afficherFinCadre();

    // Compte à rebours avant de quitter
    for (int i = 3; i > 0; --i) 
    {
        std::cout << "Le jeu se termine dans " << i << "...\r";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}























