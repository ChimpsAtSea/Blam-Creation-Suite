#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(location_name_globals_definition, LOCATION_NAME_GLOBALS_DEFINITION_TAG, location_name_globals_definition_block_block );

	TAG_BLOCK(location_name_block, s_location_name_globals_tag_definition::k_maximum_location_names)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(location_name_globals_definition_block, 1, location_name_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(location_name_globals_definition_struct_definition)
	{
		FIELD( _field_block, "location names", &location_name_block_block ),
		FIELD( _field_tag_reference, "location name string list" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

