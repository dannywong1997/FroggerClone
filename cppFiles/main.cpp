#include <SFML\Graphics.hpp>
#include "FroggerGame.h"

using namespace std;
//Template
/*[What this function does?]

[When it is going to be called?]
*/
int main()
{
	//FroggerGame is a class where all the main game loop are placed.
	FroggerGame Game;
	Game.initializeTheGame();
	while (Game.running())
	{
	}
	return 0;
}

