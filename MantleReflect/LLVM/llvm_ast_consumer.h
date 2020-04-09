#pragma once

class c_llvm_ast_consumer :
	public clang::ASTConsumer
{
public:
	c_llvm_ast_consumer() = delete;
	c_llvm_ast_consumer(const c_llvm_ast_consumer&) = delete;
	c_llvm_ast_consumer& operator=(const c_llvm_ast_consumer&) = delete;

	explicit c_llvm_ast_consumer(clang::ASTContext* ast_context, c_llvm_compiler_interface* compiler_interface);

	virtual void HandleTranslationUnit(clang::ASTContext& ast_context) override;
private:
	c_llvm_class_visitor class_visitor;
	c_llvm_compiler_interface* compiler_interface;
};
