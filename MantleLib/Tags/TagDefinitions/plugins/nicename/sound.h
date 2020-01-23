#pragma once

nicename("sound") struct s_sound_definition
{
	nicename("Extra Info") struct s_extra_info_block_definition;

	nicename("Flags") unsigned short flags;
	nicename("Sound Class") signed char sound_class;
	nicename("Unknown") signed char unknown;
	nicename("[ugh!] Platform Codec Index") signed short ugh!_platform_codec_index;
	nicename("[ugh!] Pitch Range Index") signed short ugh!_pitch_range_index;
	nicename("[ugh!] Language B Index") signed short ugh!_language_b_index;
	nicename("Unknown ugh! Value") signed short unknown_ugh!_value;
	nicename("Unknown") signed short unknown2;
	nicename("[ugh!] Playback Parameter Index") signed short ugh!_playback_parameter_index;
	nicename("[ugh!] Scale Index") signed short ugh!_scale_index;
	nicename("[ugh!] Promotion Index") signed char ugh!_promotion_index;
	nicename("[ugh!] Custom Playback Index") signed char ugh!_custom_playback_index;
	nicename("Unknown") signed short unknown3;
	nicename("Unknown") signed short unknown4;
	nicename("Unknown") signed int unknown5;
	nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
	nicename("[easy read] Index") unsigned short easy_read_index;
	nicename("[easy read] Salt") unsigned short easy_read_salt;
	nicename("Useless Padding") signed int useless_padding;
	nicename("Extra Info") s_tag_block_definition<s_extra_info_block_definition> extra_info2;

	nicename("Extra Info") struct s_extra_info_definition
	{
		nicename("Unknown") struct s_unknown_block_definition;

		nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
		nicename("Unknown") DataReference unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") signed int unknown6;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") struct s_unknown6_block_definition;

			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
			nicename("Unknown") s_tag_block_definition<s_unknown6_block_definition> unknown7;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed int unknown2;
				nicename("Unknown") signed int unknown3;
				nicename("Unknown") signed int unknown4;
			};
		};
	};
};
