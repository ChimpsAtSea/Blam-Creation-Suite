#pragma once
class GlobalReference
{
public:
	
	GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction);
	GlobalReference(const char* pReferenceName, Engine engine, Build build, intptr_t offset);

	static void InitTree(Engine engine, Build build);
	static void DeinitTree(Engine engine, Build build);
	static void DestroyTree();
private:
	void init();
	GlobalReference* initNode(Engine engine, Build build);
	GlobalReference* deinitNode(Engine engine, Build build);

	GlobalReference* m_pNextGlobalReference;
	Engine m_engine;
	Build m_build;
	intptr_t m_offset;
	intptr_t m_originalValue;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static GlobalReference* s_pFirstGlobalReference;
	static GlobalReference* s_pLastGlobalReference;
};

