#include "mantlereflect-private-pch.h"

c_mantle_compile_time_gui_generator::c_mantle_compile_time_gui_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types) :
	c_ast_source_generator(output_header_file, output_source_file, reflection_types)
{

}

void c_mantle_compile_time_gui_generator::run()
{

	header_string_stream << "#pragma once" << std::endl << std::endl;
	header_string_stream << "template<typename T>" << std::endl;
	header_string_stream << "void render_type_gui(void* data);" << std::endl << std::endl;
	header_string_stream << "#ifndef __visual_assist__" << std::endl;

	source_string_stream << "#include <MantleReflect/ReflectionTypes.h>" << std::endl;
	source_string_stream << "#include \"Tags.h\"" << std::endl;
	source_string_stream << "#include <assert.h>" << std::endl << std::endl;

	source_string_stream << "#ifndef __visual_assist__" << std::endl;
	source_string_stream << "template<e_primitive_type primitive_type, typename T>" << std::endl;
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
	//source_string_stream << "void render_primitive_gui_undefined8" << "(Undefined8	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined16" << "(Undefined16	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined32" << "(Undefined32	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined64" << "(Undefined64	* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_character" << "(char			* field_data, const c_reflection_field& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_widecharacter" << "(wchar_t		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_stringid_gui" << "(string_id		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_struct_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_tagref_gui" << "(TagReference		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_tagblock_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_dataref_gui" << "(DataReference		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_enum_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;
	source_string_stream << "void render_bitfield_gui" << "(void		* field_data, const c_reflection_field& reflection_field);" << std::endl;

	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		if (!reflection_type_container->is_enum && !reflection_type_container->is_bitfield)
		{
			write_render_gui_type_entry_header(*reflection_type_container);
		}
	}
	source_string_stream << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
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

void c_mantle_compile_time_gui_generator::write_render_gui_type_entry_header(const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive) return; // skip internal types

	std::string data_variable_name = get_variable_name(reflection_type_container.type_name) + "_data";

	header_string_stream << "template<> void render_type_gui<" << reflection_type_container.qualified_type_name << ">(void* raw_" << data_variable_name << ");" << std::endl;
}

