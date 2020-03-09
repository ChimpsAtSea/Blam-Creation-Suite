#pragma once

struct nicename("chud_widget_animation_data_template") group('wadt') s_chud_widget_animation_data_template_definition
{
	struct nicename("Animation Data") s_animation_data_definition
	{
		enum nicename("Animation 1 Function") e_animation_1_function : uint8_t
		{
			/*nicename("Default")*/ _animation_1_function_default = 1ui8,
			/*nicename("Use Input")*/ _animation_1_function_use_input = 2ui8,
			/*nicename("Use Range Input")*/ _animation_1_function_use_range_input = 3ui8,
			/*nicename("Zero")*/ _animation_1_function_zero = 4ui8,
		};

		enum nicename("Animation 2 Function") e_animation_2_function : uint8_t
		{
			/*nicename("Default")*/ _animation_2_function_default = 1ui8,
			/*nicename("Use Input")*/ _animation_2_function_use_input = 2ui8,
			/*nicename("Use Range Input")*/ _animation_2_function_use_range_input = 3ui8,
			/*nicename("Zero")*/ _animation_2_function_zero = 4ui8,
		};

		enum nicename("Animation 3 Function") e_animation_3_function : uint8_t
		{
			/*nicename("Default")*/ _animation_3_function_default = 1ui8,
			/*nicename("Use Input")*/ _animation_3_function_use_input = 2ui8,
			/*nicename("Use Range Input")*/ _animation_3_function_use_range_input = 3ui8,
			/*nicename("Zero")*/ _animation_3_function_zero = 4ui8,
		};

		enum nicename("Animation 4 Function") e_animation_4_function : uint8_t
		{
			/*nicename("Default")*/ _animation_4_function_default = 1ui8,
			/*nicename("Use Input")*/ _animation_4_function_use_input = 2ui8,
			/*nicename("Use Range Input")*/ _animation_4_function_use_range_input = 3ui8,
			/*nicename("Zero")*/ _animation_4_function_zero = 4ui8,
		};

		enum nicename("Animation 5 Function") e_animation_5_function : uint8_t
		{
			/*nicename("Default")*/ _animation_5_function_default = 1ui8,
			/*nicename("Use Input")*/ _animation_5_function_use_input = 2ui8,
			/*nicename("Use Range Input")*/ _animation_5_function_use_range_input = 3ui8,
			/*nicename("Zero")*/ _animation_5_function_zero = 4ui8,
		};

		enum nicename("Animation 1 Flags") b_animation_1_flags : uint8_t /* bitfield */
		{
			/*nicename("Reverse Frames")*/ _animation_1_flags_reverse_frames = 1ui8 << 0ui8,
		};

		enum nicename("Animation 2 Flags") b_animation_2_flags : uint8_t /* bitfield */
		{
			/*nicename("Reverse Frames")*/ _animation_2_flags_reverse_frames = 1ui8 << 0ui8,
		};

		enum nicename("Animation 3 Flags") b_animation_3_flags : uint8_t /* bitfield */
		{
			/*nicename("Reverse Frames")*/ _animation_3_flags_reverse_frames = 1ui8 << 0ui8,
		};

		enum nicename("Animation 4 Flags") b_animation_4_flags : uint8_t /* bitfield */
		{
			/*nicename("Reverse Frames")*/ _animation_4_flags_reverse_frames = 1ui8 << 0ui8,
		};

		enum nicename("Animation 5 Flags") b_animation_5_flags : uint8_t /* bitfield */
		{
			/*nicename("Reverse Frames")*/ _animation_5_flags_reverse_frames = 1ui8 << 0ui8,
		};

		b_animation_1_flags nicename("Animation 1 Flags") animation_1_flags;
		e_animation_1_function nicename("Animation 1 Function") animation_1_function;
		int16_t __unknown0;
		TagReference nicename("Animation 1") animation_1_reference;
		b_animation_2_flags nicename("Animation 2 Flags") animation_2_flags;
		e_animation_2_function nicename("Animation 2 Function") animation_2_function;
		int16_t __unknown1;
		TagReference nicename("Animation 2") animation_2_reference;
		b_animation_3_flags nicename("Animation 3 Flags") animation_3_flags;
		e_animation_3_function nicename("Animation 3 Function") animation_3_function;
		int16_t __unknown2;
		TagReference nicename("Animation 3") animation_3_reference;
		b_animation_4_flags nicename("Animation 4 Flags") animation_4_flags;
		e_animation_4_function nicename("Animation 4 Function") animation_4_function;
		int16_t __unknown3;
		TagReference nicename("Animation 4") animation_4_reference;
		b_animation_5_flags nicename("Animation 5 Flags") animation_5_flags;
		e_animation_5_function nicename("Animation 5 Function") animation_5_function;
		int16_t __unknown4;
		TagReference nicename("Animation 5") animation_5_reference;
	};

	s_tag_block_definition<s_animation_data_definition> nicename("Animation Data") animation_data_block;
};

