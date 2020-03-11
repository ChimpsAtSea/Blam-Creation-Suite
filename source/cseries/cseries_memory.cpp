#include <cseries/cseries_asserts.h>
#include <cseries/cseries_memory.h>
#include <cstring>

void *csmemcpy(void *destination, const void *source, unsigned long length)
{
	assert(destination && source);

	errno_t memcpy_result = memcpy_s(destination, length, source, length);
	assert(memcpy_result == 0);

	return destination;
}

void *csmemmove(void *destination, const void *source, unsigned long length)
{
	assert(destination && source);

	errno_t memmove_result = memmove_s(destination, length, source, length);
	assert(memmove_result == 0);

	return destination;
}

void *csmemset(void *address, int value, unsigned long length)
{
	assert(address);

	void *memset_result = memset(address, value, length);
	assert(memset_result);

	return memset_result;
}

int csmemcmp(const void *p1, const void *p2, unsigned long length)
{
	assert(p1 && p2);
	return memcmp(p1, p2, length);
}
