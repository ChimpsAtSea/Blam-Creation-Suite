#include "tagcodegen-private-pch.h"

c_source_generator_base::c_source_generator_base(s_engine_platform_build _engine_platform_build) :
	engine_platform_build(_engine_platform_build),
	has_error(false),
	indent(),
	_engine_namespace(),
	_platform_namespace()
{
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_namespace(engine_platform_build.engine_type, _engine_namespace);
	BCS_FAIL_THROW_DBG(engine_type_to_folder_name_result);

	BCS_RESULT platform_type_to_folder_name_result = get_platform_type_namespace(engine_platform_build.platform_type, _platform_namespace);
	BCS_FAIL_THROW_DBG(platform_type_to_folder_name_result);
}

c_source_generator_base::~c_source_generator_base()
{

}

void c_source_generator_base::increment_indent()
{
	indent.push_back('\t');
}

void c_source_generator_base::decrement_indent()
{
	ASSERT(!indent.empty());
	indent.pop_back();
}

std::string c_source_generator_base::get_base_namespace(bool semicolon_suffix)
{
	std::stringstream stream;
	stream << "blofeld";
	if (semicolon_suffix)
	{
		stream << "::";
	}
	return stream.str();
}

std::string c_source_generator_base::get_engine_namespace(bool semicolon_suffix)
{
	std::stringstream stream;
	stream << _engine_namespace;
	if (semicolon_suffix)
	{
		stream << "::";
	}
	return stream.str();
}

std::string c_source_generator_base::get_platform_namespace(bool semicolon_suffix)
{
	std::stringstream stream;
	stream << _platform_namespace;
	if (semicolon_suffix)
	{
		stream << "::";
	}
	return stream.str();
}

std::string c_source_generator_base::get_namespace(bool semicolon_suffix)
{
	std::stringstream stream;
	stream << "blofeld::";
	stream << _engine_namespace << "::";
	stream << _platform_namespace;
	if (semicolon_suffix)
	{
		stream << "::";
	}
	return stream.str();
}

void c_source_generator_base::begin_namespace_tree(std::stringstream& stream, uint32_t tree_write_options)
{
	if (tree_write_options & _namespace_tree_write_intellisense)
	{
		stream << "#ifndef __INTELLISENSE__" << std::endl;
	}
	if (tree_write_options & _namespace_tree_write_namespace)
	{
		if (tree_write_options & (_namespace_tree_write_intellisense))
		{
			stream << indent << std::endl;
		}
		stream << indent << "namespace " << get_base_namespace(false) << " {" << std::endl;
		increment_indent();
		stream << indent << "namespace " << get_engine_namespace(false) << " {" << std::endl;
		increment_indent();
		stream << indent << "namespace " << get_platform_namespace(false) << " {" << std::endl;
		increment_indent();
	}
	if (tree_write_options & _namespace_tree_write_warnings)
	{
		if (tree_write_options & (
			_namespace_tree_write_intellisense | 
			_namespace_tree_write_namespace))
		{
			stream << indent << std::endl;
		}
		stream << indent << "#pragma warning(push)" << std::endl;
		stream << indent << "#pragma warning(disable : 4065)" << std::endl;
		stream << indent << "#pragma warning(error : 4172)" << std::endl;
	}
	if (tree_write_options & _namespace_tree_write_pragma_pack)
	{
		if (tree_write_options & (
			_namespace_tree_write_intellisense | 
			_namespace_tree_write_namespace | 
			_namespace_tree_write_warnings))
		{
			stream << indent << std::endl;
		}
		stream << indent << "#pragma pack(push, 1)" << std::endl;
	}
	if (tree_write_options)
	{
		stream << indent << std::endl;
	}
}

void c_source_generator_base::end_namespace_tree(std::stringstream& stream, uint32_t tree_write_options)
{
	if (tree_write_options)
	{
		stream << indent << std::endl;
	}
	if (tree_write_options & _namespace_tree_write_pragma_pack)
	{
		stream << indent << "#pragma pack(pop)" << std::endl;
	}
	if (tree_write_options & _namespace_tree_write_warnings)
	{
		stream << indent << "#pragma warning(pop)" << std::endl;
	}
	if (tree_write_options & _namespace_tree_write_namespace)
	{
		decrement_indent();
		stream << indent << "} // end namespace  " << get_platform_namespace(false) << " {" << std::endl;
		decrement_indent();
		stream << indent << "} // end namespace  " << get_engine_namespace(false) << " {" << std::endl;
		decrement_indent();
		stream << indent << "} // end namespace  " << get_base_namespace(false) << " {" << std::endl;
	}
	if (tree_write_options & _namespace_tree_write_intellisense)
	{
		if (tree_write_options & ~_namespace_tree_write_intellisense)
		{
			stream << indent << std::endl;
		}
		stream << "#endif // __INTELLISENSE__" << std::endl;
	}
}

void c_source_generator_base::write_field_description_comment(std::stringstream& stream, const blofeld::s_tag_field& tag_field)
{
	stream << indent << "/* " << tag_field.name << std::endl;
	stream << indent << " ";
	const char* current_pos = tag_field.explanation;
	while (*current_pos)
	{
		switch (*current_pos)
		{
		case '\n':
			stream << *current_pos;
			stream << indent << " ";
			break;
		default:
			stream << *current_pos;
		}
		current_pos++;
	}
	stream << indent << std::endl;
	stream << indent << "*/" << std::endl << std::endl;
}
