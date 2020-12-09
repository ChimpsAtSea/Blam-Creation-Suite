#pragma once

class c_structure_relationship_node
{
public:
	c_structure_relationship_node(const blofeld::s_tag_struct_definition& tag_struct_definition);
	void populate();
	void create_sorted_tag_struct_definitions_impl();

	static void create_sorted_tag_struct_definitions();
	static c_structure_relationship_node& get_node_by_structure(const blofeld::s_tag_struct_definition& tag_struct_definition);
	static void create_structure_relationships();
	static void create_sorted_tag_enum_definitions();

	bool written_to_source;
	const blofeld::s_tag_struct_definition& tag_struct_definition;
	std::vector<c_structure_relationship_node*> child_nodes;
	static std::vector<c_structure_relationship_node*> nodes;
	static std::vector<const blofeld::s_tag_struct_definition*> sorted_tag_struct_definitions;
	static std::vector<const blofeld::s_string_list_definition*> sorted_string_list_definitions;
	static std::unordered_set<const blofeld::s_string_list_definition*> unsorted_string_list_definitions;
	
};
