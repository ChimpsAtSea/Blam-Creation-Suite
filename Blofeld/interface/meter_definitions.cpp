#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM_EMPTY(meter_flags, 0);

	TAG_ENUM(color_interpolation_modes_enum, 4)
	{
		OPTION("linearly"),
		OPTION("faster near empty"),
		OPTION("faster near full"),
		OPTION("through random noise"),
	};

	TAG_ENUM(color_anchors_enum, 3)
	{
		OPTION("at both ends"),
		OPTION("at empty"),
		OPTION("at full"),
	};

	TAG_GROUP_FROM_BLOCK(meter, METER_TAG, meter_block_block );

	TAG_BLOCK_FROM_STRUCT(meter_block, 1, meter_struct_definition_struct_definition );

TAG_STRUCT(meter_struct_definition)
{
		FIELD( _field_long_flags, "flags", &meter_flags ),
		FIELD( _field_tag_reference, "stencil bitmaps#two bitmaps specifying the mask and the meter levels" ),
		FIELD( _field_tag_reference, "source bitmap#optional bitmap to draw into the unmasked regions of the meter (modulated by the colors below)" ),
		FIELD( _field_short_integer, "stencil sequence index" ),
		FIELD( _field_short_integer, "source sequence index" ),
		FIELD( _field_pad, "KBT", 16 ),
		FIELD( _field_pad, "ON", 4 ),
		FIELD( _field_enum, "interpolate colors...", &color_interpolation_modes_enum ),
		FIELD( _field_enum, "anchor colors...", &color_anchors_enum ),
		FIELD( _field_pad, "WMTT", 8 ),
		FIELD( _field_real_argb_color, "empty color" ),
		FIELD( _field_real_argb_color, "full color" ),
		FIELD( _field_pad, "VNJW", 20 ),
		FIELD( _field_real, "unmask distance:meter units#fade from fully masked to fully unmasked this distance beyond full (and below empty)" ),
		FIELD( _field_real, "mask distance:meter units#fade from fully unmasked to fully masked this distance below full (and beyond empty)" ),
		FIELD( _field_pad, "SBQWDR", 20 ),
		FIELD( _field_data, "encoded stencil" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

