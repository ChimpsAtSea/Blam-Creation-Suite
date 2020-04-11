#include "mantlereflect-private-pch.h"

c_legacy_compile_time_gui_generator::c_legacy_compile_time_gui_generator(const wchar_t* output_header_file, const wchar_t* output_source_file) :
	c_legacy_ast_source_generator(output_header_file, output_source_file)
{

}

void c_legacy_compile_time_gui_generator::run(std::vector<c_reflection_type_container*>& reflection_type_containers)
{

	header_string_stream << "#pragma once" << std::endl << std::endl;
	header_string_stream << "template<typename T>" << std::endl;
	header_string_stream << "void render_type_gui_legacy(void* data);" << std::endl << std::endl;
	header_string_stream << "#ifndef __visual_assist__" << std::endl;

	source_string_stream << "#include <MantleReflect/legacy_reflection_types.h>" << std::endl;
	source_string_stream << "#include <MantleLib/Tags/Tags.h>" << std::endl;
	source_string_stream << "#include <assert.h>" << std::endl << std::endl;

	source_string_stream << "#ifndef __visual_assist__" << std::endl;
	source_string_stream << "template<e_legacy_primitive_type primitive_type, typename T>" << std::endl;
	source_string_stream << "void render_primitive_gui(void* field_data, const c_reflection_field & reflection_field);" << std::endl;

	//source_string_stream << "void render_primitive_gui_int8" << "(int8_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_int16" << "(int16_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_int32" << "(int32_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_int64" << "(int64_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint8" << "(uint8_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint16" << "(uint16_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint32" << "(uint32_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint64" << "(uint64_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_float" << "(float			* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_double" << "(double		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean8" << "(bool8_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean16" << "(bool16_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean32" << "(bool32_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean64" << "(bool64_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum8" << "(enum8_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum16" << "(enum16_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum32" << "(enum32_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum64" << "(enum64_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield8" << "(bitfield8_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield16" << "(bitfield16_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield32" << "(bitfield32_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield64" << "(bitfield64_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag8" << "(bitflag8_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag16" << "(bitflag16_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag32" << "(bitflag32_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag64" << "(bitflag64_t	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined8" << "(s_undefined8_legacy	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined16" << "(s_undefined16_legacy	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined32" << "(s_undefined32_legacy	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined64" << "(s_undefined64_legacy	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_character" << "(char			* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_widecharacter" << "(wchar_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_stringid_gui" << "(string_id_legacy		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_struct_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_tagref_gui" << "(s_tag_reference_legacy		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_tagblock_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_dataref_gui" << "(s_data_reference_legacy		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_enum_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_bitfield_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;

	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_type_containers)
	{
		if (!reflection_type_container->is_enum && !reflection_type_container->is_bitfield)
		{
			write_render_gui_type_entry_header(*reflection_type_container);
		}
	}
	source_string_stream << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_type_containers)
	{
		if (!reflection_type_container->is_enum && !reflection_type_container->is_bitfield)
		{
			write_render_gui_type_entry_source(*reflection_type_container);
		}
	}
	header_string_stream << "#endif" << std::endl; // __visual_assist__
	source_string_stream << "#endif" << std::endl; // __visual_assist__
}

#define std_string_tolower(string) std::transform(string.begin(), string.end(), string.begin(), [](char c) { return static_cast<char>(std::tolower(c)); });

std::string get_variable_name(const std::string& type_name)
{
	std::string data_variable_name;
	{
		std::string data_variable_name_format = type_name;
		data_variable_name.reserve(data_variable_name_format.size() + 32);
		std_string_tolower(data_variable_name_format);
		if (data_variable_name_format.size() > 2 && (data_variable_name_format[0] == 's' || data_variable_name_format[0] == 'c') && data_variable_name_format[1] == '_')
		{
			data_variable_name = data_variable_name_format.data() + 2;
		}
		else
		{
			data_variable_name = data_variable_name_format;
		}
	}
	return data_variable_name;
}

