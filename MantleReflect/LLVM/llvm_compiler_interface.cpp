#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

// llvm/clang things
llvm::cl::OptionCategory c_llvm_compiler_interface::s_mantle_tool_category("mantle options");
LangOptions const c_llvm_compiler_interface::k_clang_language_options;
PrintingPolicy const c_llvm_compiler_interface::k_clang_printing_policy = k_clang_language_options;

c_llvm_compiler_interface::c_llvm_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	reflection_type_containers(),
	ast_source_generators(),
	executable_path(executable_path),
	reflection_source_file(reflection_source_file)
{

}

c_llvm_compiler_interface::~c_llvm_compiler_interface()
{
	for (c_reflection_type_container* pType : reflection_type_containers)
	{
		delete pType;
	}
}

void c_llvm_compiler_interface::register_ast_source_generator(c_ast_source_generator* source_generator)
{
	ast_source_generators.push_back(source_generator);
}

void c_llvm_compiler_interface::run()
{
	execute_llvm_compiler();
	execute_type_generator();
	tbb::parallel_for_each(ast_source_generators.begin(), ast_source_generators.end(), std::bind(&c_llvm_compiler_interface::execute_source_generator, this, std::placeholders::_1));
}

void c_llvm_compiler_interface::execute_llvm_compiler()
{
	const char* argv[] =
	{
		executable_path.c_str(),
		reflection_source_file.c_str()
	};
	int argc = _countof(argv);

	CommonOptionsParser common_options_parser = CommonOptionsParser(argc, argv, s_mantle_tool_category);
	ClangTool clang_tool = ClangTool(common_options_parser.getCompilations(), common_options_parser.getSourcePathList());

	int clang_tool_result = clang_tool.run(c_llvm_compile_action::new_compiler_action_factory(this).get());
	assert(clang_tool_result == 0);
}

void c_llvm_compiler_interface::execute_source_generator(c_ast_source_generator* source_generator)
{
	source_generator->run(reflection_type_containers);
	source_generator->write_output();
}
