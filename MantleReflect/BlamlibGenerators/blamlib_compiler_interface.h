#pragma once

class c_blamlib_compiler_interface :
	public c_llvm_compiler_interface
{
public:
	c_blamlib_compiler_interface() = delete;
	c_blamlib_compiler_interface(const c_blamlib_compiler_interface&) = delete;
	c_blamlib_compiler_interface& operator=(const c_blamlib_compiler_interface&) = delete;

	c_blamlib_compiler_interface(const char* executable_path, const char* reflection_source_file);
	virtual ~c_blamlib_compiler_interface();

	virtual c_reflection_type_container* create_reflected_type(
		clang::ASTContext* ast_context,
		const clang::QualType* record_qualified_type,
		const clang::RecordDecl& record_declaration,
		bool is_primitive = false) override;
	
protected:
	virtual void execute_type_generator() override;


};

