#pragma once
class c_global_reference
{
public:
	
	c_global_reference(const char* pReferenceName, OffsetFunction offsetFunction);
	c_global_reference(const char* pReferenceName, Engine engine, Build build, intptr_t offset);

	static void InitTree(Engine engine, Build build);
	static void DeinitTree(Engine engine, Build build);
	static void DestroyTree();
private:
	void init();
	c_global_reference* initNode(Engine engine, Build build);
	c_global_reference* deinitNode(Engine engine, Build build);

	c_global_reference* m_pNextc_global_reference;
	Engine m_engine;
	Build m_build;
	intptr_t m_offset;
	intptr_t m_originalValue;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static c_global_reference* s_pFirstc_global_reference;
	static c_global_reference* s_pLastc_global_reference;
};