void c_legacy_compile_time_gui_generator::write_render_gui_type_entry_header(const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive) return; // skip internal types

	std::string data_variable_name = get_variable_name(reflection_type_container.type_name) + "_data";

	header_string_stream << "template<> void render_type_gui_legacy<" << reflection_type_container.qualified_type_name << ">(void* raw_" << data_variable_name << ");" << std::endl;
}

const char* get_primitive_handler_function(e_legacy_primitive_type primitiveType)
{
	switch (primitiveType)
	{
	case _legacy_primitive_type_int8:						return "render_primitive_gui<_legacy_primitive_type_int8,				int8_t>";
	case _legacy_primitive_type_int16:						return "render_primitive_gui<_legacy_primitive_type_int16,				int16_t>";
	case _legacy_primitive_type_int32:						return "render_primitive_gui<_legacy_primitive_type_int32,				int32_t>";
	case _legacy_primitive_type_int64:						return "render_primitive_gui<_legacy_primitive_type_int64,				int64_t>";
	case _legacy_primitive_type_uint8:						return "render_primitive_gui<_legacy_primitive_type_uint8,				uint8_t>";
	case _legacy_primitive_type_uint16:					return "render_primitive_gui<_legacy_primitive_type_uint16,			uint16_t>";
	case _legacy_primitive_type_uint32:					return "render_primitive_gui<_legacy_primitive_type_uint32,			uint32_t>";
	case _legacy_primitive_type_uint64:					return "render_primitive_gui<_legacy_primitive_type_uint64,			uint64_t>";
	case _legacy_primitive_type_float:						return "render_primitive_gui<_legacy_primitive_type_float,				float>";
	case _legacy_primitive_type_double:					return "render_primitive_gui<_legacy_primitive_type_float,				double>";
	case _legacy_primitive_type_boolean8:					return "render_primitive_gui<_legacy_primitive_type_boolean8,			boolean8_t>";
	case _legacy_primitive_type_boolean16:					return "render_primitive_gui<_legacy_primitive_type_boolean16,			boolean16_t>";
	case _legacy_primitive_type_boolean32:					return "render_primitive_gui<_legacy_primitive_type_boolean32,			boolean32_t>";
	case _legacy_primitive_type_boolean64:					return "render_primitive_gui<_legacy_primitive_type_boolean64,			boolean64_t>";
	case _legacy_primitive_type_enum8:						return "render_primitive_gui<_legacy_primitive_type_enum8,				enum8_t>";
	case _legacy_primitive_type_enum16:					return "render_primitive_gui<_legacy_primitive_type_enum16,			enum16_t>";
	case _legacy_primitive_type_enum32:					return "render_primitive_gui<_legacy_primitive_type_enum32,			enum32_t>";
	case _legacy_primitive_type_enum64:					return "render_primitive_gui<_legacy_primitive_type_enum64,			enum64_t>";
	case _legacy_primitive_type_bitfield8:					return "render_primitive_gui<_legacy_primitive_type_bitfield8,			bitfield8_t>";
	case _legacy_primitive_type_bitfield16:				return "render_primitive_gui<_legacy_primitive_type_bitfield16,		bitfield16_t>";
	case _legacy_primitive_type_bitfield32:				return "render_primitive_gui<_legacy_primitive_type_bitfield32,		bitfield32_t>";
	case _legacy_primitive_type_bitfield64:				return "render_primitive_gui<_legacy_primitive_type_bitfield64,		bitfield64_t>";
	case _legacy_primitive_type_bitflag8:					return "render_primitive_gui<_legacy_primitive_type_bitflag8,			bitflag8_t>";
	case _legacy_primitive_type_bitflag16:					return "render_primitive_gui<_legacy_primitive_type_bitflag16,			bitflag16_t>";
	case _legacy_primitive_type_bitflag32:					return "render_primitive_gui<_legacy_primitive_type_bitflag32,			bitflag32_t>";
	case _legacy_primitive_type_bitflag64:					return "render_primitive_gui<_legacy_primitive_type_bitflag64,			bitflag64_t>";
	case _legacy_primitive_type_undefined8:				return "render_primitive_gui<_legacy_primitive_type_undefined8,		s_undefined8_legacy>";
	case _legacy_primitive_type_undefined16:				return "render_primitive_gui<_legacy_primitive_type_undefined16,		s_undefined16_legacy>";
	case _legacy_primitive_type_undefined32:				return "render_primitive_gui<_legacy_primitive_type_undefined32,		s_undefined32_legacy>";
	case _legacy_primitive_type_undefined64:				return "render_primitive_gui<_legacy_primitive_type_undefined64,		s_undefined64_legacy>";
	case _legacy_primitive_type_char8:						return "render_primitive_gui<_legacy_primitive_type_char8,				char>";
	case _legacy_primitive_type_char16:					return "render_primitive_gui<_legacy_primitive_type_char16,			wchar_t>";
	case _legacy_primitive_type_static_string8:			return "render_primitive_gui<_legacy_primitive_type_static_string8,	char>";
	case _legacy_primitive_type_static_string16:			return "render_primitive_gui<_legacy_primitive_type_static_string16,	wchar_t>";
	}
	return "##UNKNOWN_PRIMITIVE_TYPE##";
}

