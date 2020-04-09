#include "mantlereflect-private-pch.h"

c_blamlib_compiler_interface::c_blamlib_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	c_llvm_compiler_interface(executable_path, reflection_source_file)
{

}

c_blamlib_compiler_interface::~c_blamlib_compiler_interface()
{

}

c_reflection_type_container* c_blamlib_compiler_interface::create_reflected_type(
	clang::ASTContext* ast_context, 
	const clang::QualType* record_qualified_type, 
	const clang::RecordDecl& record_declaration, 
	bool is_primitive)
{
	std::string declaration_name = record_declaration.getNameAsString();
	printf("blamlib_compiler_interface> '%s'\n", declaration_name.c_str());

	return nullptr;
}

void c_blamlib_compiler_interface::execute_type_generator()
{

}
