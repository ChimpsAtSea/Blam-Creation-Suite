#pragma once

struct nicename("megalo_string_id_table") tag_group('msit') s_megalo_string_id_table_definition_legacy
{
	struct nicename("Megalo String IDs") s_megalo_string_ids_definition_legacy
	{
		string_id_legacy nicename("String ID") string_id;
	};

	s_tag_block_legacy<s_megalo_string_ids_definition_legacy> nicename("Megalo String IDs") megalo_string_ids_block;
};
