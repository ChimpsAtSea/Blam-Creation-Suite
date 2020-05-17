#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(g_scenario_editor_folder_block, k_maximum_scenario_editor_folders)
	{
		FIELD( _field_long_block_index, "parent folder" ),
		FIELD( _field_long_string, "name^" ),
		FIELD( _field_pad, "pad", 4 ),
		FIELD( _field_int64_integer, "offset*!" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

