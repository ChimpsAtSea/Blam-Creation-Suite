#pragma once
class c_mantle_tag_groups_generator :
	public c_ast_source_generator
{
public:
	c_mantle_tag_groups_generator(const wchar_t* output_header_file, std::vector<c_reflection_type_container*>& reflection_types);
	virtual void run() override;
	void write_tag_group_enum(std::stringstream& stringstream);
};

