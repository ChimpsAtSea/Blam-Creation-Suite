#include "blamboozle-private-pch.h"

#if defined(_WIN64)
#define uintptr_t uint32_t
#endif

// source material by grimdoomer https://github.com/grimdoomer/Mutation/blob/master/Mutation.HEK/Guerilla/GuerillaReader.cs

struct tag_group
{
	char name[4];
};

static constexpr uintptr_t base_address = 0x400000;
static constexpr uintptr_t tag_layout_table_address = 0x00901B90;
static constexpr uint32_t num_tag_layouts = 120;

// #TODO: More sophistocated addressing using sections
#define va_to_pa(address) (address - base_address)
#define va_to_pointer(data, address) (address ? ((const char*)(data + va_to_pa(address))) : 0)

enum e_h2_field_type : short
{
	_field_string,
	_field_long_string,
	_field_string_id,
	_field_old_string_id,
	_field_char_integer,
	_field_short_integer,
	_field_long_integer,
	_field_angle,
	_field_tag,
	_field_char_enum,
	_field_enum,
	_field_long_enum,
	_field_long_flags,
	_field_word_flags,
	_field_byte_flags,
	_field_point_2d,
	_field_rectangle_2d,
	_field_rgb_color,
	_field_argb_color,
	_field_real,
	_field_real_fraction,
	_field_real_point_2d,
	_field_real_point_3d,
	_field_real_vector_2d,
	_field_real_vector_3d,
	_field_real_quaternion,
	_field_real_euler_angles_2d,
	_field_real_euler_angles_3d,
	_field_real_plane_2d,
	_field_real_plane_3d,
	_field_real_rgb_color,
	_field_real_argb_color,
	_field_real_hsv_color,
	_field_real_ahsv_color,
	_field_short_bounds,
	_field_angle_bounds,
	_field_real_bounds,
	_field_real_fraction_bounds,
	_field_tag_reference,
	_field_block,
	_field_long_block_flags,
	_field_word_block_flags,
	_field_byte_block_flags,
	_field_char_block_index,
	_field_custom_char_block_index,
	_field_short_block_index,
	_field_custom_short_block_index,
	_field_long_block_index,
	_field_custom_long_block_index,
	_field_data,
	_field_vertex_buffer,
	_field_array_start,
	_field_array_end,
	_field_pad,
	_field_useless_pad,
	_field_skip,
	_field_explanation,
	_field_custom,
	_field_struct,
	_field_terminator,

	_field_type_max,
};

struct s_h2_tag_field_definition
{
	e_h2_field_type field_type;
	uint16_t _padding;
	uintptr_t name_address;
	uintptr_t definition_address;
	uint32_t group_tag;
};

class c_h2_tag_field
{
public:
	const char* name;
	const char* definition;

	c_h2_tag_field(const char* guerilla_data, const s_h2_tag_field_definition* field_definition)
	{
		ASSERT(field_definition->_padding == 0);

		name = va_to_pointer(guerilla_data, field_definition->name_address);
		definition = va_to_pointer(guerilla_data, field_definition->definition_address);
	}
};

struct s_h2_tag_reference_definition
{
	uint32_t flags;
	uint32_t group_tag2;
	uintptr_t group_tags_address;
};

class c_h2_tag_field_tag_reference :
	public c_h2_tag_field
{
public:
	const s_h2_tag_reference_definition* tag_reference_definition;

	c_h2_tag_field_tag_reference(const char* guerilla_data, const s_h2_tag_field_definition* field_definition) :
		c_h2_tag_field(guerilla_data, field_definition)
	{
		tag_reference_definition = reinterpret_cast<const s_h2_tag_reference_definition*>(va_to_pointer(guerilla_data, field_definition->definition_address));

	}
};

struct s_h2_tag_struct_definition
{
	uintptr_t name_address;
	uint32_t group_tag;
	uintptr_t display_name_address;
	uintptr_t block_definition_address;
};

class c_h2_tag_field_struct :
	public c_h2_tag_field
{
public:
	const s_h2_tag_struct_definition* tag_struct_definition;

	c_h2_tag_field_struct(const char* guerilla_data, const s_h2_tag_field_definition* field_definition) :
		c_h2_tag_field(guerilla_data, field_definition)
	{
		tag_struct_definition = reinterpret_cast<const s_h2_tag_struct_definition*>(va_to_pointer(guerilla_data, field_definition->definition_address));

	}
};

