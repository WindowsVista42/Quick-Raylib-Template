# Quick-Raylib-Template
A quick raylib template with a simple game state switcher.  
Raylib, Cmake, Ninja, Make and a c++ compiler are required for building and running.  
Initialize first using `make b`, build and run using `make d` for debug builds, and `make r` for release builds.

# Example
A basic example showing state switching between a red and blue background.  
```
#include "states.hpp"
#include <raylib.h>
#include <iostream>

enum State {
    STATE_RED, STATE_BLUE, STATE_COUNT
};

void red_init() { printf("Entered red!\n"); }
void red_update() {
    BeginDrawing();
        ClearBackground(RED);
    EndDrawing();

    if(IsKeyPressed(KEY_ENTER)) { SetNextState(STATE_BLUE); }
}
void red_deinit() { printf("Exited red!\n"); }

void blue_init() { printf("Entered blue!\n"); }
void blue_update() {
    BeginDrawing();
        ClearBackground(BLUE);
    EndDrawing();

    if(IsKeyPressed(KEY_ENTER)) { SetNextState(STATE_RED); }
}
void blue_deinit() { printf("Exited blue!\n"); }

int main() {
    InitStates(800, 600, "", 60, STATE_COUNT);

    SetFunctions(STATE_RED, red_init, red_update, red_deinit);
    SetFunctions(STATE_BLUE, blue_init, blue_update, blue_deinit);

    RunStates();

    DeinitStates();

    return 0;
}
```
