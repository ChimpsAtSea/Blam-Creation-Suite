#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

c_llvm_compile_action::c_llvm_compile_action(c_llvm_compiler_interface& compiler_interface) :
	compiler_interface(compiler_interface)
{

}

std::unique_ptr<ASTConsumer> c_llvm_compile_action::CreateASTConsumer(CompilerInstance& compiler, llvm::StringRef file)
{
	Preprocessor& preprocessor = compiler.getPreprocessor();
	const clang::LangOptions& const_language_options = preprocessor.getLangOpts();
	clang::LangOptions& language_options = const_cast<clang::LangOptions&>(const_language_options);
	language_options.RetainCommentsFromSystemHeaders = 1;

	c_llvm_ast_consumer* ast_consumer = new c_llvm_ast_consumer(compiler.getASTContext(), compiler_interface);
	return std::unique_ptr<ASTConsumer>(ast_consumer);
}

std::unique_ptr<FrontendActionFactory> c_llvm_compile_action::new_compiler_action_factory(c_llvm_compiler_interface& llvm_compiler_interface)
{
	class c_llvm_compile_action_factory : public FrontendActionFactory
	{
	public:
		c_llvm_compile_action_factory(c_llvm_compiler_interface& llvm_compiler_interface) :
			llvm_compiler_interface(llvm_compiler_interface)
		{

		}
		c_llvm_compiler_interface& llvm_compiler_interface;

		std::unique_ptr<FrontendAction> create() override
		{
			return std::unique_ptr<FrontendAction>(new c_llvm_compile_action(llvm_compiler_interface));
		}
	};

	return std::unique_ptr<FrontendActionFactory>(new c_llvm_compile_action_factory(llvm_compiler_interface));
}