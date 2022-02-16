#include "Screen.h"

Screen::Screen(const int width, const int height):
    _windowWidth(width), _windowHeight(height)
{
    this->hasInitialize = initWindow();
}

Screen::~Screen()
{
    SDL_DestroyRenderer(_mainRenderer);
    SDL_DestroyWindow(_mainWindow);
}

bool Screen::initWindow()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SCREEN_H: SDL did not initialize | " << SDL_GetError() << std::endl;
        return false;
    }

    _mainWindow = SDL_CreateWindow( "Project Farm", 
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    _windowWidth,
                                    _windowHeight,
                                    0);
    if (!_mainWindow)
    {
        std::cout << "SCREEN_H: GLFW Window did not initialize" << std::endl;
        return false;
    }

    return true;
}

void Screen::clear()
{
    SDL_RenderClear(_mainRenderer);
}

void Screen::present()
{
    SDL_RenderPresent(_mainRenderer);
}
