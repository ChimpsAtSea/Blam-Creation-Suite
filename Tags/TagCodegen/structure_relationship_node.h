#pragma once

class c_structure_relationship_node
{
public:
	c_structure_relationship_node(s_engine_platform_build engine_platform_build, const blofeld::s_tag_struct_definition& tag_struct_definition);
	void populate();
	void create_sorted_tag_struct_definitions_impl();

	s_engine_platform_build engine_platform_build;
	bool written_to_source;
	const blofeld::s_tag_struct_definition& tag_struct_definition;
	std::vector<c_structure_relationship_node*> child_nodes;

	static void create_sorted_tag_struct_definitions(s_engine_platform_build engine_platform_build);
	static void create_structure_relationships(s_engine_platform_build engine_platform_build);
	static void create_sorted_tag_enum_definitions(s_engine_platform_build engine_platform_build);
	static void create_sorted_tag_block_definitions(s_engine_platform_build engine_platform_build);

	static c_structure_relationship_node& get_node_by_structure(s_engine_platform_build engine_platform_build, const blofeld::s_tag_struct_definition& tag_struct_definition);

	static std::vector<c_structure_relationship_node*> nodes[k_number_of_engine_types];
	static std::vector<const blofeld::s_tag_struct_definition*> sorted_tag_struct_definitions[k_number_of_engine_types];

	static std::vector<const blofeld::s_string_list_definition*> sorted_string_list_definitions[k_number_of_engine_types];
	static std::unordered_set<const blofeld::s_string_list_definition*> unsorted_string_list_definitions[k_number_of_engine_types];

	static std::vector<const blofeld::s_tag_block_definition*> sorted_block_definitions[k_number_of_engine_types];
	static std::unordered_set<const blofeld::s_tag_block_definition*> unsorted_block_definitions[k_number_of_engine_types];

	static std::vector<const blofeld::s_tag_struct_definition*> sorted_block_struct_definitions[k_number_of_engine_types];
	static std::unordered_set<const blofeld::s_tag_struct_definition*> unsorted_block_struct_definitions[k_number_of_engine_types];
};
