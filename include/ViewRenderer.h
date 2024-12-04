#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


using namespace std;

class MapLine;

class ViewRenderer
{
public:
	bool init(int w, int h);
	void render(SDL_Texture*& texture);
	void close();
	static ViewRenderer* getInstance();
	static void clearInstance();

	SDL_Texture* loadTexture(std::string path);
	void renderLine(MapLine* line);
	void commitChange();
private:
	// Singleton
	static ViewRenderer* instance;

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	ViewRenderer();
	~ViewRenderer();
	
};