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

	source_string_stream << "#include <MantleReflect/ReflectionTypes.h>" << std::endl;
	source_string_stream << "#include \"Tags.h\"" << std::endl;
	source_string_stream << "#include <assert.h>" << std::endl << std::endl;

	source_string_stream << "template<PrimitiveType primitive_type, typename T>" << std::endl;
	source_string_stream << "void render_primitive_gui(void* field_data, const ReflectionField & reflection_field);" << std::endl;

	//source_string_stream << "void render_primitive_gui_int8" << "(int8_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_int16" << "(int16_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_int32" << "(int32_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_int64" << "(int64_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint8" << "(uint8_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint16" << "(uint16_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint32" << "(uint32_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_uint64" << "(uint64_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_float" << "(float			* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_double" << "(double		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean8" << "(bool8_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean16" << "(bool16_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean32" << "(bool32_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_boolean64" << "(bool64_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum8" << "(enum8_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum16" << "(enum16_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum32" << "(enum32_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_enum64" << "(enum64_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield8" << "(bitfield8_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield16" << "(bitfield16_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield32" << "(bitfield32_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitfield64" << "(bitfield64_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag8" << "(bitflag8_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag16" << "(bitflag16_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag32" << "(bitflag32_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_bitflag64" << "(bitflag64_t	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined8" << "(Undefined8	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined16" << "(Undefined16	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined32" << "(Undefined32	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_undefined64" << "(Undefined64	* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_character" << "(char			* field_data, const ReflectionField& reflection_field);" << std::endl;
	//source_string_stream << "void render_primitive_gui_widecharacter" << "(wchar_t		* field_data, const ReflectionField& reflection_field);" << std::endl;
	source_string_stream << "void render_stringid_gui" << "(string_id		* field_data, const ReflectionField& reflection_field);" << std::endl;
	source_string_stream << "void render_struct_gui" << "(void		* field_data, const ReflectionField& reflection_field);" << std::endl;
	source_string_stream << "void render_tagref_gui" << "(TagReference		* field_data, const ReflectionField& reflection_field);" << std::endl;
	source_string_stream << "void render_tagblock_gui" << "(void		* field_data, const ReflectionField& reflection_field);" << std::endl;
	source_string_stream << "void render_dataref_gui" << "(DataReference		* field_data, const ReflectionField& reflection_field);" << std::endl;

	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;
	source_string_stream << "" << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_render_gui_type_entry_header(*reflection_type_container);
	}
	source_string_stream << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_render_gui_type_entry_source(*reflection_type_container);
	}
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

