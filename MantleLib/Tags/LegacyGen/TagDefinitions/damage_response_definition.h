#pragma once

struct nicename("damage_response_definition") tag_group('drdf') s_damage_response_definition_definition
{
	struct nicename("Responses") s_responses_definition
	{
		enum nicename("Response Type") e_response_type : uint16_t
		{
			/*nicename("Shielded")*/ _response_type_shielded = 1ui16,
			/*nicename("Unshielded")*/ _response_type_unshielded = 2ui16,
			/*nicename("All")*/ _response_type_all = 3ui16,
		};

		struct nicename("Lowpass") s_lowpass_definition
		{
			string_id_legacy nicename("Name") name;
			s_data_reference_legacy nicename("Lowpass Function") lowpass_function_data_reference;
		};

		e_response_type nicename("Response Type") response_type;
		int16_t __unknown0;
		float __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		float __unknown4;
		float __unknown5;
		float __unknown6;
		float __unknown7;
		float __unknown8;
		s_undefined32_legacy __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		s_undefined32_legacy __unknown18;
		s_tag_reference_legacy nicename("Rumble") rumble_reference;
		s_tag_reference_legacy nicename("Camera Shake") camera_shake_reference;
		s_tag_reference_legacy nicename("Simulated Input") simulated_input_reference;
		s_tag_block_legacy<s_lowpass_definition> nicename("Lowpass") lowpass_block;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
		s_undefined32_legacy __unknown2;
		s_data_reference_legacy __unknown3;
		s_data_reference_legacy __unknown4;
		string_id_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_data_reference_legacy __unknown7;
	};

	s_tag_block_legacy<s_responses_definition> nicename("Responses") responses_block;
	s_tag_block_legacy<s_unknown_definition> __unknown0;
};

