#pragma once
//Template
#pragma region "Rename_This"
#pragma endregion

#pragma region "General_Game_Settings"
#define GAMETITLE "Frogger Game"
#define FRAMELIMIT 60
#define WINDOW_WIDTH 420
#define WINDOW_HEIGHT 480
#define MAX_LEVEL 5
#define SPEED_SCALE { 1.0f,1.2f,1.3f,1.4f,1.7f }
#define SPAWN_RATE_SCALE { 1.0f,0.9f,0.8f,0.7f,0.5f }
#pragma endregion
#pragma region "Game_Map"
#define AMOUNT_OF_FROGBASE 5
#define AMOUNT_OF_SAFEAREA 2

#define SAFEAREA_SIZE sf::Vector2f(420.0f, 30.0f)
#define SAFEAREA_1_POS sf::Vector2f(0.0f,420.0f)
#define SAFEAREA_2_POS sf::Vector2f(0.0f,240.0f)

#define TOPAREA_SIZE sf::Vector2f(420.0f, 30.0f)
#define TOPAREA_POS sf::Vector2f(0.0f,0.0f)

#define WATER_BACKGROUND_SIZE sf::Vector2f(420.0f, 210.0f)
#define WATER_BACKGROUND_POS sf::Vector2f(0.0f, 30.0f)

#pragma endregion


#pragma region "Vehicles and Logs"
#define AMOUNT_OF_VEHICLES 5

#define VEHICLE_1_SPEED 30.0f
#define VEHICLE_1_POS sf::Vector2f(410.0f,270.0f)
#define VEHICLE_1_SIZE sf::Vector2f(30.0f, 30.0f)
#define VEHICLE_1_SPAWN_RATE 1.2f

#define VEHICLE_2_SPEED 16.0f
#define VEHICLE_2_POS sf::Vector2f(-50.0f, 300.0f)
#define VEHICLE_2_SIZE sf::Vector2f(60.0f, 30.0f)
#define VEHICLE_2_SPAWN_RATE 2.5f

#define VEHICLE_3_SPEED 45.0f
#define VEHICLE_3_POS sf::Vector2f(410.0f, 390.0f)
#define VEHICLE_3_SIZE sf::Vector2f(32.0f, 30.0f)
#define VEHICLE_3_SPAWN_RATE 1.2f

#define VEHICLE_4_SPEED 14.0f
#define VEHICLE_4_POS sf::Vector2f(-70.0f, 360.0f)
#define VEHICLE_4_SIZE sf::Vector2f(80.0f, 30.0f)
#define VEHICLE_4_SPAWN_RATE 3.0f

#define VEHICLE_5_SPEED 90.0f
#define VEHICLE_5_POS sf::Vector2f(410.0f, 330.0f)
#define VEHICLE_5_SIZE sf::Vector2f(30.0f, 30.0f)
#define VEHICLE_5_SPAWN_RATE 2.5f

#define AMOUNT_OF_LOGS 7
#define LOGS_SIZE sf::Vector2f(100.0f, 30.0f)
#define LOGS_SPAWN_RATE 5.0f
#define LOGS_1_SPEED 8.0f
#define LOGS_2_SPEED 6.0f
#define LOGS_3_SPEED 7.0f
#define LOGS_4_SPEED 8.0f
#define LOGS_5_SPEED 10.0f
#define LOGS_6_SPEED 11.0f
#define LOGS_7_SPEED 5.0f
#pragma endregion

#pragma region "Frog"
#define FROG_HEALTH 3
#define FROG_MOVEMENT_AMOUNT 30.0f
#define FROG_POS sf::Vector2f(210.0f, 420.0f)
#define FROG_SIZE sf::Vector2f(30, 30)
#pragma endregion

