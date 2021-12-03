#ifndef STATES_H
#define STATES_H

#include <stdint.h>

typedef void (*FunctionType)();

void InitStates(int32_t width, int32_t height, const char* window_name, int32_t target_fps, int32_t count);
void DeinitStates();

void SetFunctions(int32_t index, FunctionType init, FunctionType update, FunctionType deinit);
void SetInitFunction(int32_t index, FunctionType init);
void SetUpdateFunction(int32_t index, FunctionType update);
void SetDeinitFunction(int32_t index, FunctionType deinit);

FunctionType GetInitFunction(int32_t index);
FunctionType GetUpdateFunction(int32_t index);
FunctionType GetDeinitFunction(int32_t index);

void SetNextState(int32_t next);

void RunStates();

#endif
