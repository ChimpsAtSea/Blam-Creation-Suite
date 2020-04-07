#pragma once

struct nicename("sound_cache_file_gestalt") tag_group('ugh!') s_sound_cache_file_gestalt_definition
{
	struct nicename("Platform Codec") s_platform_codec_definition
	{
		enum nicename("Sample Rate") e_sample_rate : uint8_t
		{
			/*nicename("22kHz")*/ _sample_rate__22khz = 0ui8,
			/*nicename("44kHz")*/ _sample_rate__44khz = 1ui8,
			/*nicename("32kHz")*/ _sample_rate__32khz = 2ui8,
		};

		enum nicename("Encoding") e_encoding : uint8_t
		{
			/*nicename("Mono")*/ _encoding_mono = 0ui8,
			/*nicename("Stereo")*/ _encoding_stereo = 1ui8,
			/*nicename("Surround")*/ _encoding_surround = 2ui8,
			/*nicename("5.1 Surround")*/ _encoding__51_surround = 3ui8,
		};

		e_sample_rate nicename("Sample Rate") sample_rate;
		e_encoding nicename("Encoding") encoding;
		int8_t __unknown0;
	};

	struct nicename("Playback Parameters") s_playback_parameters_definition
	{
		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Override Azimuth")*/ _flags_override_azimuth = 1ui32 << 0ui32,
			/*nicename("Override 3D Gain")*/ _flags_override_3d_gain = 1ui32 << 1ui32,
			/*nicename("Override Speaker Gain")*/ _flags_override_speaker_gain = 1ui32 << 2ui32,
		};

