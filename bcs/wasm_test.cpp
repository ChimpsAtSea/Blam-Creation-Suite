#include <stdio.h>

#define EXPORT __attribute__((__visibility__("default")))

int main()
{
	return 0;
}

EXPORT extern "C" int monkey_two(int a)
{
	return printf("test %i", a);
}

EXPORT extern "C" int monkey_do(int a, int b)
{
	try
	{
		throw a + b + 100;
	}
	catch (int test)
	{
		return test;
	}
	catch (...)
	{

	}
	return a + b;
}

char scratch[500] = "hello world";

EXPORT extern "C" void* __scratch(void* ptr, size_t size)
{
	return scratch;
}

EXPORT extern "C" size_t __read1(unsigned char* ptr)
{
	return *ptr;
}

EXPORT extern "C" void __write1(unsigned char* ptr, unsigned char value)
{
	*ptr = value;
}

EXPORT extern "C" size_t __read2(unsigned short* ptr)
{
	return *ptr;
}

EXPORT extern "C" void __write2(unsigned short* ptr, unsigned short value)
{
	*ptr = value;
}

EXPORT extern "C" size_t __read4(unsigned int* ptr)
{
	return *ptr;
}

EXPORT extern "C" void __write4(unsigned int* ptr, unsigned int value)
{
	*ptr = value;
}

EXPORT extern "C" size_t __read8(unsigned long long* ptr)
{
	return *ptr;
}

EXPORT extern "C" void __write8(unsigned long long* ptr, unsigned long long value)
{
	*ptr = value;
}
