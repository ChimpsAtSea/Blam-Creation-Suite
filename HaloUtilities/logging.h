#pragma once

#include <stdio.h>

#define WriteLineVerbose(str, ...) printf(str, ##__VA_ARGS__); printf("\n");
#define WriteVerbose(str, ...) printf(str, ##__VA_ARGS__);
#define ThrowDebugger() if (IsDebuggerPresent()) { throw; }
