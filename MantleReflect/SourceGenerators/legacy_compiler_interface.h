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

	virtual c_reflection_type_container* create_reflected_type(
		clang::ASTContext& ast_context,
		const clang::QualType* record_qualified_type,
		const clang::RecordDecl& record_declaration,
		bool is_primitive = false) override;

protected:


	c_reflection_type_container* create_reflected_enum_type(const clang::QualType* record_qualified_type, const clang::RecordDecl& record_declaration);
	virtual void execute_type_generator() override;

	static e_primitive_type qualified_type_to_primitive_type(const clang::QualType& _qualifiedType);
	c_reflection_type_container* get_primitive_reflection_type_container(e_primitive_type primitive_type);

	uint32_t init_type_size_and_offsets(c_reflection_type_container& rType);
	void create_nice_type_names(c_reflection_type_container& rType);
	const char* format_nice_name_and_is_hidden_property(e_reflection_type_category reflectionTypeCategory, char* pString, bool* isHiddenByDefault = nullptr);

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
	c_reflection_type_container* bitfield8_type;
	c_reflection_type_container* bitfield16_type;
	c_reflection_type_container* bitfield32_type;
	c_reflection_type_container* bitfield64_type;
	c_reflection_type_container* bitflag8_type;
	c_reflection_type_container* bitflag16_type;
	c_reflection_type_container* bitflag32_type;
	c_reflection_type_container* bitflag64_type;
	c_reflection_type_container* float_type;
	c_reflection_type_container* double_type;
	c_reflection_type_container* enum8_type;
	c_reflection_type_container* enum16_type;
	c_reflection_type_container* enum32_type;
	c_reflection_type_container* enum64_type;
	c_reflection_type_container* undefined8_type;
	c_reflection_type_container* undefined16_type;
	c_reflection_type_container* undefined32_type;
	c_reflection_type_container* undefined64_type;
	c_reflection_type_container* raw_character_array_type;
	c_reflection_type_container* raw_wide_character_array_type;
	c_reflection_type_container* static_string_type;
	c_reflection_type_container* static_wide_string_type;
};

