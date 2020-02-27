#pragma once

template<typename T, find_offset_func find_offset>
class BasicDataEx : public c_data_reference_base
{
public:
	BasicDataEx(const BasicDataEx&) = delete;
	BasicDataEx()
		: c_data_reference_base(Build::NotSet, sizeof(T), 0, find_offset)
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

