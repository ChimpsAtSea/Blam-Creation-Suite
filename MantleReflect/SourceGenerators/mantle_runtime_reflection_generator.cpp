#include "mantlereflect-private-pch.h"

c_mantle_runtime_reflection_generator::c_mantle_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types) :
	c_ast_source_generator(output_header_file, output_source_file, reflection_types)
{

}

void c_mantle_runtime_reflection_generator::run()
{
	header_string_stream << "#pragma once" << std::endl << std::endl;
	header_string_stream << "template<typename T>" << std::endl;
	header_string_stream << "const s_reflection_structure_type& runtime_structure_reflection();" << std::endl << std::endl;

	header_string_stream << "template<typename T>" << std::endl;
	header_string_stream << "const s_reflection_enum_type& runtime_enum_reflection();" << std::endl << std::endl;

	header_string_stream << "#ifndef __visual_assist__" << std::endl;
	source_string_stream << "#ifndef __visual_assist__" << std::endl;

	source_string_stream << "#include <MantleReflect/ReflectionTypes.h>" << std::endl;
	source_string_stream << "#include \"Tags.h\"" << std::endl << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		if (!reflection_type_container->is_enum && !reflection_type_container->is_bitfield) // #TODO: Cleanup what is considered a structure type
		{
			write_reflection_structure_type_entry_header(source_string_stream, *reflection_type_container);
		}
	}
	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		if (reflection_type_container->is_enum || reflection_type_container->is_bitfield)
		{
			write_reflection_enum_type_entry_header(source_string_stream, *reflection_type_container);
		}
	}
	source_string_stream << std::endl;
	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		if (reflection_type_container->is_enum || reflection_type_container->is_bitfield)
		{
			write_reflection_enum_type_entry(source_string_stream, *reflection_type_container);
		}
		else // #TODO: Cleanup what is considered a structure type
		{
			write_reflection_structure_type_entry(source_string_stream, *reflection_type_container);
		}
	}

	header_string_stream << "const s_reflection_structure_type* get_tag_reflection_data_by_tag_group(uint32_t tagGroup);" << std::endl;
	write_tag_type_lookup_function(source_string_stream);

	header_string_stream << "#endif" << std::endl; // __visual_assist__
	source_string_stream << "#endif" << std::endl; // __visual_assist__
}

void c_mantle_runtime_reflection_generator::write_tag_type_lookup_function(std::stringstream& stringstream)
{
	stringstream << std::endl;
	stringstream << "const s_reflection_structure_type* get_tag_reflection_data_by_tag_group(uint32_t tagGroup)" << std::endl;
	stringstream << "{" << std::endl;
	stringstream << "\tswitch (tagGroup)" << std::endl;
	stringstream << "\t{" << std::endl;
	for (c_reflection_type_container* reflection_type_container_ptr : reflection_types)
	{
		c_reflection_type_container& reflection_type_container = *reflection_type_container_ptr;
		if (reflection_type_container.raw_tag_group.empty()) continue;

		stringstream << "\tcase '" << reflection_type_container.raw_tag_group << "':" << std::endl;
		if (reflection_type_container.raw_tag_group != reflection_type_container.tag_group)
		{
			stringstream << "\tcase '" << reflection_type_container.tag_group << "':" << std::endl;
		}
		stringstream << "\t\treturn &runtime_structure_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl;
	}
	stringstream << "\t}" << std::endl;
	stringstream << "\treturn nullptr;" << std::endl;
	stringstream << "}" << std::endl;
	stringstream << std::endl;
}
void c_mantle_runtime_reflection_generator::write_reflection_structure_type_entry_header(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive)
	{
		// skip internal types
		return;
	}

	stringstream << "template<> ";
	stringstream << "const s_reflection_structure_type& runtime_structure_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl;
}

