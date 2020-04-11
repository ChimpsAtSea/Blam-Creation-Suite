#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_llvm_ast_consumer::c_llvm_ast_consumer(clang::ASTContext& ast_context, c_llvm_compiler_interface& compiler_interface) :
	class_visitor(ast_context, compiler_interface),
	compiler_interface(compiler_interface)
{

}

void c_llvm_ast_consumer::HandleTranslationUnit(clang::ASTContext& ast_context)
{
	class_visitor.TraverseDecl(ast_context.getTranslationUnitDecl());
}
