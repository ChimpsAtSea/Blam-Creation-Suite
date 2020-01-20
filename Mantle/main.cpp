#include "mantle-private-pch.h"

int main()
{
	const ReflectionData& reflectionData = GetReflectionData<s_scenario_definition>();

	printf("struct %s {\n", reflectionData.pType);
	for (size_t i = 0; i < reflectionData.count; i++)
	{
		const ReflectionMember& reflectionMember = reflectionData.members[i];

		printf("\t%s %s;\n", reflectionMember.pType, reflectionMember.pName);
	}
	printf("};\n");

	return 0;
}
