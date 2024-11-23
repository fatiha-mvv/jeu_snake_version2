#include "Food.h"
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour initialiser srand()
#include "Position.h"

////----------> Constructeur de classe Food
Food::Food(int boardWidth, int boardHeight)
{
    srand(static_cast<unsigned>(time(0))); // Initialisation du g�n�rateur de nombres al�atoires
    generateNewPosition(boardWidth, boardHeight);
}


////----------> Pour generer une nouvelle position pour la nouriture
void Food::generateNewPosition(int boardWidth, int boardHeight)
{
    position.genererPositionAleatoire(boardWidth, boardHeight);
}


////----------> si la position actuelle de la nourriture est d�j� occup�e par le corps du serpent
void Food::regenerateIfInSnake(const std::vector<Position>& snakeBody, int boardWidth, int boardHeight)
{
    while (std::find(snakeBody.begin(), snakeBody.end(), position) != snakeBody.end()) 
    {
        generateNewPosition(boardWidth, boardHeight);
    } //tant que vraie regenerer une nouvelle position pour le food
}


////----------> to get the position of the food 
Position Food::getPosition() const
{
    return position;
}


////----------> pour r�initialiser par une nouvelle position
void Food::initialiserPos(Position p)
{
    this->position = p;
}
