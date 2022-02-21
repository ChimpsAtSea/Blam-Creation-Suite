#pragma once

/* ---------- macros */

#ifdef _DEBUG
#	define vassert(expr, diag) if (!(expr) && !assert_handle(diag, __FILE__, __LINE__)) assert_halt(diag, __FILE__, __LINE__)
#else
#	define vassert(expr, diag) (expr)
#endif

#ifndef blamlib_assert
#ifdef _DEBUG
#	define blamlib_assert(expr) vassert(expr, #expr)
#else
#	define blamlib_assert(expr) (expr)
#endif
#endif

/* ---------- prototypes/CSERIES_ASSERTS.CPP */

bool assert_handle(
	char const* message,
	char const* file,
	int line);

[[noreturn]]
void assert_halt(
	char const *message,
	char const *file,
	int line);
