#pragma once

class DataReferenceBase
{
public:
	DataReferenceBase(
		EngineVersion engineVersion,
		BuildVersion buildVersion,
		size_t dataSize,
		size_t offset,
		intptr_t(find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion)
	)
		: m_buildVersion(buildVersion),
		m_dataSize(dataSize),
		m_offset(offset),
		m_pPtr(nullptr),
		m_pNextDataReference(nullptr),
		m_find_offset_func(find_offset_func)
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

		if (buildVersion != BuildVersion::NotSet && IsHaloExecutableLoaded(engineVersion))
		{
			initNode(engineVersion, buildVersion);
		}
	}

protected:
	void* m_pPtr;
private:
	intptr_t(*m_find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion);
	BuildVersion m_buildVersion;
	size_t m_dataSize;
	size_t m_offset;
	static DataReferenceBase* g_pDataReferenceBaseBaseFirst;
	static DataReferenceBase* g_pDataReferenceBaseBaseLast;
	DataReferenceBase* m_pNextDataReference;

public:
	static void InitTree(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->initNode(engineVersion, buildVersion);
		}
	}

	static void DeinitTree(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->deinitNode();
		}
	}

private:

	DataReferenceBase* initNode(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		if (m_pPtr == nullptr)
		{
			if (m_buildVersion == BuildVersion::NotSet)
			{
				assert(m_find_offset_func);
				m_pPtr = getPointer(engineVersion, buildVersion);
			}
			if (m_buildVersion == buildVersion)
			{
				m_pPtr = getPointer(engineVersion, buildVersion);
				assert(m_pPtr);
			}
		}
		return m_pNextDataReference;
	}
	DataReferenceBase* deinitNode()
	{
		if (m_pPtr == nullptr)
		{
			
		}
		return m_pNextDataReference;
	}

	void* getPointer(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		intptr_t offset = m_offset;
		if (offset == 0 && m_find_offset_func)
		{
			offset = m_find_offset_func(engineVersion, buildVersion);

			if (offset == ~intptr_t())
			{
				return nullptr;
			}

			assert(m_buildVersion == BuildVersion::NotSet && offset >= GetHaloBaseAddress(buildVersion)/*, "Offset is out of bounds"*/);
			assert(m_buildVersion == BuildVersion::NotSet && offset < GetHaloTopAddress(buildVersion)/*, "Offset is out of bounds"*/);
			assert(m_buildVersion == BuildVersion::NotSet && static_cast<intptr_t>(offset + m_dataSize) < GetHaloTopAddress(buildVersion)/*, "Offset is out of bounds"*/);
		}

		HMODULE hModule = GetModuleHandleA(GetHaloExecutableString(engineVersion));
		char* pBaseAddress = reinterpret_cast<char*>(hModule);
		char* ptr = reinterpret_cast<char*>(pBaseAddress + (offset - GetHaloBaseAddress(buildVersion)));
		return ptr;
	}


};

template<BuildVersion buildVersion, typename T, size_t offset>
class BasicData : public DataReferenceBase
{
public:
	BasicData(const BasicData&) = delete;
	BasicData()
		: DataReferenceBase(buildVersion, sizeof(T), offset, nullptr)
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

template<BuildVersion buildVersion, typename T, size_t offset>
class Data : public DataReferenceBase
{
public:
	Data(const Data&) = delete;
	Data()
		: DataReferenceBase(buildVersion, sizeof(T), offset, nullptr)
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

template<BuildVersion buildVersion, typename T, size_t offset>
class Pointer : public DataReferenceBase
{
public:
	Pointer(const Pointer&) = delete;
	Pointer()
		: DataReferenceBase(buildVersion, sizeof(T), offset, nullptr)
	{

	}

	volatile T volatile_ptr() const
	{
		return static_cast<volatile T>(impl_ref());
	}

	T operator->()
	{
		return impl_ref();
	}

	T ptr()
	{
		assert(m_pPtr != nullptr);
		return impl_ref();
	}

	T& ref()
	{
		assert(m_pPtr != nullptr);
		return impl_ref();
	}

	operator bool()
	{
		return !!this->operator->();
	}

protected:
	T& impl_ref() const
	{
		return *PointerToPointer();
	}

	T* PointerToPointer() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}
};

template<typename T, intptr_t(find_offset_func)(BuildVersion buildVersion)>
class BasicDataEx : public DataReferenceBase
{
public:
	BasicDataEx(const BasicDataEx&) = delete;
	BasicDataEx()
		: DataReferenceBase(BuildVersion::NotSet, sizeof(T), 0, find_offset_func)
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

template<typename T, intptr_t(find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion)>
class DataEx : public DataReferenceBase
{
public:
	DataEx(const DataEx&) = delete;
	DataEx()
		: DataReferenceBase(EngineVersion::NotSet, BuildVersion::NotSet, sizeof(T), 0, find_offset_func)
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

template<typename T, intptr_t(find_offset_func)(BuildVersion buildVersion)>
class PointerEx : public DataReferenceBase
{
public:
	PointerEx(const PointerEx&) = delete;
	PointerEx()
		: DataReferenceBase(BuildVersion::NotSet, sizeof(T), 0, find_offset_func)
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

	operator T& () const
	{
		return Reference();
	}

protected:
	T* PointerToPointer() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}
};

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_Pointer = Pointer<BuildVersion::Build_1_887_0_0, T, offset>;

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_BasicData = BasicData<BuildVersion::Build_1_887_0_0, T, offset>;

template<typename T, size_t offset>
using HaloReach_2019_Jun_24_Data = Data<BuildVersion::Build_1_887_0_0, T, offset>;
