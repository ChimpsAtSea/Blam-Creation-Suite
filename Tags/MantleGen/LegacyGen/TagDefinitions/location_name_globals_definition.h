#pragma once

struct nicename("location_name_globals_definition") tag_group('locs') s_location_name_globals_definition_definition_legacy
{
	struct nicename("Callouts") s_callouts_definition_legacy
	{
		string_id_legacy nicename("Name") name;
	};

	s_tag_block_legacy<s_callouts_definition_legacy> nicename("Callouts") callouts_block;
	s_tag_reference_legacy nicename("Location Names") location_names_reference;
};

