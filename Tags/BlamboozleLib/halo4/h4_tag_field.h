#pragma once

class c_h4_tag_struct;


struct s_h4_tag_field_definition
{
	bigendian_type<e_h4_field_type> field_type;
	typed_bptr32<const char*> name_address;
	typed_bptr32<void*> definition_address;
	bulong tool_tag;
};

struct s_h4_tag_block_definition
{
	typed_bptr32<const char*> display_name;
	typed_bptr32<const char*> name;
	bulong maximum_element_count;
	typed_bptr32<const char*> maximum_element_count_string;
	typed_bptr32<s_h4_tag_struct_definition*> struct_definition;
};


class c_h4_tag_field
{
public:
	c_h4_tag_field(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		field_type(field_definition->field_type),
		field_definition(field_definition),
		name(h4_va_to_pointer(h4_data, field_definition->name_address)),
		raw(field_definition->definition_address.value()),
		tool_tag(field_definition->tool_tag)
	{

	}
	virtual ~c_h4_tag_field() {}

public:
	e_h4_field_type field_type;
	const char* name;
	const unsigned long raw;
	const unsigned long tool_tag;

protected:
	const s_h4_tag_field_definition* field_definition;
};

enum e_h4_tag_field_validation_check
{
	_h4_tag_field_validation_check_none,
	_h4_tag_field_validation_check_ensure_valid,
	_h4_tag_field_validation_check_ensure_invalid,
};

template<typename T>
class t_h4_tag_field :
	public c_h4_tag_field
{
public:

	t_h4_tag_field(const char* h4_data, const s_h4_tag_field_definition* field_definition, e_h4_tag_field_validation_check ensure_valid_definition = _h4_tag_field_validation_check_none) :
		c_h4_tag_field(h4_data, field_definition),
		definition(reinterpret_cast<const T*>(h4_va_to_pointer(h4_data, field_definition->definition_address.value())))
	{
		if (ensure_valid_definition == _h4_tag_field_validation_check_ensure_valid)
		{
			ASSERT(definition != nullptr);
		}
		if (ensure_valid_definition == _h4_tag_field_validation_check_ensure_invalid)
		{
			ASSERT(definition == nullptr);
		}
	}

	const T* definition;
};

template<typename T>
struct t_h4_tag_numerical_definition
{
	T min;
	T max;
	T step;
};

using c_h4_tag_field_char_integer = t_h4_tag_field<t_h4_tag_numerical_definition<char>>;
using c_h4_tag_field_short_integer = t_h4_tag_field<t_h4_tag_numerical_definition<short>>;
using c_h4_tag_field_long_integer = t_h4_tag_field<t_h4_tag_numerical_definition<long>>;
using c_h4_tag_field_int64_integer = t_h4_tag_field<t_h4_tag_numerical_definition<int64_t>>;
using c_h4_tag_field_byte_integer = t_h4_tag_field<t_h4_tag_numerical_definition<unsigned char>>;
using c_h4_tag_field_word_integer = t_h4_tag_field<t_h4_tag_numerical_definition<unsigned short>>;
using c_h4_tag_field_dword_integer = t_h4_tag_field<t_h4_tag_numerical_definition<unsigned long>>;
using c_h4_tag_field_qword_integer = t_h4_tag_field<t_h4_tag_numerical_definition<uint64_t>>;
using c_h4_tag_field_real = t_h4_tag_field<t_h4_tag_numerical_definition<float>>;
using c_h4_tag_field_explanation = t_h4_tag_field<const char>;

struct s_h4_tag_enum_definition
{
	typed_bptr32<const char*> name;
	bulong option_count;
	typed_bptr32<typed_bptr32<const char*>*> options;
	typed_bptr32<const char*> filepath;
	bulong line_number;
};

struct s_h4_tag_reference_definition
{
	bulong flags;
	bulong group_tag;
	typed_bptr32<bulong*> group_tags_address;
};

class c_h4_tag_field_tag_reference :
	public t_h4_tag_field<s_h4_tag_reference_definition>
{
public:
	c_h4_tag_reference* const reference;
	c_h4_tag_field_tag_reference(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition),
		reference(c_h4_blamboozle::get_tag_reference_definition(h4_data, definition, field_definition->definition_address.value()))
	{
		unsigned long definition_address = field_definition->definition_address.value();
		unsigned long group_tags_address = this->definition->group_tags_address.value();

		
	}
};

struct s_h4_tag_data_definition
{
	typed_bptr32<const char*> definition_name_address;
	unsigned long flags;
	unsigned long alignment_bit;
	unsigned long maximum_size;
	typed_bptr32<const char*> maximum_size_string_address;
	typed_bptr32<void*> byteswap_procedure;
	typed_bptr32<void*> copy_procedure;
	unsigned long : 32; // unknown
	unsigned long : 32; // unknown
	unsigned long : 32; // unknown
};

class c_h4_tag_field_data :
	public t_h4_tag_field<s_h4_tag_data_definition>
{
public:
	c_h4_tag_field_data(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid)
	{
		unsigned long definition_address = field_definition->definition_address.value();

		if (definition)
		{
			const char* definition_name = h4_va_to_pointer(h4_data, definition->definition_name_address);
			console_write_line("found data for field '%s' called '%s'", name, definition_name);
		}
	}
};

class c_h4_tag_field_struct :
	public t_h4_tag_field<s_h4_tag_struct_definition>
{
public:
	c_h4_tag_struct* tag_struct;

	c_h4_tag_field_struct(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, definition, field_definition->definition_address.value()))
	{
		unsigned long definition_address = field_definition->definition_address.value();
		const char* field_set_display_name = h4_va_to_pointer(h4_data, definition->pretty_name);
		const char* field_set_name = h4_va_to_pointer(h4_data, definition->name);

		
	}
};

