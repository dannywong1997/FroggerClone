#pragma once
#include <SFML\Graphics.hpp>
#include "DEFINITIONS.h"
#include <vector>
#include <iostream>
class GameObjectRec :public sf::RectangleShape
{
public:
	GameObjectRec();
	~GameObjectRec();
	void gameObjectRecMovement();
	void setEnemyPos(sf::Vector2f Temp_Positions);
	void setSpeed(float iGivenSpeed);
	void setWalkDistance(float fWD);
	float getXSpeed();
	float getCurrentSpeedScale();
	void increaseSpeedScale();
	void resetSpeedScale();
	bool isReachedMaxScale();
private:
	int iCurrentLevel, iMaxLevel;
	float fSpeed, fWalkDistance;
	std::vector<float> vfSpeedScale;
protected:

};

