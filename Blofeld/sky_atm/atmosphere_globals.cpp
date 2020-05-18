#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(atmosphere_globals, ATMOSPHERE_GLOBALS_TAG, atmosphere_globals_block_block );

	TAG_BLOCK(underwater_setting_block, k_max_atmosphere_settings)
	{
		{ _field_string_id, "Name" },
		{ _field_real, "Murkiness" },
		{ _field_real_rgb_color, "Fog Color" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(atmosphere_globals_block, 1, atmosphere_globals_struct_definition_struct_definition );

	TAG_STRUCT(atmosphere_globals_struct_definition)
	{
		{ _field_explanation, "Patchy Fog Global Parameters" },
		{ _field_tag_reference, "Fog Bitmap", &global_bitmap_reference },
		{ _field_real, "Texture repeat rate" },
		{ _field_real, "Distance between sheets" },
		{ _field_real, "Depth fade factor" },
		{ _field_real, "Transparent sort distance" },
		{ _field_char_enum, "Transparent sort layer", &global_sort_layer_enum_defintion },
		{ _field_pad, "UNdfdfdSED", 3 },
		{ _field_struct, "wind strength across distance", &scalar_function_named_struct_default_one_struct_definition },
		{ _field_block, "underwater settings", &underwater_setting_block_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_atmosphere_globals_reference, ATMOSPHERE_GLOBALS_TAG);

} // namespace blofeld

