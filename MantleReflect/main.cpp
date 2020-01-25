#include "mantlereflect-private-pch.h"

#ifdef _DEBUG_FAST /* change build configuration for full debug */
#pragma optimize("", off)
#endif

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

// llvm/clang things
static llvm::cl::OptionCategory MantleToolCategory("mantle options");
static std::stringstream stringstream;
static LangOptions languageOptions;
static PrintingPolicy printingPolicy = languageOptions;

struct ReflectionTypeContainer;
struct ReflectionFieldContainer;

// reflection temporary containers
struct ReflectionFieldContainer
{
	ReflectionFieldContainer()
		: m_fieldName()
		, m_fieldNiceName()
		, m_reflectionTypeCategory()
		, m_primitiveType()
		, m_pFieldType()
		, m_arraySize()
		, m_offset()
		, m_size()
		, m_isHiddenByDefault()
	{

	}

	std::string m_fieldName;
	std::string m_fieldNiceName;
	ReflectionTypeCategory m_reflectionTypeCategory;
	PrimitiveType m_primitiveType;
	ReflectionTypeContainer* m_pFieldType;
	uint64_t m_arraySize;
	uint64_t m_offset;
	uint64_t m_size;
	bool m_isHiddenByDefault;
};

struct ReflectionTypeContainer
{
	ReflectionTypeContainer()
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

	ReflectionTypeContainer(std::string typeName, uint64_t size)
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

	~ReflectionTypeContainer()
	{
		for (ReflectionFieldContainer* pField : m_fieldsData)
		{
			delete pField;
		}
	}

	bool m_isSizeInitialized;
	bool m_isPrimitive;
	const clang::RecordDecl* pRecordDeclaration;
	std::string m_tagGroup;
	std::string m_typeName;
	std::string m_qualifiedTypeName;
	std::vector<ReflectionFieldContainer*> m_fieldsData;
	uint64_t m_size;
	std::string m_typeNiceName;
	bool m_isTypeTemplate;
	std::vector<ReflectionTypeContainer*> m_pTemplateTypes;
};

const char* FormatNiceNameAndIsHidden(ReflectionTypeCategory reflectionTypeCategory, char* pString, bool* isHiddenByDefault = nullptr)
{
	char* pOutputString = pString;

	uint32_t currentPos = 0;

	if ((pString[0] && pString[1]))
	{
		if (pString[0] == '_' && pString[1] == '_')
		{
			if (isHiddenByDefault)
			{
				*isHiddenByDefault = true;
			}

			pOutputString = pString + 2;

			if (pOutputString[0] == 'u' && strstr(pString, "__unknown") == pOutputString)
			{
				return "Unknown";
			}
		}

		if ((pString[0] == 's' || pString[0] == 'c') && pString[1] == '_')
		{
			pOutputString = pString + 2;

			char* pDefinitionStr = strstr(pOutputString, "_definition");
			if (pDefinitionStr)
			{
				pDefinitionStr[0] = 0;
			}
		}

		if (reflectionTypeCategory == ReflectionTypeCategory::TagBlock)
		{
			char* pBlockString = strstr(pOutputString, "_block");
			if (pBlockString)
			{
				pBlockString[0] = 0;
			}

			char* pBlockString2 = strstr(pOutputString, "_block_definition");
			if (pBlockString2)
			{
				pBlockString2[0] = 0;
			}
		}

		if (reflectionTypeCategory == ReflectionTypeCategory::TagReference)
		{
			char* pReference = strstr(pOutputString, "_reference");
			if (pReference)
			{
				pReference[0] = 0;
			}

			char* pReference2 = strstr(pOutputString, "_definition");
			if (pReference2)
			{
				pReference2[0] = 0;
			}
		}

		if (reflectionTypeCategory == ReflectionTypeCategory::DataReference)
		{
			char* pDataReference = strstr(pOutputString, "_data_reference");
			if (pDataReference)
			{
				pDataReference[0] = 0;
			}

			char* pDefinition = strstr(pOutputString, "_definition");
			if (pDefinition)
			{
				pDefinition[0] = 0;
			}
		}
	}

	if (pOutputString[0] == 0)
	{
		return "Unknown";
	}

	char& currentCharacter = pOutputString[currentPos];
	if (currentCharacter && !std::isupper(currentCharacter))
	{
		currentCharacter = currentCharacter - 0x20;
	}

	while (pOutputString[currentPos])
	{
		char& currentCharacter = pOutputString[currentPos];
		char& nextCharacter = pOutputString[currentPos + 1];
		bool hasNextCharacter = nextCharacter != 0;
		if (currentCharacter == '_' && hasNextCharacter && nextCharacter != '_')
		{
			currentCharacter = ' ';
			nextCharacter = std::isupper(nextCharacter) ? nextCharacter : (nextCharacter - 0x20);
		}

		currentPos++;
	}

	return pOutputString;
}

