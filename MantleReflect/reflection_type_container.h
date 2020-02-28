#pragma once

class c_reflection_type_container
{
public:
	c_reflection_type_container();
	c_reflection_type_container(std::string typeName, uint32_t size);
	~c_reflection_type_container();

	bool m_isSizeInitialized;
	bool m_isPrimitive;
	const clang::RecordDecl* pRecordDeclaration;
	std::string m_tagGroup;
	std::string m_typeName;
	std::string m_qualifiedTypeName;
	std::vector<c_reflection_field_container*> m_fieldsData;
	uint32_t m_size;
	std::string m_typeNiceName;
	bool m_isTypeTemplate;
	std::vector<c_reflection_type_container*> m_pTemplateTypes;
};

