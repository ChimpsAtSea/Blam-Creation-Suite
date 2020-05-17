#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_STRUCT(midnight_light_struct)
	{
		FIELD( _field_long_integer, "Version!" ),
		FIELD( _field_explanation, "Dynamic/Static Shared Light Parameters" ),
		FIELD( _field_string_id, "haloLightNode:^#Light node name in DCC." ),
		FIELD( _field_long_enum, "Light Type:#Geometry shape of light.", &midnight_light_type_enum_definition ),
		FIELD( _field_real_rgb_color, "Light Color:" ),
		FIELD( _field_struct, "Intensity:[0-1+]", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_long_enum, "Lighting Mode:#Attenuation overrides.", &midnight_lighting_mode_definition ),
		FIELD( _field_real, "Distance Attenuation Start:#Inner penumbra start." ),
		FIELD( _field_struct, "Distance Attenuation End:#Radius or size of light", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_real, "Camera Distance Fade Start:#Distance at which we start to fade out this light" ),
		FIELD( _field_real, "Camera Distance Fade End:#Distance at which the light should be completely faded out and not seen" ),
		FIELD( _field_real, "Specular Power:#For screen-space dynamic lights" ),
		FIELD( _field_real, "Specular Intensity:#For screen-space dynamic lights" ),
		FIELD( _field_explanation, "Shared Spot Parameters" ),
		FIELD( _field_real, "Inner Cone Angle:[0-160 degrees]#Inner hotspot attenuation end." ),
		FIELD( _field_struct, "Outer Cone End:[0-160 degrees]#Angle size of spotlight.", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_long_enum, "Cone Projection Shape:#Use cone in all cases unless you have a gobo you need to project, frustum uses the full clip area of the light", &midnight_projection_definition ),
		FIELD( _field_explanation, "Dynamic Only Parameters" ),
		FIELD( _field_real, "Shadow Near Clip Plane" ),
		FIELD( _field_real, "Shadow Far Clip Plane" ),
		FIELD( _field_real, "Shadow Bias Offset" ),
		FIELD( _field_real_rgb_color, "Shadow Color:#Shadow tint." ),
		FIELD( _field_enum, "Dynamic Shadow Quality", &midnight_dynamic_shadow_quality_modes ),
		FIELD( _field_enum, "Shadows:", &midnight_boolean_enum_definition ),
		FIELD( _field_char_enum, "Screenspace Light", &midnight_boolean_enum_definition ),
		FIELD( _field_char_enum, "Ignore Dynamic Objects", &midnight_boolean_enum_definition ),
		FIELD( _field_char_enum, "Cinema Objects Only#This should only be turned on if you have light linking data correctly setup", &midnight_boolean_enum_definition ),
		FIELD( _field_char_enum, "Cinema Only", &midnight_boolean_enum_definition ),
		FIELD( _field_char_enum, "Cinema Exclude", &midnight_boolean_enum_definition ),
		FIELD( _field_pad, "PADDING1", 1 ),
		FIELD( _field_char_enum, "Specular Contribution", &midnight_boolean_enum_definition ),
		FIELD( _field_char_enum, "Diffuse Contribution", &midnight_boolean_enum_definition ),
		FIELD( _field_explanation, "Dynamic Gobo" ),
		FIELD( _field_tag_reference, "Gobo Tag Path:#Bitmap file for spotlight. Cube map for point light. Gobo bitmap must be synced to xbox." ),
		FIELD( _field_struct, "Rotation:[0-360 degrees]", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_real, "Aspect Ratio:[-0-1+]#Shape length and width of Gobo." ),
		FIELD( _field_long_enum, "Tile Behavior:#Gobo texture lookup behavior when tiled.", &midnight_gobo_tile_behavior_enum_definition ),
		FIELD( _field_real, "Repeat X:[0-1+]#Tile Gobo." ),
		FIELD( _field_real, "Repeat Y:[0-1+]#Tile Gobo." ),
		FIELD( _field_struct, "Offset X:#Offset Gobo.", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_struct, "Offset Y:#Offset Gobo.", &light_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "Color Change" ),
		FIELD( _field_struct, "Interpolation Function", &light_color_function_struct_struct_definition ),
		FIELD( _field_real_rgb_color, "Target Color" ),
		FIELD( _field_explanation, "Channels" ),
		FIELD( _field_long_flags, "Light Channels:", &channelDefinitionFlags ),
		FIELD( _field_long_flags, "Shadow Channels:", &channelDefinitionFlags ),
		FIELD( _field_explanation, "Bungie Parameters" ),
		FIELD( _field_long_flags, "flags", &light_definition_flags ),
		FIELD( _field_real, "destroy light after:seconds#automatically destroys the light after it has existed this long (0 to disable)" ),
		FIELD( _field_tag_reference, "Lens Flare" ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(midnight_light_type_enum_definition, 5)
	{
		OPTION("Point"),
		OPTION("Spot"),
		OPTION("Directional"),
		OPTION("Area"),
		OPTION("Sun"),
	};

	TAG_ENUM(midnight_lighting_mode_definition, 2)
	{
		OPTION("Physically Correct"),
		OPTION("Artistic"),
	};

	TAG_ENUM(midnight_projection_definition, 2)
	{
		OPTION("Cone"),
		OPTION("Frustum"),
	};

	TAG_ENUM(midnight_boolean_enum_definition, 2)
	{
		OPTION("Off"),
		OPTION("On"),
	};

	TAG_ENUM(midnight_dynamic_shadow_quality_modes, 2)
	{
		OPTION("Normal"),
		OPTION("Expensive (cinematics only)"),
	};

	TAG_ENUM(midnight_gobo_tile_behavior_enum_definition, 3)
	{
		OPTION("Clamp"),
		OPTION("Repeat"),
		OPTION("Mirror"),
	};

	TAG_ENUM(channelDefinitionFlags, 32)
	{
		OPTION("0"),
		OPTION("1"),
		OPTION("2"),
		OPTION("3"),
		OPTION("4"),
		OPTION("5"),
		OPTION("6"),
		OPTION("7"),
		OPTION("8"),
		OPTION("9"),
		OPTION("10"),
		OPTION("11"),
		OPTION("12"),
		OPTION("13"),
		OPTION("14"),
		OPTION("15"),
		OPTION("16"),
		OPTION("17"),
		OPTION("18"),
		OPTION("19"),
		OPTION("20"),
		OPTION("21"),
		OPTION("22"),
		OPTION("23"),
		OPTION("24"),
		OPTION("25"),
		OPTION("26"),
		OPTION("27"),
		OPTION("28"),
		OPTION("29"),
		OPTION("30"),
		OPTION("31"),
	};

	TAG_ENUM(light_definition_flags, 12)
	{
		OPTION("allow shadows and gels!#"),
		OPTION("shadow casting#turns on shadow casting"),
		OPTION("render first person only#only render when camera is 1st person"),
		OPTION("render third person only#don\'t render when camera is 1st person"),
		OPTION("dont render splitscreen#no rendering this light in splitscreen mode"),
		OPTION("render while active camo#keep rendering this light when the attached player goes camo"),
		OPTION("render in multiplayer override#overrides game settings that disable dynamic lights"),
		OPTION("move to camera in first person#moves the light to match the camera"),
		OPTION("never priority cull#never cull this light because of low priority"),
		OPTION("affected by game_can_use_flashlights"),
		OPTION("screenspace specular lighting#uses expensive specular lighting on screenspace lights"),
		OPTION("always on for weapon#even it is dropped"),
	};

} // namespace blofeld

