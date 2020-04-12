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

	void register_ast_source_generator(c_ast_source_generator* source_generator);

	virtual void create_reflected_type(
		clang::ASTContext& ast_context,
		const clang::QualType* record_qualified_type,
		const clang::RecordDecl& record_declaration,
		bool is_primitive = false) override;

	virtual int run() override;
	
protected:
	virtual void execute_type_generator() override;
	void execute_source_generator(c_ast_source_generator* source_generator);

	c_reflection_type_container* create_reflected_struct(
		clang::ASTContext& ast_context,
		const clang::QualType* record_qualified_type,
		const clang::RecordDecl& record_declaration,
		bool is_primitive = false);

	c_reflection_type_container* get_reflected_scalar(
		clang::ASTContext& ast_context,
		const clang::QualType& qualified_type);

	c_reflection_type_container* create_reflected_enum(
		clang::ASTContext& ast_context,
		const clang::QualType& qualified_type);

	std::vector<c_ast_source_generator*> ast_source_generators;
	std::vector<c_reflection_type_container*> type_containers;
	
	c_reflection_type_container* int8_type;
	c_reflection_type_container* int16_type;
	c_reflection_type_container* int32_type;
	c_reflection_type_container* int64_type;
	c_reflection_type_container* uint8_type;
	c_reflection_type_container* uint16_type;
	c_reflection_type_container* uint32_type;
	c_reflection_type_container* uint64_type;
	c_reflection_type_container* boolean8_type;
	c_reflection_type_container* boolean16_type;
	c_reflection_type_container* boolean32_type;
	c_reflection_type_container* boolean64_type;
	c_reflection_type_container* float_type;
	c_reflection_type_container* double_type;
	c_reflection_type_container* undefined8_type;
	c_reflection_type_container* undefined16_type;
	c_reflection_type_container* undefined32_type;
	c_reflection_type_container* undefined64_type;
	c_reflection_type_container* static_string_type;
	c_reflection_type_container* static_wide_string_type;

};

