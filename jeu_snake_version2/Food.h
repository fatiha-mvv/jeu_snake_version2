#pragma once
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour initialiser srand()
#include "Utilities.h"
#include <vector>
#include <iostream>
#include "Position.h"

class Food
{
private:
	Position position; //position de la nourriture 
public:
	// Constructeur : initialise une position initiale
	Food(int boardWidth, int boardHeight);

	//pour generer une nouvelle position pour la nourriture 
	void generateNewPosition(int boardWidth, int boardHeight);

	//si y a collision avec le corps de serpent , on generer une nouvelle position
	void regenerateIfInSnake(const std::vector<Position>& snakeBody, int boardWidth, int boardHeight);

	//to get the position of the food
	Position getPosition()const;

	//pour initialiser position aleatoirement
	void initialiserPos(Position);
};
