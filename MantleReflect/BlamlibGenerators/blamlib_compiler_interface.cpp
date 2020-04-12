#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_blamlib_compiler_interface::c_blamlib_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	c_llvm_compiler_interface(executable_path, reflection_source_file),
	ast_source_generators(),
	type_containers(),
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
	float_type(),
	double_type(),
	undefined8_type(),
	undefined16_type(),
	undefined32_type(),
	undefined64_type(),
	static_string_type(),
	static_wide_string_type()
{
	int8_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_int, "int8_t", "int8_t", "Int8", "Signed 8bit Integer"));
	int16_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_int, "int16_t", "int16_t", "Int16", "Signed 16bit Integer"));
	int32_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_int, "int32_t", "int32_t", "Int32", "Signed 32bit Integer"));
	int64_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_int, "int64_t", "int64_t", "Int64", "Signed 64bit Integer"));
	uint8_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_uint, "uint8_t", "uint8_t", "UInt8", "Unsigned 8bit Integer"));
	uint16_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_uint, "uint16_t", "uint16_t", "UInt16", "Unsigned 16bit Integer"));
	uint32_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_uint, "uint32_t", "uint32_t", "UInt32", "Unsigned 32bit Integer"));
	uint64_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_uint, "uint64_t", "uint64_t", "UInt64", "Unsigned 64bit Integer"));
	boolean8_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_boolean, "bool8_t", "bool8_t", "Boolean8", "8bit Boolean"));
	boolean16_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_boolean, "bool16_t", "bool16_t", "Boolean16", "16bit Boolean"));
	boolean32_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_boolean, "bool32_t", "bool32_t", "Boolean32", "32bit Boolean"));
	boolean64_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_boolean, "bool64_t", "bool64_t", "Boolean64", "64bit Boolean"));
	undefined8_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_undefined, "undefined8_t", "undefined8_t", "Undefined8", "8bit undefined value"));
	undefined16_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_undefined, "undefined16_t", "undefined16_t", "Undefined16", "16bit undefined value"));
	undefined32_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_undefined, "undefined32_t", "undefined32_t", "Undefined32", "32bit undefined value"));
	undefined64_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_undefined, "undefined64_t", "undefined64_t", "Undefined64", "64bit undefined value"));
	float_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_float, "float", "float", "Float", "32bit Floating Point Number"));
	double_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_float, "double", "double", "Double", "64bit Floating Point Number"));
	static_string_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_text, "char8_t", "char8_t", "StaticString", "8bit Character"));
	static_wide_string_type = type_containers.emplace_back(new c_reflection_type_container(_reflection_type_class_text, "char16_t", "char16_t", "StaticString", "16bit Character"));
}

c_blamlib_compiler_interface::~c_blamlib_compiler_interface()
{
	for (c_reflection_type_container* type_container : type_containers)
	{
		delete type_container;
	}
}

void c_blamlib_compiler_interface::register_ast_source_generator(c_ast_source_generator* source_generator)
{
	ast_source_generators.push_back(source_generator);
}

void c_blamlib_compiler_interface::create_reflected_type(
	clang::ASTContext& ast_context,
	const clang::QualType* record_qualified_type,
	const clang::RecordDecl& record_declaration,
	bool is_primitive)
{
	create_reflected_struct(ast_context, record_qualified_type, record_declaration, is_primitive);
}

int c_blamlib_compiler_interface::run()
{
	int clang_tool_result = c_llvm_compiler_interface::run();
	if (clang_tool_result == 0)
	{
		tbb::parallel_for_each(ast_source_generators.begin(), ast_source_generators.end(), std::bind(&c_blamlib_compiler_interface::execute_source_generator, this, std::placeholders::_1));
	}
	return clang_tool_result;
}

