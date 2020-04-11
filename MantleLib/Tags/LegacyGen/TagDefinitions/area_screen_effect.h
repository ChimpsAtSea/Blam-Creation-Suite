#pragma once

struct nicename("area_screen_effect") tag_group('sefc') s_area_screen_effect_definition
{
	struct nicename("Screen Effect") s_screen_effect_definition
	{
		string_id nicename("Name") name;
		int16_t __unknown0;
		int16_t __unknown1;
		float __unknown2;
		DataReference nicename("Function") function_data_reference;
		Undefined32 __unknown3;
		float nicename("Duration") duration;
		DataReference nicename("Function") function1_data_reference;
		DataReference nicename("Function") function2_data_reference;
		string_id nicename("Trigger") trigger;
		string_id nicename("Trigger") trigger1;
		DataReference nicename("Function") function3_data_reference;
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
		colorf nicename("Tint") tint;
		colorf nicename("Tone") tone;
		float nicename("Holograph") holograph;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		float nicename("Horizontal Blur") horizontal_blur;
		float nicename("Vertical Blur") vertical_blur;
		Undefined32 __unknown8;
		float nicename("HUD Transparency") hud_transparency;
		float nicename("Zoom In") zoom_in;
		float nicename("Zoom Out") zoom_out;
		float nicename("Turbulence") turbulence;
		TagReference nicename("Screen Shader") screen_shader_reference;
	};

	int16_t __unknown0;
	int16_t __unknown1;
	s_tag_block_definition<s_screen_effect_definition> nicename("Screen Effect") screen_effect_block;
};