void c_mantle_runtime_reflection_generator::write_reflection_structure_type_entry(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive)
	{
		// skip internal types
		return;
	}

	if (!reflection_type_container.raw_tag_group.empty())
	{
		stringstream << "c_tag_interface* v_" << reflection_type_container.type_name.substr(2) << "_ctor(c_cache_file&, uint16_t);" << std::endl;
	}

	stringstream << "template<>" << std::endl;
	stringstream << "const s_reflection_structure_type& runtime_structure_reflection<" << reflection_type_container.qualified_type_name << ">()" << std::endl;

	stringstream << "{" << std::endl;
	stringstream << "\t" << "static s_reflection_structure_type reflectionData = " << std::endl;
	stringstream << "\t{" << std::endl;

	stringstream << "\t\t\"" << reflection_type_container.type_name << "\", \"" << reflection_type_container.type_nice_name << "\", " << std::endl;
	stringstream << std::uppercase;
	stringstream << "\t\t0x" << std::hex << reflection_type_container.data_size << "u," << std::endl;
	stringstream << std::nouppercase;
	stringstream << "\t\t" << std::dec << reflection_type_container.fields.size() << "ui32," << std::endl;
	stringstream << "\t\t" << "render_type_gui<" << reflection_type_container.qualified_type_name << ">," << std::endl;

	if (!reflection_type_container.raw_tag_group.empty())
	{
		stringstream << "\t\t" << "v_" << reflection_type_container.type_name.substr(2) << "_ctor," << std::endl;
	}
	else
	{
		stringstream << "\t\t" << "nullptr," << std::endl;
	}
	stringstream << "\t\t" << "{" << std::endl;
	for (const c_reflection_field_container* reflection_field_container_ptr : reflection_type_container.fields)
	{
		assert(reflection_field_container_ptr != nullptr);
		const c_reflection_field_container& reflection_field_container = *reflection_field_container_ptr;
		assert(reflection_field_container.field_type != nullptr);
		const c_reflection_type_container& reflection_type_container = *reflection_field_container.field_type;


		const char* primitive_type_string = "NonPrimitive";
		if (reflection_type_container.is_primitive)
		{
			primitive_type_string = reflection_field_container.field_type->type_name.c_str();
		}

		if (reflection_type_container.is_enum || reflection_type_container.is_bitfield)
		{
			primitive_type_string = e_primitive_typeToString(reflection_field_container.primitive_type);
		}

		const char* reflection_type_category_string = e_reflection_type_categoryToString(reflection_field_container.reflection_type_category);

		stringstream << "\t\t\t{ \"" << reflection_field_container.field_name << "\", \"" << reflection_field_container.field_nice_name << "\", ";
		{
			switch (reflection_field_container.reflection_type_category)
			{
			case e_reflection_type_category::TagBlock:
				stringstream << "s_reflection_tag_block_info";
				break;
			case e_reflection_type_category::Structure:
				stringstream << "s_reflection_structure_info";
				break;
			case e_reflection_type_category::Enum:
			case e_reflection_type_category::BitField:
				stringstream << "s_reflection_enum_info";
				break;
			default:
				stringstream << "s_reflection_structure_type_info";
				break;
			}
			stringstream << "{ " << "e_reflection_type_category::" << reflection_type_category_string;
			stringstream << ", e_primitive_type::" << primitive_type_string;
			stringstream << ", \"" << reflection_type_container.type_name << "\"";
			stringstream << ", \"" << reflection_type_container.type_nice_name << "\"";
			stringstream << ", \"" << reflection_type_container.qualified_type_name << "\"";
			switch (reflection_field_container.reflection_type_category)
			{
			case e_reflection_type_category::TagBlock:
				//#TODO: Print a Visual Studio warning for tab blocks without their types specified
				if (!reflection_field_container.field_type->template_types.empty())
				{
					//#TODO: Print a Visual Studio warning for tab blocks with too many types specified. The first only will be used
					stringstream << ", &runtime_structure_reflection<" << reflection_field_container.field_type->template_types[0]->qualified_type_name << ">()";
				}
				else stringstream << ", nullptr";
				break;
			case e_reflection_type_category::Structure:
				stringstream << ", &runtime_structure_reflection<" << reflection_field_container.field_type->qualified_type_name << ">()";
				break;
			case e_reflection_type_category::Enum:
			case e_reflection_type_category::BitField:
				stringstream << ", &runtime_enum_reflection<" << reflection_field_container.field_type->qualified_type_name << ">()";
				break;
			}
			stringstream << " }";
		}
		stringstream << std::uppercase;
		stringstream << ", 0x" << std::hex << reflection_field_container.offset << "ui32";
		//stringstream << ", offsetof(" << rType.m_qualifiedTypeName << ", " << rType.m_qualifiedTypeName << "::" << rField.m_fieldName << ")"; // #TODO: Generate offsetof code where possible
		stringstream << ", 0x" << std::hex << reflection_field_container.data_size << "ui16";
		stringstream << std::nouppercase;
		stringstream << ", " << std::dec << reflection_field_container.array_size << "ui32";
		stringstream << ", " << (reflection_field_container.is_hidden_by_default ? "true" : "false");
		stringstream << " }," << std::endl;
	}
	stringstream << "\t\t\t{ }" << std::endl;

	stringstream << "\t\t" << "}" << std::endl;
	stringstream << "\t" << "};" << std::endl << std::endl;
	stringstream << "\treturn reflectionData;" << std::endl;

	stringstream << "}" << std::endl << std::endl;
}

void c_mantle_runtime_reflection_generator::write_reflection_enum_type_entry_header(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive)
	{
		// skip internal types
		return;
	}

	stringstream << "template<> ";
	stringstream << "const s_reflection_enum_type& runtime_enum_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl;
}

void c_mantle_runtime_reflection_generator::write_reflection_enum_type_entry(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	stringstream << "template<> ";
	stringstream << "const s_reflection_enum_type& runtime_enum_reflection<" << reflection_type_container.qualified_type_name << ">()" << std::endl;
	stringstream << "{" << std::endl;
	stringstream << "\tstatic s_reflection_enum_type reflection_enum_type =" << std::endl;
	stringstream << "\t{" << std::endl;
	stringstream << "\t\t\"" << reflection_type_container.type_name << "\"," << std::endl;
	stringstream << "\t\t\"" << reflection_type_container.type_nice_name << "\"," << std::endl;
	stringstream << "\t\t" << reflection_type_container.data_size << "," << std::endl;
	stringstream << "\t\t" << reflection_type_container.enum_values.size() << "," << std::endl;
	stringstream << "\t\t" << "{" << std::endl;
	for (c_reflection_enum_value_container* enum_value_container : reflection_type_container.enum_values)
	{
		stringstream << "\t\t\t{ \"" << enum_value_container->value_name << "\", " << enum_value_container->value << "ui64 }," << std::endl;
	}
	stringstream << "\t\t\t{}" << std::endl;
	stringstream << "\t\t" << "}" << std::endl;
	stringstream << "\t};" << std::endl << std::endl;
	stringstream << "\treturn reflection_enum_type;" << std::endl;
	stringstream << "}" << std::endl << std::endl;

}
