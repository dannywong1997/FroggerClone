#pragma once
#include "DEFINITIONS.h"
class GameState
{
public:
	GameState();
	~GameState();
	bool isGameOver();
	int getiCurrentLevel();
	void setiCurrentLevel(int tempInt);
	int getiMaxLevel();
	void setiMaxLevel(int tempInt);
	bool isInStartMenu();
	void setGameOver(bool TF);
	void setInStartMenu(bool TF);
private:
	/*
	User enters the start menu if bStartMenu is true.
	User enters the gameover menu if bGameOver is true.
	User enters the main game if both are false.
	*/
	bool bStartMenu , bGameOver;
	/*iCurrentLevel represents the number of the level that the player is playing, this game is going to have 5 levels,
	these vehicles are going to be much faster and spawn more frequently as the game level increases.*/
	int iCurrentLevel;
	/*
	The maximum level of this game, once the iCurrentLevel is equal to iMaxLevel, the game ends.
	*/
	int iMaxLevel;
};

