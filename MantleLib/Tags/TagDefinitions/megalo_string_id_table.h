#pragma once

struct nicename("megalo_string_id_table") group('msit') s_megalo_string_id_table_definition
{
	struct nicename("Megalo String IDs") s_megalo_string_ids_definition
	{
		string_id nicename("String ID") string_id;
	};

	s_tag_block_definition<s_megalo_string_ids_definition> nicename("Megalo String IDs") megalo_string_ids_block;
};

