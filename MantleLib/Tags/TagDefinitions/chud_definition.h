#pragma once

struct nicename("Chud Definition") group('chdt') s_chud_definition_definition
{
	struct nicename("HUD Widgets") s_hud_widget_block_definition;
	struct nicename("Compiled Widget Data") s_compiled_widget_datum_block_definition;

	// comment
	// comment
	s_tag_block_definition<s_hud_widget_block_definition> nicename("HUD Widgets") hud_widgets_block; 
	int32_t nicename("Low Clip Cutoff") low_clip_cutoff; 
	int32_t nicename("Low Ammo Cutoff") low_ammo_cutoff; 
	int32_t nicename("Age Cutoff") age_cutoff; 
	int32_t nicename("Sword Age Cutoff") sword_age_cutoff; 
	s_tag_block_definition<s_compiled_widget_datum_block_definition> nicename("Compiled Widget Data") compiled_widget_data_block; 

	struct nicename("hud_widget") s_hud_widget_block_definition
	{
		struct nicename("State Data") s_state_datum_block_definition;
		struct nicename("Placement Data") s_placement_datum_block_definition;
		struct nicename("Animation Data") s_animation_datum_block_definition;
		struct nicename("Render Data") s_render_datum_block_definition;
		struct nicename("Datasource") s_datasource_block_definition;
		struct nicename("Bitmap Widgets") s_bitmap_widget_block_definition;
		struct nicename("Text Widgets") s_text_widget_block_definition;

		string_id nicename("Name") name; 
		int8_t nicename("Special HUD Type") special_hud_type; 
		uint8_t __unknown; 
		uint8_t __unknown2; 
		uint8_t __unknown3; 
		int16_t nicename("Import Input") import_input; 
		int16_t nicename("Import Range Input") import_range_input; 
		TagReference nicename("State Data Template") state_data_template_reference; 
		s_tag_block_definition<s_state_datum_block_definition> nicename("State Data") state_data_block; 
		TagReference nicename("Placement Data Template") placement_data_template_reference; 
		s_tag_block_definition<s_placement_datum_block_definition> nicename("Placement Data") placement_data_block; 
		TagReference nicename("Animation Data Template") animation_data_template_reference; 
		s_tag_block_definition<s_animation_datum_block_definition> nicename("Animation Data") animation_data_block; 
		TagReference nicename("Render Data Template") render_data_template_reference; 
		s_tag_block_definition<s_render_datum_block_definition> nicename("Render Data") render_data_block; 
		TagReference nicename("Datasource Template") datasource_template_reference; 
		s_tag_block_definition<s_datasource_block_definition> nicename("Datasource") datasource_block; 
		s_tag_block_definition<s_bitmap_widget_block_definition> nicename("Bitmap Widgets") bitmap_widgets_block; 
		s_tag_block_definition<s_text_widget_block_definition> nicename("Text Widgets") text_widgets_block; 
		int32_t __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		// comment
		int8_t nicename("Second State-Block Starting Value") second_state_block_starting_value; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		// comment
		uint16_t nicename("Input Variable Triggers") input_variable_triggers; 
		// comment
		int16_t nicename("__0") __0; 
		int16_t nicename("__1") __1; 
		int16_t nicename("__2") __2; 
		int16_t nicename("__3") __3; 
		int16_t nicename("__4") __4; 
		int16_t nicename("__5") __5; 
		int16_t nicename("__6") __6; 
		int16_t nicename("__7") __7; 
		int16_t nicename("__8") __8; 
		int16_t nicename("__9") __9; 
		int16_t nicename("__10") __10; 
		int16_t nicename("__11") __11; 
		int16_t nicename("__12") __12; 

		struct nicename("state_datum") s_state_datum_block_definition
		{
			struct nicename("'Yes' States") s__yes__state_block_definition;
			struct s_unknown_state_block_definition;
			struct nicename("'No' States") s__no__state_block_definition;

			// comment
			s_tag_block_definition<s__yes__state_block_definition> nicename("'Yes' States") _yes__states_block; 
			s_tag_block_definition<s_unknown_state_block_definition> __unknown_states_block; 
			s_tag_block_definition<s__no__state_block_definition> nicename("'No' States") _no__states_block; 
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t __unknown3; 
			int16_t __unknown4; 
			Undefined32 __unknown5; 
			Undefined32 __unknown6; 
			Undefined32 __unknown7; 

