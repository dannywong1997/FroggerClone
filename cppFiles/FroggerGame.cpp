#include "FroggerGame.h"
using namespace std;

FroggerGame::FroggerGame()
{
	bCloseApp = true;
}


FroggerGame::~FroggerGame()
{
}

void FroggerGame::initializeTheGame()
{
	//These two variables store the width and height of the game window.
	uiWidth = WINDOW_WIDTH, uiHeight = WINDOW_HEIGHT;
	//Initializing the game window.
	window.create(sf::VideoMode(uiWidth, uiHeight, 32), GAMETITLE);
	//Set the frame-rate limit.
	window.setFramerateLimit(FRAMELIMIT);
	/*
	bRespawn prevents the game from keep calling both functions vehiclesSetting() and logsSetting() non-stop, these two functions should only be called whenever the game is starting a new level.
	bKeyPressed is here to prevents the frog from teleporting, it makes sure that the frog cannot move before the next frame has been rendered.
	*/
	bRespwan = false, bKeyPressed = false;
	Frog.setHealth(FROG_HEALTH);
	CurrentGameState.setiMaxLevel(MAX_LEVEL);
}
bool FroggerGame::running()
{
#pragma region "Loading_And_Applying_Texture"
	/*Loading texture and font from the program directory.
	Folder:
	spr   - stores texture
	font  - stores text font
	*/
	sf::Texture textuSA, textuWater, truckTextu, spCarTextu, carTextu, YtruckTextu, pMotorTextu, woodTextu, lilyPadWithFrogTextu, TopMapTextu,logoTextu;
	if (!textuSA.loadFromFile("../spr/SA.png") || !textuWater.loadFromFile("../spr/WaterBackGround.png") || !woodTextu.loadFromFile("../spr/Wood.png") || !TopMapTextu.loadFromFile("../spr/TopMap.png") || !logoTextu.loadFromFile("../spr/FroggerLogo.png"))
	{
		cout << "hi" << endl;
	}
	if (!truckTextu.loadFromFile("../spr/Truck.png") || !spCarTextu.loadFromFile("../spr/SportCar.png") || !carTextu.loadFromFile("../spr/Car0.png") || !YtruckTextu.loadFromFile("../spr/YellowTruck.png") || !pMotorTextu.loadFromFile("../spr/PMotor.png"))
	{
		cout << "hi" << endl;
	}
	//Applying texture to game object.
	VehicleArray[0].setTexture(&carTextu);
	VehicleArray[1].setTexture(&YtruckTextu);
	VehicleArray[2].setTexture(&spCarTextu);
	VehicleArray[3].setTexture(&truckTextu);
	VehicleArray[4].setTexture(&pMotorTextu);
	WaterBackground.setTexture(&textuWater);
	Logo.setTexture(&logoTextu);
	TopAreaBackGround.setTexture(&TopMapTextu);
	for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
	{
		LogsArray[i].setTexture(&woodTextu);
	}
	for (size_t i = 0; i < AMOUNT_OF_SAFEAREA; i++)
	{
		SafeArea[i].setTexture(&textuSA);
	}
#pragma endregion

	while (window.isOpen())
	{
		sf::Clock cVC[AMOUNT_OF_VEHICLES], cLC[AMOUNT_OF_LOGS], tempClock;
#pragma region "Start_Menu_Loop"
		/*Start menu loop, display text and wait for user input to enter the main game loop.*/
		while (CurrentGameState.isInStartMenu() && !CurrentGameState.isGameOver())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					//Enter main game loop if pressed space.
					CurrentGameState.setInStartMenu(false);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					return false;
				}
			}
			//Logo setting.
			Logo.setSize(sf::Vector2f(350, 150));
			Logo.setPosition(30,30);
			window.clear();
			//Draw logo and text.
			MainGameTextHandler.initialize_tStartMenu();
			MainGameTextHandler.draw_tStartMenu(window);
			window.draw(Logo);
			window.display();
		}
#pragma endregion
		clock.restart();
		tempClock.restart();
