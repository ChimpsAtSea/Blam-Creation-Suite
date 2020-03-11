#pragma once

/* ---------- prototypes/CSERIES_MEMORY.CPP */

void *csmemcpy(void *destination, const void *source, unsigned long length);
void *csmemmove(void *destination, const void *source, unsigned long length);
void *csmemset(void *address, int value, unsigned long length);
int csmemcmp(const void *p1, const void *p2, unsigned long length);
