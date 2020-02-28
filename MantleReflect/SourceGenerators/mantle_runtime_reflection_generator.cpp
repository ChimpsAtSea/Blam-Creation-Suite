#include "mantlereflect-private-pch.h"

c_mantle_runtime_reflection_generator::c_mantle_runtime_reflection_generator(const wchar_t* output_header_file, const wchar_t* output_source_file, std::vector<c_reflection_type_container*>& reflection_types) :
	c_ast_source_generator(output_header_file, output_source_file, reflection_types)
{

}

void c_mantle_runtime_reflection_generator::run()
{
	header_string_stream << "#pragma once" << std::endl << std::endl;

	for (c_reflection_type_container* reflection_type_container : reflection_types)
	{
		write_reflection_type_entry(*reflection_type_container);
	}

	write_tag_type_lookup_function();
}

void c_mantle_runtime_reflection_generator::write_tag_type_lookup_function()
{
	header_string_stream << std::endl;
	header_string_stream << "inline const ReflectionType* GetTagReflectionDataByTagGroup(uint32_t tagGroup)" << std::endl;
	header_string_stream << "{" << std::endl;
	header_string_stream << "\tswitch (tagGroup)" << std::endl;
	header_string_stream << "\t{" << std::endl;
	for (c_reflection_type_container* pType : reflection_types)
	{
		c_reflection_type_container& rType = *pType;
		if (!rType.m_tagGroup.empty())
		{
			const uint32_t& rawTagGroup = *reinterpret_cast<const uint32_t*>(rType.m_tagGroup.data());
			uint64_t swappedTagGroupWithPadding = bswap(rawTagGroup);
			const char* pTagGroupSwapped = reinterpret_cast<const char*>(&swappedTagGroupWithPadding);

			header_string_stream << "\tcase '" << rType.m_tagGroup << "':" << std::endl;
			if (rawTagGroup != swappedTagGroupWithPadding)
			{
				header_string_stream << "\tcase '" << pTagGroupSwapped << "':" << std::endl;
			}
			header_string_stream << "\t\treturn &GetReflectionType<" << rType.m_qualifiedTypeName << ">();" << std::endl;
		}
	}
	header_string_stream << "\t}" << std::endl;
	header_string_stream << "\treturn nullptr;" << std::endl;
	header_string_stream << "}" << std::endl;
	header_string_stream << std::endl;
}
void c_mantle_runtime_reflection_generator::write_reflection_type_entry(const c_reflection_type_container& rType)
{
	if (rType.m_isPrimitive)
	{
		// skip internal types
		return;
	}

	header_string_stream << "template<>" << std::endl;

	//if (!rType.m_isTypeTemplate)
	{
		header_string_stream << "inline const ReflectionType& GetReflectionType<" << rType.m_qualifiedTypeName << ">()" << std::endl;
	}
	//else
	//{
	//	stringstream << "inline const ReflectionType& GetReflectionType<" << rType.m_typeName << "<";

	//	if (!rType.m_pTemplateTypes.empty())
	//	{
	//		for (ReflectionTypeContainer* pTemplateType : rType.m_pTemplateTypes)
	//		{
	//			stringstream << pTemplateType->m_typeName << ", ";
	//		}
	//		stringstream.seekp(-2, stringstream.cur); // remove trailing ", "
	//	}
	//	
	//	stringstream << ">>()" << std::endl;
	//}
	header_string_stream << "{" << std::endl;
	header_string_stream << "\t" << "static ReflectionType reflectionData = " << std::endl;
	header_string_stream << "\t{" << std::endl;

	header_string_stream << "\t\t\"" << rType.m_typeName << "\", \"" << rType.m_typeNiceName << "\", " << std::endl;
	header_string_stream << std::uppercase;
	header_string_stream << "\t\t0x" << std::hex << rType.m_size << "u," << std::endl;
	header_string_stream << std::nouppercase;
	header_string_stream << "\t\t" << std::dec << rType.m_fieldsData.size() << "ui32," << std::endl;
	header_string_stream << "\t\t" << "{" << std::endl;
	for (const c_reflection_field_container* pField : rType.m_fieldsData)
	{
		const c_reflection_field_container& rField = *pField;
		const c_reflection_type_container& rFieldType = *rField.m_pFieldType;
		assert(&rField);
		assert(&rFieldType);

		const char* pPrimitiveTypeStr = rFieldType.m_isPrimitive ? rField.m_pFieldType->m_qualifiedTypeName.c_str() : "NonPrimitive";
		const char* pReflectionTypeCategoryStr = ReflectionTypeCategoryToString(rField.m_reflectionTypeCategory);

		header_string_stream << "\t\t\t{ \"" << rField.m_fieldName << "\", \"" << rField.m_fieldNiceName << "\", ";
		{
			switch (rField.m_reflectionTypeCategory)
			{
			case ReflectionTypeCategory::TagBlock:
				header_string_stream << "ReflectionTagBlockInfo";
				break;
			case ReflectionTypeCategory::Structure:
				header_string_stream << "ReflectionStructureInfo";
				break;
			default:
				header_string_stream << "ReflectionTypeInfo";
				break;
			}
			header_string_stream << "{ " << "ReflectionTypeCategory::" << pReflectionTypeCategoryStr;
			header_string_stream << ", PrimitiveType::" << pPrimitiveTypeStr;
			header_string_stream << ", \"" << rFieldType.m_qualifiedTypeName << "\"";
			switch (rField.m_reflectionTypeCategory)
			{
			case ReflectionTypeCategory::TagBlock:
				//#TODO: Print a Visual Studio warning for tab blocks without their types specified
				if (!rField.m_pFieldType->m_pTemplateTypes.empty())
				{
					//#TODO: Print a Visual Studio warning for tab blocks with too many types specified. The first only will be used
					header_string_stream << ", &GetReflectionType<" << rField.m_pFieldType->m_pTemplateTypes[0]->m_qualifiedTypeName << ">()";
				}
				else header_string_stream << ", nullptr";
				break;
			case ReflectionTypeCategory::Structure:
				header_string_stream << ", &GetReflectionType<" << rField.m_pFieldType->m_qualifiedTypeName << ">()";
				break;
			}
			header_string_stream << " }";
		}
		header_string_stream << std::uppercase;
		header_string_stream << ", 0x" << std::hex << rField.m_offset << "ui32";
		//stringstream << ", offsetof(" << rType.m_qualifiedTypeName << ", " << rType.m_qualifiedTypeName << "::" << rField.m_fieldName << ")"; // #TODO: Generate offsetof code where possible
		header_string_stream << ", 0x" << std::hex << rField.m_size << "ui16";
		header_string_stream << std::nouppercase;
		header_string_stream << ", " << std::dec << rField.m_arraySize << "ui32";
		header_string_stream << ", " << (rField.m_isHiddenByDefault ? "true" : "false");
		header_string_stream << " }," << std::endl;
	}
	header_string_stream << "\t\t\t{ }" << std::endl;

	header_string_stream << "\t\t" << "}" << std::endl;
	header_string_stream << "\t" << "};" << std::endl << std::endl;
	header_string_stream << "\treturn reflectionData;" << std::endl;

	header_string_stream << "}" << std::endl << std::endl;
}
