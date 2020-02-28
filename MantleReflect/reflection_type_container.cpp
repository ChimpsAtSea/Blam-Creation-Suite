#include "mantlereflect-private-pch.h"

c_reflection_type_container::c_reflection_type_container()
	: m_isSizeInitialized(false)
	, m_isPrimitive(true)
	, pRecordDeclaration(nullptr)
	, m_tagGroup()
	, m_typeName()
	, m_qualifiedTypeName()
	, m_fieldsData()
	, m_size()
	, m_typeNiceName()
	, m_isTypeTemplate(false)
	, m_pTemplateTypes()
{
}

c_reflection_type_container::c_reflection_type_container(std::string typeName, uint32_t size)
	: m_isSizeInitialized(true)
	, m_isPrimitive(true)
	, pRecordDeclaration(nullptr)
	, m_tagGroup()
	, m_typeName(typeName)
	, m_qualifiedTypeName(typeName)
	, m_fieldsData()
	, m_size(size)
	, m_typeNiceName()
	, m_isTypeTemplate(false)
	, m_pTemplateTypes()
{
}

c_reflection_type_container::~c_reflection_type_container()
{
	for (c_reflection_field_container* pField : m_fieldsData)
	{
		delete pField;
	}
}