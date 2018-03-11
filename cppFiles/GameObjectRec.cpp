#include "GameObjectRec.h"

GameObjectRec::GameObjectRec()
{
	iCurrentLevel = 0;
	iMaxLevel = MAX_LEVEL -1;
	//This line of code adds all the SPEED_SCALE values into vector vfSpeedScale;
	vfSpeedScale.insert(vfSpeedScale.end(), SPEED_SCALE);
	GameObjectRec::setOutlineColor(sf::Color::Black);
	GameObjectRec::setWalkDistance(0.1f);
}


GameObjectRec::~GameObjectRec()
{
}

void GameObjectRec::gameObjectRecMovement()
{
	GameObjectRec::move(fSpeed*fWalkDistance,0.0f);
}
void GameObjectRec::setEnemyPos(sf::Vector2f Temp_Positions)
{
	GameObjectRec::setPosition(Temp_Positions);
}
void GameObjectRec::setSpeed(float iGivenSpeed)
{
	fSpeed = iGivenSpeed * getCurrentSpeedScale();
}
void GameObjectRec::setWalkDistance(float fWD)
{
	fWalkDistance = fWD;
}
float GameObjectRec::getXSpeed()
{
	return fSpeed*fWalkDistance;
}
float GameObjectRec::getCurrentSpeedScale()
{
	return vfSpeedScale[iCurrentLevel];
}
void GameObjectRec::increaseSpeedScale() 
{
	iCurrentLevel++;
}
void GameObjectRec::resetSpeedScale()
{
	iCurrentLevel = 0;
}
bool GameObjectRec::isReachedMaxScale()
{
	if (iCurrentLevel >= iMaxLevel)
	{
		return true;
	}
	else
	{
		return false;
	}
}

