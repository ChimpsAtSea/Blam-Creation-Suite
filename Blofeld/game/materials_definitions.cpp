#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(object_type_drag_properties_block, NUMBER_OF_OBJECT_TYPES)
	{
		FIELD( _field_tag_reference, "drag properties" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(underwater_proxies_block, k_maximum_material_types)
	{
		FIELD( _field_explanation, "when this material is encounted under a material of this type ..." ),
		FIELD( _field_string_id, "underwater material" ),
		FIELD( _field_explanation, "... we report it as this material" ),
		FIELD( _field_string_id, "proxy material" ),
		FIELD( _field_short_integer, "underwater material type*!" ),
		FIELD( _field_short_integer, "proxy material type*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(materials_block, k_maximum_editable_material_types)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "parent name" ),
		FIELD( _field_short_integer, "runtime material index!" ),
		FIELD( _field_word_flags, "flags", &global_material_flags_definition ),
		FIELD( _field_string_id, "general armor" ),
		FIELD( _field_string_id, "specific armor" ),
		FIELD( _field_struct, "wet proxies", &wet_proxies_struct_struct_definition ),
		FIELD( _field_short_integer, "runtime dry base material index!" ),
		FIELD( _field_pad, "RMBP1", 2 ),
		FIELD( _field_struct, "physics properties", &material_physics_properties_struct_struct_definition ),
		FIELD( _field_tag_reference, "breakable surface" ),
		FIELD( _field_struct, "sweeteners", &materials_sweeteners_struct_struct_definition ),
		FIELD( _field_tag_reference, "material effects" ),
		FIELD( _field_block, "underwater proxies", &underwater_proxies_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(runtime_materials_block, k_maximum_material_types)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "parent name" ),
		FIELD( _field_short_integer, "runtime material index!" ),
		FIELD( _field_word_flags, "flags", &global_material_flags_definition ),
		FIELD( _field_string_id, "general armor" ),
		FIELD( _field_string_id, "specific armor" ),
		FIELD( _field_struct, "wet proxies", &wet_proxies_struct_struct_definition ),
		FIELD( _field_short_integer, "runtime dry base material index!" ),
		FIELD( _field_pad, "RMBP1", 2 ),
		FIELD( _field_struct, "physics properties", &material_physics_properties_struct_struct_definition ),
		FIELD( _field_tag_reference, "breakable surface" ),
		FIELD( _field_struct, "sweeteners", &materials_sweeteners_struct_struct_definition ),
		FIELD( _field_tag_reference, "material effects" ),
		FIELD( _field_block, "underwater proxies", &underwater_proxies_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(wet_proxies_struct)
	{
		FIELD( _field_explanation, "when rained on, we report this material" ),
		FIELD( _field_string_id, "wet material" ),
		FIELD( _field_short_integer, "runtime proxy material index*!" ),
		FIELD( _field_pad, "wpb1", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(material_physics_properties_struct)
	{
		FIELD( _field_long_integer, "flags!" ),
		FIELD( _field_real, "friction" ),
		FIELD( _field_real_fraction, "restitution" ),
		FIELD( _field_real, "density:kg/m^3" ),
		FIELD( _field_explanation, "Drag" ),
		FIELD( _field_tag_reference, "water physics drag properties" ),
		FIELD( _field_block, "drag overrides", &object_type_drag_properties_block_block ),
		FIELD( _field_explanation, "Floatation" ),
		FIELD( _field_pad, "default", 4 ),
		FIELD( _field_real, "super floater" ),
		FIELD( _field_real, "floater" ),
		FIELD( _field_real, "neutral" ),
		FIELD( _field_real, "sinker" ),
		FIELD( _field_real, "super sinker" ),
		FIELD( _field_pad, "none", 4 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(materials_sweeteners_struct)
	{
		FIELD( _field_tag_reference, "sound sweetener (small)" ),
		FIELD( _field_tag_reference, "sound sweetener (medium)" ),
		FIELD( _field_tag_reference, "sound sweetener (large)" ),
		FIELD( _field_tag_reference, "sound sweetener rolling" ),
		FIELD( _field_tag_reference, "sound sweetener grinding" ),
		FIELD( _field_tag_reference, "sound sweetener (melee small)" ),
		FIELD( _field_tag_reference, "sound sweetener (melee)#this is a medium sweetener and was the old default" ),
		FIELD( _field_tag_reference, "sound sweetener (melee large)" ),
		FIELD( _field_tag_reference, "effect sweetener (small)" ),
		FIELD( _field_tag_reference, "effect sweetener (medium)" ),
		FIELD( _field_tag_reference, "effect sweetener (large)" ),
		FIELD( _field_tag_reference, "effect sweetener rolling" ),
		FIELD( _field_tag_reference, "effect sweetener grinding" ),
		FIELD( _field_tag_reference, "effect sweetener (melee)" ),
		FIELD( _field_tag_reference, "water ripple (small)" ),
		FIELD( _field_tag_reference, "water ripple (medium)" ),
		FIELD( _field_tag_reference, "water ripple (large)" ),
		FIELD( _field_explanation, "sweetener inheritance flags" ),
		FIELD( _field_long_flags, "sweetener inheritance flags", &materials_sweeteners_inheritance_flags ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(materials_sweeteners_inheritance_flags, 17)
	{
		OPTION("sound_small"),
		OPTION("sound_medium"),
		OPTION("sound_large"),
		OPTION("sound_rolling"),
		OPTION("sound_grinding"),
		OPTION("sound_melee_small"),
		OPTION("sound_melee"),
		OPTION("sound_melee_large"),
		OPTION("effect_small"),
		OPTION("effect_medium"),
		OPTION("effect_large"),
		OPTION("effect_rolling"),
		OPTION("effect_grinding"),
		OPTION("effect_melee"),
		OPTION("water_ripple_small"),
		OPTION("water_ripple_medium"),
		OPTION("water_ripple_large"),
	};

	TAG_ENUM(global_material_flags_definition, 5)
	{
		OPTION("flammable"),
		OPTION("biomass"),
		OPTION("rad xfer interior"),
		OPTION("used directly!"),
		OPTION("used by children!"),
	};

} // namespace blofeld

