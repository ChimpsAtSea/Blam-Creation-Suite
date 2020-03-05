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


const char* FormatNiceNameAndIsHidden(e_reflection_type_category reflectionTypeCategory, char* pString, bool* isHiddenByDefault = nullptr)
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

		if (reflectionTypeCategory == e_reflection_type_category::TagBlock)
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

		if (reflectionTypeCategory == e_reflection_type_category::TagReference)
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

		if (reflectionTypeCategory == e_reflection_type_category::DataReference)
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
	rType.type_nice_name = FormatNiceNameAndIsHidden(e_reflection_type_category::Structure, rType.type_nice_name.data());
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

c_reflection_type_container* GetPrimitives_reflection_type(e_primitive_type primitiveType)
{
	static c_reflection_type_container* pInt8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int8", "int8_t", sizeof(int8_t)));
	static c_reflection_type_container* pInt16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int16", "int16_t", sizeof(int16_t)));
	static c_reflection_type_container* pInt32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int32", "int32_t", sizeof(int32_t)));
	static c_reflection_type_container* pInt64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int64", "int64_t", sizeof(int64_t)));
	static c_reflection_type_container* pUInt8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* pUInt16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* pUInt32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* pUInt64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* pBoolean8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* pBoolean16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* pBoolean32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* pBoolean64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* pBitField8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* pBitField16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* pBitField32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* pBitField64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* pBitFlag8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* pBitFlag16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* pBitFlag32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* pBitFlag64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* pFloats_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Float", "float", sizeof(float)));
	static c_reflection_type_container* pDoubles_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Double", "double", sizeof(double)));
	static c_reflection_type_container* pEnum8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* pEnum16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* pEnum32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* pEnum64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* pUndefined8s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined8", "Undefined8", sizeof(uint8_t)));
	static c_reflection_type_container* pUndefined16s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined16", "Undefined16", sizeof(uint16_t)));
	static c_reflection_type_container* pUndefined32s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined32", "Undefined32", sizeof(uint32_t)));
	static c_reflection_type_container* pUndefined64s_reflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined64", "Undefined64", sizeof(uint64_t)));
	static c_reflection_type_container* pCharactereflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Character", "char", sizeof(char)));
	static c_reflection_type_container* pWideCharactereflection_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("WideCharacter", "wchar_t", sizeof(wchar_t)));

	switch (primitiveType)
	{
	case e_primitive_type::Int8:			return pInt8s_reflection_type;
	case e_primitive_type::Int16:			return pInt16s_reflection_type;
	case e_primitive_type::Int32:			return pInt32s_reflection_type;
	case e_primitive_type::Int64:			return pInt64s_reflection_type;
	case e_primitive_type::UInt8:			return pUInt8s_reflection_type;
	case e_primitive_type::UInt16:			return pUInt16s_reflection_type;
	case e_primitive_type::UInt32:			return pUInt32s_reflection_type;
	case e_primitive_type::UInt64:			return pUInt64s_reflection_type;
	case e_primitive_type::Boolean8:		return pBoolean8s_reflection_type;
	case e_primitive_type::Boolean16:		return pBoolean16s_reflection_type;
	case e_primitive_type::Boolean32:		return pBoolean32s_reflection_type;
	case e_primitive_type::Boolean64:		return pBoolean64s_reflection_type;
	case e_primitive_type::BitFlag8:		return pBitFlag8s_reflection_type;
	case e_primitive_type::BitFlag16:		return pBitFlag16s_reflection_type;
	case e_primitive_type::BitFlag32:		return pBitFlag32s_reflection_type;
	case e_primitive_type::BitFlag64:		return pBitFlag64s_reflection_type;
	case e_primitive_type::BitField8:		return pBitField8s_reflection_type;
	case e_primitive_type::BitField16:		return pBitField16s_reflection_type;
	case e_primitive_type::BitField32:		return pBitField32s_reflection_type;
	case e_primitive_type::BitField64:		return pBitField64s_reflection_type;
	case e_primitive_type::Float:			return pFloats_reflection_type;
	case e_primitive_type::Double:			return pDoubles_reflection_type;
	case e_primitive_type::Enum8:			return pEnum8s_reflection_type;
	case e_primitive_type::Enum16:			return pEnum16s_reflection_type;
	case e_primitive_type::Enum32:			return pEnum32s_reflection_type;
	case e_primitive_type::Enum64:			return pEnum64s_reflection_type;
	case e_primitive_type::Undefined8:		return pUndefined8s_reflection_type;
	case e_primitive_type::Undefined16:	return pUndefined16s_reflection_type;
	case e_primitive_type::Undefined32:	return pUndefined32s_reflection_type;
	case e_primitive_type::Undefined64:	return pUndefined64s_reflection_type;
	case e_primitive_type::Character:		return pCharactereflection_type;
	case e_primitive_type::WideCharacter:	return pWideCharactereflection_type;
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

	c_reflection_type_container* pExistings_reflection_typeContainer = nullptr;
	{ // handle existing records
		for (c_reflection_type_container* reflection_typeContainer : ReflectedTypesData)
		{
			if (reflection_typeContainer->clang_record_declaration == &rRecordDeclaration || reflection_typeContainer->qualified_type_name == qualifiedDeclarationName)
			{
				pExistings_reflection_typeContainer = reflection_typeContainer;

			}
		}
	}
	if (pExistings_reflection_typeContainer)
	{
		if (numFields == 0)
		{
			return pExistings_reflection_typeContainer; // we already have data for this
		}
		else if (!pExistings_reflection_typeContainer->fields.empty())
		{
			return pExistings_reflection_typeContainer; // we already have data for this
		}
	}

	// if existing reflection container exists and we're updating it, replace all data

	bool createdNewReflectionContainer = pExistings_reflection_typeContainer == nullptr;
	c_reflection_type_container* ps_reflection_typeContainer = pExistings_reflection_typeContainer;
	if (createdNewReflectionContainer)
	{
		ps_reflection_typeContainer = new c_reflection_type_container();
	}
	c_reflection_type_container& reflection_type_container = *ps_reflection_typeContainer;

	assert(reflection_type_container.fields.empty());

	reflection_type_container.type_name = declarationName;
	reflection_type_container.qualified_type_name = qualifiedDeclarationName;
	reflection_type_container.clang_record_declaration = &rRecordDeclaration;
	reflection_type_container.is_primitive = isPrimitive;

	if (pClassTemplateSpecializationDecl)
	{
		reflection_type_container.is_template = true;

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
				reflection_type_container.template_types.push_back(pTemplateType);
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

	reflection_type_container.raw_tag_group = tag_group_str;
	{
		const uint32_t& raw_tag_group = *reinterpret_cast<const uint32_t*>(reflection_type_container.raw_tag_group.data());
		uint64_t swapped_tag_group = bswap(raw_tag_group);
		const char* swapped_tag_group_str = reinterpret_cast<const char*>(&swapped_tag_group);
		reflection_type_container.tag_group = swapped_tag_group_str;
	}

	if (disableReflection)
	{
		return &reflection_type_container;
	}

	for (FieldDecl* field : fields)
	{
		c_reflection_field_container& rFieldData = *reflection_type_container.fields.emplace_back(new c_reflection_field_container());

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

			e_reflection_type_category reflectionTypeCategory;
			{
				if (name == "TagBlock") reflectionTypeCategory = e_reflection_type_category::TagBlock;
				else if (name == "s_tag_block_definition") reflectionTypeCategory = e_reflection_type_category::TagBlock;
				else if (name == "DataReference") reflectionTypeCategory = e_reflection_type_category::DataReference;
				else if (name == "string_id") reflectionTypeCategory = e_reflection_type_category::StringID;
				else if (name == "StringID") reflectionTypeCategory = e_reflection_type_category::StringID;
				//else if (name == "TagGroupName") reflectionTypeCategory = e_reflection_type_category::TagGroupName; 
				else if (name == "TagReference") reflectionTypeCategory = e_reflection_type_category::TagReference;
				else if (name == "Undefined8") reflectionTypeCategory = e_reflection_type_category::Primitive;
				else if (name == "Undefined16") reflectionTypeCategory = e_reflection_type_category::Primitive;
				else if (name == "Undefined32") reflectionTypeCategory = e_reflection_type_category::Primitive;
				else if (name == "Undefined64") reflectionTypeCategory = e_reflection_type_category::Primitive;
				else if (reflectionQualifiedType->isStructureType()) reflectionTypeCategory = e_reflection_type_category::Structure;
				else assert(!"Unsupported class type");
			}

			rFieldData.reflection_type_category = reflectionTypeCategory;
			if (reflectionTypeCategory == e_reflection_type_category::Primitive)
			{
				e_primitive_type primitiveType;
				if (name == "Undefined8") primitiveType = e_primitive_type::Undefined8;
				else if (name == "Undefined16") primitiveType = e_primitive_type::Undefined16;
				else if (name == "Undefined32") primitiveType = e_primitive_type::Undefined32;
				else if (name == "Undefined64") primitiveType = e_primitive_type::Undefined64;
				else assert(!"Unsupported primitive type");

				rFieldData.primitive_type = primitiveType;
				rFieldData.field_type = GetPrimitives_reflection_type(primitiveType);
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

			rFieldData.reflection_type_category = e_reflection_type_category::Primitive;
			switch (reflectionQualifiedType->getScalarTypeKind())
			{
			case clang::Type::ScalarTypeKind::STK_Bool:
				rFieldData.primitive_type = e_primitive_type::Boolean32;
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
					if (integralTypeName == "char") rFieldData.primitive_type = e_primitive_type::Character;
					else if (integralTypeName == "signed char") rFieldData.primitive_type = e_primitive_type::Int8;
					else if (integralTypeName == "short") rFieldData.primitive_type = e_primitive_type::Int16;
					else if (integralTypeName == "int") rFieldData.primitive_type = e_primitive_type::Int32;
					else if (integralTypeName == "long") rFieldData.primitive_type = e_primitive_type::Int32;
					else if (integralTypeName == "long long") rFieldData.primitive_type = e_primitive_type::Int64;
					else assert(!"Unsupported signed integral type");
				}
				else if (integralCanonicalType->isUnsignedIntegerType())
				{
					if (integralTypeName == "unsigned char") rFieldData.primitive_type = e_primitive_type::UInt8;
					else if (integralTypeName == "unsigned short") rFieldData.primitive_type = e_primitive_type::UInt16;
					else if (integralTypeName == "unsigned int") rFieldData.primitive_type = e_primitive_type::UInt32;
					else if (integralTypeName == "unsigned long long") rFieldData.primitive_type = e_primitive_type::UInt64;
					else assert(!"Unsupported signed integral type");
				}
				else assert(!"Unsupported integral type");

				if (isEnum)
				{
					switch (rFieldData.primitive_type)
					{
					case e_primitive_type::Int8:
					case e_primitive_type::UInt8:
						rFieldData.primitive_type = e_primitive_type::Enum8;
						break;
					case e_primitive_type::Int16:
					case e_primitive_type::UInt16:
						rFieldData.primitive_type = e_primitive_type::Enum16;
						break;
					case e_primitive_type::Int32:
					case e_primitive_type::UInt32:
						rFieldData.primitive_type = e_primitive_type::Enum32;
						break;
					case e_primitive_type::Int64:
					case e_primitive_type::UInt64:
						rFieldData.primitive_type = e_primitive_type::Enum64;
						break;
					case e_primitive_type::Enum8:
					case e_primitive_type::Enum16:
					case e_primitive_type::Enum32:
					case e_primitive_type::Enum64:
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
				if (typeName == "float") rFieldData.primitive_type = e_primitive_type::Float;
				else if (typeName == "double") rFieldData.primitive_type = e_primitive_type::Double;
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

			assert(rFieldData.primitive_type != e_primitive_type::NonPrimitive);
			rFieldData.field_type = GetPrimitives_reflection_type(rFieldData.primitive_type);
		}
		else assert(!"UNSUPPORTED TYPE");

		assert(rFieldData.field_type != nullptr);
	}

	if (createdNewReflectionContainer)
	{
		ReflectedTypesData.emplace_back(ps_reflection_typeContainer);
	}

	return &reflection_type_container;
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
	if (argc < 2)
	{
		printf("Incorrect number of arguments. Expected 3");
		return 1;
	}

	const wchar_t* command_line = GetCommandLineW();
	int argc_widechar = 0;
	wchar_t** argv_widechar = CommandLineToArgvW(command_line, &argc);


	std::string output_directory = argv[1];
	std::wstring output_directory_wide = argv_widechar[1];

	wprintf(L"Output Directory:   '%s'\n", output_directory_wide.c_str());

	std::string reflection_source_file = output_directory + "TagsReflectionObject.cpp";
	std::wstring reflection_output_header = output_directory_wide + L"ReflectionData.h";
	std::wstring reflection_output_source = output_directory_wide + L"ReflectionData.cpp";
	std::wstring tag_groups_header = output_directory_wide + L"TagGroups.h";
	std::wstring compile_time_gui_header = output_directory_wide + L"GeneratedGUI.h";
	std::wstring compile_time_gui_source = output_directory_wide + L"GeneratedGUI.cpp";
	std::wstring compile_time_conversion_header = output_directory_wide + L"GeneratedConversion.h";
	std::wstring compile_time_conversion_source = output_directory_wide + L"GeneratedConversion.cpp";
	std::wstring virtual_tag_interface_header = output_directory_wide + L"VirtualTagInterfaces.h";
	std::wstring virtual_tag_interface_source = output_directory_wide + L"VirtualTagInterfaces.cpp";

	wprintf(L"Reflection Source File:   '%S'\n", reflection_source_file.c_str());
	wprintf(L"Reflection Output Header: '%s'\n", reflection_output_header.c_str());
	wprintf(L"Reflection Output Source: '%s'\n", reflection_output_source.c_str());
	wprintf(L"Tag Groups Header: '%s'\n", tag_groups_header.c_str());
	wprintf(L"Compile Time GUI Output Header: '%s'\n", compile_time_gui_header.c_str());
	wprintf(L"Compile Time GUI Output Source: '%s'\n", compile_time_gui_source.c_str());
	wprintf(L"Compile Time Conversion Output Header: '%s'\n", compile_time_conversion_header.c_str());
	wprintf(L"Compile Time Conversion Output Source: '%s'\n", compile_time_conversion_source.c_str());
	wprintf(L"Virtual Tag Interface Output Header: '%s'\n", virtual_tag_interface_header.c_str());
	wprintf(L"Virtual Tag Interface Output Source: '%s'\n", virtual_tag_interface_source.c_str());

	const char* argumentsArray[] = {
			argv[0],
			reflection_source_file.c_str()
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
			c_mantle_runtime_reflection_generator tag_groups_generator = { reflection_output_header.c_str(), reflection_output_source.c_str(), ReflectedTypesData };
			tag_groups_generator.run();
			tag_groups_generator.write_output();
		},
			[=]
		{
			c_mantle_tag_groups_generator tag_groups_generator = { tag_groups_header.c_str(), ReflectedTypesData };
			tag_groups_generator.run();
			tag_groups_generator.write_output();
		},
			[=]
		{
			c_mantle_compile_time_conversion_generator mantle_compile_time_conversion_generator = { compile_time_conversion_header.c_str(), compile_time_conversion_source.c_str(), ReflectedTypesData };
			mantle_compile_time_conversion_generator.run();
			mantle_compile_time_conversion_generator.write_output();
		},
			[=]
		{
			c_mantle_compile_time_gui_generator mantle_compile_time_gui_generator = { compile_time_gui_header.c_str(), compile_time_gui_source.c_str(), ReflectedTypesData };
			mantle_compile_time_gui_generator.run();
			mantle_compile_time_gui_generator.write_output();
		},
			[=]
		{
			c_mantle_virtual_tag_interface_generator mantle_virtual_tag_interface_generator = { virtual_tag_interface_header.c_str(), virtual_tag_interface_source.c_str(), ReflectedTypesData };
			mantle_virtual_tag_interface_generator.run();
			mantle_virtual_tag_interface_generator.write_output();
		});

	for (c_reflection_type_container* pType : ReflectedTypesData)
	{
		delete pType;
	}

	return llvmResult;
}


