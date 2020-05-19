#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(object_type_drag_properties_block, NUMBER_OF_OBJECT_TYPES)
	{
		{ _field_tag_reference, "drag properties", &water_physics_drag_properties_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(underwater_proxies_block, k_maximum_material_types)
	{
		{ _field_explanation, "when this material is encounted under a material of this type ..." },
		{ _field_string_id, "underwater material" },
		{ _field_explanation, "... we report it as this material" },
		{ _field_string_id, "proxy material" },
		{ _field_short_integer, "underwater material type*!" },
		{ _field_short_integer, "proxy material type*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(materials_block, k_maximum_editable_material_types)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "parent name" },
		{ _field_short_integer, "runtime material index!" },
		{ _field_word_flags, "flags", &global_material_flags_definition },
		{ _field_string_id, "general armor" },
		{ _field_string_id, "specific armor" },
		{ _field_struct, "wet proxies", &wet_proxies_struct_struct_definition },
		{ _field_short_integer, "runtime dry base material index!" },
		{ _field_pad, "RMBP1", 2 },
		{ _field_struct, "physics properties", &material_physics_properties_struct_struct_definition },
		{ _field_tag_reference, "breakable surface", &global_breakable_surface_reference },
		{ _field_struct, "sweeteners", &materials_sweeteners_struct_struct_definition },
		{ _field_tag_reference, "material effects", &global_material_effects_reference },
		{ _field_block, "underwater proxies", &underwater_proxies_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(runtime_materials_block, k_maximum_material_types)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "parent name" },
		{ _field_short_integer, "runtime material index!" },
		{ _field_word_flags, "flags", &global_material_flags_definition },
		{ _field_string_id, "general armor" },
		{ _field_string_id, "specific armor" },
		{ _field_struct, "wet proxies", &wet_proxies_struct_struct_definition },
		{ _field_short_integer, "runtime dry base material index!" },
		{ _field_pad, "RMBP1", 2 },
		{ _field_struct, "physics properties", &material_physics_properties_struct_struct_definition },
		{ _field_tag_reference, "breakable surface", &global_breakable_surface_reference },
		{ _field_struct, "sweeteners", &materials_sweeteners_struct_struct_definition },
		{ _field_tag_reference, "material effects", &global_material_effects_reference },
		{ _field_block, "underwater proxies", &underwater_proxies_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(wet_proxies_struct)
	{
		{ _field_explanation, "when rained on, we report this material" },
		{ _field_string_id, "wet material" },
		{ _field_short_integer, "runtime proxy material index*!" },
		{ _field_pad, "wpb1", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(material_physics_properties_struct)
	{
		{ _field_long_integer, "flags!" },
		{ _field_real, "friction" },
		{ _field_real_fraction, "restitution" },
		{ _field_real, "density:kg/m^3" },
		{ _field_explanation, "Drag" },
		{ _field_tag_reference, "water physics drag properties", &water_physics_drag_properties_reference },
		{ _field_block, "drag overrides", &object_type_drag_properties_block_block },
		{ _field_explanation, "Floatation" },
		{ _field_pad, "default", 4 },
		{ _field_real, "super floater" },
		{ _field_real, "floater" },
		{ _field_real, "neutral" },
		{ _field_real, "sinker" },
		{ _field_real, "super sinker" },
		{ _field_pad, "none", 4 },
		{ _field_terminator }
	};

	TAG_STRUCT(materials_sweeteners_struct)
	{
		{ _field_tag_reference, "sound sweetener (small)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (medium)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (large)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener rolling", &global_looping_sound_reference },
		{ _field_tag_reference, "sound sweetener grinding", &global_looping_sound_reference },
		{ _field_tag_reference, "sound sweetener (melee small)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (melee)#this is a medium sweetener and was the old default", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (melee large)", &global_sound_reference },
		{ _field_tag_reference, "effect sweetener (small)", &global_effect_reference },
		{ _field_tag_reference, "effect sweetener (medium)", &global_effect_reference },
		{ _field_tag_reference, "effect sweetener (large)", &global_effect_reference },
		{ _field_tag_reference, "effect sweetener rolling", &global_effect_reference },
		{ _field_tag_reference, "effect sweetener grinding", &global_effect_reference },
		{ _field_tag_reference, "effect sweetener (melee)", &global_effect_reference },
		{ _field_tag_reference, "water ripple (small)", &render_water_ripple_reference },
		{ _field_tag_reference, "water ripple (medium)", &render_water_ripple_reference },
		{ _field_tag_reference, "water ripple (large)", &render_water_ripple_reference },
		{ _field_explanation, "sweetener inheritance flags" },
		{ _field_long_flags, "sweetener inheritance flags", &materials_sweeteners_inheritance_flags },
		{ _field_terminator }
	};

	STRINGS(materials_sweeteners_inheritance_flags)
	{
		"sound_small",
		"sound_medium",
		"sound_large",
		"sound_rolling",
		"sound_grinding",
		"sound_melee_small",
		"sound_melee",
		"sound_melee_large",
		"effect_small",
		"effect_medium",
		"effect_large",
		"effect_rolling",
		"effect_grinding",
		"effect_melee",
		"water_ripple_small",
		"water_ripple_medium",
		"water_ripple_large"
	};
	STRING_LIST(materials_sweeteners_inheritance_flags, materials_sweeteners_inheritance_flags_strings, _countof(materials_sweeteners_inheritance_flags_strings));

	STRINGS(global_material_flags_definition)
	{
		"flammable",
		"biomass",
		"rad xfer interior",
		"used directly!",
		"used by children!"
	};
	STRING_LIST(global_material_flags_definition, global_material_flags_definition_strings, _countof(global_material_flags_definition_strings));

} // namespace blofeld

