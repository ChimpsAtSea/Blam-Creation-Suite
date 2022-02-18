#pragma once

struct s_infinite_ucs_header
{
	long magic;								// 'hscu' (UCSH = "Universal Cache Storage Header" ? )
	long version;							// 27 (0x1B)
	unsigned long long unknown8;
	unsigned long long asset_checksum;		// Murmur3_x64_128 hash of(what appears to be) the original file that this file was built from.This is not always the same thing as the file stored in the module.
	//long unknown18;
	unsigned long tag_dependency_count;		// Number of tag dependencies
	unsigned long nugget_count;				// Number of data blocks
	unsigned long tag_block_count;			// Number of tag structs
	unsigned long data_reference_count;		// Number of data references
	unsigned long tag_reference_count;		// Number of tag references
	//long string_id_count;					// Number of string_ids
	unsigned long string_table_size;		// String table size in bytes
	unsigned long zoneset_data_size;		// Zoneset data size in bytes
	long unknown19;
	unsigned long header_size;				// Header size in bytes
	unsigned long data_size;				// Tag data size in bytes
	unsigned long resource_data_size;		// Resource data size in bytes
	long unknown18;
	unsigned char header_alignment;			// Power of 2 to align the header buffer to(e.g. 4 = align to a multiple of 16 bytes).
	unsigned char tag_data_alignment;		// Power of 2 to align the tag data buffer to.
	unsigned char resource_data;			// Alignment	Power of 2 to align the resource data buffer to.
	unsigned char unknown4B;
	long unknown4C;
};
static constexpr size_t k_infinite_ucs_header_size = sizeof(s_infinite_ucs_header);
static_assert(k_infinite_ucs_header_size == 0x50);

struct s_infinite_ucs_tag_dependency_list
{
	tag group_tag;					// Group tag(e.g. 'proj').
	unsigned long name_offset;		// Offset of the tag filename in the String Table.
	unsigned long long asset_id;	// Asset ID of the tag.
	long global_id;					// Global ID of the tag.
	long unknown14;					// (Haven't seen this be anything other than -1 yet)
};
static constexpr size_t k_infinite_ucs_tag_dependency_list_size = sizeof(s_infinite_ucs_tag_dependency_list);
static_assert(k_infinite_ucs_tag_dependency_list_size == 0x18);

enum e_infinite_ucs_data_block_section
{
	_infinite_ucs_data_block_section_header,
	_infinite_ucs_data_block_section_tag_data,
	_infinite_ucs_data_block_section_resource_data,
};

struct s_infinite_ucs_nugget
{
	unsigned long size; // The size of the data block in bytes.
	short unknown4; // (0 - 14, probably an enum)
	c_enum<e_infinite_ucs_data_block_section, short> section; // 0 = Header, 1 = Tag Data, 2 = Resource Data
	unsigned long long offset; // The offset of the start of the data block, relative to the start of its section.
};
static constexpr size_t k_infinite_ucs_data_block_list_size = sizeof(s_infinite_ucs_nugget);
static_assert(k_infinite_ucs_data_block_list_size == 0x10);

enum e_infinite_ucs_tag_block_type
{
	_infinite_ucs_tag_block_type_tag_group,
	_infinite_ucs_tag_block_type_tag_block,
	_infinite_ucs_tag_block_type_resource,
	_infinite_ucs_tag_block_type_custom,
};

struct s_infinite_ucs_tag_block_data
{
	blofeld::s_tag_persistent_identifier persistent_identifier; // This is used to write in a static pointer to type info located in the.rdata section of the executable. (At load time, the first 8 bytes of this are replaced with the type info pointer for efficiency reasons.)
	c_enum<e_infinite_ucs_tag_block_type, short> type;			// 0 = Main Struct, 1 = Tag Block, 2 = Resource, 3 = Custom
	short unknown12;											// (May be padding, but haven't confirmed this)
	long nugget_index;											// For Main Struct and Tag Block structs, the index of the block containing the struct.For Resource structs, this (probably)is the index of the resource.This can be - 1 if the tag field doesn't point to anything (null Tag Blocks or Custom structs).
	long owner_block_index;										// The offset of the tag field inside the data block. (Unlike in Halo Online, this points to the tag field, not the pointer inside the tag field.Some tag fields for structs don't even have a pointer.)
	long owner_block_offset;									// The index of the data block containing the tag field which refers to this struct.Can be - 1 for the Main Struct.
};
static constexpr size_t k_infinite_ucs_tag_struct_list_size = sizeof(s_infinite_ucs_tag_block_data);
static_assert(k_infinite_ucs_tag_struct_list_size == 0x20);

