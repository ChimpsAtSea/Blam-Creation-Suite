#pragma once

#define vector_erase_by_value_helper(vector, value) vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());

#define StaticClassSizeCheck(TYPE) static_assert(sizeof(TYPE) == 1, "Static classes shouldn't contain any data");

#define CONCAT(x, y) x##y
#define STRINGIFY(s) __STRINGIFY(s)
#define __STRINGIFY(s) #s

#define CHECK_STRUCTURE_SIZE(type, size) \
static constexpr size_t k##type = sizeof(type);\
static_assert(k##type == size, STRINGIFY(type) " is incorrect size");\

#define COMBINE1(X,Y) X##Y
#define COMBINE(X,Y) COMBINE1(X,Y)
#define RUNONCE(...) do { \
static bool COMBINE(__runonceflag_, __LINE__) = false; \
if (COMBINE(__runonceflag_, __LINE__) == false) \
{ \
	__VA_ARGS__; \
	COMBINE(__runonceflag_, __LINE__) = true; \
} } while(0)

#ifdef _DEBUG
#define DEBUG_ONLY(...) do { __VA_ARGS__; } while (0)
#else
#define DEBUG_ONLY(...)
#endif

template<typename T>
constexpr decltype(auto) underlying_cast(T value)
{
	using ResultType = __underlying_type(T); // supported on most main compilers
	return static_cast<ResultType>(value);
}

#define underlying(type) __underlying_type(type)

#ifdef assert
#undef assert
#endif
#define assert assert_is_banned_use_ASSERT_and_DEBUG_ASSERT

#ifdef _WIN64
#define static_assert_64 static_assert
#define static_assert_32(...)
#else
#define static_assert_64(...)
#define static_assert_32 static_assert
#endif
