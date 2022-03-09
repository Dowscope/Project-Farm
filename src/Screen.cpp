#include "Screen.h"

Screen::Screen(const int width, const int height, const int tileSize):
    _windowWidth(width), _windowHeight(height), _tileSize(tileSize)
{
    this->hasInitialize = _initWindow();
    this->hasInitialize = _initSurfaces();
}

Screen::~Screen()
{
    SDL_DestroyRenderer(_mainRenderer);
    SDL_DestroyWindow(_mainWindow);
}

bool Screen::_initWindow()
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
        std::cout << "SCREEN_H: SDL Window did not initialize" << std::endl;
        return false;
    }

    _mainRenderer = SDL_CreateRenderer(_mainWindow, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC);

    if (!_mainWindow)
        {
            std::cout << "SCREEN_H: SDL Renderer did not initialize" << std::endl;
            return false;
        }

    return true;
}

bool Screen::_initSurfaces()
{
    _tileSurface = SDL_CreateRGBSurface(    0,
                                            16 * _tileSize,
                                            16 * _tileSize,
                                            32,
                                            0,
                                            0,
                                            0,
                                            0);

    if (!_tileSurface)
    {
        std::cout << "SCREEN_H: TileSurface did not initialize" << std::endl;
        return false;
    }

    return true;
}

void Screen::clear()
{
    SDL_SetRenderDrawColor(_mainRenderer, 0, 0, 0, 255);
    SDL_RenderClear(_mainRenderer);
}

void Screen::present()
{
    SDL_Texture* s = SDL_CreateTextureFromSurface(_mainRenderer, _tileSurface);
    SDL_RenderCopy(_mainRenderer, s, NULL, NULL);
    SDL_RenderPresent(_mainRenderer);
}

void Screen::drawTile(const int x, const int y, const int tileType)
{
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = _tileSize;
    r.h = _tileSize;

    SDL_FillRect(_tileSurface, &r, SDL_MapRGBA(_tileSurface->format, 255, 0, 0, 255));
}
