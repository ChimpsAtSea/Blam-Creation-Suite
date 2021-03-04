#pragma once

template<typename T>
class reference_symbol
{
public:
	reference_symbol(const char* pReferenceName, reference_symbol_offset_function offset_function)
		:offset(0)
	{
		// pointer to this allocation is stored internally in tree structure
		new c_global_reference(pReferenceName, offset_function);
	}
	reference_symbol(const char* pReferenceName, s_engine_platform_build engine_platform_build, intptr_t offset)
		:offset(offset)
	{
		// pointer to this allocation is stored internally in tree structure
		new c_global_reference(pReferenceName, engine_platform_build, offset);
	}
	operator T& () const
	{
		return *(T*)(0); // return null to allow checking if this value exists
	}
private:
	intptr_t offset;
};
