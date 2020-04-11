#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_llvm_class_visitor::c_llvm_class_visitor(clang::ASTContext& ast_context, c_llvm_compiler_interface& compiler_interface) :
	ast_context(ast_context),
	compiler_interface(compiler_interface)
{

}

bool c_llvm_class_visitor::VisitCXXRecordDecl(CXXRecordDecl* cxx_record_declaration)
{
	compiler_interface.create_reflected_type(ast_context, nullptr, *cxx_record_declaration);

	return true;
}
