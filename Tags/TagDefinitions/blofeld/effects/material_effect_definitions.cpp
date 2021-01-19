#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(material_effects, MATERIAL_EFFECTS_TAG)
	{
		{ _field_block, "effects", &material_effect_block_v2_block },
		{ _field_useless_pad },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(old_material_effect_material_block, 33)
	{
		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_tag_reference, "sound", &global_sound_and_looping_sound_reference },
		{ _field_string_id, "material name^" },
		{ _field_short_integer, "runtime material index!" },
		{ _field_pad, "KTRVUIKB", 2 },
		{ _field_char_enum, "sweetener mode", &sweeneter_mode_enum },
		{ _field_pad, "QNGPTA", 3 },
		{ _field_useless_pad },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(material_effect_material_block, k_maximum_material_effect_blocks)
	{
		{ _field_tag_reference, "tag (effect or sound)", &material_effect_material_block_tag_effect_or_sound_reference },
		{ _field_tag_reference, "secondary tag (effect or sound)", &material_effect_material_block_tag_effect_or_sound_reference },
		{ _field_string_id, "material name^" },
		{ _field_short_integer, "runtime material index!" },
		{ _field_char_enum, "sweetener mode", &sweeneter_mode_enum },
		{ _field_pad, "L", 1 },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "max_visibility_distance#manual override for the max distance this effect can be from the camera and still be rendered (not valid for sounds)." },

		{ _field_terminator }
	};

	V5_TAG_BLOCK(material_effect_block_v2, k_material_effect_type_count)
	{
		{ _field_block, "old materials (DO NOT USE)!", &old_material_effect_material_block_block },
		{ _field_block, "sounds", &material_effect_material_block_block },
		{ _field_block, "effects", &material_effect_material_block_block },
		{ _field_terminator }
	};

	STRINGS(sweeneter_mode_enum)
	{
		"sweetener default",
		"sweetener enabled",
		"sweetener disabled"
	};
	STRING_LIST(sweeneter_mode_enum, sweeneter_mode_enum_strings, _countof(sweeneter_mode_enum_strings));

	TAG_REFERENCE(global_material_effects_reference, MATERIAL_EFFECTS_TAG);

} // namespace blofeld

