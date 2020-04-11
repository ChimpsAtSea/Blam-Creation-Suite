#pragma once

class c_llvm_class_visitor :
	public clang::RecursiveASTVisitor<c_llvm_class_visitor>
{
public:
	c_llvm_class_visitor() = delete;
	c_llvm_class_visitor(const c_llvm_class_visitor&) = delete;
	c_llvm_class_visitor& operator=(const c_llvm_class_visitor&) = delete;

	explicit c_llvm_class_visitor(clang::ASTContext& ast_context, c_llvm_compiler_interface& compiler_interface);

	bool VisitCXXRecordDecl(clang::CXXRecordDecl* declaration);

private:
	clang::ASTContext& ast_context;
	c_llvm_compiler_interface& compiler_interface;
};