			struct nicename("_yes__state") s__yes__state_block_definition
			{
				struct nicename("Triggers") s_trigger_block_definition;

				s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

				struct nicename("trigger") s_trigger_block_definition
				{
					uint8_t nicename("Flag") flag; 
					int8_t __unknown; 
					int8_t __unknown2; 
					int8_t __unknown3; 
					int32_t nicename("Trigger Index") trigger_index; 
				};
			};

			struct s_unknown_state_block_definition
			{
				struct nicename("Triggers") s_trigger_block_definition;

				s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

				struct nicename("trigger") s_trigger_block_definition
				{
					uint8_t nicename("Flag") flag; 
					int8_t __unknown; 
					int8_t __unknown2; 
					int8_t __unknown3; 
					int32_t nicename("Trigger Index") trigger_index; 
				};
			};

			struct nicename("_no__state") s__no__state_block_definition
			{
				struct nicename("Triggers") s_trigger_block_definition;

				s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

				struct nicename("trigger") s_trigger_block_definition
				{
					uint8_t nicename("Flag") flag; 
					int8_t __unknown; 
					int8_t __unknown2; 
					int8_t __unknown3; 
					int32_t nicename("Trigger Index") trigger_index; 
				};
			};
		};

		struct nicename("placement_datum") s_placement_datum_block_definition
		{
			uint8_t __unknown; 
			int8_t nicename("Anchor") anchor; 
			int16_t __unknown2; 
			float nicename("Mirror Offset X") mirror_offset_x; 
			float nicename("Mirror Offset Y") mirror_offset_y; 
			float nicename("Offset X") offset_x; 
			float nicename("Offset Y") offset_y; 
			float nicename("Scale X") scale_x; 
			float nicename("Scale Y") scale_y; 
		};

		struct nicename("animation_datum") s_animation_datum_block_definition
		{
			uint8_t nicename("Animation 1 Flags") animation_1_flags; 
			int8_t nicename("Animation 1 Function") animation_1_function; 
			int16_t __unknown; 
			TagReference nicename("Animation 1") animation_1_reference; 
			uint8_t nicename("Animation 2 Flags") animation_2_flags; 
			int8_t nicename("Animation 2 Function") animation_2_function; 
			int16_t __unknown2; 
			TagReference nicename("Animation 2") animation_2_reference; 
			uint8_t nicename("Animation 3 Flags") animation_3_flags; 
			int8_t nicename("Animation 3 Function") animation_3_function; 
			int16_t __unknown3; 
			TagReference nicename("Animation 3") animation_3_reference; 
			uint8_t nicename("Animation 4 Flags") animation_4_flags; 
			int8_t nicename("Animation 4 Function") animation_4_function; 
			int16_t __unknown4; 
			TagReference nicename("Animation 4") animation_4_reference; 
			uint8_t nicename("Animation 5 Flags") animation_5_flags; 
			int8_t nicename("Animation 5 Function") animation_5_function; 
			int16_t __unknown5; 
			TagReference nicename("Animation 5") animation_5_reference; 
		};

		struct nicename("render_datum") s_render_datum_block_definition
		{
			int8_t nicename("Shader Index") shader_index; 
			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			float nicename("Local Color Alpha a") local_color_alpha_a; 
			float nicename("Local Color a r") local_color_a_r; 
			float nicename("Local Color a g") local_color_a_g; 
			float nicename("Local Color a b") local_color_a_b; 
			float nicename("Local Color Alpha b") local_color_alpha_b; 
			float nicename("Local Color b r") local_color_b_r; 
			float nicename("Local Color b g") local_color_b_g; 
			float nicename("Local Color b b") local_color_b_b; 
			float nicename("Local Color Alpha c") local_color_alpha_c; 
			float nicename("Local Color c r") local_color_c_r; 
			float nicename("Local Color c g") local_color_c_g; 
			float nicename("Local Color c b") local_color_c_b; 
			float nicename("Local Color Alpha d") local_color_alpha_d; 
			float nicename("Local Color d r") local_color_d_r; 
			float nicename("Local Color d g") local_color_d_g; 
			float nicename("Local Color d b") local_color_d_b; 
			float nicename("Local Scalar a") local_scalar_a; 
			float nicename("Local Scalar b") local_scalar_b; 
			float nicename("Local Scalar c") local_scalar_c; 
			float nicename("Local Scalar d") local_scalar_d; 
			int16_t nicename("Output Color a") output_color_a; 
			int16_t nicename("Output Color b") output_color_b; 
			int16_t nicename("Output Color c") output_color_c; 
			int16_t nicename("Output Color d") output_color_d; 
			int16_t nicename("Output Color e") output_color_e; 
			int16_t nicename("Output Color f") output_color_f; 
			int16_t nicename("Output Scalar a") output_scalar_a; 
			int16_t nicename("Output Scalar b") output_scalar_b; 
			int16_t nicename("Output Scalar c") output_scalar_c; 
			int16_t nicename("Output Scalar d") output_scalar_d; 
			int16_t nicename("Output Scalar e") output_scalar_e; 
			int16_t nicename("Output Scalar f") output_scalar_f; 
			Undefined32 __unknown4; 
			Undefined32 __unknown5; 
			int16_t __unknown6; 
			int16_t __unknown7; 
		};

