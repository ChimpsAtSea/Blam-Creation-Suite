#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_STRUCT(midnight_light_struct)
	{
		{ _field_long_integer, "Version!" },
		{ _field_explanation, "Dynamic/Static Shared Light Parameters", "" },
		{ _field_string_id, "haloLightNode:^#Light node name in DCC." },
		{ _field_long_enum, "Light Type:#Geometry shape of light.", &midnight_light_type_enum_definition },
		{ _field_real_rgb_color, "Light Color:" },
		{ _field_struct, "Intensity:[0-1+]", &light_scalar_function_struct_struct_definition },
		{ _field_long_enum, "Lighting Mode:#Attenuation overrides.", &midnight_lighting_mode_definition },
		{ _field_real, "Distance Attenuation Start:#Inner penumbra start." },
		{ _field_struct, "Distance Attenuation End:#Radius or size of light", &light_scalar_function_struct_struct_definition },
		{ _field_real, "Camera Distance Fade Start:#Distance at which we start to fade out this light" },
		{ _field_real, "Camera Distance Fade End:#Distance at which the light should be completely faded out and not seen" },
		{ _field_real, "Specular Power:#For screen-space dynamic lights" },
		{ _field_real, "Specular Intensity:#For screen-space dynamic lights" },
		{ _field_explanation, "Shared Spot Parameters", "" },
		{ _field_real, "Inner Cone Angle:[0-160 degrees]#Inner hotspot attenuation end." },
		{ _field_struct, "Outer Cone End:[0-160 degrees]#Angle size of spotlight.", &light_scalar_function_struct_struct_definition },
		{ _field_long_enum, "Cone Projection Shape:#Use cone in all cases unless you have a gobo you need to project, frustum uses the full clip area of the light", &midnight_projection_definition },
		{ _field_explanation, "Dynamic Only Parameters", "" },
		{ _field_real, "Shadow Near Clip Plane" },
		{ _field_real, "Shadow Far Clip Plane" },
		{ _field_real, "Shadow Bias Offset" },
		{ _field_real_rgb_color, "Shadow Color:#Shadow tint." },
		{ _field_enum, "Dynamic Shadow Quality", &midnight_dynamic_shadow_quality_modes },
		{ _field_enum, "Shadows:", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Screenspace Light", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Ignore Dynamic Objects", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Cinema Objects Only#This should only be turned on if you have light linking data correctly setup", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Cinema Only", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Cinema Exclude", &midnight_boolean_enum_definition },
		{ _field_pad, "PADDING1", 1 },
		{ _field_char_enum, "Specular Contribution", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Diffuse Contribution", &midnight_boolean_enum_definition },
		{ _field_explanation, "Dynamic Gobo", "" },
		{ _field_tag_reference, "Gobo Tag Path:#Bitmap file for spotlight. Cube map for point light. Gobo bitmap must be synced to xbox.", &bitmap_reference$8 },
		{ _field_struct, "Rotation:[0-360 degrees]", &light_scalar_function_struct_struct_definition },
		{ _field_real, "Aspect Ratio:[-0-1+]#Shape length and width of Gobo." },
		{ _field_long_enum, "Tile Behavior:#Gobo texture lookup behavior when tiled.", &midnight_gobo_tile_behavior_enum_definition },
		{ _field_real, "Repeat X:[0-1+]#Tile Gobo." },
		{ _field_real, "Repeat Y:[0-1+]#Tile Gobo." },
		{ _field_struct, "Offset X:#Offset Gobo.", &light_scalar_function_struct_struct_definition },
		{ _field_struct, "Offset Y:#Offset Gobo.", &light_scalar_function_struct_struct_definition },
		{ _field_explanation, "Color Change", "" },
		{ _field_struct, "Interpolation Function", &light_color_function_struct_struct_definition },
		{ _field_real_rgb_color, "Target Color" },
		{ _field_explanation, "Channels", "" },
		{ _field_long_flags, "Light Channels:", &channelDefinitionFlags },
		{ _field_long_flags, "Shadow Channels:", &channelDefinitionFlags },
		{ _field_explanation, "Bungie Parameters", "" },
		{ _field_long_flags, "flags", &light_definition_flags },
		{ _field_real, "destroy light after:seconds#automatically destroys the light after it has existed this long (0 to disable)" },
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

} // namespace blofeld

