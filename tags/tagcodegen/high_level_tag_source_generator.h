#pragma once

class c_high_level_structure_type_container :
	protected c_source_generator_base
{
public:
	c_high_level_structure_type_container(c_high_level_structure_type_container const&) = delete;
	c_high_level_structure_type_container(
		c_runtime_tag_struct_definition& struct_definition,
		s_engine_platform_build engine_platform_build,
		unsigned int global_vftable_index,
		unsigned int local_vftable_index);
	~c_high_level_structure_type_container();

	std::string header;
	std::string source;

	BCS_RESULT generate_high_level_header(unsigned int header_indent_count);
	BCS_RESULT generate_high_level_header_structure_fields(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);
	BCS_RESULT generate_high_level_source(unsigned int source_indent_count);
	BCS_RESULT generate_high_level_source_structure_fields(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);
	BCS_RESULT generate_high_level_assignment_operator(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);
	BCS_RESULT generate_high_level_source_serialization_fields(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);
	BCS_RESULT empty_field_iterator(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);

	std::string high_level_structure_name;
	c_runtime_tag_struct_definition& struct_definition;
	unsigned int global_vftable_index;
	unsigned int local_vftable_index;
	bool header_written;
	bool source_written;
};

class c_high_level_tag_source_generator :
	public c_source_generator_base
{
public:
	c_high_level_tag_source_generator(c_high_level_tag_source_generator const&) = delete;
	c_high_level_tag_source_generator(c_runtime_tag_definitions& runtime_definitions, s_engine_platform_build engine_platform_build, unsigned int global_vftable_index);
	virtual ~c_high_level_tag_source_generator();
	BCS_RESULT enqueue_high_level_virtual_fields(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);

	BCS_RESULT iterate_struct_definitions(
		std::stringstream& stream,
		c_runtime_tag_struct_definition& struct_definition,
		std::string c_high_level_structure_type_container::* string_member,
		bool c_high_level_structure_type_container::* written_member);
	BCS_RESULT generate_high_level_header(unsigned int thread_index, unsigned int thread_count);
	BCS_RESULT generate_high_level_source(unsigned int thread_index, unsigned int thread_count);
	BCS_RESULT generate_high_level_virtual(unsigned int thread_index, unsigned int thread_count);
	BCS_RESULT generate_high_level_virtual_fields(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name);
	BCS_RESULT generate_high_level_natvis(unsigned int thread_index, unsigned int thread_count);

	static std::string format_structure_symbol(c_runtime_tag_struct_definition const& struct_definition);
	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);

	unsigned int global_vftable_index; // #TODO: replace this with something better sometime
	unsigned int local_vftable_count;
	std::string output_directory;
	std::string output_header_file_path;
	std::string output_source_file_path;
	std::string output_natvis_file_path;
	std::string output_virtual_file_path;
	std::string output_misc_file_path;
	c_runtime_tag_definitions& runtime_definitions;
	using t_pointer_to_vftable_index = std::map<void*, unsigned int>;
	t_pointer_to_vftable_index pointer_to_vftable_index;
	std::map<c_runtime_tag_struct_definition*, c_high_level_structure_type_container*> structure_type_containers;
	c_high_level_structure_type_container** _structure_type_containers;
};

//
//
//class c_high_level_tag_source_generator :
//	public c_source_generator_base
//{
//public:
//	c_high_level_tag_source_generator(s_engine_platform_build engine_platform_build, unsigned int global_index);
//	virtual ~c_high_level_tag_source_generator();
//
//	void generate_header();
//	void generate_forward_declare();
//	void generate_tag_constructor_params(std::stringstream& stream, blofeld::s_tag_struct_definition const& tag_struct_definition);
//	void generate_ctor_source(uint32_t source_index, uint32_t source_count);
//	void generate_source_virtual();
//	void generate_source_misc();
//	void generate_function_get_blofeld_field_list(std::stringstream& stream, blofeld::s_tag_struct_definition const& struct_definition);
//	void generate_function_get_blofeld_field_list_deprecated(std::stringstream& stream, blofeld::s_tag_struct_definition const& struct_definition);
//	void generate_function_get_version(std::stringstream& stream, blofeld::s_tag_struct_definition const& struct_definition);
//	void generate_function_get_field_data(std::stringstream& stream, blofeld::s_tag_struct_definition const& struct_definition, bool is_const);
//	void generate_function_get_field_data_unsafe(std::stringstream& stream, blofeld::s_tag_struct_definition const& struct_definition, bool is_const);
//
//
//
//	blofeld::s_tag_group const* get_tag_struct_tag_group(blofeld::s_tag_struct_definition const& tag_struct_definition);
//	unsigned int get_tag_struct_version(blofeld::s_tag_struct_definition const& tag_struct_definition);
//	
//	static const char* field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type);
//};
