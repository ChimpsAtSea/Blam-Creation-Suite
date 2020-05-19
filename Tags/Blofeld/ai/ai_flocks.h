#pragma once

namespace blofeld
{

	constexpr unsigned long FLOCK_TAG = 'flck';

	extern s_tag_group flock_group;

	extern s_tag_block_definition flock_block_block;
	extern s_tag_struct_definition flock_palette_block_block_struct;
	extern s_tag_block_definition flock_palette_block_block;
	extern s_tag_struct_definition flock_source_block_block_struct;
	extern s_tag_block_definition flock_source_block_block;
	extern s_tag_struct_definition flock_destination_block_block_struct;
	extern s_tag_block_definition flock_destination_block_block;
	extern s_tag_struct_definition flock_instance_block_block_struct;
	extern s_tag_block_definition flock_instance_block_block;

	extern s_tag_struct_definition flock_struct_definition_struct_definition; // tag group

	extern const char* flock_source_flags_strings[];
	extern s_string_list_definition flock_source_flags;
	extern const char* destination_type_enum_strings[];
	extern s_string_list_definition destination_type_enum;
	extern const char* flock_flags_strings[];
	extern s_string_list_definition flock_flags;

} // namespace blofeld