const char* get_legacy_reflection_type_category_handler_function(e_legacy_reflection_type_category legacy_reflection_type_category)
{
	switch (legacy_reflection_type_category)
	{
	case _legacy_reflection_type_category_primitive:			return "render_primitive_gui";
	case _legacy_reflection_type_category_structure:			return "render_struct_gui";
	case _legacy_reflection_type_category_tag_reference:		return "render_tagref_gui";
	case _legacy_reflection_type_category_tag_block:			return "render_tagblock_gui";
	case _legacy_reflection_type_category_data_reference:		return "render_dataref_gui";
	case _legacy_reflection_type_category_shader_data:			return "render_shaderdata_gui";
	case _legacy_reflection_type_category_string_id:			return "render_stringid_gui";
	case _legacy_reflection_type_category_enum:				return "render_enum_gui";
	case _legacy_reflection_type_category_bitfield:			return "render_bitfield_gui";
	}
	throw;
	return "##UNKNOWN_REFLECTION_TYPE##";
}

void c_legacy_compile_time_gui_generator::write_render_gui_type_entry_source(const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive) return; // skip internal types

	source_string_stream << "template<>" << std::endl;

	std::string variable_name = get_variable_name(reflection_type_container.type_name);
	std::string data_variable_name = variable_name + "_data";
	std::string reflection_variable_name = variable_name + "_reflection";

	source_string_stream << "void render_type_gui_legacy<" << reflection_type_container.qualified_type_name << ">(void* raw_" << data_variable_name << ")" << std::endl;
	source_string_stream << "{" << std::endl;
	source_string_stream << "\tassert(raw_" << data_variable_name << " != nullptr);" << std::endl;
	source_string_stream << "\t" << reflection_type_container.qualified_type_name << "* " << data_variable_name << " = static_cast<" << reflection_type_container.qualified_type_name << "*>(raw_" << data_variable_name << ");" << std::endl << std::endl;
	source_string_stream << "\tstatic const s_reflection_structure_type& " << reflection_variable_name << " = reflection_structure_legacy<" << reflection_type_container.qualified_type_name << ">();" << std::endl << std::endl;

	int reflection_member_index = -1;
	for (const c_reflection_field_container* reflection_field_container_ptr : reflection_type_container.fields)
	{
		reflection_member_index++;

		assert(reflection_field_container_ptr != nullptr);
		const c_reflection_field_container& reflection_field_container = *reflection_field_container_ptr;
		assert(reflection_field_container.field_type != nullptr);
		const c_reflection_type_container& reflection_type_container = *reflection_field_container.field_type;

		const char* legacy_reflection_type_category_string = legacy_reflection_type_category_to_string(reflection_field_container.legacy_reflection_type_category);
		switch (reflection_field_container.legacy_reflection_type_category)
		{
		case _legacy_reflection_type_category_primitive:
		{
			const char* primitive_type_string = reflection_field_container.field_type->qualified_type_name.c_str();
			const char* primitive_handler_function = get_primitive_handler_function(reflection_field_container.primitive_type);

			source_string_stream << "\t" << primitive_handler_function << "(";

			switch (reflection_field_container.primitive_type)
			{
			case _legacy_primitive_type_enum8:
				source_string_stream << "(enum8_t*)&";
				break;
			case _legacy_primitive_type_enum16:
				source_string_stream << "(enum16_t*)";
				break;
			case _legacy_primitive_type_enum32:
				source_string_stream << "(enum32_t*)";
				break;
			case _legacy_primitive_type_enum64:
				source_string_stream << "(enum64_t*)";
				break;
			case _legacy_primitive_type_int8:
			case _legacy_primitive_type_int16:
			case _legacy_primitive_type_int32:
			case _legacy_primitive_type_int64:
			case _legacy_primitive_type_uint8:
			case _legacy_primitive_type_uint16:
			case _legacy_primitive_type_uint32:
			case _legacy_primitive_type_uint64:
			case _legacy_primitive_type_float:
			case _legacy_primitive_type_double:
			case _legacy_primitive_type_boolean8:
			case _legacy_primitive_type_boolean16:
			case _legacy_primitive_type_boolean32:
			case _legacy_primitive_type_boolean64:
			case _legacy_primitive_type_bitfield8:
			case _legacy_primitive_type_bitfield16:
			case _legacy_primitive_type_bitfield32:
			case _legacy_primitive_type_bitfield64:
			case _legacy_primitive_type_bitflag8:
			case _legacy_primitive_type_bitflag16:
			case _legacy_primitive_type_bitflag32:
			case _legacy_primitive_type_bitflag64:
			case _legacy_primitive_type_undefined8:
			case _legacy_primitive_type_undefined16:
			case _legacy_primitive_type_undefined32:
			case _legacy_primitive_type_undefined64:
			case _legacy_primitive_type_char8:
			case _legacy_primitive_type_char16:
			default:
				break;
			}
			if (reflection_field_container.array_size == 0) source_string_stream << "&";
			source_string_stream << data_variable_name << "->" << reflection_field_container.field_name << ", " << reflection_variable_name << ".fields[" << reflection_member_index << "]" << "); // " << primitive_type_string;
		}
		break;
		case _legacy_reflection_type_category_structure:
		case _legacy_reflection_type_category_tag_reference:
		case _legacy_reflection_type_category_tag_block:
		case _legacy_reflection_type_category_data_reference:
		case _legacy_reflection_type_category_shader_data:
		case _legacy_reflection_type_category_string_id:
		case _legacy_reflection_type_category_enum:
		case _legacy_reflection_type_category_bitfield:
		{
			const char* handler_function = get_legacy_reflection_type_category_handler_function(reflection_field_container.legacy_reflection_type_category);

			source_string_stream << "\t" << handler_function << "(";
			if (reflection_field_container.array_size == 0) source_string_stream << "&";
			source_string_stream << data_variable_name << "->" << reflection_field_container.field_name << ", " << reflection_variable_name << ".fields[" << reflection_member_index << "]" << "); // " << legacy_reflection_type_category_string;
		}
		break;
		default: throw; // unsupported e_legacy_reflection_type_category
		}
		if (reflection_field_container.array_size > 0) source_string_stream << "[]";
		source_string_stream << std::endl;
	}

	source_string_stream << "}" << std::endl;
	source_string_stream << std::endl;
}
