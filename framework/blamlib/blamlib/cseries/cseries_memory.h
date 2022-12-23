#pragma once

/* ---------- prototypes/CSERIES_MEMORY.CPP */

void *csmemcpy(void *destination, const void *source, unsigned int length);
void *csmemmove(void *destination, const void *source, unsigned int length);
void *csmemset(void *address, int value, unsigned int length);
int csmemcmp(const void *p1, const void *p2, unsigned int length);