struct s_h2_tag_data_definition
{
	uintptr_t definition_name_address;
	uint32_t flags;
	uint32_t alignment_bit;
	uint32_t maximum_size;
	uintptr_t maximum_size_string_address;
	uintptr_t byteswap_procedure;
	uintptr_t copy_procedure;
};

class c_h2_tag_field_data :
	public c_h2_tag_field
{
public:
	const s_h2_tag_data_definition* tag_data_definition;
	const char* definition_name;
	const char* maximum_size;

	c_h2_tag_field_data(const char* guerilla_data, const s_h2_tag_field_definition* field_definition) :
		c_h2_tag_field(guerilla_data, field_definition)
	{
		tag_data_definition = reinterpret_cast<const s_h2_tag_data_definition*>(va_to_pointer(guerilla_data, field_definition->definition_address));

		definition_name = va_to_pointer(guerilla_data, tag_data_definition->definition_name_address);
		maximum_size = va_to_pointer(guerilla_data, tag_data_definition->maximum_size_string_address);

	}
};

struct s_h2_tag_enum_definition
{
	uint32_t option_count;
	uintptr_t options_address;
	uint32_t flags; //?
};

class c_h2_tag_field_enum :
	public c_h2_tag_field
{
public:
	const s_h2_tag_enum_definition* tag_enum_definition;
	std::vector<const char*> options;


	c_h2_tag_field_enum(const char* guerilla_data, const s_h2_tag_field_definition* field_definition) :
		c_h2_tag_field(guerilla_data, field_definition)
	{
		tag_enum_definition = reinterpret_cast<const s_h2_tag_enum_definition*>(va_to_pointer(guerilla_data, field_definition->definition_address));

		const uintptr_t* options_strings_address = reinterpret_cast<const uint32_t*>(va_to_pointer(guerilla_data, tag_enum_definition->options_address));
		for (uint32_t option_index = 0; option_index < tag_enum_definition->option_count; option_index++)
		{
			uintptr_t option_string_address = options_strings_address[option_index];
			const char* option = va_to_pointer(guerilla_data, option_string_address);
			options.push_back(option);
			debug_point;
		}
	}
};

struct s_h2_tag_block_index_custom_search_definition
{
	uintptr_t get_block_procedure;
	uintptr_t is_valid_source_block_procedure;
};

class c_h2_tag_field_block_index_custom_search_definition :
	public c_h2_tag_field
{
public:
	const s_h2_tag_block_index_custom_search_definition* tag_block_index_custom_search_definition;

	c_h2_tag_field_block_index_custom_search_definition(const char* guerilla_data, const s_h2_tag_field_definition* field_definition) :
		c_h2_tag_field(guerilla_data, field_definition)
	{
		tag_block_index_custom_search_definition = reinterpret_cast<const s_h2_tag_block_index_custom_search_definition*>(va_to_pointer(guerilla_data, field_definition->definition_address));

	}
};

class c_h2_tag_field_explaination_definition :
	public c_h2_tag_field
{
public:
	const char* explaination;

	c_h2_tag_field_explaination_definition(const char* guerilla_data, const s_h2_tag_field_definition* field_definition) :
		c_h2_tag_field(guerilla_data, field_definition)
	{
		explaination = reinterpret_cast<const char*>(va_to_pointer(guerilla_data, field_definition->definition_address));

	}
};

struct s_h2_tag_field_set_version_header
{
	uintptr_t fields_address;
	uint32_t index;
	uintptr_t upgrade_procedure;
	uint32_t _unknown;
	uint32_t size_of;
};

struct s_h2_byte_swap_definition
{
	uintptr_t name_address;
	uint32_t _unknown0;
	uint32_t _unknown1;
	uint32_t magic;
	uint32_t _unknown2;
	uint32_t _unknown3;
	uint32_t _unknown4;
	uint32_t _unknown5;
	uint32_t _unknown6;
};

struct s_h2_tag_field_set_header
{
	s_h2_tag_field_set_version_header version;
	uint32_t size;
	uint32_t alignment_bit;
	uint32_t parent_version_index;
	uintptr_t fields_address;
	uintptr_t size_string_address;
	s_h2_byte_swap_definition byte_swap_definition;
};
static_assert(sizeof(s_h2_tag_field_set_header) == 76, "s_h2_tag_field_set_header is incorrect size");