const char* get_primitive_handler_function(e_primitive_type primitiveType)
{
	switch (primitiveType)
	{
	case e_primitive_type::Int8:						return "render_primitive_gui<e_primitive_type::Int8,			 int8_t>";
	case e_primitive_type::Int16:						return "render_primitive_gui<e_primitive_type::Int16,			 int16_t>";
	case e_primitive_type::Int32:						return "render_primitive_gui<e_primitive_type::Int32,			 int32_t>";
	case e_primitive_type::Int64:						return "render_primitive_gui<e_primitive_type::Int64,			 int64_t>";
	case e_primitive_type::UInt8:						return "render_primitive_gui<e_primitive_type::UInt8,			 uint8_t>";
	case e_primitive_type::UInt16:						return "render_primitive_gui<e_primitive_type::UInt16,			 uint16_t>";
	case e_primitive_type::UInt32:						return "render_primitive_gui<e_primitive_type::UInt32,			 uint32_t>";
	case e_primitive_type::UInt64:						return "render_primitive_gui<e_primitive_type::UInt64,			 uint64_t>";
	case e_primitive_type::Float:						return "render_primitive_gui<e_primitive_type::Float,			 float>";
	case e_primitive_type::Double:						return "render_primitive_gui<e_primitive_type::Double,			 double>";
	case e_primitive_type::Boolean8:					return "render_primitive_gui<e_primitive_type::Boolean8,		 boolean8_t>";
	case e_primitive_type::Boolean16:					return "render_primitive_gui<e_primitive_type::Boolean16,		 boolean16_t>";
	case e_primitive_type::Boolean32:					return "render_primitive_gui<e_primitive_type::Boolean32,		 boolean32_t>";
	case e_primitive_type::Boolean64:					return "render_primitive_gui<e_primitive_type::Boolean64,		 boolean64_t>";
	case e_primitive_type::Enum8:						return "render_primitive_gui<e_primitive_type::Enum8,			 enum8_t>";
	case e_primitive_type::Enum16:						return "render_primitive_gui<e_primitive_type::Enum16,			 enum16_t>";
	case e_primitive_type::Enum32:						return "render_primitive_gui<e_primitive_type::Enum32,			 enum32_t>";
	case e_primitive_type::Enum64:						return "render_primitive_gui<e_primitive_type::Enum64,			 enum64_t>";
	case e_primitive_type::BitField8:					return "render_primitive_gui<e_primitive_type::BitField8,		 bitfield8_t>";
	case e_primitive_type::BitField16:					return "render_primitive_gui<e_primitive_type::BitField16,		 bitfield16_t>";
	case e_primitive_type::BitField32:					return "render_primitive_gui<e_primitive_type::BitField32,		 bitfield32_t>";
	case e_primitive_type::BitField64:					return "render_primitive_gui<e_primitive_type::BitField64,		 bitfield64_t>";
	case e_primitive_type::BitFlag8:					return "render_primitive_gui<e_primitive_type::BitFlag8,		 bitflag8_t>";
	case e_primitive_type::BitFlag16:					return "render_primitive_gui<e_primitive_type::BitFlag16,		 bitflag16_t>";
	case e_primitive_type::BitFlag32:					return "render_primitive_gui<e_primitive_type::BitFlag32,		 bitflag32_t>";
	case e_primitive_type::BitFlag64:					return "render_primitive_gui<e_primitive_type::BitFlag64,		 bitflag64_t>";
	case e_primitive_type::Undefined8:					return "render_primitive_gui<e_primitive_type::Undefined8,		 Undefined8>";
	case e_primitive_type::Undefined16:					return "render_primitive_gui<e_primitive_type::Undefined16,	 Undefined16>";
	case e_primitive_type::Undefined32:					return "render_primitive_gui<e_primitive_type::Undefined32,	 Undefined32>";
	case e_primitive_type::Undefined64:					return "render_primitive_gui<e_primitive_type::Undefined64,	 Undefined64>";
	case e_primitive_type::RawCharacter:				return "render_primitive_gui<e_primitive_type::RawCharacter,		 char>";
	case e_primitive_type::RawWideCharacter:			return "render_primitive_gui<e_primitive_type::RawWideCharacter,	 wchar_t>";
	case e_primitive_type::StaticString:				return "render_primitive_gui<e_primitive_type::StaticString,		 char>";
	case e_primitive_type::StaticWideString:			return "render_primitive_gui<e_primitive_type::StaticWideString,	 wchar_t>";
	}
	return "##UNKNOWN_PRIMITIVE_TYPE##";
}

const char* get_reflection_type_category_handler_function(e_reflection_type_category reflection_type_category)
{
	switch (reflection_type_category)
	{
	case e_reflection_type_category::Primitive:			return "render_primitive_gui";
	case e_reflection_type_category::Structure:			return "render_struct_gui";
	case e_reflection_type_category::TagReference:		return "render_tagref_gui";
	case e_reflection_type_category::TagBlock:			return "render_tagblock_gui";
	case e_reflection_type_category::DataReference:		return "render_dataref_gui";
	case e_reflection_type_category::ShaderData:		return "render_shaderdata_gui";
	case e_reflection_type_category::StringID:			return "render_stringid_gui";
	case e_reflection_type_category::Enum:				return "render_enum_gui";
	case e_reflection_type_category::BitField:			return "render_bitfield_gui";
	}
	throw;
	return "##UNKNOWN_REFLECTION_TYPE##";
}