#pragma region "Main_Game_Loop"	
		sf::Vector2u v2uWindowSize = window.getSize();
		//Main game loop
		while (!CurrentGameState.isGameOver() && !CurrentGameState.isInStartMenu())
		{
			handleMainGameEvent();
			//Set the size and position for the game map.
			for (size_t i = 0; i < AMOUNT_OF_SAFEAREA; i++)
			{
				SafeArea[i].setSize(SAFEAREA_SIZE);
			}
			TopAreaBackGround.setSize(SAFEAREA_SIZE);
			TopAreaBackGround.setPosition(TOPAREA_POS);
			WaterBackground.setSize(WATER_BACKGROUND_SIZE);
			WaterBackground.setPosition(WATER_BACKGROUND_POS);
			for (size_t i = 0; i < AMOUNT_OF_FROGBASE; i++)
			{
				FrogBaseArray[i].setPosition(int(i) * 95.0f, 0.0f);
			}
			sf::Time time1 = clock.getElapsedTime(), ThreeSecReadyTimer = tempClock.getElapsedTime();
			//ThreeSecReadyTimer as the name suggested, the player must wait 3 seconds until the player is allowed to control the frog.
			if (ThreeSecReadyTimer.asSeconds() > 3.0f)
			{
				Frog.setAllowToMove(true);
			}
			//time1 is a timer for moving the Vehicles and Logs.
			if (time1.asSeconds() > 0.01f)
			{
				bKeyPressed = false;
				//Calls the member function "move" within the "GameObjectControl" class to apply movement to all the vechicles and logs.
				for (size_t i = 0; i < AMOUNT_OF_VEHICLES; i++)
				{
					VehicleControl[i].move(VehicleArray[i], v2uWindowSize.x);
				}
				for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
				{
					LogsControl[i].move(LogsArray[i], v2uWindowSize.x);
				}
				clock.restart();
			}
			int iallFalseCheck = 0;

			iallFalseCheck =0;
#pragma region "Water Area"	
			//Check the collision between the frog and all the logs.
			for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
			{
				if (LogsControl[i].checksGameObjectUnitGroupIsIntersectWith(Frog))
				{
					//If the Frog is on a log, then the frog is going to move with the same speed as the log.
					Frog.move(LogsArray[i].getXSpeed(), 0.0f);
					Frog.setSafeFromWater(true);
				}
				else
				{
					iallFalseCheck++;
				}
				//Set bSafeFromWater to false if the frog is not on any of the log.
				if (iallFalseCheck >= AMOUNT_OF_LOGS)
				{
					Frog.setSafeFromWater(false);
				}
			}
			//Check if frog reaches the frog base, and also the frog base must be available at the same time.
			if (Frog.getPosition().y < 30)
			{
				for (size_t i = 0; i < AMOUNT_OF_FROGBASE; i++)
				{
					if (!FrogBaseArray[i].checkIntersect(Frog) || !FrogBaseArray[i].isFrogBaseAvailable())
					{
						iallFalseCheck++;
					}
					else
					{
						FrogBaseArray[i].setTextureToFrogOnTop();
						Frog.setSafeFromWater(true);
						startNewLevel();
						tempClock.restart();
						//Once a specific frog base has been used, the player can't use the same one next round.
						FrogBaseArray[i].setFrogBaseAvailable(false);
					}
					//Set bSafeFromWater to false if the frog is not on any of the frog base.
					if (iallFalseCheck >= AMOUNT_OF_FROGBASE)
					{
						Frog.setSafeFromWater(false);
					}
				}
			}
			//If the frog walks into the water area and the frog is not safe, then the frog dead.
			if (Frog.getPosition().y < 240 && !Frog.isFrogSafeFromWater())
			{
				Frog.death();
			}
#pragma endregion

			if (bRespwan == false)
			{
				vehiclesSetting();
				logsSetting();
				bRespwan = true;
			}
			SafeArea[0].setPosition(SAFEAREA_1_POS);
			SafeArea[1].setPosition(SAFEAREA_2_POS);
#pragma region "Spawning Units"	
			for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
			{
				LogsControl[i].setSpawnRate(LOGS_SPAWN_RATE);
				LogsControl[i].spawnUnit(LogsArray[i], cLC[i]);
			}
			VehicleControl[0].setSpawnRate(VEHICLE_1_SPAWN_RATE);
			VehicleControl[1].setSpawnRate(VEHICLE_2_SPAWN_RATE);
			VehicleControl[2].setSpawnRate(VEHICLE_3_SPAWN_RATE);
			VehicleControl[3].setSpawnRate(VEHICLE_4_SPAWN_RATE);
			VehicleControl[4].setSpawnRate(VEHICLE_5_SPAWN_RATE);
			for (size_t i = 0; i < AMOUNT_OF_VEHICLES; i++)
			{
				VehicleControl[i].spawnUnit(VehicleArray[i], cVC[i]);
				//Kill the frog once it collides with any vehicles.
				if (VehicleControl[i].checksGameObjectUnitGroupIsIntersectWith(Frog))
				{
					Frog.death();
				}
			}
#pragma endregion		
			Frog.borderCheck(v2uWindowSize.x, v2uWindowSize.y);
			//Display current level and health.
			MainGameTextHandler.initialize_tHealthAndLevelCount(Frog.getHealth(), CurrentGameState.getiCurrentLevel());
			MainGameTextHandler.initialize_tReady();
			MainGameTextHandler.tReadyCountDown(tempClock);
			//GameOver conditions
			if (Frog.getHealth() == 0 || CurrentGameState.getiCurrentLevel() == CurrentGameState.getiMaxLevel() + 1)
			{
				CurrentGameState.setGameOver(true);
			}
			window.clear();
			drawMainGame();
			window.display();
			if (!bCloseApp)
			{
				//close application
				return false;
			}
		}
