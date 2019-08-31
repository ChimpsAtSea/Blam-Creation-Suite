#pragma once

#include <stdio.h>

#define WriteLineVerbose(str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
printf(str, ##__VA_ARGS__); \
printf("\n")

#define WriteVerbose(str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
printf(str, ##__VA_ARGS__)

#define WriteColoredLineVerbose(color, str, ...) \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  \
printf(str, ##__VA_ARGS__); printf("\n"); \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

#define WriteColoredVerbose(color, str, ...)  \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);  \
printf(str, ##__VA_ARGS__); \
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)

#define WriteColoredPrefixVerbose(color, prefix, str, ...) \
WriteColoredVerbose(color, "%s ", prefix); \
WriteLineVerbose(str, ##__VA_ARGS__)


#define ThrowDebugger() if (IsDebuggerPresent()) { throw; }
