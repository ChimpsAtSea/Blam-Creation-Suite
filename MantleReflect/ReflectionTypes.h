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
	BitField8,
	BitField16,
	BitField32,
	BitField64,
	BitFlag8,
	BitFlag16,
	BitFlag32,
	BitFlag64,
};

inline const char* PrimitiveTypeToString(PrimitiveType primitiveType)
{
	switch (primitiveType)
	{
	case PrimitiveType::Undefined:			return "Undefined";
	case PrimitiveType::Int8:				return "Int8";
	case PrimitiveType::Int16:				return "Int16";
	case PrimitiveType::Int32:				return "Int32";
	case PrimitiveType::Int64:				return "Int64";
	case PrimitiveType::UInt8:				return "UInt8";
	case PrimitiveType::UInt16:				return "UInt16";
	case PrimitiveType::UInt32:				return "UInt32";
	case PrimitiveType::UInt64:				return "UInt64";
	case PrimitiveType::Float:				return "Float";
	case PrimitiveType::Double:				return "Double";
	case PrimitiveType::Boolean8:			return "Boolean8";
	case PrimitiveType::Boolean16:			return "Boolean16";
	case PrimitiveType::Boolean32:			return "Boolean32";
	case PrimitiveType::Boolean64:			return "Boolean64";
	case PrimitiveType::Enum8:				return "Enum8";
	case PrimitiveType::Enum16:				return "Enum16";
	case PrimitiveType::Enum32:				return "Enum32";
	case PrimitiveType::Enum64:				return "Enum64";
	case PrimitiveType::BitField8:			return "BitField8";
	case PrimitiveType::BitField16:			return "BitField16";
	case PrimitiveType::BitField32:			return "BitField32";
	case PrimitiveType::BitField64:			return "BitField64";
	case PrimitiveType::BitFlag8:			return "BitFlag8";
	case PrimitiveType::BitFlag16:			return "BitFlag16";
	case PrimitiveType::BitFlag32:			return "BitFlag32";
	case PrimitiveType::BitFlag64:			return "BitFlag64";
	}
#ifdef FATAL_ERROR
	FATAL_ERROR("Invalid primitive type");
#else
	throw;
#endif
}

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
#ifdef FATAL_ERROR
	FATAL_ERROR("Invalid reflection type");
#else
	throw;
#endif
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

struct ReflectionTagBlockInfo : ReflectionTypeInfo
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
		m_tagBlockInfo = {};
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
		m_tagBlockInfo = {};
		m_structureInfo = structureInfo;
	}

	ReflectionField(
		const char* pMemberName,
		const char* pMemberNiceName,
		ReflectionTagBlockInfo tagBlockInfo,
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
		m_structureInfo = {};
		m_tagBlockInfo = tagBlockInfo;
	}

	const char* m_pMemberName;
	const char* m_pMemberNiceName;
	union {
		ReflectionTypeInfo m_typeInfo;
		ReflectionStructureInfo m_structureInfo;
		ReflectionTagBlockInfo m_tagBlockInfo;
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
inline const ReflectionType& GetReflectionType();

#pragma pack(pop)

// intellisense beautiful code hacks
#ifdef __INTELLISENSE__

#endif
