#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		meter_group,
		METER_TAG,
		nullptr,
		INVALID_TAG,
		meter_block );

	TAG_BLOCK_FROM_STRUCT(
		meter_block,
		"meter_block",
		1,
		meter_struct_definition);

	#define METER_STRUCT_DEFINITION_ID { 0x3B48AAFB, 0xF0C147FC, 0xAD439E06, 0xEDAF749A }
	TAG_STRUCT(
		meter_struct_definition,
		"meter_struct_definition",
		"meter_definition",
		METER_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &meter_flags },
		{ _field_tag_reference, "stencil bitmaps", &bitmap_reference$9 },
		{ _field_tag_reference, "source bitmap", &global_bitmap_reference },
		{ _field_short_integer, "stencil sequence index" },
		{ _field_short_integer, "source sequence index" },
		FIELD_PAD("KBT", nullptr, 16),
		FIELD_PAD("ON", nullptr, 4),
		{ _field_enum, "interpolate colors...", &color_interpolation_modes_enum },
		{ _field_enum, "anchor colors...", &color_anchors_enum },
		FIELD_PAD("WMTT", nullptr, 8),
		{ _field_real_argb_color, "empty color" },
		{ _field_real_argb_color, "full color" },
		FIELD_PAD("VNJW", nullptr, 20),
		{ _field_real, "unmask distance", "fade from fully masked to fully unmasked this distance beyond full (and below empty)", "meter units" },
		{ _field_real, "mask distance", "fade from fully unmasked to fully masked this distance below full (and beyond empty)", "meter units" },
		FIELD_PAD("SBQWDR", nullptr, 20),
		{ _field_data, "encoded stencil" },
		{ _field_terminator }
	};

	STRING_LIST(meter_flags, empty_string_list, 0);

	STRINGS(color_interpolation_modes_enum)
	{
		"linearly",
		"faster near empty",
		"faster near full",
		"through random noise"
	};
	STRING_LIST(color_interpolation_modes_enum, color_interpolation_modes_enum_strings, _countof(color_interpolation_modes_enum_strings));

	STRINGS(color_anchors_enum)
	{
		"at both ends",
		"at empty",
		"at full"
	};
	STRING_LIST(color_anchors_enum, color_anchors_enum_strings, _countof(color_anchors_enum_strings));

} // namespace macaque

} // namespace blofeld

