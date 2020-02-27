#pragma once

template<typename T, find_offset_func find_offset>
class PointerEx : public c_data_reference_base
{
public:
	PointerEx(const PointerEx&) = delete;
	PointerEx()
		: c_data_reference_base(_build_not_set, sizeof(T), 0, find_offset)
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
