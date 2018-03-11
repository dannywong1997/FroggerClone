#include "GameObjectControl.h"
/*
[Attributes]
fSpawnRate - keep tracks on the spawn rate given by the DEFINITION.h file.
iCurrent - keep tracks on the level that the player is on while playing the game.
iMaxLevel - the maximum level of this game.
[What this class does?]
One GameObjectControl object is responsible for one type of unit, 
for example, the game has one "GameObjectControl" instance for the red cars and one for the white trucks.
This class does mainly two things:
1.  "spawnUnit" member function - Keeps spawning unit( vehicles/logs) in the game, based on the given spawn rate.
2.  "move" member function - Calls the member function "gameObjectRecMovement" within the "GameObjectRec" class,
which allows the instance created by the "GameObjectRec" class can contentiously moving to one direction , if the unit is outside the game window range, deletes the unit.
*/

GameObjectControl::GameObjectControl()
{
	iCurrentLevel = 0;
	iMaxLevel = MAX_LEVEL;
	vfSpawnRateScale.insert(vfSpawnRateScale.end(), SPAWN_RATE_SCALE);
	setFirstUntiNotSpawned(true);
}


GameObjectControl::~GameObjectControl()
{
}

void GameObjectControl::spawnUnit( GameObjectRec tempGameObject_Rec,sf::Clock& tempClock)
{
	sf::Time time0 = tempClock.getElapsedTime();
	//If the first unit has not been spawned yet, spawn one unit.
	if (isFirstUnitNotSpawned())
	{
		spawnFirstUnit(tempGameObject_Rec);
		tempClock.restart();
	}
	//Once the first unit has been spawned, wait until the cool down(Spawn Rate) is finish before spawning the next unit.
	if (!isFirstUnitNotSpawned())
	{
		//If the cool down is finish.
		if (checkSpawnCoolDownIsFinish(time0))
		{
			//Adds the unit into vector "vGameObject".
			vGameObject_Rec.push_back(tempGameObject_Rec);
			tempClock.restart();
		}
	}
}
void GameObjectControl::drawAllUnits(sf::RenderWindow&window)
{
	//Draw all the units within vGameObject vector
	for (size_t i = 0; i < vGameObject_Rec.size(); i++)
	{
		window.draw(vGameObject_Rec[i]);
	}
}
void GameObjectControl::spawnFirstUnit(GameObjectRec tempGameObject_Rec) 
{
	if (vGameObject_Rec.size() < 1)
	{
		vGameObject_Rec.push_back(tempGameObject_Rec);
	}
	setFirstUntiNotSpawned(false);
}
bool GameObjectControl::checkSpawnCoolDownIsFinish(sf::Time tempTime)
{
	if (tempTime.asSeconds() < getCurrentSpawnRateScale())
	{
		return false;
	}
	return true;
}
void GameObjectControl::move(GameObjectRec tempGameObject_Rec, unsigned int fWindowX)
{
	//Make sure the vector has at least one unit in it.
	if (!isVectorEmpty())
	{
		//Apply to all the units within this Vector.
		for (size_t i = 0; i < vGameObject_Rec.size(); i++)
		{
			sf::Vector2f v2fUnitPos = vGameObject_Rec[i].getPosition();
			sf::Vector2f v2uUnitSize = vGameObject_Rec[i].getSize();
			//Here the program checks if the unit is out size the window range.
			if (v2fUnitPos.x > fWindowX + v2uUnitSize.x||v2fUnitPos.x <-v2uUnitSize.x)
			{
				//Remove the unit from vector once it is out of range.
				vGameObject_Rec.erase(vGameObject_Rec.begin());
			}
			//If the vector is not empty
			if (!isVectorEmpty())
			{
				//Here the program calls the "gameObjectRecMovement" member function to all the units within this Vector.
				vGameObject_Rec[i].gameObjectRecMovement();
			}
		}
	}
}
bool GameObjectControl::isVectorEmpty() {
	//Simply checks if the size of the vector is bigger than or equal 1.
	if (vGameObject_Rec.size() >= 1)
	{
		return false;
	}
	return true;
}
bool GameObjectControl::checksGameObjectUnitGroupIsIntersectWith(sf::RectangleShape Shape)
{
	//Make sure the vector has at least one unit in it.
	if (!isVectorEmpty())
	{
		//Apply to all the units within this Vector.
		for (size_t i = 0; i < vGameObject_Rec.size(); i++)
		{
			sf::Vector2f v2fPosObA = vGameObject_Rec[i].getPosition();
			sf::Vector2f v2fSizeObA = vGameObject_Rec[i].getSize();
			sf::Vector2f v2fPosObB = Shape.getPosition();
			sf::Vector2f v2fSizeObB = Shape.getSize();

			if (v2fPosObA.x < v2fPosObB.x + v2fSizeObB.x &&
				v2fPosObA.x + v2fSizeObA.x > v2fPosObB.x&&
				v2fPosObA.y < v2fPosObB.y + v2fSizeObB.y&&
				v2fPosObA.y + v2fSizeObA.y > v2fPosObB.y)
			{
				return true;
			}
		}
		return false;
	}
	return false;
}
void GameObjectControl::clearAllGameObjectRecInVector()
{
	//Clear the vector.
		vGameObject_Rec.clear();
}
void GameObjectControl::setSpawnRate(float tempSpawnRate) 
{
	//Multiply the given spawn rate with the spawn rate scale.
	fSpawnRate = tempSpawnRate * vfSpawnRateScale[iCurrentLevel];
}
float GameObjectControl::getCurrentSpawnRateScale()
{
	return fSpawnRate;
}
void GameObjectControl::increaseSpawnRateScale()
{
	iCurrentLevel++;
}
void GameObjectControl::resetSpawnRateScale()
{
	iCurrentLevel = 0;
}
bool GameObjectControl::isReachedMaxScale()
{
	if (iCurrentLevel >= iMaxLevel-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool GameObjectControl::isFirstUnitNotSpawned() {
	return bFirstUnitNotSpawned;
}
void GameObjectControl::setFirstUntiNotSpawned(bool TF) {
	bFirstUnitNotSpawned = TF;
}