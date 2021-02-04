#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MIDNIGHT_LIGHT_STRUCT_ID { 0xC74B158E, 0xE0004613, 0x893D65F6, 0xE1E69DA7 }
	TAG_STRUCT(
		midnight_light_struct,
		"midnight_light_struct",
		"s_midnight_light_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MIDNIGHT_LIGHT_STRUCT_ID)
	{
		{ _field_long_integer, "Version", FIELD_FLAG_UNKNOWN0 },
		FIELD_EXPLANATION("Dynamic/Static Shared Light Parameters", nullptr, ""),
		{ _field_string_id, "haloLightNode", "Light node name in DCC.", FIELD_FLAG_INDEX },
		{ _field_long_enum, "Light Type", &midnight_light_type_enum_definition },
		{ _field_real_rgb_color, "Light Color" },
		{ _field_struct, "Intensity", &light_scalar_function_struct },
		{ _field_long_enum, "Lighting Mode", &midnight_lighting_mode_definition },
		{ _field_real, "Distance Attenuation Start", "Inner penumbra start." },
		{ _field_struct, "Distance Attenuation End", &light_scalar_function_struct },
		{ _field_real, "Camera Distance Fade Start", "Distance at which we start to fade out this light" },
		{ _field_real, "Camera Distance Fade End", "Distance at which the light should be completely faded out and not seen" },
		{ _field_real, "Specular Power", "For screen-space dynamic lights" },
		{ _field_real, "Specular Intensity", "For screen-space dynamic lights" },
		FIELD_EXPLANATION("Shared Spot Parameters", nullptr, ""),
		{ _field_real, "Inner Cone Angle", "Inner hotspot attenuation end." },
		{ _field_struct, "Outer Cone End", &light_scalar_function_struct },
		{ _field_long_enum, "Cone Projection Shape", &midnight_projection_definition },
		FIELD_EXPLANATION("Dynamic Only Parameters", nullptr, ""),
		{ _field_real, "Shadow Near Clip Plane" },
		{ _field_real, "Shadow Far Clip Plane" },
		{ _field_real, "Shadow Bias Offset" },
		{ _field_real_rgb_color, "Shadow Color", "Shadow tint." },
		{ _field_enum, "Dynamic Shadow Quality", &midnight_dynamic_shadow_quality_modes },
		{ _field_enum, "Shadows", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Screenspace Light", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Ignore Dynamic Objects", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Cinema Objects Only", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Cinema Only", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Cinema Exclude", &midnight_boolean_enum_definition },
		FIELD_PAD("PADDING1", nullptr, 1),
		{ _field_char_enum, "Specular Contribution", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Diffuse Contribution", &midnight_boolean_enum_definition },
		FIELD_EXPLANATION("Dynamic Gobo", nullptr, ""),
		{ _field_tag_reference, "Gobo Tag Path", &bitmap_reference$8 },
		{ _field_struct, "Rotation", &light_scalar_function_struct },
		{ _field_real, "Aspect Ratio", "Shape length and width of Gobo." },
		{ _field_long_enum, "Tile Behavior", &midnight_gobo_tile_behavior_enum_definition },
		{ _field_real, "Repeat X", "Tile Gobo." },
		{ _field_real, "Repeat Y", "Tile Gobo." },
		{ _field_struct, "Offset X", &light_scalar_function_struct },
		{ _field_struct, "Offset Y", &light_scalar_function_struct },
		FIELD_EXPLANATION("Color Change", nullptr, ""),
		{ _field_struct, "Interpolation Function", &light_color_function_struct },
		{ _field_real_rgb_color, "Target Color" },
		FIELD_EXPLANATION("Channels", nullptr, ""),
		{ _field_long_flags, "Light Channels", &channelDefinitionFlags },
		{ _field_long_flags, "Shadow Channels", &channelDefinitionFlags },
		FIELD_EXPLANATION("Bungie Parameters", nullptr, ""),
		{ _field_long_flags, "flags", &light_definition_flags },
		{ _field_real, "destroy light after", "automatically destroys the light after it has existed this long (0 to disable)", "seconds" },
		{ _field_tag_reference, "Lens Flare", &global_lens_flare_reference },
		{ _field_terminator }
	};

	STRINGS(midnight_light_type_enum_definition)
	{
		"Point",
		"Spot",
		"Directional",
		"Area",
		"Sun"
	};
	STRING_LIST(midnight_light_type_enum_definition, midnight_light_type_enum_definition_strings, _countof(midnight_light_type_enum_definition_strings));

	STRINGS(midnight_lighting_mode_definition)
	{
		"Physically Correct",
		"Artistic"
	};
	STRING_LIST(midnight_lighting_mode_definition, midnight_lighting_mode_definition_strings, _countof(midnight_lighting_mode_definition_strings));

	STRINGS(midnight_projection_definition)
	{
		"Cone",
		"Frustum"
	};
	STRING_LIST(midnight_projection_definition, midnight_projection_definition_strings, _countof(midnight_projection_definition_strings));

	STRINGS(midnight_boolean_enum_definition)
	{
		"Off",
		"On"
	};
	STRING_LIST(midnight_boolean_enum_definition, midnight_boolean_enum_definition_strings, _countof(midnight_boolean_enum_definition_strings));

	STRINGS(midnight_dynamic_shadow_quality_modes)
	{
		"Normal",
		"Expensive (cinematics only)"
	};
	STRING_LIST(midnight_dynamic_shadow_quality_modes, midnight_dynamic_shadow_quality_modes_strings, _countof(midnight_dynamic_shadow_quality_modes_strings));

	STRINGS(midnight_gobo_tile_behavior_enum_definition)
	{
		"Clamp",
		"Repeat",
		"Mirror"
	};
	STRING_LIST(midnight_gobo_tile_behavior_enum_definition, midnight_gobo_tile_behavior_enum_definition_strings, _countof(midnight_gobo_tile_behavior_enum_definition_strings));

	STRINGS(channelDefinitionFlags)
	{
		"0",
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"11",
		"12",
		"13",
		"14",
		"15",
		"16",
		"17",
		"18",
		"19",
		"20",
		"21",
		"22",
		"23",
		"24",
		"25",
		"26",
		"27",
		"28",
		"29",
		"30",
		"31"
	};
	STRING_LIST(channelDefinitionFlags, channelDefinitionFlags_strings, _countof(channelDefinitionFlags_strings));

	STRINGS(light_definition_flags)
	{
		"allow shadows and gels!#",
		"shadow casting#turns on shadow casting",
		"render first person only#only render when camera is 1st person",
		"render third person only#don\'t render when camera is 1st person",
		"dont render splitscreen#no rendering this light in splitscreen mode",
		"render while active camo#keep rendering this light when the attached player goes camo",
		"render in multiplayer override#overrides game settings that disable dynamic lights",
		"move to camera in first person#moves the light to match the camera",
		"never priority cull#never cull this light because of low priority",
		"affected by game_can_use_flashlights",
		"screenspace specular lighting#uses expensive specular lighting on screenspace lights",
		"always on for weapon#even it is dropped"
	};
	STRING_LIST(light_definition_flags, light_definition_flags_strings, _countof(light_definition_flags_strings));

} // namespace macaque

} // namespace blofeld

