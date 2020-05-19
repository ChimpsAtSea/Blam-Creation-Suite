#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(meter, METER_TAG, meter_block_block );

	TAG_BLOCK_FROM_STRUCT(meter_block, 1, meter_struct_definition_struct_definition );

	TAG_STRUCT(meter_struct_definition)
	{
		{ _field_long_flags, "flags", &meter_flags },
		{ _field_tag_reference, "stencil bitmaps#two bitmaps specifying the mask and the meter levels", &bitmap_reference$9 },
		{ _field_tag_reference, "source bitmap#optional bitmap to draw into the unmasked regions of the meter (modulated by the colors below)", &global_bitmap_reference },
		{ _field_short_integer, "stencil sequence index" },
		{ _field_short_integer, "source sequence index" },
		{ _field_pad, "KBT", 16 },
		{ _field_pad, "ON", 4 },
		{ _field_enum, "interpolate colors...", &color_interpolation_modes_enum },
		{ _field_enum, "anchor colors...", &color_anchors_enum },
		{ _field_pad, "WMTT", 8 },
		{ _field_real_argb_color, "empty color" },
		{ _field_real_argb_color, "full color" },
		{ _field_pad, "VNJW", 20 },
		{ _field_real, "unmask distance:meter units#fade from fully masked to fully unmasked this distance beyond full (and below empty)" },
		{ _field_real, "mask distance:meter units#fade from fully unmasked to fully masked this distance below full (and beyond empty)" },
		{ _field_pad, "SBQWDR", 20 },
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

