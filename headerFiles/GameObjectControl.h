#pragma once
#include "GameObjectRec.h"
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
class GameObjectControl
{
public:
	GameObjectControl();
	~GameObjectControl();
	void spawnUnit(GameObjectRec tempGameObject_Rec, sf::Clock & tempClock);
	void drawAllUnits(sf::RenderWindow & window);
	void spawnFirstUnit(GameObjectRec tempGameObject_Rec);
	bool checkSpawnCoolDownIsFinish(sf::Time tempTime);
	void move(GameObjectRec NewEnemy,unsigned int fWindowX);
	bool isVectorEmpty();
	bool checksGameObjectUnitGroupIsIntersectWith(sf::RectangleShape Shape);
	void clearAllGameObjectRecInVector();
	void setSpawnRate(float tempSpawnRate);
	float getCurrentSpawnRateScale();
	void increaseSpawnRateScale();
	void resetSpawnRateScale();
	bool isReachedMaxScale();
	bool isFirstUnitNotSpawned();
	void setFirstUntiNotSpawned(bool TF);
protected:
	float fSpawnRate;
	int iCurrentLevel, iMaxLevel;
	std::vector<GameObjectRec> vGameObject_Rec;
	std::vector<float> vfSpawnRateScale;
	bool bFirstUnitNotSpawned;
};

