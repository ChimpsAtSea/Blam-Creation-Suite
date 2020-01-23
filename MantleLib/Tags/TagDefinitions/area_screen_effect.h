#pragma once

struct nicename("Area Screen Effect") group('sefc') s_area_screen_effect_definition
{
	struct nicename("Screen Effect") s_screen_effect_block_definition;

	int16_t __unknown; 
	int16_t __unknown2; 
	s_tag_block_definition<s_screen_effect_block_definition> nicename("Screen Effect") screen_effect_block; 

	struct nicename("screen_effect") s_screen_effect_block_definition
	{
		string_id nicename("Name") name; 
		int16_t __unknown; 
		int16_t __unknown2; 
		float __unknown3; 
		DataReference nicename("Function") function_data_reference; 
		Undefined32 __unknown4; 
		float nicename("Duration") duration; 
		DataReference nicename("Function") function2_data_reference; 
		DataReference nicename("Function") function3_data_reference; 
		string_id nicename("Trigger") trigger; 
		string_id nicename("Trigger") trigger2; 
		DataReference nicename("Function") function4_data_reference; 
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
		float nicename("Tint r") tint_r; 
		float nicename("Tint g") tint_g; 
		float nicename("Tint b") tint_b; 
		float nicename("Tone r") tone_r; 
		float nicename("Tone g") tone_g; 
		float nicename("Tone b") tone_b; 
		float nicename("Holograph") holograph; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		float nicename("Horizontal Blur") horizontal_blur; 
		float nicename("Vertical Blur") vertical_blur; 
		Undefined32 __unknown9; 
		float nicename("HUD Transparency") hud_transparency; 
		float nicename("Zoom In") zoom_in; 
		float nicename("Zoom Out") zoom_out; 
		float nicename("Turbulence") turbulence; 
		TagReference nicename("Screen Shader") screen_shader_reference; 
	};
};
