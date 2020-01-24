#pragma once

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