class c_h2_tag_field_set
{
public:
	const s_h2_tag_field_definition* fields;
	const char* size_string;
	const char* byte_swap_definition_name;
	std::vector<std::unique_ptr<c_h2_tag_field>> tag_fields;

	c_h2_tag_field_set(const char* guerilla_data, const s_h2_tag_field_set_header* set_header)
	{
		const char* version_fields = va_to_pointer(guerilla_data, set_header->version.fields_address);

		fields = reinterpret_cast<const s_h2_tag_field_definition*>(va_to_pointer(guerilla_data, set_header->fields_address));
		size_string = va_to_pointer(guerilla_data, set_header->size_string_address);

		byte_swap_definition_name = va_to_pointer(guerilla_data, set_header->byte_swap_definition.name_address);

		const s_h2_tag_field_definition* current_field = fields;
		uint32_t field_index = 0;
		do
		{
			c_h2_tag_field* field = nullptr;

			switch (current_field->field_type)
			{
			case _field_tag_reference:
			{
				c_h2_tag_field_tag_reference* struct_field = new c_h2_tag_field_tag_reference(guerilla_data, current_field);
				field = struct_field;
				break;
			}
			case _field_struct:
			{
				c_h2_tag_field_struct* struct_field = new c_h2_tag_field_struct(guerilla_data, current_field);
				field = struct_field;
				break;
			}
			case _field_data:
			{
				c_h2_tag_field_data* data_field = new c_h2_tag_field_data(guerilla_data, current_field);
				field = data_field;
				break;
			}
			case _field_byte_flags:
			case _field_long_flags:
			case _field_word_flags:
			case _field_char_enum:
			case _field_enum:
			case _field_long_enum:
			{
				c_h2_tag_field_enum* enum_field = new c_h2_tag_field_enum(guerilla_data, current_field);
				field = enum_field;
				break;
			}
			case _field_char_block_index:
			case _field_custom_char_block_index:
			case _field_short_block_index:
			case _field_custom_short_block_index:
			case _field_long_block_index:
			case _field_custom_long_block_index:
			{
				c_h2_tag_field_block_index_custom_search_definition* block_index_custom_search_field = new c_h2_tag_field_block_index_custom_search_definition(guerilla_data, current_field);
				field = block_index_custom_search_field;
				break;
			}
			case _field_explanation:
			{
				c_h2_tag_field_explaination_definition* explaination_field = new c_h2_tag_field_explaination_definition(guerilla_data, current_field);
				field = explaination_field;
				break;
			}
			default:
			{
				field = new c_h2_tag_field(guerilla_data, current_field);
				break;
			}
			}
			tag_fields.emplace_back(field);

			current_field++;
			field_index++;
		} while (current_field->field_type != _field_terminator);

	}
};

struct s_h2_tag_block_definition_header
{
	uintptr_t display_name_address;
	uintptr_t name_address;
	uint32_t flags;
	uint32_t maximum_element_count;
	uintptr_t maximum_element_count_string_address;
	uintptr_t field_sets_address;
	uint32_t field_set_count;
	uintptr_t field_set_latest_address;
	uint32_t _unknown;
	uintptr_t postprocess_procedure;
	uintptr_t format_procedure;
	uintptr_t generate_default_procedure;
	uintptr_t dispose_element_procedure;
};

struct s_h2_tag_layout_header
{
	uintptr_t name_address;
	uint32_t flags;
	tag_group group_tag;
	tag_group parent_group_tag;
	uint16_t version;
	uint8_t initialized;
	uint8_t : 8;
	uintptr_t postprocess_procedure;
	uintptr_t save_postprocess_procedure;
	uintptr_t postprocess_for_sync_procedure;
	uint32_t inheritance_flags;
	uintptr_t definition_address;
	tag_group child_group_tags[16];
	uint16_t num_child_group_tags;
	uint16_t : 16;
	uintptr_t default_tag_path_address;
};
static_assert(sizeof(s_h2_tag_layout_header) == 112, "s_h2_tag_layout_header is incorrect size");

