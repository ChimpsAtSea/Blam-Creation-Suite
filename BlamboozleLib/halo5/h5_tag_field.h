#pragma once

struct s_h5_tag_field_definition
{
	e_h5_field_type field_type;
	const char* name_address;
	void* definition_address;
	uint32_t group_tag;
	uint32_t : 32;
};

struct s_h5_tag_struct_definition
{
	const char* name_address;
	uint32_t group_tag;
	const char* display_name_address;
	uint32_t block_definition_address;
};

struct s_h5_tag_block_definition
{
	const char* display_name_address;
	const char* name_address;
	uint32_t flags;
	uint32_t maximum_element_count;
	void* maximum_element_count_string_address;
	void* field_set_address;
	GUID* guid_address;
};

struct s_h5_tag_block_index_custom_search_definition
{
	void* get_block_procedure;
	void* is_valid_source_block_procedure;
};

struct s_h5_tag_data_definition
{
	const char* definition_name_address;
	uint32_t flags;
	uint32_t alignment_bit;
	uint32_t maximum_size;
	const char* maximum_size_string_address;
	void* byteswap_procedure;
	void* copy_procedure;
};

struct s_h5_tag_reference_definition
{
	uint32_t flags;
	uint32_t group_tag2;
	uint32_t group_tags_address;
};


class c_h5_tag_field
{
public:
	virtual ~c_h5_tag_field() {}
};

enum e_h5_tag_field_validation_check
{
	_h5_tag_field_validation_check_none,
	_h5_tag_field_validation_check_ensure_valid,
	_h5_tag_field_validation_check_ensure_invalid,
};

template<typename T>
class c_h5_tag_field_template :
	public c_h5_tag_field
{
public:
	const s_h5_tag_field_definition* field_definition;
	const char* name;
	const T* definition;

	c_h5_tag_field_template(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition, e_h5_tag_field_validation_check ensure_valid_definition = _h5_tag_field_validation_check_none):
		field_definition(field_definition),
		name(nullptr),
		definition(nullptr)
	{
		if (ensure_valid_definition == _h5_tag_field_validation_check_ensure_valid)
		{
			ASSERT(field_definition != nullptr);
		}
		if (ensure_valid_definition == _h5_tag_field_validation_check_ensure_invalid)
		{
			ASSERT(field_definition == nullptr);
		}
		name = h5_aa_to_pointer(halo5_forge_data, field_definition->name_address);
		definition = reinterpret_cast<const T*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));
	}
};

template<typename T>
struct s_h5_tag_numerical_definition
{
	T min;
	T max;
	T step;
};

using c_h5_tag_field_char_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<int8_t>>;
using c_h5_tag_field_short_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<int16_t>>;
using c_h5_tag_field_long_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<int32_t>>;
using c_h5_tag_field_int64_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<int64_t>>;
using c_h5_tag_field_byte_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<uint8_t>>;
using c_h5_tag_field_word_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<uint16_t>>;
using c_h5_tag_field_dword_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<uint32_t>>;
using c_h5_tag_field_qword_integer = c_h5_tag_field_template<s_h5_tag_numerical_definition<uint64_t>>;
using c_h5_tag_field_real = c_h5_tag_field_template<s_h5_tag_numerical_definition<float>>;

struct s_h5_tag_enum_definition
{
	uint32_t option_count;
	uint32_t options_address;
	uint32_t flags; //?
};



template<typename T>
class c_h5_tag_field_block_index :
	public c_h5_tag_field_template<s_h5_tag_block_index_custom_search_definition>
{
public:
	const s_h5_tag_enum_definition* tag_enum_definition;
	std::vector<const char*> options;

	c_h5_tag_field_block_index(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
		c_h5_tag_field_template(halo5_forge_data, field_definition)
	{

	}

};

class c_h5_tag_field_pad :
	public c_h5_tag_field_template<void>
{
public:
	const uintptr_t&  padding;

	c_h5_tag_field_pad(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
		c_h5_tag_field_template(halo5_forge_data, field_definition),
		padding(*reinterpret_cast<uintptr_t*>(&this->definition))
	{

	}
};

class c_h5_tag_field_skip :
	public c_h5_tag_field_template<void>
{
public:
	const uintptr_t&  length;

	c_h5_tag_field_skip(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
		c_h5_tag_field_template(halo5_forge_data, field_definition),
		length(*reinterpret_cast<uintptr_t*>(&this->definition))
	{

	}
};
