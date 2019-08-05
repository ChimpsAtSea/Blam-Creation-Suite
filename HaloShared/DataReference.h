#pragma once

class DataReferenceBase
{
public:
	DataReferenceBase(
		HaloGameID gameID,
		size_t offset
	)
		: m_gameID(gameID),
		m_offset(offset),
		m_pPtr(nullptr),
		m_pNextDataReference(nullptr)
	{
		if (g_pDataReferenceBaseBaseFirst == nullptr)
		{
			g_pDataReferenceBaseBaseFirst = this;
			g_pDataReferenceBaseBaseLast = this;
		}
		else
		{
			g_pDataReferenceBaseBaseLast->m_pNextDataReference = this;
			g_pDataReferenceBaseBaseLast = this;
		}

		if (IsHaloExecutableLoaded(gameID))
		{
			processNode(gameID);
		}
	}

protected:
	void* m_pPtr;
private:
	HaloGameID m_gameID;
	size_t m_offset;
	static DataReferenceBase* g_pDataReferenceBaseBaseFirst;
	static DataReferenceBase* g_pDataReferenceBaseBaseLast;
	DataReferenceBase* m_pNextDataReference;

public:
	static void ProcessTree(HaloGameID gameID)
	{
		if (!g_pDataReferenceBaseBaseFirst)
		{
			return;
		}
		g_pDataReferenceBaseBaseFirst->processNode(gameID);
	}

private:

	void processNode(HaloGameID gameID)
	{
		if (m_gameID == gameID)
		{
			m_pPtr = getPointer(gameID);
		}
		if (m_pNextDataReference)
		{
			m_pNextDataReference->processNode(gameID);
		}
	}

	char* getPointer(HaloGameID gameID) const
	{
		HMODULE hModule = GetModuleHandleA(GetHaloExecutableString(gameID));
		char* pBaseAddress = reinterpret_cast<char*>(hModule);
		char* ptr = reinterpret_cast<char*>(pBaseAddress + (m_offset - GetHaloBaseAddress(gameID)));
		return ptr;
	}


};

template<HaloGameID gameid, typename T, size_t offset>
class DataReference : DataReferenceBase
{
private:
public:
	DataReference(const DataReference&) = delete;
	DataReference()
		: DataReferenceBase(gameid, offset)
	{

	}

	T* ptr() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}

	volatile T* volatile_ptr() const
	{
		return static_cast<volatile T*>(ptr());
	}

	T& ref() const
	{
		return *ptr();
	}

	T& operator=(T value)
	{
		T& reference = ref();
		reference = value;
		return reference;
	}

	T& operator->()
	{
		return ref();
	}

	T const& operator->() const
	{
		return ref();
	}

	operator T& () const
	{
		return ref();
	}

	operator bool() const
	{
		T& r = ref();
		return (bool)r;
	}
};

template<typename T, size_t offset>
using HaloReachReference = DataReference<HaloGameID::HaloReach, T, offset>;