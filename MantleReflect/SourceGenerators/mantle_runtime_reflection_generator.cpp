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
	for (c_reflection_type_container* pType : reflection_types)
	{
		c_reflection_type_container& rType = *pType;
		if (!rType.m_tagGroup.empty())
		{
			const uint32_t& rawTagGroup = *reinterpret_cast<const uint32_t*>(rType.m_tagGroup.data());
			uint64_t swappedTagGroupWithPadding = bswap(rawTagGroup);
			const char* pTagGroupSwapped = reinterpret_cast<const char*>(&swappedTagGroupWithPadding);

			stringstream << "\tcase '" << rType.m_tagGroup << "':" << std::endl;
			if (rawTagGroup != swappedTagGroupWithPadding)
			{
				stringstream << "\tcase '" << pTagGroupSwapped << "':" << std::endl;
			}
			stringstream << "\t\treturn &runtime_reflection<" << rType.m_qualifiedTypeName << ">();" << std::endl;
		}
	}
	stringstream << "\t}" << std::endl;
	stringstream << "\treturn nullptr;" << std::endl;
	stringstream << "}" << std::endl;
	stringstream << std::endl;
}
void c_mantle_runtime_reflection_generator::write_reflection_type_entry_header(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.m_isPrimitive)
	{
		// skip internal types
		return;
	}
	
	stringstream << "template<> ";
	stringstream << "const ReflectionType& runtime_reflection<" << reflection_type_container.m_qualifiedTypeName << ">();" << std::endl;
}

void c_mantle_runtime_reflection_generator::write_reflection_type_entry(std::stringstream& stringstream, const c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.m_isPrimitive)
	{
		// skip internal types
		return;
	}

	stringstream << "template<>" << std::endl;
	stringstream << "const ReflectionType& runtime_reflection<" << reflection_type_container.m_qualifiedTypeName << ">()" << std::endl;
	
	stringstream << "{" << std::endl;
	stringstream << "\t" << "static ReflectionType reflectionData = " << std::endl;
	stringstream << "\t{" << std::endl;

	stringstream << "\t\t\"" << reflection_type_container.m_typeName << "\", \"" << reflection_type_container.m_typeNiceName << "\", " << std::endl;
	stringstream << std::uppercase;
	stringstream << "\t\t0x" << std::hex << reflection_type_container.m_size << "u," << std::endl;
	stringstream << std::nouppercase;
	stringstream << "\t\t" << std::dec << reflection_type_container.m_fieldsData.size() << "ui32," << std::endl;
	stringstream << "\t\t" << "render_type_gui<" << reflection_type_container.m_qualifiedTypeName << ">," << std::endl;
	stringstream << "\t\t" << "{" << std::endl;
	for (const c_reflection_field_container* pField : reflection_type_container.m_fieldsData)
	{
		const c_reflection_field_container& rField = *pField;
		const c_reflection_type_container& rFieldType = *rField.m_pFieldType;
		assert(&rField);
		assert(&rFieldType);

		const char* pPrimitiveTypeStr = rFieldType.m_isPrimitive ? rField.m_pFieldType->m_qualifiedTypeName.c_str() : "NonPrimitive";
		const char* pReflectionTypeCategoryStr = ReflectionTypeCategoryToString(rField.m_reflectionTypeCategory);

		stringstream << "\t\t\t{ \"" << rField.m_fieldName << "\", \"" << rField.m_fieldNiceName << "\", ";
		{
			switch (rField.m_reflectionTypeCategory)
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
			stringstream << "{ " << "ReflectionTypeCategory::" << pReflectionTypeCategoryStr;
			stringstream << ", PrimitiveType::" << pPrimitiveTypeStr;
			stringstream << ", \"" << rFieldType.m_qualifiedTypeName << "\"";
			switch (rField.m_reflectionTypeCategory)
			{
			case ReflectionTypeCategory::TagBlock:
				//#TODO: Print a Visual Studio warning for tab blocks without their types specified
				if (!rField.m_pFieldType->m_pTemplateTypes.empty())
				{
					//#TODO: Print a Visual Studio warning for tab blocks with too many types specified. The first only will be used
					stringstream << ", &runtime_reflection<" << rField.m_pFieldType->m_pTemplateTypes[0]->m_qualifiedTypeName << ">()";
				}
				else stringstream << ", nullptr";
				break;
			case ReflectionTypeCategory::Structure:
				stringstream << ", &runtime_reflection<" << rField.m_pFieldType->m_qualifiedTypeName << ">()";
				break;
			}
			stringstream << " }";
		}
		stringstream << std::uppercase;
		stringstream << ", 0x" << std::hex << rField.m_offset << "ui32";
		//stringstream << ", offsetof(" << rType.m_qualifiedTypeName << ", " << rType.m_qualifiedTypeName << "::" << rField.m_fieldName << ")"; // #TODO: Generate offsetof code where possible
		stringstream << ", 0x" << std::hex << rField.m_size << "ui16";
		stringstream << std::nouppercase;
		stringstream << ", " << std::dec << rField.m_arraySize << "ui32";
		stringstream << ", " << (rField.m_isHiddenByDefault ? "true" : "false");
		stringstream << " }," << std::endl;
	}
	stringstream << "\t\t\t{ }" << std::endl;

	stringstream << "\t\t" << "}" << std::endl;
	stringstream << "\t" << "};" << std::endl << std::endl;
	stringstream << "\treturn reflectionData;" << std::endl;

	stringstream << "}" << std::endl << std::endl;
}