const char* get_primitive_handler_function(PrimitiveType primitiveType)
{
	switch (primitiveType)
	{
	//case PrimitiveType::Int8:					return "render_primitive_gui_int8";
	//case PrimitiveType::Int16:					return "render_primitive_gui_int16";
	//case PrimitiveType::Int32:					return "render_primitive_gui_int32";
	//case PrimitiveType::Int64:					return "render_primitive_gui_int64";
	//case PrimitiveType::UInt8:					return "render_primitive_gui_uint8";
	//case PrimitiveType::UInt16:					return "render_primitive_gui_uint16";
	//case PrimitiveType::UInt32:					return "render_primitive_gui_uint32";
	//case PrimitiveType::UInt64:					return "render_primitive_gui_uint64";
	//case PrimitiveType::Float:					return "render_primitive_gui_float";
	//case PrimitiveType::Double:					return "render_primitive_gui_double";
	//case PrimitiveType::Boolean8:				return "render_primitive_gui_boolean8";
	//case PrimitiveType::Boolean16:				return "render_primitive_gui_boolean16";
	//case PrimitiveType::Boolean32:				return "render_primitive_gui_boolean32";
	//case PrimitiveType::Boolean64:				return "render_primitive_gui_boolean64";
	//case PrimitiveType::Enum8:					return "render_primitive_gui_enum8";
	//case PrimitiveType::Enum16:					return "render_primitive_gui_enum16";
	//case PrimitiveType::Enum32:					return "render_primitive_gui_enum32";
	//case PrimitiveType::Enum64:					return "render_primitive_gui_enum64";
	//case PrimitiveType::BitField8:				return "render_primitive_gui_bitfield8";
	//case PrimitiveType::BitField16:				return "render_primitive_gui_bitfield16";
	//case PrimitiveType::BitField32:				return "render_primitive_gui_bitfield32";
	//case PrimitiveType::BitField64:				return "render_primitive_gui_bitfield64";
	//case PrimitiveType::BitFlag8:				return "render_primitive_gui_bitflag8";
	//case PrimitiveType::BitFlag16:				return "render_primitive_gui_bitflag16";
	//case PrimitiveType::BitFlag32:				return "render_primitive_gui_bitflag32";
	//case PrimitiveType::BitFlag64:				return "render_primitive_gui_bitflag64";
	//case PrimitiveType::Undefined8:				return "render_primitive_gui_undefined8";
	//case PrimitiveType::Undefined16:			return "render_primitive_gui_undefined16";
	//case PrimitiveType::Undefined32:			return "render_primitive_gui_undefined32";
	//case PrimitiveType::Undefined64:			return "render_primitive_gui_undefined64";
	//case PrimitiveType::Character:				return "render_primitive_gui_character";
	//case PrimitiveType::WideCharacter:			return "render_primitive_gui_widecharacter";
	case PrimitiveType::Int8:					return "render_primitive_gui<PrimitiveType::Int8,			 int8_t>";
	case PrimitiveType::Int16:					return "render_primitive_gui<PrimitiveType::Int16,			 int16_t>";
	case PrimitiveType::Int32:					return "render_primitive_gui<PrimitiveType::Int32,			 int32_t>";
	case PrimitiveType::Int64:					return "render_primitive_gui<PrimitiveType::Int64,			 int64_t>";
	case PrimitiveType::UInt8:					return "render_primitive_gui<PrimitiveType::UInt8,			 uint8_t>";
	case PrimitiveType::UInt16:					return "render_primitive_gui<PrimitiveType::UInt16,			 uint16_t>";
	case PrimitiveType::UInt32:					return "render_primitive_gui<PrimitiveType::UInt32,			 uint32_t>";
	case PrimitiveType::UInt64:					return "render_primitive_gui<PrimitiveType::UInt64,			 uint64_t>";
	case PrimitiveType::Float:					return "render_primitive_gui<PrimitiveType::Float,			 float>";
	case PrimitiveType::Double:					return "render_primitive_gui<PrimitiveType::Double,			 double>";
	case PrimitiveType::Boolean8:				return "render_primitive_gui<PrimitiveType::Boolean8,		 boolean8_t>";
	case PrimitiveType::Boolean16:				return "render_primitive_gui<PrimitiveType::Boolean16,		 boolean16_t>";
	case PrimitiveType::Boolean32:				return "render_primitive_gui<PrimitiveType::Boolean32,		 boolean32_t>";
	case PrimitiveType::Boolean64:				return "render_primitive_gui<PrimitiveType::Boolean64,		 boolean64_t>";
	case PrimitiveType::Enum8:					return "render_primitive_gui<PrimitiveType::Enum8,			 enum8_t>";
	case PrimitiveType::Enum16:					return "render_primitive_gui<PrimitiveType::Enum16,			 enum16_t>";
	case PrimitiveType::Enum32:					return "render_primitive_gui<PrimitiveType::Enum32,			 enum32_t>";
	case PrimitiveType::Enum64:					return "render_primitive_gui<PrimitiveType::Enum64,			 enum64_t>";
	case PrimitiveType::BitField8:				return "render_primitive_gui<PrimitiveType::BitField8,		 bitfield8_t>";
	case PrimitiveType::BitField16:				return "render_primitive_gui<PrimitiveType::BitField16,		 bitfield16_t>";
	case PrimitiveType::BitField32:				return "render_primitive_gui<PrimitiveType::BitField32,		 bitfield32_t>";
	case PrimitiveType::BitField64:				return "render_primitive_gui<PrimitiveType::BitField64,		 bitfield64_t>";
	case PrimitiveType::BitFlag8:				return "render_primitive_gui<PrimitiveType::BitFlag8,		 bitflag8_t>";
	case PrimitiveType::BitFlag16:				return "render_primitive_gui<PrimitiveType::BitFlag16,		 bitflag16_t>";
	case PrimitiveType::BitFlag32:				return "render_primitive_gui<PrimitiveType::BitFlag32,		 bitflag32_t>";
	case PrimitiveType::BitFlag64:				return "render_primitive_gui<PrimitiveType::BitFlag64,		 bitflag64_t>";
	case PrimitiveType::Undefined8:				return "render_primitive_gui<PrimitiveType::Undefined8,		 Undefined8>";
	case PrimitiveType::Undefined16:			return "render_primitive_gui<PrimitiveType::Undefined16,	 Undefined16>";
	case PrimitiveType::Undefined32:			return "render_primitive_gui<PrimitiveType::Undefined32,	 Undefined32>";
	case PrimitiveType::Undefined64:			return "render_primitive_gui<PrimitiveType::Undefined64,	 Undefined64>";
	case PrimitiveType::Character:				return "render_primitive_gui<PrimitiveType::Character,		 char>";
	case PrimitiveType::WideCharacter:			return "render_primitive_gui<PrimitiveType::WideCharacter,	 wchar_t>";
	}
	return "##UNKNOWN_PRIMITIVE_TYPE##";
}

