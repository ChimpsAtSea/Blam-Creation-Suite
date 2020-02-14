#pragma once

template<typename T>
class reference_symbol
{
public:
	reference_symbol(const char* pReferenceName, OffsetFunction offsetFunction)
		:m_offset(0)
	{
		// pointer to this allocation is stored internally in tree structure
		new GlobalReference(pReferenceName, offsetFunction);
	}
	reference_symbol(const char* pReferenceName, EngineVersion engineVersion, BuildVersion buildVersion, intptr_t offset)
		:m_offset(offset)
	{
		// pointer to this allocation is stored internally in tree structure
		new GlobalReference(pReferenceName, engineVersion, buildVersion, offset);
	}
	operator T& () const
	{
		return *(T*)(0); // return null to allow checking if this value exists
	}
private:
	intptr_t m_offset;
};
