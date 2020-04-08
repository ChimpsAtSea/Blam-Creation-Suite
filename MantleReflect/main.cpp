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

e_primitive_type qualified_type_to_primitive_type(const clang::QualType& _qualifiedType)
{
	clang::QualType qualifiedType = _qualifiedType;

	e_primitive_type primitive_type = e_primitive_type::NonPrimitive;

	const bool isEnum = qualifiedType->isEnumeralType();
	if (isEnum)
	{
		TagDecl* pTagDecl = qualifiedType->getAsTagDecl();
		EnumDecl* pEnumDecl = static_cast<EnumDecl*>(pTagDecl); // this is nasty!
		assert(pEnumDecl != nullptr);
		qualifiedType = pEnumDecl->getIntegerType()->getCanonicalTypeInternal();
	}
	const std::string integralTypeName = QualType::getAsString(qualifiedType.split(), printingPolicy);

	if (qualifiedType->isSignedIntegerType())
	{
		if (integralTypeName == "char") primitive_type = e_primitive_type::RawCharacter;
		else if (integralTypeName == "signed char") primitive_type = e_primitive_type::Int8;
		else if (integralTypeName == "short") primitive_type = e_primitive_type::Int16;
		else if (integralTypeName == "int") primitive_type = e_primitive_type::Int32;
		else if (integralTypeName == "long") primitive_type = e_primitive_type::Int32;
		else if (integralTypeName == "long long") primitive_type = e_primitive_type::Int64;
		else assert(!"Unsupported signed integral type");
	}
	else if (qualifiedType->isUnsignedIntegerType())
	{
		if (integralTypeName == "unsigned char") primitive_type = e_primitive_type::UInt8;
		else if (integralTypeName == "unsigned short") primitive_type = e_primitive_type::UInt16;
		else if (integralTypeName == "unsigned int") primitive_type = e_primitive_type::UInt32;
		else if (integralTypeName == "unsigned long long") primitive_type = e_primitive_type::UInt64;
		else assert(!"Unsupported signed integral type");
	}
	else assert(!"Unsupported integral type");

	if (isEnum)
	{
		switch (primitive_type)
		{
		case e_primitive_type::Int8:
		case e_primitive_type::UInt8:
			primitive_type = e_primitive_type::Enum8;
			break;
		case e_primitive_type::Int16:
		case e_primitive_type::UInt16:
			primitive_type = e_primitive_type::Enum16;
			break;
		case e_primitive_type::Int32:
		case e_primitive_type::UInt32:
			primitive_type = e_primitive_type::Enum32;
			break;
		case e_primitive_type::Int64:
		case e_primitive_type::UInt64:
			primitive_type = e_primitive_type::Enum64;
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

	return primitive_type;
}

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

		if ((pString[0] == 's' || pString[0] == 'c' || pString[0] == 'e' || pString[0] == 'b') && pString[1] == '_')
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
		assert(pField != nullptr);

		uint64_t field_size = 0;
		switch (pField->reflection_type_category)
		{
		case e_reflection_type_category::TagReference:
			field_size = 0x10;
			break;
		case e_reflection_type_category::TagBlock:
			field_size = 0xC;
			break;
		case e_reflection_type_category::DataReference:
			field_size = 0x14;
			break;
		case e_reflection_type_category::StringID:
			field_size = 0x4;
			break;
		case e_reflection_type_category::Primitive:
		case e_reflection_type_category::Structure:
		case e_reflection_type_category::ShaderData:
		case e_reflection_type_category::Enum:
		case e_reflection_type_category::BitField:
		default:
			field_size = InitTypeSizeAndOffsets(*pField->field_type);
			break;
		}

		if (field_size == 0)
			throw;			

		uint64_t data_size = field_size * __max(1ull, pField->array_size);
		pField->data_size = field_size;
		pField->offset = currentOffset;
		currentOffset += static_cast<uint32_t>(data_size);
	}
	rType.data_size = currentOffset;

	return rType.data_size;
}

std::vector<c_reflection_type_container*> ReflectedTypesData;