void CreateNiceNames(ReflectionTypeContainer& rType)
{
	rType.m_typeNiceName = rType.m_typeName;
	rType.m_typeNiceName = FormatNiceNameAndIsHidden(ReflectionTypeCategory::Structure, rType.m_typeNiceName.data());
	for (ReflectionFieldContainer* pField : rType.m_fieldsData)
	{
		ReflectionFieldContainer& rField = *pField;

		rField.m_fieldNiceName = rField.m_fieldName;
		rField.m_isHiddenByDefault = false;
		rField.m_fieldNiceName = FormatNiceNameAndIsHidden(rField.m_reflectionTypeCategory, rField.m_fieldNiceName.data(), &rField.m_isHiddenByDefault);
	}
}

size_t InitTypeSizeAndOffsets(ReflectionTypeContainer& rType)
{
	if (rType.m_isSizeInitialized)
	{
		return rType.m_size;
	}

	uint32_t currentOffset = 0;
	for (ReflectionFieldContainer* pField : rType.m_fieldsData)
	{
		ReflectionFieldContainer& rField = *pField;
		uint64_t fieldSize = InitTypeSizeAndOffsets(*rField.m_pFieldType);
		uint64_t dataSize = fieldSize * __max(1ull, rField.m_arraySize);
		rField.m_size = fieldSize;
		rField.m_offset = currentOffset;
		currentOffset += static_cast<uint32_t>(dataSize);
	}
	rType.m_size = currentOffset;

	return rType.m_size;
}

std::vector<ReflectionTypeContainer*> ReflectedTypesData;

ReflectionTypeContainer* GetPrimitiveReflectionType(PrimitiveType primitiveType)
{
	static ReflectionTypeContainer* pInt8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Int8", sizeof(int8_t)));
	static ReflectionTypeContainer* pInt16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Int16", sizeof(int16_t)));
	static ReflectionTypeContainer* pInt32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Int32", sizeof(int32_t)));
	static ReflectionTypeContainer* pInt64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Int64", sizeof(int64_t)));
	static ReflectionTypeContainer* pUInt8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("UInt8", sizeof(uint8_t)));
	static ReflectionTypeContainer* pUInt16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("UInt16", sizeof(uint16_t)));
	static ReflectionTypeContainer* pUInt32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("UInt32", sizeof(uint32_t)));
	static ReflectionTypeContainer* pUInt64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("UInt64", sizeof(uint64_t)));
	static ReflectionTypeContainer* pBoolean8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Boolean8", sizeof(uint8_t)));
	static ReflectionTypeContainer* pBoolean16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Boolean16", sizeof(uint16_t)));
	static ReflectionTypeContainer* pBoolean32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Boolean32", sizeof(uint32_t)));
	static ReflectionTypeContainer* pBoolean64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Boolean64", sizeof(uint64_t)));
	static ReflectionTypeContainer* pBitField8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitField8", sizeof(uint8_t)));
	static ReflectionTypeContainer* pBitField16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitField16", sizeof(uint16_t)));
	static ReflectionTypeContainer* pBitField32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitField32", sizeof(uint32_t)));
	static ReflectionTypeContainer* pBitField64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitField64", sizeof(uint64_t)));
	static ReflectionTypeContainer* pBitFlag8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitFlag8", sizeof(uint8_t)));
	static ReflectionTypeContainer* pBitFlag16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitFlag16", sizeof(uint16_t)));
	static ReflectionTypeContainer* pBitFlag32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitFlag32", sizeof(uint32_t)));
	static ReflectionTypeContainer* pBitFlag64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("BitFlag64", sizeof(uint64_t)));
	static ReflectionTypeContainer* pFloatReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Float", sizeof(float)));
	static ReflectionTypeContainer* pDoubleReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Double", sizeof(double)));
	static ReflectionTypeContainer* pEnum8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Enum8", sizeof(uint8_t)));
	static ReflectionTypeContainer* pEnum16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Enum16", sizeof(uint16_t)));
	static ReflectionTypeContainer* pEnum32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Enum32", sizeof(uint32_t)));
	static ReflectionTypeContainer* pEnum64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Enum64", sizeof(uint64_t)));
	static ReflectionTypeContainer* pUndefined8ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Undefined8", sizeof(uint8_t)));
	static ReflectionTypeContainer* pUndefined16ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Undefined16", sizeof(uint16_t)));
	static ReflectionTypeContainer* pUndefined32ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Undefined32", sizeof(uint32_t)));
	static ReflectionTypeContainer* pUndefined64ReflectionType = ReflectedTypesData.emplace_back(new ReflectionTypeContainer("Undefined64", sizeof(uint64_t)));

	switch (primitiveType)
	{
	case PrimitiveType::Int8:			return pInt8ReflectionType;
	case PrimitiveType::Int16:			return pInt16ReflectionType;
	case PrimitiveType::Int32:			return pInt32ReflectionType;
	case PrimitiveType::Int64:			return pInt64ReflectionType;
	case PrimitiveType::UInt8:			return pUInt8ReflectionType;
	case PrimitiveType::UInt16:			return pUInt16ReflectionType;
	case PrimitiveType::UInt32:			return pUInt32ReflectionType;
	case PrimitiveType::UInt64:			return pUInt64ReflectionType;
	case PrimitiveType::Boolean8:		return pBoolean8ReflectionType;
	case PrimitiveType::Boolean16:		return pBoolean16ReflectionType;
	case PrimitiveType::Boolean32:		return pBoolean32ReflectionType;
	case PrimitiveType::Boolean64:		return pBoolean64ReflectionType;
	case PrimitiveType::BitFlag8:		return pBitFlag8ReflectionType;
	case PrimitiveType::BitFlag16:		return pBitFlag16ReflectionType;
	case PrimitiveType::BitFlag32:		return pBitFlag32ReflectionType;
	case PrimitiveType::BitFlag64:		return pBitFlag64ReflectionType;
	case PrimitiveType::BitField8:		return pBitField8ReflectionType;
	case PrimitiveType::BitField16:		return pBitField16ReflectionType;
	case PrimitiveType::BitField32:		return pBitField32ReflectionType;
	case PrimitiveType::BitField64:		return pBitField64ReflectionType;
	case PrimitiveType::Float:			return pFloatReflectionType;
	case PrimitiveType::Double:			return pDoubleReflectionType;
	case PrimitiveType::Enum8:			return pEnum8ReflectionType;
	case PrimitiveType::Enum16:			return pEnum16ReflectionType;
	case PrimitiveType::Enum32:			return pEnum32ReflectionType;
	case PrimitiveType::Enum64:			return pEnum64ReflectionType;
	case PrimitiveType::Undefined8:		return pUndefined8ReflectionType;
	case PrimitiveType::Undefined16:	return pUndefined16ReflectionType;
	case PrimitiveType::Undefined32:	return pUndefined32ReflectionType;
	case PrimitiveType::Undefined64:	return pUndefined64ReflectionType;
	}

	assert(!"Undefined primitive type");
	return nullptr;
}

