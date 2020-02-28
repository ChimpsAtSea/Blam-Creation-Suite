#pragma once

class c_reflection_type_container;

class c_reflection_field_container
{
public:
	c_reflection_field_container();

	std::string m_fieldName;
	std::string m_fieldNiceName;
	ReflectionTypeCategory m_reflectionTypeCategory;
	PrimitiveType m_primitiveType;
	c_reflection_type_container* m_pFieldType;
	uint64_t m_arraySize;
	uint64_t m_offset;
	uint64_t m_size;
	bool m_isHiddenByDefault;
};


