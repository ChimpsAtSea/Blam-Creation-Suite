#pragma once
class c_legacy_runtime_reflection_generator :
	public c_legacy_ast_source_generator
{
public:
	c_legacy_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file);
	virtual void run(std::vector<c_reflection_type_container_legacy*>& reflection_type_containers) override;
	void write_tag_type_lookup_function(std::stringstream& stringstream, std::vector<c_reflection_type_container_legacy*>& reflection_type_containers);
	void write_reflection_structure_type_entry_header(std::stringstream& stringstream, const c_reflection_type_container_legacy& reflection_type_container);
	void write_reflection_structure_type_entry(std::stringstream& stringstream, const c_reflection_type_container_legacy& reflection_type_container);
	void write_reflection_enum_type_entry_header(std::stringstream& stringstream, const c_reflection_type_container_legacy& reflection_type_container);
	void write_reflection_enum_type_entry(std::stringstream& stringstream, const c_reflection_type_container_legacy& reflection_type_container);
};

