#pragma once

namespace blofeld
{
	enum e_tag_field_attributed_definition
	{
		_tag_field_attributed_definition_unknown_type = 0,
		_tag_field_attributed_definition_position = 'poin',
		_tag_field_attributed_definition_orientation = 'orie',
		_tag_field_attributed_definition_scale = 'scal',
		_tag_field_attributed_definition_block_wide_field_default = 'wide',
		_tag_field_attributed_definition_block_collapsed_field_default = 'slap',
		_tag_field_attributed_definition_block_name_sorted = 'sort',
		_tag_field_attributed_definition_block_grid_view_by_default = 'grid',
		_tag_field_attributed_definition_template_refresh_field = 'rfsh',
		_tag_field_attributed_definition_custom_block_filter_field = 'cflt',
		_tag_field_attributed_definition_string_editor = 'sted',
		_tag_field_attributed_definition_update_layout_field = 'enum',
		_tag_field_attributed_definition_scenario_object_manual_bsp_flags = 'mbsp',
		_tag_field_attributed_definition_scenario_folder_field = 'ugly',
	};
	BCS_SHARED const char* tag_field_attributed_definition_to_string(e_tag_field_attributed_definition tag_field_attributed_definitions);
}
