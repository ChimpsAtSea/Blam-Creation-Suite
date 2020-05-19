#pragma once

struct nicename("chud_widget_placement_data_template") tag_group('wpdt') s_chud_widget_placement_data_template_definition_legacy
{
	struct nicename("Placement Data") s_placement_data_definition_legacy
	{
		enum nicename("Anchor") e_anchor : uint8_t
		{
			/*nicename("Unknown")*/ _anchor_unknown = 0ui8,
			/*nicename("Top, Left")*/ _anchor_top_left = 1ui8,
			/*nicename("Top, Middle")*/ _anchor_top_middle = 2ui8,
			/*nicename("Top, Right")*/ _anchor_top_right = 3ui8,
			/*nicename("Center, Middle")*/ _anchor_center_middle = 4ui8,
			/*nicename("Bottom, Left")*/ _anchor_bottom_left = 5ui8,
			/*nicename("Bottom, Middle")*/ _anchor_bottom_middle = 6ui8,
			/*nicename("Bottom, Right")*/ _anchor_bottom_right = 7ui8,
			/*nicename("Motion Sensor")*/ _anchor_motion_sensor = 8ui8,
			/*nicename("Crosshair A")*/ _anchor_crosshair_a = 9ui8,
			/*nicename("Ability")*/ _anchor_ability = 10ui8,
			/*nicename("Weapon Left")*/ _anchor_weapon_left = 11ui8,
			/*nicename("Weapon Right")*/ _anchor_weapon_right = 12ui8,
			/*nicename("Health and Shield")*/ _anchor_health_and_shield = 13ui8,
			/*nicename("Unknown")*/ _anchor_unknown1 = 14ui8,
			/*nicename("Top, Left B")*/ _anchor_top_left_b = 15ui8,
			/*nicename("Unknown")*/ _anchor_unknown2 = 16ui8,
			/*nicename("Crosshair B")*/ _anchor_crosshair_b = 17ui8,
			/*nicename("Top, Left C")*/ _anchor_top_left_c = 18ui8,
			/*nicename("Top, Left D")*/ _anchor_top_left_d = 19ui8,
			/*nicename("Top, Left E")*/ _anchor_top_left_e = 20ui8,
			/*nicename("Crosshair B")*/ _anchor_crosshair_b1 = 21ui8,
			/*nicename("Top, Left F")*/ _anchor_top_left_f = 22ui8,
			/*nicename("Unknown")*/ _anchor_unknown3 = 23ui8,
			/*nicename("Top, Left G")*/ _anchor_top_left_g = 24ui8,
			/*nicename("Unknown")*/ _anchor_unknown4 = 25ui8,
			/*nicename("Top, Left F")*/ _anchor_top_left_f1 = 26ui8,
			/*nicename("Score")*/ _anchor_score = 27ui8,
			/*nicename("Score B")*/ _anchor_score_b = 28ui8,
			/*nicename("Score C")*/ _anchor_score_c = 29ui8,
			/*nicename("Score D")*/ _anchor_score_d = 30ui8,
			/*nicename("Score E")*/ _anchor_score_e = 31ui8,
			/*nicename("Score F")*/ _anchor_score_f = 32ui8,
			/*nicename("Score G")*/ _anchor_score_g = 33ui8,
			/*nicename("Unknown")*/ _anchor_unknown5 = 34ui8,
			/*nicename("Unknown")*/ _anchor_unknown6 = 35ui8,
			/*nicename("Unknown")*/ _anchor_unknown7 = 36ui8,
			/*nicename("Unknown")*/ _anchor_unknown8 = 37ui8,
			/*nicename("Unknown")*/ _anchor_unknown9 = 38ui8,
			/*nicename("Unknown")*/ _anchor_unknown10 = 39ui8,
		};

		enum b_unknown : uint8_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _unknown_bit_0 = 1ui8 << 0ui8,
			/*nicename("Bit 1")*/ _unknown_bit_1 = 1ui8 << 1ui8,
			/*nicename("Bit 2")*/ _unknown_bit_2 = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _unknown_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _unknown_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _unknown_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _unknown_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _unknown_bit_7 = 1ui8 << 7ui8,
		};

		b_unknown __unknown0;
		e_anchor nicename("Anchor") anchor;
		int16_t __unknown1;
		float nicename("Mirror Offset X") mirror_offset_x;
		float nicename("Mirror Offset Y") mirror_offset_y;
		float nicename("Offset X") offset_x;
		float nicename("Offset Y") offset_y;
		float nicename("Scale X") scale_x;
		float nicename("Scale Y") scale_y;
	};

	s_tag_block_legacy<s_placement_data_definition_legacy> nicename("Placement Data") placement_data_block;
};

