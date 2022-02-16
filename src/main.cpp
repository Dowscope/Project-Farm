
#include "Screen.h"
#include "World.h"

// Declare MAIN functions
bool init();
bool gameInit();
void cleanup();
void mainLoop();

// Declare game objects
Screen* screen;

// Declare data objects
World* world;

// MAIN function
int main(int argc, char const *argv[])
{
    init();
    gameInit();
    mainLoop();
    cleanup();
    return 0;
}

// Initialize the game
bool init() 
{
    screen = new Screen(800, 600);
    if (!screen->hasInitialize) 
    {
        std::cout << "MAIN_CPP: Screen did not initialize" << std::endl;
        return false;
    }

    return true;
}

bool gameInit() {
    world = new World();
    return true;
}

// Clean up before quiting game
void cleanup()
{
    delete world;
    delete screen;
}

// MAIN LOOP
void mainLoop()
{
    bool isRunning = true;

    while(isRunning)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) 
            {   
                isRunning = false;
            }
        }

        screen->clear();
        screen->present();
    }
}