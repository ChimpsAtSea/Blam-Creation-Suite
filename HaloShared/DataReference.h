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
class DataReference : public DataReferenceBase
{
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

	T& PointerReference() const
	{
		return *ptr();
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};

template<HaloGameID gameid, typename T, size_t offset>
class DataReferenceEx : public DataReferenceBase
{
public:
	DataReferenceEx(const DataReferenceEx&) = delete;
	DataReferenceEx()
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

	T& PointerReference() const
	{
		return *ptr();
	}

	T& operator=(T value)
	{
		T& reference = PointerReference();
		reference = value;
		return reference;
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};

template<HaloGameID gameid, typename T, size_t offset>
class DataPointer : public DataReferenceBase
{
public:
	DataPointer(const DataPointer&) = delete;
	DataPointer()
		: DataReferenceBase(gameid, offset)
	{

	}

	T& Reference() const
	{
		return *PointerToPointer();
	}

	volatile T volatile_ptr() const
	{
		return static_cast<volatile T>(Reference());
	}

	T operator->()
	{
		return Reference();
	}

	operator bool() const
	{
		return !!this->operator->();
	}

protected:
	T* PointerToPointer() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}
};

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_Pointer = DataPointer<HaloGameID::HaloReach_2019_Jun_24, T, offset>;

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_BasicData = DataReference<HaloGameID::HaloReach_2019_Jun_24, T, offset>;

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_Data = DataReferenceEx<HaloGameID::HaloReach_2019_Jun_24, T, offset>;