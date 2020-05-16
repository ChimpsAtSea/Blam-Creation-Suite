#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(particle_struct_definition)
{
	FIELD( _field_custom ),
	FIELD( _field_long_flags, "main flags" ),
	FIELD( _field_block, "attachments", &attachment_block ),
	FIELD( _field_explanation, "PARTICLE APPEARANCE" ),
	FIELD( _field_long_flags, "appearance flags" ),
	FIELD( _field_enum, "particle billboard style" ),
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
	FIELD( _field_long_flags, "animation flags" ),
	FIELD( _field_struct, "frame index#0=first frame, 1=last frame", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "animation rate:index cycles per second", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "palette animation:v coord of palette", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_explanation, "Mesh data, if this is a mesh particle" ),
	FIELD( _field_tag_reference, "Model" ),
	FIELD( _field_custom, "OLD DEPRECATED shader definition" ),
	FIELD( _field_custom, "shader" ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual shader\?", &shader_particle_struct_definition$2_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_dword_integer, "runtime m_used_particle_states!" ),
	FIELD( _field_dword_integer, "runtime m_constant_per_particle_properties!" ),
	FIELD( _field_dword_integer, "runtime m_constant_over_time_properties!" ),
	FIELD( _field_struct, "runtime m_gpu_data!", &gpu_data_struct$2_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(gpu_data_struct$2)
{
	FIELD( _field_block, "runtime m_sprite!", &gpu_sprite_block ),
	FIELD( _field_block, "runtime m_frames!", &gpu_variants_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gpu_variants_block, sizeof(c_particle_definition::s_gpu_data::s_frames)/sizeof(real_vector4d))
{
	FIELD( _field_array, "runtime m_count!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(attachment_block, 4)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "gerrrrr", 3 ),
	FIELD( _field_tag_reference, "type" ),
	FIELD( _field_char_enum, "trigger" ),
	FIELD( _field_byte_integer, "skip fraction:[0-127]#0 will always play, 127 will be extremely rare" ),
	FIELD( _field_char_enum, "primary scale" ),
	FIELD( _field_char_enum, "secondary scale" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gpu_sprite_block, 1)
{
	FIELD( _field_array, "runtime gpu_sprite_array!" ),
	FIELD( _field_terminator )
};

TAG_GROUP(particle_block, PARTICLE_TAG)
{
	FIELD( _field_custom ),
	FIELD( _field_long_flags, "main flags" ),
	FIELD( _field_block, "attachments", &attachment_block ),
	FIELD( _field_explanation, "PARTICLE APPEARANCE" ),
	FIELD( _field_long_flags, "appearance flags" ),
	FIELD( _field_enum, "particle billboard style" ),
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
	FIELD( _field_long_flags, "animation flags" ),
	FIELD( _field_struct, "frame index#0=first frame, 1=last frame", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "animation rate:index cycles per second", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "palette animation:v coord of palette", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_explanation, "Mesh data, if this is a mesh particle" ),
	FIELD( _field_tag_reference, "Model" ),
	FIELD( _field_custom, "OLD DEPRECATED shader definition" ),
	FIELD( _field_custom, "shader" ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual shader\?", &shader_particle_struct_definition$2_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_dword_integer, "runtime m_used_particle_states!" ),
	FIELD( _field_dword_integer, "runtime m_constant_per_particle_properties!" ),
	FIELD( _field_dword_integer, "runtime m_constant_over_time_properties!" ),
	FIELD( _field_struct, "runtime m_gpu_data!", &gpu_data_struct$2_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

