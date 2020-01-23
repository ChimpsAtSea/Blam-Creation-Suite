#include "mantlelib-private-pch.h"

#define PAGE_ALIGNMENT 4096
#define ALIGN_MEMORY(value, alignment) ((((value - 1) / alignment) + 1) * alignment)

VirtualMemoryContainer::VirtualMemoryContainer(size_t addressSpaceSize)
	: m_pageSize(getPageSize())
	, m_addressSpaceSize(ALIGN_MEMORY(addressSpaceSize, m_pageSize))
	, m_currentSize(0)
	, m_currentSizeAligned(0)
	, m_pVirtualMemory(0)
{
	m_pVirtualMemory = VirtualAlloc(NULL, addressSpaceSize, MEM_RESERVE, PAGE_READWRITE);
	assert(m_pVirtualMemory);
}

VirtualMemoryContainer::~VirtualMemoryContainer()
{
	BOOL virtualFreeResult = VirtualFree(m_pVirtualMemory, 0, MEM_RELEASE);
	assert(virtualFreeResult);
}

void* VirtualMemoryContainer::InsertHole(size_t offset, size_t size)
{
	uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(m_pVirtualMemory);
	virtualMemoryAddress += offset;
	LPVOID const pFreeVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);
	return InsertHole(pFreeVirtualMemoryAddress, size);
}

void* VirtualMemoryContainer::InsertHole(void* pPosition, size_t size)
{
	if (size == 0) return pPosition;

	SetSize(m_currentSize + size);

	intptr_t memoryOffset = reinterpret_cast<intptr_t>(pPosition) - reinterpret_cast<intptr_t>(m_pVirtualMemory);
	assert(memoryOffset > 0 && static_cast<uintptr_t>(memoryOffset) < m_addressSpaceSize);

	uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(m_pVirtualMemory) + static_cast<uintptr_t>(memoryOffset);
	LPVOID const pNewMemoryVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);

	memmove(pPosition, pNewMemoryVirtualMemoryAddress, size);

	return pNewMemoryVirtualMemoryAddress;
}

void VirtualMemoryContainer::SetSize(size_t size)
{
	size_t alignedSize = ALIGN_MEMORY(size, PAGE_ALIGNMENT);
	if (m_currentSizeAligned > alignedSize) // can we trim the tail of this memory region?
	{
		uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(m_pVirtualMemory);
		virtualMemoryAddress += alignedSize;
		LPVOID const pFreeVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);

		size_t const amountToFree = m_currentSizeAligned - alignedSize;
		assert(amountToFree % PAGE_ALIGNMENT == 0);

		if (amountToFree > 0)
		{
			// we can free some commited memory
			BOOL virtualFreeResult = __pragma(warning(suppress: 6250)) VirtualFree(pFreeVirtualMemoryAddress, amountToFree, MEM_DECOMMIT);
			assert(virtualFreeResult);
		}
	}
	else if (alignedSize > m_currentSizeAligned)
	{
		uintptr_t virtualMemoryAddress = reinterpret_cast<uintptr_t>(m_pVirtualMemory);
		virtualMemoryAddress += m_currentSizeAligned;
		LPVOID const pCommitVirtualMemoryAddress = reinterpret_cast<LPVOID>(virtualMemoryAddress);

		size_t const amountToCommit = alignedSize - m_currentSizeAligned;
		assert(amountToCommit % PAGE_ALIGNMENT == 0);

		if (amountToCommit > 0)
		{
			// we can free some commited memory
			LPVOID virtualAllocResult = __pragma(warning(suppress: 6250)) VirtualAlloc(pCommitVirtualMemoryAddress, amountToCommit, MEM_COMMIT, PAGE_READWRITE);
			assert(virtualAllocResult);
		}
	}
	m_currentSize = size;
	m_currentSizeAligned = alignedSize;
}

size_t VirtualMemoryContainer::getPageSize()
{
	SYSTEM_INFO systemInfo = {};
	GetSystemInfo(&systemInfo);
	return systemInfo.dwPageSize;
}
