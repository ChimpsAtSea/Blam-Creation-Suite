#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		ssao_definition_group,
		SSAO_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		ssao_definition_block );

	TAG_BLOCK_FROM_STRUCT(
		ssao_definition_block,
		"ssao_definition_block",
		1,
		ssao_definition_struct_definition);

	#define SSAO_DEFINITION_STRUCT_DEFINITION_ID { 0x677644E3, 0xF3A54E06, 0x84199B42, 0xBA8F8DAF }
	TAG_STRUCT(
		ssao_definition_struct_definition,
		"ssao_definition_struct_definition",
		"s_ssao_definition",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SSAO_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_char_enum, "downsample", FIELD_FLAG_READ_ONLY, &ssao_downsample_enum_definition },
		{ _field_char_enum, "ssao type", FIELD_FLAG_READ_ONLY, &ssao_type_enum_definition },
		{ _field_byte_integer, "version", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("BKGKKELQIF", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_real, "hdao ambient shadow", "how much ssao shadowing darkens the ambient lighting" },
		{ _field_real, "hdao point shadow", "how much ssao shadowing darkens the point lighting ie the sun" },
		{ _field_real, "sharp ambient shadow", "how much the sharp dynamic shadows darken ambient lighting" },
		{ _field_real, "sharp point shadow", "how much the sharp dynamic shadows darken the point lighting ie the sun" },
		{ _field_real, "max intensity", "unshadowed areas will have this relative intensity" },
		{ _field_real, "min intensity", "fully shadowed areas will have this relative intensity" },
		{ _field_real, "falloff width", "controls the shape of the shadow falloff curve" },
		{ _field_real, "corner scale", "controls shadow sensitivity to corners" },
		{ _field_real, "corner bias", "offsets corner sensitivity, generally to ignore shallow corners" },
		{ _field_real, "bounds scale", "controls the maximum shadow distance, as a ratio of the distance to the object" },
		{ _field_real, "bounds offset", "offsets the maximum shadow distance, generally to make a region of full darkness before fading" },
		{ _field_real, "near clip", "completely removes ssao on anything closer than this", "world units" },
		{ _field_real, "near fade width", "distance over which the ssao fades in", "world units" },
		{ _field_real, "far clip", "completely removes ssao on anything farther than this", "world units" },
		{ _field_real, "far fade width", "distance over which the ssao fades in", "world units" },
		{ _field_real_argb_color, "runtime_data_0", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_argb_color, "runtime_data_1", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_argb_color, "runtime_data_2", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_argb_color, "runtime_data_3", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_argb_color, "runtime_data_4", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_argb_color, "runtime_data_5", FIELD_FLAG_UNKNOWN0 },
		{ _field_real_argb_color, "runtime_data_7", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(ssao_downsample_enum_definition)
	{
		"block downsample",
		"clover downsample"
	};
	STRING_LIST(ssao_downsample_enum_definition, ssao_downsample_enum_definition_strings, _countof(ssao_downsample_enum_definition_strings));

	STRINGS(ssao_type_enum_definition)
	{
		"off",
		"hdao large 32 sample",
		"hdao large 64 predicated",
		"hdao small 24 sample",
		"hdao screenshot",
		"debug mask",
		"ssao midnight 16 sample"
	};
	STRING_LIST(ssao_type_enum_definition, ssao_type_enum_definition_strings, _countof(ssao_type_enum_definition_strings));

	TAG_REFERENCE(global_ssao_definition_reference, SSAO_DEFINITION_TAG);

} // namespace macaque

} // namespace blofeld

