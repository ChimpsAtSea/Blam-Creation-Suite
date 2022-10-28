#pragma once

class c_runtime_tag_group_definition;
class c_tag_serialization_context;

class c_group_serialization_context :
	public c_serialization_context
{
public:
	c_group_serialization_context(c_definition_tweaker& definition_tweaker, c_runtime_tag_group_definition& _tag_group);
	~c_group_serialization_context();

	virtual void read() override;
	virtual void traverse() override;
	virtual void render_tree() override;

	c_definition_tweaker& definition_tweaker;
	c_runtime_tag_group_definition& tag_group;
	std::vector<c_tag_serialization_context*> serialization_contexts;
};
