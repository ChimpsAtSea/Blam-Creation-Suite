#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(ssao_definition, SSAO_DEFINITION_TAG)
{
	{ _field_char_enum, "downsample*" },
	{ _field_char_enum, "ssao type*" },
	{ _field_byte_integer, "version!" },
	{ _field_pad, "BKGKKELQIF", 1 },
	{ _field_real, "hdao ambient shadow#how much ssao shadowing darkens the ambient lighting" },
	{ _field_real, "hdao point shadow#how much ssao shadowing darkens the point lighting ie the sun" },
	{ _field_real, "sharp ambient shadow#how much the sharp dynamic shadows darken ambient lighting" },
	{ _field_real, "sharp point shadow#how much the sharp dynamic shadows darken the point lighting ie the sun" },
	{ _field_real, "max intensity:[0-1]#unshadowed areas will have this relative intensity" },
	{ _field_real, "min intensity:[0-1]#fully shadowed areas will have this relative intensity" },
	{ _field_real, "falloff width#controls the shape of the shadow falloff curve" },
	{ _field_real, "corner scale#controls shadow sensitivity to corners" },
	{ _field_real, "corner bias#offsets corner sensitivity, generally to ignore shallow corners" },
	{ _field_real, "bounds scale#controls the maximum shadow distance, as a ratio of the distance to the object" },
	{ _field_real, "bounds offset#offsets the maximum shadow distance, generally to make a region of full darkness before fading" },
	{ _field_real, "near clip:world units#completely removes ssao on anything closer than this" },
	{ _field_real, "near fade width:world units#distance over which the ssao fades in" },
	{ _field_real, "far clip:world units#completely removes ssao on anything farther than this" },
	{ _field_real, "far fade width:world units#distance over which the ssao fades in" },
	{ _field_real_argb_color, "runtime_data_0!" },
	{ _field_real_argb_color, "runtime_data_1!" },
	{ _field_real_argb_color, "runtime_data_2!" },
	{ _field_real_argb_color, "runtime_data_3!" },
	{ _field_real_argb_color, "runtime_data_4!" },
	{ _field_real_argb_color, "runtime_data_5!" },
	{ _field_real_argb_color, "runtime_data_7!" },
	{ _field_terminator },
};

} // namespace blofeld

