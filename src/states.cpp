#include <raylib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "states.hpp"

typedef struct FunctionState {
    FunctionType init;
    FunctionType update;
    FunctionType deinit;
} FunctionState;

typedef struct Data {
    int32_t state_count;
    FunctionState* states;
    int32_t curr_state;
    int32_t next_state;
} Data;

static Data DATA = { 0 };

void InitStates(int32_t width, int32_t height, const char* window_name, int32_t target_fps, int32_t count) {
    InitWindow(width, height, window_name);
    SetTargetFPS(target_fps);

    DATA.states = (FunctionState*)malloc(count * sizeof(FunctionState));
    DATA.state_count = count;
}

void SetFunctions(int32_t index, FunctionType init, FunctionType update, FunctionType deinit) {
    if(index < 0 || index >= DATA.state_count) {
        perror("SetState index was out of bounds!\n");
        exit(1);
    }

    DATA.states[index].init = init;
    DATA.states[index].update = update;
    DATA.states[index].deinit = deinit;
}

void index_check(int32_t index, const char* func_name) {
    if(index >= DATA.state_count) {
        printf("State %d in call to %s() is invalid!", index, func_name);
        exit(1);
    }
}

void SetInitFunction(int32_t index, FunctionType init) {
    index_check(index, __func__);
    DATA.states[index].init = init;
}

void SetUpdateFunction(int32_t index, FunctionType update) {
    index_check(index, __func__);
    DATA.states[index].update = update;
}

void SetDeinitFunction(int32_t index, FunctionType deinit) {
    index_check(index, __func__);
    DATA.states[index].deinit = deinit;
}

FunctionType GetInitFunction(int32_t index) {
    index_check(index, __func__);
    return DATA.states[index].init;
}
FunctionType GetUpdateFunction(int32_t index) {
    index_check(index, __func__);
    return DATA.states[index].update;
}
FunctionType GetDeinitFunction(int32_t index) {
    index_check(index, __func__);
    return DATA.states[index].deinit;
}

void SetNextState(int32_t next) {
    DATA.next_state = next;
}

#define RUN(func) if(func != 0) { (*func)(); }

void RunStates() {
    RUN(DATA.states[DATA.curr_state].init);
    while(!WindowShouldClose()) {
        RUN(DATA.states[DATA.curr_state].update);

        if(DATA.curr_state != DATA.next_state) { 
            RUN(DATA.states[DATA.curr_state].deinit);
            RUN(DATA.states[DATA.next_state].init);
            DATA.curr_state = DATA.next_state;
        }
    }
    RUN(DATA.states[DATA.curr_state].deinit);
}

void DeinitStates() {
    free(DATA.states);
    CloseWindow();
}