void c_mantle_compile_time_gui_generator::write_render_gui_type_entry_source(const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive) return; // skip internal types

	source_string_stream << "template<>" << std::endl;

	std::string variable_name = get_variable_name(reflection_type_container.type_name);
	std::string data_variable_name = variable_name + "_data";
	std::string reflection_variable_name = variable_name + "_reflection";

	source_string_stream << "void render_type_gui<" << reflection_type_container.qualified_type_name << ">(void* raw_" << data_variable_name << ")" << std::endl;
	source_string_stream << "{" << std::endl;
	source_string_stream << "\tassert(raw_" << data_variable_name << " != nullptr);" << std::endl;
	source_string_stream << "\t" << reflection_type_container.qualified_type_name << "* " << data_variable_name << " = static_cast<" << reflection_type_container.qualified_type_name << "*>(raw_" << data_variable_name << ");" << std::endl << std::endl;
	source_string_stream << "\tstatic const s_reflection_structure_type& " << reflection_variable_name << " = runtime_structure_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl << std::endl;

	int reflection_member_index = -1;
	for (const c_reflection_field_container* reflection_field_container_ptr : reflection_type_container.fields)
	{
		reflection_member_index++;

		assert(reflection_field_container_ptr != nullptr);
		const c_reflection_field_container& reflection_field_container = *reflection_field_container_ptr;
		assert(reflection_field_container.field_type != nullptr);
		const c_reflection_type_container& reflection_type_container = *reflection_field_container.field_type;

		const char* reflection_type_category_string = e_reflection_type_categoryToString(reflection_field_container.reflection_type_category);
		switch (reflection_field_container.reflection_type_category)
		{
		case e_reflection_type_category::Primitive:
		{
			const char* primitive_type_string = reflection_field_container.field_type->qualified_type_name.c_str();
			const char* primitive_handler_function = get_primitive_handler_function(reflection_field_container.primitive_type);

			source_string_stream << "\t" << primitive_handler_function << "(";

			switch (reflection_field_container.primitive_type)
			{
			case e_primitive_type::Enum8:
				source_string_stream << "(enum8_t*)&";
				break;
			case e_primitive_type::Enum16:
				source_string_stream << "(enum16_t*)";
				break;
			case e_primitive_type::Enum32:
				source_string_stream << "(enum32_t*)";
				break;
			case e_primitive_type::Enum64:
				source_string_stream << "(enum64_t*)";
				break;
			case e_primitive_type::Int8:
			case e_primitive_type::Int16:
			case e_primitive_type::Int32:
			case e_primitive_type::Int64:
			case e_primitive_type::UInt8:
			case e_primitive_type::UInt16:
			case e_primitive_type::UInt32:
			case e_primitive_type::UInt64:
			case e_primitive_type::Float:
			case e_primitive_type::Double:
			case e_primitive_type::Boolean8:
			case e_primitive_type::Boolean16:
			case e_primitive_type::Boolean32:
			case e_primitive_type::Boolean64:
			case e_primitive_type::BitField8:
			case e_primitive_type::BitField16:
			case e_primitive_type::BitField32:
			case e_primitive_type::BitField64:
			case e_primitive_type::BitFlag8:
			case e_primitive_type::BitFlag16:
			case e_primitive_type::BitFlag32:
			case e_primitive_type::BitFlag64:
			case e_primitive_type::Undefined8:
			case e_primitive_type::Undefined16:
			case e_primitive_type::Undefined32:
			case e_primitive_type::Undefined64:
			case e_primitive_type::RawCharacter:
			case e_primitive_type::RawWideCharacter:
			default:
				break;
			}
			if (reflection_field_container.array_size == 0) source_string_stream << "&";
			source_string_stream << data_variable_name << "->" << reflection_field_container.field_name << ", " << reflection_variable_name << ".fields[" << reflection_member_index << "]" << "); // " << primitive_type_string;
		}
		break;
		case e_reflection_type_category::Structure:
		case e_reflection_type_category::TagReference:
		case e_reflection_type_category::TagBlock:
		case e_reflection_type_category::DataReference:
		case e_reflection_type_category::ShaderData:
		case e_reflection_type_category::StringID:
		case e_reflection_type_category::Enum:
		case e_reflection_type_category::BitField:
		{
			const char* handler_function = get_reflection_type_category_handler_function(reflection_field_container.reflection_type_category);

			source_string_stream << "\t" << handler_function << "(";
			if (reflection_field_container.array_size == 0) source_string_stream << "&";
			source_string_stream << data_variable_name << "->" << reflection_field_container.field_name << ", " << reflection_variable_name << ".fields[" << reflection_member_index << "]" << "); // " << reflection_type_category_string;
		}
		break;
		default: throw; // unsupported e_reflection_type_category
		}
		if (reflection_field_container.array_size > 0) source_string_stream << "[]";
		source_string_stream << std::endl;
	}

	source_string_stream << "}" << std::endl;
	source_string_stream << std::endl;
}