c_reflection_type_container* get_primitive_reflection_type_container(e_primitive_type primitive_type)
{
	static c_reflection_type_container* int8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int8", "int8_t", sizeof(int8_t)));
	static c_reflection_type_container* int16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int16", "int16_t", sizeof(int16_t)));
	static c_reflection_type_container* int32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int32", "int32_t", sizeof(int32_t)));
	static c_reflection_type_container* int64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Int64", "int64_t", sizeof(int64_t)));
	static c_reflection_type_container* uint8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* uint16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* uint32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* uint64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("UInt64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* boolean8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* boolean16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* boolean32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* boolean64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Boolean64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* bitfield8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* bitfield16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* bitfield32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* bitfield64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitField64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* bitflag8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* bitflag16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* bitflag32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* bitflag64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("BitFlag64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* float_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Float", "float", sizeof(float)));
	static c_reflection_type_container* double_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Double", "double", sizeof(double)));
	static c_reflection_type_container* enum8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum8", "uint8_t", sizeof(uint8_t)));
	static c_reflection_type_container* enum16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum16", "uint16_t", sizeof(uint16_t)));
	static c_reflection_type_container* enum32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum32", "uint32_t", sizeof(uint32_t)));
	static c_reflection_type_container* enum64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Enum64", "uint64_t", sizeof(uint64_t)));
	static c_reflection_type_container* undefined8_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined8", "Undefined8", sizeof(uint8_t)));
	static c_reflection_type_container* undefined16_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined16", "Undefined16", sizeof(uint16_t)));
	static c_reflection_type_container* undefined32_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined32", "Undefined32", sizeof(uint32_t)));
	static c_reflection_type_container* undefined64_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("Undefined64", "Undefined64", sizeof(uint64_t)));
	static c_reflection_type_container* raw_character_array_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("RawCharacter", "char", sizeof(char)));
	static c_reflection_type_container* raw_wide_character_array_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("RawWideCharacter", "wchar_t", sizeof(wchar_t)));
	static c_reflection_type_container* static_string_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("StaticString", "c_static_string", sizeof(char)));
	static c_reflection_type_container* static_wide_string_type = ReflectedTypesData.emplace_back(new c_reflection_type_container("StaticString", "c_static_wide_string", sizeof(wchar_t)));

	switch (primitive_type)
	{
	case e_primitive_type::Int8:				return int8_type;
	case e_primitive_type::Int16:				return int16_type;
	case e_primitive_type::Int32:				return int32_type;
	case e_primitive_type::Int64:				return int64_type;
	case e_primitive_type::UInt8:				return uint8_type;
	case e_primitive_type::UInt16:				return uint16_type;
	case e_primitive_type::UInt32:				return uint32_type;
	case e_primitive_type::UInt64:				return uint64_type;
	case e_primitive_type::Boolean8:			return boolean8_type;
	case e_primitive_type::Boolean16:			return boolean16_type;
	case e_primitive_type::Boolean32:			return boolean32_type;
	case e_primitive_type::Boolean64:			return boolean64_type;
	case e_primitive_type::BitFlag8:			return bitflag8_type;
	case e_primitive_type::BitFlag16:			return bitflag16_type;
	case e_primitive_type::BitFlag32:			return bitflag32_type;
	case e_primitive_type::BitFlag64:			return bitflag64_type;
	case e_primitive_type::BitField8:			return bitfield8_type;
	case e_primitive_type::BitField16:			return bitfield16_type;
	case e_primitive_type::BitField32:			return bitfield32_type;
	case e_primitive_type::BitField64:			return bitfield64_type;
	case e_primitive_type::Float:				return float_type;
	case e_primitive_type::Double:				return double_type;
	case e_primitive_type::Enum8:				return enum8_type;
	case e_primitive_type::Enum16:				return enum16_type;
	case e_primitive_type::Enum32:				return enum32_type;
	case e_primitive_type::Enum64:				return enum64_type;
	case e_primitive_type::Undefined8:			return undefined8_type;
	case e_primitive_type::Undefined16:			return undefined16_type;
	case e_primitive_type::Undefined32:			return undefined32_type;
	case e_primitive_type::Undefined64:			return undefined64_type;
	case e_primitive_type::RawCharacter:		return raw_character_array_type;
	case e_primitive_type::RawWideCharacter:	return raw_wide_character_array_type;
	case e_primitive_type::StaticString:		return static_string_type;
	case e_primitive_type::StaticWideString:	return static_wide_string_type;
	}

	assert(!"Undefined primitive type");
	return nullptr;
}

