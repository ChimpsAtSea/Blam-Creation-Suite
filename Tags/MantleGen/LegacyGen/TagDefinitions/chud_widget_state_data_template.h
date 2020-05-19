#pragma once

struct nicename("chud_widget_state_data_template") tag_group('wsdt') s_chud_widget_state_data_template_definition_legacy
{
	struct nicename("State Data") s_state_data_definition_legacy
	{
		struct nicename("States 1") s_states_1_definition_legacy
		{
			struct nicename("Triggers") s_triggers_definition_legacy
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Trigger Index") trigger_index;
			};

			s_tag_block_legacy<s_triggers_definition_legacy> nicename("Triggers") triggers_block;
		};

		struct nicename("States 2") s_states_2_definition_legacy
		{
			struct nicename("Triggers") s_triggers1_definition_legacy
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Trigger Index") trigger_index;
			};

			s_tag_block_legacy<s_triggers1_definition_legacy> nicename("Triggers") triggers_block;
		};

		struct nicename("States 3") s_states_3_definition_legacy
		{
			struct nicename("Triggers") s_triggers2_definition_legacy
			{
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int32_t nicename("Trigger Index") trigger_index;
			};

			s_tag_block_legacy<s_triggers2_definition_legacy> nicename("Triggers") triggers_block;
		};

		s_tag_block_legacy<s_states_1_definition_legacy> nicename("States 1") states_1_block;
		s_tag_block_legacy<s_states_2_definition_legacy> nicename("States 2") states_2_block;
		s_tag_block_legacy<s_states_3_definition_legacy> nicename("States 3") states_3_block;
		int16_t __unknown0;
		int16_t __unknown1;
		int16_t __unknown2;
		int16_t __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	s_tag_block_legacy<s_state_data_definition_legacy> nicename("State Data") state_data_block;
};

