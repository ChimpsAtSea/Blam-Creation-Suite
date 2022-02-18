#pragma once

class c_reach_x360_tag_struct_definition;
class c_reach_x360_tag_group_definition;

enum e_reach_tag_memory_allocation_type
{
	_reach_tag_memory_default,
	_reach_tag_memory_node,
	k_num_reach_tag_memory_type
};

enum e_reach_tag_memory_usage_bit
{
	_reach_tag_memory_physical_bit,
	_reach_tag_memory_unknown1_bit,
	_reach_tag_memory_unknown2_bit,
	_reach_tag_memory_writeable_bit,
	_reach_tag_memory_combined_bit,
	_reach_tag_memory_streaming_bit,
	_reach_tag_memory_non_aliased_bit,
	k_num_reach_tag_memory_usage_bits
};

//bulong __fastcall s_tag_struct_definition::is_built_from_disk(s_tag_struct_definition* this)
//{
//	return (this->runtime_flags >> 6) & 1;
//}

enum e_reach_tag_field_set_bit : unsigned long
{
	_reach_tag_field_set_unknown0,
	_reach_tag_field_set_unknown1,
	_reach_tag_field_set_has_inlined_children_with_placement_new_bit, // confirmed
	_reach_tag_field_set_unknown3,
	_reach_tag_field_set_unknown4,
	_reach_tag_field_set_unknown5,
	_reach_tag_field_set_is_temporary_bit, // confirmed
	_reach_tag_field_set_unknown7,
	_reach_tag_field_set_unknown8,
	_reach_tag_field_set_delete_recursively_bit, // confirmed
	_reach_tag_field_set_postprocess_recursively_bit, // confirmed
	_reach_tag_field_set_is_memcpyable_bit, // confirmed
	_reach_tag_field_set_unknown12,
	_reach_tag_field_set_has_resources,
	_reach_tag_field_set_unknown14,
	_reach_tag_field_set_unknown15,
	_reach_tag_field_set_has_level_specific_fields_bit, // confirmed
	_reach_tag_field_set_can_memset_to_initialize_bit, // confirmed
	_reach_tag_field_set_unknown18,
	_reach_tag_field_set_unknown19,
	k_num_reach_runtime_flags
};

struct s_reach_tag_memory_attributes
{
	c_enum<e_reach_tag_memory_allocation_type, unsigned long, _reach_tag_memory_default, k_num_reach_tag_memory_type> memory_type;
	c_flags<e_reach_tag_memory_usage_bit, unsigned long, k_num_reach_tag_memory_usage_bits> usage_flags;
};

struct s_reach_x360_byte_swap_definition
{
	bptr32 name;
	unsigned long size;
	bptr32 byte_swap_traits;
	bptr32 filepath;
	unsigned long line;
	unsigned long signature;
	unsigned long unknown14;
};

struct s_reach_x360_tag_struct_runtime
{
	ptr32 original_fields;																									//104				68
	s_reach_x360_byte_swap_definition byte_swap_definition;																	//108				6C
	unsigned long structure_size;																							//136				88
	unsigned long flags;																									//140				8C
	ptr32 combined_fields;																									//144				90
	unsigned long cache_file_struct_size;																					//148				94
	unsigned long unknown98;																								//152				98
	unsigned long unknown9C;																								//156				9C
	unsigned long unknownA0;																								//160				A0
	unsigned long unique_index;																								//164				A4
	c_big_flags_typed<long, k_num_reach_x360_field_types> inlined_field_types;												//168				A8
	c_big_flags_typed<long, k_num_reach_x360_field_types> unknown_field_types;												//176				B0
	ptr32 descendent_definition;																							//184				B8
};

struct s_reach_x360_tag_struct_legacy
{
	unsigned long legacy_struct_tag;																						//48				30
	unsigned long unknown34;																								//52				34
	unsigned long unknown37;																								//56				38
	unsigned long legacy_version;																							//60				3C
	ptr32 unknown40; // s_tag_struct_definition																				//64				40
	unsigned long unknown44;																								//68				44
	ptr32 legacy_struct;																									//72				48
	bool is_legacy_field_set;																								//76				4C
	bool padding4D;																											//77				4D
	bool padding4E;																											//78				4E
	bool padding4F;																											//79				4F
};

struct s_reach_x360_tag_struct_type
{
	ptr32 pretty_name_address;																								//0					0
	ptr32 name_address;																										//4					4
	ptr32 filepath_address;																									//8					8
	long line_number;																										//12				C
	blofeld::s_tag_persistent_identifier persistent_identifier;																//16				10
	ptr32 fields_address;																									//32				20
	unsigned long structure_size;																							//36				24
	ptr32 size_string_address; // not included in release build																//40				28
	unsigned long alignment_bits;																							//44				2C
	s_reach_x360_tag_struct_legacy legacy;																					//48				30
};

struct s_reach_x360_tag_struct_definition
{
	s_reach_x360_tag_struct_type type;																						//0					0
	ptr32 struct_vtable;																									//80				50
	unsigned long unknown54;																								//84				54
	unsigned long exploded_struct_size;																						//88				58
	unsigned long unknown5C;																								//92				5C
	s_reach_tag_memory_attributes memory_attributes;																				//96				60
	s_reach_x360_tag_struct_runtime runtime;																				//104				68
	unsigned long unknownBC;																								//104				BC
};
constexpr size_t k_reach_x360_tag_struct_definition_size = sizeof(s_reach_x360_tag_struct_definition);
static_assert(k_reach_x360_tag_struct_definition_size == 0xC0);







class c_reach_x360_tag_struct_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string code_name;
	unsigned long structure_size;
	unsigned long alignment_bits;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	std::vector<s_reach_x360_tag_struct_definition> struct_definitions;
	std::vector<c_reach_x360_tag_field*> fields;

	c_reach_x360_tag_struct_definition(const char* guerilla_data, const s_reach_x360_tag_struct_definition& definition_header);
	~c_reach_x360_tag_struct_definition();

	void handle_conflict(const char* guerilla_data, const s_reach_x360_tag_struct_definition& definition_header);

	static std::map<ptr32, c_reach_x360_tag_struct_definition*> tag_struct_definitions;
	static c_reach_x360_tag_struct_definition* reach_x360_get_tag_struct_definition(const char* guerilla_data, ptr32 virtual_address);
	static c_reach_x360_tag_struct_definition* reach_x360_find_tag_struct_definition_by_persistent_id(blofeld::s_tag_persistent_identifier persistent_identifier);
};