const char* get_reflection_type_category_handler_function(ReflectionTypeCategory reflection_type_category)
{
	switch (reflection_type_category)
	{
	case ReflectionTypeCategory::Primitive:			return "render_primitive_gui";
	case ReflectionTypeCategory::Structure:			return "render_struct_gui";
	case ReflectionTypeCategory::TagReference:		return "render_tagref_gui";
	case ReflectionTypeCategory::TagBlock:			return "render_tagblock_gui";
	case ReflectionTypeCategory::DataReference:		return "render_dataref_gui";
	case ReflectionTypeCategory::ShaderData:		return "render_shaderdata_gui";
	case ReflectionTypeCategory::StringID:			return "render_stringid_gui";
	}
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
	source_string_stream << "\tstatic const ReflectionType& " << reflection_variable_name << " = runtime_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl << std::endl;

	int reflection_member_index = -1;
	for (const c_reflection_field_container* reflection_field_container_ptr : reflection_type_container.fields)
	{
		reflection_member_index++;

		assert(reflection_field_container_ptr != nullptr);
		const c_reflection_field_container& reflection_field_container = *reflection_field_container_ptr;
		assert(reflection_field_container.field_type != nullptr);
		const c_reflection_type_container& reflection_type_container = *reflection_field_container.field_type;

		const char* reflection_type_category_string = ReflectionTypeCategoryToString(reflection_field_container.reflection_type_category);
		switch (reflection_field_container.reflection_type_category)
		{
		case ReflectionTypeCategory::Primitive:
		{
			const char* primitive_type_string = reflection_field_container.field_type->qualified_type_name.c_str();
			const char* primitive_handler_function = get_primitive_handler_function(reflection_field_container.primitive_type);

			source_string_stream << "\t" << primitive_handler_function << "(";

			switch (reflection_field_container.primitive_type)
			{
			case PrimitiveType::Enum8:
				source_string_stream << "(enum8_t*)&";
				break;
			case PrimitiveType::Enum16:
				source_string_stream << "(enum16_t*)";
				break;
			case PrimitiveType::Enum32:
				source_string_stream << "(enum32_t*)";
				break;
			case PrimitiveType::Enum64:
				source_string_stream << "(enum64_t*)";
				break;
			case PrimitiveType::Int8:
			case PrimitiveType::Int16:
			case PrimitiveType::Int32:
			case PrimitiveType::Int64:
			case PrimitiveType::UInt8:
			case PrimitiveType::UInt16:
			case PrimitiveType::UInt32:
			case PrimitiveType::UInt64:
			case PrimitiveType::Float:
			case PrimitiveType::Double:
			case PrimitiveType::Boolean8:
			case PrimitiveType::Boolean16:
			case PrimitiveType::Boolean32:
			case PrimitiveType::Boolean64:
			case PrimitiveType::BitField8:
			case PrimitiveType::BitField16:
			case PrimitiveType::BitField32:
			case PrimitiveType::BitField64:
			case PrimitiveType::BitFlag8:
			case PrimitiveType::BitFlag16:
			case PrimitiveType::BitFlag32:
			case PrimitiveType::BitFlag64:
			case PrimitiveType::Undefined8:
			case PrimitiveType::Undefined16:
			case PrimitiveType::Undefined32:
			case PrimitiveType::Undefined64:
			case PrimitiveType::Character:
			case PrimitiveType::WideCharacter:
			default:
				break;
			}
			if (reflection_field_container.array_size == 0) source_string_stream << "&";
			source_string_stream << data_variable_name << "->" << reflection_field_container.field_name << ", " << reflection_variable_name << ".m_members[" << reflection_member_index << "]" << "); // " << primitive_type_string;
		}
		break;
		case ReflectionTypeCategory::Structure:
		case ReflectionTypeCategory::TagReference:
		case ReflectionTypeCategory::TagBlock:
		case ReflectionTypeCategory::DataReference:
		case ReflectionTypeCategory::ShaderData:
		case ReflectionTypeCategory::StringID:
		{
			const char* handler_function = get_reflection_type_category_handler_function(reflection_field_container.reflection_type_category);

			source_string_stream << "\t" << handler_function << "(";
			if (reflection_field_container.array_size == 0) source_string_stream << "&";
			source_string_stream << data_variable_name << "->" << reflection_field_container.field_name << ", " << reflection_variable_name << ".m_members[" << reflection_member_index << "]" << "); // " << reflection_type_category_string;
		}
		break;
		default:
			break;
		}
		if (reflection_field_container.array_size > 0) source_string_stream << "[]";
		source_string_stream << std::endl;
	}

	source_string_stream << "}" << std::endl;
	source_string_stream << std::endl;
}
