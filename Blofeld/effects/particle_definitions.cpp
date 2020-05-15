#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(attachment, 4)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "gerrrrr", 3 },
	{ _field_tag_reference, "type" },
	{ _field_char_enum, "trigger" },
	{ _field_byte_integer, "skip fraction:[0-127]#0 will always play, 127 will be extremely rare" },
	{ _field_char_enum, "primary scale" },
	{ _field_char_enum, "secondary scale" },
	{ _field_terminator },
};

TAG_GROUP(particle, PARTICLE_TAG)
{
	{ _field_custom },
	{ _field_long_flags, "main flags" },
	{ _field_block, "attachments", &attachment_block },
	{ _field_explanation, "PARTICLE APPEARANCE" },
	{ _field_long_flags, "appearance flags" },
	{ _field_enum, "particle billboard style" },
	{ _field_pad, "NQCLLBQ", 2 },
	{ _field_short_integer, "first sequence index" },
	{ _field_short_integer, "sequence count" },
	{ _field_real, "low res switch distance:wu#the distance at which we switch from low res (close) to high res (far)" },
	{ _field_real_point_2d, "center offset" },
	{ _field_real, "curvature:0=flat, 1=hemisphere" },
	{ _field_real, "angle fade range:degrees#degrees beyond cutoff over which particles fade" },
	{ _field_real, "angle fade cutoff:degrees#degrees away from edge-on where fade is total" },
	{ _field_real, "motion blur translation scale#affects billboard tilt from observer motion" },
	{ _field_real, "motion blur rotation scale#affects billboard tilt from observer turning" },
	{ _field_real, "motion blur aspect scale#affects aspect ratio stretching from particle and observer motion" },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_custom },
	{ _field_struct, "aspect ratio" },
	{ _field_struct, "color:RGB#controls how the color of the particle changes as a function of its input" },
	{ _field_struct, "intensity#multiplies color to give dynamic range outside [0,1]" },
	{ _field_struct, "alpha#separate from color, controls how the particle fades as a function of its input" },
	{ _field_real, "tint factor:0=modulate, 1=tint#switches between modulate (multiply) and tint(preserve whites)" },
	{ _field_explanation, "PARTICLE ANIMATION" },
	{ _field_long_flags, "animation flags" },
	{ _field_struct, "frame index#0=first frame, 1=last frame" },
	{ _field_struct, "animation rate:index cycles per second" },
	{ _field_struct, "palette animation:v coord of palette" },
	{ _field_explanation, "Mesh data, if this is a mesh particle" },
	{ _field_tag_reference, "Model" },
	{ _field_custom, "OLD DEPRECATED shader definition" },
	{ _field_custom, "shader" },
	{ _field_custom },
	{ _field_custom },
	{ _field_struct, "actual shader\?" },
	{ _field_custom },
	{ _field_dword_integer, "runtime m_used_particle_states!" },
	{ _field_dword_integer, "runtime m_constant_per_particle_properties!" },
	{ _field_dword_integer, "runtime m_constant_over_time_properties!" },
	{ _field_struct, "runtime m_gpu_data!" },
	{ _field_terminator },
};

} // namespace blofeld

