#pragma once
class GlobalReference
{
public:
	
	GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction);
	GlobalReference(const char* pReferenceName, EngineVersion engineVersion, BuildVersion buildVersion, intptr_t offset);

	static void InitTree(EngineVersion engineVersion, BuildVersion buildVersion);
	static void DeinitTree(EngineVersion engineVersion, BuildVersion buildVersion);
	static void DestroyTree();
private:
	void init();
	GlobalReference* initNode(EngineVersion engineVersion, BuildVersion buildVersion);
	GlobalReference* deinitNode(EngineVersion engineVersion, BuildVersion buildVersion);

	GlobalReference* m_pNextGlobalReference;
	EngineVersion m_engineVersion;
	BuildVersion m_buildVersion;
	intptr_t m_offset;
	intptr_t m_originalValue;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static GlobalReference* s_pFirstGlobalReference;
	static GlobalReference* s_pLastGlobalReference;
};

