#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(camera_fx_settings, CAMERA_FX_SETTINGS_TAG)
{
	{ _field_custom },
	{ _field_struct, "exposure" },
	{ _field_struct, "auto_exposure_sensitivity" },
	{ _field_struct, "bloom_highlight{bloom_point}" },
	{ _field_struct, "bloom_inherent" },
	{ _field_struct, "bloom_self_illum" },
	{ _field_struct, "bloom_intensity" },
	{ _field_struct, "bloom_large_color" },
	{ _field_struct, "bloom_medium_color" },
	{ _field_struct, "bloom_small_color" },
	{ _field_struct, "bling_intensity!" },
	{ _field_struct, "bling_size!" },
	{ _field_struct, "bling_angle!" },
	{ _field_struct, "bling_count!" },
	{ _field_struct, "self_illum_preferred" },
	{ _field_struct, "self_illum_scale" },
	{ _field_struct, "color_grading" },
	{ _field_struct, "filmic_tone_curve" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

