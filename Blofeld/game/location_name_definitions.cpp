#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(location_name, s_location_name_globals_tag_definition::k_maximum_location_names)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(location_name_globals_definition, LOCATION_NAME_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_block, "location names", &location_name_block ),
	FIELD( _field_tag_reference, "location name string list" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

