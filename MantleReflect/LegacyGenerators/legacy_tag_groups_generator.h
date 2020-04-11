#pragma once
class c_legacy_tag_groups_generator :
	public c_legacy_ast_source_generator
{
public:
	c_legacy_tag_groups_generator(const wchar_t* output_header_file);
	virtual void run(std::vector<c_reflection_type_container_legacy*>& reflection_type_containers) override;
	void write_tag_group_enum(std::stringstream& stringstream, std::vector<c_reflection_type_container_legacy*>& reflection_type_containers);
};