c_reflection_type_container* c_blamlib_compiler_interface::create_reflected_struct(
	clang::ASTContext& ast_context,
	const clang::QualType* record_qualified_type,
	const clang::RecordDecl& record_declaration,
	bool is_primitive)
{
	std::string type_name = record_declaration.getNameAsString();
	std::string qualified_name = record_declaration.getQualifiedNameAsString();

	bool is_anonymous = record_declaration.isAnonymousStructOrUnion();
	if (is_anonymous)
	{
		printf("blamlib_compiler_interface> skipping '%s' (anonymous type)\n", type_name.c_str());
		return nullptr;
	}

	/* if (type_name == "c_enum")
	{
		return nullptr;
	}
	else if (type_name == "c_typed_tag_block")
	{
		return nullptr;
	}
	else */ if (strncmp(qualified_name.c_str(), "s_", 2) != 0)
	{
		printf("blamlib_compiler_interface> skipping '%s'\n", type_name.c_str());
		return nullptr;
	}

	if (!record_declaration.isCompleteDefinition())
	{
		printf("blamlib_compiler_interface> skipping '%s' (incomplete type)\n", type_name.c_str());
		return nullptr;
	}

	for (c_reflection_type_container* type_container : type_containers)
	{
		if (type_container->type_name == type_name)
		{
			return type_container;
		}
	}


	SourceManager& source_manager = ast_context.getSourceManager();
	const clang::ClassTemplateSpecializationDecl* class_template_specialization_decl = dyn_cast<const clang::ClassTemplateSpecializationDecl>(&record_declaration);

	bool is_template = class_template_specialization_decl != nullptr;
	bool is_class = record_declaration.isClass();
	bool is_struct = record_declaration.isStruct();
	bool is_union = record_declaration.isUnion();
	bool is_object = is_struct || is_class || is_union;
	ASSERT(is_object);

	if (is_template)
	{
		// #TODO: Template specialization
		return nullptr;
	}

	printf("blamlib_compiler_interface> creating object '%s'\n", type_name.c_str());

	bool is_bitmap = type_name == "s_bitmap_definition";
	if (is_bitmap)
	{
		printf("");
	}

	e_reflection_type_class type_class = is_union ? _reflection_type_class_union : _reflection_type_class_structure;

	c_reflection_type_container* type_container = new c_reflection_type_container(type_class, type_name, qualified_name, type_name, "todo description");
	type_containers.push_back(type_container);

	RecordDecl::field_range structure_fields = record_declaration.fields();
	bool has_fields = structure_fields.end() != structure_fields.begin();
	for (FieldDecl* field : structure_fields)
	{
		const clang::QualType field_qualified_type = field->getType();
		const clang::Type* field_type = field_qualified_type.getTypePtr();
		const clang::RecordDecl* field_record_declaration = nullptr;
		const clang::ClassTemplateSpecializationDecl* field_class_template_specialization_decl = nullptr;

		const std::string field_qualified_type_name = QualType::getAsString(field_qualified_type.split(), k_clang_printing_policy);
		const std::string field_type_name = field_record_declaration ? field_record_declaration->getNameAsString() : field_qualified_type_name;
		const std::string field_qualified_name = field->getQualifiedNameAsString();
		const std::string field_name = field->getNameAsString();
		std::string decl_name = "";

		bool is_field_scalar = field_type->isScalarType();
		bool is_field_enum = field_type->isEnumeralType();
		bool is_field_struct = field_type->isStructureType();
		bool is_field_class = field_type->isClassType();
		bool is_field_union = field_type->isUnionType();
		bool is_field_object = is_field_struct || is_field_class || is_field_union;

		if (is_field_object)
		{
			field_record_declaration = field_qualified_type->getAsRecordDecl();
			ASSERT(field_record_declaration != nullptr);
			decl_name = field_record_declaration->getDeclName().getAsString();
			field_class_template_specialization_decl = dyn_cast<const clang::ClassTemplateSpecializationDecl>(field_record_declaration);
		}

		bool is_anonymous = is_field_object && field_record_declaration->isAnonymousStructOrUnion();
		bool is_field_template = field_class_template_specialization_decl != nullptr;
		bool is_field_custom_enum = is_field_template && decl_name == "c_enum";
		bool is_field_custom_flags = is_field_template && decl_name == "c_flags";
		bool is_field_tag_block = is_field_template && decl_name == "c_typed_tag_block";
		bool is_field_recognised_template = is_field_custom_enum || is_field_custom_flags || is_field_tag_block;

		if (is_field_template && !is_field_recognised_template)
		{
			continue; // #TODO: Figure out how to support lots of templated types
			ASSERT(is_field_recognised_template);
		}

		c_reflection_field_container* field_container = new c_reflection_field_container();
		type_container->field_containers.push_back(field_container);
		field_container->field_name = field_name;
		field_container->nice_name = field_name;
		field_container->type_container = nullptr;
		field_container->type_class = _reflection_type_class_undefined;
		field_container->qualified_decl = field_qualified_name;

		if (is_anonymous) // process these fields in place
		{

		}
		else if (is_field_tag_block)
		{
			const TemplateArgumentList& template_arguments = field_class_template_specialization_decl->getTemplateArgs();
			ASSERT(template_arguments.size() == 1);

			const TemplateArgument& argument0 = template_arguments.get(0);
			clang::QualType tag_block_qualified_type = argument0.getAsType();
			bool is_void_type = tag_block_qualified_type->isVoidType();
			ASSERT(!is_void_type);

			const std::string tag_block_qualified_type_name = QualType::getAsString(tag_block_qualified_type.split(), k_clang_printing_policy);

			bool is_tag_block_scalar = tag_block_qualified_type->isScalarType();
			bool is_tag_block_enum = tag_block_qualified_type->isEnumeralType();
			bool is_tag_block_struct = tag_block_qualified_type->isStructureType();
			bool is_tag_block_class = tag_block_qualified_type->isClassType();
			bool is_tag_block_union = tag_block_qualified_type->isUnionType();
			bool is_tag_block_object = is_tag_block_struct || is_tag_block_class || is_tag_block_union;

			if (is_tag_block_object)
			{
				const RecordDecl* tag_block_record_decl = tag_block_qualified_type->getAsRecordDecl();
				ASSERT(tag_block_record_decl != nullptr);

				field_container->type_container = create_reflected_struct(ast_context, &tag_block_qualified_type, *tag_block_record_decl);
			}
			else if (is_tag_block_scalar)
			{
				c_reflection_type_container* scalar_type_container = get_reflected_scalar(ast_context, tag_block_qualified_type);

				if (scalar_type_container)
				{
					field_container->type_container = scalar_type_container;
					field_container->type_class = field_container->type_container->type_class;
				}
				else
				{
					constexpr const char* scalar_type_kind_to_string[] =
					{
					"STK_CPointer"
					"STK_BlockPointer"
					"STK_ObjCObjectPointer"
					"STK_MemberPointer"
					"STK_Bool"
					"STK_Integral"
					"STK_Floating"
					"STK_IntegralComplex"
					"STK_FloatingComplex"
					"STK_FixedPoint",
					"<unknown scalar type kind>"
					};
					const clang::Type::ScalarTypeKind scalar_type_kind = tag_block_qualified_type->getScalarTypeKind();
					const char* scalar_type_kind_str = scalar_type_kind_to_string[__min(scalar_type_kind, _countof(scalar_type_kind_to_string) - 1)];
					printf("Unknown scalar type for tag block '%s' '%s' (%s)", type_name.c_str(), field_name.c_str(), scalar_type_kind_str);
				}
			}
			else
			{
				printf("Unknown type for '%s' '%s'", type_name.c_str(), field_name.c_str());
			}
			
			field_container->type_class = _reflection_type_class_tag_block;

		}
		else if (is_field_custom_enum || is_field_custom_flags)
		{
			const TemplateArgumentList& template_arguments = field_class_template_specialization_decl->getTemplateArgs();
			ASSERT(template_arguments.size() >= 2);

			const TemplateArgument& argument0 = template_arguments.get(0);
			clang::QualType enum_qualified_type = argument0.getAsType();
			bool is_enum_type = enum_qualified_type->isEnumeralType();
			ASSERT(is_enum_type);

			const TemplateArgument& argument1 = template_arguments.get(1);
			clang::QualType storage_qualified_type = argument0.getAsType();
			bool is_scalar_type = enum_qualified_type->isScalarType();
			ASSERT(is_scalar_type);

			field_container->type_container = create_reflected_enum(ast_context, enum_qualified_type);

			if (is_field_custom_enum)
			{
				field_container->type_class = _reflection_type_class_enum;
			}
			else if (is_field_custom_flags)
			{
				field_container->type_class = _reflection_type_class_bitfield;
			}
		}
		else if (is_field_object)
		{
			TagDecl* tag_decl = field_qualified_type->getAsTagDecl();
			clang::RecordDecl* record_decl = static_cast<clang::RecordDecl*>(tag_decl);
			std::string name = tag_decl->getNameAsString();

			field_container->type_container = create_reflected_struct(ast_context, &field_qualified_type, *record_decl);

			if (is_union)
			{
				field_container->type_class = _reflection_type_class_union;
			}
			else
			{
				field_container->type_class = _reflection_type_class_structure;
			}

		}
		else if (is_field_enum)
		{
			printf("");
		}
		else if (is_field_scalar)
		{
			c_reflection_type_container* scalar_type_container = get_reflected_scalar(ast_context, field_qualified_type);

			if (scalar_type_container)
			{
				field_container->type_container = scalar_type_container;
				field_container->type_class = field_container->type_container->type_class;
			}
			else
			{
				constexpr const char* scalar_type_kind_to_string[] =
				{
				"STK_CPointer"
				"STK_BlockPointer"
				"STK_ObjCObjectPointer"
				"STK_MemberPointer"
				"STK_Bool"
				"STK_Integral"
				"STK_Floating"
				"STK_IntegralComplex"
				"STK_FloatingComplex"
				"STK_FixedPoint",
				"<unknown scalar type kind>"
				};
				const clang::Type::ScalarTypeKind scalar_type_kind = field_qualified_type->getScalarTypeKind();
				const char* scalar_type_kind_str = scalar_type_kind_to_string[__min(scalar_type_kind, _countof(scalar_type_kind_to_string) - 1)];
				printf("Unknown scalar type for '%s' '%s' (%s)", type_name.c_str(), field_name.c_str(), scalar_type_kind_str);
			}
		}

		comments::FullComment* full_comment = ast_context.getCommentForDecl(field, nullptr);
		//const RawComment* raw_comment = ast_context.getRawCommentForDeclNoCache(&record_declaration);

		//if (raw_comment)
		if (full_comment)
		{
			std::string comment_raw_text;
			for (comments::Comment::child_iterator comment_iterator = full_comment->child_begin(); comment_iterator != full_comment->child_end(); comment_iterator++)
			{
				comments::Comment& comment_section = **comment_iterator;

				if (comment_section.getCommentKind() != comments::BlockContentComment::ParagraphCommentKind)
				{
					continue;
				}

				for (auto textItr = comment_section.child_begin(); textItr != comment_section.child_end(); textItr++)
				{
					if (auto textComment = dyn_cast<comments::TextComment>(*textItr))
					{
						comment_raw_text += textComment->getText().ltrim();
						comment_raw_text += " ";
					}
				}
			}

			printf("blamlib_compiler_interface> \t'%s' // %s\n", field_name.c_str(), comment_raw_text.c_str());
		}
		else
		{
			printf("blamlib_compiler_interface> \t'%s'\n", field_name.c_str());
		}
	}
	printf("blamlib_compiler_interface> };\n");

	return type_container;
}

