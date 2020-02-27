#pragma once

template<Build build, typename T, size_t offset>
class Pointer : public c_data_reference_base
{
public:
	Pointer(const Pointer&) = delete;
	Pointer()
		: c_data_reference_base(build, sizeof(T), offset, nullptr)
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
		ASSERT(m_pPtr != nullptr);
		return impl_ref();
	}

	T& ref()
	{
		ASSERT(m_pPtr != nullptr);
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

