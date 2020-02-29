#include "mantlereflect-private-pch.h"

#ifdef _DEBUG_FAST /* change build configuration for full debug */
#pragma optimize("", off)
#endif



using namespace llvm;
using namespace clang;
using namespace clang::tooling;

// llvm/clang things
static llvm::cl::OptionCategory MantleToolCategory("mantle options");
static LangOptions languageOptions;
static PrintingPolicy printingPolicy = languageOptions;


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

void CreateNiceNames(c_reflection_type_container& rType)
{
	rType.type_nice_name = rType.type_name;
	rType.type_nice_name = FormatNiceNameAndIsHidden(ReflectionTypeCategory::Structure, rType.type_nice_name.data());
	for (c_reflection_field_container* pField : rType.fields)
	{
		c_reflection_field_container& rField = *pField;

		rField.field_nice_name = rField.field_name;
		rField.is_hidden_by_default = false;
		rField.field_nice_name = FormatNiceNameAndIsHidden(rField.reflection_type_category, rField.field_nice_name.data(), &rField.is_hidden_by_default);
	}
}

uint32_t InitTypeSizeAndOffsets(c_reflection_type_container& rType)
{
	if (rType.is_size_initialized)
	{
		return rType.data_size;
	}

	uint32_t currentOffset = 0;
	for (c_reflection_field_container* pField : rType.fields)
	{
		c_reflection_field_container& rField = *pField;
		uint64_t fieldSize = InitTypeSizeAndOffsets(*rField.field_type);
		uint64_t dataSize = fieldSize * __max(1ull, rField.array_size);
		rField.data_size = fieldSize;
		rField.offset = currentOffset;
		currentOffset += static_cast<uint32_t>(dataSize);
	}
	rType.data_size = currentOffset;

	return rType.data_size;
}

std::vector<c_reflection_type_container*> ReflectedTypesData;