		struct nicename("datasource") s_datasource_block_definition
		{
			struct s_unknown_6_block_definition;

			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			int16_t __unknown5; 
			int16_t __unknown6; 
			Undefined32 __unknown7; 
			Undefined32 __unknown8; 
			Undefined32 __unknown9; 
			s_tag_block_definition<s_unknown_6_block_definition> __unknown_6_block; 

			struct s_unknown_6_block_definition
			{
				float __unknown; 
				float __unknown2; 
				float __unknown3; 
				float __unknown4; 
			};
		};

		struct nicename("bitmap_widget") s_bitmap_widget_block_definition
		{
			struct nicename("State Data") s_state_datum_block_definition;
			struct nicename("Placement Data") s_placement_datum_block_definition;
			struct nicename("Animation Data") s_animation_datum_block_definition;
			struct nicename("Render Data") s_render_datum_block_definition;

			string_id nicename("Name") name; 
			int8_t nicename("Special HUD Type") special_hud_type; 
			uint8_t __unknown; 
			uint8_t __unknown2; 
			uint8_t __unknown3; 
			int16_t nicename("Import Input") import_input; 
			int16_t nicename("Import Range Input") import_range_input; 
			TagReference nicename("State Data Template") state_data_template_reference; 
			s_tag_block_definition<s_state_datum_block_definition> nicename("State Data") state_data_block; 
			TagReference nicename("Placement Data Template") placement_data_template_reference; 
			s_tag_block_definition<s_placement_datum_block_definition> nicename("Placement Data") placement_data_block; 
			TagReference nicename("Animation Data Template") animation_data_template_reference; 
			s_tag_block_definition<s_animation_datum_block_definition> nicename("Animation Data") animation_data_block; 
			TagReference nicename("Render Data Template") render_data_template_reference; 
			s_tag_block_definition<s_render_datum_block_definition> nicename("Render Data") render_data_block; 
			int32_t nicename("Flags") flags; 
			TagReference nicename("Bitmap") bitmap_reference; 
			uint8_t nicename("Bitmap Sprite Index") bitmap_sprite_index; 
			uint8_t __unknown4; 
			uint8_t __unknown5; 
			uint8_t __unknown6; 
			Undefined32 __unknown7; 
			Undefined32 __unknown8; 

			struct nicename("state_datum") s_state_datum_block_definition
			{
				struct nicename("'Yes' States") s__yes__state_block_definition;
				struct s_unknown_state_block_definition;
				struct nicename("'No' States") s__no__state_block_definition;

				// comment
				s_tag_block_definition<s__yes__state_block_definition> nicename("'Yes' States") _yes__states_block; 
				s_tag_block_definition<s_unknown_state_block_definition> __unknown_states_block; 
				s_tag_block_definition<s__no__state_block_definition> nicename("'No' States") _no__states_block; 
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				Undefined32 __unknown5; 
				Undefined32 __unknown6; 
				Undefined32 __unknown7; 

				struct nicename("_yes__state") s__yes__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						uint8_t nicename("Flag") flag; 
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int32_t nicename("Trigger Index") trigger_index; 
					};
				};