class c_h4_tag_field_block :
	public t_h4_tag_field<s_h4_tag_block_definition>
{
public:
	c_h4_tag_block* tag_block_definition;

	c_h4_tag_field_block(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_block_definition(c_h4_blamboozle::get_tag_block_definition(h4_data, definition, nullptr))
	{
		unsigned long definition_address = field_definition->definition_address.value();

		
	}
};

class c_h4_tag_field_enum :
	public t_h4_tag_field<s_h4_tag_enum_definition>
{
public:
	c_h4_tag_enum* tag_enum;

	c_h4_tag_field_enum(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_enum(c_h4_blamboozle::get_tag_enum_definition(h4_data, definition))
	{
		unsigned long definition_address = field_definition->definition_address.value();

		
	}
};

struct s_h4_block_index_custom_search_definition
{
	typed_bptr32<const char*> name_address;
	typed_bptr32<void*> get_block_procedure;
	typed_bptr32<void*> is_valid_source_block_procedure;
};

class c_h4_tag_field_custom_block_index :
	public t_h4_tag_field<s_h4_block_index_custom_search_definition>
{
public:
	const char* name;

	c_h4_tag_field_custom_block_index(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid)
	{
		unsigned long definition_address = field_definition->definition_address.value();

		name = h4_va_to_pointer(h4_data, definition->name_address);

		
	}
};

class c_h4_tag_field_pad :
	public t_h4_tag_field<void>
{
public:
	unsigned long const padding;

	c_h4_tag_field_pad(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition),
		padding(field_definition->definition_address.value())
	{

	}
};

class c_h4_tag_field_skip :
	public t_h4_tag_field<void>
{
public:
	unsigned long const length;

	c_h4_tag_field_skip(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition),
		length(field_definition->definition_address.value())
	{

	}
};

struct s_h4_tag_array_definition
{
	typed_bptr32<const char*> name;
	bulong element_count;
	typed_bptr32<const char*> element_count_string;
	typed_bptr32<s_h4_tag_struct_definition*> struct_definition;
};

class c_h4_tag_field_array :
	public t_h4_tag_field<s_h4_tag_array_definition>
{
public:
	const char* const name;
	unsigned long const count;
	const char* const count_string;
protected:
	const s_h4_tag_struct_definition* struct_definition;
public:
	c_h4_tag_struct* tag_struct_definition;
	c_h4_tag_array* tag_array_definition;

	c_h4_tag_field_array(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		name(h4_va_to_pointer(h4_data, definition->name)),
		count(definition->element_count),
		count_string(h4_va_to_pointer(h4_data, definition->element_count_string)),
		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition.value())),
		tag_struct_definition(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition.value())),
		tag_array_definition(c_h4_blamboozle::get_tag_array_definition(h4_data, definition))
	{
		unsigned long definition_address = field_definition->definition_address.value();
		unsigned long struct_definition_address = definition->struct_definition.value();

		
	}
};

class c_h4_tag_field_string :
	public t_h4_tag_field<void>
{
public:

	c_h4_tag_field_string(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_invalid)
	{
		unsigned long definition_address = field_definition->definition_address.value();

		
	}
};