c_reflection_type_container* GetPrimitiveReflectionType(PrimitiveType primitiveType)
{
	static c_reflection_type_container* pInt8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int8", sizeof(int8_t)));
	static c_reflection_type_container* pInt16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int16", sizeof(int16_t)));
	static c_reflection_type_container* pInt32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int32", sizeof(int32_t)));
	static c_reflection_type_container* pInt64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int64", sizeof(int64_t)));
	static c_reflection_type_container* pUInt8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt8", sizeof(uint8_t)));
	static c_reflection_type_container* pUInt16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt16", sizeof(uint16_t)));
	static c_reflection_type_container* pUInt32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt32", sizeof(uint32_t)));
	static c_reflection_type_container* pUInt64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt64", sizeof(uint64_t)));
	static c_reflection_type_container* pBoolean8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean8", sizeof(uint8_t)));
	static c_reflection_type_container* pBoolean16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean16", sizeof(uint16_t)));
	static c_reflection_type_container* pBoolean32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean32", sizeof(uint32_t)));
	static c_reflection_type_container* pBoolean64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean64", sizeof(uint64_t)));
	static c_reflection_type_container* pBitField8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField8", sizeof(uint8_t)));
	static c_reflection_type_container* pBitField16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField16", sizeof(uint16_t)));
	static c_reflection_type_container* pBitField32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField32", sizeof(uint32_t)));
	static c_reflection_type_container* pBitField64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField64", sizeof(uint64_t)));
	static c_reflection_type_container* pBitFlag8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag8", sizeof(uint8_t)));
	static c_reflection_type_container* pBitFlag16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag16", sizeof(uint16_t)));
	static c_reflection_type_container* pBitFlag32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag32", sizeof(uint32_t)));
	static c_reflection_type_container* pBitFlag64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag64", sizeof(uint64_t)));
	static c_reflection_type_container* pFloatReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Float", sizeof(float)));
	static c_reflection_type_container* pDoubleReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Double", sizeof(double)));
	static c_reflection_type_container* pEnum8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum8", sizeof(uint8_t)));
	static c_reflection_type_container* pEnum16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum16", sizeof(uint16_t)));
	static c_reflection_type_container* pEnum32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum32", sizeof(uint32_t)));
	static c_reflection_type_container* pEnum64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum64", sizeof(uint64_t)));
	static c_reflection_type_container* pUndefined8ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined8", sizeof(uint8_t)));
	static c_reflection_type_container* pUndefined16ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined16", sizeof(uint16_t)));
	static c_reflection_type_container* pUndefined32ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined32", sizeof(uint32_t)));
	static c_reflection_type_container* pUndefined64ReflectionType = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined64", sizeof(uint64_t)));

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

c_reflection_type_container* CreateReflectedType(ASTContext* Context, const clang::QualType* recordQualifiedType, const clang::RecordDecl& rRecordDeclaration, bool isPrimitive = false)
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

	c_reflection_type_container* pExistingReflectionTypeContainer = nullptr;
	{ // handle existing records
		for (c_reflection_type_container* rReflectionTypeContainer : ReflectedTypesData)
		{
			if (rReflectionTypeContainer->clang_record_declaration == &rRecordDeclaration || rReflectionTypeContainer->qualified_type_name == qualifiedDeclarationName)
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
		else if (!pExistingReflectionTypeContainer->fields.empty())
		{
			return pExistingReflectionTypeContainer; // we already have data for this
		}
	}

	// if existing reflection container exists and we're updating it, replace all data

	bool createdNewReflectionContainer = pExistingReflectionTypeContainer == nullptr;
	c_reflection_type_container* pReflectionTypeContainer = pExistingReflectionTypeContainer;
	if (createdNewReflectionContainer)
	{
		pReflectionTypeContainer = new c_reflection_type_container();
	}
	c_reflection_type_container& rReflectionTypeContainer = *pReflectionTypeContainer;

	assert(rReflectionTypeContainer.fields.empty());

	rReflectionTypeContainer.type_name = declarationName;
	rReflectionTypeContainer.qualified_type_name = qualifiedDeclarationName;
	rReflectionTypeContainer.clang_record_declaration = &rRecordDeclaration;
	rReflectionTypeContainer.is_primitive = isPrimitive;

	if (pClassTemplateSpecializationDecl)
	{
		rReflectionTypeContainer.is_template = true;

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
				c_reflection_type_container* pTemplateType = CreateReflectedType(Context, &qualifiedType, *pDecl);
				assert(pTemplateType != nullptr);
				rReflectionTypeContainer.template_types.push_back(pTemplateType);
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

	rReflectionTypeContainer.raw_tag_group = tag_group_str;

	if (disableReflection)
	{
		return &rReflectionTypeContainer;
	}

	for (FieldDecl* field : fields)
	{
		c_reflection_field_container& rFieldData = *rReflectionTypeContainer.fields.emplace_back(new c_reflection_field_container());

		const clang::QualType fieldQualifiedType = field->getType();
		const clang::Type* fieldType = fieldQualifiedType.getTypePtr();

		const std::string fieldQualifiedTypeName = QualType::getAsString(fieldQualifiedType.split(), printingPolicy);
		const std::string fieldQualifiedName = field->getQualifiedNameAsString();
		const std::string fieldName = field->getNameAsString();

		rFieldData.field_name = fieldName;

		const clang::Type* const reflectionBaseType = fieldType;
		const clang::QualType reflectionQualifiedBaseType = reflectionBaseType->getCanonicalTypeInternal();
		clang::QualType reflectionQualifiedType = reflectionQualifiedBaseType;

		if (reflectionQualifiedType->isArrayType())
		{
			const ConstantArrayType* pConstantArrayType = Context->getAsConstantArrayType(reflectionQualifiedType);
			if (pConstantArrayType)
			{
				llvm::APInt arraySizeRaw = pConstantArrayType->getSize();
				rFieldData.array_size = *arraySizeRaw.getRawData();
				assert(rFieldData.array_size > 0);

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

			rFieldData.reflection_type_category = reflectionTypeCategory;
			if (reflectionTypeCategory == ReflectionTypeCategory::Undefined)
			{
				PrimitiveType primitiveType;
				if (name == "Undefined8") primitiveType = PrimitiveType::Undefined8;
				else if (name == "Undefined16") primitiveType = PrimitiveType::Undefined16;
				else if (name == "Undefined32") primitiveType = PrimitiveType::Undefined32;
				else if (name == "Undefined64") primitiveType = PrimitiveType::Undefined64;
				else assert(!"Unsupported primitive type");

				rFieldData.primitive_type = primitiveType;
				rFieldData.field_type = GetPrimitiveReflectionType(primitiveType);
			}
			else
			{
				c_reflection_type_container* pType = CreateReflectedType(Context, &fieldQualifiedType, *pCXXRecord);
				assert(pType != nullptr);
				rFieldData.field_type = pType;
			}
		}
		else if (reflectionQualifiedType->isScalarType())
		{
			clang::QualType scalarQualifiedType = reflectionQualifiedType->getCanonicalTypeInternal();
			const std::string scalarQualifiedTypeName = QualType::getAsString(scalarQualifiedType.split(), printingPolicy);

			rFieldData.reflection_type_category = ReflectionTypeCategory::Primitive;
			switch (reflectionQualifiedType->getScalarTypeKind())
			{
			case clang::Type::ScalarTypeKind::STK_Bool:
				rFieldData.primitive_type = PrimitiveType::Boolean32;
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
					if (integralTypeName == "char") rFieldData.primitive_type = PrimitiveType::Int8;
					else if (integralTypeName == "signed char") rFieldData.primitive_type = PrimitiveType::Int8;
					else if (integralTypeName == "short") rFieldData.primitive_type = PrimitiveType::Int16;
					else if (integralTypeName == "int") rFieldData.primitive_type = PrimitiveType::Int32;
					else if (integralTypeName == "long") rFieldData.primitive_type = PrimitiveType::Int32;
					else if (integralTypeName == "long long") rFieldData.primitive_type = PrimitiveType::Int64;
					else assert(!"Unsupported signed integral type");
				}
				else if (integralCanonicalType->isUnsignedIntegerType())
				{
					if (integralTypeName == "unsigned char") rFieldData.primitive_type = PrimitiveType::UInt8;
					else if (integralTypeName == "unsigned short") rFieldData.primitive_type = PrimitiveType::UInt16;
					else if (integralTypeName == "unsigned int") rFieldData.primitive_type = PrimitiveType::UInt32;
					else if (integralTypeName == "unsigned long long") rFieldData.primitive_type = PrimitiveType::UInt64;
					else assert(!"Unsupported signed integral type");
				}
				else assert(!"Unsupported integral type");

				if (isEnum)
				{
					switch (rFieldData.primitive_type)
					{
					case PrimitiveType::Int8:
					case PrimitiveType::UInt8:
						rFieldData.primitive_type = PrimitiveType::Enum8;
						break;
					case PrimitiveType::Int16:
					case PrimitiveType::UInt16:
						rFieldData.primitive_type = PrimitiveType::Enum16;
						break;
					case PrimitiveType::Int32:
					case PrimitiveType::UInt32:
						rFieldData.primitive_type = PrimitiveType::Enum32;
						break;
					case PrimitiveType::Int64:
					case PrimitiveType::UInt64:
						rFieldData.primitive_type = PrimitiveType::Enum64;
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
				if (typeName == "float") rFieldData.primitive_type = PrimitiveType::Float;
				else if (typeName == "double") rFieldData.primitive_type = PrimitiveType::Double;
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

			assert(rFieldData.primitive_type != PrimitiveType::NonPrimitive);
			rFieldData.field_type = GetPrimitiveReflectionType(rFieldData.primitive_type);
		}
		else assert(!"UNSUPPORTED TYPE");

		assert(rFieldData.field_type != nullptr);
	}

	if (createdNewReflectionContainer)
	{
		ReflectedTypesData.emplace_back(pReflectionTypeContainer);
	}

	return &rReflectionTypeContainer;
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

int main(int argc, const char** argv)
{
	if (argc < 4)
	{
		printf("Incorrect number of arguments. Expected 3");
		return 1;
	}

	const wchar_t* command_line = GetCommandLineW();
	int argc_widechar = 0;
	wchar_t** argv_widechar = CommandLineToArgvW(command_line, &argc);

	const char* reflection_source_file = argv[1];
	const wchar_t* reflection_output_header = argv_widechar[2];
	const wchar_t* reflection_output_source = argv_widechar[3];
	const wchar_t* compile_time_gui_header = argc > 4 ? argv_widechar[4] : nullptr;
	const wchar_t* compile_time_gui_source = argc > 5 ? argv_widechar[5] : nullptr;
	const wchar_t* compile_time_conversion_header = argc > 6 ? argv_widechar[6] : nullptr;
	const wchar_t* compile_time_conversion_source = argc > 7 ? argv_widechar[7] : nullptr;

	wprintf(L"Reflection Source File:   '%S'\n", reflection_source_file);
	wprintf(L"Reflection Output Header: '%s'\n", reflection_output_header);
	wprintf(L"Reflection Output Source: '%s'\n", reflection_output_source);
	if (compile_time_gui_header) wprintf(L"Compile Time GUI Output Header: '%s'\n", compile_time_gui_header);
	if (compile_time_gui_source) wprintf(L"Compile Time GUI Output Source: '%s'\n", compile_time_gui_source);
	if (compile_time_conversion_header) wprintf(L"Compile Time Conversion Output Header: '%s'\n", compile_time_conversion_header);
	if (compile_time_conversion_source) wprintf(L"Compile Time Conversion Output Source: '%s'\n", compile_time_conversion_source);

	const char* argumentsArray[] = {
			argv[0],
			reflection_source_file
	};
	int num_args = _countof(argumentsArray);

	CommonOptionsParser OptionsParser(num_args, argumentsArray, MantleToolCategory);
	ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

	FindNamedClassAction findNamedClassAction;

	//// #TODO: Add custom LLVM code here and pass to newFrontendActionFactory
	//// see https://clang.llvm.org/docs/LibASTMatchersTutorial.html

	int llvmResult = Tool.run(newFrontendActionFactory<FindNamedClassAction>().get());

	for (c_reflection_type_container* pType : ReflectedTypesData)
	{
		c_reflection_type_container& rType = *pType;
		InitTypeSizeAndOffsets(rType);
		CreateNiceNames(rType);
	}

	tbb::parallel_invoke(
		[=] 
		{
			c_mantle_runtime_reflection_generator runtime_reflection_generator = { reflection_output_header, reflection_output_source, ReflectedTypesData };
			runtime_reflection_generator.run();
			runtime_reflection_generator.write_output();
		}, 
		[=]
		{
			if (compile_time_conversion_header && compile_time_conversion_source)
			{
				c_mantle_compile_time_conversion_generator mantle_compile_time_conversion_generator = { compile_time_conversion_header, compile_time_conversion_source, ReflectedTypesData };
				mantle_compile_time_conversion_generator.run();
				mantle_compile_time_conversion_generator.write_output();
			}
		}, 
		[=]
		{
			if (compile_time_gui_header && compile_time_gui_source)
			{
				c_mantle_compile_time_gui_generator mantle_compile_time_gui_generator = { compile_time_gui_header, compile_time_gui_source, ReflectedTypesData };
				mantle_compile_time_gui_generator.run();
				mantle_compile_time_gui_generator.write_output();
			}
		});

	for (c_reflection_type_container* pType : ReflectedTypesData)
	{
		delete pType;
	}

	return llvmResult;
}


