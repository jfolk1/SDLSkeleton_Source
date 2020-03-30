
#include "gtest/gtest.h"

 #include "SDL_test_common.h"
#include <thread>
class Graphics;

// The fixture for testing class Foo.
class TestExample : public ::testing::Test {

protected:

    // You can do set-up work for each test here.
    TestExample();

    // You can do clean-up work that doesn't throw exceptions here.
    virtual ~TestExample();
    void handleInput();
    void holdView(unsigned int seconds);
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    // Code here will be called immediately after the constructor (right
    // before each test).
    virtual void SetUp();

    // Code here will be called immediately after each test (right
    // before the destructor).
    virtual void TearDown();

    
    SDLTest_CommonState *state;
    typedef struct {
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *background;
        SDL_Texture *sprite;
        SDL_Rect sprite_rect;
        int scale_direction;
    } DrawState;
    DrawState *drawstates;
    
    SDL_GLContext glContext;
    std::unique_ptr<Graphics> graphics;
    std::thread *updateThread;
    bool done;
};