				struct s_unknown_state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						uint8_t nicename("Flag") flag; 
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int32_t nicename("Trigger Index") trigger_index; 
					};
				};

				struct nicename("_no__state") s__no__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						uint8_t nicename("Flag") flag; 
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int32_t nicename("Trigger Index") trigger_index; 
					};
				};
			};

			struct nicename("placement_datum") s_placement_datum_block_definition
			{
				uint8_t __unknown; 
				int8_t nicename("Anchor") anchor; 
				int16_t __unknown2; 
				float nicename("Mirror Offset X") mirror_offset_x; 
				float nicename("Mirror Offset Y") mirror_offset_y; 
				float nicename("Offset X") offset_x; 
				float nicename("Offset Y") offset_y; 
				float nicename("Scale X") scale_x; 
				float nicename("Scale Y") scale_y; 
			};

			struct nicename("animation_datum") s_animation_datum_block_definition
			{
				uint8_t nicename("Animation 1 Flags") animation_1_flags; 
				int8_t nicename("Animation 1 Function") animation_1_function; 
				int16_t __unknown; 
				TagReference nicename("Animation 1") animation_1_reference; 
				uint8_t nicename("Animation 2 Flags") animation_2_flags; 
				int8_t nicename("Animation 2 Function") animation_2_function; 
				int16_t __unknown2; 
				TagReference nicename("Animation 2") animation_2_reference; 
				uint8_t nicename("Animation 3 Flags") animation_3_flags; 
				int8_t nicename("Animation 3 Function") animation_3_function; 
				int16_t __unknown3; 
				TagReference nicename("Animation 3") animation_3_reference; 
				uint8_t nicename("Animation 4 Flags") animation_4_flags; 
				int8_t nicename("Animation 4 Function") animation_4_function; 
				int16_t __unknown4; 
				TagReference nicename("Animation 4") animation_4_reference; 
				uint8_t nicename("Animation 5 Flags") animation_5_flags; 
				int8_t nicename("Animation 5 Function") animation_5_function; 
				int16_t __unknown5; 
				TagReference nicename("Animation 5") animation_5_reference; 
			};

			struct nicename("render_datum") s_render_datum_block_definition
			{
				int8_t nicename("Shader Index") shader_index; 
				int8_t __unknown; 
				int8_t __unknown2; 
				int8_t __unknown3; 
				float nicename("Local Color Alpha a") local_color_alpha_a; 
				float nicename("Local Color a r") local_color_a_r; 
				float nicename("Local Color a g") local_color_a_g; 
				float nicename("Local Color a b") local_color_a_b; 
				float nicename("Local Color Alpha b") local_color_alpha_b; 
				float nicename("Local Color b r") local_color_b_r; 
				float nicename("Local Color b g") local_color_b_g; 
				float nicename("Local Color b b") local_color_b_b; 
				float nicename("Local Color Alpha c") local_color_alpha_c; 
				float nicename("Local Color c r") local_color_c_r; 
				float nicename("Local Color c g") local_color_c_g; 
				float nicename("Local Color c b") local_color_c_b; 
				float nicename("Local Color Alpha d") local_color_alpha_d; 
				float nicename("Local Color d r") local_color_d_r; 
				float nicename("Local Color d g") local_color_d_g; 
				float nicename("Local Color d b") local_color_d_b; 
				float nicename("Local Scalar a") local_scalar_a; 
				float nicename("Local Scalar b") local_scalar_b; 
				float nicename("Local Scalar c") local_scalar_c; 
				float nicename("Local Scalar d") local_scalar_d; 
				int16_t nicename("Output Color a") output_color_a; 
				int16_t nicename("Output Color b") output_color_b; 
				int16_t nicename("Output Color c") output_color_c; 
				int16_t nicename("Output Color d") output_color_d; 
				int16_t nicename("Output Color e") output_color_e; 
				int16_t nicename("Output Color f") output_color_f; 
				int16_t nicename("Output Scalar a") output_scalar_a; 
				int16_t nicename("Output Scalar b") output_scalar_b; 
				int16_t nicename("Output Scalar c") output_scalar_c; 
				int16_t nicename("Output Scalar d") output_scalar_d; 
				int16_t nicename("Output Scalar e") output_scalar_e; 
				int16_t nicename("Output Scalar f") output_scalar_f; 
				Undefined32 __unknown4; 
				Undefined32 __unknown5; 
				int16_t __unknown6; 
				int16_t __unknown7; 
			};
		};

		struct nicename("text_widget") s_text_widget_block_definition
		{
			struct nicename("State Data") s_state_datum_block_definition;
			struct nicename("Placement Data") s_placement_datum_block_definition;
			struct nicename("Animation Data") s_animation_datum_block_definition;
			struct nicename("Render Data") s_render_datum_block_definition;

			string_id nicename("Name") name; 
			int8_t nicename("Special HUD Type") special_hud_type; 
			uint8_t __unknown; 
			uint8_t __unknown2; 
			uint8_t __unknown3; 
			int16_t nicename("Import Input") import_input; 
			int16_t nicename("Import Range Input") import_range_input; 
			TagReference nicename("State Data Template") state_data_template_reference; 
			s_tag_block_definition<s_state_datum_block_definition> nicename("State Data") state_data_block; 
			TagReference nicename("Placement Data Template") placement_data_template_reference; 
			s_tag_block_definition<s_placement_datum_block_definition> nicename("Placement Data") placement_data_block; 
			TagReference nicename("Animation Data Template") animation_data_template_reference; 
			s_tag_block_definition<s_animation_datum_block_definition> nicename("Animation Data") animation_data_block; 
			TagReference nicename("Render Data Template") render_data_template_reference; 
			s_tag_block_definition<s_render_datum_block_definition> nicename("Render Data") render_data_block; 
			uint16_t nicename("Flags") flags; 
			int16_t nicename("Font") font; 
			string_id nicename("String") string; 

			struct nicename("state_datum") s_state_datum_block_definition
			{
				struct nicename("'Yes' States") s__yes__state_block_definition;
				struct s_unknown_state_block_definition;
				struct nicename("'No' States") s__no__state_block_definition;

				// comment
				s_tag_block_definition<s__yes__state_block_definition> nicename("'Yes' States") _yes__states_block; 
				s_tag_block_definition<s_unknown_state_block_definition> __unknown_states_block; 
				s_tag_block_definition<s__no__state_block_definition> nicename("'No' States") _no__states_block; 
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				Undefined32 __unknown5; 
				Undefined32 __unknown6; 
				Undefined32 __unknown7; 

				struct nicename("_yes__state") s__yes__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						uint8_t nicename("Flag") flag; 
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int32_t nicename("Trigger Index") trigger_index; 
					};
				};

				struct s_unknown_state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						uint8_t nicename("Flag") flag; 
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int32_t nicename("Trigger Index") trigger_index; 
					};
				};

				struct nicename("_no__state") s__no__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						uint8_t nicename("Flag") flag; 
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int32_t nicename("Trigger Index") trigger_index; 
					};
				};
			};

			struct nicename("placement_datum") s_placement_datum_block_definition
			{
				uint8_t __unknown; 
				int8_t nicename("Anchor") anchor; 
				int16_t __unknown2; 
				float nicename("Mirror Offset X") mirror_offset_x; 
				float nicename("Mirror Offset Y") mirror_offset_y; 
				float nicename("Offset X") offset_x; 
				float nicename("Offset Y") offset_y; 
				float nicename("Scale X") scale_x; 
				float nicename("Scale Y") scale_y; 
			};

			struct nicename("animation_datum") s_animation_datum_block_definition
			{
				uint8_t nicename("Animation 1 Flags") animation_1_flags; 
				int8_t nicename("Animation 1 Function") animation_1_function; 
				int16_t __unknown; 
				TagReference nicename("Animation 1") animation_1_reference; 
				uint8_t nicename("Animation 2 Flags") animation_2_flags; 
				int8_t nicename("Animation 2 Function") animation_2_function; 
				int16_t __unknown2; 
				TagReference nicename("Animation 2") animation_2_reference; 
				uint8_t nicename("Animation 3 Flags") animation_3_flags; 
				int8_t nicename("Animation 3 Function") animation_3_function; 
				int16_t __unknown3; 
				TagReference nicename("Animation 3") animation_3_reference; 
				uint8_t nicename("Animation 4 Flags") animation_4_flags; 
				int8_t nicename("Animation 4 Function") animation_4_function; 
				int16_t __unknown4; 
				TagReference nicename("Animation 4") animation_4_reference; 
				uint8_t nicename("Animation 5 Flags") animation_5_flags; 
				int8_t nicename("Animation 5 Function") animation_5_function; 
				int16_t __unknown5; 
				TagReference nicename("Animation 5") animation_5_reference; 
			};

			struct nicename("render_datum") s_render_datum_block_definition
			{
				int8_t nicename("Shader Index") shader_index; 
				int8_t __unknown; 
				int8_t __unknown2; 
				int8_t __unknown3; 
				float nicename("Local Color Alpha a") local_color_alpha_a; 
				float nicename("Local Color a r") local_color_a_r; 
				float nicename("Local Color a g") local_color_a_g; 
				float nicename("Local Color a b") local_color_a_b; 
				float nicename("Local Color Alpha b") local_color_alpha_b; 
				float nicename("Local Color b r") local_color_b_r; 
				float nicename("Local Color b g") local_color_b_g; 
				float nicename("Local Color b b") local_color_b_b; 
				float nicename("Local Color Alpha c") local_color_alpha_c; 
				float nicename("Local Color c r") local_color_c_r; 
				float nicename("Local Color c g") local_color_c_g; 
				float nicename("Local Color c b") local_color_c_b; 
				float nicename("Local Color Alpha d") local_color_alpha_d; 
				float nicename("Local Color d r") local_color_d_r; 
				float nicename("Local Color d g") local_color_d_g; 
				float nicename("Local Color d b") local_color_d_b; 
				float nicename("Local Scalar a") local_scalar_a; 
				float nicename("Local Scalar b") local_scalar_b; 
				float nicename("Local Scalar c") local_scalar_c; 
				float nicename("Local Scalar d") local_scalar_d; 
				int16_t nicename("Output Color a") output_color_a; 
				int16_t nicename("Output Color b") output_color_b; 
				int16_t nicename("Output Color c") output_color_c; 
				int16_t nicename("Output Color d") output_color_d; 
				int16_t nicename("Output Color e") output_color_e; 
				int16_t nicename("Output Color f") output_color_f; 
				int16_t nicename("Output Scalar a") output_scalar_a; 
				int16_t nicename("Output Scalar b") output_scalar_b; 
				int16_t nicename("Output Scalar c") output_scalar_c; 
				int16_t nicename("Output Scalar d") output_scalar_d; 
				int16_t nicename("Output Scalar e") output_scalar_e; 
				int16_t nicename("Output Scalar f") output_scalar_f; 
				Undefined32 __unknown4; 
				Undefined32 __unknown5; 
				int16_t __unknown6; 
				int16_t __unknown7; 
			};
		};
	};

	struct nicename("compiled_widget_datum") s_compiled_widget_datum_block_definition
	{
		int8_t nicename("Special HUD Type") special_hud_type; 
		uint8_t __unknown; 
		uint8_t __unknown2; 
		uint8_t __unknown3; 
		float nicename("Animation 1 Frame Count") animation_1_frame_count; 
		float nicename("Animation 2 Frame Count") animation_2_frame_count; 
		float nicename("Animation 3 Frame Count") animation_3_frame_count; 
		float nicename("Animation 4 Frame Count") animation_4_frame_count; 
		float nicename("Animation 5 Frame Count") animation_5_frame_count; 
		int16_t nicename("Input") input; 
		int16_t nicename("Range Input") range_input; 
		// comment
		int32_t nicename("Input Variable Triggers") input_variable_triggers; 
		// comment
		int8_t nicename("Second State-Block Start Value") second_state_block_start_value; 
		int8_t nicename("Third State-Block Start Value") third_state_block_start_value; 
		// comment
		int16_t nicename("__0") __0; 
		int16_t nicename("__1") __1; 
		int16_t nicename("__2") __2; 
		int16_t nicename("__3") __3; 
		int16_t nicename("__4") __4; 
		int16_t nicename("__5") __5; 
		int16_t nicename("__6") __6; 
		int16_t nicename("__7") __7; 
		int16_t nicename("__8") __8; 
		int16_t nicename("__9") __9; 
		int16_t nicename("__10") __10; 
		int16_t nicename("__11") __11; 
		int16_t nicename("__12") __12; 
		int16_t nicename("__13") __13; 
		int16_t nicename("__14") __14; 
		int16_t nicename("__15") __15; 
		int16_t nicename("__16") __16; 
		int16_t nicename("__17") __17; 
		int16_t nicename("__18") __18; 
		int16_t nicename("__19") __19; 
		int16_t nicename("__20") __20; 
		int16_t nicename("__21") __21; 
		int16_t nicename("__22") __22; 
		int16_t nicename("__23") __23; 
		int16_t nicename("__24") __24; 
		int16_t nicename("__25") __25; 
		int16_t nicename("__26") __26; 
		int16_t nicename("__27") __27; 
		int16_t nicename("__28") __28; 
	};
};