ReflectionTypeContainer* CreateReflectedType(ASTContext* Context, const clang::QualType* recordQualifiedType, const clang::RecordDecl& rRecordDeclaration, bool isPrimitive = false)
{
	std::string declarationName = rRecordDeclaration.getNameAsString();
	std::string qualifiedDeclarationName;
	if (recordQualifiedType)
	{
		qualifiedDeclarationName = QualType::getAsString(recordQualifiedType->split(), printingPolicy);
	}
	else // construct best qualified type name
	{
		if (rRecordDeclaration.isClass())
		{
			qualifiedDeclarationName += "class ";
		}
		else if (rRecordDeclaration.isStruct())
		{
			qualifiedDeclarationName += "struct ";
		}
		qualifiedDeclarationName += rRecordDeclaration.getQualifiedNameAsString();
	}

	RecordDecl::field_range fields = rRecordDeclaration.fields();
	size_t numFields = false; for (FieldDecl* field : fields) { numFields++; }

	bool isTemplated = rRecordDeclaration.isTemplated();
	const clang::ClassTemplateSpecializationDecl* pClassTemplateSpecializationDecl = dyn_cast<ClassTemplateSpecializationDecl>(&rRecordDeclaration);
	if (isTemplated && pClassTemplateSpecializationDecl == nullptr)
	{
		return nullptr;
	}

	ReflectionTypeContainer* pExistingReflectionTypeContainer = nullptr;
	{ // handle existing records
		for (ReflectionTypeContainer* rReflectionTypeContainer : ReflectedTypesData)
		{
			if (rReflectionTypeContainer->pRecordDeclaration == &rRecordDeclaration || rReflectionTypeContainer->m_qualifiedTypeName == qualifiedDeclarationName)
			{
				pExistingReflectionTypeContainer = rReflectionTypeContainer;

			}
		}
	}
	if (pExistingReflectionTypeContainer)
	{
		if (numFields == 0)
		{
			return pExistingReflectionTypeContainer; // we already have data for this
		}
		else if (!pExistingReflectionTypeContainer->m_fieldsData.empty())
		{
			return pExistingReflectionTypeContainer; // we already have data for this
		}
	}

	// if existing reflection container exists and we're updating it, replace all data

	bool createdNewReflectionContainer = pExistingReflectionTypeContainer == nullptr;
	ReflectionTypeContainer* pReflectionTypeContainer = pExistingReflectionTypeContainer;
	if (createdNewReflectionContainer)
	{
		pReflectionTypeContainer = new ReflectionTypeContainer();
	}
	ReflectionTypeContainer& rReflectionTypeContainer = *pReflectionTypeContainer;

	assert(rReflectionTypeContainer.m_fieldsData.empty());

	rReflectionTypeContainer.m_typeName = declarationName;
	rReflectionTypeContainer.m_qualifiedTypeName = qualifiedDeclarationName;
	rReflectionTypeContainer.pRecordDeclaration = &rRecordDeclaration;
	rReflectionTypeContainer.m_isPrimitive = isPrimitive;

	if (pClassTemplateSpecializationDecl)
	{
		rReflectionTypeContainer.m_isTypeTemplate = true;

		const clang::TemplateArgumentList& rArgList = pClassTemplateSpecializationDecl->getTemplateArgs();
		for (unsigned int i = 0; i < rArgList.size(); i++)
		{
			const clang::TemplateArgument& rArg = rArgList.get(i);
			QualType qualifiedType = rArg.getAsType();

			bool isVoid = qualifiedType->isVoidType();
			assert(rArgList.size() <= 1 || !isVoid); // no voids allowed unless single void template
			if (!isVoid)
			{
				const std::string reflectionQualifiedTypeName = QualType::getAsString(qualifiedType.split(), printingPolicy);
				CXXRecordDecl* pDecl = qualifiedType->getAsCXXRecordDecl();
				assert(pDecl != nullptr);
				ReflectionTypeContainer* pTemplateType = CreateReflectedType(Context, &qualifiedType, *pDecl);
				assert(pTemplateType != nullptr);
				rReflectionTypeContainer.m_pTemplateTypes.push_back(pTemplateType);
			}
		}
	}

	bool disableReflection = false;
	std::string no_reflection_str;
	std::string nice_name_str;
	std::string tag_group_str;
	for (clang::Attr* it : rRecordDeclaration.attrs())
	{
		Attr& attr = (*it);
		AnnotateAttr* annotatedAttr = dyn_cast<AnnotateAttr>(&attr);
		if (annotatedAttr != nullptr)
		{
			std::string str = annotatedAttr->getAnnotation();

			const char* pNoReflection = strstr(str.c_str(), "no_reflection");
			const char* pNiceName = strstr(str.c_str(), "nice_name");
			const char* pTagGroup = strstr(str.c_str(), "tag_group");

			if (pNoReflection)
			{
				disableReflection = true;
			}
			if (pNiceName)
			{
				nice_name_str = pNiceName + strlen("nice_name:");
			}
			if (pTagGroup)
			{
				const char* pTagGroupStringBegin = pTagGroup + strlen("tag_group:");
				size_t tagGroupRawStringLength = strlen(pTagGroupStringBegin);
				assert(tagGroupRawStringLength == 6);
				char pBuffer[5] = // #NOTE: We expect to receive these characters swapped. We're swapping them back to the original integer order
				{
					pTagGroupStringBegin[4],
					pTagGroupStringBegin[3],
					pTagGroupStringBegin[2],
					pTagGroupStringBegin[1],
					0
				};
				tag_group_str = pBuffer;
			}
		}
	}

	rReflectionTypeContainer.m_tagGroup = tag_group_str;

	if (disableReflection)
	{
		return &rReflectionTypeContainer;
	}

	for (FieldDecl* field : fields)
	{
		ReflectionFieldContainer& rFieldData = *rReflectionTypeContainer.m_fieldsData.emplace_back(new ReflectionFieldContainer());

		const clang::QualType fieldQualifiedType = field->getType();
		const clang::Type* fieldType = fieldQualifiedType.getTypePtr();

		const std::string fieldQualifiedTypeName = QualType::getAsString(fieldQualifiedType.split(), printingPolicy);
		const std::string fieldQualifiedName = field->getQualifiedNameAsString();
		const std::string fieldName = field->getNameAsString();

		rFieldData.m_fieldName = fieldName;

		const clang::Type* const reflectionBaseType = fieldType;
		const clang::QualType reflectionQualifiedBaseType = reflectionBaseType->getCanonicalTypeInternal();
		clang::QualType reflectionQualifiedType = reflectionQualifiedBaseType;

		if (reflectionQualifiedType->isArrayType())
		{
			const ConstantArrayType* pConstantArrayType = Context->getAsConstantArrayType(reflectionQualifiedType);
			if (pConstantArrayType)
			{
				llvm::APInt arraySizeRaw = pConstantArrayType->getSize();
				rFieldData.m_arraySize = *arraySizeRaw.getRawData();
				assert(rFieldData.m_arraySize > 0);

				QualType elementType = pConstantArrayType->getElementType();
				reflectionQualifiedType = elementType->getCanonicalTypeInternal();
			}
			else assert(!"Unsupported array type");
		}
		const std::string reflectionQualifiedTypeName = QualType::getAsString(reflectionQualifiedType.split(), printingPolicy);


		if (reflectionQualifiedType->isClassType() || reflectionQualifiedType->isStructureType())
		{
			TagDecl* pTagDecl = reflectionQualifiedType->getAsTagDecl();
			clang::RecordDecl* pCXXRecord = static_cast<clang::RecordDecl*>(pTagDecl);
			std::string name = pTagDecl->getNameAsString();

			ReflectionTypeCategory reflectionTypeCategory;
			{
				if (name == "TagBlock") reflectionTypeCategory = ReflectionTypeCategory::TagBlock;
				else if (name == "s_tag_block_definition") reflectionTypeCategory = ReflectionTypeCategory::TagBlock;
				else if (name == "DataReference") reflectionTypeCategory = ReflectionTypeCategory::DataReference;
				else if (name == "string_id") reflectionTypeCategory = ReflectionTypeCategory::StringID;
				else if (name == "StringID") reflectionTypeCategory = ReflectionTypeCategory::StringID;
				//else if (name == "TagGroupName") reflectionTypeCategory = ReflectionTypeCategory::TagGroupName; 
				else if (name == "TagReference") reflectionTypeCategory = ReflectionTypeCategory::TagReference;
				else if (name == "Undefined8") reflectionTypeCategory = ReflectionTypeCategory::Undefined;
				else if (name == "Undefined16") reflectionTypeCategory = ReflectionTypeCategory::Undefined;
				else if (name == "Undefined32") reflectionTypeCategory = ReflectionTypeCategory::Undefined;
				else if (name == "Undefined64") reflectionTypeCategory = ReflectionTypeCategory::Undefined;
				else assert(!"Unsupported class type");
			}

			rFieldData.m_reflectionTypeCategory = reflectionTypeCategory;
			if (reflectionTypeCategory == ReflectionTypeCategory::Undefined)
			{
				PrimitiveType primitiveType;
				if (name == "Undefined8") primitiveType = PrimitiveType::Undefined8;
				else if (name == "Undefined16") primitiveType = PrimitiveType::Undefined16;
				else if (name == "Undefined32") primitiveType = PrimitiveType::Undefined32;
				else if (name == "Undefined64") primitiveType = PrimitiveType::Undefined64;
				else assert(!"Unsupported primitive type");

				rFieldData.m_primitiveType = primitiveType;
				rFieldData.m_pFieldType = GetPrimitiveReflectionType(primitiveType);
			}
			else
			{
				ReflectionTypeContainer* pType = CreateReflectedType(Context, &fieldQualifiedType, *pCXXRecord);
				assert(pType != nullptr);
				rFieldData.m_pFieldType = pType;
			}
		}
		else if (reflectionQualifiedType->isScalarType())
		{
			clang::QualType scalarQualifiedType = reflectionQualifiedType->getCanonicalTypeInternal();
			const std::string scalarQualifiedTypeName = QualType::getAsString(scalarQualifiedType.split(), printingPolicy);

			rFieldData.m_reflectionTypeCategory = ReflectionTypeCategory::Primitive;
			switch (reflectionQualifiedType->getScalarTypeKind())
			{
			case clang::Type::ScalarTypeKind::STK_Bool:
				rFieldData.m_primitiveType = PrimitiveType::Boolean32;
				break;
			case clang::Type::ScalarTypeKind::STK_Integral:
			{
				clang::QualType integralCanonicalType = scalarQualifiedType;
				const bool isEnum = reflectionQualifiedType->isEnumeralType();
				if (isEnum)
				{
					TagDecl* pTagDecl = integralCanonicalType->getAsTagDecl();
					EnumDecl* pEnumDecl = static_cast<EnumDecl*>(pTagDecl); // this is nasty!
					assert(pEnumDecl != nullptr);
					integralCanonicalType = pEnumDecl->getIntegerType()->getCanonicalTypeInternal();
				}
				const std::string integralTypeName = QualType::getAsString(integralCanonicalType.split(), printingPolicy);

				if (integralCanonicalType->isSignedIntegerType())
				{
					if (integralTypeName == "char") rFieldData.m_primitiveType = PrimitiveType::Int8;
					else if (integralTypeName == "signed char") rFieldData.m_primitiveType = PrimitiveType::Int8;
					else if (integralTypeName == "short") rFieldData.m_primitiveType = PrimitiveType::Int16;
					else if (integralTypeName == "int") rFieldData.m_primitiveType = PrimitiveType::Int32;
					else if (integralTypeName == "long") rFieldData.m_primitiveType = PrimitiveType::Int32;
					else if (integralTypeName == "long long") rFieldData.m_primitiveType = PrimitiveType::Int64;
					else assert(!"Unsupported signed integral type");
				}
				else if (integralCanonicalType->isUnsignedIntegerType())
				{
					if (integralTypeName == "unsigned char") rFieldData.m_primitiveType = PrimitiveType::UInt8;
					else if (integralTypeName == "unsigned short") rFieldData.m_primitiveType = PrimitiveType::UInt16;
					else if (integralTypeName == "unsigned int") rFieldData.m_primitiveType = PrimitiveType::UInt32;
					else if (integralTypeName == "unsigned long long") rFieldData.m_primitiveType = PrimitiveType::UInt64;
					else assert(!"Unsupported signed integral type");
				}
				else assert(!"Unsupported integral type");

				if (isEnum)
				{
					switch (rFieldData.m_primitiveType)
					{
					case PrimitiveType::Int8:
					case PrimitiveType::UInt8:
						rFieldData.m_primitiveType = PrimitiveType::Enum8;
						break;
					case PrimitiveType::Int16:
					case PrimitiveType::UInt16:
						rFieldData.m_primitiveType = PrimitiveType::Enum16;
						break;
					case PrimitiveType::Int32:
					case PrimitiveType::UInt32:
						rFieldData.m_primitiveType = PrimitiveType::Enum32;
						break;
					case PrimitiveType::Int64:
					case PrimitiveType::UInt64:
						rFieldData.m_primitiveType = PrimitiveType::Enum64;
						break;
					case PrimitiveType::Enum8:
					case PrimitiveType::Enum16:
					case PrimitiveType::Enum32:
					case PrimitiveType::Enum64:
						break;
					default:
						assert(!"Unsupported enum integral interpretation");
					}
				}

			}
			break;
			case clang::Type::ScalarTypeKind::STK_Floating:
			{
				const std::string typeName = QualType::getAsString(scalarQualifiedType.split(), printingPolicy);
				if (typeName == "float") rFieldData.m_primitiveType = PrimitiveType::Float;
				else if (typeName == "double") rFieldData.m_primitiveType = PrimitiveType::Double;
				else assert(!"Unsupported floating point type");
			}
			break;
			case clang::Type::ScalarTypeKind::STK_CPointer:
			case clang::Type::ScalarTypeKind::STK_BlockPointer:
			case clang::Type::ScalarTypeKind::STK_ObjCObjectPointer:
			case clang::Type::ScalarTypeKind::STK_MemberPointer:
			case clang::Type::ScalarTypeKind::STK_IntegralComplex:
			case clang::Type::ScalarTypeKind::STK_FloatingComplex:
			case clang::Type::ScalarTypeKind::STK_FixedPoint:
				assert(!"UNSUPPORTED SCALAR TYPE");
				break;
			}

			assert(rFieldData.m_primitiveType != PrimitiveType::NonPrimitive);
			rFieldData.m_pFieldType = GetPrimitiveReflectionType(rFieldData.m_primitiveType);
		}
		else assert(!"UNSUPPORTED TYPE");

		assert(rFieldData.m_pFieldType != nullptr);
	}

	if (createdNewReflectionContainer)
	{
		ReflectedTypesData.emplace_back(pReflectionTypeContainer);
	}

	return &rReflectionTypeContainer;
}

