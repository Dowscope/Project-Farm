
#include "Screen.h"
#include "World.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TILE_SIZE 32

// Declare MAIN functions
bool init();
bool gameInit();
void cleanup();
void mainLoop();

// Declare Game Functions
void update();
void render();

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
    screen = new Screen(800, 600, TILE_SIZE);
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

    Uint32 minFPS = 1000 / 6;
    Uint32 lastTick = SDL_GetTicks64();

    while(isRunning)
    {
        Uint32 now = SDL_GetTicks64();

        if (lastTick < now)
        {
            Uint32 deltaTime = now - lastTick;

            if (deltaTime > minFPS)
            {
                deltaTime = minFPS;
            }

            SDL_Event e;
            while(SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT) 
                {   
                    isRunning = false;
                }
            }
        
            update();
            lastTick = now;

            screen->clear();
            render();
            screen->present();
        }
        else 
        {
            SDL_Delay(1);
        }
    }
}

void render()
{
    std::vector<Tile> worldTiles = world->getTiles();
    for (unsigned i = 0; i < worldTiles.size(); i++)
    {
        Tile t = worldTiles.at(i);
        if (t.x >= 0 && t.x * TILE_SIZE < WINDOW_WIDTH && t.y >= 0 && t.y * TILE_SIZE < WINDOW_HEIGHT)
        {
            screen->drawTile(t.x * TILE_SIZE, t.y * TILE_SIZE, t.type);
        }
    }
    
}

void update()
{

}