#include "mantle-private-pch.h"

template<typename TagType>
inline const ReflectionType& GetTagReflectionData()
{
	return GetTagReflectionData(TagType::kTagGroupName);
}

inline const ReflectionType& GetTagReflectionData(TagGroupName tagGroupName)
{
	switch (tagGroupName)
	{
	case TagGroupName::Scenario: return GetReflectionType<s_scenario_definition>();
	}
	assert(!"Failed to find tag reflection data");
	throw;
}

template<typename T>
inline const ReflectionType& GetReflectionType(const T& member)
{
	return GetReflectionType<T>();
}

void PrintReflectionInfo(const ReflectionType& reflectionData)
{
	printf("struct %s {\n", reflectionData.m_pTypeName);
	for (size_t i = 0; i < reflectionData.m_count; i++)
	{
		const ReflectionField& ReflectionField = reflectionData.m_members[i];

		if (ReflectionField.m_arraySize)
		{
			printf("\t%s %s[%u]; // size:0x%X offset:0x%X\n", ReflectionField.m_typeInfo.m_pTypeName, ReflectionField.m_pMemberName, ReflectionField.m_arraySize, ReflectionField.m_size, ReflectionField.m_offset);
		}
		else
		{
			printf("\t%s %s; // size:0x%X offset:0x%X\n", ReflectionField.m_typeInfo.m_pTypeName, ReflectionField.m_pMemberName, ReflectionField.m_size, ReflectionField.m_offset);
		}
	}

	printf("};\n");
}

int main()
{
	s_scenario_definition scenario;
	
	const ReflectionType& scenarioReflectionData = GetTagReflectionData<s_scenario_definition>();
	const ReflectionType& biped_palette_blockReflectionData = GetReflectionType(scenario.biped_palette_block);
	PrintReflectionInfo(scenarioReflectionData);

	for (int i = 0; i < biped_palette_blockReflectionData.m_count; i++) // multithreaded
	{
		biped_palette_blockReflectionData.m_members[i]; // do something
	}

	return 0;
}
