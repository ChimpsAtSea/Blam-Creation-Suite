#pragma once

#pragma pack(push, 1)

enum class ReflectionTypeCategory : unsigned __int8
{
	Primitive,
	BitFlag,
	BitField,
	Structure,
	TagReference,
	TagBlock,
	DataReference,
	ShaderData,
	StringID,
	Unknown8,
	Unknown16,
	Unknown32,
	Unknown64,
};

typedef unsigned __int16 ReflectionTypeIndex;
enum class PrimitiveType : ReflectionTypeIndex
{
	Undefined,
	Int8,
	Int16,
	Int32,
	Int64,
	UInt8,
	UInt16,
	UInt32,
	UInt64,
	Float,
	Double,
	Boolean8,
	Boolean16,
	Boolean32,
	Boolean64,
	Enum8,
	Enum16,
	Enum32,
	Enum64,
	BitFlag,
	BitField
};

inline const char* ReflectionTypeCategoryToString(ReflectionTypeCategory reflectionType)
{
	switch (reflectionType)
	{
	case ReflectionTypeCategory::Primitive:				return "Primitive";
	case ReflectionTypeCategory::BitFlag:				return "BitFlag";
	case ReflectionTypeCategory::BitField:				return "BitField";
	case ReflectionTypeCategory::Structure:				return "Structure";
	case ReflectionTypeCategory::TagReference:			return "TagReference";
	case ReflectionTypeCategory::TagBlock:				return "TagBlock";
	case ReflectionTypeCategory::DataReference:			return "DataReference";
	case ReflectionTypeCategory::ShaderData:			return "ShaderData";
	case ReflectionTypeCategory::StringID:				return "StringID";
	case ReflectionTypeCategory::Unknown8:				return "Unknown8";
	case ReflectionTypeCategory::Unknown16:				return "Unknown16";
	case ReflectionTypeCategory::Unknown32:				return "Unknown32";
	case ReflectionTypeCategory::Unknown64:				return "Unknown64";
	}
#ifdef _DEBUG
	throw;
#endif
	return "<INVALID REFLECTION TYPE>";
}

struct ReflectionTypeInfo
{
	ReflectionTypeCategory m_reflectionTypeCategory;
	union
	{
		PrimitiveType m_primitiveTypeIndex;
		ReflectionTypeIndex m_reflectionTypeIndex;
	};
	const char* m_pTypeName;
};

struct ReflectionType;

struct ReflectionStructureInfo : ReflectionTypeInfo
{
	const ReflectionType* m_pReflectionTypeInfo;
};

struct ReflectionField
{
	ReflectionField()
	{
		m_pMemberName = {};
		m_pMemberNiceName = {};
		m_typeInfo = {};
		m_structureInfo = {};
		m_offset = {};
		m_size = {};
		m_arraySize = {};
		m_isHiddenByDefault = {};
	}

	ReflectionField(
		const char* pMemberName,
		const char* pMemberNiceName,
		ReflectionTypeInfo typeInfo,
		unsigned __int32 offset,
		unsigned __int16 size,
		unsigned __int32 arraySize,
		bool isHiddenByDefault
	)
		: m_pMemberName(pMemberName)
		, m_pMemberNiceName(pMemberNiceName)
		, m_offset(offset)
		, m_size(size)
		, m_arraySize(arraySize)
		, m_isHiddenByDefault(isHiddenByDefault)
	{
		m_structureInfo = {};
		m_typeInfo = typeInfo;
	}

	ReflectionField(
		const char* pMemberName,
		const char* pMemberNiceName,
		ReflectionStructureInfo structureInfo,
		unsigned __int32 offset,
		unsigned __int16 size,
		unsigned __int32 arraySize,
		bool isHiddenByDefault
	)
		: m_pMemberName(pMemberName)
		, m_pMemberNiceName(pMemberNiceName)
		, m_offset(offset)
		, m_size(size)
		, m_arraySize(arraySize)
		, m_isHiddenByDefault(isHiddenByDefault)
	{
		m_typeInfo = {};
		m_structureInfo = structureInfo;
	}

	const char* m_pMemberName;
	const char* m_pMemberNiceName;
	union {
		ReflectionTypeInfo m_typeInfo;
		ReflectionStructureInfo m_structureInfo;
	};
	unsigned __int32 m_offset;
	unsigned __int16 m_size;
	unsigned __int32 m_arraySize;
	bool m_isHiddenByDefault;
};

#pragma warning( push )
#pragma warning( disable : 4200 ) // allow using non standard language features without warning
struct ReflectionType
{
	const char* m_pTypeName;
	const char* m_pTypeNiceName;
	unsigned __int32 m_size;
	unsigned __int32 m_count;
	ReflectionField m_members[]; // #NOTE: non standard language feature
};
#pragma warning( pop )

template<typename T>
constexpr const ReflectionType& GetReflectionType();

#pragma pack(pop)

// intellisense beautiful code hacks
#ifdef __INTELLISENSE__

#endif
