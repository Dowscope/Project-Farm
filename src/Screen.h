#ifndef  SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>
#include <iostream>


class Screen
{
private:
    int _windowWidth, _windowHeight;
    SDL_Window* _mainWindow;
    SDL_Renderer* _mainRenderer;
public:
    bool hasInitialize = false;
private:
public:
    Screen(const int width, const int height);
    ~Screen();
    bool initWindow();
    bool shouldWindowClose();
    void clear();
    void present();
    void drawTriangle();
};

#endif