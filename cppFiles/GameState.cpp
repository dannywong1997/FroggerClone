#include "GameState.h"



GameState::GameState()
{
	setiMaxLevel(MAX_LEVEL);
	setInStartMenu(true);
	setGameOver(false);
	setiCurrentLevel(1);
}


GameState::~GameState()
{
}
bool GameState::isInStartMenu()
{
	return bStartMenu;
}
void GameState::setGameOver(bool TF)
{
	bGameOver = TF;
}
void GameState::setInStartMenu(bool TF)
{
	bStartMenu = TF;
}
bool GameState::isGameOver()
{
	return bGameOver;
}
int GameState::getiCurrentLevel() {
	return iCurrentLevel;
}
void GameState::setiCurrentLevel(int tempInt) {
	iCurrentLevel = tempInt;
}
int GameState::getiMaxLevel() {
	return iMaxLevel;
}
void GameState::setiMaxLevel(int tempInt) {
	iMaxLevel = tempInt;
}

