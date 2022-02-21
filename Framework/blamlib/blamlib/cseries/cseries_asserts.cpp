#include <blamlib/cseries/cseries_asserts.h>
#include <cstdio>
#include <cstdlib>

/* ---------- code */

bool assert_handle(
	[[maybe_unused]] char const* message,
	[[maybe_unused]] char const* file,
	[[maybe_unused]] int line)
{
	// TODO
	return false;
}

[[noreturn]]
void assert_halt(
	char const* message,
	char const* file,
	int line)
{
	printf("ERROR: %s, FILE: %s, LINE: %ull\n", message, file, line);
	exit(-1);
}
