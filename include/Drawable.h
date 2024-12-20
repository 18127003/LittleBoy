#pragma once
#include <SDL.h>
#include <ViewRenderer.h>

class Drawable
{
protected:
	SDL_Texture* texture;
	SDL_Rect* spriteRect;
	SDL_Rect* renderRect;
public:
	Drawable(SDL_Texture* texture, SDL_Rect* sprite, SDL_Rect* render) :
		texture(texture), spriteRect(sprite), renderRect(render) {}
	virtual ~Drawable();
	void draw();
	void draw(ViewRenderer* viewRenderer);
};

class PhysicObject: public Drawable
{
public:
	PhysicObject(SDL_Texture* texture, SDL_Rect* sprite, SDL_Rect* render) : Drawable(texture, sprite, render) {};
	virtual ~PhysicObject();
	virtual bool isPassable() = 0;
private:

};

class MovableObject: public PhysicObject
{
public:
	MovableObject(SDL_Texture* texture, SDL_Rect* sprite, SDL_Rect* render) : PhysicObject(texture, sprite, render) {};
	virtual ~MovableObject();
	virtual bool isPassable() = 0;
private:

};