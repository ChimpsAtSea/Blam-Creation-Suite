#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
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
	TAG_STRUCT_V6(
		meter_struct_definition,
		"meter_struct_definition",
		"meter_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		METER_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &meter_flags },
		{ _field_tag_reference, "stencil bitmaps", "two bitmaps specifying the mask and the meter levels", &bitmap_reference$9 },
		{ _field_tag_reference, "source bitmap", "optional bitmap to draw into the unmasked regions of the meter (modulated by the colors below)", &global_bitmap_reference },
		{ _field_short_integer, "stencil sequence index" },
		{ _field_short_integer, "source sequence index" },
		FIELD_PAD_EX("KBT", nullptr, FIELD_FLAG_NONE, 16),
		FIELD_PAD_EX("ON", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_enum, "interpolate colors...", &color_interpolation_modes_enum },
		{ _field_enum, "anchor colors...", &color_anchors_enum },
		FIELD_PAD_EX("WMTT", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_argb_color, "empty color" },
		{ _field_real_argb_color, "full color" },
		FIELD_PAD_EX("VNJW", nullptr, FIELD_FLAG_NONE, 20),
		{ _field_real, "unmask distance", "fade from fully masked to fully unmasked this distance beyond full (and below empty)", "meter units" },
		{ _field_real, "mask distance", "fade from fully unmasked to fully masked this distance below full (and beyond empty)", "meter units" },
		FIELD_PAD_EX("SBQWDR", nullptr, FIELD_FLAG_NONE, 20),
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



} // namespace blofeld

