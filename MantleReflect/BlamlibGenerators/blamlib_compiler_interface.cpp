#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_blamlib_compiler_interface::c_blamlib_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	c_llvm_compiler_interface(executable_path, reflection_source_file),
	ast_source_generators(),
	type_containers()
{

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

	c_reflection_type_container* type_container = new c_reflection_type_container();
	type_containers.push_back(type_container);
	type_container->type_class = is_union ? _reflection_type_class_union : _reflection_type_class_structure;
	type_container->type_name = type_name;
	type_container->nice_name = type_name;
	type_container->qualified_name = qualified_name;
	
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


		bool is_field_scalar = field_type->isScalarType();
		bool is_field_enum = field_type->isEnumeralType();
		bool is_field_class = field_type->isClassType();
		bool is_field_struct = field_type->isStructureType();
		bool is_field_union = field_type->isUnionType();
		bool is_field_object = is_field_struct || is_field_class || is_field_union;

		if (is_field_object)
		{
			field_record_declaration = field_qualified_type->getAsRecordDecl();
			field_class_template_specialization_decl = dyn_cast<const clang::ClassTemplateSpecializationDecl>(field_record_declaration);
			ASSERT(field_record_declaration != nullptr);
		}

		bool is_anonymous = is_field_object && field_record_declaration->isAnonymousStructOrUnion();
		bool is_field_template = field_class_template_specialization_decl != nullptr;
		bool is_field_custom_enum = is_field_template && field_qualified_type_name == "c_enum";
		bool is_field_tag_block = is_field_template && field_qualified_type_name == "c_typed_tag_block";
		bool is_field_recognised_template = is_field_custom_enum || is_field_tag_block;

		if (is_field_template && !is_field_recognised_template)
		{
			continue; // #TODO: Figure out how to support lots of templated types
			ASSERT(is_field_recognised_template);
		}

		c_reflection_field_container* field_container = new c_reflection_field_container();
		type_container->field_containers.push_back(field_container);
		field_container->field_name = field_name;
		field_container->nice_name = field_name;

		if (is_anonymous) // process these fields in place
		{

		}
		else if (is_field_object)
		{
			TagDecl* tag_decl = field_qualified_type->getAsTagDecl();
			clang::RecordDecl* record_decl = static_cast<clang::RecordDecl*>(tag_decl);
			std::string name = tag_decl->getNameAsString();

			create_reflected_type(ast_context, &field_qualified_type, *record_decl);
		}
		else if (is_field_enum)
		{
			printf("");
		}
		else if (is_field_scalar)
		{
			const clang::Type::ScalarTypeKind scalar_type_kind = field_type->getScalarTypeKind();

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

void c_blamlib_compiler_interface::execute_type_generator()
{

}

void c_blamlib_compiler_interface::execute_source_generator(c_ast_source_generator* source_generator)
{
	source_generator->run(type_containers);
	source_generator->write_output();
}