class c_h2_tag_block_definition
{
public:
	const char* display_name;
	const char* name;
	std::vector<std::unique_ptr<c_h2_tag_field_set>> tag_field_sets;

	c_h2_tag_block_definition(const char* guerilla_data, const s_h2_tag_block_definition_header* definition_header, const s_h2_tag_layout_header* tag_layout_header = nullptr)
	{
		display_name = va_to_pointer(guerilla_data, definition_header->display_name_address);
		name = va_to_pointer(guerilla_data, definition_header->name_address);
		const char* maximum_element_count_string = va_to_pointer(guerilla_data, definition_header->maximum_element_count_string_address);
		const s_h2_tag_field_set_header* field_sets = reinterpret_cast<const s_h2_tag_field_set_header*>(va_to_pointer(guerilla_data, definition_header->field_sets_address));
		const void* field_set_latest = va_to_pointer(guerilla_data, definition_header->field_set_latest_address);

		bool unsupported_inheritance_flag = tag_layout_header ? !!(tag_layout_header->inheritance_flags & 2) : false;
		debug_point;

		if (!unsupported_inheritance_flag)
		{
			for (uint32_t set_index = 0; set_index < definition_header->field_set_count; set_index++)
			{
				const s_h2_tag_field_set_header* field_set = field_sets + set_index;
				c_h2_tag_field_set* tag_field_set = new c_h2_tag_field_set(guerilla_data, field_sets + set_index);
				tag_field_sets.emplace_back(tag_field_set);
			}
		}
	}
};

std::map<uintptr_t, c_h2_tag_block_definition*> tag_block_definitions;

c_h2_tag_block_definition* get_tag_block_definition(uintptr_t virtual_address)
{
	std::map<uintptr_t, c_h2_tag_block_definition*>::iterator tag_block_definition_iterator = tag_block_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_block_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	return nullptr;
}

class c_h2_tag_layout
{
public:
	const char* name;
	std::unique_ptr<c_h2_tag_block_definition> tag_block_definition;
	c_h2_tag_layout(const char* guerilla_data, const char* tag_layout_data)
	{
		const s_h2_tag_layout_header* layout_header = reinterpret_cast<const s_h2_tag_layout_header*>(tag_layout_data);

		name = va_to_pointer(guerilla_data, layout_header->name_address);
		const char* default_tag_path = va_to_pointer(guerilla_data, layout_header->default_tag_path_address);
		const s_h2_tag_block_definition_header* definition_data = reinterpret_cast<const s_h2_tag_block_definition_header*>(va_to_pointer(guerilla_data, layout_header->definition_address));

		tag_block_definition = std::unique_ptr<c_h2_tag_block_definition>(new c_h2_tag_block_definition(guerilla_data, definition_data, layout_header));
	}
};

c_blamboozle_h2_guerilla::c_blamboozle_h2_guerilla(const wchar_t* _output_directory, const wchar_t* _binary_filepath) :
	c_blamboozle_base(_output_directory, _binary_filepath)
{
	output_directory += L"halo2\\";
}

c_blamboozle_h2_guerilla::~c_blamboozle_h2_guerilla()
{

}

int c_blamboozle_h2_guerilla::run()
{
	char* guerilla_data = nullptr;
	size_t data_size = 0;
	if (!read_file_to_memory(binary_filepath.c_str(), reinterpret_cast<void**>(&guerilla_data), &data_size))
	{
		return 1;
	}
	if (guerilla_data == nullptr || data_size == 0)
	{
		return 1;
	}

	uintptr_t(&layout_addresses)[num_tag_layouts] = *reinterpret_cast<decltype(&layout_addresses)>(guerilla_data + va_to_pa(tag_layout_table_address));

	std::vector<std::unique_ptr<c_h2_tag_layout>> tag_layouts;

	for (uint32_t tag_layout_index = 0; tag_layout_index < num_tag_layouts; tag_layout_index++)
	{
		uint32_t tag_layout_virtual_address = layout_addresses[tag_layout_index];
		const char* tag_layout_data = va_to_pointer(guerilla_data, tag_layout_virtual_address);

		c_h2_tag_layout* tag_layout = new c_h2_tag_layout(guerilla_data, tag_layout_data);
		tag_layouts.emplace_back(tag_layout);
	}

	return 0;
}
