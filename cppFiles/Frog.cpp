#include "Frog.h"

using namespace std;

Frog::Frog()
{
	loadTexture();
	setToBackTexture();
	bAllowedToMove = false;
	Frog::setSize(FROG_SIZE);
	Frog::setPosition(FROG_POS);
	Frog::bSafeFromWater = false;
}

Frog::~Frog()
{
}

void Frog::borderCheck(unsigned int fBoarderX, unsigned int fBoarderY)
{
	sf::Vector2f v2fPos = Frog::getPosition();
	if (v2fPos.x >=fBoarderX-30)
	{
		Frog::setPosition(fBoarderX-30.0f, v2fPos.y);
	}
	if (v2fPos.x <0)
	{
		Frog::setPosition(0, v2fPos.y);
	}
	if (v2fPos.y <0)
	{
		Frog::setPosition(v2fPos.x, 0);
	}
	if (v2fPos.y >=fBoarderY-30)
	{
		Frog::setPosition(v2fPos.x, fBoarderY - 60.0f);
	}
}
void Frog::death()
{
		iHealth = iHealth - 1;
		cout << iHealth << endl;
		Frog::setPosition(FROG_POS);
}
void Frog::setHealth(int iGHealth)
{
	iHealth = iGHealth;
}
int Frog::getHealth()
{
	return iHealth;
}
bool Frog::isFrogSafeFromWater()
{
	return Frog::bSafeFromWater;
}
void Frog::setSafeFromWater(bool TF)
{
	Frog::bSafeFromWater = TF;
}
void Frog::loadTexture() {
	if (!textuFrogFront.loadFromFile("../spr/FroggerFront.png") || !textuFrogBack.loadFromFile("../spr/FroggerBack.png") || !textuFrogLeft.loadFromFile("../spr/FroggerLeft.png") || !textuFrogRight.loadFromFile("../spr/FroggerRight.png"))
	{
		cout << "Error 00: Texture file missing." << endl;
	}
}
void Frog::setToFrontTexture() {
	Frog::setTexture(&textuFrogFront);
}
void Frog::setToBackTexture() {
	Frog::setTexture(&textuFrogBack);
}
void Frog::setToLeftTexture() {
	Frog::setTexture(&textuFrogLeft);
}
void Frog::setToRightTexture() {
	Frog::setTexture(&textuFrogRight);
}
void Frog::setAllowToMove(bool TF)
{
	bAllowedToMove = TF;
}
bool Frog::isAllowedToMove() {
	return bAllowedToMove;
}
bool Frog::isReachedFrogBase() {
	if (getPosition().y < 30 && isFrogSafeFromWater())
	{
		return true;
	}
	return false;
}