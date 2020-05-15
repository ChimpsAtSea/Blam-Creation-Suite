#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(g_scenario_editor_folder, k_maximum_scenario_editor_folders)
{
	{ _field_long_block_index, "parent folder" },
	{ _field_long_string, "name^" },
	{ _field_pad, "pad", 4 },
	{ _field_int64_integer, "offset*!" },
	{ _field_terminator },
};

} // namespace blofeld

