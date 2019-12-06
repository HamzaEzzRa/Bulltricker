#include <SDL2/SDL.h>
#include <stdio.h>
#include "gui.h"

int screen_width;
int screen_height;

void createWindow()
{
  FILE * fptr = fopen("screen_settings.txt", "r");
  fscanf(fptr, "%d %d", &screen_width, &screen_height);
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  }
  else
  {
    window = SDL_CreateWindow( "Bulltricker", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
      else
    {
      screenSurface = SDL_GetWindowSurface(window);
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
      SDL_UpdateWindowSurface(window);
      SDL_Delay(5000);
    }
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
}
