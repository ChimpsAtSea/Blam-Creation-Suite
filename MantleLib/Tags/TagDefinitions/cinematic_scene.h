#pragma once

struct nicename("cinematic_scene") group('cisc') s_cinematic_scene_definition
{
	struct nicename("Puppets") s_puppets_definition
	{
		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui32 << 0ui32,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
			/*nicename("Player")*/ _flags_player = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
		};

		struct nicename("Puppet Firing") s_puppet_firing_definition
		{
			int16_t __unknown0;
			int16_t __unknown1;
			string_id __unknown2;
			string_id nicename("Name") name;
			string_id __unknown3;
			TagReference nicename("Object") object_reference;
		};

		string_id nicename("Import Name") import_name;
		string_id nicename("Name") name;
		string_id nicename("Variant") variant;
		TagReference nicename("Puppet Animation") puppet_animation_reference;
		TagReference nicename("Puppet Object") puppet_object_reference;
		b_flags nicename("Flags") flags;
		uint32_t __unknown0;
		int32_t __unknown1;
		Undefined32 __unknown2;
		DataReference nicename("Import Script") import_script_data_reference;
		s_tag_block_definition<s_puppet_firing_definition> nicename("Puppet Firing") puppet_firing_block;
	};

	struct nicename("Shots") s_shots_definition
	{
		struct nicename("Lighting") s_lighting_definition
		{
			int32_t __unknown0;
			TagReference nicename("Cinematic Light") cinematic_light_reference;
			int32_t nicename("Owner Puppet Index") owner_puppet_index;
			int32_t __unknown1;
		};

		struct nicename("Sounds") s_sounds_definition
		{
			TagReference nicename("Sound") sound_reference;
			TagReference nicename("Sound") sound1_reference;
			int32_t nicename("Frame") frame;
			float __unknown0;
			string_id __unknown1;
			Undefined32 __unknown2;
			string_id __unknown3;
			string_id __unknown4;
			string_id __unknown5;
		};

		struct nicename("Background Sounds") s_background_sounds_definition
		{
			Undefined32 __unknown0;
			TagReference nicename("Sound") sound_reference;
			int32_t nicename("Frame") frame;
		};

		struct nicename("Effects") s_effects_definition
		{
			Undefined32 __unknown0;
			TagReference nicename("Effect") effect_reference;
			int32_t nicename("Frame") frame;
			string_id nicename("Marker") marker;
			int32_t nicename("Owner Puppet Index") owner_puppet_index;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
		};

		struct nicename("Functions") s_functions_definition
		{
			struct nicename("Values") s_values_definition
			{
				Undefined32 __unknown0;
				int32_t __unknown1;
				float __unknown2;
				float __unknown3;
			};

			int32_t nicename("Owner Puppet Index") owner_puppet_index;
			string_id nicename("Target Function Name") target_function_name;
			s_tag_block_definition<s_values_definition> nicename("Values") values_block;
		};

		struct nicename("Screen Effects") s_screen_effects_definition
		{
			TagReference nicename("Effect") effect_reference;
			int32_t nicename("Start Frame") start_frame;
			int32_t nicename("End Frame") end_frame;
		};

		struct nicename("Import Scripts") s_import_scripts_definition
		{
			int8_t __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int32_t nicename("Frame") frame;
			DataReference nicename("Import Script") import_script_data_reference;
			uint32_t __unknown4;
			int32_t __unknown5;
		};

		struct nicename("Unknown 10") s_unknown_10_definition
		{
			int32_t __unknown0;
			int32_t __unknown1;
			int16_t __unknown2;
			int16_t __unknown3;
			int16_t __unknown4;
			int16_t __unknown5;
			float __unknown6;
		};

		struct nicename("Camera Frames") s_camera_frames_definition
		{
			float nicename("X") x;
			float nicename("Y") y;
			float nicename("Z") z;
			float __unknown0;
			float __unknown1;
			float __unknown2;
			float __unknown3;
			float __unknown4;
			float __unknown5;
		};

		struct nicename("Depth Of Field Frames") s_depth_of_field_frames_definition
		{
			enum nicename("Flags") b_flags : uint32_t /* bitfield */
			{
				/*nicename("Enable Depth Of Field")*/ _flags_enable_depth_of_field = 1ui32 << 0ui32,
				/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
				/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
			};

			int32_t nicename("Frame") frame;
			float nicename("FOV") fov;
			b_flags nicename("Flags") flags;
			float nicename("Near Plane") near_plane;
			float nicename("Far Plane") far_plane;
			float nicename("Focal Depth") focal_depth;
			float nicename("Blur Amount") blur_amount;
		};

		DataReference nicename("Opening Import Script") opening_import_script_data_reference;
		int32_t __unknown0;
		float __unknown1;
		float __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		s_tag_block_definition<s_lighting_definition> nicename("Lighting") lighting_block;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		s_tag_block_definition<s_sounds_definition> nicename("Sounds") sounds_block;
		s_tag_block_definition<s_background_sounds_definition> nicename("Background Sounds") background_sounds_block;
		s_tag_block_definition<s_effects_definition> nicename("Effects") effects_block;
		s_tag_block_definition<s_functions_definition> nicename("Functions") functions_block;
		s_tag_block_definition<s_screen_effects_definition> nicename("Screen Effects") screen_effects_block;
		s_tag_block_definition<s_import_scripts_definition> nicename("Import Scripts") import_scripts_block;
		s_tag_block_definition<s_unknown_10_definition> nicename("Unknown 10") unknown_10_block;
		DataReference nicename("Import Script") import_script_data_reference;
		int32_t nicename("Loaded Frame Count") loaded_frame_count;
		Undefined32 __unknown9;
		Undefined32 __unknown10;
		Undefined32 __unknown11;
		s_tag_block_definition<s_camera_frames_definition> nicename("Camera Frames") camera_frames_block;
		s_tag_block_definition<s_depth_of_field_frames_definition> nicename("Depth Of Field Frames") depth_of_field_frames_block;
	};

	struct nicename("Texture Cameras") s_texture_cameras_definition
	{
		struct nicename("Shots") s_shots1_definition
		{
			struct nicename("Frames") s_frames_definition
			{
				enum nicename("Flags") b_flags : uint32_t /* bitfield */
				{
					/*nicename("Enable Depth Of Field")*/ _flags_enable_depth_of_field = 1ui32 << 0ui32,
					/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
					/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
					/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
					/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
					/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
					/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
					/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
					/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
					/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
					/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
					/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
					/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
					/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
					/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
					/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
					/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
					/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
					/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
					/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
					/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
					/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
					/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
					/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
					/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
					/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
					/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
					/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
					/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
					/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
					/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
					/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
				};

				int32_t __unknown0;
				float nicename("X") x;
				float nicename("Y") y;
				float nicename("Z") z;
				float __unknown1;
				float __unknown2;
				float __unknown3;
				float __unknown4;
				float __unknown5;
				float __unknown6;
				float nicename("FOV") fov;
				// Depth Of Field : 
				b_flags nicename("Flags") flags;
				float nicename("Near Plane") near_plane;
				float nicename("Far Plane") far_plane;
				float nicename("Focal Depth") focal_depth;
				float nicename("Blur Amount") blur_amount;
			};

			s_tag_block_definition<s_frames_definition> nicename("Frames") frames_block;
		};

		string_id nicename("Name") name;
		string_id __unknown0;
		s_tag_block_definition<s_shots1_definition> nicename("Shots") shots_block;
	};

	string_id nicename("Name") name;
	string_id nicename("Anchor Name") anchor_name;
	Undefined32 __unknown0;
	DataReference nicename("Import Script") import_script_data_reference;
	s_tag_block_definition<s_puppets_definition> nicename("Puppets") puppets_block;
	s_tag_block_definition<s_shots_definition> nicename("Shots") shots_block;
	s_tag_block_definition<s_texture_cameras_definition> nicename("Texture Cameras") texture_cameras_block;
	DataReference nicename("Import Script") import_script1_data_reference;
	int32_t __unknown1;
};

