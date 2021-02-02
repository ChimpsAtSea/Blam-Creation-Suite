#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define G_SCENARIO_EDITOR_FOLDER_BLOCK_ID { 0x0B9D6A59, 0x9A5741CB, 0xA1D7A5D1, 0x9F085A3D }
	TAG_BLOCK(
		g_scenario_editor_folder_block,
		"g_scenario_editor_folder_block",
		k_maximum_scenario_editor_folders,
		"s_scenario_editor_folder",
		G_SCENARIO_EDITOR_FOLDER_BLOCK_ID)
	{
		{ _field_long_block_index, "parent folder", &g_scenario_editor_folder_block },
		{ _field_long_string, "name" },
		FIELD_PAD("pad", nullptr, 4),
		{ _field_int64_integer, "offset" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