#pragma endregion
#pragma region "GameOver_Menu"
		while (CurrentGameState.isGameOver())
		{
			handleGameOverEvent();
			tempClock.restart();
			window.clear();
			MainGameTextHandler.initialize_tGameOver();
			//Display different text if the player reaches level 6.
			if (CurrentGameState.getiCurrentLevel() >= 6)
			{
				MainGameTextHandler.tGameOver_GoodEnd();
			}
			else
			{
				MainGameTextHandler.tGameOver_BadEnd();
			}
			MainGameTextHandler.initialize_tRestart();
			MainGameTextHandler.draw_tGameOver(window);
			MainGameTextHandler.draw_tRestart(window);
			window.display();
			if (!bCloseApp)
			{
				//close application
				return false;
			}
		}
#pragma endregion
		clock.restart();
		tempClock.restart();
	}
	return false;
}
/*[What this function does?]
This function passes all the necessary properties that all the vehicles in this game needs to be able to working properly, such as position, speed and size.
[When it is going to be called?]
This function will be called in these following cases:
1. Initializing the game.
2. The frog reaches a frog base(I called it Safe Area), a next level is begun.
3. When the game restart.
*/
void FroggerGame::vehiclesSetting()
{
	VehicleArray[0].setEnemyPos(VEHICLE_1_POS);
	VehicleArray[0].setSpeed(-VEHICLE_1_SPEED);
	VehicleArray[0].setSize(VEHICLE_1_SIZE);
	VehicleArray[1].setEnemyPos(VEHICLE_2_POS);
	VehicleArray[1].setSpeed(VEHICLE_2_SPEED);
	VehicleArray[1].setSize(VEHICLE_2_SIZE);
	VehicleArray[2].setEnemyPos(VEHICLE_3_POS);
	VehicleArray[2].setSpeed(-VEHICLE_3_SPEED);
	VehicleArray[2].setSize(VEHICLE_3_SIZE);
	VehicleArray[3].setEnemyPos(VEHICLE_4_POS);
	VehicleArray[3].setSpeed(VEHICLE_4_SPEED);
	VehicleArray[3].setSize(VEHICLE_4_SIZE);
	VehicleArray[4].setEnemyPos(VEHICLE_5_POS);
	VehicleArray[4].setSpeed(-VEHICLE_5_SPEED);
	VehicleArray[4].setSize(VEHICLE_5_SIZE);
}
/*[What this function does?]
Pretty much the same as the vehiclesSetting function, but this one is for the logs.
[When it is going to be called?]
This function will be called in these following cases:
Exactly same as the vehiclesSetting.
*/
void FroggerGame::logsSetting()
{
	float NP = 0.0f;
	for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
	{
		LogsArray[i].setSize(LOGS_SIZE);
		if (NP == 1)
		{
			NP--;
		}
		else
		{
			NP++;
		}
		LogsArray[i].setPosition(-90.0f + (NP*570.0f), (i*30.0f) + 30.0f);
	}
	LogsArray[0].setSpeed(-LOGS_1_SPEED);
	LogsArray[1].setSpeed(LOGS_2_SPEED);
	LogsArray[2].setSpeed(-LOGS_3_SPEED);
	LogsArray[3].setSpeed(LOGS_4_SPEED);
	LogsArray[4].setSpeed(-LOGS_5_SPEED);
	LogsArray[5].setSpeed(LOGS_6_SPEED);
	LogsArray[6].setSpeed(-LOGS_7_SPEED);
}
void FroggerGame::handleMainGameEvent() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		//Basic movement handle.
		if (Frog.isAllowedToMove())
		{
			//Apply different texture based on the direction that the frog is moving.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !bKeyPressed)
			{
				Frog.move(0.f, -FROG_MOVEMENT_AMOUNT);
				Frog.setToBackTexture();
				bKeyPressed = !bKeyPressed;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !bKeyPressed)
			{
				Frog.move(0.f, FROG_MOVEMENT_AMOUNT);
				bKeyPressed = !bKeyPressed;
				Frog.setToFrontTexture();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !bKeyPressed)
			{
				Frog.move(-FROG_MOVEMENT_AMOUNT, 0.F);
				bKeyPressed = !bKeyPressed;
				Frog.setToLeftTexture();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !bKeyPressed)
			{
				Frog.move(FROG_MOVEMENT_AMOUNT, 0.F);
				bKeyPressed = !bKeyPressed;
				Frog.setToRightTexture();
			}
		}	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				//CloseApplication if bClose = false;
				bCloseApp = false;
			}			
		switch (event.type)
			{
			case sf::Event::Closed:
				bCloseApp = false;
				window.close();
				break;
			}		
	}
}
void FroggerGame::drawMainGame() {
	//all the draw function for the main game loop are placed in here.
	window.draw(TopAreaBackGround);
	window.draw(WaterBackground);
	for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
	{
		LogsControl[i].drawAllUnits(window);
	}
	for (size_t i = 0; i < AMOUNT_OF_VEHICLES; i++)
	{
		VehicleControl[i].drawAllUnits(window);
	}
	MainGameTextHandler.draw_tHealthAndLevelCount(window);
	for (size_t i = 0; i < AMOUNT_OF_SAFEAREA; i++)
	{
		window.draw(SafeArea[i]);
	}
	for (size_t i = 0; i < AMOUNT_OF_FROGBASE; i++)
	{
		window.draw(FrogBaseArray[i]);
	}
	window.draw(Frog);
	MainGameTextHandler.draw_tReady(window);
}
void FroggerGame::handleGameOverEvent() {
	sf::Event event;
	while (window.pollEvent(event))
			{
				//Reset the game once the player pressed space.
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					restartTheGame();
				}
				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
				{
					bCloseApp = false;
				}
			}
}
void FroggerGame::startNewLevel() {
	CurrentGameState.setiCurrentLevel(CurrentGameState.getiCurrentLevel() + 1);
	for (size_t i = 0; i < AMOUNT_OF_VEHICLES; i++)
	{
		//Increase the speed and spawn rate as the level increases.
		if (!VehicleArray[i].isReachedMaxScale())
		{
			VehicleArray[i].increaseSpeedScale();
		}
		if (!VehicleControl[i].isReachedMaxScale())
		{
			VehicleControl[i].increaseSpawnRateScale();
		}
	}
	Frog.setHealth(FROG_HEALTH);
	Frog.setPosition(FROG_POS);
	for (size_t i = 0; i < AMOUNT_OF_VEHICLES; i++)
	{
		VehicleControl[i].clearAllGameObjectRecInVector();
		VehicleControl[i].setFirstUntiNotSpawned(true);
	}
	for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
	{
		LogsControl[i].clearAllGameObjectRecInVector();
		LogsControl[i].setFirstUntiNotSpawned(true);
	}
	Frog.setAllowToMove(false);
	bRespwan = false;
}
void FroggerGame::restartTheGame() {
	Frog.setAllowToMove(false);
	Frog.setHealth(FROG_HEALTH);
	for (size_t i = 0; i < AMOUNT_OF_VEHICLES; i++)
	{
		VehicleControl[i].clearAllGameObjectRecInVector();
		VehicleControl[i].setFirstUntiNotSpawned(true);
		VehicleArray[i].resetSpeedScale();
		VehicleControl[i].resetSpawnRateScale();
	}
	for (size_t i = 0; i < AMOUNT_OF_LOGS; i++)
	{
		LogsControl[i].clearAllGameObjectRecInVector();
		LogsControl[i].setFirstUntiNotSpawned(true);
		LogsControl[i].resetSpawnRateScale();
	}
	CurrentGameState.setiCurrentLevel(1);
	for (size_t i = 0; i < AMOUNT_OF_FROGBASE; i++)
	{
		FrogBaseArray[i].ResetTexture();
		FrogBaseArray[i].setFrogBaseAvailable(true);
	}
	bRespwan = false;
	CurrentGameState.setGameOver(false);
}