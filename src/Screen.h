#ifndef  SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <iostream>


class Screen
{
private:
    int _windowWidth, _windowHeight, _tileSize;
    SDL_Window* _mainWindow;
    SDL_Renderer* _mainRenderer;
    SDL_Surface* _tileSurface;
public:
    bool hasInitialize = false;
private:
    bool _initWindow();
    bool _initSurfaces();
public:
    Screen(const int width, const int height, const int tileSize);
    ~Screen();
    void clear();
    void present();

    void drawTile(const int x, const int y, const int tileType);
};

#endif