#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(camera_fx_settings, CAMERA_FX_SETTINGS_TAG)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "exposure", &camera_fx_exposure_struct_struct_definition ),
	FIELD( _field_struct, "auto_exposure_sensitivity", &camera_fx_exposure_sensitivity_struct_struct_definition ),
	FIELD( _field_struct, "bloom_highlight{bloom_point}", &camera_fx_bloom_highlight_struct_struct_definition ),
	FIELD( _field_struct, "bloom_inherent", &camera_fx_bloom_inherent_struct_struct_definition ),
	FIELD( _field_struct, "bloom_self_illum", &camera_fx_bloom_self_illum_struct_struct_definition ),
	FIELD( _field_struct, "bloom_intensity", &camera_fx_bloom_intensity_struct_struct_definition ),
	FIELD( _field_struct, "bloom_large_color", &camera_fx_bloom_large_color_struct_struct_definition ),
	FIELD( _field_struct, "bloom_medium_color", &camera_fx_bloom_medium_color_struct_struct_definition ),
	FIELD( _field_struct, "bloom_small_color", &camera_fx_bloom_small_color_struct_struct_definition ),
	FIELD( _field_struct, "bling_intensity!", &camera_fx_bling_intensity_struct_struct_definition ),
	FIELD( _field_struct, "bling_size!", &camera_fx_bling_size_struct_struct_definition ),
	FIELD( _field_struct, "bling_angle!", &camera_fx_bling_angle_struct_struct_definition ),
	FIELD( _field_struct, "bling_count!", &camera_fx_bling_count_struct_struct_definition ),
	FIELD( _field_struct, "self_illum_preferred", &camera_fx_self_illum_preferred_struct_struct_definition ),
	FIELD( _field_struct, "self_illum_scale", &camera_fx_self_illum_scale_struct_struct_definition ),
	FIELD( _field_struct, "color_grading", &camera_fx_color_grading_struct_struct_definition ),
	FIELD( _field_struct, "filmic_tone_curve", &camera_fx_filmic_tone_curve_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_exposure_struct)
{
	FIELD( _field_custom ),
	FIELD( _field_explanation, "EXPOSURE" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "MKRGRF", 2 ),
	FIELD( _field_real, "exposure:stops#the target exposure (ONLY USED WHEN AUTO-EXPOSURE IS OFF)" ),
	FIELD( _field_real, "maximum change:stops#the maximum allowed change in exposure between frames" ),
	FIELD( _field_real, "blend speed (0-1):percent per frame#1 is instantaneous, 0.01 is a good speed, 0.001 is slower" ),
	FIELD( _field_real, "minimum:stops#the absolute target exposure is clamped to this range" ),
	FIELD( _field_real, "maximum:stops#the absolute target exposure is clamped to this range" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "auto-exposure screen brightness:[0.0001-1]#how bright you want the screen to be - auto-exposure will make it happen" ),
	FIELD( _field_custom ),
	FIELD( _field_real, "auto-exposure delay:[0.1-1]seconds#how long to wait before auto-exposure kicks in to adjust the exposure" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_exposure_sensitivity_struct)
{
	FIELD( _field_explanation, "AUTO EXPOSURE SENSITIVITY" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "MAKAMAKAHEY", 2 ),
	FIELD( _field_real, "sensitivity (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_highlight_struct)
{
	FIELD( _field_explanation, "HIGHLIGHT BLOOM" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "LOTPRER", 2 ),
	FIELD( _field_real, "highlight bloom{bloom point}" ),
	FIELD( _field_real, "maximum change" ),
	FIELD( _field_real, "blend speed (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_inherent_struct)
{
	FIELD( _field_explanation, "INHERENT BLOOM" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "ERIRLE", 2 ),
	FIELD( _field_real, "inherent bloom" ),
	FIELD( _field_real, "maximum change" ),
	FIELD( _field_real, "blend speed (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_self_illum_struct)
{
	FIELD( _field_explanation, "SELF-ILLUM BLOOM" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "ERIRLE", 2 ),
	FIELD( _field_real, "self-illum bloom bloom" ),
	FIELD( _field_real, "maximum change" ),
	FIELD( _field_real, "blend speed (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_intensity_struct)
{
	FIELD( _field_explanation, "BLOOM INTENSITY" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "SEMIFMD", 2 ),
	FIELD( _field_real, "bloom intensity" ),
	FIELD( _field_real, "maximum change" ),
	FIELD( _field_real, "blend speed (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_large_color_struct)
{
	FIELD( _field_explanation, "BLOOM LARGE COLOR" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "KKROFI", 2 ),
	FIELD( _field_real_rgb_color, "large color" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_medium_color_struct)
{
	FIELD( _field_explanation, "BLOOM MEDIUM COLOR" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "LEORPP", 2 ),
	FIELD( _field_real_rgb_color, "medium color" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bloom_small_color_struct)
{
	FIELD( _field_explanation, "BLOOM SMALL COLOR" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "JSIRWSFGAOD", 2 ),
	FIELD( _field_real_rgb_color, "small color" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bling_intensity_struct)
{
	FIELD( _field_word_flags, "flags!" ),
	FIELD( _field_pad, "QREWRER", 2 ),
	FIELD( _field_real, "bling intensity!" ),
	FIELD( _field_real, "maximum change!" ),
	FIELD( _field_real, "blend speed (0-1)!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bling_size_struct)
{
	FIELD( _field_word_flags, "flags!" ),
	FIELD( _field_pad, "LSDFPO", 2 ),
	FIELD( _field_real, "bling length!" ),
	FIELD( _field_real, "maximum change!" ),
	FIELD( _field_real, "blend speed (0-1)!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bling_angle_struct)
{
	FIELD( _field_word_flags, "flags!" ),
	FIELD( _field_pad, "ILJS", 2 ),
	FIELD( _field_real, "bling angle!" ),
	FIELD( _field_real, "maximum change!" ),
	FIELD( _field_real, "blend speed (0-1)!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_bling_count_struct)
{
	FIELD( _field_word_flags, "flags!" ),
	FIELD( _field_short_integer, "bling spikes!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_self_illum_preferred_struct)
{
	FIELD( _field_explanation, "SELF ILLUM EXPOSURE" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "JJFJFJKE", 2 ),
	FIELD( _field_real, "preferred exposure:stops#the preferred exposure for self illum" ),
	FIELD( _field_real, "maximum change" ),
	FIELD( _field_real, "blend speed (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_self_illum_scale_struct)
{
	FIELD( _field_explanation, "SELF ILLUM CHANGE" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "WOOGATCHOU", 2 ),
	FIELD( _field_real, "exposure change:[0-1]#how much the self illum is allowed to change, as a percentage of the normal exposure change" ),
	FIELD( _field_real, "maximum change" ),
	FIELD( _field_real, "blend speed (0-1)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_color_grading_struct)
{
	FIELD( _field_explanation, "Color Grading" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "SKHFDNV", 2 ),
	FIELD( _field_tag_reference, "color grading texture" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_fx_filmic_tone_curve_struct)
{
	FIELD( _field_explanation, "Filmic Tone Curve" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "MKRGRF", 2 ),
	FIELD( _field_real, "shoulder strength#How intense the shoulder is" ),
	FIELD( _field_real, "linear strength#How intense the linear portion is" ),
	FIELD( _field_real, "linear angle#Angle of linear portion of curve" ),
	FIELD( _field_real, "toe strength#How intense the toe is" ),
	FIELD( _field_real, "toe numerator#Numerator of toe slope" ),
	FIELD( _field_real, "toe denominator#Denominator of toe slope" ),
	FIELD( _field_real, "linear white point#The white point in linear space" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

