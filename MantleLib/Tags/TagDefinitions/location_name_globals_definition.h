#pragma once

struct nicename("location_name_globals_definition") tag_group('locs') s_location_name_globals_definition_definition
{
	struct nicename("Callouts") s_callouts_definition
	{
		string_id nicename("Name") name;
	};

	s_tag_block_definition<s_callouts_definition> nicename("Callouts") callouts_block;
	TagReference nicename("Location Names") location_names_reference;
};

