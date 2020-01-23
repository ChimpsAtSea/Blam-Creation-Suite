#pragma once

struct s_sound_definition
{
	struct s_extra_info_block_definition;

	unsigned short flags;
	signed char sound_class;
	signed char unknown;
	signed short ugh!_platform_codec_index;
	signed short ugh!_pitch_range_index;
	signed short ugh!_language_b_index;
	signed short unknown_ugh!_value;
	signed short unknown2;
	signed short ugh!_playback_parameter_index;
	signed short ugh!_scale_index;
	signed char ugh!_promotion_index;
	signed char ugh!_custom_playback_index;
	signed short unknown3;
	signed short unknown4;
	signed int unknown5;
	unsigned int zone_asset_datum;
	unsigned short easy_read_index;
	unsigned short easy_read_salt;
	signed int useless_padding;
	s_tag_block_definition<s_extra_info_block_definition> extra_info2;

	struct s_extra_info_definition
	{
		struct s_unknown_block_definition;

		s_tag_block_definition<s_unknown_block_definition> unknown2;
		DataReference unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		signed int unknown6;

		struct s_unknown_definition
		{
			struct s_unknown6_block_definition;

			unsigned int unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
			s_tag_block_definition<s_unknown6_block_definition> unknown7;

			struct s_unknown_definition
			{
				signed int unknown2;
				signed int unknown3;
				signed int unknown4;
			};
		};
	};
};
