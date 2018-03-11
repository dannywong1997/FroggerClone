#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.h"
class Frog: public sf::RectangleShape
{
public:
	Frog();
	~Frog();
	void death();
	void borderCheck(unsigned int fBoarderX , unsigned int fBoarderY);
	void setHealth(int iGHeath);
	int getHealth();
	bool isFrogSafeFromWater();
	void setSafeFromWater(bool TF);
	void loadTexture();
	void setToFrontTexture();
	void setToBackTexture();
	void setToLeftTexture();
	void setToRightTexture();
	void setAllowToMove(bool TF);
	bool isAllowedToMove();
	bool isReachedFrogBase();
private:
	int iHealth;
	sf::Texture textuFrogFront, textuFrogBack, textuFrogLeft, textuFrogRight;
	bool bSafeFromWater, bAllowedToMove;
};

