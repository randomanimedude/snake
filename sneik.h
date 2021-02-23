#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class ObjectWithTexture
{
private:
	SDL_Texture* sprite = nullptr;

public:
	SDL_Rect location;

	ObjectWithTexture() {};
	ObjectWithTexture(SDL_Texture*, int, int, int);
	void draw(SDL_Renderer*, int);
};

class Fruit : public ObjectWithTexture
{
private:
	int score;

public:
	Fruit(SDL_Texture*, int, int, int, int);
	void setLocation(int, int);
	int getScore() { return score; }
};

enum Direction{UP, DOWN, LEFT, RIGHT};

class Snake
{
private:
	SDL_Texture* bodySprite = nullptr;
	std::vector<ObjectWithTexture> body;
	ObjectWithTexture head;
	int angle = 90;
	int otstup;


public:
	void grow();
	Snake(SDL_Texture*, SDL_Texture*, int, int, int, int, int, int);
	int move(Direction, int, int, Fruit&);// , std::vector<Fruit>&);
	void draw(SDL_Renderer*);
};
