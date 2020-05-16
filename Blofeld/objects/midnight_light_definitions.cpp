#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(midnight_light_struct)
{
	FIELD( _field_long_integer, "Version!" ),
	FIELD( _field_explanation, "Dynamic/Static Shared Light Parameters" ),
	FIELD( _field_string_id, "haloLightNode:^#Light node name in DCC." ),
	FIELD( _field_long_enum, "Light Type:#Geometry shape of light." ),
	FIELD( _field_real_rgb_color, "Light Color:" ),
	FIELD( _field_struct, "Intensity:[0-1+]", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_long_enum, "Lighting Mode:#Attenuation overrides." ),
	FIELD( _field_real, "Distance Attenuation Start:#Inner penumbra start." ),
	FIELD( _field_struct, "Distance Attenuation End:#Radius or size of light", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_real, "Camera Distance Fade Start:#Distance at which we start to fade out this light" ),
	FIELD( _field_real, "Camera Distance Fade End:#Distance at which the light should be completely faded out and not seen" ),
	FIELD( _field_real, "Specular Power:#For screen-space dynamic lights" ),
	FIELD( _field_real, "Specular Intensity:#For screen-space dynamic lights" ),
	FIELD( _field_explanation, "Shared Spot Parameters" ),
	FIELD( _field_real, "Inner Cone Angle:[0-160 degrees]#Inner hotspot attenuation end." ),
	FIELD( _field_struct, "Outer Cone End:[0-160 degrees]#Angle size of spotlight.", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_long_enum, "Cone Projection Shape:#Use cone in all cases unless you have a gobo you need to project, frustum uses the full clip area of the light" ),
	FIELD( _field_explanation, "Dynamic Only Parameters" ),
	FIELD( _field_real, "Shadow Near Clip Plane" ),
	FIELD( _field_real, "Shadow Far Clip Plane" ),
	FIELD( _field_real, "Shadow Bias Offset" ),
	FIELD( _field_real_rgb_color, "Shadow Color:#Shadow tint." ),
	FIELD( _field_enum, "Dynamic Shadow Quality" ),
	FIELD( _field_enum, "Shadows:" ),
	FIELD( _field_char_enum, "Screenspace Light" ),
	FIELD( _field_char_enum, "Ignore Dynamic Objects" ),
	FIELD( _field_char_enum, "Cinema Objects Only#This should only be turned on if you have light linking data correctly setup" ),
	FIELD( _field_char_enum, "Cinema Only" ),
	FIELD( _field_char_enum, "Cinema Exclude" ),
	FIELD( _field_pad, "PADDING1", 1 ),
	FIELD( _field_char_enum, "Specular Contribution" ),
	FIELD( _field_char_enum, "Diffuse Contribution" ),
	FIELD( _field_explanation, "Dynamic Gobo" ),
	FIELD( _field_tag_reference, "Gobo Tag Path:#Bitmap file for spotlight. Cube map for point light. Gobo bitmap must be synced to xbox." ),
	FIELD( _field_struct, "Rotation:[0-360 degrees]", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_real, "Aspect Ratio:[-0-1+]#Shape length and width of Gobo." ),
	FIELD( _field_long_enum, "Tile Behavior:#Gobo texture lookup behavior when tiled." ),
	FIELD( _field_real, "Repeat X:[0-1+]#Tile Gobo." ),
	FIELD( _field_real, "Repeat Y:[0-1+]#Tile Gobo." ),
	FIELD( _field_struct, "Offset X:#Offset Gobo.", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_struct, "Offset Y:#Offset Gobo.", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_explanation, "Color Change" ),
	FIELD( _field_struct, "Interpolation Function", &light_color_function_struct_struct_definition ),
	FIELD( _field_real_rgb_color, "Target Color" ),
	FIELD( _field_explanation, "Channels" ),
	FIELD( _field_long_flags, "Light Channels:" ),
	FIELD( _field_long_flags, "Shadow Channels:" ),
	FIELD( _field_explanation, "Bungie Parameters" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "destroy light after:seconds#automatically destroys the light after it has existed this long (0 to disable)" ),
	FIELD( _field_tag_reference, "Lens Flare" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

