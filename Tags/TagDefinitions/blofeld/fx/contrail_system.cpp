#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	TAG_BLOCK(contrail_system_entry, 65536)
	{

		{ _field_terminator }
	};

	TAG_GROUP(contrail_system, CONTRAIL_SYSTEM_TAG)
	{
		{ _field_block, "contrail system", &contrail_system_entry_block },
		{ _field_terminator }
	};

}