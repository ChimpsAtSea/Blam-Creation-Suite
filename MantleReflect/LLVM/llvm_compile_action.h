#pragma once

class c_llvm_compile_action :
	public clang::ASTFrontendAction
{
public:
	static std::unique_ptr<clang::tooling::FrontendActionFactory> new_compiler_action_factory(c_llvm_compiler_interface* llvm_compiler_interface);

protected:
	c_llvm_compile_action() = delete;
	c_llvm_compile_action(const c_llvm_compile_action&) = delete;
	c_llvm_compile_action& operator=(const c_llvm_compile_action&) = delete;

	c_llvm_compile_action(c_llvm_compiler_interface* compiler_interface);

	virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance& compiler, llvm::StringRef file) override;

	c_llvm_compiler_interface* compiler_interface;
};