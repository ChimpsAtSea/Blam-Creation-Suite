#pragma once

struct nicename("Damage Response Definition") group('drdf') s_damage_response_definition_definition
{
	struct nicename("Responses") s_respons_block_definition;
	struct s_unknown_block_definition;

	s_tag_block_definition<s_respons_block_definition> nicename("Responses") responses_block; 
	s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

	struct nicename("respons") s_respons_block_definition
	{
		struct nicename("Lowpass") s_lowpass_block_definition;

		int16_t nicename("Response Type") response_type; 
		int16_t __unknown; 
		float __unknown2; 
		int16_t __unknown3; 
		int16_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		Undefined32 __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		Undefined32 __unknown19; 
		TagReference nicename("Rumble") rumble_reference; 
		TagReference nicename("Camera Shake") camera_shake_reference; 
		TagReference nicename("Simulated Input") simulated_input_reference; 
		s_tag_block_definition<s_lowpass_block_definition> nicename("Lowpass") lowpass_block; 

		struct nicename("lowpass") s_lowpass_block_definition
		{
			string_id nicename("Name") name; 
			DataReference nicename("Lowpass Function") lowpass_function_data_reference; 
		};
	};

	struct s_unknown_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
		Undefined32 __unknown3; 
		DataReference __unknown4_data_reference; 
		DataReference __unknown5_data_reference; 
		string_id __unknown6; 
		Undefined32 __unknown7; 
		DataReference __unknown8_data_reference; 
	};
};
