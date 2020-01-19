#pragma once

#pragma once

struct ReflectionMember
{

};

struct ReflectionData
{
	size_t count;
	ReflectionMember members[];
};

template<typename T>
const constexpr ReflectionData& GetReflectionData();