c_reflection_type_container* c_blamlib_compiler_interface::get_reflected_scalar(clang::ASTContext& ast_context, const clang::QualType& qualified_type)
{
	const clang::Type::ScalarTypeKind scalar_type_kind = qualified_type->getScalarTypeKind();

	clang::TypeInfo FieldInfo = ast_context.getTypeInfo(qualified_type);
	uint64_t size = FieldInfo.Width / 8u;

	c_reflection_type_container* scalar_type_container = nullptr;
	e_reflection_type_class scalar_type_class = _reflection_type_class_int;
	switch (scalar_type_kind)
	{
	case clang::Type::ScalarTypeKind::STK_Bool:
	{
		scalar_type_class = _reflection_type_class_boolean;
		switch (size)
		{
		case 8: scalar_type_container = boolean64_type; break;
		case 4: scalar_type_container = boolean32_type; break;
		case 2: scalar_type_container = boolean16_type; break;
		case 1: scalar_type_container = boolean8_type; break;
		default:scalar_type_container = boolean8_type; break;
		}
	}
	break;
	case clang::Type::ScalarTypeKind::STK_Integral:
	{
		if (qualified_type->isUnsignedIntegerType())
		{
			scalar_type_class = _reflection_type_class_uint;
			switch (size)
			{
			case 8: scalar_type_container = uint64_type; break;
			case 4: scalar_type_container = uint32_type; break;
			case 2: scalar_type_container = uint16_type; break;
			case 1: scalar_type_container = uint8_type; break;
			default:scalar_type_container = uint32_type; break;
			}
		}
		else
		{
			scalar_type_class = _reflection_type_class_int;
			switch (size)
			{
			case 8: scalar_type_container = int64_type; break;
			case 4: scalar_type_container = int32_type; break;
			case 2: scalar_type_container = int16_type; break;
			case 1: scalar_type_container = int8_type; break;
			default:scalar_type_container = int32_type; break;
			}
		}
	}
	break;
	case clang::Type::ScalarTypeKind::STK_Floating:
	{
		scalar_type_class = _reflection_type_class_float;
		switch (size)
		{
		case 8: scalar_type_container = double_type; break;
		case 4: scalar_type_container = float_type; break;
		default:scalar_type_container = float_type; break;
		}
	}
	break;
	case clang::Type::ScalarTypeKind::STK_CPointer:
	case clang::Type::ScalarTypeKind::STK_BlockPointer:
	case clang::Type::ScalarTypeKind::STK_ObjCObjectPointer:
	case clang::Type::ScalarTypeKind::STK_MemberPointer:
	case clang::Type::ScalarTypeKind::STK_IntegralComplex:
	case clang::Type::ScalarTypeKind::STK_FloatingComplex:
	case clang::Type::ScalarTypeKind::STK_FixedPoint:
		break;
	}

	return scalar_type_container;
}

