#include "mandrilllib-private-pch.h"

#define PAGE_ALIGNMENT 4096
#define ALIGN_MEMORY(value, alignment) ((((value - 1) / alignment) + 1) * alignment)

c_virtual_memory_container::c_virtual_memory_container(size_t address_space_size)
	: page_size(get_page_size())
	, address_space_size(ALIGN_MEMORY(address_space_size, page_size))
	, current_size(0)
	, current_size_aligned(0)
	, virtual_memory(0)
{
	virtual_memory = VirtualAlloc(NULL, address_space_size, MEM_RESERVE, PAGE_READWRITE);
	ASSERT(virtual_memory);
}

c_virtual_memory_container::~c_virtual_memory_container()
{
	BOOL virtualfreeResult = VirtualFree(virtual_memory, 0, MEM_RELEASE);
	ASSERT_NO_THROW(virtualfreeResult);
}

void* c_virtual_memory_container::insert_hole(size_t offset, size_t size)
{
	uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(virtual_memory);
	virtualMemoryAddress += offset;
	LPVOID const pfreeVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);
	return insert_hole(pfreeVirtualMemoryAddress, size);
}

void* c_virtual_memory_container::insert_hole(void* position, size_t size)
{
	if (size == 0) return position;

	set_size(current_size + size);

	intptr_t memoryOffset = reinterpret_cast<intptr_t>(position) - reinterpret_cast<intptr_t>(virtual_memory);
	ASSERT(memoryOffset > 0 && static_cast<uintptr_t>(memoryOffset) < address_space_size);

	uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(virtual_memory) + static_cast<uintptr_t>(memoryOffset);
	LPVOID const pNewMemoryVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);

	memmove(position, pNewMemoryVirtualMemoryAddress, size);

	return pNewMemoryVirtualMemoryAddress;
}

void c_virtual_memory_container::set_size(size_t size)
{
	size_t alignedSize = ALIGN_MEMORY(size, PAGE_ALIGNMENT);
	if (current_size_aligned > alignedSize) // can we trim the tail of this memory region?
	{
		uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(virtual_memory);
		virtualMemoryAddress += alignedSize;
		LPVOID const pfreeVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);

		size_t const amountTofree = current_size_aligned - alignedSize;
		ASSERT(amountTofree % PAGE_ALIGNMENT == 0);

		if (amountTofree > 0)
		{
			// we can free some commited memory
			BOOL virtualfreeResult = __pragma(warning(suppress: 6250)) VirtualFree(pfreeVirtualMemoryAddress, amountTofree, MEM_DECOMMIT);
			ASSERT(virtualfreeResult);
		}
	}
	else if (alignedSize > current_size_aligned)
	{
		uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(virtual_memory);
		virtualMemoryAddress += current_size_aligned;
		LPVOID const pCommitVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);

		size_t const amountToCommit = alignedSize - current_size_aligned;
		ASSERT(amountToCommit % PAGE_ALIGNMENT == 0);

		if (amountToCommit > 0)
		{
			// we can free some commited memory
			LPVOID virtualAllocResult = __pragma(warning(suppress: 6250)) VirtualAlloc(pCommitVirtualMemoryAddress, amountToCommit, MEM_COMMIT, PAGE_READWRITE);
			ASSERT(virtualAllocResult);
		}
	}
	current_size = size;
	current_size_aligned = alignedSize;
}

size_t c_virtual_memory_container::get_page_size()
{
	SYSTEM_INFO systemInfo = {};
	GetSystemInfo(&systemInfo);
	return systemInfo.dwPageSize;
}
