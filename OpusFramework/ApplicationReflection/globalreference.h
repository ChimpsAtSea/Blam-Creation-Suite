#pragma once
class c_global_reference
{
public:
	
	c_global_reference(const char* pReferenceName, OffsetFunction offsetFunction);
	c_global_reference(const char* pReferenceName, e_engine_type engine_type, e_build build, intptr_t offset);

	static void init_global_reference_tree(e_engine_type engine_type, e_build build);
	static void deinit_global_reference_tree(e_engine_type engine_type, e_build build);
	static void DestroyTree();
private:
	void init();
	c_global_reference* initNode(e_engine_type engine_type, e_build build);
	c_global_reference* deinitNode(e_engine_type engine_type, e_build build);

	c_global_reference* m_pNextc_global_reference;
	e_engine_type m_engine;
	e_build m_build;
	intptr_t m_offset;
	intptr_t m_originalValue;
	OffsetFunction* m_pOffsetFunction;
	const char* m_pReferenceName;

	static c_global_reference* s_pFirstc_global_reference;
	static c_global_reference* s_pLastc_global_reference;
};