c_reflection_type_container* c_blamlib_compiler_interface::create_reflected_enum(clang::ASTContext& ast_context, const clang::QualType& qualified_type)
{
	ASSERT(qualified_type->isEnumeralType());

	TagDecl* tag_decl = qualified_type->getAsTagDecl();
	const std::string enum_name = tag_decl->getNameAsString();
	const std::string enum_qualified_name = tag_decl->getQualifiedNameAsString();

	for (c_reflection_type_container* type_container : type_containers)
	{
		if (type_container->type_name == enum_name)
		{
			return type_container;
		}
	}

	c_reflection_type_container* enum_type_container = new c_reflection_type_container(_reflection_type_class_enum, enum_name, enum_qualified_name, enum_name, "todo description");

	const clang::EnumDecl* enum_decl = dyn_cast<EnumDecl>(tag_decl);
	ASSERT(enum_decl != nullptr);

	for (const clang::EnumDecl::enumerator_iterator::value_type& enum_decl : enum_decl->enumerators())
	{
		c_reflection_enum_name_container* enum_name_container = new c_reflection_enum_name_container();

		const llvm::APSInt& init_value = enum_decl->getInitVal();
		const uint64_t* raw_data = init_value.getRawData();
		uint64_t raw_value = raw_data ? *raw_data : 0;

		std::string value_name = enum_decl->getNameAsString();

		enum_name_container->value_name = value_name;
		enum_name_container->nice_name = value_name;
		enum_name_container->value = raw_value;

		enum_type_container->enum_name_containers.push_back(enum_name_container);
	}

	type_containers.push_back(enum_type_container);

	return enum_type_container;
}

void c_blamlib_compiler_interface::execute_type_generator()
{

}

void c_blamlib_compiler_interface::execute_source_generator(c_ast_source_generator* source_generator)
{
	source_generator->run(type_containers);
	source_generator->write_output();
}
