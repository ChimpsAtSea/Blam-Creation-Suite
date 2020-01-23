#pragma once

struct nicename("Sound") group('snd!') s_sound_definition
{
	struct nicename("Extra Info") s_extra_info_block_definition;

	unsigned short nicename("Flags") flags; 
	signed char nicename("Sound Class") sound_class; 
	signed char __unknown; 
	signed short nicename("[ugh!] Platform Codec Index") ugh_platform_codec_index; 
	signed short nicename("[ugh!] Pitch Range Index") ugh_pitch_range_index; 
	signed short nicename("[ugh!] Language B Index") ugh_language_b_index; 
	signed short __unknown_ugh_value; 
	signed short __unknown2; 
	signed short nicename("[ugh!] Playback Parameter Index") ugh_playback_parameter_index; 
	signed short nicename("[ugh!] Scale Index") ugh_scale_index; 
	signed char nicename("[ugh!] Promotion Index") ugh_promotion_index; 
	signed char nicename("[ugh!] Custom Playback Index") ugh_custom_playback_index; 
	signed short __unknown3; 
	signed short __unknown4; 
	signed int __unknown5; 
	signed int nicename("[zone] Asset Datum") zone_asset_datum; 
	unsigned short nicename("[easy read] Index") easy_read_index; 
	unsigned short nicename("[easy read] Salt") easy_read_salt; 
	signed int nicename("Useless Padding") useless_padding; 
	s_tag_block_definition<s_extra_info_block_definition> nicename("Extra Info") extra_info_block; 

	struct nicename("extra_info") s_extra_info_block_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
		DataReference __unknown2_data_reference; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		signed int __unknown5; 

		struct s_unknown_block_definition
		{
			struct s_unknown2_block_definition;

			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 
			Unknown32 __unknown4; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown5_block; 

			struct s_unknown2_block_definition
			{
				signed int __unknown; 
				signed int __unknown2; 
				signed int __unknown3; 
			};
		};
	};
};
