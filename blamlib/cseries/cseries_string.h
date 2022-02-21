#pragma once

/* ---------- constants */

enum
{
	k_maximum_string_size = 0x100000
};

/* ---------- prototypes/CSERIES_STRING.CPP */

bool ascii_islower(int c);
bool ascii_isupper(int c);
bool ascii_isdigit(int c);
bool ascii_isalnum(int c);
bool ascii_isspace(int c);
int ascii_tolower(int c);
int ascii_toupper(int c);

char *csstrchr(char *string, int c);
int csstrcmp(char const *s1, char const *s2);
int csstricmp(char *s1, char *s2);
unsigned int csstrlen(char const *string);
int csstrncmp(char const *s1, char const *s2, unsigned int max_length);
int csstrnicmp(char *s1, char *s2, unsigned int max_length);
unsigned int csstrnlen(char const *string, unsigned int max_length);
char *csstrnlwr(char *string, unsigned int max_length);
char *csstrnupr(char *string, unsigned int max_length);
char *csstrnzcat(char *s1, char *s2, unsigned int s1_size);
char *csstrnzcpy(char *s1, char const *s2, unsigned int s1_size);
char *csstrnzncat(char *s1, char *s2, unsigned int s1_size, unsigned int count);
char *csstrpbrk(char *string, char const *control);
char *csstrrchr(char *string, int c);
char *csstrstr(char *string, char const *substring);
char *csstrtok(char *string, char const *delimiter);

char *csnzprintf(char *buffer, unsigned int size, char const *format, ...);
long cvsnzprintf(char *buffer, unsigned int size, char const *format, void *args);

/*
TODO:
csnzappendf
csnzprintf
csnzprintfi
cvsnzprintf
*/