		int32_t __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		float nicename("Distance A") distance_a;
		float nicename("Distance B") distance_b;
		float nicename("Distance C") distance_c;
		float nicename("Distance D") distance_d;
		float __unknown6;
		// Randomization : 
		float nicename("Gain Base") gain_base;
		float nicename("Gain Variance") gain_variance;
		int16_t nicename("Random Pitch Bounds min") random_pitch_bounds_min;
		int16_t nicename("Random Pitch Bounds max") random_pitch_bounds_max;
		// Directional Sounds : 
		float nicename("Inner Cone Angle") inner_cone_angle;
		float nicename("Outer Cone Angle") outer_cone_angle;
		float nicename("Outer Cone Gain") outer_cone_gain;
		// Scripted Location Override : 
		b_flags nicename("Flags") flags;
		float nicename("Azimuth") azimuth;
		float nicename("Positional Gain") positional_gain;
		float nicename("First Person Gain") first_person_gain;
	};

	struct nicename("Scales") s_scales_definition
	{
		float nicename("Gain Modifier min") gain_modifier_min;
		float nicename("Gain Modifier max") gain_modifier_max;
		int16_t nicename("Pitch Modifier min") pitch_modifier_min;
		int16_t nicename("Pitch Modifier max") pitch_modifier_max;
		float nicename("Skip Fraction Modifier min") skip_fraction_modifier_min;
		float nicename("Skip Fraction Modifier max") skip_fraction_modifier_max;
	};

	struct nicename("Import Names") s_import_names_definition
	{
		string_id nicename("Name") name;
	};

	struct nicename("Unknown 4") s_unknown_4_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
	};

	struct nicename("Pitch Range Parameters") s_pitch_range_parameters_definition
	{
		int16_t nicename("Natural Pitch") natural_pitch;
		int16_t __unknown0;
		int16_t nicename("Bend Bounds min") bend_bounds_min;
		int16_t nicename("Bend Bounds max") bend_bounds_max;
		int16_t nicename("Max Gain Pitch Bounds min") max_gain_pitch_bounds_min;
		int16_t nicename("Max Gain Pitch Bounds max") max_gain_pitch_bounds_max;
		int16_t nicename("Unknown Bounds min") unknown_bounds_min;
		int16_t nicename("Unknown Bounds max") unknown_bounds_max;
	};

	struct nicename("Pitch Ranges") s_pitch_ranges_definition
	{
		int16_t nicename("Import Name Index") import_name_index;
		int16_t nicename("Pitch Range Parameter Index") pitch_range_parameter_index;
		int16_t nicename("Encoded Permutation Data Index") encoded_permutation_data_index;
		int16_t nicename("Encoded Runtime Permutation Flag Index") encoded_runtime_permutation_flag_index;
		int16_t nicename("Encoded Permutation Count") encoded_permutation_count;
		uint16_t nicename("First Permuation Index") first_permuation_index;
	};

	struct nicename("Permutations") s_permutations_definition
	{
		int16_t nicename("Import Name Index") import_name_index;
		int16_t nicename("Encoded Skip Fraction") encoded_skip_fraction;
		uint32_t nicename("Sample Size") sample_size;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk;
		int16_t nicename("Permutation Chunk Count") permutation_chunk_count;
		int8_t nicename("Encoded Gain") encoded_gain;
		int8_t nicename("Encoded Permutation Index") encoded_permutation_index;
		int32_t __unknown0;
		uint32_t nicename("FSB Info Value") fsb_info_value;
	};

	struct nicename("Language Permutations") s_language_permutations_definition
	{
		int32_t nicename("Parent Permutation Index") parent_permutation_index;
		// English : 
		uint32_t nicename("Sample Size") sample_size;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count;
		// Japanese : 
		uint32_t nicename("Sample Size") sample_size1;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk1;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count1;
		// German : 
		uint32_t nicename("Sample Size") sample_size2;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk2;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count2;
		// French : 
		uint32_t nicename("Sample Size") sample_size3;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk3;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count3;
		// Spanish : 
		uint32_t nicename("Sample Size") sample_size4;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk4;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count4;
		// Latin American Spanish : 
		uint32_t nicename("Sample Size") sample_size5;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk5;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count5;
		// Italian : 
		uint32_t nicename("Sample Size") sample_size6;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk6;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count6;
		// Korean : 
		uint32_t nicename("Sample Size") sample_size7;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk7;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count7;
		// Chinese Traditional : 
		uint32_t nicename("Sample Size") sample_size8;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk8;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count8;
		// Chinese Simplified : 
		uint32_t nicename("Sample Size") sample_size9;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk9;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count9;
		// Portuguese : 
		uint32_t nicename("Sample Size") sample_size10;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk10;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count10;
		// Polish : 
		uint32_t nicename("Sample Size") sample_size11;
		int32_t nicename("First Permutation Chunk") first_permutation_chunk11;
		int32_t nicename("Permutation Chunk Count") permutation_chunk_count11;
	};

	struct nicename("Unknown 9") s_unknown_9_definition
	{
		Undefined32 __unknown0;
		TagReference __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
	};

	struct nicename("Languages") s_languages_definition
	{
		enum nicename("Language") e_language : uint32_t
		{
			/*nicename("English")*/ _language_english = 0ui32,
			/*nicename("Japanese")*/ _language_japanese = 1ui32,
			/*nicename("German")*/ _language_german = 2ui32,
			/*nicename("French")*/ _language_french = 3ui32,
			/*nicename("Spanish")*/ _language_spanish = 4ui32,
			/*nicename("Latin American Spanish")*/ _language_latin_american_spanish = 5ui32,
			/*nicename("Italian")*/ _language_italian = 6ui32,
			/*nicename("Korean")*/ _language_korean = 7ui32,
			/*nicename("Chinese Traditional")*/ _language_chinese_traditional = 8ui32,
			/*nicename("Chinese Simplified")*/ _language_chinese_simplified = 9ui32,
			/*nicename("Portuguese")*/ _language_portuguese = 10ui32,
			/*nicename("Polish")*/ _language_polish = 11ui32,
		};

		struct nicename("Unknown A") s_unknown_a_definition
		{
			int16_t __unknown0;
		};

		struct nicename("Unknown B") s_unknown_b_definition
		{
			int16_t nicename("Unknown A Start Index") unknown_a_start_index;
			int16_t nicename("Unknown A Count") unknown_a_count;
		};

		e_language nicename("Language") language;
		s_tag_block_definition<s_unknown_a_definition> nicename("Unknown A") unknown_a_block;
		s_tag_block_definition<s_unknown_b_definition> nicename("Unknown B") unknown_b_block;
	};

	struct nicename("Runtime Permutation Flags") s_runtime_permutation_flags_definition
	{
		int8_t __unknown0;
	};

	struct nicename("Permutation Chunks") s_permutation_chunks_definition
	{
		enum nicename("Flags") b_flags : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Has 'Unknown A' Value")*/ _flags_has_unknown_a_value = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui8 << 7ui8,
		};

		uint32_t nicename("File Offset") file_offset;
		b_flags nicename("Flags") flags;
		// Chunk Size : Chunk size is actually int24 but since that isn't supported the "Leftmost Byte" value will take care of it. It is for bits 16-24 as seen in windows calculator.
		uint8_t nicename("Chunk Size Leftmost Byte") chunk_size_leftmost_byte;
		uint16_t nicename("Chunk Size") chunk_size1;
		int32_t nicename("Runtime Index") runtime_index;
		int32_t nicename("Unknown A") unknown_a;
		int32_t nicename("Unknown Size") unknown_size;
		Undefined32 __unknown0;
		Undefined32 __unknown1;
	};

	struct nicename("Promotions") s_promotions_definition
	{
		struct nicename("Rules") s_rules_definition
		{
			int16_t nicename("Pitch Range Index") pitch_range_index;
			int16_t nicename("Maximum Playing Count") maximum_playing_count;
			float nicename("Suppression Time") suppression_time;
			int32_t __unknown0;
			int32_t __unknown1;
		};

		struct nicename("Runtime Timers") s_runtime_timers_definition
		{
			int32_t __unknown0;
		};

		s_tag_block_definition<s_rules_definition> nicename("Rules") rules_block;
		s_tag_block_definition<s_runtime_timers_definition> nicename("Runtime Timers") runtime_timers_block;
		int32_t __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
	};

	struct nicename("Extra Info") s_extra_info_definition
	{
		int32_t nicename("[zone] Asset Datum") zone_asset_datum;
		uint16_t nicename("[easy read] Index") easy_read_index;
		uint16_t nicename("[easy read] Salt") easy_read_salt;
		int32_t nicename("Useless Padding") useless_padding;
	};

	struct nicename("Unknown 15") s_unknown_15_definition
	{
		int32_t __unknown0;
	};

	int32_t __unknown0;
	s_tag_block_definition<s_platform_codec_definition> nicename("Platform Codec") platform_codec_block;
	s_tag_block_definition<s_playback_parameters_definition> nicename("Playback Parameters") playback_parameters_block;
	s_tag_block_definition<s_scales_definition> nicename("Scales") scales_block;
	s_tag_block_definition<s_import_names_definition> nicename("Import Names") import_names_block;
	s_tag_block_definition<s_unknown_4_definition> nicename("Unknown 4") unknown_4_block;
	s_tag_block_definition<s_pitch_range_parameters_definition> nicename("Pitch Range Parameters") pitch_range_parameters_block;
	s_tag_block_definition<s_pitch_ranges_definition> nicename("Pitch Ranges") pitch_ranges_block;
	s_tag_block_definition<s_permutations_definition> nicename("Permutations") permutations_block;
	s_tag_block_definition<s_language_permutations_definition> nicename("Language Permutations") language_permutations_block;
	s_tag_block_definition<s_unknown_9_definition> nicename("Unknown 9") unknown_9_block;
	s_tag_block_definition<s_languages_definition> nicename("Languages") languages_block;
	s_tag_block_definition<s_runtime_permutation_flags_definition> nicename("Runtime Permutation Flags") runtime_permutation_flags_block;
	DataReference __unknown1;
	Undefined32 __unknown2;
	Undefined32 __unknown3;
	s_tag_block_definition<s_permutation_chunks_definition> nicename("Permutation Chunks") permutation_chunks_block;
	s_tag_block_definition<s_promotions_definition> nicename("Promotions") promotions_block;
	s_tag_block_definition<s_extra_info_definition> nicename("Extra Info") extra_info_block;
	s_tag_block_definition<s_unknown_15_definition> nicename("Unknown 15") unknown_15_block;
};

