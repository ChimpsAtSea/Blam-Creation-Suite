#pragma once

struct nicename("Chud Definition") group('chdt') s_chud_definition_definition
{
	struct nicename("HUD Widgets") s_hud_widget_block_definition;
	struct nicename("Compiled Widget Data") s_compiled_widget_datum_block_definition;

	// comment
	// comment
	s_tag_block_definition<s_hud_widget_block_definition> nicename("HUD Widgets") hud_widgets_block; 
	signed int nicename("Low Clip Cutoff") low_clip_cutoff; 
	signed int nicename("Low Ammo Cutoff") low_ammo_cutoff; 
	signed int nicename("Age Cutoff") age_cutoff; 
	signed int nicename("Sword Age Cutoff") sword_age_cutoff; 
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
		signed char nicename("Special HUD Type") special_hud_type; 
		unsigned char __unknown; 
		unsigned char __unknown2; 
		unsigned char __unknown3; 
		signed short nicename("Import Input") import_input; 
		signed short nicename("Import Range Input") import_range_input; 
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
		signed int __unknown4; 
		signed short __unknown5; 
		signed short __unknown6; 
		signed short __unknown7; 
		signed short __unknown8; 
		// comment
		signed char nicename("Second State-Block Starting Value") second_state_block_starting_value; 
		signed char __unknown9; 
		signed char __unknown10; 
		signed char __unknown11; 
		// comment
		unsigned short nicename("Input Variable Triggers") input_variable_triggers; 
		// comment
		signed short nicename("__0") __0; 
		signed short nicename("__1") __1; 
		signed short nicename("__2") __2; 
		signed short nicename("__3") __3; 
		signed short nicename("__4") __4; 
		signed short nicename("__5") __5; 
		signed short nicename("__6") __6; 
		signed short nicename("__7") __7; 
		signed short nicename("__8") __8; 
		signed short nicename("__9") __9; 
		signed short nicename("__10") __10; 
		signed short nicename("__11") __11; 
		signed short nicename("__12") __12; 

		struct nicename("state_datum") s_state_datum_block_definition
		{
			struct nicename("'Yes' States") s__yes__state_block_definition;
			struct s_unknown_state_block_definition;
			struct nicename("'No' States") s__no__state_block_definition;

			// comment
			s_tag_block_definition<s__yes__state_block_definition> nicename("'Yes' States") _yes__states_block; 
			s_tag_block_definition<s_unknown_state_block_definition> __unknown_states_block; 
			s_tag_block_definition<s__no__state_block_definition> nicename("'No' States") _no__states_block; 
			signed short __unknown; 
			signed short __unknown2; 
			signed short __unknown3; 
			signed short __unknown4; 
			Unknown32 __unknown5; 
			Unknown32 __unknown6; 
			Unknown32 __unknown7; 

			struct nicename("_yes__state") s__yes__state_block_definition
			{
				struct nicename("Triggers") s_trigger_block_definition;

				s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

				struct nicename("trigger") s_trigger_block_definition
				{
					unsigned char nicename("Flag") flag; 
					signed char __unknown; 
					signed char __unknown2; 
					signed char __unknown3; 
					signed int nicename("Trigger Index") trigger_index; 
				};
			};

			struct s_unknown_state_block_definition
			{
				struct nicename("Triggers") s_trigger_block_definition;

				s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

				struct nicename("trigger") s_trigger_block_definition
				{
					unsigned char nicename("Flag") flag; 
					signed char __unknown; 
					signed char __unknown2; 
					signed char __unknown3; 
					signed int nicename("Trigger Index") trigger_index; 
				};
			};

			struct nicename("_no__state") s__no__state_block_definition
			{
				struct nicename("Triggers") s_trigger_block_definition;

				s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

				struct nicename("trigger") s_trigger_block_definition
				{
					unsigned char nicename("Flag") flag; 
					signed char __unknown; 
					signed char __unknown2; 
					signed char __unknown3; 
					signed int nicename("Trigger Index") trigger_index; 
				};
			};
		};

