#pragma once
#include <SFML\Graphics.hpp>
class FrogBase : public sf::RectangleShape
{
public:
	FrogBase();
	~FrogBase();
	bool checkIntersect(sf::RectangleShape Shape);
	bool isFrogBaseAvailable();
	void setFrogBaseAvailable(bool TF);
	void LoadTexture();
	void ResetTexture();
	void setTextureToFrogOnTop();
private:
	bool bFrogBaseAvailableForFrog;
	sf::Texture textuFrogBase, textuLilyPadWithFrog;
};

