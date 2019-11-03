#pragma once

#include <stdio.h>

#define _LOGCOMBINE1(X,Y) X##Y  // helper macro
#define _LOGCOMBINE(X,Y) _LOGCOMBINE1(X,Y)

#define WriteLineNoSpamVerbose(str, ...) \
static std::string _LOGCOMBINE(__string_last, __LINE__) = ""; \
static char _LOGCOMBINE(__buffer_current, __LINE__)[1024] = {}; \
snprintf(_LOGCOMBINE(__buffer_current, __LINE__), sizeof(_LOGCOMBINE(__buffer_current, __LINE__)), str, ##__VA_ARGS__); \
if(_LOGCOMBINE(__string_last, __LINE__) != _LOGCOMBINE(__buffer_current, __LINE__)) \
{ \
	_LOGCOMBINE(__string_last, __LINE__) = _LOGCOMBINE(__buffer_current, __LINE__); \
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
	printf(str, ##__VA_ARGS__); \
	printf("\n"); \
} \
(void)(0)

#define WriteLineNoSpamVerboseC(str, ...) \
static char _LOGCOMBINE(__buffer_last, __LINE__) [1024] = {}; \
static char _LOGCOMBINE(__buffer_current, __LINE__) [1024] = {}; \
snprintf(_LOGCOMBINE(__buffer_current, __LINE__), sizeof(_LOGCOMBINE(__buffer_current, __LINE__)), str, ##__VA_ARGS__); \
if(strcmp(_LOGCOMBINE(__buffer_last, __LINE__), _LOGCOMBINE(__buffer_current, __LINE__)) != 0) \
{ \
	snprintf(_LOGCOMBINE(__buffer_last, __LINE__), sizeof(_LOGCOMBINE(__buffer_last, __LINE__)), str, ##__VA_ARGS__); \
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); \
	printf(str, ##__VA_ARGS__); \
	printf("\n"); \
} \
(void)(0)

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
