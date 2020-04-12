#pragma once

class c_reflection_enum_value_container_legacy;

class c_reflection_type_container_legacy
{
public:
	c_reflection_type_container_legacy();
	c_reflection_type_container_legacy(std::string type_name, std::string qualified_type_name, uint32_t size);
	~c_reflection_type_container_legacy();

	bool is_structure;
	bool is_enum;
	bool is_bitfield;
	
	// enum information
	std::vector<c_reflection_enum_value_container_legacy*> enum_values;


	// structure information

	bool is_size_initialized;
	bool is_primitive;
	const clang::RecordDecl* clang_record_declaration;
	std::string raw_tag_group;
	std::string tag_group;
	std::string type_name;
	std::string qualified_type_name;
	std::vector<c_reflection_field_legacy_container*> fields;
	uint32_t data_size;
	std::string type_nice_name;
	bool is_template;
	std::vector<c_reflection_type_container_legacy*> template_types;
};

