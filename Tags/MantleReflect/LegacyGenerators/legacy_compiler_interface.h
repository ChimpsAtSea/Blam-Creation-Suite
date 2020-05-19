#pragma once

class c_legacy_compiler_interface : 
	public c_llvm_compiler_interface
{
public:
	c_legacy_compiler_interface() = delete;
	c_legacy_compiler_interface(const c_legacy_compiler_interface&) = delete;
	c_legacy_compiler_interface& operator=(const c_legacy_compiler_interface&) = delete;

	c_legacy_compiler_interface(const char* executable_path, const char* reflection_source_file);
	virtual ~c_legacy_compiler_interface();

	void register_ast_source_generator(c_legacy_ast_source_generator* source_generator);

	virtual void create_reflected_type(
		clang::ASTContext& ast_context,
		const clang::QualType* record_qualified_type,
		const clang::RecordDecl& record_declaration,
		bool is_primitive = false) override;

	c_reflection_type_container_legacy* create_reflected_struct(
		clang::ASTContext& ast_context,
		const clang::QualType* record_qualified_type,
		const clang::RecordDecl& record_declaration,
		bool is_primitive = false);

	virtual int run() override;

protected:


	c_reflection_type_container_legacy* create_reflected_enum_type(const clang::QualType* record_qualified_type, const clang::RecordDecl& record_declaration);
	virtual void execute_type_generator() override;

	static e_legacy_primitive_type qualified_type_to_legacy_primitive_type_(const clang::QualType& _qualifiedType);
	c_reflection_type_container_legacy* get_primitive_reflection_type_container(e_legacy_primitive_type primitive_type);

	uint32_t init_type_size_and_offsets(c_reflection_type_container_legacy& rType);
	void create_nice_type_names(c_reflection_type_container_legacy& rType);
	const char* format_nice_name_and_is_hidden_property(e_legacy_reflection_type_category reflectionTypeCategory, char* pString, bool* isHiddenByDefault = nullptr);

	void execute_source_generator(c_legacy_ast_source_generator* source_generator);

	std::vector<c_reflection_type_container_legacy*> reflection_type_containers;
	std::vector<c_legacy_ast_source_generator*> ast_source_generators;

	c_reflection_type_container_legacy* int8_type;
	c_reflection_type_container_legacy* int16_type;
	c_reflection_type_container_legacy* int32_type;
	c_reflection_type_container_legacy* int64_type;
	c_reflection_type_container_legacy* uint8_type;
	c_reflection_type_container_legacy* uint16_type;
	c_reflection_type_container_legacy* uint32_type;
	c_reflection_type_container_legacy* uint64_type;
	c_reflection_type_container_legacy* boolean8_type;
	c_reflection_type_container_legacy* boolean16_type;
	c_reflection_type_container_legacy* boolean32_type;
	c_reflection_type_container_legacy* boolean64_type;
	c_reflection_type_container_legacy* bitfield8_type;
	c_reflection_type_container_legacy* bitfield16_type;
	c_reflection_type_container_legacy* bitfield32_type;
	c_reflection_type_container_legacy* bitfield64_type;
	c_reflection_type_container_legacy* bitflag8_type;
	c_reflection_type_container_legacy* bitflag16_type;
	c_reflection_type_container_legacy* bitflag32_type;
	c_reflection_type_container_legacy* bitflag64_type;
	c_reflection_type_container_legacy* float_type;
	c_reflection_type_container_legacy* double_type;
	c_reflection_type_container_legacy* enum8_type;
	c_reflection_type_container_legacy* enum16_type;
	c_reflection_type_container_legacy* enum32_type;
	c_reflection_type_container_legacy* enum64_type;
	c_reflection_type_container_legacy* undefined8_type;
	c_reflection_type_container_legacy* undefined16_type;
	c_reflection_type_container_legacy* undefined32_type;
	c_reflection_type_container_legacy* undefined64_type;
	c_reflection_type_container_legacy* raw_character_array_type;
	c_reflection_type_container_legacy* raw_wide_character_array_type;
	c_reflection_type_container_legacy* static_string_type;
	c_reflection_type_container_legacy* static_wide_string_type;
};

