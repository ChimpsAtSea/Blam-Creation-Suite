#pragma once

#pragma once

struct ReflectionMember
{
	const char* pType;
	const char* pName;
};

struct ReflectionData
{
	const char* pType;
	size_t count;
	ReflectionMember members[];
};

template<typename T>
constexpr const ReflectionData& GetReflectionData();


