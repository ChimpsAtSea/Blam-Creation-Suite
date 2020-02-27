#pragma once

template<typename T>
class reference_symbol
{
public:
	reference_symbol(const char* pReferenceName, OffsetFunction offsetFunction)
		:m_offset(0)
	{
		// pointer to this allocation is stored internally in tree structure
		new c_global_reference(pReferenceName, offsetFunction);
	}
	reference_symbol(const char* pReferenceName, Engine engine, Build build, intptr_t offset)
		:m_offset(offset)
	{
		// pointer to this allocation is stored internally in tree structure
		new c_global_reference(pReferenceName, engine, build, offset);
	}
	operator T& () const
	{
		return *(T*)(0); // return null to allow checking if this value exists
	}
private:
	intptr_t m_offset;
};