void FormatReflectedTypeToFunction(const ReflectionTypeContainer& rType)
{
	if (rType.m_isPrimitive)
	{
		// skip internal types
		return;
	}

	stringstream << "template<>" << std::endl;

	//if (!rType.m_isTypeTemplate)
	{
		stringstream << "inline const ReflectionType& GetReflectionType<" << rType.m_qualifiedTypeName << ">()" << std::endl;
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
	stringstream << "{" << std::endl;
	stringstream << "\t" << "static ReflectionType reflectionData = " << std::endl;
	stringstream << "\t{" << std::endl;

	stringstream << "\t\t\"" << rType.m_typeName << "\", \"" << rType.m_typeNiceName << "\", " << std::endl;
	stringstream << std::uppercase;
	stringstream << "\t\t0x" << std::hex << rType.m_size << "u," << std::endl;
	stringstream << std::nouppercase;
	stringstream << "\t\t" << std::dec << rType.m_fieldsData.size() << "ui32," << std::endl;
	stringstream << "\t\t" << "{" << std::endl;
	for (const ReflectionFieldContainer* pField : rType.m_fieldsData)
	{
		const ReflectionFieldContainer& rField = *pField;
		const ReflectionTypeContainer& rType = *rField.m_pFieldType;
		assert(&rField);
		assert(&rType);

		const char* pPrimitiveTypeStr = rType.m_isPrimitive ? rField.m_pFieldType->m_qualifiedTypeName.c_str() : "NonPrimitive";
		const char* pReflectionTypeCategoryStr = ReflectionTypeCategoryToString(rField.m_reflectionTypeCategory);

		stringstream << "\t\t\t{ \"" << rField.m_fieldName << "\", \"" << rField.m_fieldNiceName << "\", ";
		{
			switch (rField.m_reflectionTypeCategory)
			{
			case ReflectionTypeCategory::TagBlock:
				stringstream << "ReflectionTagBlockInfo";
				break;
			case ReflectionTypeCategory::Structure:
				stringstream << "ReflectionStructureInfo";
				break;
			default:
				stringstream << "ReflectionTypeInfo";
				break;
			}
			stringstream << "{ " << "ReflectionTypeCategory::" << pReflectionTypeCategoryStr;
			stringstream << ", PrimitiveType::" << pPrimitiveTypeStr;
			stringstream << ", \"" << rType.m_qualifiedTypeName << "\"";
			switch (rField.m_reflectionTypeCategory)
			{
			case ReflectionTypeCategory::TagBlock:
				//#TODO: Print a Visual Studio warning for tab blocks without their types specified
				if (!rField.m_pFieldType->m_pTemplateTypes.empty())
				{
					//#TODO: Print a Visual Studio warning for tab blocks with too many types specified. The first only will be used
					stringstream << ", &GetReflectionType<" << rField.m_pFieldType->m_pTemplateTypes[0]->m_qualifiedTypeName << ">()";
				}
				else stringstream << ", nullptr";
				break;
			case ReflectionTypeCategory::Structure:
				stringstream << ", &GetReflectionType<" << rField.m_pFieldType->m_qualifiedTypeName << ">()";
				break;
			}
			stringstream << " }";
		}
		stringstream << std::uppercase;
		stringstream << ", 0x" << std::hex << rField.m_offset << "ui32";
		stringstream << ", 0x" << std::hex << rField.m_size << "ui16";
		stringstream << std::nouppercase;
		stringstream << ", " << std::dec << rField.m_arraySize << "ui32";
		stringstream << ", " << (rField.m_isHiddenByDefault ? "true" : "false");
		stringstream << " }," << std::endl;
	}
	stringstream << "\t\t\t{ }" << std::endl;

	stringstream << "\t\t" << "}" << std::endl;
	stringstream << "\t" << "};" << std::endl << std::endl;
	stringstream << "\treturn reflectionData;" << std::endl;

	stringstream << "}" << std::endl << std::endl;
}

class FindNamedClassVisitor
	: public RecursiveASTVisitor<FindNamedClassVisitor> {
public:
	explicit FindNamedClassVisitor(ASTContext* Context)
		: Context(Context) {}

	bool VisitCXXRecordDecl(CXXRecordDecl* Declaration) {

		CreateReflectedType(Context, nullptr, *Declaration);

		return true;
	}

private:
	ASTContext* Context;
};

class FindNamedClassConsumer : public clang::ASTConsumer {
public:
	explicit FindNamedClassConsumer(ASTContext* Context)
		: Visitor(Context) {}

	virtual void HandleTranslationUnit(clang::ASTContext& Context) {
		Visitor.TraverseDecl(Context.getTranslationUnitDecl());
	}
private:
	FindNamedClassVisitor Visitor;
};

class FindNamedClassAction : public clang::ASTFrontendAction {
public:
	virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
		clang::CompilerInstance& Compiler, llvm::StringRef InFile) {
		return std::unique_ptr<clang::ASTConsumer>(
			new FindNamedClassConsumer(&Compiler.getASTContext()));
	}
};

