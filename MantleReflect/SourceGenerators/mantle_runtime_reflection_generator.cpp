#include "mantlereflect-private-pch.h"

c_mantle_runtime_reflection_generator::c_mantle_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types) :
	c_ast_source_generator(output_header_file, output_source_file, reflection_types)
{

}

void c_mantle_runtime_reflection_generator::run()
{
	header_string_stream << "#pragma once" << std::endl << std::endl;
	header_string_stream << "template<typename T>" << std::endl;
	header_string_stream << "const ReflectionType& runtime_reflection();" << std::endl << std::endl;

	source_string_stream << "#include <MantleReflect/ReflectionTypes.h>" << std::endl;
	source_string_stream << "#include \"Tags.h\"" << std::endl << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_reflection_type_entry_header(source_string_stream, *reflection_type_container);
	}
	source_string_stream << std::endl;
	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_reflection_type_entry(source_string_stream, *reflection_type_container);
	}

	header_string_stream << "const ReflectionType* GetTagReflectionDataByTagGroup(uint32_t tagGroup);" << std::endl;
	write_tag_type_lookup_function(source_string_stream);
}

void c_mantle_runtime_reflection_generator::write_tag_type_lookup_function(std::stringstream& stringstream)
{
	stringstream << std::endl;
	stringstream << "const ReflectionType* GetTagReflectionDataByTagGroup(uint32_t tagGroup)" << std::endl;
	stringstream << "{" << std::endl;
	stringstream << "\tswitch (tagGroup)" << std::endl;
	stringstream << "\t{" << std::endl;
	for (c_reflection_type_container* reflection_type_container_ptr : reflection_types)
	{
		c_reflection_type_container& reflection_type_container = *reflection_type_container_ptr;
		if (reflection_type_container.raw_tag_group.empty()) continue;

		const uint32_t& raw_tag_group = *reinterpret_cast<const uint32_t*>(reflection_type_container.raw_tag_group.data());
		uint64_t swapped_tag_group = bswap(raw_tag_group);
		const char* swapped_tag_group_str = reinterpret_cast<const char*>(&swapped_tag_group);

		stringstream << "\tcase '" << reflection_type_container.raw_tag_group << "':" << std::endl;
		if (raw_tag_group != swapped_tag_group)
		{
			stringstream << "\tcase '" << swapped_tag_group_str << "':" << std::endl;
		}
		stringstream << "\t\treturn &runtime_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl;
	}
	stringstream << "\t}" << std::endl;
	stringstream << "\treturn nullptr;" << std::endl;
	stringstream << "}" << std::endl;
	stringstream << std::endl;
}
void c_mantle_runtime_reflection_generator::write_reflection_type_entry_header(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive)
	{
		// skip internal types
		return;
	}
	
	stringstream << "template<> ";
	stringstream << "const ReflectionType& runtime_reflection<" << reflection_type_container.qualified_type_name << ">();" << std::endl;
}

void c_mantle_runtime_reflection_generator::write_reflection_type_entry(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_primitive)
	{
		// skip internal types
		return;
	}

	stringstream << "template<>" << std::endl;
	stringstream << "const ReflectionType& runtime_reflection<" << reflection_type_container.qualified_type_name << ">()" << std::endl;
	
	stringstream << "{" << std::endl;
	stringstream << "\t" << "static ReflectionType reflectionData = " << std::endl;
	stringstream << "\t{" << std::endl;

	stringstream << "\t\t\"" << reflection_type_container.type_name << "\", \"" << reflection_type_container.type_nice_name << "\", " << std::endl;
	stringstream << std::uppercase;
	stringstream << "\t\t0x" << std::hex << reflection_type_container.data_size << "u," << std::endl;
	stringstream << std::nouppercase;
	stringstream << "\t\t" << std::dec << reflection_type_container.fields.size() << "ui32," << std::endl;
	stringstream << "\t\t" << "render_type_gui<" << reflection_type_container.qualified_type_name << ">," << std::endl;
	stringstream << "\t\t" << "{" << std::endl;
	for (const c_reflection_field_container* reflection_field_container_ptr : reflection_type_container.fields)
	{
		assert(reflection_field_container_ptr != nullptr);
		const c_reflection_field_container& reflection_field_container = *reflection_field_container_ptr;
		assert(reflection_field_container.field_type != nullptr);
		const c_reflection_type_container& reflection_type_container = *reflection_field_container.field_type;

		const char* primitive_type_string = reflection_type_container.is_primitive ? reflection_field_container.field_type->qualified_type_name.c_str() : "NonPrimitive";
		const char* reflection_type_category_string = ReflectionTypeCategoryToString(reflection_field_container.reflection_type_category);

		stringstream << "\t\t\t{ \"" << reflection_field_container.field_name << "\", \"" << reflection_field_container.field_nice_name << "\", ";
		{
			switch (reflection_field_container.reflection_type_category)
			{
			case ReflectionTypeCategory::TagBlock:
				stringstream << "ReflectionTagBlockInfo";
				break;
			case ReflectionTypeCategory::Structure:
				stringstream << "ReflectionStructureInfo";
				break;
			default:
				stringstream << "ReflectionTypeInfo";
				break;
			}
			stringstream << "{ " << "ReflectionTypeCategory::" << reflection_type_category_string;
			stringstream << ", PrimitiveType::" << primitive_type_string;
			stringstream << ", \"" << reflection_type_container.qualified_type_name << "\"";
			switch (reflection_field_container.reflection_type_category)
			{
			case ReflectionTypeCategory::TagBlock:
				//#TODO: Print a Visual Studio warning for tab blocks without their types specified
				if (!reflection_field_container.field_type->template_types.empty())
				{
					//#TODO: Print a Visual Studio warning for tab blocks with too many types specified. The first only will be used
					stringstream << ", &runtime_reflection<" << reflection_field_container.field_type->template_types[0]->qualified_type_name << ">()";
				}
				else stringstream << ", nullptr";
				break;
			case ReflectionTypeCategory::Structure:
				stringstream << ", &runtime_reflection<" << reflection_field_container.field_type->qualified_type_name << ">()";
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
