#pragma once

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
