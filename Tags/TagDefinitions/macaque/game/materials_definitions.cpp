#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MATERIALS_BLOCK_ID { 0x4D5F9153, 0x00B947A3, 0xBCAF406F, 0xC56F065C }
	TAG_BLOCK(
		materials_block$3_block,
		"materials_block",
		k_maximum_editable_material_types,
		"s_global_material_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIALS_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "parent name" },
		{ _field_short_integer, "runtime material index" },
		{ _field_word_flags, "flags", &global_material_flags_definition },
		{ _field_string_id, "general armor" },
		{ _field_string_id, "specific armor" },
		{ _field_struct, "wet proxies", &wet_proxies_struct },
		{ _field_short_integer, "runtime dry base material index" },
		FIELD_PAD("RMBP1", nullptr, 2),
		{ _field_struct, "physics properties", &material_physics_properties_struct },
		{ _field_tag_reference, "breakable surface", &global_breakable_surface_reference },
		{ _field_struct, "sweeteners", &materials_sweeteners_struct },
		{ _field_tag_reference, "material effects", &global_material_effects_reference },
		{ _field_block, "underwater proxies", &underwater_proxies_block },
		{ _field_terminator }
	};

	#define OBJECT_TYPE_DRAG_PROPERTIES_BLOCK_ID { 0x12B22BB0, 0xAF9E4906, 0xB0CCE6BA, 0xB6C4E365 }
	TAG_BLOCK(
		object_type_drag_properties_block,
		"object_type_drag_properties_block",
		NUMBER_OF_OBJECT_TYPES,
		"s_global_material_object_drag_properties",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		OBJECT_TYPE_DRAG_PROPERTIES_BLOCK_ID)
	{
		{ _field_tag_reference, "drag properties", &water_physics_drag_properties_reference },
		{ _field_terminator }
	};

	#define UNDERWATER_PROXIES_BLOCK_ID { 0xAD5F9353, 0xA0B9C7A3, 0xBAA0406F, 0xC16F2653 }
	TAG_BLOCK(
		underwater_proxies_block,
		"underwater_proxies_block",
		k_maximum_material_types,
		"s_global_material_underwater_proxy",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		UNDERWATER_PROXIES_BLOCK_ID)
	{
		FIELD_EXPLANATION("when this material is encounted under a material of this type ...", nullptr, ""),
		{ _field_string_id, "underwater material" },
		FIELD_EXPLANATION("... we report it as this material", nullptr, ""),
		{ _field_string_id, "proxy material" },
		{ _field_short_integer, "underwater material type" },
		{ _field_short_integer, "proxy material type" },
		{ _field_terminator }
	};

	#define RUNTIME_MATERIALS_BLOCK_ID { 0x83B9D6FB, 0xE0F845B8, 0x945A3F96, 0xD4F38AEE }
	TAG_BLOCK(
		runtime_materials_block,
		"runtime_materials_block",
		k_maximum_material_types,
		"s_global_material_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RUNTIME_MATERIALS_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "parent name" },
		{ _field_short_integer, "runtime material index" },
		{ _field_word_flags, "flags", &global_material_flags_definition },
		{ _field_string_id, "general armor" },
		{ _field_string_id, "specific armor" },
		{ _field_struct, "wet proxies", &wet_proxies_struct },
		{ _field_short_integer, "runtime dry base material index" },
		FIELD_PAD("RMBP1", nullptr, 2),
		{ _field_struct, "physics properties", &material_physics_properties_struct },
		{ _field_tag_reference, "breakable surface", &global_breakable_surface_reference },
		{ _field_struct, "sweeteners", &materials_sweeteners_struct },
		{ _field_tag_reference, "material effects", &global_material_effects_reference },
		{ _field_block, "underwater proxies", &underwater_proxies_block },
		{ _field_terminator }
	};

	#define WET_PROXIES_STRUCT_ID { 0xE5466355, 0x33AF4380, 0x83F0B03D, 0xFC20CC34 }
	TAG_STRUCT(
		wet_proxies_struct,
		"wet_proxies_struct",
		"s_global_material_wet_proxy",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WET_PROXIES_STRUCT_ID)
	{
		FIELD_EXPLANATION("when rained on, we report this material", nullptr, ""),
		{ _field_string_id, "wet material" },
		{ _field_short_integer, "runtime proxy material index" },
		FIELD_PAD("wpb1", nullptr, 2),
		{ _field_terminator }
	};

	#define MATERIAL_PHYSICS_PROPERTIES_STRUCT_ID { 0x8DB8D6D8, 0x833D4150, 0xA47D3861, 0x5C3FDD97 }
	TAG_STRUCT(
		material_physics_properties_struct,
		"material_physics_properties_struct",
		"material_physics_properties_struct",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_PHYSICS_PROPERTIES_STRUCT_ID)
	{
		{ _field_long_integer, "flags" },
		{ _field_real, "friction" },
		{ _field_real_fraction, "restitution" },
		{ _field_real, "density", "kg/m" },
		FIELD_EXPLANATION("Drag", nullptr, ""),
		{ _field_tag_reference, "water physics drag properties", &water_physics_drag_properties_reference },
		{ _field_block, "drag overrides", &object_type_drag_properties_block },
		FIELD_EXPLANATION("Floatation", nullptr, "objects of this flotation category have this density relative to being in this material (1.0f==neutral)"),
		FIELD_PAD("default", nullptr, 4),
		{ _field_real, "super floater" },
		{ _field_real, "floater" },
		{ _field_real, "neutral" },
		{ _field_real, "sinker" },
		{ _field_real, "super sinker" },
		FIELD_PAD("none", nullptr, 4),
		{ _field_terminator }
	};

	#define MATERIALS_SWEETENERS_STRUCT_ID { 0x9F74BAB9, 0xC3664288, 0xB82EFC4F, 0x59924C4B }
	TAG_STRUCT(
		materials_sweeteners_struct,
		"materials_sweeteners_struct",
		"s_global_material_sweeteners_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIALS_SWEETENERS_STRUCT_ID)
	{
		{ _field_tag_reference, "sound sweetener (small)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (medium)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (large)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener rolling", &global_looping_sound_reference },
		{ _field_tag_reference, "sound sweetener grinding", &global_looping_sound_reference },
		{ _field_tag_reference, "sound sweetener (melee small)", &global_sound_reference },
		{ _field_tag_reference, "sound sweetener (melee)", &global_sound_reference },
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
		FIELD_EXPLANATION("sweetener inheritance flags", nullptr, "when a sweetener inheritance flag is set the sound\\effect is not inherited from the parent material.  If you leave the sweetener blank and set the flag than no effect\\sound will play"),
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

} // namespace macaque

} // namespace blofeld

