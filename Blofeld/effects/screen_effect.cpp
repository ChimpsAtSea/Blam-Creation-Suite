#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(area_screen_effect_global_flags_definition, 6)
	{
		OPTION("play sequentially - ignore delay settings"),
		OPTION("debug this screen effect"),
		OPTION("force delete when attached to dead object"),
		OPTION("force max one per object"),
		OPTION("force looping (dangerous; lasts forever)"),
		OPTION("only spawn killcam version during killcam"),
	};

	TAG_ENUM(area_screen_effect_global_hidden_flags_definition, 2)
	{
		OPTION("update thread"),
		OPTION("render thread"),
	};

	TAG_ENUM(area_screen_effect_flags_definition, 8)
	{
		OPTION("debug disable"),
		OPTION("allow effect outside radius"),
		OPTION("unattached"),
		OPTION("first person{first person only}"),
		OPTION("third person{third person only}"),
		OPTION("disable camera falloffs{cinematic}#disables distance and angle falloffs"),
		OPTION("only affects attached object"),
		OPTION("draw precisely one (ask Bill before you check this)"),
	};

	TAG_ENUM(area_screen_effect_hidden_flags_definition, 2)
	{
		OPTION("update thread"),
		OPTION("render thread"),
	};

	TAG_GROUP_FROM_BLOCK(area_screen_effect, AREA_SCREEN_EFFECT_TAG, area_screen_effect_block_block );

	TAG_BLOCK_FROM_STRUCT(area_screen_effect_block, 1, area_screen_effect_struct_definition_struct_definition );

	TAG_BLOCK(single_screen_effect, s_area_screen_effect_definition::k_maximum_effects_per_tag)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_word_flags, "flags", &area_screen_effect_flags_definition ),
		FIELD( _field_word_flags, "hidden flags!", &area_screen_effect_hidden_flags_definition ),
		FIELD( _field_explanation, "DISTANCE FALLOFF" ),
		FIELD( _field_real, "maximum distance:world units#the maximum distance this screen effect will affect" ),
		FIELD( _field_struct, "distance falloff", &screen_effect_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "TIME EVOLUTION" ),
		FIELD( _field_real, "delay:seconds#the effect will start after this many seconds (ignored if the play sequentially flag is set)" ),
		FIELD( _field_real, "lifetime:seconds#the effect is destroyed after this many seconds (0 = never dies)" ),
		FIELD( _field_struct, "time falloff", &screen_effect_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "ANGLE FALLOFF" ),
		FIELD( _field_struct, "angle falloff", &screen_effect_scalar_function_struct_struct_definition ),
		FIELD( _field_explanation, "OBJECT FALLOFF" ),
		FIELD( _field_struct, "object falloff", &screen_effect_scalar_object_function_struct_struct_definition ),
		FIELD( _field_explanation, "EFFECTS" ),
		FIELD( _field_tag_reference, "color grading look-up-texture" ),
		FIELD( _field_real, "runtime color grading strength!:[do not edit]#do not edit" ),
		FIELD( _field_real, "exposure boost:stops#increase in exposure" ),
		FIELD( _field_real, "exposure deboost:stops#decrease in exposure" ),
		FIELD( _field_real, "hue left:degrees [0-360]#shifts hue R->G->B" ),
		FIELD( _field_real, "hue right:degrees [0-360]#shifts hue B->G->R" ),
		FIELD( _field_real, "saturation:[0-1]#increases saturation" ),
		FIELD( _field_real, "desaturation:[0-1]#decreases saturation" ),
		FIELD( _field_real, "contrast enhance:[0-1]#contrast increase" ),
		FIELD( _field_real, "gamma enhance:[0-10]#gamma increase" ),
		FIELD( _field_real, "gamma reduce:[0-10]#gamma increase" ),
		FIELD( _field_real, "bright noise:[0-1]#add bright noise contribution, 0 turns it off, 1: full on" ),
		FIELD( _field_real, "dark noise:[0-1]#add dark noise contribution, 0 turns it off, 1: full on" ),
		FIELD( _field_real_rgb_color, "color filter#this color is multiplied on top" ),
		FIELD( _field_real_rgb_color, "color floor#this color is subtracted" ),
		FIELD( _field_real_fraction, "color replace strength:[0-1]#used to blend in the color replace below" ),
		FIELD( _field_real_rgb_color, "color replace#this color is blended in place of the screen\'s color" ),
		FIELD( _field_real, "tron:[0-1]#adds a full-screen tron effect" ),
		FIELD( _field_real, "motion suck:[-2, 2]#adds motion-blur towards or away from this screen effect" ),
		FIELD( _field_real, "bloom buffer motion suck:[-2, 2]#adds cheap bloom buffer motion-blur towards or away from this screen effect" ),
		FIELD( _field_real_vector_3d, "motion suck direction!:[do not edit]#do not edit" ),
		FIELD( _field_real, "horizontal blur:[0-10] expensive#blurs the entire screen" ),
		FIELD( _field_real, "vertical blur:[0-10] expensive#blurs the entire screen" ),
		FIELD( _field_real, "vision mode:[0-1]#turns on the global vision mode" ),
		FIELD( _field_real, "hud fade:[0-1]#fades the chud" ),
		FIELD( _field_real, "fov in:[0-1]#zooms in the field of view" ),
		FIELD( _field_real, "fov out:[0-1]#zooms out the field of view" ),
		FIELD( _field_real, "screen shake:[0-1]#shakes the entire screen" ),
		FIELD( _field_tag_reference, "shader effect#applies this shader to the entire screen" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(area_screen_effect_struct_definition)
{
		FIELD( _field_word_flags, "global flags", &area_screen_effect_global_flags_definition ),
		FIELD( _field_word_flags, "global hidden flags!", &area_screen_effect_global_hidden_flags_definition ),
		FIELD( _field_block, "screen effects", &single_screen_effect_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(screen_effect_scalar_function_struct)
{
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
};

TAG_STRUCT(screen_effect_scalar_object_function_struct)
{
		FIELD( _field_string_id, "Input Variable!" ),
		FIELD( _field_string_id, "Range Variable!" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

