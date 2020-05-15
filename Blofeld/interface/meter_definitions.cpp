#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(meter, METER_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_tag_reference, "stencil bitmaps#two bitmaps specifying the mask and the meter levels" },
	{ _field_tag_reference, "source bitmap#optional bitmap to draw into the unmasked regions of the meter (modulated by the colors below)" },
	{ _field_short_integer, "stencil sequence index" },
	{ _field_short_integer, "source sequence index" },
	{ _field_pad, "KBT", 16 },
	{ _field_pad, "ON", 4 },
	{ _field_enum, "interpolate colors..." },
	{ _field_enum, "anchor colors..." },
	{ _field_pad, "WMTT", 8 },
	{ _field_real_argb_color, "empty color" },
	{ _field_real_argb_color, "full color" },
	{ _field_pad, "VNJW", 20 },
	{ _field_real, "unmask distance:meter units#fade from fully masked to fully unmasked this distance beyond full (and below empty)" },
	{ _field_real, "mask distance:meter units#fade from fully unmasked to fully masked this distance below full (and beyond empty)" },
	{ _field_pad, "SBQWDR", 20 },
	{ _field_data, "encoded stencil" },
	{ _field_terminator },
};

} // namespace blofeld

