#pragma once

namespace blofeld
{

	extern const char* SpawnerFlags_strings[];
	extern s_string_list_definition SpawnerFlags;

	constexpr unsigned long SPAWNER_TAG = 'spnr';

	extern s_tag_group spawner_group;

	extern s_tag_block_definition spawner_block_block;

	extern s_tag_struct spawner_struct_definition_struct_definition; // tag group

} // namespace blofeld

