#include "bcs.h"
#include <stdio.h>

BCS_SHARED extern "C" int python_test(int a, int b)
{
	return a + b;
}

// Define the prototype of the callback function in C
typedef void (*callback_type)(int);

// Define a function that takes a callback and calls it with the value 42
BCS_SHARED extern "C" void call_with_callback(callback_type callback) {
    printf("Calling callback with value 42...\n");
    callback(42);
}
