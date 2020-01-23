#pragma once

struct nicename("Sound") group('snd!') s_sound_definition
{
	struct nicename("Extra Info") s_extra_info_block_definition;

	uint16_t nicename("Flags") flags; 
	int8_t nicename("Sound Class") sound_class; 
	int8_t __unknown; 
	int16_t nicename("[ugh!] Platform Codec Index") ugh_platform_codec_index; 
	int16_t nicename("[ugh!] Pitch Range Index") ugh_pitch_range_index; 
	int16_t nicename("[ugh!] Language B Index") ugh_language_b_index; 
	int16_t __unknown_ugh_value; 
	int16_t __unknown2; 
	int16_t nicename("[ugh!] Playback Parameter Index") ugh_playback_parameter_index; 
	int16_t nicename("[ugh!] Scale Index") ugh_scale_index; 
	int8_t nicename("[ugh!] Promotion Index") ugh_promotion_index; 
	int8_t nicename("[ugh!] Custom Playback Index") ugh_custom_playback_index; 
	int16_t __unknown3; 
	int16_t __unknown4; 
	int32_t __unknown5; 
	int32_t nicename("[zone] Asset Datum") zone_asset_datum; 
	uint16_t nicename("[easy read] Index") easy_read_index; 
	uint16_t nicename("[easy read] Salt") easy_read_salt; 
	int32_t nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_extra_info_block_definition> nicename("Extra Info") extra_info_block; 

	struct nicename("extra_info") s_extra_info_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
		DataReference __unknown2_data_reference; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		int32_t __unknown5; 

		struct s_unknown_block_definition
		{
			struct s_unknown2_block_definition;

			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown5_block; 

			struct s_unknown2_block_definition
			{
				int32_t __unknown; 
				int32_t __unknown2; 
				int32_t __unknown3; 
			};
		};
	};
};
