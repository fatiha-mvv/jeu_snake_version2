#include "Game.h"
#include "Joueur.h"
#include <string.h>

//************************************************************************************************************

//--------> constructeur avec parametres
Game::Game(const std::string& nomJoueur, const std::string& nomFichierHistorique)
    :joueur(nomJoueur), historique(Fichier(nomFichierHistorique))
{}



//---------> fonction draw qui va dessiner le champs de jeu
void Game::draw(const Snake& snake, const Position& food, int width, int height)
{
    system("cls"); // Efface l'écran (Windows)

    // Dessiner le plateau
    for (int y = 0; y < height; ++y) 
    {
        for (int x = 0; x < width; ++x) 
        {
            Position currentPos = { x, y };

            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) 
            {
                std::cout << "#"; // Mur
            }
            else if (snake.comparerHeadet(currentPos))
            {
                std::cout << "O"; // Tête du serpent
            }
            else if (snake.comparer(currentPos))
            {
                std::cout << "o"; // corps de serpent
            }
            else if (currentPos == food) 
            {
                std::cout << "F"; // Nourriture
            }
            else 
            {
                std::cout << " "; // Espace vide
            }
        }
        std::cout << "\n";
    }
}



//---------> affichage de cadre
void Game::afficherCadre()
{
    // Afficher une bordure avec des étoiles pour le cadre
    std::cout << "\n\t\t\t**************************************************\n";
    std::cout << "\t\t\t*                                                *\n";
}


//---------> affichage de texte au centre
void Game::afficherCentre(const std::string& texte)
{
    // Afficher un texte centré avec des étoiles autour
    std::cout << "\t\t\t*               " << texte << "               *\n";
}


//---------> fonction d'affichage de cadre de fin
void Game::afficherFinCadre()
{
    // Fermer le cadre avec des étoiles
    std::cout << "\t\t\t*                                                *\n";
    std::cout << "\t\t\t**************************************************\n";
}



//--------> fonction d'affichage d'introduction
void Game::afficherIntroduction()
{
    // Affichage de l'en-tête
    std::cout << "\n";
    std::cout << "\t\t\t*******************************************************\n";
    std::cout << "\t\t\t*                                                     *\n";
    std::cout << "\t\t\t*      Bienvenue dans le jeu Serpent !                *\n";
    std::cout << "\t\t\t*                                                     *\n";
    std::cout << "\t\t\t*******************************************************\n\n";

    // Instructions pour commencer le jeu
    std::cout << "\t\t\tAppuyez sur 'suivant' ou appuyez sur Enter pour commencer.\n";
}
