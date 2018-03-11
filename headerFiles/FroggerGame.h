#pragma once
#include <SFML\Graphics.hpp>
#include "FrogBase.h"
#include "Frog.h"
#include "GameObjectRec.h"
#include "DEFINITIONS.h"
#include "GameObjectControl.h"
#include "TextHandle.h"
#include <iostream>
#include <vector>
#include "GameState.h"
#include "..\include\main.h"
class FroggerGame
{
public:
	FroggerGame();
	~FroggerGame();
	void vehiclesSetting();
	void logsSetting();
	void initializeTheGame();
	bool running();
	void handleMainGameEvent();
	void drawMainGame();
	void handleGameOverEvent();
	void startNewLevel();
	void restartTheGame();
private:
	unsigned int uiWidth, uiHeight;
	sf::RenderWindow window;
	Frog Frog;
	sf::Clock clock;
	GameState CurrentGameState;
	TextHandle MainGameTextHandler;
	//Initializing two arrays based on the GameObject_Rec class, please read the GameObject_Rec.cpp file for more details on what this class does.
	GameObjectRec VehicleArray[AMOUNT_OF_VEHICLES], LogsArray[AMOUNT_OF_LOGS];
	//Initializing two arrays based on the GameObjectControl class, please read the GameObjectControl.cpp file for more details on what this class does.
	GameObjectControl VehicleControl[AMOUNT_OF_VEHICLES], LogsControl[AMOUNT_OF_LOGS];
	FrogBase FrogBaseArray[AMOUNT_OF_FROGBASE];
	sf::RectangleShape WaterBackground, SafeArea[AMOUNT_OF_SAFEAREA], TopAreaBackGround, Logo;
	bool bKeyPressed, bRespwan, bCloseApp;
};