		struct nicename("placement_datum") s_placement_datum_block_definition
		{
			unsigned char __unknown; 
			signed char nicename("Anchor") anchor; 
			signed short __unknown2; 
			float nicename("Mirror Offset X") mirror_offset_x; 
			float nicename("Mirror Offset Y") mirror_offset_y; 
			float nicename("Offset X") offset_x; 
			float nicename("Offset Y") offset_y; 
			float nicename("Scale X") scale_x; 
			float nicename("Scale Y") scale_y; 
		};

		struct nicename("animation_datum") s_animation_datum_block_definition
		{
			unsigned char nicename("Animation 1 Flags") animation_1_flags; 
			signed char nicename("Animation 1 Function") animation_1_function; 
			signed short __unknown; 
			TagReference nicename("Animation 1") animation_1_reference; 
			unsigned char nicename("Animation 2 Flags") animation_2_flags; 
			signed char nicename("Animation 2 Function") animation_2_function; 
			signed short __unknown2; 
			TagReference nicename("Animation 2") animation_2_reference; 
			unsigned char nicename("Animation 3 Flags") animation_3_flags; 
			signed char nicename("Animation 3 Function") animation_3_function; 
			signed short __unknown3; 
			TagReference nicename("Animation 3") animation_3_reference; 
			unsigned char nicename("Animation 4 Flags") animation_4_flags; 
			signed char nicename("Animation 4 Function") animation_4_function; 
			signed short __unknown4; 
			TagReference nicename("Animation 4") animation_4_reference; 
			unsigned char nicename("Animation 5 Flags") animation_5_flags; 
			signed char nicename("Animation 5 Function") animation_5_function; 
			signed short __unknown5; 
			TagReference nicename("Animation 5") animation_5_reference; 
		};

		struct nicename("render_datum") s_render_datum_block_definition
		{
			signed char nicename("Shader Index") shader_index; 
			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
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
			signed short nicename("Output Color a") output_color_a; 
			signed short nicename("Output Color b") output_color_b; 
			signed short nicename("Output Color c") output_color_c; 
			signed short nicename("Output Color d") output_color_d; 
			signed short nicename("Output Color e") output_color_e; 
			signed short nicename("Output Color f") output_color_f; 
			signed short nicename("Output Scalar a") output_scalar_a; 
			signed short nicename("Output Scalar b") output_scalar_b; 
			signed short nicename("Output Scalar c") output_scalar_c; 
			signed short nicename("Output Scalar d") output_scalar_d; 
			signed short nicename("Output Scalar e") output_scalar_e; 
			signed short nicename("Output Scalar f") output_scalar_f; 
			Unknown32 __unknown4; 
			Unknown32 __unknown5; 
			signed short __unknown6; 
			signed short __unknown7; 
		};

		struct nicename("datasource") s_datasource_block_definition
		{
			struct s_unknown_6_block_definition;

			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed char __unknown4; 
			signed short __unknown5; 
			signed short __unknown6; 
			Unknown32 __unknown7; 
			Unknown32 __unknown8; 
			Unknown32 __unknown9; 
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
			signed char nicename("Special HUD Type") special_hud_type; 
			unsigned char __unknown; 
			unsigned char __unknown2; 
			unsigned char __unknown3; 
			signed short nicename("Import Input") import_input; 
			signed short nicename("Import Range Input") import_range_input; 
			TagReference nicename("State Data Template") state_data_template_reference; 
			s_tag_block_definition<s_state_datum_block_definition> nicename("State Data") state_data_block; 
			TagReference nicename("Placement Data Template") placement_data_template_reference; 
			s_tag_block_definition<s_placement_datum_block_definition> nicename("Placement Data") placement_data_block; 
			TagReference nicename("Animation Data Template") animation_data_template_reference; 
			s_tag_block_definition<s_animation_datum_block_definition> nicename("Animation Data") animation_data_block; 
			TagReference nicename("Render Data Template") render_data_template_reference; 
			s_tag_block_definition<s_render_datum_block_definition> nicename("Render Data") render_data_block; 
			signed int nicename("Flags") flags; 
			TagReference nicename("Bitmap") bitmap_reference; 
			unsigned char nicename("Bitmap Sprite Index") bitmap_sprite_index; 
			unsigned char __unknown4; 
			unsigned char __unknown5; 
			unsigned char __unknown6; 
			Unknown32 __unknown7; 
			Unknown32 __unknown8; 

