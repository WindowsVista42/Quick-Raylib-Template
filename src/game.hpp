#pragma once

#include <raylib.h>
#include <raymath.h>
#include "defs.hpp"
#include "game.hpp"
#include "states.hpp"

static const i32 WIDTH = 800;
static const i32 HEIGHT = 600;
static const char* WINDOW_NAME = "";
static const i32 TARGET_FPS = 60;

namespace STATE { enum e: i32 {
    START, GAME, COUNT,
};};

static void game_init() {}
static void game_update() {
    BeginDrawing();
        ClearBackground(RED);
        DrawText("PLAYING THE GAME", 100, 100, 20, BLACK);
    EndDrawing();

    if(IsKeyPressed(KEY_ENTER)) { SetNextState(STATE::START); }
}
static void game_deinit() {}

static void start_init() {}
static void start_update() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("WELCOME TO THE GAME", 100, 100, 20, BLACK);
    EndDrawing();

    if(IsKeyPressed(KEY_ENTER)) { SetNextState(STATE::GAME); }
}
static void start_deinit() {}

