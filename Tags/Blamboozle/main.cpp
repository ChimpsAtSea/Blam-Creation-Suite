#include "blamboozle-private-pch.h"

int wmain(int argc, const wchar_t** argv)
{
	init_command_line();
	init_console();

	int result = blamboozle_run();
	
	deinit_console();
	deinit_command_line();
	return result;
}

//
//void* operator new(std::size_t size) throw(std::bad_alloc) 
//{
//    printf("allocating %i bytes", (int)size);
//    void* address = malloc(size);
//    printf(" %p\n", address);
//    return address;
//}
//
//void operator delete(void* mem) throw() 
//{
//    printf("deallocating %p\n", mem);
//    //free(mem);
//}