struct s_infinite_ucs_data_reference_list
{
	long parent_tag_block_index;		//The index of the tag struct containing the tag field. (See the Tag Struct List file section.)
	long unknown4;						
	long nugget_index;					//The index of the data block containing the referenced data.Can be - 1 for null references.
	long owner_block_index;				//The index of the data block containing the tag field.
	unsigned long owner_block_offset;	//The offset of the tag field inside the data block.
};
static constexpr size_t k_infinite_ucs_data_reference_list_size = sizeof(s_infinite_ucs_data_reference_list);
static_assert(k_infinite_ucs_data_reference_list_size == 0x14);

struct s_infinite_ucs_tag_reference_list
{
	long fieldBlock;				// The index of the data block containing the tag field.
	unsigned long fieldOffset;		// The offset of the tag field inside the data block. (Unlike in Halo Online, this points to the tag field, not the handle inside the tag field.)
	unsigned long nameOffset;		// The offset of the tag filename within the String Table.
	long dependencyIndex;			// The index of the tag dependency in the Tag Dependency List.Can be - 1 for null tag references.
};
static constexpr size_t k_infinite_ucs_tag_reference_list_size = sizeof(s_infinite_ucs_tag_reference_list);
static_assert(k_infinite_ucs_tag_reference_list_size == 0x10);

struct s_infinite_ucs_string_id_list
{
	unsigned long unknown0;			//  (Flags ? )
	unsigned long stringOffset;		//  The offset of the string value within the String Table.
};
static constexpr size_t k_infinite_ucs_string_id_list_size = sizeof(s_infinite_ucs_string_id_list);
static_assert(k_infinite_ucs_string_id_list_size == 0x8);

struct s_infinite_ucs_string_id_field
{
	unsigned long hash;
};
static constexpr size_t k_infinite_ucs_string_id_field_size = sizeof(s_infinite_ucs_string_id_field);
static_assert(k_infinite_ucs_string_id_field_size == 0x4);

#pragma pack(push, 4)
struct s_infinite_ucs_block_field
{
	unsigned long long elements;	// Runtime: pointer to the block containing the first struct.
	unsigned long long type_info;	// Runtime: pointer to type information.
	long count;						// Element count.
};
static constexpr size_t k_infinite_ucs_block_field_size = sizeof(s_infinite_ucs_block_field);
static_assert(k_infinite_ucs_block_field_size == 0x14);
#pragma pack(pop)

#pragma pack(push, 4)
struct s_infinite_ucs_data_reference_field
{
	unsigned long long data;		// Runtime : pointer to the referenced data.
	unsigned long long type_info;	// Runtime : pointer to type information.
	long unknown10;					// (Unused ? )
	unsigned long size;				// Size of the referenced data in bytes.
};
static constexpr size_t k_infinite_ucs_data_reference_field_size = sizeof(s_infinite_ucs_data_reference_field);
static_assert(k_infinite_ucs_data_reference_field_size == 0x18);
#pragma pack(pop)

#pragma pack(push, 4)
struct s_infinite_ucs_tag_reference_field
{
	unsigned long long type_info;	// Runtime : pointer to type information.
	long global_id;					// Global ID of the tag.
	long long global_id64;			// Global ID of the tag.
	long group_tag;					// Group tag(e.g.proj).
	long local_handle;				// Runtime : the resolved local tag handle.
};
static constexpr size_t k_infinite_ucs_tag_reference_field_size = sizeof(s_infinite_ucs_tag_reference_field);
static_assert(k_infinite_ucs_tag_reference_field_size == 0x1C);
#pragma pack(pop)

#pragma pack(push, 4)
struct s_infinite_ucs_pageable_resource_field
{
	unsigned long long type_info;	// Runtime: pointer to type information.
	unsigned long handle;			// Runtime: local resource handle.
	long unknownC;					// (Padding ? )
};
static constexpr size_t k_infinite_ucs_pageable_resource_field_size = sizeof(s_infinite_ucs_pageable_resource_field);
static_assert(k_infinite_ucs_pageable_resource_field_size == 0x10);
#pragma pack(pop)

class c_infinite_ucs_reader
{
public:
	c_infinite_ucs_reader(const void* ucs_data);
	~c_infinite_ucs_reader();
	
	unsigned long get_root_tag_block_entry_index() const;

	const void* header_data;
	const void* tag_data;

	const s_infinite_ucs_header* ucs_header;
	const s_infinite_ucs_tag_dependency_list* tag_dependency_list;
	const s_infinite_ucs_nugget* nuggets;
	const s_infinite_ucs_tag_block_data* tag_block_instances;
	const s_infinite_ucs_data_reference_list* tag_data_instances;
	const s_infinite_ucs_tag_reference_list* tag_reference;
	const char* string_table;
	const char* zoneset_data;
	const void* extra_data;
	unsigned long extra_data_size;

	long root_tag_block_entry_index;
	const s_infinite_ucs_tag_block_data* tag_group_tag_block_entry;
	const s_infinite_ucs_nugget* root_nugget;
	const char* root_tag_block_data;
};
