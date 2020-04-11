#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_blamlib_compiler_interface::c_blamlib_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	c_llvm_compiler_interface(executable_path, reflection_source_file)
{

}

c_blamlib_compiler_interface::~c_blamlib_compiler_interface()
{

}

c_reflection_type_container* c_blamlib_compiler_interface::create_reflected_type(
	clang::ASTContext& ast_context, 
	const clang::QualType* record_qualified_type, 
	const clang::RecordDecl& record_declaration, 
	bool is_primitive)
{
	SourceManager& source_manager = ast_context.getSourceManager();

	std::string declaration_name = record_declaration.getNameAsString();

	if (strncmp(declaration_name.c_str(), "s_", 2) == 0)
	{
		printf("blamlib_compiler_interface> '%s'\n", declaration_name.c_str());

		RecordDecl::field_range structure_fields = record_declaration.fields();

		bool has_fields = structure_fields.end() != structure_fields.begin();
		printf("blamlib_compiler_interface> {\n");
		for (FieldDecl* field : structure_fields)
		{
			comments::FullComment* full_comment = ast_context.getCommentForDecl(field, nullptr);
			//const RawComment* raw_comment = ast_context.getRawCommentForDeclNoCache(&record_declaration);
			const std::string field_name = field->getNameAsString();

			//if (raw_comment)
			if(full_comment)
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

	}
	else
	{
		printf("blamlib_compiler_interface> skipping '%s'\n", declaration_name.c_str());
	}

	return nullptr;
}

void c_blamlib_compiler_interface::execute_type_generator()
{

}
