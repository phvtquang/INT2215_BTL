#include <iostream>
#include "stdafx.h"


#include "game.h"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
	int flags = 4;
	game game;
	game.init(SCREEN_WIDTH,SCREEN_HEIGHT,flags);


	Uint32 frameStart, frameTime;
	SDL_Event e;

	bool run = true;
	while (run)
	{
		frameStart = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					run = false;
				}
			} else if (e.type == SDL_QUIT)
			{
				run = false;
			}
		}

		game.gameloop();
		



		frameTime = SDL_GetTicks() - frameStart;
		if (1000 / 60 > frameTime)
		{
			SDL_Delay(1000 / 60 - frameTime);	
		}
	}
	
	return 0;
}