#include "mantlereflect-private-pch.h"

c_reflection_type_container::c_reflection_type_container()
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
{
}

c_reflection_type_container::c_reflection_type_container(std::string type_name, uint32_t size)
	: is_size_initialized(true)
	, is_primitive(true)
	, clang_record_declaration(nullptr)
	, raw_tag_group()
	, type_name(type_name)
	, qualified_type_name(type_name)
	, fields()
	, data_size(size)
	, type_nice_name()
	, is_template(false)
	, template_types()
{
}

c_reflection_type_container::~c_reflection_type_container()
{
	for (c_reflection_field_container* pField : fields)
	{
		delete pField;
	}
}