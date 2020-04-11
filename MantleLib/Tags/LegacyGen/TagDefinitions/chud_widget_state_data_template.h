#pragma once

struct nicename("chud_widget_state_data_template") tag_group('wsdt') s_chud_widget_state_data_template_definition
{
	struct nicename("State Data") s_state_data_definition
	{
		struct nicename("States 1") s_states_1_definition
		{
			struct nicename("Triggers") s_triggers_definition
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Trigger Index") trigger_index;
			};

			s_tag_block_legacy<s_triggers_definition> nicename("Triggers") triggers_block;
		};

		struct nicename("States 2") s_states_2_definition
		{
			struct nicename("Triggers") s_triggers1_definition
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Trigger Index") trigger_index;
			};

			s_tag_block_legacy<s_triggers1_definition> nicename("Triggers") triggers_block;
		};

		struct nicename("States 3") s_states_3_definition
		{
			struct nicename("Triggers") s_triggers2_definition
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Trigger Index") trigger_index;
			};

			s_tag_block_legacy<s_triggers2_definition> nicename("Triggers") triggers_block;
		};

		s_tag_block_legacy<s_states_1_definition> nicename("States 1") states_1_block;
		s_tag_block_legacy<s_states_2_definition> nicename("States 2") states_2_block;
		s_tag_block_legacy<s_states_3_definition> nicename("States 3") states_3_block;
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	s_tag_block_legacy<s_state_data_definition> nicename("State Data") state_data_block;
};