			struct nicename("state_datum") s_state_datum_block_definition
			{
				struct nicename("'Yes' States") s__yes__state_block_definition;
				struct s_unknown_state_block_definition;
				struct nicename("'No' States") s__no__state_block_definition;

				// comment
				s_tag_block_definition<s__yes__state_block_definition> nicename("'Yes' States") _yes__states_block; 
				s_tag_block_definition<s_unknown_state_block_definition> __unknown_states_block; 
				s_tag_block_definition<s__no__state_block_definition> nicename("'No' States") _no__states_block; 
				signed short __unknown; 
				signed short __unknown2; 
				signed short __unknown3; 
				signed short __unknown4; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				Unknown32 __unknown7; 

				struct nicename("_yes__state") s__yes__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						unsigned char nicename("Flag") flag; 
						signed char __unknown; 
						signed char __unknown2; 
						signed char __unknown3; 
						signed int nicename("Trigger Index") trigger_index; 
					};
				};

				struct s_unknown_state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						unsigned char nicename("Flag") flag; 
						signed char __unknown; 
						signed char __unknown2; 
						signed char __unknown3; 
						signed int nicename("Trigger Index") trigger_index; 
					};
				};

				struct nicename("_no__state") s__no__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						unsigned char nicename("Flag") flag; 
						signed char __unknown; 
						signed char __unknown2; 
						signed char __unknown3; 
						signed int nicename("Trigger Index") trigger_index; 
					};
				};
			};

			struct nicename("placement_datum") s_placement_datum_block_definition
			{
				unsigned char __unknown; 
				signed char nicename("Anchor") anchor; 
				signed short __unknown2; 
				float nicename("Mirror Offset X") mirror_offset_x; 
				float nicename("Mirror Offset Y") mirror_offset_y; 
				float nicename("Offset X") offset_x; 
				float nicename("Offset Y") offset_y; 
				float nicename("Scale X") scale_x; 
				float nicename("Scale Y") scale_y; 
			};

			struct nicename("animation_datum") s_animation_datum_block_definition
			{
				unsigned char nicename("Animation 1 Flags") animation_1_flags; 
				signed char nicename("Animation 1 Function") animation_1_function; 
				signed short __unknown; 
				TagReference nicename("Animation 1") animation_1_reference; 
				unsigned char nicename("Animation 2 Flags") animation_2_flags; 
				signed char nicename("Animation 2 Function") animation_2_function; 
				signed short __unknown2; 
				TagReference nicename("Animation 2") animation_2_reference; 
				unsigned char nicename("Animation 3 Flags") animation_3_flags; 
				signed char nicename("Animation 3 Function") animation_3_function; 
				signed short __unknown3; 
				TagReference nicename("Animation 3") animation_3_reference; 
				unsigned char nicename("Animation 4 Flags") animation_4_flags; 
				signed char nicename("Animation 4 Function") animation_4_function; 
				signed short __unknown4; 
				TagReference nicename("Animation 4") animation_4_reference; 
				unsigned char nicename("Animation 5 Flags") animation_5_flags; 
				signed char nicename("Animation 5 Function") animation_5_function; 
				signed short __unknown5; 
				TagReference nicename("Animation 5") animation_5_reference; 
			};

			struct nicename("render_datum") s_render_datum_block_definition
			{
				signed char nicename("Shader Index") shader_index; 
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
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
				signed short nicename("Output Color a") output_color_a; 
				signed short nicename("Output Color b") output_color_b; 
				signed short nicename("Output Color c") output_color_c; 
				signed short nicename("Output Color d") output_color_d; 
				signed short nicename("Output Color e") output_color_e; 
				signed short nicename("Output Color f") output_color_f; 
				signed short nicename("Output Scalar a") output_scalar_a; 
				signed short nicename("Output Scalar b") output_scalar_b; 
				signed short nicename("Output Scalar c") output_scalar_c; 
				signed short nicename("Output Scalar d") output_scalar_d; 
				signed short nicename("Output Scalar e") output_scalar_e; 
				signed short nicename("Output Scalar f") output_scalar_f; 
				Unknown32 __unknown4; 
				Unknown32 __unknown5; 
				signed short __unknown6; 
				signed short __unknown7; 
			};
		};

		struct nicename("text_widget") s_text_widget_block_definition
		{
			struct nicename("State Data") s_state_datum_block_definition;
			struct nicename("Placement Data") s_placement_datum_block_definition;
			struct nicename("Animation Data") s_animation_datum_block_definition;
			struct nicename("Render Data") s_render_datum_block_definition;

			string_id nicename("Name") name; 
			signed char nicename("Special HUD Type") special_hud_type; 
			unsigned char __unknown; 
			unsigned char __unknown2; 
			unsigned char __unknown3; 
			signed short nicename("Import Input") import_input; 
			signed short nicename("Import Range Input") import_range_input; 
			TagReference nicename("State Data Template") state_data_template_reference; 
			s_tag_block_definition<s_state_datum_block_definition> nicename("State Data") state_data_block; 
			TagReference nicename("Placement Data Template") placement_data_template_reference; 
			s_tag_block_definition<s_placement_datum_block_definition> nicename("Placement Data") placement_data_block; 
			TagReference nicename("Animation Data Template") animation_data_template_reference; 
			s_tag_block_definition<s_animation_datum_block_definition> nicename("Animation Data") animation_data_block; 
			TagReference nicename("Render Data Template") render_data_template_reference; 
			s_tag_block_definition<s_render_datum_block_definition> nicename("Render Data") render_data_block; 
			unsigned short nicename("Flags") flags; 
			signed short nicename("Font") font; 
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
				signed short __unknown; 
				signed short __unknown2; 
				signed short __unknown3; 
				signed short __unknown4; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				Unknown32 __unknown7; 

				struct nicename("_yes__state") s__yes__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						unsigned char nicename("Flag") flag; 
						signed char __unknown; 
						signed char __unknown2; 
						signed char __unknown3; 
						signed int nicename("Trigger Index") trigger_index; 
					};
				};

				struct s_unknown_state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						unsigned char nicename("Flag") flag; 
						signed char __unknown; 
						signed char __unknown2; 
						signed char __unknown3; 
						signed int nicename("Trigger Index") trigger_index; 
					};
				};

				struct nicename("_no__state") s__no__state_block_definition
				{
					struct nicename("Triggers") s_trigger_block_definition;

					s_tag_block_definition<s_trigger_block_definition> nicename("Triggers") triggers_block; 

					struct nicename("trigger") s_trigger_block_definition
					{
						unsigned char nicename("Flag") flag; 
						signed char __unknown; 
						signed char __unknown2; 
						signed char __unknown3; 
						signed int nicename("Trigger Index") trigger_index; 
					};
				};
			};

			struct nicename("placement_datum") s_placement_datum_block_definition
			{
				unsigned char __unknown; 
				signed char nicename("Anchor") anchor; 
				signed short __unknown2; 
				float nicename("Mirror Offset X") mirror_offset_x; 
				float nicename("Mirror Offset Y") mirror_offset_y; 
				float nicename("Offset X") offset_x; 
				float nicename("Offset Y") offset_y; 
				float nicename("Scale X") scale_x; 
				float nicename("Scale Y") scale_y; 
			};

			struct nicename("animation_datum") s_animation_datum_block_definition
			{
				unsigned char nicename("Animation 1 Flags") animation_1_flags; 
				signed char nicename("Animation 1 Function") animation_1_function; 
				signed short __unknown; 
				TagReference nicename("Animation 1") animation_1_reference; 
				unsigned char nicename("Animation 2 Flags") animation_2_flags; 
				signed char nicename("Animation 2 Function") animation_2_function; 
				signed short __unknown2; 
				TagReference nicename("Animation 2") animation_2_reference; 
				unsigned char nicename("Animation 3 Flags") animation_3_flags; 
				signed char nicename("Animation 3 Function") animation_3_function; 
				signed short __unknown3; 
				TagReference nicename("Animation 3") animation_3_reference; 
				unsigned char nicename("Animation 4 Flags") animation_4_flags; 
				signed char nicename("Animation 4 Function") animation_4_function; 
				signed short __unknown4; 
				TagReference nicename("Animation 4") animation_4_reference; 
				unsigned char nicename("Animation 5 Flags") animation_5_flags; 
				signed char nicename("Animation 5 Function") animation_5_function; 
				signed short __unknown5; 
				TagReference nicename("Animation 5") animation_5_reference; 
			};

			struct nicename("render_datum") s_render_datum_block_definition
			{
				signed char nicename("Shader Index") shader_index; 
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
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
				signed short nicename("Output Color a") output_color_a; 
				signed short nicename("Output Color b") output_color_b; 
				signed short nicename("Output Color c") output_color_c; 
				signed short nicename("Output Color d") output_color_d; 
				signed short nicename("Output Color e") output_color_e; 
				signed short nicename("Output Color f") output_color_f; 
				signed short nicename("Output Scalar a") output_scalar_a; 
				signed short nicename("Output Scalar b") output_scalar_b; 
				signed short nicename("Output Scalar c") output_scalar_c; 
				signed short nicename("Output Scalar d") output_scalar_d; 
				signed short nicename("Output Scalar e") output_scalar_e; 
				signed short nicename("Output Scalar f") output_scalar_f; 
				Unknown32 __unknown4; 
				Unknown32 __unknown5; 
				signed short __unknown6; 
				signed short __unknown7; 
			};
		};
	};

	struct nicename("compiled_widget_datum") s_compiled_widget_datum_block_definition
	{
		signed char nicename("Special HUD Type") special_hud_type; 
		unsigned char __unknown; 
		unsigned char __unknown2; 
		unsigned char __unknown3; 
		float nicename("Animation 1 Frame Count") animation_1_frame_count; 
		float nicename("Animation 2 Frame Count") animation_2_frame_count; 
		float nicename("Animation 3 Frame Count") animation_3_frame_count; 
		float nicename("Animation 4 Frame Count") animation_4_frame_count; 
		float nicename("Animation 5 Frame Count") animation_5_frame_count; 
		signed short nicename("Input") input; 
		signed short nicename("Range Input") range_input; 
		// comment
		signed int nicename("Input Variable Triggers") input_variable_triggers; 
		// comment
		signed char nicename("Second State-Block Start Value") second_state_block_start_value; 
		signed char nicename("Third State-Block Start Value") third_state_block_start_value; 
		// comment
		signed short nicename("__0") __0; 
		signed short nicename("__1") __1; 
		signed short nicename("__2") __2; 
		signed short nicename("__3") __3; 
		signed short nicename("__4") __4; 
		signed short nicename("__5") __5; 
		signed short nicename("__6") __6; 
		signed short nicename("__7") __7; 
		signed short nicename("__8") __8; 
		signed short nicename("__9") __9; 
		signed short nicename("__10") __10; 
		signed short nicename("__11") __11; 
		signed short nicename("__12") __12; 
		signed short nicename("__13") __13; 
		signed short nicename("__14") __14; 
		signed short nicename("__15") __15; 
		signed short nicename("__16") __16; 
		signed short nicename("__17") __17; 
		signed short nicename("__18") __18; 
		signed short nicename("__19") __19; 
		signed short nicename("__20") __20; 
		signed short nicename("__21") __21; 
		signed short nicename("__22") __22; 
		signed short nicename("__23") __23; 
		signed short nicename("__24") __24; 
		signed short nicename("__25") __25; 
		signed short nicename("__26") __26; 
		signed short nicename("__27") __27; 
		signed short nicename("__28") __28; 
	};
};
