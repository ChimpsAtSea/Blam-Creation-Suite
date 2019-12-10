#pragma once
class GlobalReference
{
public:
	
	GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction);
	GlobalReference(const char* pReferenceName, BuildVersion buildVersion, intptr_t offset);

	static void InitTree(BuildVersion buildVersion);
	static void DeinitTree(BuildVersion buildVersion);
	static void DestroyTree();
private:
	void init();
	GlobalReference* initNode(BuildVersion buildVersion);
	GlobalReference* deinitNode(BuildVersion buildVersion);

	GlobalReference* m_pNextGlobalReference;
	BuildVersion m_buildVersion;
	intptr_t m_offset;
	intptr_t m_originalValue;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static GlobalReference* s_pFirstGlobalReference;
	static GlobalReference* s_pLastGlobalReference;
};

