#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(location_name_globals_definition, LOCATION_NAME_GLOBALS_DEFINITION_TAG, location_name_globals_definition_block_block );

	TAG_BLOCK(location_name_block, s_location_name_globals_tag_definition::k_maximum_location_names)
	{
		{ _field_string_id, "name^" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(location_name_globals_definition_block, 1, location_name_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(location_name_globals_definition_struct_definition)
	{
		{ _field_block, "location names", &location_name_block_block },
		{ _field_tag_reference, "location name string list", &global_multilingual_unicode_string_list_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_location_name_globals_reference, LOCATION_NAME_GLOBALS_DEFINITION_TAG);

} // namespace blofeld

