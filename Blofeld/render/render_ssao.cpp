#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(ssao_definition, SSAO_DEFINITION_TAG, ssao_definition_block_block );

TAG_BLOCK_FROM_STRUCT(ssao_definition_block, 1, ssao_definition_struct_definition_struct_definition );

TAG_STRUCT(ssao_definition_struct_definition)
{
	FIELD( _field_char_enum, "downsample*" ),
	FIELD( _field_char_enum, "ssao type*" ),
	FIELD( _field_byte_integer, "version!" ),
	FIELD( _field_pad, "BKGKKELQIF", 1 ),
	FIELD( _field_real, "hdao ambient shadow#how much ssao shadowing darkens the ambient lighting" ),
	FIELD( _field_real, "hdao point shadow#how much ssao shadowing darkens the point lighting ie the sun" ),
	FIELD( _field_real, "sharp ambient shadow#how much the sharp dynamic shadows darken ambient lighting" ),
	FIELD( _field_real, "sharp point shadow#how much the sharp dynamic shadows darken the point lighting ie the sun" ),
	FIELD( _field_real, "max intensity:[0-1]#unshadowed areas will have this relative intensity" ),
	FIELD( _field_real, "min intensity:[0-1]#fully shadowed areas will have this relative intensity" ),
	FIELD( _field_real, "falloff width#controls the shape of the shadow falloff curve" ),
	FIELD( _field_real, "corner scale#controls shadow sensitivity to corners" ),
	FIELD( _field_real, "corner bias#offsets corner sensitivity, generally to ignore shallow corners" ),
	FIELD( _field_real, "bounds scale#controls the maximum shadow distance, as a ratio of the distance to the object" ),
	FIELD( _field_real, "bounds offset#offsets the maximum shadow distance, generally to make a region of full darkness before fading" ),
	FIELD( _field_real, "near clip:world units#completely removes ssao on anything closer than this" ),
	FIELD( _field_real, "near fade width:world units#distance over which the ssao fades in" ),
	FIELD( _field_real, "far clip:world units#completely removes ssao on anything farther than this" ),
	FIELD( _field_real, "far fade width:world units#distance over which the ssao fades in" ),
	FIELD( _field_real_argb_color, "runtime_data_0!" ),
	FIELD( _field_real_argb_color, "runtime_data_1!" ),
	FIELD( _field_real_argb_color, "runtime_data_2!" ),
	FIELD( _field_real_argb_color, "runtime_data_3!" ),
	FIELD( _field_real_argb_color, "runtime_data_4!" ),
	FIELD( _field_real_argb_color, "runtime_data_5!" ),
	FIELD( _field_real_argb_color, "runtime_data_7!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

