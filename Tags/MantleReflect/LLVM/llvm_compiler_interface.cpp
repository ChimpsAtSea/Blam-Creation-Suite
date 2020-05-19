#include "mantlereflect-private-pch.h"

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

LangOptions const c_llvm_compiler_interface::k_clang_language_options;
PrintingPolicy const c_llvm_compiler_interface::k_clang_printing_policy = k_clang_language_options;

c_llvm_compiler_interface::c_llvm_compiler_interface(const char* executable_path, const char* reflection_source_file) :
	executable_path(executable_path),
	reflection_source_file(reflection_source_file)
{

}

c_llvm_compiler_interface::~c_llvm_compiler_interface()
{

}

void c_llvm_compiler_interface::set_source_file(std::string _source_file)
{
	source_file = _source_file;
}

void c_llvm_compiler_interface::add_quote_include_directory(std::string directory)
{
	add_command_line("-iquote");
	add_command_line(directory);
}

void c_llvm_compiler_interface::add_system_include_directory(std::string directory)
{
	add_command_line("-isystem");
	add_command_line(directory);
}

void c_llvm_compiler_interface::add_macro(std::string macro)
{
	add_command_line(std::string("-D") + macro);
}

void c_llvm_compiler_interface::add_command_line(std::string _command_line)
{
	command_line.push_back(_command_line);
}

int c_llvm_compiler_interface::run()
{
	int clang_tool_result = execute_llvm_compiler();
	if (clang_tool_result == 0)
	{
		execute_type_generator();
	}
	return clang_tool_result;
}

int c_llvm_compiler_interface::execute_llvm_compiler()
{
	// llvm/clang things
	llvm::cl::OptionCategory s_tool_category("mantle options");

	FixedCompilationDatabase fixed_compilation_database = FixedCompilationDatabase(".", command_line);

	ClangTool clang_tool = ClangTool(fixed_compilation_database, { source_file });

	int clang_tool_result = clang_tool.run(c_llvm_compile_action::new_compiler_action_factory(*this).get());

	//ASSERT(clang_tool_result == 0);

	return clang_tool_result;
}