int main(int argc, const char* argv[])
{
	if (argc != 4)
	{
		printf("Incorrect number of arguments. Expected 3");
		return 1;
	}

	const char* szReflectionSourceFile = argv[1];
	const char* szOutputHeader = argv[2];
	const char* szOutputSource = argv[3];

	printf("Reflection Source File:   '%s'\n", szReflectionSourceFile);
	printf("Reflection Output Header: '%s'\n", szOutputHeader);
	printf("Reflection Output Source: '%s'\n", szOutputSource);

	const char* argumentsArray[] = {
			argv[0],
			szReflectionSourceFile
	};
	int numArgs = _countof(argumentsArray);

	stringstream << "#pragma once" << std::endl << std::endl;

	CommonOptionsParser OptionsParser(numArgs, argumentsArray, MantleToolCategory);
	ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

	FindNamedClassAction findNamedClassAction;

	//// #TODO: Add custom LLVM code here and pass to newFrontendActionFactory
	//// see https://clang.llvm.org/docs/LibASTMatchersTutorial.html

	int llvmResult = Tool.run(newFrontendActionFactory<FindNamedClassAction>().get());

	for (ReflectionTypeContainer* pType : ReflectedTypesData)
	{
		ReflectionTypeContainer& rType = *pType;
		InitTypeSizeAndOffsets(rType);
		CreateNiceNames(rType);
		FormatReflectedTypeToFunction(rType);
	}

	{
		stringstream << std::endl;
		stringstream << "inline const ReflectionType* GetTagReflectionDataByTagGroup(uint32_t tagGroup)" << std::endl;
		stringstream << "{" << std::endl;
		stringstream << "\tswitch (tagGroup)" << std::endl;
		stringstream << "\t{" << std::endl;
		for (ReflectionTypeContainer* pType : ReflectedTypesData)
		{
			ReflectionTypeContainer& rType = *pType;
			if (!rType.m_tagGroup.empty())
			{
				const uint32_t& rawTagGroup = *reinterpret_cast<const uint32_t*>(rType.m_tagGroup.data());
				uint64_t swappedTagGroupWithPadding = bswap(rawTagGroup);
				const char* pTagGroupSwapped = reinterpret_cast<const char*>(&swappedTagGroupWithPadding);

				stringstream << "\tcase '" << rType.m_tagGroup << "':" << std::endl;
				if (rawTagGroup != swappedTagGroupWithPadding)
				{
					stringstream << "\tcase '" << pTagGroupSwapped << "':" << std::endl;
				}
				stringstream << "\t\treturn &GetReflectionType<" << rType.m_qualifiedTypeName << ">();" << std::endl;
			}
		}
		stringstream << "\t}" << std::endl;
		stringstream << "\treturn nullptr;" << std::endl;
		stringstream << "}" << std::endl;
		stringstream << std::endl;
	}

	if (false) // debug print
		for (ReflectionTypeContainer* pType : ReflectedTypesData)
		{
			ReflectionTypeContainer& rType = *pType;

			if (rType.m_isPrimitive) continue;

			if (rType.m_fieldsData.size() > 0)
			{
				printf("struct %s\n{\n", rType.m_qualifiedTypeName.c_str());
				for (ReflectionFieldContainer* pField : rType.m_fieldsData)
				{
					ReflectionFieldContainer& rField = *pField;

					if (rField.m_arraySize)
					{
						printf(
							"\t%s %s[%u]; // size:0x%X offset:0x%X\n",
							rField.m_pFieldType->m_qualifiedTypeName.c_str(),
							rField.m_fieldName.c_str(),
							static_cast<uint32_t>(rField.m_arraySize),
							static_cast<uint32_t>(rField.m_size),
							static_cast<uint32_t>(rField.m_offset));
					}
					else
					{
						printf(
							"\t%s %s; // size:0x%X offset:0x%X\n",
							rField.m_pFieldType->m_qualifiedTypeName.c_str(),
							rField.m_fieldName.c_str(),
							static_cast<uint32_t>(rField.m_size),
							static_cast<uint32_t>(rField.m_offset));
					}
				}

				printf("};\n");
			}
			else
			{
				printf("struct %s { };\n", rType.m_qualifiedTypeName.c_str());
			}
		}

	std::string str = stringstream.str();
	{
		FILE* pReflectionHeader = fopen(szOutputHeader, "w");
		assert(pReflectionHeader != nullptr);
		fwrite(str.c_str(), 1, str.length(), pReflectionHeader);
		fflush(pReflectionHeader);
		fclose(pReflectionHeader);
	}

	{
		FILE* pReflectionSource = fopen(szOutputSource, "w");
		assert(pReflectionSource != nullptr);
		fflush(pReflectionSource);
		fclose(pReflectionSource);
	}

	for (ReflectionTypeContainer* pType : ReflectedTypesData)
	{
		delete pType;
	}

	return llvmResult;
}


