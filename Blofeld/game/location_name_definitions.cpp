#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(location_name, s_location_name_globals_tag_definition::k_maximum_location_names)
{
	{ _field_string_id, "name^" },
	{ _field_terminator },
};

TAG_GROUP(location_name_globals_definition, LOCATION_NAME_GLOBALS_DEFINITION_TAG)
{
	{ _field_block, "location names", &location_name_block },
	{ _field_tag_reference, "location name string list" },
	{ _field_terminator },
};

} // namespace blofeld

