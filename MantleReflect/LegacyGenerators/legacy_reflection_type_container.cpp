#include "mantlereflect-private-pch.h"

c_reflection_type_container_legacy::c_reflection_type_container_legacy()
	: is_size_initialized(false)
	, is_primitive(true)
	, clang_record_declaration(nullptr)
	, raw_tag_group()
	, type_name()
	, qualified_type_name()
	, fields()
	, data_size()
	, type_nice_name()
	, is_template(false)
	, template_types()
	, is_structure(false)
	, is_enum(false)
	, is_bitfield(false)
{
}

c_reflection_type_container_legacy::c_reflection_type_container_legacy(std::string type_name, std::string qualified_type_name, uint32_t size)
	: is_size_initialized(true)
	, is_primitive(true)
	, clang_record_declaration(nullptr)
	, raw_tag_group()
	, type_name(type_name)
	, qualified_type_name(qualified_type_name)
	, fields()
	, data_size(size)
	, type_nice_name()
	, is_template(false)
	, template_types()
	, is_structure(false)
	, is_enum(false)
	, is_bitfield(false)
{
}

c_reflection_type_container_legacy::~c_reflection_type_container_legacy()
{
	for (c_reflection_enum_value_container* enum_value_container : enum_values)
	{
		delete enum_value_container;
	}

	for (c_reflection_field_legacy_container* field_container : fields)
	{
		delete field_container;
	}
}