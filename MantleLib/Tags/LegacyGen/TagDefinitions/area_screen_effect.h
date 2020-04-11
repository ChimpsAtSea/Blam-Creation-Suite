#pragma once

struct nicename("area_screen_effect") tag_group('sefc') s_area_screen_effect_definition
{
	struct nicename("Screen Effect") s_screen_effect_definition
	{
		string_id_legacy nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		float __unknown2;
		s_data_reference_legacy nicename("Function") function_data_reference;
		s_undefined32_legacy __unknown3;
		float nicename("Duration") duration;
		s_data_reference_legacy nicename("Function") function1_data_reference;
		s_data_reference_legacy nicename("Function") function2_data_reference;
		string_id_legacy nicename("Trigger") trigger;
		string_id_legacy nicename("Trigger") trigger1;
		s_data_reference_legacy nicename("Function") function3_data_reference;
		float nicename("Light Intensity") light_intensity;
		float nicename("Dark Intensity") dark_intensity;
		float nicename("Primary Hue") primary_hue;
		float nicename("Secondary Hue") secondary_hue;
		float nicename("Saturation") saturation;
		float nicename("Color Muting") color_muting;
		float nicename("Contrast") contrast;
		float nicename("Darkness") darkness;
		float nicename("Brightness") brightness;
		float nicename("Dark Grain") dark_grain;
		float nicename("Bright Grain") bright_grain;
		s_colorf_legacy nicename("Tint") tint;
		s_colorf_legacy nicename("Tone") tone;
		float nicename("Holograph") holograph;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		float nicename("Horizontal Blur") horizontal_blur;
		float nicename("Vertical Blur") vertical_blur;
		s_undefined32_legacy __unknown8;
		float nicename("HUD Transparency") hud_transparency;
		float nicename("Zoom In") zoom_in;
		float nicename("Zoom Out") zoom_out;
		float nicename("Turbulence") turbulence;
		s_tag_reference_legacy nicename("Screen Shader") screen_shader_reference;
	};

	int16_t __unknown0;
	int16_t __unknown1;
	s_tag_block_legacy<s_screen_effect_definition> nicename("Screen Effect") screen_effect_block;
};

