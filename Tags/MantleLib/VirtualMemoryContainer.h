#pragma once
class VirtualMemoryContainer
{
public:
	VirtualMemoryContainer(size_t addressSpaceSize);
	~VirtualMemoryContainer();

	void* InsertHole(size_t offset, size_t size);
	void* InsertHole(void* pPosition, size_t size);
	void SetSize(size_t size);
	inline char* GetData() const { return static_cast<char*>(m_pVirtualMemory); }
	inline size_t GetSize() const { return m_currentSizeAligned; }
	inline size_t GetSizeAligned() const { return m_currentSizeAligned; }

protected:
	static size_t getPageSize();

	const size_t m_pageSize;
	const size_t m_addressSpaceSize;
	size_t m_currentSize;
	size_t m_currentSizeAligned;
	LPVOID m_pVirtualMemory;
};

