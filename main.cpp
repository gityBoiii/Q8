#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL_Init_Error");
		exit(-1);
	}

	SDL_Window* MyWindow = SDL_CreateWindow("MyGame", 100, 100, 600, 600, SDL_WINDOW_VULKAN);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	int X = 0;
	SDL_Color BackgroundColor = { 0xff, 0, 0 ,0 };
	while (1)
	{
		//화면 지우기
		SDL_SetRenderDrawColor(MyRenderer, BackgroundColor.r, BackgroundColor.g, BackgroundColor.b, BackgroundColor.a);
		SDL_RenderClear(MyRenderer);

		if (X > 500)
		{
			X = 0;
		}
		SDL_SetRenderDrawColor(MyRenderer, 0x00, 0, 0xff, 0);
		SDL_Rect MyRect = { X++, 100, 100, 100 };
		SDL_RenderFillRect(MyRenderer, &MyRect);

		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent);

		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}
		else if (MyEvent.type == SDL_KEYDOWN)
		{
			BackgroundColor = { 0xff, 0xff, 0, 0 };
		}

		//화면에 그리기
		SDL_RenderPresent(MyRenderer);
	}


	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}