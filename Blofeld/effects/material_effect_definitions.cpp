#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(material_effect, k_material_effect_type_count)
{
	FIELD( _field_block, "old materials (DO NOT USE)!", &old_material_effect_material_block ),
	FIELD( _field_block, "sounds", &material_effect_material_block ),
	FIELD( _field_block, "effects", &material_effect_material_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(old_material_effect_material, 33)
{
	FIELD( _field_tag_reference, "effect" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_string_id, "material name^" ),
	FIELD( _field_short_integer, "runtime material index!" ),
	FIELD( _field_pad, "KTRVUIKB", 2 ),
	FIELD( _field_char_enum, "sweetener mode" ),
	FIELD( _field_pad, "QNGPTA", 3 ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

TAG_BLOCK(material_effect_material, k_maximum_material_effect_blocks)
{
	FIELD( _field_tag_reference, "tag (effect or sound)" ),
	FIELD( _field_tag_reference, "secondary tag (effect or sound)" ),
	FIELD( _field_string_id, "material name^" ),
	FIELD( _field_short_integer, "runtime material index!" ),
	FIELD( _field_char_enum, "sweetener mode" ),
	FIELD( _field_pad, "L", 1 ),
	FIELD( _field_real, "max_visibility_distance#manual override for the max distance this effect can be from the camera and still be rendered (not valid for sounds)." ),
	FIELD( _field_terminator )
};

TAG_GROUP(material_effects, MATERIAL_EFFECTS_TAG)
{
	FIELD( _field_block, "effects", &material_effect_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

} // namespace blofeld

