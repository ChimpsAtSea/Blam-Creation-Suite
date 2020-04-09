#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_legacy_compiler_interface::c_legacy_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	c_llvm_compiler_interface(executable_path, reflection_source_file),
	int8_type(),
	int16_type(),
	int32_type(),
	int64_type(),
	uint8_type(),
	uint16_type(),
	uint32_type(),
	uint64_type(),
	boolean8_type(),
	boolean16_type(),
	boolean32_type(),
	boolean64_type(),
	bitfield8_type(),
	bitfield16_type(),
	bitfield32_type(),
	bitfield64_type(),
	bitflag8_type(),
	bitflag16_type(),
	bitflag32_type(),
	bitflag64_type(),
	float_type(),
	double_type(),
	enum8_type(),
	enum16_type(),
	enum32_type(),
	enum64_type(),
	undefined8_type(),
	undefined16_type(),
	undefined32_type(),
	undefined64_type(),
	raw_character_array_type(),
	raw_wide_character_array_type(),
	static_string_type(),
	static_wide_string_type()
{
	int8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Int8", "int8_t", sizeof(int8_t)));
	int16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Int16", "int16_t", sizeof(int16_t)));
	int32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Int32", "int32_t", sizeof(int32_t)));
	int64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Int64", "int64_t", sizeof(int64_t)));
	uint8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("UInt8", "uint8_t", sizeof(uint8_t)));
	uint16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("UInt16", "uint16_t", sizeof(uint16_t)));
	uint32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("UInt32", "uint32_t", sizeof(uint32_t)));
	uint64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("UInt64", "uint64_t", sizeof(uint64_t)));
	boolean8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Boolean8", "uint8_t", sizeof(uint8_t)));
	boolean16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Boolean16", "uint16_t", sizeof(uint16_t)));
	boolean32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Boolean32", "uint32_t", sizeof(uint32_t)));
	boolean64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Boolean64", "uint64_t", sizeof(uint64_t)));
	bitfield8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitField8", "uint8_t", sizeof(uint8_t)));
	bitfield16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitField16", "uint16_t", sizeof(uint16_t)));
	bitfield32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitField32", "uint32_t", sizeof(uint32_t)));
	bitfield64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitField64", "uint64_t", sizeof(uint64_t)));
	bitflag8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitFlag8", "uint8_t", sizeof(uint8_t)));
	bitflag16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitFlag16", "uint16_t", sizeof(uint16_t)));
	bitflag32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitFlag32", "uint32_t", sizeof(uint32_t)));
	bitflag64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("BitFlag64", "uint64_t", sizeof(uint64_t)));
	float_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Float", "float", sizeof(float)));
	double_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Double", "double", sizeof(double)));
	enum8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Enum8", "uint8_t", sizeof(uint8_t)));
	enum16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Enum16", "uint16_t", sizeof(uint16_t)));
	enum32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Enum32", "uint32_t", sizeof(uint32_t)));
	enum64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Enum64", "uint64_t", sizeof(uint64_t)));
	undefined8_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Undefined8", "Undefined8", sizeof(uint8_t)));
	undefined16_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Undefined16", "Undefined16", sizeof(uint16_t)));
	undefined32_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Undefined32", "Undefined32", sizeof(uint32_t)));
	undefined64_type = reflection_type_containers.emplace_back(new c_reflection_type_container("Undefined64", "Undefined64", sizeof(uint64_t)));
	raw_character_array_type = reflection_type_containers.emplace_back(new c_reflection_type_container("RawCharacter", "char", sizeof(char)));
	raw_wide_character_array_type = reflection_type_containers.emplace_back(new c_reflection_type_container("RawWideCharacter", "wchar_t", sizeof(wchar_t)));
	static_string_type = reflection_type_containers.emplace_back(new c_reflection_type_container("StaticString", "c_static_string", sizeof(char)));
	static_wide_string_type = reflection_type_containers.emplace_back(new c_reflection_type_container("StaticString", "c_static_wide_string", sizeof(wchar_t)));
}

c_legacy_compiler_interface::~c_legacy_compiler_interface()
{

}

void c_legacy_compiler_interface::execute_type_generator()
{
	for (c_reflection_type_container* reflection_type_container : reflection_type_containers)
	{
		assert(reflection_type_container != nullptr);
		init_type_size_and_offsets(*reflection_type_container);
		if (reflection_type_container->is_structure)
		{
			assert(reflection_type_container->data_size > 0);
		}
		create_nice_type_names(*reflection_type_container);
	}
}

uint32_t c_legacy_compiler_interface::init_type_size_and_offsets(c_reflection_type_container& reflection_type_container)
{
	if (reflection_type_container.is_size_initialized)
	{
		return reflection_type_container.data_size;
	}

	uint32_t current_offset = 0;
	for (c_reflection_field_container* reflection_field_container : reflection_type_container.fields)
	{
		assert(reflection_field_container != nullptr);

		uint64_t field_size = 0;
		switch (reflection_field_container->reflection_type_category)
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
			field_size = init_type_size_and_offsets(*reflection_field_container->field_type);
			break;
		}

		if (field_size == 0)
			throw;

		uint64_t data_size = field_size * __max(1ull, reflection_field_container->array_size);
		reflection_field_container->data_size = field_size;
		reflection_field_container->offset = current_offset;
		current_offset += static_cast<uint32_t>(data_size);
	}
	reflection_type_container.data_size = current_offset;

	return reflection_type_container.data_size;
}

