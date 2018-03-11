#include "FrogBase.h"



FrogBase::FrogBase()
{
	LoadTexture();
	ResetTexture();
	FrogBase::setSize(sf::Vector2f(40, 30));

}


FrogBase::~FrogBase()
{
}

bool FrogBase::checkIntersect(sf::RectangleShape Shape)
{
	sf::Vector2f v2fPosObA = FrogBase::getPosition();
	sf::Vector2f v2fSizeObA = FrogBase::getSize();
	sf::Vector2f v2fPosObB = Shape.getPosition();
	sf::Vector2f v2fSizeObB = Shape.getSize();
	if (v2fPosObA.x < v2fPosObB.x + v2fSizeObB.x &&
		v2fPosObA.x + v2fSizeObA.x > v2fPosObB.x&&
		v2fPosObA.y < v2fPosObB.y + v2fSizeObB.y&&
		v2fPosObA.y + v2fSizeObA.y > v2fPosObB.y)
	{
		return true;
	}
	return false;
}
bool FrogBase::isFrogBaseAvailable()
{
	if (bFrogBaseAvailableForFrog)
	{
		return true;
	}
	return false;
}

void FrogBase::setFrogBaseAvailable(bool TF)
{
	bFrogBaseAvailableForFrog = TF;
}

void FrogBase::LoadTexture()
{
	if (!textuFrogBase.loadFromFile("../spr/LilyPad.png") || !textuLilyPadWithFrog.loadFromFile("../spr/LilyPadWithFrog.png"))
	{
	}
}

void FrogBase::ResetTexture()
{
	FrogBase::setTexture(&textuFrogBase);
}
void FrogBase::setTextureToFrogOnTop() {
	FrogBase::setTexture(&textuLilyPadWithFrog);
}