class c_h4_tag_field_string_id :
	public t_h4_tag_field<void>
{
public:

	c_h4_tag_field_string_id(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_invalid)
	{
		unsigned long definition_address = field_definition->definition_address.value();

		
	}
};

enum e_tag_resource_type
{
	_tag_resource_type_sound = 2,
	_tag_resource_type_bitmap = 4,
};

struct s_h4_tag_resource_definition
{
	typed_bptr32<const char*> name;
	bigendian_type<e_tag_resource_type> resource_type;
	typed_bptr32<s_h4_tag_struct_definition*> struct_definition;
	typed_bptr32<void*> tag_resource_vtable; // c_tag_resource_vtable<c_sound_resource_vtable>
	bulong unknown0;
	typed_bptr32<const char*> filepath;
	bulong count;
	bulong unknown1;
	bulong unknown2;
};

class c_h4_tag_resource_definition :
	public t_h4_tag_field<s_h4_tag_resource_definition>
{
public:
	const char* const name;
	e_tag_resource_type const resource_type;
	const s_h4_tag_struct_definition* const struct_definition;
	const void* const tag_resource_vtable;
	bulong const unknown0;
	const char* const filepath;
	bulong const count;
	bulong const unknown1;
	bulong const unknown2;

	c_h4_tag_struct* tag_struct;
	c_h4_tag_resource* tag_resource_definition;

	c_h4_tag_resource_definition(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		name(h4_va_to_pointer(h4_data, definition->name)),
		resource_type(definition->resource_type),
		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition.value())),
		tag_resource_vtable(h4_va_to_pointer<void>(h4_data, definition->struct_definition.value())),
		unknown0(definition->unknown0),
		filepath(h4_va_to_pointer(h4_data, definition->filepath)),
		count(definition->count),
		unknown1(definition->unknown1),
		unknown2(definition->unknown2),
		tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition.value())),
		tag_resource_definition(c_h4_blamboozle::get_tag_resource_definition(h4_data, definition))
	{
		unsigned long definition_address = field_definition->definition_address.value();

		ASSERT(unknown0 == 0);
		//ASSERT(unknown1 == 0);
		//ASSERT(unknown2 == 0);

		
	}
};

struct s_h4_tag_interop_definition
{
	GUID guid;
	typed_bptr32<s_h4_tag_struct_definition*> struct_definition;
	typed_bptr32<void*> interop_vtable; // c_tag_d3d_interop_vtable
	typed_bptr32<const char*> name;
	bulong unknown;
};

class c_h4_tag_interop_definition :
	public t_h4_tag_field<s_h4_tag_interop_definition>
{
public:
	c_h4_tag_interop* tag_interop_definition;

	c_h4_tag_interop_definition(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
		tag_interop_definition(c_h4_blamboozle::get_tag_interop_definition(h4_data, definition))
	{
		unsigned long definition_address = field_definition->definition_address.value();


	}
};
//
//class c_h4_tag_interop_definition :
//	public t_h4_tag_field<s_h4_tag_interop_definition>
//{
//public:
//	GUID const guid;
//protected:
//	const s_h4_tag_struct_definition* const struct_definition;
//public:
//	const char* name;
//	unsigned long unknown;
//	c_h4_tag_struct* tag_struct;
//
//	c_h4_tag_interop_definition(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
//		t_h4_tag_field(h4_data, field_definition, _h4_tag_field_validation_check_ensure_valid),
//		guid(definition->guid),
//		struct_definition(h4_va_to_pointer<s_h4_tag_struct_definition>(h4_data, definition->struct_definition.value())),
//		name(h4_va_to_pointer(h4_data, definition->name)),
//		unknown(definition->unknown),
//		tag_struct(c_h4_blamboozle::get_tag_struct_definition(h4_data, struct_definition, definition->struct_definition.value()))
//	{
//		unsigned long definition_address = field_definition->definition_address.value();
//
//		
//	}
//};

struct s_tag_custom_tool_data_definition;
class c_h4_tag_field_custom :
	public t_h4_tag_field<s_tag_custom_tool_data_definition>
{
public:
	c_h4_tag_field_custom(const char* h4_data, const s_h4_tag_field_definition* field_definition) :
		t_h4_tag_field(h4_data, field_definition)
	{
		unsigned long definition_address = field_definition->definition_address.value();

		
	}
};