void c_legacy_compiler_interface::create_nice_type_names(c_reflection_type_container& rType)
{
	rType.type_nice_name = rType.type_name;
	rType.type_nice_name = format_nice_name_and_is_hidden_property(e_reflection_type_category::Structure, rType.type_nice_name.data());
	for (c_reflection_field_container* pField : rType.fields)
	{
		c_reflection_field_container& rField = *pField;

		rField.field_nice_name = rField.field_name;
		rField.is_hidden_by_default = false;
		rField.field_nice_name = format_nice_name_and_is_hidden_property(rField.reflection_type_category, rField.field_nice_name.data(), &rField.is_hidden_by_default);
	}
}

e_primitive_type c_legacy_compiler_interface::qualified_type_to_primitive_type(const clang::QualType& _qualifiedType)
{
	clang::QualType qualified_type = _qualifiedType;

	e_primitive_type primitive_type = e_primitive_type::NonPrimitive;

	const bool is_enum = qualified_type->isEnumeralType();
	if (is_enum)
	{
		TagDecl* tag_declaraction = qualified_type->getAsTagDecl();
		EnumDecl* enum_declaration = static_cast<EnumDecl*>(tag_declaraction); // this is nasty!
		assert(enum_declaration != nullptr);
		qualified_type = enum_declaration->getIntegerType()->getCanonicalTypeInternal();
	}
	const std::string integral_type_name = QualType::getAsString(qualified_type.split(), k_clang_printing_policy);

	if (qualified_type->isSignedIntegerType())
	{
		if (integral_type_name == "char") primitive_type = e_primitive_type::RawCharacter;
		else if (integral_type_name == "signed char") primitive_type = e_primitive_type::Int8;
		else if (integral_type_name == "short") primitive_type = e_primitive_type::Int16;
		else if (integral_type_name == "int") primitive_type = e_primitive_type::Int32;
		else if (integral_type_name == "long") primitive_type = e_primitive_type::Int32;
		else if (integral_type_name == "long long") primitive_type = e_primitive_type::Int64;
		else assert(!"Unsupported signed integral type");
	}
	else if (qualified_type->isUnsignedIntegerType())
	{
		if (integral_type_name == "unsigned char") primitive_type = e_primitive_type::UInt8;
		else if (integral_type_name == "unsigned short") primitive_type = e_primitive_type::UInt16;
		else if (integral_type_name == "unsigned int") primitive_type = e_primitive_type::UInt32;
		else if (integral_type_name == "unsigned long long") primitive_type = e_primitive_type::UInt64;
		else assert(!"Unsupported signed integral type");
	}
	else assert(!"Unsupported integral type");

	// its an enum. convert from its underlying integral type
	if (is_enum)
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

c_reflection_type_container* c_legacy_compiler_interface::create_reflected_enum_type(
	const clang::QualType* record_qualified_type,
	const clang::RecordDecl& record_declaration)
{
	const clang::EnumDecl* enum_decl = dyn_cast<EnumDecl>(&record_declaration);
	assert(enum_decl != nullptr);

	std::string declarationName = record_declaration.getNameAsString();
	std::string qualifiedDeclarationName;
	if (record_qualified_type)
	{
		qualifiedDeclarationName = QualType::getAsString(record_qualified_type->split(), k_clang_printing_policy);
	}
	else // construct best qualified type name
	{
		assert(record_declaration.isEnum());
		if (record_declaration.isEnum())
		{
			qualifiedDeclarationName += "enum ";
		}
		qualifiedDeclarationName += record_declaration.getQualifiedNameAsString();
	}

	for (c_reflection_type_container* reflection_typeContainer : reflection_type_containers)
	{
		if (reflection_typeContainer->clang_record_declaration == &record_declaration || reflection_typeContainer->qualified_type_name == qualifiedDeclarationName)
		{
			return reflection_typeContainer;
		}
	}

	c_reflection_type_container& reflection_type_container = *new c_reflection_type_container();
	reflection_type_containers.emplace_back(&reflection_type_container);

	reflection_type_container.type_name = declarationName;
	reflection_type_container.qualified_type_name = qualifiedDeclarationName;
	reflection_type_container.clang_record_declaration = &record_declaration;
	reflection_type_container.is_primitive = false;
	reflection_type_container.is_enum = true;
	reflection_type_container.is_structure = false;

	e_primitive_type primitive_type = qualified_type_to_primitive_type(*record_qualified_type);
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
	for (clang::Attr* it : record_declaration.attrs())
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

c_reflection_type_container* c_legacy_compiler_interface::create_reflected_type(
	ASTContext* ast_context,
	const clang::QualType* record_qualified_type,
	const clang::RecordDecl& record_declaration,
	bool is_primitive)
{
	std::string declarationName = record_declaration.getNameAsString();
	std::string qualifiedDeclarationName;
	if (record_qualified_type)
	{
		qualifiedDeclarationName = QualType::getAsString(record_qualified_type->split(), k_clang_printing_policy);
	}
	else // construct best qualified type name
	{
		if (record_declaration.isClass())
		{
			qualifiedDeclarationName += "class ";
		}
		else if (record_declaration.isStruct())
		{
			qualifiedDeclarationName += "struct ";
		}
		qualifiedDeclarationName += record_declaration.getQualifiedNameAsString();
	}

	RecordDecl::field_range fields = record_declaration.fields();
	size_t numFields = false; for (FieldDecl* field : fields) { numFields++; }

	bool isTemplated = record_declaration.isTemplated();
	const clang::ClassTemplateSpecializationDecl* pClassTemplateSpecializationDecl = dyn_cast<ClassTemplateSpecializationDecl>(&record_declaration);
	if (isTemplated && pClassTemplateSpecializationDecl == nullptr)
	{
		return nullptr;
	}

	c_reflection_type_container* pExistings_reflection_structure_typeContainer = nullptr;
	{ // handle existing records
		for (c_reflection_type_container* reflection_typeContainer : reflection_type_containers)
		{
			if (reflection_typeContainer->clang_record_declaration == &record_declaration || reflection_typeContainer->qualified_type_name == qualifiedDeclarationName)
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
	reflection_type_container.clang_record_declaration = &record_declaration;
	reflection_type_container.is_primitive = is_primitive;
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
				const std::string reflectionQualifiedTypeName = QualType::getAsString(qualifiedType.split(), k_clang_printing_policy);
				CXXRecordDecl* pDecl = qualifiedType->getAsCXXRecordDecl();
				assert(pDecl != nullptr);
				c_reflection_type_container* pTemplateType = create_reflected_type(ast_context, &qualifiedType, *pDecl);
				assert(pTemplateType != nullptr);
				reflection_type_container.template_types.push_back(pTemplateType);
			}
		}
	}

	bool disableReflection = false;
	std::string no_reflection_str;
	std::string nice_name_str;
	std::string tag_group_str;
	for (clang::Attr* it : record_declaration.attrs())
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

		const std::string fieldQualifiedTypeName = QualType::getAsString(fieldQualifiedType.split(), k_clang_printing_policy);
		const std::string fieldQualifiedName = field->getQualifiedNameAsString();
		const std::string fieldName = field->getNameAsString();

		rFieldData.field_name = fieldName;

		const clang::Type* const reflectionBaseType = fieldType;
		const clang::QualType reflectionQualifiedBaseType = reflectionBaseType->getCanonicalTypeInternal();
		clang::QualType reflectionQualifiedType = reflectionQualifiedBaseType;

		if (reflectionQualifiedType->isArrayType())
		{
			const ConstantArrayType* pConstantArrayType = ast_context->getAsConstantArrayType(reflectionQualifiedType);
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
		const std::string reflectionQualifiedTypeName = QualType::getAsString(reflectionQualifiedType.split(), k_clang_printing_policy);


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
				else if (name == "DEPRECATED_string_id") reflectionTypeCategory = e_reflection_type_category::StringID;
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
				c_reflection_type_container* pType = create_reflected_type(ast_context, &fieldQualifiedType, *pCXXRecord);
				assert(pType != nullptr);
				rFieldData.field_type = pType;
			}
		}
		else if (reflectionQualifiedType->isScalarType())
		{
			clang::QualType scalarQualifiedType = reflectionQualifiedType->getCanonicalTypeInternal();
			const std::string scalarQualifiedTypeName = QualType::getAsString(scalarQualifiedType.split(), k_clang_printing_policy);

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
				const std::string typeName = QualType::getAsString(scalarQualifiedType.split(), k_clang_printing_policy);
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
			const std::string enumQualifiedTypeName = QualType::getAsString(enumQualifiedType.split(), k_clang_printing_policy);
			TagDecl* pEnumDecl = reflectionQualifiedType->getAsTagDecl();
			clang::RecordDecl* pCXXRecord = static_cast<clang::RecordDecl*>(pEnumDecl);

			c_reflection_type_container* pType = create_reflected_enum_type(&fieldQualifiedType, *pCXXRecord);
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
		reflection_type_containers.emplace_back(ps_reflection_structure_typeContainer);
	}

	return &reflection_type_container;
}

c_reflection_type_container* c_legacy_compiler_interface::get_primitive_reflection_type_container(e_primitive_type primitive_type)
{
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

const char* c_legacy_compiler_interface::format_nice_name_and_is_hidden_property(e_reflection_type_category reflection_type_category, char* pString, bool* is_hidden_by_default)
{
	char* pOutputString = pString;

	uint32_t currentPos = 0;

	if ((pString[0] && pString[1]))
	{
		if (pString[0] == '_' && pString[1] == '_')
		{
			if (is_hidden_by_default)
			{
				*is_hidden_by_default = true;
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

		if (reflection_type_category == e_reflection_type_category::TagBlock)
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

		if (reflection_type_category == e_reflection_type_category::TagReference)
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

		if (reflection_type_category == e_reflection_type_category::DataReference)
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
