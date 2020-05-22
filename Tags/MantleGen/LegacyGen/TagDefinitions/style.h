#pragma once

struct nicename("style") tag_group('styl') s_style_definition_legacy
{
	enum nicename("Combat Status Decay Options") e_combat_status_decay_options : uint16_t
	{
		/*nicename("Latch at Idle")*/ _combat_status_decay_options_latch_at_idle = 0ui16,
		/*nicename("Latch at Alert")*/ _combat_status_decay_options_latch_at_alert = 1ui16,
		/*nicename("Latch at Combat")*/ _combat_status_decay_options_latch_at_combat = 2ui16,
	};

	enum nicename("Special Movement 1") b_special_movement_1 : uint32_t /* bitfield */
	{
		/*nicename("New Behaviors Default To ON")*/ _special_movement_1_new_behaviors_default_to_on = 1ui32 << 0ui32,
	};

	enum nicename("Behaviors1") b_behaviors1 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors1_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors1_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors1_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors1_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors1_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors1_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors1_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors1_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors1_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors1_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors1_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors1_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors1_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors1_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors1_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors1_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors1_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors1_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors1_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors1_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors1_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors1_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors1_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors1_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors1_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors1_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors1_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors1_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors1_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors1_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors1_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors1_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors2") b_behaviors2 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors2_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors2_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors2_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors2_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors2_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors2_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors2_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors2_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors2_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors2_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors2_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors2_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors2_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors2_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors2_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors2_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors2_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors2_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors2_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors2_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors2_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors2_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors2_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors2_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors2_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors2_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors2_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors2_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors2_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors2_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors2_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors2_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors3") b_behaviors3 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors3_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors3_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors3_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors3_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors3_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors3_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors3_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors3_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors3_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors3_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors3_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors3_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors3_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors3_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors3_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors3_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors3_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors3_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors3_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors3_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors3_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors3_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors3_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors3_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors3_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors3_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors3_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors3_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors3_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors3_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors3_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors3_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors4") b_behaviors4 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors4_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors4_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors4_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors4_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors4_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors4_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors4_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors4_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors4_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors4_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors4_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors4_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors4_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors4_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors4_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors4_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors4_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors4_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors4_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors4_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors4_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors4_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors4_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors4_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors4_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors4_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors4_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors4_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors4_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors4_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors4_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors4_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors5") b_behaviors5 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors5_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors5_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors5_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors5_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors5_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors5_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors5_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors5_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors5_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors5_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors5_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors5_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors5_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors5_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors5_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors5_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors5_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors5_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors5_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors5_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors5_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors5_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors5_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors5_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors5_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors5_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors5_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors5_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors5_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors5_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors5_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors5_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors6") b_behaviors6 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors6_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors6_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors6_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors6_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors6_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors6_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors6_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors6_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors6_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors6_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors6_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors6_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors6_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors6_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors6_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors6_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors6_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors6_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors6_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors6_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors6_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors6_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors6_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors6_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors6_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors6_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors6_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors6_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors6_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors6_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors6_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors6_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors7") b_behaviors7 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors7_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors7_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors7_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors7_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors7_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors7_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors7_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors7_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors7_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors7_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors7_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors7_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors7_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors7_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors7_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors7_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors7_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors7_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors7_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors7_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors7_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors7_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors7_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors7_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors7_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors7_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors7_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors7_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors7_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors7_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors7_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors7_bit_31 = 1ui32 << 31ui32,
	};

	enum nicename("Behaviors8") b_behaviors8 : uint32_t /* bitfield */
	{
		/*nicename("Bit 0")*/ _behaviors8_bit_0 = 1ui32 << 0ui32,
		/*nicename("Bit 1")*/ _behaviors8_bit_1 = 1ui32 << 1ui32,
		/*nicename("Bit 2")*/ _behaviors8_bit_2 = 1ui32 << 2ui32,
		/*nicename("Bit 3")*/ _behaviors8_bit_3 = 1ui32 << 3ui32,
		/*nicename("Bit 4")*/ _behaviors8_bit_4 = 1ui32 << 4ui32,
		/*nicename("Bit 5")*/ _behaviors8_bit_5 = 1ui32 << 5ui32,
		/*nicename("Bit 6")*/ _behaviors8_bit_6 = 1ui32 << 6ui32,
		/*nicename("Bit 7")*/ _behaviors8_bit_7 = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _behaviors8_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _behaviors8_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _behaviors8_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _behaviors8_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _behaviors8_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _behaviors8_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _behaviors8_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _behaviors8_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _behaviors8_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _behaviors8_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _behaviors8_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _behaviors8_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _behaviors8_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _behaviors8_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _behaviors8_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _behaviors8_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _behaviors8_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _behaviors8_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _behaviors8_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _behaviors8_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _behaviors8_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _behaviors8_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _behaviors8_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _behaviors8_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Special Movement") s_special_movement_definition_legacy
	{
		enum nicename("Special Movement 1") b_special_movement_11 : uint32_t /* bitfield */
		{
			/*nicename("Jump")*/ _special_movement_11_jump = 1ui32 << 0ui32,
			/*nicename("Climb")*/ _special_movement_11_climb = 1ui32 << 1ui32,
			/*nicename("Vault")*/ _special_movement_11_vault = 1ui32 << 2ui32,
			/*nicename("Mount")*/ _special_movement_11_mount = 1ui32 << 3ui32,
			/*nicename("Hoist")*/ _special_movement_11_hoist = 1ui32 << 4ui32,
			/*nicename("Wall Jump")*/ _special_movement_11_wall_jump = 1ui32 << 5ui32,
			/*nicename("N/A")*/ _special_movement_11_n_a = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _special_movement_11_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _special_movement_11_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _special_movement_11_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _special_movement_11_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _special_movement_11_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _special_movement_11_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _special_movement_11_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _special_movement_11_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _special_movement_11_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _special_movement_11_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _special_movement_11_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _special_movement_11_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _special_movement_11_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _special_movement_11_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _special_movement_11_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _special_movement_11_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _special_movement_11_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _special_movement_11_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _special_movement_11_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _special_movement_11_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _special_movement_11_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _special_movement_11_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _special_movement_11_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _special_movement_11_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _special_movement_11_bit_31 = 1ui32 << 31ui32,
		};

		b_special_movement_11 nicename("Special Movement 1") special_movement_1;
	};

	struct nicename("Behavior List") s_behavior_list_definition_legacy
	{
		char nicename("Behavior Name") behavior_name[32];
	};

	char nicename("Name") name[32];
	e_combat_status_decay_options nicename("Combat Status Decay Options") combat_status_decay_options;
	int16_t __unknown0;
	b_special_movement_1 nicename("Special Movement 1") special_movement_1;
	b_behaviors1 nicename("Behaviors1") behaviors1;
	b_behaviors2 nicename("Behaviors2") behaviors2;
	b_behaviors3 nicename("Behaviors3") behaviors3;
	b_behaviors4 nicename("Behaviors4") behaviors4;
	b_behaviors5 nicename("Behaviors5") behaviors5;
	b_behaviors6 nicename("Behaviors6") behaviors6;
	b_behaviors7 nicename("Behaviors7") behaviors7;
	b_behaviors8 nicename("Behaviors8") behaviors8;
	s_tag_block_legacy<s_special_movement_definition_legacy> nicename("Special Movement") special_movement_block;
	s_tag_block_legacy<s_behavior_list_definition_legacy> nicename("Behavior List") behavior_list_block;
};

