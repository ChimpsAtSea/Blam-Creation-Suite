#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_effect, k_material_effect_type_count)
{
	{ _field_block, "old materials (DO NOT USE)!", &old_material_effect_material_block },
	{ _field_block, "sounds", &material_effect_material_block },
	{ _field_block, "effects", &material_effect_material_block },
	{ _field_terminator },
};

TAG_BLOCK(old_material_effect_material, 33)
{
	{ _field_tag_reference, "effect" },
	{ _field_tag_reference, "sound" },
	{ _field_string_id, "material name^" },
	{ _field_short_integer, "runtime material index!" },
	{ _field_pad, "KTRVUIKB", 2 },
	{ _field_char_enum, "sweetener mode" },
	{ _field_pad, "QNGPTA", 3 },
	{ _field_useless_pad },
	{ _field_terminator },
};

TAG_BLOCK(material_effect_material, k_maximum_material_effect_blocks)
{
	{ _field_tag_reference, "tag (effect or sound)" },
	{ _field_tag_reference, "secondary tag (effect or sound)" },
	{ _field_string_id, "material name^" },
	{ _field_short_integer, "runtime material index!" },
	{ _field_char_enum, "sweetener mode" },
	{ _field_pad, "L", 1 },
	{ _field_real, "max_visibility_distance#manual override for the max distance this effect can be from the camera and still be rendered (not valid for sounds)." },
	{ _field_terminator },
};

TAG_GROUP(material_effects, MATERIAL_EFFECTS_TAG)
{
	{ _field_block, "effects", &material_effect_block },
	{ _field_useless_pad },
	{ _field_terminator },
};

} // namespace blofeld

