#include "game.hpp"
#include "states.hpp"

int main() {
    InitStates(WIDTH, HEIGHT, WINDOW_NAME, TARGET_FPS, STATE::COUNT);
    SetFunctions(STATE::START, start_init, start_update, start_deinit);
    SetFunctions(STATE::GAME, game_init, game_update, game_deinit);

    RunStates();

    DeinitStates();

    return 0;
}
