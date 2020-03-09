#pragma once

struct nicename("damage_response_definition") group('drdf') s_damage_response_definition_definition
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
			string_id nicename("Name") name;
			DataReference nicename("Lowpass Function") lowpass_function_data_reference;
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
		Undefined32 __unknown9;
		float __unknown10;
		float __unknown11;
		float __unknown12;
		float __unknown13;
		float __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		Undefined32 __unknown18;
		TagReference nicename("Rumble") rumble_reference;
		TagReference nicename("Camera Shake") camera_shake_reference;
		TagReference nicename("Simulated Input") simulated_input_reference;
		s_tag_block_definition<s_lowpass_definition> nicename("Lowpass") lowpass_block;
	};

	struct nicename("Unknown") s_unknown_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
		Undefined32 __unknown2;
		DataReference __unknown3;
		DataReference __unknown4;
		string_id __unknown5;
		Undefined32 __unknown6;
		DataReference __unknown7;
	};

	s_tag_block_definition<s_responses_definition> nicename("Responses") responses_block;
	s_tag_block_definition<s_unknown_definition> __unknown0;
};

