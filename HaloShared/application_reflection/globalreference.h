#pragma once
class GlobalReference
{
public:
	
	GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction);
	GlobalReference(const char* pReferenceName, HaloGameID gameID, intptr_t offset);

	static void InitTree(HaloGameID gameID);
	static void DeinitTree(HaloGameID gameID);
	static void DestroyTree();
private:
	void init();
	GlobalReference* initNode(HaloGameID gameID);
	GlobalReference* deinitNode(HaloGameID gameID);

	GlobalReference* m_pNextGlobalReference;
	HaloGameID m_gameID;
	intptr_t m_offset;
	intptr_t m_originalValue;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static GlobalReference* s_pFirstGlobalReference;
	static GlobalReference* s_pLastGlobalReference;
};

