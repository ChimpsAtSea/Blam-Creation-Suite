#pragma once

class c_runtime_tag_definitions;
class c_tag_file_reader;
struct s_tag_persist_struct_definition;

class c_runtime_tag_struct_definition :
	public c_blamtoozle_tag_struct_definition
{
public:
	friend c_runtime_tag_definitions;

	const blofeld::s_tag_struct_definition* original_tag_struct_definition;
	s_tag_persist_struct_definition const* original_tag_persist_struct_definition;
	std::string pretty_name;
	std::string name;
	std::string type_name;
	std::string symbol_name;
	c_flags<blofeld::e_tag_field_set_bit> runtime_flags;
	blofeld::c_tag_memory_attributes memory_attributes;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	int alignment_bits;
	c_runtime_tag_definitions& runtime_tag_definitions;

protected:
	c_runtime_tag_struct_definition() = delete;
	c_runtime_tag_struct_definition(c_runtime_tag_struct_definition const&) = delete;
	BCS_SHARED c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	BCS_SHARED c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_struct_definition const& source);
	BCS_SHARED c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, s_engine_platform_build engine_platform_build, const blofeld::s_tag_struct_definition& tag_struct_definition);
	BCS_SHARED c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, c_tag_file_reader& tag_file_reader, s_tag_persist_struct_definition const& struct_definition);
	BCS_SHARED ~c_runtime_tag_struct_definition();

	virtual const char* get_pretty_name() override;
	virtual const char* get_name() override;
	virtual const char* get_code_symbol_name() override;
	virtual const char* get_structure_type_name() override;
	virtual uint32_t get_alignment_bits() override;
	virtual const char* get_file_path() override;
	virtual int32_t get_line_number() override;
	virtual blofeld::s_tag_persistent_identifier& get_persistent_identifier() override;
	virtual c_flags<blofeld::e_tag_field_set_bit> get_field_set_bits() override;

public:
	void restore(s_engine_platform_build engine_platform_build);
};
