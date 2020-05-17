#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(particle_main_flags, 6)
	{
		OPTION("dies at rest"),
		OPTION("dies on structure collision"),
		OPTION("dies in water"),
		OPTION("dies in air"),
		OPTION("has sweetener"),
		OPTION("uses cheap shader"),
	};

	TAG_ENUM(particle_appearance_flags, 14)
	{
		OPTION("random u mirror"),
		OPTION("random v mirror"),
		OPTION("random starting rotation"),
		OPTION("tint from lightmap"),
		OPTION("tint from diffuse texture"),
		OPTION("bitmap authored vertically"),
		OPTION("intensity affects alpha"),
		OPTION("fade when viewed edge-on"),
		OPTION("motion blur"),
		OPTION("double-sided"),
		OPTION("low res#renders heavy overdraw particles faster"),
		OPTION("low res tighter mask#requires depth fade"),
		OPTION("never kill verts on GPU (expensive)"),
		OPTION("particle velocity relative to camera#makes parallel and perpindicular to velocity behave differently based upon camera motion"),
	};

	TAG_ENUM(particle_animation_flags, 2)
	{
		OPTION("frame animation one shot"),
		OPTION("can animate backwards"),
	};

	TAG_ENUM(particle_billboard_type_enum, 10)
	{
		OPTION("screen facing"),
		OPTION("camera facing"),
		OPTION("parallel to direction"),
		OPTION("perpendicular to direction"),
		OPTION("vertical"),
		OPTION("horizontal"),
		OPTION("local vertical"),
		OPTION("local horizontal"),
		OPTION("world (particle models)"),
		OPTION("velocity horizontal (particle models)"),
	};

	TAG_ENUM(attachment_type_enum, 4)
	{
		OPTION("birth"),
		OPTION("collision"),
		OPTION("death"),
		OPTION("first collision"),
	};

	TAG_ENUM(attachment_flags, 1)
	{
		OPTION("disabled for debugging"),
	};

	TAG_GROUP_FROM_BLOCK(particle, PARTICLE_TAG, particle_block_block );

	TAG_BLOCK_FROM_STRUCT(particle_block, 1, particle_struct_definition_struct_definition );

	TAG_BLOCK(gpu_variants_block, sizeof(c_particle_definition::s_gpu_data::s_frames)/sizeof(real_vector4d))
	{
		FIELD( _field_array, "runtime m_count!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(attachment_block, 4)
	{
		FIELD( _field_byte_flags, "flags", &attachment_flags ),
		FIELD( _field_pad, "gerrrrr", 3 ),
		FIELD( _field_tag_reference, "type" ),
		FIELD( _field_char_enum, "trigger", &attachment_type_enum ),
		FIELD( _field_byte_integer, "skip fraction:[0-127]#0 will always play, 127 will be extremely rare" ),
		FIELD( _field_char_enum, "primary scale", &game_state_type_enum ),
		FIELD( _field_char_enum, "secondary scale", &game_state_type_enum ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(gpu_sprite_block, 1)
	{
		FIELD( _field_array, "runtime gpu_sprite_array!" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(particle_struct_definition)
{
		FIELD( _field_custom ),
		FIELD( _field_long_flags, "main flags", &particle_main_flags ),
		FIELD( _field_block, "attachments", &attachment_block_block ),
		FIELD( _field_explanation, "PARTICLE APPEARANCE" ),
		FIELD( _field_long_flags, "appearance flags", &particle_appearance_flags ),
		FIELD( _field_enum, "particle billboard style", &particle_billboard_type_enum ),
		FIELD( _field_pad, "NQCLLBQ", 2 ),
		FIELD( _field_short_integer, "first sequence index" ),
		FIELD( _field_short_integer, "sequence count" ),
		FIELD( _field_real, "low res switch distance:wu#the distance at which we switch from low res (close) to high res (far)" ),
		FIELD( _field_real_point_2d, "center offset" ),
		FIELD( _field_real, "curvature:0=flat, 1=hemisphere" ),
		FIELD( _field_real, "angle fade range:degrees#degrees beyond cutoff over which particles fade" ),
		FIELD( _field_real, "angle fade cutoff:degrees#degrees away from edge-on where fade is total" ),
		FIELD( _field_real, "motion blur translation scale#affects billboard tilt from observer motion" ),
		FIELD( _field_real, "motion blur rotation scale#affects billboard tilt from observer turning" ),
		FIELD( _field_real, "motion blur aspect scale#affects aspect ratio stretching from particle and observer motion" ),
		FIELD( _field_custom, "material" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual material\?", &material_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "aspect ratio", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_struct, "color:RGB#controls how the color of the particle changes as a function of its input", &particle_property_color_struct_new_struct_definition ),
		FIELD( _field_struct, "intensity#multiplies color to give dynamic range outside [0,1]", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_struct, "alpha#separate from color, controls how the particle fades as a function of its input", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_real, "tint factor:0=modulate, 1=tint#switches between modulate (multiply) and tint(preserve whites)" ),
		FIELD( _field_explanation, "PARTICLE ANIMATION" ),
		FIELD( _field_long_flags, "animation flags", &particle_animation_flags ),
		FIELD( _field_struct, "frame index#0=first frame, 1=last frame", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_struct, "animation rate:index cycles per second", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_struct, "palette animation:v coord of palette", &particle_property_scalar_struct_new_struct_definition ),
		FIELD( _field_explanation, "Mesh data, if this is a mesh particle" ),
		FIELD( _field_tag_reference, "Model" ),
		FIELD( _field_custom, "OLD DEPRECATED shader definition" ),
		FIELD( _field_custom, "shader" ),
		FIELD( _field_custom ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual shader\?", &shader_particle_struct_definition_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_dword_integer, "runtime m_used_particle_states!" ),
		FIELD( _field_dword_integer, "runtime m_constant_per_particle_properties!" ),
		FIELD( _field_dword_integer, "runtime m_constant_over_time_properties!" ),
		FIELD( _field_struct, "runtime m_gpu_data!", &gpu_data_struct$2_struct_definition ),
		FIELD( _field_terminator )
};

TAG_STRUCT(gpu_data_struct$2)
{
		FIELD( _field_block, "runtime m_sprite!", &gpu_sprite_block_block ),
		FIELD( _field_block, "runtime m_frames!", &gpu_variants_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

