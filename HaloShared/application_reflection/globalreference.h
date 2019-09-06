#pragma once
class GlobalReference
{
public:
	
	GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction);
	GlobalReference(const char* pReferenceName, HaloGameID gameID, intptr_t offset);

	static void InitTree(HaloGameID gameID);
	static void DeinitTree(HaloGameID gameID);

private:
	void init();
	GlobalReference* processNode(HaloGameID gameID);

	GlobalReference* m_pNextGlobalReference;
	HaloGameID m_gameID;
	intptr_t m_offset;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static GlobalReference* s_pFirstGlobalReference;
	static GlobalReference* s_pLastGlobalReference;
};

