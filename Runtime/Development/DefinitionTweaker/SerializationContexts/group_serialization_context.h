#pragma once

class c_definition_tweaker;
class c_runtime_tag_group_definition;
class c_tag_serialization_context;

class c_group_serialization_context :
	public c_serialization_context
{
public:
	c_definition_tweaker& definition_tweaker;
	std::vector<c_tag_serialization_context*> serialization_contexts;
	c_mutex serialization_contexts_mutex;
	c_runtime_tag_group_definition& runtime_tag_group_definition;

	std::string name;
	unsigned int group_tag;


public:
	c_group_serialization_context(c_definition_tweaker& definition_tweaker, c_runtime_tag_group_definition& _tag_group);
	~c_group_serialization_context();

	virtual BCS_RESULT read() override;
	virtual BCS_RESULT traverse() override;
	virtual void render_tree() override;

	volatile unsigned int tag_cache_offset_index;
	volatile unsigned int tag_serialization_read_index;
	volatile unsigned int tag_serialization_traverse_index;
	void read(unsigned int tag_cache_offset_index);
};
