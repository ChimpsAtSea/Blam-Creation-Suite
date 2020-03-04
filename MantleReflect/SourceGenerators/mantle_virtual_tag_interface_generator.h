#pragma once
class c_mantle_virtual_tag_interface_generator :
	public c_ast_source_generator
{
public:
	c_mantle_virtual_tag_interface_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types);
	virtual void run() override;
	void write_virtual_tag_interface(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container);
	void write_virtual_tag_initializer(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container);
};

