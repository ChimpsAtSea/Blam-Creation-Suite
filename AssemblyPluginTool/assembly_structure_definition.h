#pragma once

class c_assembly_plugin_tool;
class c_assembly_field_definition;

class c_assembly_structure_definition
{
public:
	c_assembly_structure_definition(c_assembly_structure_definition* parent, c_assembly_plugin_tool& plugin_tool, const char* structure_name, pugi::xml_object_range<pugi::xml_node_iterator> nodes, const char* tag_group_name = "");
	~c_assembly_structure_definition();
	c_assembly_structure_definition* parent;
	c_assembly_plugin_tool& plugin_tool;
	std::string unformatted_name;
	e_assembly_plugin_tool_error tool_error;
	std::string tag_group_name;
	std::string name;
	std::string type_name;
	std::string nice_name;
	std::vector<c_assembly_field_definition> fields;

	int next_unknown_index = 0;
	int get_next_unknown_type_index() { return next_unknown_index++; }

	std::map<std::string, int> type_name_tracker;
	std::string get_unique_type_name(const std::string& name);

	std::map<std::string, int> field_name_tracker;
	std::string get_unique_field_name(const std::string& name);

	static thread_local c_assembly_structure_definition* current_root_structure;

	void print_debug(int level = 0);
	void write_begin(std::stringstream& stream);
protected:
	void write(std::stringstream& stream, int level);
};