c_reflection_type_container* CreateReflectedEnumType(ASTContext* Context, const clang::QualType* recordQualifiedType, const clang::RecordDecl& rRecordDeclaration)
{
	const clang::EnumDecl* enum_decl = dyn_cast<EnumDecl>(&rRecordDeclaration);
	assert(enum_decl != nullptr);

	std::string declarationName = rRecordDeclaration.getNameAsString();
	std::string qualifiedDeclarationName;
	if (recordQualifiedType)
	{
		qualifiedDeclarationName = QualType::getAsString(recordQualifiedType->split(), printingPolicy);
	}
	else // construct best qualified type name
	{
		assert(rRecordDeclaration.isEnum());
		if (rRecordDeclaration.isEnum())
		{
			qualifiedDeclarationName += "enum ";
		}
		qualifiedDeclarationName += rRecordDeclaration.getQualifiedNameAsString();
	}

	for (c_reflection_type_container* reflection_typeContainer : ReflectedTypesData)
	{
		if (reflection_typeContainer->clang_record_declaration == &rRecordDeclaration || reflection_typeContainer->qualified_type_name == qualifiedDeclarationName)
		{
			return reflection_typeContainer;
		}
	}

	c_reflection_type_container& reflection_type_container = *new c_reflection_type_container();
	ReflectedTypesData.emplace_back(&reflection_type_container);

	reflection_type_container.type_name = declarationName;
	reflection_type_container.qualified_type_name = qualifiedDeclarationName;
	reflection_type_container.clang_record_declaration = &rRecordDeclaration;
	reflection_type_container.is_primitive = false;
	reflection_type_container.is_enum = true;
	reflection_type_container.is_structure = false;

	e_primitive_type primitive_type = qualified_type_to_primitive_type(*recordQualifiedType);
	switch (primitive_type)
	{
	case e_primitive_type::Enum8:
		reflection_type_container.data_size = 1;
		break;
	case e_primitive_type::Enum16:
		reflection_type_container.data_size = 2;
		break;
	case e_primitive_type::Enum32:
		reflection_type_container.data_size = 4;
		break;
	case e_primitive_type::Enum64:
		reflection_type_container.data_size = 8;
		break;
	}
	reflection_type_container.is_size_initialized = true;

	//QualType integer_type = enum_decl->getIntegerType();

	bool disableReflection = false;
	std::string nice_name_str;
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
		}
	}

	reflection_type_container.type_nice_name = nice_name_str;

	if (disableReflection)
	{
		return &reflection_type_container;
	}

	for (const clang::EnumDecl::enumerator_iterator::value_type& enum_decl : enum_decl->enumerators())
	{
		c_reflection_enum_value_container* enum_value_container = new c_reflection_enum_value_container();

		enum_value_container->value_name = enum_decl->getNameAsString();
		const llvm::APSInt& init_value = enum_decl->getInitVal();
		const uint64_t* raw_data = init_value.getRawData();
		if (raw_data)
		{
			enum_value_container->value = *raw_data;
		}
		reflection_type_container.enum_values.push_back(enum_value_container);
	}

	return &reflection_type_container;
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

	c_reflection_type_container* pExistings_reflection_structure_typeContainer = nullptr;
	{ // handle existing records
		for (c_reflection_type_container* reflection_typeContainer : ReflectedTypesData)
		{
			if (reflection_typeContainer->clang_record_declaration == &rRecordDeclaration || reflection_typeContainer->qualified_type_name == qualifiedDeclarationName)
			{
				pExistings_reflection_structure_typeContainer = reflection_typeContainer;

			}
		}
	}
	if (pExistings_reflection_structure_typeContainer)
	{
		if (numFields == 0)
		{
			return pExistings_reflection_structure_typeContainer; // we already have data for this
		}
		else if (!pExistings_reflection_structure_typeContainer->fields.empty())
		{
			return pExistings_reflection_structure_typeContainer; // we already have data for this
		}
	}

	// if existing reflection container exists and we're updating it, replace all data

	bool createdNewReflectionContainer = pExistings_reflection_structure_typeContainer == nullptr;
	c_reflection_type_container* ps_reflection_structure_typeContainer = pExistings_reflection_structure_typeContainer;
	if (createdNewReflectionContainer)
	{
		ps_reflection_structure_typeContainer = new c_reflection_type_container();
	}
	c_reflection_type_container& reflection_type_container = *ps_reflection_structure_typeContainer;

	assert(reflection_type_container.fields.empty());

	reflection_type_container.type_name = declarationName;
	reflection_type_container.qualified_type_name = qualifiedDeclarationName;
	reflection_type_container.clang_record_declaration = &rRecordDeclaration;
	reflection_type_container.is_primitive = isPrimitive;
	reflection_type_container.is_enum = false;
	reflection_type_container.is_structure = true;

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

				assert(tagGroupRawStringLength == 5 || tagGroupRawStringLength == 6);
				char buffer[5]{}; // #NOTE: We expect to receive these characters swapped. We're swapping them back to the original integer order
				if (tagGroupRawStringLength == 5)
				{
					buffer[0] = ' ';
					buffer[1] = pTagGroupStringBegin[3];
					buffer[2] = pTagGroupStringBegin[2];
					buffer[3] = pTagGroupStringBegin[1];
				}
				if (tagGroupRawStringLength == 6)
				{
					buffer[0] = pTagGroupStringBegin[4];
					buffer[1] = pTagGroupStringBegin[3];
					buffer[2] = pTagGroupStringBegin[2];
					buffer[3] = pTagGroupStringBegin[1];
				}
				tag_group_str = buffer;
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
				rFieldData.field_type = get_primitive_reflection_type_container(primitiveType);
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
				rFieldData.primitive_type = qualified_type_to_primitive_type(scalarQualifiedType);
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
			rFieldData.field_type = get_primitive_reflection_type_container(rFieldData.primitive_type);
		}
		else assert(!"UNSUPPORTED TYPE");

		if (reflectionQualifiedType->isEnumeralType())
		{
			clang::QualType enumQualifiedType = reflectionQualifiedType->getCanonicalTypeInternal();
			const std::string enumQualifiedTypeName = QualType::getAsString(enumQualifiedType.split(), printingPolicy);
			TagDecl* pEnumDecl = reflectionQualifiedType->getAsTagDecl();
			clang::RecordDecl* pCXXRecord = static_cast<clang::RecordDecl*>(pEnumDecl);

			c_reflection_type_container* pType = CreateReflectedEnumType(Context, &fieldQualifiedType, *pCXXRecord);
			assert(pType != nullptr);
			rFieldData.field_type = pType;

			if (!pType->type_name.empty() && std::tolower(pType->type_name.front()) == 'b')
			{
				pType->is_enum = false;
				pType->is_bitfield = true;
				rFieldData.reflection_type_category = e_reflection_type_category::BitField;
				switch (rFieldData.primitive_type)
				{
				case e_primitive_type::Enum8:	rFieldData.primitive_type = e_primitive_type::BitField8;  break;
				case e_primitive_type::Enum16:	rFieldData.primitive_type = e_primitive_type::BitField16; break;
				case e_primitive_type::Enum32:	rFieldData.primitive_type = e_primitive_type::BitField32; break;
				case e_primitive_type::Enum64:	rFieldData.primitive_type = e_primitive_type::BitField64; break;
				}
			}
			else
			{
				rFieldData.reflection_type_category = e_reflection_type_category::Enum;
			}
		}

		assert(rFieldData.field_type != nullptr);
	}

	if (createdNewReflectionContainer)
	{
		ReflectedTypesData.emplace_back(ps_reflection_structure_typeContainer);
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
		if (rType.is_structure && rType.data_size == 0)
		{
			assert(rType.data_size > 0);
		}
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


