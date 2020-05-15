#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(camera_fx_settings, CAMERA_FX_SETTINGS_TAG)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "exposure" ),
	FIELD( _field_struct, "auto_exposure_sensitivity" ),
	FIELD( _field_struct, "bloom_highlight{bloom_point}" ),
	FIELD( _field_struct, "bloom_inherent" ),
	FIELD( _field_struct, "bloom_self_illum" ),
	FIELD( _field_struct, "bloom_intensity" ),
	FIELD( _field_struct, "bloom_large_color" ),
	FIELD( _field_struct, "bloom_medium_color" ),
	FIELD( _field_struct, "bloom_small_color" ),
	FIELD( _field_struct, "bling_intensity!" ),
	FIELD( _field_struct, "bling_size!" ),
	FIELD( _field_struct, "bling_angle!" ),
	FIELD( _field_struct, "bling_count!" ),
	FIELD( _field_struct, "self_illum_preferred" ),
	FIELD( _field_struct, "self_illum_scale" ),
	FIELD( _field_struct, "color_grading" ),
	FIELD( _field_struct, "filmic_tone_curve" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

