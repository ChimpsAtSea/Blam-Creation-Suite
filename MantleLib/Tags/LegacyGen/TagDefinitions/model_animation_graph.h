#pragma once

struct nicename("model_animation_graph") tag_group('jmad') s_model_animation_graph_definition
{
	enum nicename("Inheritance Flags") b_inheritance_flags : uint8_t /* bitfield */
	{
		/*nicename("Inherit Root Trans Scale Only")*/ _inheritance_flags_inherit_root_trans_scale_only = 1ui8 << 0ui8,
		/*nicename("Inherit For Use On Player")*/ _inheritance_flags_inherit_for_use_on_player = 1ui8 << 1ui8,
		/*nicename("Bit 2")*/ _inheritance_flags_bit_2 = 1ui8 << 2ui8,
		/*nicename("Bit 3")*/ _inheritance_flags_bit_3 = 1ui8 << 3ui8,
		/*nicename("Bit 4")*/ _inheritance_flags_bit_4 = 1ui8 << 4ui8,
		/*nicename("Bit 5")*/ _inheritance_flags_bit_5 = 1ui8 << 5ui8,
		/*nicename("Bit 6")*/ _inheritance_flags_bit_6 = 1ui8 << 6ui8,
		/*nicename("Bit 7")*/ _inheritance_flags_bit_7 = 1ui8 << 7ui8,
	};

	enum nicename("Private Flags") b_private_flags : uint8_t /* bitfield */
	{
		/*nicename("Prepared For Cache")*/ _private_flags_prepared_for_cache = 1ui8 << 0ui8,
		/*nicename("Bit 1")*/ _private_flags_bit_1 = 1ui8 << 1ui8,
		/*nicename("Imported With Codec Compressors")*/ _private_flags_imported_with_codec_compressors = 1ui8 << 2ui8,
		/*nicename("Bit 3")*/ _private_flags_bit_3 = 1ui8 << 3ui8,
		/*nicename("Written To Cache")*/ _private_flags_written_to_cache = 1ui8 << 4ui8,
		/*nicename("Animation Data Reordered")*/ _private_flags_animation_data_reordered = 1ui8 << 5ui8,
		/*nicename("Bit 6")*/ _private_flags_bit_6 = 1ui8 << 6ui8,
		/*nicename("Bit 7")*/ _private_flags_bit_7 = 1ui8 << 7ui8,
	};

	enum nicename("Unknown Arm Nodes 1") b_unknown_arm_nodes_1 : uint32_t /* bitfield */
	{
		/*nicename("Node 0")*/ _unknown_arm_nodes_1_node_0 = 1ui32 << 0ui32,
		/*nicename("Node 1")*/ _unknown_arm_nodes_1_node_1 = 1ui32 << 1ui32,
		/*nicename("Node 2")*/ _unknown_arm_nodes_1_node_2 = 1ui32 << 2ui32,
		/*nicename("Node 3")*/ _unknown_arm_nodes_1_node_3 = 1ui32 << 3ui32,
		/*nicename("Node 4")*/ _unknown_arm_nodes_1_node_4 = 1ui32 << 4ui32,
		/*nicename("Node 5")*/ _unknown_arm_nodes_1_node_5 = 1ui32 << 5ui32,
		/*nicename("Node 6")*/ _unknown_arm_nodes_1_node_6 = 1ui32 << 6ui32,
		/*nicename("Node 7")*/ _unknown_arm_nodes_1_node_7 = 1ui32 << 7ui32,
		/*nicename("Node 8")*/ _unknown_arm_nodes_1_node_8 = 1ui32 << 8ui32,
		/*nicename("Node 9")*/ _unknown_arm_nodes_1_node_9 = 1ui32 << 9ui32,
		/*nicename("Node 10")*/ _unknown_arm_nodes_1_node_10 = 1ui32 << 10ui32,
		/*nicename("Node 11")*/ _unknown_arm_nodes_1_node_11 = 1ui32 << 11ui32,
		/*nicename("Node 12")*/ _unknown_arm_nodes_1_node_12 = 1ui32 << 12ui32,
		/*nicename("Node 13")*/ _unknown_arm_nodes_1_node_13 = 1ui32 << 13ui32,
		/*nicename("Node 14")*/ _unknown_arm_nodes_1_node_14 = 1ui32 << 14ui32,
		/*nicename("Node 15")*/ _unknown_arm_nodes_1_node_15 = 1ui32 << 15ui32,
		/*nicename("Node 16")*/ _unknown_arm_nodes_1_node_16 = 1ui32 << 16ui32,
		/*nicename("Node 17")*/ _unknown_arm_nodes_1_node_17 = 1ui32 << 17ui32,
		/*nicename("Node 18")*/ _unknown_arm_nodes_1_node_18 = 1ui32 << 18ui32,
		/*nicename("Node 19")*/ _unknown_arm_nodes_1_node_19 = 1ui32 << 19ui32,
		/*nicename("Node 20")*/ _unknown_arm_nodes_1_node_20 = 1ui32 << 20ui32,
		/*nicename("Node 21")*/ _unknown_arm_nodes_1_node_21 = 1ui32 << 21ui32,
		/*nicename("Node 22")*/ _unknown_arm_nodes_1_node_22 = 1ui32 << 22ui32,
		/*nicename("Node 23")*/ _unknown_arm_nodes_1_node_23 = 1ui32 << 23ui32,
		/*nicename("Node 24")*/ _unknown_arm_nodes_1_node_24 = 1ui32 << 24ui32,
		/*nicename("Node 25")*/ _unknown_arm_nodes_1_node_25 = 1ui32 << 25ui32,
		/*nicename("Node 26")*/ _unknown_arm_nodes_1_node_26 = 1ui32 << 26ui32,
		/*nicename("Node 27")*/ _unknown_arm_nodes_1_node_27 = 1ui32 << 27ui32,
		/*nicename("Node 28")*/ _unknown_arm_nodes_1_node_28 = 1ui32 << 28ui32,
		/*nicename("Node 29")*/ _unknown_arm_nodes_1_node_29 = 1ui32 << 29ui32,
		/*nicename("Node 30")*/ _unknown_arm_nodes_1_node_30 = 1ui32 << 30ui32,
		/*nicename("Node 31")*/ _unknown_arm_nodes_1_node_31 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 2") b_unknown_arm_nodes_2 : uint32_t /* bitfield */
	{
		/*nicename("Node 32")*/ _unknown_arm_nodes_2_node_32 = 1ui32 << 0ui32,
		/*nicename("Node 33")*/ _unknown_arm_nodes_2_node_33 = 1ui32 << 1ui32,
		/*nicename("Node 34")*/ _unknown_arm_nodes_2_node_34 = 1ui32 << 2ui32,
		/*nicename("Node 35")*/ _unknown_arm_nodes_2_node_35 = 1ui32 << 3ui32,
		/*nicename("Node 36")*/ _unknown_arm_nodes_2_node_36 = 1ui32 << 4ui32,
		/*nicename("Node 37")*/ _unknown_arm_nodes_2_node_37 = 1ui32 << 5ui32,
		/*nicename("Node 38")*/ _unknown_arm_nodes_2_node_38 = 1ui32 << 6ui32,
		/*nicename("Node 39")*/ _unknown_arm_nodes_2_node_39 = 1ui32 << 7ui32,
		/*nicename("Node 40")*/ _unknown_arm_nodes_2_node_40 = 1ui32 << 8ui32,
		/*nicename("Node 41")*/ _unknown_arm_nodes_2_node_41 = 1ui32 << 9ui32,
		/*nicename("Node 42")*/ _unknown_arm_nodes_2_node_42 = 1ui32 << 10ui32,
		/*nicename("Node 43")*/ _unknown_arm_nodes_2_node_43 = 1ui32 << 11ui32,
		/*nicename("Node 44")*/ _unknown_arm_nodes_2_node_44 = 1ui32 << 12ui32,
		/*nicename("Node 45")*/ _unknown_arm_nodes_2_node_45 = 1ui32 << 13ui32,
		/*nicename("Node 46")*/ _unknown_arm_nodes_2_node_46 = 1ui32 << 14ui32,
		/*nicename("Node 47")*/ _unknown_arm_nodes_2_node_47 = 1ui32 << 15ui32,
		/*nicename("Node 48")*/ _unknown_arm_nodes_2_node_48 = 1ui32 << 16ui32,
		/*nicename("Node 49")*/ _unknown_arm_nodes_2_node_49 = 1ui32 << 17ui32,
		/*nicename("Node 50")*/ _unknown_arm_nodes_2_node_50 = 1ui32 << 18ui32,
		/*nicename("Node 51")*/ _unknown_arm_nodes_2_node_51 = 1ui32 << 19ui32,
		/*nicename("Node 52")*/ _unknown_arm_nodes_2_node_52 = 1ui32 << 20ui32,
		/*nicename("Node 53")*/ _unknown_arm_nodes_2_node_53 = 1ui32 << 21ui32,
		/*nicename("Node 54")*/ _unknown_arm_nodes_2_node_54 = 1ui32 << 22ui32,
		/*nicename("Node 55")*/ _unknown_arm_nodes_2_node_55 = 1ui32 << 23ui32,
		/*nicename("Node 56")*/ _unknown_arm_nodes_2_node_56 = 1ui32 << 24ui32,
		/*nicename("Node 57")*/ _unknown_arm_nodes_2_node_57 = 1ui32 << 25ui32,
		/*nicename("Node 58")*/ _unknown_arm_nodes_2_node_58 = 1ui32 << 26ui32,
		/*nicename("Node 59")*/ _unknown_arm_nodes_2_node_59 = 1ui32 << 27ui32,
		/*nicename("Node 60")*/ _unknown_arm_nodes_2_node_60 = 1ui32 << 28ui32,
		/*nicename("Node 61")*/ _unknown_arm_nodes_2_node_61 = 1ui32 << 29ui32,
		/*nicename("Node 62")*/ _unknown_arm_nodes_2_node_62 = 1ui32 << 30ui32,
		/*nicename("Node 63")*/ _unknown_arm_nodes_2_node_63 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 3") b_unknown_arm_nodes_3 : uint32_t /* bitfield */
	{
		/*nicename("Node 64")*/ _unknown_arm_nodes_3_node_64 = 1ui32 << 0ui32,
		/*nicename("Node 65")*/ _unknown_arm_nodes_3_node_65 = 1ui32 << 1ui32,
		/*nicename("Node 66")*/ _unknown_arm_nodes_3_node_66 = 1ui32 << 2ui32,
		/*nicename("Node 67")*/ _unknown_arm_nodes_3_node_67 = 1ui32 << 3ui32,
		/*nicename("Node 68")*/ _unknown_arm_nodes_3_node_68 = 1ui32 << 4ui32,
		/*nicename("Node 69")*/ _unknown_arm_nodes_3_node_69 = 1ui32 << 5ui32,
		/*nicename("Node 70")*/ _unknown_arm_nodes_3_node_70 = 1ui32 << 6ui32,
		/*nicename("Node 71")*/ _unknown_arm_nodes_3_node_71 = 1ui32 << 7ui32,
		/*nicename("Node 72")*/ _unknown_arm_nodes_3_node_72 = 1ui32 << 8ui32,
		/*nicename("Node 73")*/ _unknown_arm_nodes_3_node_73 = 1ui32 << 9ui32,
		/*nicename("Node 74")*/ _unknown_arm_nodes_3_node_74 = 1ui32 << 10ui32,
		/*nicename("Node 75")*/ _unknown_arm_nodes_3_node_75 = 1ui32 << 11ui32,
		/*nicename("Node 76")*/ _unknown_arm_nodes_3_node_76 = 1ui32 << 12ui32,
		/*nicename("Node 77")*/ _unknown_arm_nodes_3_node_77 = 1ui32 << 13ui32,
		/*nicename("Node 78")*/ _unknown_arm_nodes_3_node_78 = 1ui32 << 14ui32,
		/*nicename("Node 79")*/ _unknown_arm_nodes_3_node_79 = 1ui32 << 15ui32,
		/*nicename("Node 80")*/ _unknown_arm_nodes_3_node_80 = 1ui32 << 16ui32,
		/*nicename("Node 81")*/ _unknown_arm_nodes_3_node_81 = 1ui32 << 17ui32,
		/*nicename("Node 82")*/ _unknown_arm_nodes_3_node_82 = 1ui32 << 18ui32,
		/*nicename("Node 83")*/ _unknown_arm_nodes_3_node_83 = 1ui32 << 19ui32,
		/*nicename("Node 84")*/ _unknown_arm_nodes_3_node_84 = 1ui32 << 20ui32,
		/*nicename("Node 85")*/ _unknown_arm_nodes_3_node_85 = 1ui32 << 21ui32,
		/*nicename("Node 86")*/ _unknown_arm_nodes_3_node_86 = 1ui32 << 22ui32,
		/*nicename("Node 87")*/ _unknown_arm_nodes_3_node_87 = 1ui32 << 23ui32,
		/*nicename("Node 88")*/ _unknown_arm_nodes_3_node_88 = 1ui32 << 24ui32,
		/*nicename("Node 89")*/ _unknown_arm_nodes_3_node_89 = 1ui32 << 25ui32,
		/*nicename("Node 90")*/ _unknown_arm_nodes_3_node_90 = 1ui32 << 26ui32,
		/*nicename("Node 91")*/ _unknown_arm_nodes_3_node_91 = 1ui32 << 27ui32,
		/*nicename("Node 92")*/ _unknown_arm_nodes_3_node_92 = 1ui32 << 28ui32,
		/*nicename("Node 93")*/ _unknown_arm_nodes_3_node_93 = 1ui32 << 29ui32,
		/*nicename("Node 94")*/ _unknown_arm_nodes_3_node_94 = 1ui32 << 30ui32,
		/*nicename("Node 95")*/ _unknown_arm_nodes_3_node_95 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 4") b_unknown_arm_nodes_4 : uint32_t /* bitfield */
	{
		/*nicename("Node 96")*/ _unknown_arm_nodes_4_node_96 = 1ui32 << 0ui32,
		/*nicename("Node 97")*/ _unknown_arm_nodes_4_node_97 = 1ui32 << 1ui32,
		/*nicename("Node 98")*/ _unknown_arm_nodes_4_node_98 = 1ui32 << 2ui32,
		/*nicename("Node 99")*/ _unknown_arm_nodes_4_node_99 = 1ui32 << 3ui32,
		/*nicename("Node 100")*/ _unknown_arm_nodes_4_node_100 = 1ui32 << 4ui32,
		/*nicename("Node 101")*/ _unknown_arm_nodes_4_node_101 = 1ui32 << 5ui32,
		/*nicename("Node 102")*/ _unknown_arm_nodes_4_node_102 = 1ui32 << 6ui32,
		/*nicename("Node 103")*/ _unknown_arm_nodes_4_node_103 = 1ui32 << 7ui32,
		/*nicename("Node 104")*/ _unknown_arm_nodes_4_node_104 = 1ui32 << 8ui32,
		/*nicename("Node 105")*/ _unknown_arm_nodes_4_node_105 = 1ui32 << 9ui32,
		/*nicename("Node 106")*/ _unknown_arm_nodes_4_node_106 = 1ui32 << 10ui32,
		/*nicename("Node 107")*/ _unknown_arm_nodes_4_node_107 = 1ui32 << 11ui32,
		/*nicename("Node 108")*/ _unknown_arm_nodes_4_node_108 = 1ui32 << 12ui32,
		/*nicename("Node 109")*/ _unknown_arm_nodes_4_node_109 = 1ui32 << 13ui32,
		/*nicename("Node 110")*/ _unknown_arm_nodes_4_node_110 = 1ui32 << 14ui32,
		/*nicename("Node 111")*/ _unknown_arm_nodes_4_node_111 = 1ui32 << 15ui32,
		/*nicename("Node 112")*/ _unknown_arm_nodes_4_node_112 = 1ui32 << 16ui32,
		/*nicename("Node 113")*/ _unknown_arm_nodes_4_node_113 = 1ui32 << 17ui32,
		/*nicename("Node 114")*/ _unknown_arm_nodes_4_node_114 = 1ui32 << 18ui32,
		/*nicename("Node 115")*/ _unknown_arm_nodes_4_node_115 = 1ui32 << 19ui32,
		/*nicename("Node 116")*/ _unknown_arm_nodes_4_node_116 = 1ui32 << 20ui32,
		/*nicename("Node 117")*/ _unknown_arm_nodes_4_node_117 = 1ui32 << 21ui32,
		/*nicename("Node 118")*/ _unknown_arm_nodes_4_node_118 = 1ui32 << 22ui32,
		/*nicename("Node 119")*/ _unknown_arm_nodes_4_node_119 = 1ui32 << 23ui32,
		/*nicename("Node 120")*/ _unknown_arm_nodes_4_node_120 = 1ui32 << 24ui32,
		/*nicename("Node 121")*/ _unknown_arm_nodes_4_node_121 = 1ui32 << 25ui32,
		/*nicename("Node 122")*/ _unknown_arm_nodes_4_node_122 = 1ui32 << 26ui32,
		/*nicename("Node 123")*/ _unknown_arm_nodes_4_node_123 = 1ui32 << 27ui32,
		/*nicename("Node 124")*/ _unknown_arm_nodes_4_node_124 = 1ui32 << 28ui32,
		/*nicename("Node 125")*/ _unknown_arm_nodes_4_node_125 = 1ui32 << 29ui32,
		/*nicename("Node 126")*/ _unknown_arm_nodes_4_node_126 = 1ui32 << 30ui32,
		/*nicename("Node 127")*/ _unknown_arm_nodes_4_node_127 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 5") b_unknown_arm_nodes_5 : uint32_t /* bitfield */
	{
		/*nicename("Node 128")*/ _unknown_arm_nodes_5_node_128 = 1ui32 << 0ui32,
		/*nicename("Node 129")*/ _unknown_arm_nodes_5_node_129 = 1ui32 << 1ui32,
		/*nicename("Node 130")*/ _unknown_arm_nodes_5_node_130 = 1ui32 << 2ui32,
		/*nicename("Node 131")*/ _unknown_arm_nodes_5_node_131 = 1ui32 << 3ui32,
		/*nicename("Node 132")*/ _unknown_arm_nodes_5_node_132 = 1ui32 << 4ui32,
		/*nicename("Node 133")*/ _unknown_arm_nodes_5_node_133 = 1ui32 << 5ui32,
		/*nicename("Node 134")*/ _unknown_arm_nodes_5_node_134 = 1ui32 << 6ui32,
		/*nicename("Node 135")*/ _unknown_arm_nodes_5_node_135 = 1ui32 << 7ui32,
		/*nicename("Node 136")*/ _unknown_arm_nodes_5_node_136 = 1ui32 << 8ui32,
		/*nicename("Node 137")*/ _unknown_arm_nodes_5_node_137 = 1ui32 << 9ui32,
		/*nicename("Node 138")*/ _unknown_arm_nodes_5_node_138 = 1ui32 << 10ui32,
		/*nicename("Node 139")*/ _unknown_arm_nodes_5_node_139 = 1ui32 << 11ui32,
		/*nicename("Node 140")*/ _unknown_arm_nodes_5_node_140 = 1ui32 << 12ui32,
		/*nicename("Node 141")*/ _unknown_arm_nodes_5_node_141 = 1ui32 << 13ui32,
		/*nicename("Node 142")*/ _unknown_arm_nodes_5_node_142 = 1ui32 << 14ui32,
		/*nicename("Node 143")*/ _unknown_arm_nodes_5_node_143 = 1ui32 << 15ui32,
		/*nicename("Node 144")*/ _unknown_arm_nodes_5_node_144 = 1ui32 << 16ui32,
		/*nicename("Node 145")*/ _unknown_arm_nodes_5_node_145 = 1ui32 << 17ui32,
		/*nicename("Node 146")*/ _unknown_arm_nodes_5_node_146 = 1ui32 << 18ui32,
		/*nicename("Node 147")*/ _unknown_arm_nodes_5_node_147 = 1ui32 << 19ui32,
		/*nicename("Node 148")*/ _unknown_arm_nodes_5_node_148 = 1ui32 << 20ui32,
		/*nicename("Node 149")*/ _unknown_arm_nodes_5_node_149 = 1ui32 << 21ui32,
		/*nicename("Node 150")*/ _unknown_arm_nodes_5_node_150 = 1ui32 << 22ui32,
		/*nicename("Node 151")*/ _unknown_arm_nodes_5_node_151 = 1ui32 << 23ui32,
		/*nicename("Node 152")*/ _unknown_arm_nodes_5_node_152 = 1ui32 << 24ui32,
		/*nicename("Node 153")*/ _unknown_arm_nodes_5_node_153 = 1ui32 << 25ui32,
		/*nicename("Node 154")*/ _unknown_arm_nodes_5_node_154 = 1ui32 << 26ui32,
		/*nicename("Node 155")*/ _unknown_arm_nodes_5_node_155 = 1ui32 << 27ui32,
		/*nicename("Node 156")*/ _unknown_arm_nodes_5_node_156 = 1ui32 << 28ui32,
		/*nicename("Node 157")*/ _unknown_arm_nodes_5_node_157 = 1ui32 << 29ui32,
		/*nicename("Node 158")*/ _unknown_arm_nodes_5_node_158 = 1ui32 << 30ui32,
		/*nicename("Node 159")*/ _unknown_arm_nodes_5_node_159 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 6") b_unknown_arm_nodes_6 : uint32_t /* bitfield */
	{
		/*nicename("Node 160")*/ _unknown_arm_nodes_6_node_160 = 1ui32 << 0ui32,
		/*nicename("Node 161")*/ _unknown_arm_nodes_6_node_161 = 1ui32 << 1ui32,
		/*nicename("Node 162")*/ _unknown_arm_nodes_6_node_162 = 1ui32 << 2ui32,
		/*nicename("Node 163")*/ _unknown_arm_nodes_6_node_163 = 1ui32 << 3ui32,
		/*nicename("Node 164")*/ _unknown_arm_nodes_6_node_164 = 1ui32 << 4ui32,
		/*nicename("Node 165")*/ _unknown_arm_nodes_6_node_165 = 1ui32 << 5ui32,
		/*nicename("Node 166")*/ _unknown_arm_nodes_6_node_166 = 1ui32 << 6ui32,
		/*nicename("Node 167")*/ _unknown_arm_nodes_6_node_167 = 1ui32 << 7ui32,
		/*nicename("Node 168")*/ _unknown_arm_nodes_6_node_168 = 1ui32 << 8ui32,
		/*nicename("Node 169")*/ _unknown_arm_nodes_6_node_169 = 1ui32 << 9ui32,
		/*nicename("Node 170")*/ _unknown_arm_nodes_6_node_170 = 1ui32 << 10ui32,
		/*nicename("Node 171")*/ _unknown_arm_nodes_6_node_171 = 1ui32 << 11ui32,
		/*nicename("Node 172")*/ _unknown_arm_nodes_6_node_172 = 1ui32 << 12ui32,
		/*nicename("Node 173")*/ _unknown_arm_nodes_6_node_173 = 1ui32 << 13ui32,
		/*nicename("Node 174")*/ _unknown_arm_nodes_6_node_174 = 1ui32 << 14ui32,
		/*nicename("Node 175")*/ _unknown_arm_nodes_6_node_175 = 1ui32 << 15ui32,
		/*nicename("Node 176")*/ _unknown_arm_nodes_6_node_176 = 1ui32 << 16ui32,
		/*nicename("Node 177")*/ _unknown_arm_nodes_6_node_177 = 1ui32 << 17ui32,
		/*nicename("Node 178")*/ _unknown_arm_nodes_6_node_178 = 1ui32 << 18ui32,
		/*nicename("Node 179")*/ _unknown_arm_nodes_6_node_179 = 1ui32 << 19ui32,
		/*nicename("Node 180")*/ _unknown_arm_nodes_6_node_180 = 1ui32 << 20ui32,
		/*nicename("Node 181")*/ _unknown_arm_nodes_6_node_181 = 1ui32 << 21ui32,
		/*nicename("Node 182")*/ _unknown_arm_nodes_6_node_182 = 1ui32 << 22ui32,
		/*nicename("Node 183")*/ _unknown_arm_nodes_6_node_183 = 1ui32 << 23ui32,
		/*nicename("Node 184")*/ _unknown_arm_nodes_6_node_184 = 1ui32 << 24ui32,
		/*nicename("Node 185")*/ _unknown_arm_nodes_6_node_185 = 1ui32 << 25ui32,
		/*nicename("Node 186")*/ _unknown_arm_nodes_6_node_186 = 1ui32 << 26ui32,
		/*nicename("Node 187")*/ _unknown_arm_nodes_6_node_187 = 1ui32 << 27ui32,
		/*nicename("Node 188")*/ _unknown_arm_nodes_6_node_188 = 1ui32 << 28ui32,
		/*nicename("Node 189")*/ _unknown_arm_nodes_6_node_189 = 1ui32 << 29ui32,
		/*nicename("Node 190")*/ _unknown_arm_nodes_6_node_190 = 1ui32 << 30ui32,
		/*nicename("Node 191")*/ _unknown_arm_nodes_6_node_191 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 7") b_unknown_arm_nodes_7 : uint32_t /* bitfield */
	{
		/*nicename("Node 192")*/ _unknown_arm_nodes_7_node_192 = 1ui32 << 0ui32,
		/*nicename("Node 193")*/ _unknown_arm_nodes_7_node_193 = 1ui32 << 1ui32,
		/*nicename("Node 194")*/ _unknown_arm_nodes_7_node_194 = 1ui32 << 2ui32,
		/*nicename("Node 195")*/ _unknown_arm_nodes_7_node_195 = 1ui32 << 3ui32,
		/*nicename("Node 196")*/ _unknown_arm_nodes_7_node_196 = 1ui32 << 4ui32,
		/*nicename("Node 197")*/ _unknown_arm_nodes_7_node_197 = 1ui32 << 5ui32,
		/*nicename("Node 198")*/ _unknown_arm_nodes_7_node_198 = 1ui32 << 6ui32,
		/*nicename("Node 199")*/ _unknown_arm_nodes_7_node_199 = 1ui32 << 7ui32,
		/*nicename("Node 200")*/ _unknown_arm_nodes_7_node_200 = 1ui32 << 8ui32,
		/*nicename("Node 201")*/ _unknown_arm_nodes_7_node_201 = 1ui32 << 9ui32,
		/*nicename("Node 202")*/ _unknown_arm_nodes_7_node_202 = 1ui32 << 10ui32,
		/*nicename("Node 203")*/ _unknown_arm_nodes_7_node_203 = 1ui32 << 11ui32,
		/*nicename("Node 204")*/ _unknown_arm_nodes_7_node_204 = 1ui32 << 12ui32,
		/*nicename("Node 205")*/ _unknown_arm_nodes_7_node_205 = 1ui32 << 13ui32,
		/*nicename("Node 206")*/ _unknown_arm_nodes_7_node_206 = 1ui32 << 14ui32,
		/*nicename("Node 207")*/ _unknown_arm_nodes_7_node_207 = 1ui32 << 15ui32,
		/*nicename("Node 208")*/ _unknown_arm_nodes_7_node_208 = 1ui32 << 16ui32,
		/*nicename("Node 209")*/ _unknown_arm_nodes_7_node_209 = 1ui32 << 17ui32,
		/*nicename("Node 210")*/ _unknown_arm_nodes_7_node_210 = 1ui32 << 18ui32,
		/*nicename("Node 211")*/ _unknown_arm_nodes_7_node_211 = 1ui32 << 19ui32,
		/*nicename("Node 212")*/ _unknown_arm_nodes_7_node_212 = 1ui32 << 20ui32,
		/*nicename("Node 213")*/ _unknown_arm_nodes_7_node_213 = 1ui32 << 21ui32,
		/*nicename("Node 214")*/ _unknown_arm_nodes_7_node_214 = 1ui32 << 22ui32,
		/*nicename("Node 215")*/ _unknown_arm_nodes_7_node_215 = 1ui32 << 23ui32,
		/*nicename("Node 216")*/ _unknown_arm_nodes_7_node_216 = 1ui32 << 24ui32,
		/*nicename("Node 217")*/ _unknown_arm_nodes_7_node_217 = 1ui32 << 25ui32,
		/*nicename("Node 218")*/ _unknown_arm_nodes_7_node_218 = 1ui32 << 26ui32,
		/*nicename("Node 219")*/ _unknown_arm_nodes_7_node_219 = 1ui32 << 27ui32,
		/*nicename("Node 220")*/ _unknown_arm_nodes_7_node_220 = 1ui32 << 28ui32,
		/*nicename("Node 221")*/ _unknown_arm_nodes_7_node_221 = 1ui32 << 29ui32,
		/*nicename("Node 222")*/ _unknown_arm_nodes_7_node_222 = 1ui32 << 30ui32,
		/*nicename("Node 223")*/ _unknown_arm_nodes_7_node_223 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Arm Nodes 8") b_unknown_arm_nodes_8 : uint32_t /* bitfield */
	{
		/*nicename("Node 224")*/ _unknown_arm_nodes_8_node_224 = 1ui32 << 0ui32,
		/*nicename("Node 225")*/ _unknown_arm_nodes_8_node_225 = 1ui32 << 1ui32,
		/*nicename("Node 226")*/ _unknown_arm_nodes_8_node_226 = 1ui32 << 2ui32,
		/*nicename("Node 227")*/ _unknown_arm_nodes_8_node_227 = 1ui32 << 3ui32,
		/*nicename("Node 228")*/ _unknown_arm_nodes_8_node_228 = 1ui32 << 4ui32,
		/*nicename("Node 229")*/ _unknown_arm_nodes_8_node_229 = 1ui32 << 5ui32,
		/*nicename("Node 230")*/ _unknown_arm_nodes_8_node_230 = 1ui32 << 6ui32,
		/*nicename("Node 231")*/ _unknown_arm_nodes_8_node_231 = 1ui32 << 7ui32,
		/*nicename("Node 232")*/ _unknown_arm_nodes_8_node_232 = 1ui32 << 8ui32,
		/*nicename("Node 233")*/ _unknown_arm_nodes_8_node_233 = 1ui32 << 9ui32,
		/*nicename("Node 234")*/ _unknown_arm_nodes_8_node_234 = 1ui32 << 10ui32,
		/*nicename("Node 235")*/ _unknown_arm_nodes_8_node_235 = 1ui32 << 11ui32,
		/*nicename("Node 236")*/ _unknown_arm_nodes_8_node_236 = 1ui32 << 12ui32,
		/*nicename("Node 237")*/ _unknown_arm_nodes_8_node_237 = 1ui32 << 13ui32,
		/*nicename("Node 238")*/ _unknown_arm_nodes_8_node_238 = 1ui32 << 14ui32,
		/*nicename("Node 239")*/ _unknown_arm_nodes_8_node_239 = 1ui32 << 15ui32,
		/*nicename("Node 240")*/ _unknown_arm_nodes_8_node_240 = 1ui32 << 16ui32,
		/*nicename("Node 241")*/ _unknown_arm_nodes_8_node_241 = 1ui32 << 17ui32,
		/*nicename("Node 242")*/ _unknown_arm_nodes_8_node_242 = 1ui32 << 18ui32,
		/*nicename("Node 243")*/ _unknown_arm_nodes_8_node_243 = 1ui32 << 19ui32,
		/*nicename("Node 244")*/ _unknown_arm_nodes_8_node_244 = 1ui32 << 20ui32,
		/*nicename("Node 245")*/ _unknown_arm_nodes_8_node_245 = 1ui32 << 21ui32,
		/*nicename("Node 246")*/ _unknown_arm_nodes_8_node_246 = 1ui32 << 22ui32,
		/*nicename("Node 247")*/ _unknown_arm_nodes_8_node_247 = 1ui32 << 23ui32,
		/*nicename("Node 248")*/ _unknown_arm_nodes_8_node_248 = 1ui32 << 24ui32,
		/*nicename("Node 249")*/ _unknown_arm_nodes_8_node_249 = 1ui32 << 25ui32,
		/*nicename("Node 250")*/ _unknown_arm_nodes_8_node_250 = 1ui32 << 26ui32,
		/*nicename("Node 251")*/ _unknown_arm_nodes_8_node_251 = 1ui32 << 27ui32,
		/*nicename("Node 252")*/ _unknown_arm_nodes_8_node_252 = 1ui32 << 28ui32,
		/*nicename("Node 253")*/ _unknown_arm_nodes_8_node_253 = 1ui32 << 29ui32,
		/*nicename("Node 254")*/ _unknown_arm_nodes_8_node_254 = 1ui32 << 30ui32,
		/*nicename("Node 255")*/ _unknown_arm_nodes_8_node_255 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 1") b_unknown_nodes_1 : uint32_t /* bitfield */
	{
		/*nicename("Node 0")*/ _unknown_nodes_1_node_0 = 1ui32 << 0ui32,
		/*nicename("Node 1")*/ _unknown_nodes_1_node_1 = 1ui32 << 1ui32,
		/*nicename("Node 2")*/ _unknown_nodes_1_node_2 = 1ui32 << 2ui32,
		/*nicename("Node 3")*/ _unknown_nodes_1_node_3 = 1ui32 << 3ui32,
		/*nicename("Node 4")*/ _unknown_nodes_1_node_4 = 1ui32 << 4ui32,
		/*nicename("Node 5")*/ _unknown_nodes_1_node_5 = 1ui32 << 5ui32,
		/*nicename("Node 6")*/ _unknown_nodes_1_node_6 = 1ui32 << 6ui32,
		/*nicename("Node 7")*/ _unknown_nodes_1_node_7 = 1ui32 << 7ui32,
		/*nicename("Node 8")*/ _unknown_nodes_1_node_8 = 1ui32 << 8ui32,
		/*nicename("Node 9")*/ _unknown_nodes_1_node_9 = 1ui32 << 9ui32,
		/*nicename("Node 10")*/ _unknown_nodes_1_node_10 = 1ui32 << 10ui32,
		/*nicename("Node 11")*/ _unknown_nodes_1_node_11 = 1ui32 << 11ui32,
		/*nicename("Node 12")*/ _unknown_nodes_1_node_12 = 1ui32 << 12ui32,
		/*nicename("Node 13")*/ _unknown_nodes_1_node_13 = 1ui32 << 13ui32,
		/*nicename("Node 14")*/ _unknown_nodes_1_node_14 = 1ui32 << 14ui32,
		/*nicename("Node 15")*/ _unknown_nodes_1_node_15 = 1ui32 << 15ui32,
		/*nicename("Node 16")*/ _unknown_nodes_1_node_16 = 1ui32 << 16ui32,
		/*nicename("Node 17")*/ _unknown_nodes_1_node_17 = 1ui32 << 17ui32,
		/*nicename("Node 18")*/ _unknown_nodes_1_node_18 = 1ui32 << 18ui32,
		/*nicename("Node 19")*/ _unknown_nodes_1_node_19 = 1ui32 << 19ui32,
		/*nicename("Node 20")*/ _unknown_nodes_1_node_20 = 1ui32 << 20ui32,
		/*nicename("Node 21")*/ _unknown_nodes_1_node_21 = 1ui32 << 21ui32,
		/*nicename("Node 22")*/ _unknown_nodes_1_node_22 = 1ui32 << 22ui32,
		/*nicename("Node 23")*/ _unknown_nodes_1_node_23 = 1ui32 << 23ui32,
		/*nicename("Node 24")*/ _unknown_nodes_1_node_24 = 1ui32 << 24ui32,
		/*nicename("Node 25")*/ _unknown_nodes_1_node_25 = 1ui32 << 25ui32,
		/*nicename("Node 26")*/ _unknown_nodes_1_node_26 = 1ui32 << 26ui32,
		/*nicename("Node 27")*/ _unknown_nodes_1_node_27 = 1ui32 << 27ui32,
		/*nicename("Node 28")*/ _unknown_nodes_1_node_28 = 1ui32 << 28ui32,
		/*nicename("Node 29")*/ _unknown_nodes_1_node_29 = 1ui32 << 29ui32,
		/*nicename("Node 30")*/ _unknown_nodes_1_node_30 = 1ui32 << 30ui32,
		/*nicename("Node 31")*/ _unknown_nodes_1_node_31 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 2") b_unknown_nodes_2 : uint32_t /* bitfield */
	{
		/*nicename("Node 32")*/ _unknown_nodes_2_node_32 = 1ui32 << 0ui32,
		/*nicename("Node 33")*/ _unknown_nodes_2_node_33 = 1ui32 << 1ui32,
		/*nicename("Node 34")*/ _unknown_nodes_2_node_34 = 1ui32 << 2ui32,
		/*nicename("Node 35")*/ _unknown_nodes_2_node_35 = 1ui32 << 3ui32,
		/*nicename("Node 36")*/ _unknown_nodes_2_node_36 = 1ui32 << 4ui32,
		/*nicename("Node 37")*/ _unknown_nodes_2_node_37 = 1ui32 << 5ui32,
		/*nicename("Node 38")*/ _unknown_nodes_2_node_38 = 1ui32 << 6ui32,
		/*nicename("Node 39")*/ _unknown_nodes_2_node_39 = 1ui32 << 7ui32,
		/*nicename("Node 40")*/ _unknown_nodes_2_node_40 = 1ui32 << 8ui32,
		/*nicename("Node 41")*/ _unknown_nodes_2_node_41 = 1ui32 << 9ui32,
		/*nicename("Node 42")*/ _unknown_nodes_2_node_42 = 1ui32 << 10ui32,
		/*nicename("Node 43")*/ _unknown_nodes_2_node_43 = 1ui32 << 11ui32,
		/*nicename("Node 44")*/ _unknown_nodes_2_node_44 = 1ui32 << 12ui32,
		/*nicename("Node 45")*/ _unknown_nodes_2_node_45 = 1ui32 << 13ui32,
		/*nicename("Node 46")*/ _unknown_nodes_2_node_46 = 1ui32 << 14ui32,
		/*nicename("Node 47")*/ _unknown_nodes_2_node_47 = 1ui32 << 15ui32,
		/*nicename("Node 48")*/ _unknown_nodes_2_node_48 = 1ui32 << 16ui32,
		/*nicename("Node 49")*/ _unknown_nodes_2_node_49 = 1ui32 << 17ui32,
		/*nicename("Node 50")*/ _unknown_nodes_2_node_50 = 1ui32 << 18ui32,
		/*nicename("Node 51")*/ _unknown_nodes_2_node_51 = 1ui32 << 19ui32,
		/*nicename("Node 52")*/ _unknown_nodes_2_node_52 = 1ui32 << 20ui32,
		/*nicename("Node 53")*/ _unknown_nodes_2_node_53 = 1ui32 << 21ui32,
		/*nicename("Node 54")*/ _unknown_nodes_2_node_54 = 1ui32 << 22ui32,
		/*nicename("Node 55")*/ _unknown_nodes_2_node_55 = 1ui32 << 23ui32,
		/*nicename("Node 56")*/ _unknown_nodes_2_node_56 = 1ui32 << 24ui32,
		/*nicename("Node 57")*/ _unknown_nodes_2_node_57 = 1ui32 << 25ui32,
		/*nicename("Node 58")*/ _unknown_nodes_2_node_58 = 1ui32 << 26ui32,
		/*nicename("Node 59")*/ _unknown_nodes_2_node_59 = 1ui32 << 27ui32,
		/*nicename("Node 60")*/ _unknown_nodes_2_node_60 = 1ui32 << 28ui32,
		/*nicename("Node 61")*/ _unknown_nodes_2_node_61 = 1ui32 << 29ui32,
		/*nicename("Node 62")*/ _unknown_nodes_2_node_62 = 1ui32 << 30ui32,
		/*nicename("Node 63")*/ _unknown_nodes_2_node_63 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 3") b_unknown_nodes_3 : uint32_t /* bitfield */
	{
		/*nicename("Node 64")*/ _unknown_nodes_3_node_64 = 1ui32 << 0ui32,
		/*nicename("Node 65")*/ _unknown_nodes_3_node_65 = 1ui32 << 1ui32,
		/*nicename("Node 66")*/ _unknown_nodes_3_node_66 = 1ui32 << 2ui32,
		/*nicename("Node 67")*/ _unknown_nodes_3_node_67 = 1ui32 << 3ui32,
		/*nicename("Node 68")*/ _unknown_nodes_3_node_68 = 1ui32 << 4ui32,
		/*nicename("Node 69")*/ _unknown_nodes_3_node_69 = 1ui32 << 5ui32,
		/*nicename("Node 70")*/ _unknown_nodes_3_node_70 = 1ui32 << 6ui32,
		/*nicename("Node 71")*/ _unknown_nodes_3_node_71 = 1ui32 << 7ui32,
		/*nicename("Node 72")*/ _unknown_nodes_3_node_72 = 1ui32 << 8ui32,
		/*nicename("Node 73")*/ _unknown_nodes_3_node_73 = 1ui32 << 9ui32,
		/*nicename("Node 74")*/ _unknown_nodes_3_node_74 = 1ui32 << 10ui32,
		/*nicename("Node 75")*/ _unknown_nodes_3_node_75 = 1ui32 << 11ui32,
		/*nicename("Node 76")*/ _unknown_nodes_3_node_76 = 1ui32 << 12ui32,
		/*nicename("Node 77")*/ _unknown_nodes_3_node_77 = 1ui32 << 13ui32,
		/*nicename("Node 78")*/ _unknown_nodes_3_node_78 = 1ui32 << 14ui32,
		/*nicename("Node 79")*/ _unknown_nodes_3_node_79 = 1ui32 << 15ui32,
		/*nicename("Node 80")*/ _unknown_nodes_3_node_80 = 1ui32 << 16ui32,
		/*nicename("Node 81")*/ _unknown_nodes_3_node_81 = 1ui32 << 17ui32,
		/*nicename("Node 82")*/ _unknown_nodes_3_node_82 = 1ui32 << 18ui32,
		/*nicename("Node 83")*/ _unknown_nodes_3_node_83 = 1ui32 << 19ui32,
		/*nicename("Node 84")*/ _unknown_nodes_3_node_84 = 1ui32 << 20ui32,
		/*nicename("Node 85")*/ _unknown_nodes_3_node_85 = 1ui32 << 21ui32,
		/*nicename("Node 86")*/ _unknown_nodes_3_node_86 = 1ui32 << 22ui32,
		/*nicename("Node 87")*/ _unknown_nodes_3_node_87 = 1ui32 << 23ui32,
		/*nicename("Node 88")*/ _unknown_nodes_3_node_88 = 1ui32 << 24ui32,
		/*nicename("Node 89")*/ _unknown_nodes_3_node_89 = 1ui32 << 25ui32,
		/*nicename("Node 90")*/ _unknown_nodes_3_node_90 = 1ui32 << 26ui32,
		/*nicename("Node 91")*/ _unknown_nodes_3_node_91 = 1ui32 << 27ui32,
		/*nicename("Node 92")*/ _unknown_nodes_3_node_92 = 1ui32 << 28ui32,
		/*nicename("Node 93")*/ _unknown_nodes_3_node_93 = 1ui32 << 29ui32,
		/*nicename("Node 94")*/ _unknown_nodes_3_node_94 = 1ui32 << 30ui32,
		/*nicename("Node 95")*/ _unknown_nodes_3_node_95 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 4") b_unknown_nodes_4 : uint32_t /* bitfield */
	{
		/*nicename("Node 96")*/ _unknown_nodes_4_node_96 = 1ui32 << 0ui32,
		/*nicename("Node 97")*/ _unknown_nodes_4_node_97 = 1ui32 << 1ui32,
		/*nicename("Node 98")*/ _unknown_nodes_4_node_98 = 1ui32 << 2ui32,
		/*nicename("Node 99")*/ _unknown_nodes_4_node_99 = 1ui32 << 3ui32,
		/*nicename("Node 100")*/ _unknown_nodes_4_node_100 = 1ui32 << 4ui32,
		/*nicename("Node 101")*/ _unknown_nodes_4_node_101 = 1ui32 << 5ui32,
		/*nicename("Node 102")*/ _unknown_nodes_4_node_102 = 1ui32 << 6ui32,
		/*nicename("Node 103")*/ _unknown_nodes_4_node_103 = 1ui32 << 7ui32,
		/*nicename("Node 104")*/ _unknown_nodes_4_node_104 = 1ui32 << 8ui32,
		/*nicename("Node 105")*/ _unknown_nodes_4_node_105 = 1ui32 << 9ui32,
		/*nicename("Node 106")*/ _unknown_nodes_4_node_106 = 1ui32 << 10ui32,
		/*nicename("Node 107")*/ _unknown_nodes_4_node_107 = 1ui32 << 11ui32,
		/*nicename("Node 108")*/ _unknown_nodes_4_node_108 = 1ui32 << 12ui32,
		/*nicename("Node 109")*/ _unknown_nodes_4_node_109 = 1ui32 << 13ui32,
		/*nicename("Node 110")*/ _unknown_nodes_4_node_110 = 1ui32 << 14ui32,
		/*nicename("Node 111")*/ _unknown_nodes_4_node_111 = 1ui32 << 15ui32,
		/*nicename("Node 112")*/ _unknown_nodes_4_node_112 = 1ui32 << 16ui32,
		/*nicename("Node 113")*/ _unknown_nodes_4_node_113 = 1ui32 << 17ui32,
		/*nicename("Node 114")*/ _unknown_nodes_4_node_114 = 1ui32 << 18ui32,
		/*nicename("Node 115")*/ _unknown_nodes_4_node_115 = 1ui32 << 19ui32,
		/*nicename("Node 116")*/ _unknown_nodes_4_node_116 = 1ui32 << 20ui32,
		/*nicename("Node 117")*/ _unknown_nodes_4_node_117 = 1ui32 << 21ui32,
		/*nicename("Node 118")*/ _unknown_nodes_4_node_118 = 1ui32 << 22ui32,
		/*nicename("Node 119")*/ _unknown_nodes_4_node_119 = 1ui32 << 23ui32,
		/*nicename("Node 120")*/ _unknown_nodes_4_node_120 = 1ui32 << 24ui32,
		/*nicename("Node 121")*/ _unknown_nodes_4_node_121 = 1ui32 << 25ui32,
		/*nicename("Node 122")*/ _unknown_nodes_4_node_122 = 1ui32 << 26ui32,
		/*nicename("Node 123")*/ _unknown_nodes_4_node_123 = 1ui32 << 27ui32,
		/*nicename("Node 124")*/ _unknown_nodes_4_node_124 = 1ui32 << 28ui32,
		/*nicename("Node 125")*/ _unknown_nodes_4_node_125 = 1ui32 << 29ui32,
		/*nicename("Node 126")*/ _unknown_nodes_4_node_126 = 1ui32 << 30ui32,
		/*nicename("Node 127")*/ _unknown_nodes_4_node_127 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 5") b_unknown_nodes_5 : uint32_t /* bitfield */
	{
		/*nicename("Node 128")*/ _unknown_nodes_5_node_128 = 1ui32 << 0ui32,
		/*nicename("Node 129")*/ _unknown_nodes_5_node_129 = 1ui32 << 1ui32,
		/*nicename("Node 130")*/ _unknown_nodes_5_node_130 = 1ui32 << 2ui32,
		/*nicename("Node 131")*/ _unknown_nodes_5_node_131 = 1ui32 << 3ui32,
		/*nicename("Node 132")*/ _unknown_nodes_5_node_132 = 1ui32 << 4ui32,
		/*nicename("Node 133")*/ _unknown_nodes_5_node_133 = 1ui32 << 5ui32,
		/*nicename("Node 134")*/ _unknown_nodes_5_node_134 = 1ui32 << 6ui32,
		/*nicename("Node 135")*/ _unknown_nodes_5_node_135 = 1ui32 << 7ui32,
		/*nicename("Node 136")*/ _unknown_nodes_5_node_136 = 1ui32 << 8ui32,
		/*nicename("Node 137")*/ _unknown_nodes_5_node_137 = 1ui32 << 9ui32,
		/*nicename("Node 138")*/ _unknown_nodes_5_node_138 = 1ui32 << 10ui32,
		/*nicename("Node 139")*/ _unknown_nodes_5_node_139 = 1ui32 << 11ui32,
		/*nicename("Node 140")*/ _unknown_nodes_5_node_140 = 1ui32 << 12ui32,
		/*nicename("Node 141")*/ _unknown_nodes_5_node_141 = 1ui32 << 13ui32,
		/*nicename("Node 142")*/ _unknown_nodes_5_node_142 = 1ui32 << 14ui32,
		/*nicename("Node 143")*/ _unknown_nodes_5_node_143 = 1ui32 << 15ui32,
		/*nicename("Node 144")*/ _unknown_nodes_5_node_144 = 1ui32 << 16ui32,
		/*nicename("Node 145")*/ _unknown_nodes_5_node_145 = 1ui32 << 17ui32,
		/*nicename("Node 146")*/ _unknown_nodes_5_node_146 = 1ui32 << 18ui32,
		/*nicename("Node 147")*/ _unknown_nodes_5_node_147 = 1ui32 << 19ui32,
		/*nicename("Node 148")*/ _unknown_nodes_5_node_148 = 1ui32 << 20ui32,
		/*nicename("Node 149")*/ _unknown_nodes_5_node_149 = 1ui32 << 21ui32,
		/*nicename("Node 150")*/ _unknown_nodes_5_node_150 = 1ui32 << 22ui32,
		/*nicename("Node 151")*/ _unknown_nodes_5_node_151 = 1ui32 << 23ui32,
		/*nicename("Node 152")*/ _unknown_nodes_5_node_152 = 1ui32 << 24ui32,
		/*nicename("Node 153")*/ _unknown_nodes_5_node_153 = 1ui32 << 25ui32,
		/*nicename("Node 154")*/ _unknown_nodes_5_node_154 = 1ui32 << 26ui32,
		/*nicename("Node 155")*/ _unknown_nodes_5_node_155 = 1ui32 << 27ui32,
		/*nicename("Node 156")*/ _unknown_nodes_5_node_156 = 1ui32 << 28ui32,
		/*nicename("Node 157")*/ _unknown_nodes_5_node_157 = 1ui32 << 29ui32,
		/*nicename("Node 158")*/ _unknown_nodes_5_node_158 = 1ui32 << 30ui32,
		/*nicename("Node 159")*/ _unknown_nodes_5_node_159 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 6") b_unknown_nodes_6 : uint32_t /* bitfield */
	{
		/*nicename("Node 160")*/ _unknown_nodes_6_node_160 = 1ui32 << 0ui32,
		/*nicename("Node 161")*/ _unknown_nodes_6_node_161 = 1ui32 << 1ui32,
		/*nicename("Node 162")*/ _unknown_nodes_6_node_162 = 1ui32 << 2ui32,
		/*nicename("Node 163")*/ _unknown_nodes_6_node_163 = 1ui32 << 3ui32,
		/*nicename("Node 164")*/ _unknown_nodes_6_node_164 = 1ui32 << 4ui32,
		/*nicename("Node 165")*/ _unknown_nodes_6_node_165 = 1ui32 << 5ui32,
		/*nicename("Node 166")*/ _unknown_nodes_6_node_166 = 1ui32 << 6ui32,
		/*nicename("Node 167")*/ _unknown_nodes_6_node_167 = 1ui32 << 7ui32,
		/*nicename("Node 168")*/ _unknown_nodes_6_node_168 = 1ui32 << 8ui32,
		/*nicename("Node 169")*/ _unknown_nodes_6_node_169 = 1ui32 << 9ui32,
		/*nicename("Node 170")*/ _unknown_nodes_6_node_170 = 1ui32 << 10ui32,
		/*nicename("Node 171")*/ _unknown_nodes_6_node_171 = 1ui32 << 11ui32,
		/*nicename("Node 172")*/ _unknown_nodes_6_node_172 = 1ui32 << 12ui32,
		/*nicename("Node 173")*/ _unknown_nodes_6_node_173 = 1ui32 << 13ui32,
		/*nicename("Node 174")*/ _unknown_nodes_6_node_174 = 1ui32 << 14ui32,
		/*nicename("Node 175")*/ _unknown_nodes_6_node_175 = 1ui32 << 15ui32,
		/*nicename("Node 176")*/ _unknown_nodes_6_node_176 = 1ui32 << 16ui32,
		/*nicename("Node 177")*/ _unknown_nodes_6_node_177 = 1ui32 << 17ui32,
		/*nicename("Node 178")*/ _unknown_nodes_6_node_178 = 1ui32 << 18ui32,
		/*nicename("Node 179")*/ _unknown_nodes_6_node_179 = 1ui32 << 19ui32,
		/*nicename("Node 180")*/ _unknown_nodes_6_node_180 = 1ui32 << 20ui32,
		/*nicename("Node 181")*/ _unknown_nodes_6_node_181 = 1ui32 << 21ui32,
		/*nicename("Node 182")*/ _unknown_nodes_6_node_182 = 1ui32 << 22ui32,
		/*nicename("Node 183")*/ _unknown_nodes_6_node_183 = 1ui32 << 23ui32,
		/*nicename("Node 184")*/ _unknown_nodes_6_node_184 = 1ui32 << 24ui32,
		/*nicename("Node 185")*/ _unknown_nodes_6_node_185 = 1ui32 << 25ui32,
		/*nicename("Node 186")*/ _unknown_nodes_6_node_186 = 1ui32 << 26ui32,
		/*nicename("Node 187")*/ _unknown_nodes_6_node_187 = 1ui32 << 27ui32,
		/*nicename("Node 188")*/ _unknown_nodes_6_node_188 = 1ui32 << 28ui32,
		/*nicename("Node 189")*/ _unknown_nodes_6_node_189 = 1ui32 << 29ui32,
		/*nicename("Node 190")*/ _unknown_nodes_6_node_190 = 1ui32 << 30ui32,
		/*nicename("Node 191")*/ _unknown_nodes_6_node_191 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 7") b_unknown_nodes_7 : uint32_t /* bitfield */
	{
		/*nicename("Node 192")*/ _unknown_nodes_7_node_192 = 1ui32 << 0ui32,
		/*nicename("Node 193")*/ _unknown_nodes_7_node_193 = 1ui32 << 1ui32,
		/*nicename("Node 194")*/ _unknown_nodes_7_node_194 = 1ui32 << 2ui32,
		/*nicename("Node 195")*/ _unknown_nodes_7_node_195 = 1ui32 << 3ui32,
		/*nicename("Node 196")*/ _unknown_nodes_7_node_196 = 1ui32 << 4ui32,
		/*nicename("Node 197")*/ _unknown_nodes_7_node_197 = 1ui32 << 5ui32,
		/*nicename("Node 198")*/ _unknown_nodes_7_node_198 = 1ui32 << 6ui32,
		/*nicename("Node 199")*/ _unknown_nodes_7_node_199 = 1ui32 << 7ui32,
		/*nicename("Node 200")*/ _unknown_nodes_7_node_200 = 1ui32 << 8ui32,
		/*nicename("Node 201")*/ _unknown_nodes_7_node_201 = 1ui32 << 9ui32,
		/*nicename("Node 202")*/ _unknown_nodes_7_node_202 = 1ui32 << 10ui32,
		/*nicename("Node 203")*/ _unknown_nodes_7_node_203 = 1ui32 << 11ui32,
		/*nicename("Node 204")*/ _unknown_nodes_7_node_204 = 1ui32 << 12ui32,
		/*nicename("Node 205")*/ _unknown_nodes_7_node_205 = 1ui32 << 13ui32,
		/*nicename("Node 206")*/ _unknown_nodes_7_node_206 = 1ui32 << 14ui32,
		/*nicename("Node 207")*/ _unknown_nodes_7_node_207 = 1ui32 << 15ui32,
		/*nicename("Node 208")*/ _unknown_nodes_7_node_208 = 1ui32 << 16ui32,
		/*nicename("Node 209")*/ _unknown_nodes_7_node_209 = 1ui32 << 17ui32,
		/*nicename("Node 210")*/ _unknown_nodes_7_node_210 = 1ui32 << 18ui32,
		/*nicename("Node 211")*/ _unknown_nodes_7_node_211 = 1ui32 << 19ui32,
		/*nicename("Node 212")*/ _unknown_nodes_7_node_212 = 1ui32 << 20ui32,
		/*nicename("Node 213")*/ _unknown_nodes_7_node_213 = 1ui32 << 21ui32,
		/*nicename("Node 214")*/ _unknown_nodes_7_node_214 = 1ui32 << 22ui32,
		/*nicename("Node 215")*/ _unknown_nodes_7_node_215 = 1ui32 << 23ui32,
		/*nicename("Node 216")*/ _unknown_nodes_7_node_216 = 1ui32 << 24ui32,
		/*nicename("Node 217")*/ _unknown_nodes_7_node_217 = 1ui32 << 25ui32,
		/*nicename("Node 218")*/ _unknown_nodes_7_node_218 = 1ui32 << 26ui32,
		/*nicename("Node 219")*/ _unknown_nodes_7_node_219 = 1ui32 << 27ui32,
		/*nicename("Node 220")*/ _unknown_nodes_7_node_220 = 1ui32 << 28ui32,
		/*nicename("Node 221")*/ _unknown_nodes_7_node_221 = 1ui32 << 29ui32,
		/*nicename("Node 222")*/ _unknown_nodes_7_node_222 = 1ui32 << 30ui32,
		/*nicename("Node 223")*/ _unknown_nodes_7_node_223 = 1ui32 << 31ui32,
	};

	enum nicename("Unknown Nodes 8") b_unknown_nodes_8 : uint32_t /* bitfield */
	{
		/*nicename("Node 224")*/ _unknown_nodes_8_node_224 = 1ui32 << 0ui32,
		/*nicename("Node 225")*/ _unknown_nodes_8_node_225 = 1ui32 << 1ui32,
		/*nicename("Node 226")*/ _unknown_nodes_8_node_226 = 1ui32 << 2ui32,
		/*nicename("Node 227")*/ _unknown_nodes_8_node_227 = 1ui32 << 3ui32,
		/*nicename("Node 228")*/ _unknown_nodes_8_node_228 = 1ui32 << 4ui32,
		/*nicename("Node 229")*/ _unknown_nodes_8_node_229 = 1ui32 << 5ui32,
		/*nicename("Node 230")*/ _unknown_nodes_8_node_230 = 1ui32 << 6ui32,
		/*nicename("Node 231")*/ _unknown_nodes_8_node_231 = 1ui32 << 7ui32,
		/*nicename("Node 232")*/ _unknown_nodes_8_node_232 = 1ui32 << 8ui32,
		/*nicename("Node 233")*/ _unknown_nodes_8_node_233 = 1ui32 << 9ui32,
		/*nicename("Node 234")*/ _unknown_nodes_8_node_234 = 1ui32 << 10ui32,
		/*nicename("Node 235")*/ _unknown_nodes_8_node_235 = 1ui32 << 11ui32,
		/*nicename("Node 236")*/ _unknown_nodes_8_node_236 = 1ui32 << 12ui32,
		/*nicename("Node 237")*/ _unknown_nodes_8_node_237 = 1ui32 << 13ui32,
		/*nicename("Node 238")*/ _unknown_nodes_8_node_238 = 1ui32 << 14ui32,
		/*nicename("Node 239")*/ _unknown_nodes_8_node_239 = 1ui32 << 15ui32,
		/*nicename("Node 240")*/ _unknown_nodes_8_node_240 = 1ui32 << 16ui32,
		/*nicename("Node 241")*/ _unknown_nodes_8_node_241 = 1ui32 << 17ui32,
		/*nicename("Node 242")*/ _unknown_nodes_8_node_242 = 1ui32 << 18ui32,
		/*nicename("Node 243")*/ _unknown_nodes_8_node_243 = 1ui32 << 19ui32,
		/*nicename("Node 244")*/ _unknown_nodes_8_node_244 = 1ui32 << 20ui32,
		/*nicename("Node 245")*/ _unknown_nodes_8_node_245 = 1ui32 << 21ui32,
		/*nicename("Node 246")*/ _unknown_nodes_8_node_246 = 1ui32 << 22ui32,
		/*nicename("Node 247")*/ _unknown_nodes_8_node_247 = 1ui32 << 23ui32,
		/*nicename("Node 248")*/ _unknown_nodes_8_node_248 = 1ui32 << 24ui32,
		/*nicename("Node 249")*/ _unknown_nodes_8_node_249 = 1ui32 << 25ui32,
		/*nicename("Node 250")*/ _unknown_nodes_8_node_250 = 1ui32 << 26ui32,
		/*nicename("Node 251")*/ _unknown_nodes_8_node_251 = 1ui32 << 27ui32,
		/*nicename("Node 252")*/ _unknown_nodes_8_node_252 = 1ui32 << 28ui32,
		/*nicename("Node 253")*/ _unknown_nodes_8_node_253 = 1ui32 << 29ui32,
		/*nicename("Node 254")*/ _unknown_nodes_8_node_254 = 1ui32 << 30ui32,
		/*nicename("Node 255")*/ _unknown_nodes_8_node_255 = 1ui32 << 31ui32,
	};

	struct nicename("Unknown") s_unknown_definition
	{
		int16_t __unknown0;
		int16_t __unknown1;
	};

	struct nicename("Aim Blending") s_aim_blending_definition
	{
		struct nicename("Bones") s_bones_definition
		{
			int16_t nicename("Bone") bone;
			int16_t __unknown0;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_bones_definition> nicename("Bones") bones_block;
		int8_t __unknown0;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		int8_t __unknown6;
		int8_t __unknown7;
		int8_t __unknown8;
		int8_t __unknown9;
		int8_t __unknown10;
		int8_t __unknown11;
		int8_t __unknown12;
		int8_t __unknown13;
		int8_t __unknown14;
		int8_t __unknown15;
		int8_t __unknown16;
		int8_t __unknown17;
		int8_t __unknown18;
		int8_t __unknown19;
		int8_t __unknown20;
		int8_t __unknown21;
		int8_t __unknown22;
		int8_t __unknown23;
		int8_t __unknown24;
		int8_t __unknown25;
		int8_t __unknown26;
		int8_t __unknown27;
		int8_t __unknown28;
		int8_t __unknown29;
		int8_t __unknown30;
		int8_t __unknown31;
	};

	struct nicename("Pain") s_pain_definition
	{
		string_id_legacy nicename("Name") name;
		s_data_reference_legacy nicename("Function") function_data_reference;
	};

	struct nicename("Variant Mode Substitution") s_variant_mode_substitution_definition
	{
		struct nicename("Modes") s_modes_definition
		{
			string_id_legacy nicename("Original Mode") original_mode;
			string_id_legacy nicename("New Mode") new_mode;
		};

		string_id_legacy nicename("Variant Name") variant_name;
		int32_t __unknown0;
		s_tag_block_legacy<s_modes_definition> nicename("Modes") modes_block;
	};

	struct nicename("Skeleton Nodes") s_skeleton_nodes_definition
	{
		enum nicename("Model Flags") b_model_flags : uint8_t /* bitfield */
		{
			/*nicename("Primary Model")*/ _model_flags_primary_model = 1ui8 << 0ui8,
			/*nicename("Secondary Model")*/ _model_flags_secondary_model = 1ui8 << 1ui8,
			/*nicename("Local Root")*/ _model_flags_local_root = 1ui8 << 2ui8,
			/*nicename("Left Hand")*/ _model_flags_left_hand = 1ui8 << 3ui8,
			/*nicename("Right Hand")*/ _model_flags_right_hand = 1ui8 << 4ui8,
			/*nicename("Left Arm Member")*/ _model_flags_left_arm_member = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _model_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _model_flags_bit_7 = 1ui8 << 7ui8,
		};

		enum nicename("Node Joint Flags") b_node_joint_flags : uint8_t /* bitfield */
		{
			/*nicename("Ball-Socket")*/ _node_joint_flags_ball_socket = 1ui8 << 0ui8,
			/*nicename("Hinge")*/ _node_joint_flags_hinge = 1ui8 << 1ui8,
			/*nicename("No Movement")*/ _node_joint_flags_no_movement = 1ui8 << 2ui8,
			/*nicename("Bit 3")*/ _node_joint_flags_bit_3 = 1ui8 << 3ui8,
			/*nicename("Bit 4")*/ _node_joint_flags_bit_4 = 1ui8 << 4ui8,
			/*nicename("Bit 5")*/ _node_joint_flags_bit_5 = 1ui8 << 5ui8,
			/*nicename("Bit 6")*/ _node_joint_flags_bit_6 = 1ui8 << 6ui8,
			/*nicename("Bit 7")*/ _node_joint_flags_bit_7 = 1ui8 << 7ui8,
		};

		string_id_legacy nicename("Name") name;
		int16_t nicename("Next Sibling Node Index") next_sibling_node_index;
		int16_t nicename("First Child Node Index") first_child_node_index;
		int16_t nicename("Parent Node Index") parent_node_index;
		b_model_flags nicename("Model Flags") model_flags;
		b_node_joint_flags nicename("Node Joint Flags") node_joint_flags;
		int8_t __unknown0;
		int8_t __unknown1;
		int16_t __unknown2;
		float nicename("Base Vector i") base_vector_i;
		float nicename("Base Vector j") base_vector_j;
		float nicename("Base Vector k") base_vector_k;
		float nicename("Vector Range") vector_range;
		float nicename("z Position") z_position;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
	};

	struct nicename("Sound References") s_sound_references_definition
	{
		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Allow on Player")*/ _flags_allow_on_player = 1ui16 << 0ui16,
			/*nicename("Left Arm Only")*/ _flags_left_arm_only = 1ui16 << 1ui16,
			/*nicename("Right Arm Only")*/ _flags_right_arm_only = 1ui16 << 2ui16,
			/*nicename("First Person Only")*/ _flags_first_person_only = 1ui16 << 3ui16,
			/*nicename("Forward Only")*/ _flags_forward_only = 1ui16 << 4ui16,
			/*nicename("Reverse Only")*/ _flags_reverse_only = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		s_tag_reference_legacy nicename("Sound") sound_reference;
		b_flags nicename("Flags") flags;
		int16_t __unknown0;
	};

	struct nicename("Effect References") s_effect_references_definition
	{
		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Allow on Player")*/ _flags_allow_on_player = 1ui16 << 0ui16,
			/*nicename("Left Arm Only")*/ _flags_left_arm_only = 1ui16 << 1ui16,
			/*nicename("Right Arm Only")*/ _flags_right_arm_only = 1ui16 << 2ui16,
			/*nicename("First Person Only")*/ _flags_first_person_only = 1ui16 << 3ui16,
			/*nicename("Forward Only")*/ _flags_forward_only = 1ui16 << 4ui16,
			/*nicename("Reverse Only")*/ _flags_reverse_only = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		s_tag_reference_legacy nicename("Effect") effect_reference;
		b_flags nicename("Flags") flags;
		int16_t __unknown0;
	};

	struct nicename("Blend Screens") s_blend_screens_definition
	{
		string_id_legacy nicename("Label") label;
		float nicename("Right Yaw Per Frame") right_yaw_per_frame;
		float nicename("Left Yaw Per Frame") left_yaw_per_frame;
		int16_t nicename("Right Frame Count") right_frame_count;
		int16_t nicename("Left Frame Count") left_frame_count;
		float nicename("Down Pitch Per Frame") down_pitch_per_frame;
		float nicename("Up Pitch Per Frame") up_pitch_per_frame;
		int16_t nicename("Down Pitch Frame Count") down_pitch_frame_count;
		int16_t nicename("Up Pitch Frame Count") up_pitch_frame_count;
	};

	struct nicename("Legs") s_legs_definition
	{
		enum nicename("Anchors") e_anchors : uint16_t
		{
			/*nicename("False")*/ _anchors_false = 0ui16,
			/*nicename("True")*/ _anchors_true = 1ui16,
		};

		string_id_legacy nicename("Foot Marker") foot_marker;
		float nicename("Foot min") foot_min;
		float nicename("Foot max") foot_max;
		string_id_legacy nicename("Ankle Marker") ankle_marker;
		float nicename("Ankle min") ankle_min;
		float nicename("Ankle max") ankle_max;
		e_anchors nicename("Anchors") anchors;
		int16_t __unknown0;
	};

	struct nicename("Animations") s_animations_definition
	{
		enum nicename("Playback Flags") b_playback_flags : uint16_t /* bitfield */
		{
			/*nicename("Disable Interpolation In")*/ _playback_flags_disable_interpolation_in = 1ui16 << 0ui16,
			/*nicename("Disable Interpolation Out")*/ _playback_flags_disable_interpolation_out = 1ui16 << 1ui16,
			/*nicename("Disable Mode ik")*/ _playback_flags_disable_mode_ik = 1ui16 << 2ui16,
			/*nicename("Disable Weapon ik")*/ _playback_flags_disable_weapon_ik = 1ui16 << 3ui16,
			/*nicename("Disable Weapon Aim/First Person")*/ _playback_flags_disable_weapon_aim_first_person = 1ui16 << 4ui16,
			/*nicename("Disable Look Screen")*/ _playback_flags_disable_look_screen = 1ui16 << 5ui16,
			/*nicename("Disable Transition Adjustment")*/ _playback_flags_disable_transition_adjustment = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _playback_flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _playback_flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _playback_flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _playback_flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _playback_flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _playback_flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _playback_flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _playback_flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _playback_flags_bit_15 = 1ui16 << 15ui16,
		};

		enum nicename("Production Flags") b_production_flags : uint16_t /* bitfield */
		{
			/*nicename("Do Not Monitor Changes")*/ _production_flags_do_not_monitor_changes = 1ui16 << 0ui16,
			/*nicename("Verify Sound Events")*/ _production_flags_verify_sound_events = 1ui16 << 1ui16,
			/*nicename("Do Not Inherit For Player Graphs")*/ _production_flags_do_not_inherit_for_player_graphs = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _production_flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _production_flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _production_flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _production_flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _production_flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _production_flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _production_flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _production_flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _production_flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _production_flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _production_flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _production_flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _production_flags_bit_15 = 1ui16 << 15ui16,
		};

		struct nicename("Animation Definition") s_animation_definition_definition
		{
			struct nicename("Frame Events") s_frame_events_definition
			{
				int16_t nicename("Type") type;
				int16_t nicename("Frame") frame;
			};

			struct nicename("Sound Events") s_sound_events_definition
			{
				int16_t nicename("Sound") sound;
				int16_t nicename("Frame") frame;
				string_id_legacy nicename("Marker Name") marker_name;
			};

			struct nicename("Effect Events") s_effect_events_definition
			{
				enum nicename("Damage Reporting Type") e_damage_reporting_type : uint8_t
				{
					/*nicename("Guardians (Unknown)")*/ _damage_reporting_type_guardians_unknown = 0ui8,
					/*nicename("Guardians")*/ _damage_reporting_type_guardians = 1ui8,
					/*nicename("Guardians (Scripting)")*/ _damage_reporting_type_guardians_scripting = 2ui8,
					/*nicename("Suicide")*/ _damage_reporting_type_suicide = 3ui8,
					/*nicename("Magnum")*/ _damage_reporting_type_magnum = 4ui8,
					/*nicename("Assault Rifle")*/ _damage_reporting_type_assault_rifle = 5ui8,
					/*nicename("DMR")*/ _damage_reporting_type_dmr = 6ui8,
					/*nicename("Shotgun")*/ _damage_reporting_type_shotgun = 7ui8,
					/*nicename("Sniper Rifle")*/ _damage_reporting_type_sniper_rifle = 8ui8,
					/*nicename("Rocket Launcher")*/ _damage_reporting_type_rocket_launcher = 9ui8,
					/*nicename("Spartan Laser")*/ _damage_reporting_type_spartan_laser = 10ui8,
					/*nicename("Frag Grenade")*/ _damage_reporting_type_frag_grenade = 11ui8,
					/*nicename("Grenade Launcher")*/ _damage_reporting_type_grenade_launcher = 12ui8,
					/*nicename("Plasma Pistol")*/ _damage_reporting_type_plasma_pistol = 13ui8,
					/*nicename("Needler")*/ _damage_reporting_type_needler = 14ui8,
					/*nicename("Plasma Rifle")*/ _damage_reporting_type_plasma_rifle = 15ui8,
					/*nicename("Plasma Repeater")*/ _damage_reporting_type_plasma_repeater = 16ui8,
					/*nicename("Needle Rifle")*/ _damage_reporting_type_needle_rifle = 17ui8,
					/*nicename("Spiker")*/ _damage_reporting_type_spiker = 18ui8,
					/*nicename("Plasma Launcher")*/ _damage_reporting_type_plasma_launcher = 19ui8,
					/*nicename("Gravity Hammer")*/ _damage_reporting_type_gravity_hammer = 20ui8,
					/*nicename("Energy Sword")*/ _damage_reporting_type_energy_sword = 21ui8,
					/*nicename("Plasma Grenade")*/ _damage_reporting_type_plasma_grenade = 22ui8,
					/*nicename("Concussion Rifle")*/ _damage_reporting_type_concussion_rifle = 23ui8,
					/*nicename("Ghost")*/ _damage_reporting_type_ghost = 24ui8,
					/*nicename("Revenant")*/ _damage_reporting_type_revenant = 25ui8,
					/*nicename("Revenant Gunner")*/ _damage_reporting_type_revenant_gunner = 26ui8,
					/*nicename("Wraith")*/ _damage_reporting_type_wraith = 27ui8,
					/*nicename("Wraith Turret")*/ _damage_reporting_type_wraith_turret = 28ui8,
					/*nicename("Banshee")*/ _damage_reporting_type_banshee = 29ui8,
					/*nicename("Banshee Bomb")*/ _damage_reporting_type_banshee_bomb = 30ui8,
					/*nicename("Seraph")*/ _damage_reporting_type_seraph = 31ui8,
					/*nicename("Mongoose")*/ _damage_reporting_type_mongoose = 32ui8,
					/*nicename("Warthog")*/ _damage_reporting_type_warthog = 33ui8,
					/*nicename("Warthog Chaingun")*/ _damage_reporting_type_warthog_chaingun = 34ui8,
					/*nicename("Warthog Gauss")*/ _damage_reporting_type_warthog_gauss = 35ui8,
					/*nicename("Warthog Rocket")*/ _damage_reporting_type_warthog_rocket = 36ui8,
					/*nicename("Scorpion")*/ _damage_reporting_type_scorpion = 37ui8,
					/*nicename("Scorpion Turret")*/ _damage_reporting_type_scorpion_turret = 38ui8,
					/*nicename("Falcon")*/ _damage_reporting_type_falcon = 39ui8,
					/*nicename("Falcon Gunner")*/ _damage_reporting_type_falcon_gunner = 40ui8,
					/*nicename("Falling")*/ _damage_reporting_type_falling = 41ui8,
					/*nicename("Collision")*/ _damage_reporting_type_collision = 42ui8,
					/*nicename("Melee")*/ _damage_reporting_type_melee = 43ui8,
					/*nicename("Explosion")*/ _damage_reporting_type_explosion = 44ui8,
					/*nicename("Birthday Explosion")*/ _damage_reporting_type_birthday_explosion = 45ui8,
					/*nicename("Flag")*/ _damage_reporting_type_flag = 46ui8,
					/*nicename("Bomb")*/ _damage_reporting_type_bomb = 47ui8,
					/*nicename("Bomb Explosion")*/ _damage_reporting_type_bomb_explosion = 48ui8,
					/*nicename("Ball")*/ _damage_reporting_type_ball = 49ui8,
					/*nicename("Teleporter")*/ _damage_reporting_type_teleporter = 50ui8,
					/*nicename("Transfer Damage")*/ _damage_reporting_type_transfer_damage = 51ui8,
					/*nicename("Armor Lock")*/ _damage_reporting_type_armor_lock = 52ui8,
					/*nicename("Target Locator")*/ _damage_reporting_type_target_locator = 53ui8,
					/*nicename("Human Turret")*/ _damage_reporting_type_human_turret = 54ui8,
					/*nicename("Plasma Cannon")*/ _damage_reporting_type_plasma_cannon = 55ui8,
					/*nicename("Plasma Mortar")*/ _damage_reporting_type_plasma_mortar = 56ui8,
					/*nicename("Plasma Turret")*/ _damage_reporting_type_plasma_turret = 57ui8,
					/*nicename("Shade Turret")*/ _damage_reporting_type_shade_turret = 58ui8,
					/*nicename("Sabre")*/ _damage_reporting_type_sabre = 59ui8,
					/*nicename("SMG")*/ _damage_reporting_type_smg = 60ui8,
					/*nicename("Carbine")*/ _damage_reporting_type_carbine = 61ui8,
					/*nicename("Battle Rifle")*/ _damage_reporting_type_battle_rifle = 62ui8,
					/*nicename("Focus Rifle")*/ _damage_reporting_type_focus_rifle = 63ui8,
					/*nicename("Fuel Rod")*/ _damage_reporting_type_fuel_rod = 64ui8,
					/*nicename("Missile Pod")*/ _damage_reporting_type_missile_pod = 65ui8,
					/*nicename("Brute Shot")*/ _damage_reporting_type_brute_shot = 66ui8,
					/*nicename("Flamethrower")*/ _damage_reporting_type_flamethrower = 67ui8,
					/*nicename("Sentinel Gun")*/ _damage_reporting_type_sentinel_gun = 68ui8,
					/*nicename("Spike Grenade")*/ _damage_reporting_type_spike_grenade = 69ui8,
					/*nicename("Firebomb Grenade")*/ _damage_reporting_type_firebomb_grenade = 70ui8,
					/*nicename("Elephant Turret")*/ _damage_reporting_type_elephant_turret = 71ui8,
					/*nicename("Spectre")*/ _damage_reporting_type_spectre = 72ui8,
					/*nicename("Spectre Gunner")*/ _damage_reporting_type_spectre_gunner = 73ui8,
					/*nicename("Tank")*/ _damage_reporting_type_tank = 74ui8,
					/*nicename("Chopper")*/ _damage_reporting_type_chopper = 75ui8,
					/*nicename("Falcon")*/ _damage_reporting_type_falcon1 = 76ui8,
					/*nicename("Mantis")*/ _damage_reporting_type_mantis = 77ui8,
					/*nicename("Prowler")*/ _damage_reporting_type_prowler = 78ui8,
					/*nicename("Sentinel Beam")*/ _damage_reporting_type_sentinel_beam = 79ui8,
					/*nicename("Sentinel RPG")*/ _damage_reporting_type_sentinel_rpg = 80ui8,
					/*nicename("Tripmine")*/ _damage_reporting_type_tripmine = 81ui8,
				};

				int16_t nicename("Effect") effect;
				int16_t nicename("Frame") frame;
				string_id_legacy nicename("Marker Name") marker_name;
				e_damage_reporting_type nicename("Damage Reporting Type") damage_reporting_type;
				int8_t __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
			};

			struct nicename("Unknown 14") s_unknown_14_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
			};

			struct nicename("Object-Space Parent Nodes") s_object_space_parent_nodes_definition
			{
				enum nicename("Component Flags") b_component_flags : uint16_t /* bitfield */
				{
					/*nicename("Rotation")*/ _component_flags_rotation = 1ui16 << 0ui16,
					/*nicename("Translation")*/ _component_flags_translation = 1ui16 << 1ui16,
					/*nicename("Scale")*/ _component_flags_scale = 1ui16 << 2ui16,
				};

				int16_t nicename("Node Index") node_index;
				b_component_flags nicename("Component Flags") component_flags;
				int16_t nicename("Rotation x") rotation_x;
				int16_t nicename("Rotation y") rotation_y;
				int16_t nicename("Rotation z") rotation_z;
				int16_t nicename("Rotation w") rotation_w;
				float nicename("Default Translation x") default_translation_x;
				float nicename("Default Translation y") default_translation_y;
				float nicename("Default Translation z") default_translation_z;
				float nicename("Default Scale") default_scale;
			};

			struct nicename("Leg Anchoring") s_leg_anchoring_definition
			{
				struct nicename("Unknown") s_unknown1_definition
				{
					int16_t nicename("Frame 1a") frame_1a;
					int16_t nicename("Frame 2a") frame_2a;
					int16_t nicename("Frame 1b") frame_1b;
					int16_t nicename("Frame 2b") frame_2b;
					s_undefined32_legacy __unknown0;
					s_undefined32_legacy __unknown1;
					s_undefined32_legacy __unknown2;
				};

				int16_t nicename("Leg Index") leg_index;
				int16_t __unknown0;
				s_tag_block_legacy<s_unknown1_definition> __unknown1;
			};

			struct nicename("Unknown") s_unknown2_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
			};

			struct nicename("Unknown") s_unknown3_definition
			{
				int16_t __unknown0;
				int16_t __unknown1;
			};

			struct nicename("New Mode ik") s_new_mode_ik_definition
			{
				string_id_legacy nicename("Marker") marker;
				int16_t __unknown0;
				int16_t nicename("Bone A") bone_a;
				int16_t nicename("Bone B") bone_b;
				int16_t __unknown1;
				string_id_legacy nicename("Attach To Marker") attach_to_marker;
				int32_t __unknown2;
				int8_t __unknown3;
				int8_t __unknown4;
				int8_t __unknown5;
				int8_t __unknown6;
				int8_t __unknown7;
				int8_t __unknown8;
				int8_t __unknown9;
				int8_t __unknown10;
			};

			struct nicename("Unknown") s_unknown4_definition
			{
				string_id_legacy __unknown0;
				int8_t __unknown1;
				int8_t __unknown2;
				int8_t __unknown3;
				int8_t __unknown4;
				int16_t __unknown5;
				int16_t __unknown6;
				int8_t __unknown7;
				int8_t __unknown8;
				int8_t __unknown9;
				int8_t __unknown10;
				int16_t __unknown11;
				int8_t __unknown12;
				int8_t __unknown13;
			};

			struct nicename("Unknown") s_unknown5_definition
			{
				string_id_legacy __unknown0;
				int32_t __unknown1;
				float __unknown2;
				int16_t __unknown3;
				int16_t __unknown4;
			};

			struct nicename("Unknown") s_unknown6_definition
			{
				s_undefined32_legacy __unknown0;
				s_undefined32_legacy __unknown1;
				s_undefined32_legacy __unknown2;
				s_data_reference_legacy __unknown3;
			};

			int8_t nicename("Node Count") node_count;
			int8_t __unknown0;
			int16_t nicename("Frame Count") frame_count;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
			int16_t __unknown5;
			int8_t __unknown6;
			int8_t __unknown7;
			int32_t nicename("Production Checksum") production_checksum;
			string_id_legacy nicename("Import Path") import_path;
			int32_t nicename("Node List Checksum") node_list_checksum;
			int32_t __unknown8;
			int16_t __unknown9;
			int16_t __unknown10;
			int16_t nicename("Raw Information Group Index") raw_information_group_index;
			int16_t nicename("Raw Information Member Index") raw_information_member_index;
			float __unknown11;
			float __unknown12;
			float __unknown13;
			float __unknown14;
			float __unknown15;
			s_tag_block_legacy<s_frame_events_definition> nicename("Frame Events") frame_events_block;
			s_tag_block_legacy<s_sound_events_definition> nicename("Sound Events") sound_events_block;
			s_tag_block_legacy<s_effect_events_definition> nicename("Effect Events") effect_events_block;
			s_tag_block_legacy<s_unknown_14_definition> nicename("Unknown 14") unknown_14_block;
			s_tag_block_legacy<s_object_space_parent_nodes_definition> nicename("Object-Space Parent Nodes") object_space_parent_nodes_block;
			s_tag_block_legacy<s_leg_anchoring_definition> nicename("Leg Anchoring") leg_anchoring_block;
			s_tag_block_legacy<s_unknown2_definition> __unknown16;
			s_tag_block_legacy<s_unknown3_definition> __unknown17;
			s_tag_block_legacy<s_new_mode_ik_definition> nicename("New Mode ik") new_mode_ik_block;
			s_undefined32_legacy __unknown18;
			s_undefined32_legacy __unknown19;
			s_undefined32_legacy __unknown20;
			s_tag_block_legacy<s_unknown4_definition> __unknown21;
			s_tag_block_legacy<s_unknown5_definition> __unknown22;
			s_tag_block_legacy<s_unknown6_definition> __unknown23;
		};

		string_id_legacy nicename("Name") name;
		float nicename("Weight") weight;
		int16_t nicename("Loop Frame Index") loop_frame_index;
		b_playback_flags nicename("Playback Flags") playback_flags;
		float __unknown0;
		float __unknown1;
		int16_t nicename("Previous Variant Sibling") previous_variant_sibling;
		int16_t nicename("Next Variant Sibling") next_variant_sibling;
		b_production_flags nicename("Production Flags") production_flags;
		int8_t nicename("Blend Screen") blend_screen;
		int8_t __unknown2;
		s_tag_reference_legacy nicename("Parent") parent_reference;
		int16_t nicename("Parent Index") parent_index;
		int16_t __unknown3;
		s_tag_block_legacy<s_animation_definition_definition> nicename("Animation Definition") animation_definition_block;
	};

	struct nicename("Animations 2") s_animations_2_definition
	{
		string_id_legacy nicename("Label") label;
		int32_t __unknown0;
		s_undefined32_legacy __unknown1;
		float __unknown2;
		int16_t __unknown3;
		int16_t __unknown4;
		int16_t __unknown5;
		int16_t __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		string_id_legacy nicename("Function") function;
		int16_t nicename("Pain Index") pain_index;
		int16_t __unknown9;
		int16_t nicename("Graph Index") graph_index;
		int16_t nicename("Animation") animation;
	};

	struct nicename("Trigger Animations") s_trigger_animations_definition
	{
		string_id_legacy nicename("Label") label;
		int32_t __unknown0;
		string_id_legacy nicename("Function") function;
		string_id_legacy nicename("Function") function1;
		string_id_legacy nicename("Function") function2;
		int16_t nicename("Graph Index") graph_index;
		int16_t nicename("Animation") animation;
	};

	struct nicename("Animation Groups") s_animation_groups_definition
	{
		struct nicename("Animations 2") s_animations_21_definition
		{
			int16_t nicename("Animations 2 Index") animations_2_index;
			int16_t __unknown0;
			int16_t __unknown1;
			int16_t __unknown2;
		};

		struct nicename("Trigger Animations") s_trigger_animations1_definition
		{
			int16_t nicename("Trigger Animation Index") trigger_animation_index;
			int16_t __unknown0;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_animations_21_definition> nicename("Animations 2") animations_2_block;
		s_tag_block_legacy<s_trigger_animations1_definition> nicename("Trigger Animations") trigger_animations_block;
	};

	struct nicename("Locomotion") s_locomotion_definition
	{
		string_id_legacy nicename("Full Name") full_name;
		string_id_legacy nicename("Low Speed") low_speed;
		string_id_legacy nicename("Mid Speed") mid_speed;
		string_id_legacy nicename("High Speed") high_speed;
		int16_t __unknown0;
		int16_t __unknown1;
	};

	struct nicename("Movement Groups") s_movement_groups_definition
	{
		struct nicename("Locomotion") s_locomotion1_definition
		{
			int16_t nicename("Locomotion Index") locomotion_index;
			int16_t __unknown0;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_locomotion1_definition> nicename("Locomotion") locomotion_block;
	};

	struct nicename("Limb ik") s_limb_ik_definition
	{
		string_id_legacy nicename("Name") name;
		string_id_legacy nicename("Marker") marker;
		int32_t __unknown0;
		string_id_legacy nicename("Marker") marker1;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
	};

	struct nicename("Limb ik Groups") s_limb_ik_groups_definition
	{
		struct nicename("Limb ik") s_limb_ik1_definition
		{
			int16_t nicename("Limb ik Index") limb_ik_index;
			int16_t __unknown0;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_limb_ik1_definition> nicename("Limb ik") limb_ik_block;
	};

	struct nicename("Limb Positioning") s_limb_positioning_definition
	{
		string_id_legacy nicename("Limb") limb;
		s_undefined32_legacy __unknown0;
		int16_t nicename("Bone A") bone_a;
		int16_t nicename("Bone B") bone_b;
		int16_t __unknown1;
		int16_t __unknown2;
	};

	struct nicename("Modes") s_modes1_definition
	{
		struct nicename("Weapon Class") s_weapon_class_definition
		{
			struct nicename("Weapon Type") s_weapon_type_definition
			{
				struct nicename("Action Type") s_action_type_definition
				{
					struct nicename("Actions") s_actions_definition
					{
						string_id_legacy nicename("Label") label;
						int16_t nicename("Animation Group") animation_group;
						int16_t nicename("Limb ik Group") limb_ik_group;
						int16_t nicename("Graph Index") graph_index;
						int16_t nicename("Animation") animation;
					};

					struct nicename("Overlays") s_overlays_definition
					{
						string_id_legacy nicename("Label") label;
						int16_t nicename("Animation Group") animation_group;
						int16_t nicename("Limb ik Group") limb_ik_group;
						int16_t nicename("Graph Index") graph_index;
						int16_t nicename("Animation") animation;
					};

					struct nicename("Death And Damage") s_death_and_damage_definition
					{
						struct nicename("Directions") s_directions_definition
						{
							struct nicename("Regions") s_regions_definition
							{
								int16_t nicename("Graph Index") graph_index;
								int16_t nicename("Animation") animation;
							};

							s_tag_block_legacy<s_regions_definition> nicename("Regions") regions_block;
						};

						string_id_legacy nicename("Label") label;
						s_tag_block_legacy<s_directions_definition> nicename("Directions") directions_block;
					};

					struct nicename("Transitions") s_transitions_definition
					{
						struct nicename("Destinations") s_destinations_definition
						{
							string_id_legacy nicename("Mode Name") mode_name;
							string_id_legacy nicename("State Name") state_name;
							int16_t nicename("Graph Index") graph_index;
							int16_t nicename("Animation") animation;
						};

						string_id_legacy nicename("State Name") state_name;
						s_tag_block_legacy<s_destinations_definition> nicename("Destinations") destinations_block;
					};

					struct nicename("Unknown") s_unknown7_definition
					{
						float __unknown0;
						float __unknown1;
						float __unknown2;
						float __unknown3;
						float __unknown4;
						float __unknown5;
						float __unknown6;
						float __unknown7;
					};

					string_id_legacy nicename("Label") label;
					int16_t nicename("Animation Group") animation_group;
					int16_t nicename("Limb ik Group") limb_ik_group;
					int16_t nicename("Movement Group") movement_group;
					int16_t __unknown0;
					s_tag_block_legacy<s_actions_definition> nicename("Actions") actions_block;
					s_tag_block_legacy<s_overlays_definition> nicename("Overlays") overlays_block;
					s_tag_block_legacy<s_death_and_damage_definition> nicename("Death And Damage") death_and_damage_block;
					s_tag_block_legacy<s_transitions_definition> nicename("Transitions") transitions_block;
					s_tag_block_legacy<s_unknown7_definition> __unknown1;
				};

				string_id_legacy nicename("Label") label;
				int16_t nicename("Animation Group") animation_group;
				int16_t nicename("Limb ik Group") limb_ik_group;
				s_tag_block_legacy<s_action_type_definition> nicename("Action Type") action_type_block;
			};

			struct nicename("Weapon ik") s_weapon_ik_definition
			{
				string_id_legacy nicename("Marker") marker;
				string_id_legacy nicename("Attach To Marker") attach_to_marker;
			};

			struct nicename("Ranged Actions") s_ranged_actions_definition
			{
				struct nicename("Unknown") s_unknown8_definition
				{
					int32_t __unknown0;
					int16_t nicename("Graph Index") graph_index;
					int16_t nicename("Animation") animation;
					float __unknown1;
					s_undefined32_legacy __unknown2;
				};

				struct nicename("Unknown") s_unknown9_definition
				{
					struct nicename("Unknown") s_unknown10_definition
					{
						float __unknown0;
						float __unknown1;
					};

					struct nicename("Unknown") s_unknown11_definition
					{
						int8_t __unknown0;
						int8_t __unknown1;
						int8_t __unknown2;
						int8_t __unknown3;
						int8_t __unknown4;
						int8_t __unknown5;
						int8_t __unknown6;
						int8_t __unknown7;
					};

					s_tag_block_legacy<s_unknown10_definition> __unknown0;
					s_tag_block_legacy<s_unknown11_definition> __unknown1;
				};

				string_id_legacy nicename("Label") label;
				s_tag_block_legacy<s_unknown8_definition> __unknown0;
				s_tag_block_legacy<s_unknown9_definition> __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				int16_t __unknown4;
				int16_t __unknown5;
			};

			struct nicename("Sync Actions") s_sync_actions_definition
			{
				struct nicename("Class") s_$class_definition
				{
					struct nicename("Unknown") s_unknown12_definition
					{
						int32_t __unknown0;
						int16_t nicename("Graph Index") graph_index;
						int16_t nicename("Animation") animation;
						s_undefined32_legacy __unknown1;
						s_undefined32_legacy __unknown2;
						s_undefined32_legacy __unknown3;
						s_undefined32_legacy __unknown4;
						s_undefined32_legacy __unknown5;
						s_undefined32_legacy __unknown6;
						s_undefined32_legacy __unknown7;
						s_undefined32_legacy __unknown8;
						s_undefined32_legacy __unknown9;
						s_undefined32_legacy __unknown10;
					};

					struct nicename("Sync Biped") s_sync_biped_definition
					{
						int32_t __unknown0;
						s_tag_reference_legacy nicename("Biped") biped_reference;
					};

					string_id_legacy nicename("Label") label;
					s_tag_block_legacy<s_unknown12_definition> __unknown0;
					s_tag_block_legacy<s_sync_biped_definition> nicename("Sync Biped") sync_biped_block;
				};

				string_id_legacy nicename("Label") label;
				s_tag_block_legacy<s_$class_definition> nicename("Class") $class_block;
			};

			string_id_legacy nicename("Label") label;
			int16_t nicename("Animation Group") animation_group;
			int16_t nicename("Limb ik Group") limb_ik_group;
			s_tag_block_legacy<s_weapon_type_definition> nicename("Weapon Type") weapon_type_block;
			s_tag_block_legacy<s_weapon_ik_definition> nicename("Weapon ik") weapon_ik_block;
			s_tag_block_legacy<s_ranged_actions_definition> nicename("Ranged Actions") ranged_actions_block;
			s_tag_block_legacy<s_sync_actions_definition> nicename("Sync Actions") sync_actions_block;
		};

		struct nicename("Mode ik") s_mode_ik_definition
		{
			string_id_legacy nicename("Marker") marker;
			string_id_legacy nicename("Attach To Marker") attach_to_marker;
		};

		string_id_legacy nicename("Label") label;
		int16_t nicename("Animation Group") animation_group;
		int16_t nicename("Limb ik Group") limb_ik_group;
		int32_t __unknown0;
		s_tag_block_legacy<s_weapon_class_definition> nicename("Weapon Class") weapon_class_block;
		s_tag_block_legacy<s_mode_ik_definition> nicename("Mode ik") mode_ik_block;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
	};

	struct nicename("Vehicle Suspension") s_vehicle_suspension_definition
	{
		string_id_legacy nicename("Label") label;
		int16_t nicename("Graph Index") graph_index;
		int16_t nicename("Animation") animation;
		string_id_legacy nicename("Function") function;
		string_id_legacy nicename("Marker Name") marker_name;
		string_id_legacy nicename("Unknown Marker Name") unknown_marker_name;
		float nicename("Mass Point Offset") mass_point_offset;
		float nicename("Full Extension Ground Depth") full_extension_ground_depth;
		float nicename("Full Compression Ground Depth") full_compression_ground_depth;
		// Destroyed Suspension : 
		string_id_legacy nicename("Region Name") region_name;
		float nicename("Mass Point Offset") mass_point_offset1;
		float nicename("Full Extension Ground Depth") full_extension_ground_depth1;
		float nicename("Full Compression Ground Depth") full_compression_ground_depth1;
	};

	struct nicename("Object Overlays") s_object_overlays_definition
	{
		enum nicename("Function Controls") e_function_controls : uint16_t
		{
			/*nicename("Frame")*/ _function_controls_frame = 0ui16,
			/*nicename("Scale")*/ _function_controls_scale = 1ui16,
		};

		string_id_legacy nicename("Label") label;
		int16_t nicename("Graph Index") graph_index;
		int16_t nicename("Animation") animation;
		int16_t __unknown0;
		e_function_controls nicename("Function Controls") function_controls;
		string_id_legacy nicename("Function") function;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Inheritance List") s_inheritance_list_definition
	{
		struct nicename("Node Map") s_node_map_definition
		{
			int16_t nicename("Local Node") local_node;
		};

		struct nicename("Node Map Flags") s_node_map_flags_definition
		{
			enum nicename("Local Node Flags") b_local_node_flags : uint32_t /* bitfield */
			{
				/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _local_node_flags_node_0_32_64_96_128_160_192_224 = 1ui32 << 0ui32,
				/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _local_node_flags_node_1_33_65_97_129_161_193_225 = 1ui32 << 1ui32,
				/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _local_node_flags_node_2_34_66_98_130_162_194_226 = 1ui32 << 2ui32,
				/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _local_node_flags_node_3_35_67_99_131_163_195_227 = 1ui32 << 3ui32,
				/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _local_node_flags_node_4_36_68_100_132_164_196_228 = 1ui32 << 4ui32,
				/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _local_node_flags_node_5_37_69_101_133_165_197_229 = 1ui32 << 5ui32,
				/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _local_node_flags_node_6_38_70_102_134_166_198_230 = 1ui32 << 6ui32,
				/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _local_node_flags_node_7_39_71_103_135_167_199_231 = 1ui32 << 7ui32,
				/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _local_node_flags_node_8_40_72_104_136_168_200_232 = 1ui32 << 8ui32,
				/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _local_node_flags_node_9_41_73_105_137_169_201_233 = 1ui32 << 9ui32,
				/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _local_node_flags_node_10_42_74_106_138_170_202_234 = 1ui32 << 10ui32,
				/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _local_node_flags_node_11_43_75_107_139_171_203_235 = 1ui32 << 11ui32,
				/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _local_node_flags_node_12_44_76_108_140_172_204_236 = 1ui32 << 12ui32,
				/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _local_node_flags_node_13_45_77_109_141_173_205_237 = 1ui32 << 13ui32,
				/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _local_node_flags_node_14_46_78_110_142_174_206_238 = 1ui32 << 14ui32,
				/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _local_node_flags_node_15_47_79_111_143_175_207_239 = 1ui32 << 15ui32,
				/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _local_node_flags_node_16_48_80_112_144_176_208_240 = 1ui32 << 16ui32,
				/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _local_node_flags_node_17_49_81_113_145_177_209_241 = 1ui32 << 17ui32,
				/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _local_node_flags_node_18_50_82_114_146_178_210_242 = 1ui32 << 18ui32,
				/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _local_node_flags_node_19_51_83_115_147_179_211_243 = 1ui32 << 19ui32,
				/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _local_node_flags_node_20_52_84_116_148_180_212_244 = 1ui32 << 20ui32,
				/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _local_node_flags_node_21_53_85_117_149_181_213_245 = 1ui32 << 21ui32,
				/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _local_node_flags_node_22_54_86_118_150_182_214_246 = 1ui32 << 22ui32,
				/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _local_node_flags_node_23_55_87_119_151_183_215_247 = 1ui32 << 23ui32,
				/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _local_node_flags_node_24_56_88_120_152_184_216_248 = 1ui32 << 24ui32,
				/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _local_node_flags_node_25_57_89_121_153_185_217_249 = 1ui32 << 25ui32,
				/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _local_node_flags_node_26_58_90_122_154_186_218_250 = 1ui32 << 26ui32,
				/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _local_node_flags_node_27_59_91_123_155_187_219_251 = 1ui32 << 27ui32,
				/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _local_node_flags_node_28_60_92_124_156_188_220_252 = 1ui32 << 28ui32,
				/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _local_node_flags_node_29_61_93_125_157_189_221_253 = 1ui32 << 29ui32,
				/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _local_node_flags_node_30_62_94_126_158_190_222_254 = 1ui32 << 30ui32,
				/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _local_node_flags_node_31_63_95_127_159_191_223_255 = 1ui32 << 31ui32,
			};

			b_local_node_flags nicename("Local Node Flags") local_node_flags;
		};

		s_tag_reference_legacy nicename("Inherited Graph") inherited_graph_reference;
		s_tag_block_legacy<s_node_map_definition> nicename("Node Map") node_map_block;
		s_tag_block_legacy<s_node_map_flags_definition> nicename("Node Map Flags") node_map_flags_block;
		s_undefined32_legacy __unknown0;
	};

	struct nicename("New Inheritance List") s_new_inheritance_list_definition
	{
		struct nicename("Node Map") s_node_map1_definition
		{
			int16_t nicename("Local Node") local_node;
		};

		struct nicename("Node Map Flags") s_node_map_flags1_definition
		{
			enum nicename("Local Node Flags") b_local_node_flags : uint32_t /* bitfield */
			{
				/*nicename("Node 0, 32, 64, 96, 128, 160, 192, 224")*/ _local_node_flags_node_0_32_64_96_128_160_192_224 = 1ui32 << 0ui32,
				/*nicename("Node 1, 33, 65, 97, 129, 161, 193, 225")*/ _local_node_flags_node_1_33_65_97_129_161_193_225 = 1ui32 << 1ui32,
				/*nicename("Node 2, 34, 66, 98, 130, 162, 194, 226")*/ _local_node_flags_node_2_34_66_98_130_162_194_226 = 1ui32 << 2ui32,
				/*nicename("Node 3, 35, 67, 99, 131, 163, 195, 227")*/ _local_node_flags_node_3_35_67_99_131_163_195_227 = 1ui32 << 3ui32,
				/*nicename("Node 4, 36, 68, 100, 132, 164, 196, 228")*/ _local_node_flags_node_4_36_68_100_132_164_196_228 = 1ui32 << 4ui32,
				/*nicename("Node 5, 37, 69, 101, 133, 165, 197, 229")*/ _local_node_flags_node_5_37_69_101_133_165_197_229 = 1ui32 << 5ui32,
				/*nicename("Node 6, 38, 70, 102, 134, 166, 198, 230")*/ _local_node_flags_node_6_38_70_102_134_166_198_230 = 1ui32 << 6ui32,
				/*nicename("Node 7, 39, 71, 103, 135, 167, 199, 231")*/ _local_node_flags_node_7_39_71_103_135_167_199_231 = 1ui32 << 7ui32,
				/*nicename("Node 8, 40, 72, 104, 136, 168, 200, 232")*/ _local_node_flags_node_8_40_72_104_136_168_200_232 = 1ui32 << 8ui32,
				/*nicename("Node 9, 41, 73, 105, 137, 169, 201, 233")*/ _local_node_flags_node_9_41_73_105_137_169_201_233 = 1ui32 << 9ui32,
				/*nicename("Node 10, 42, 74, 106, 138, 170, 202, 234")*/ _local_node_flags_node_10_42_74_106_138_170_202_234 = 1ui32 << 10ui32,
				/*nicename("Node 11, 43, 75, 107, 139, 171, 203, 235")*/ _local_node_flags_node_11_43_75_107_139_171_203_235 = 1ui32 << 11ui32,
				/*nicename("Node 12, 44, 76, 108, 140, 172, 204, 236")*/ _local_node_flags_node_12_44_76_108_140_172_204_236 = 1ui32 << 12ui32,
				/*nicename("Node 13, 45, 77, 109, 141, 173, 205, 237")*/ _local_node_flags_node_13_45_77_109_141_173_205_237 = 1ui32 << 13ui32,
				/*nicename("Node 14, 46, 78, 110, 142, 174, 206, 238")*/ _local_node_flags_node_14_46_78_110_142_174_206_238 = 1ui32 << 14ui32,
				/*nicename("Node 15, 47, 79, 111, 143, 175, 207, 239")*/ _local_node_flags_node_15_47_79_111_143_175_207_239 = 1ui32 << 15ui32,
				/*nicename("Node 16, 48, 80, 112, 144, 176, 208, 240")*/ _local_node_flags_node_16_48_80_112_144_176_208_240 = 1ui32 << 16ui32,
				/*nicename("Node 17, 49, 81, 113, 145, 177, 209, 241")*/ _local_node_flags_node_17_49_81_113_145_177_209_241 = 1ui32 << 17ui32,
				/*nicename("Node 18, 50, 82, 114, 146, 178, 210, 242")*/ _local_node_flags_node_18_50_82_114_146_178_210_242 = 1ui32 << 18ui32,
				/*nicename("Node 19, 51, 83, 115, 147, 179, 211, 243")*/ _local_node_flags_node_19_51_83_115_147_179_211_243 = 1ui32 << 19ui32,
				/*nicename("Node 20, 52, 84, 116, 148, 180, 212, 244")*/ _local_node_flags_node_20_52_84_116_148_180_212_244 = 1ui32 << 20ui32,
				/*nicename("Node 21, 53, 85, 117, 149, 181, 213, 245")*/ _local_node_flags_node_21_53_85_117_149_181_213_245 = 1ui32 << 21ui32,
				/*nicename("Node 22, 54, 86, 118, 150, 182, 214, 246")*/ _local_node_flags_node_22_54_86_118_150_182_214_246 = 1ui32 << 22ui32,
				/*nicename("Node 23, 55, 87, 119, 151, 183, 215, 247")*/ _local_node_flags_node_23_55_87_119_151_183_215_247 = 1ui32 << 23ui32,
				/*nicename("Node 24, 56, 88, 120, 152, 184, 216, 248")*/ _local_node_flags_node_24_56_88_120_152_184_216_248 = 1ui32 << 24ui32,
				/*nicename("Node 25, 57, 89, 121, 153, 185, 217, 249")*/ _local_node_flags_node_25_57_89_121_153_185_217_249 = 1ui32 << 25ui32,
				/*nicename("Node 26, 58, 90, 122, 154, 186, 218, 250")*/ _local_node_flags_node_26_58_90_122_154_186_218_250 = 1ui32 << 26ui32,
				/*nicename("Node 27, 59, 91, 123, 155, 187, 219, 251")*/ _local_node_flags_node_27_59_91_123_155_187_219_251 = 1ui32 << 27ui32,
				/*nicename("Node 28, 60, 92, 124, 156, 188, 220, 252")*/ _local_node_flags_node_28_60_92_124_156_188_220_252 = 1ui32 << 28ui32,
				/*nicename("Node 29, 61, 93, 125, 157, 189, 221, 253")*/ _local_node_flags_node_29_61_93_125_157_189_221_253 = 1ui32 << 29ui32,
				/*nicename("Node 30, 62, 94, 126, 158, 190, 222, 254")*/ _local_node_flags_node_30_62_94_126_158_190_222_254 = 1ui32 << 30ui32,
				/*nicename("Node 31, 63, 95, 127, 159, 191, 223, 255")*/ _local_node_flags_node_31_63_95_127_159_191_223_255 = 1ui32 << 31ui32,
			};

			b_local_node_flags nicename("Local Node Flags") local_node_flags;
		};

		s_tag_reference_legacy nicename("Inherited Graph") inherited_graph_reference;
		s_tag_block_legacy<s_node_map1_definition> nicename("Node Map") node_map_block;
		s_tag_block_legacy<s_node_map_flags1_definition> nicename("Node Map Flags") node_map_flags_block;
		s_undefined32_legacy __unknown0;
	};

	struct nicename("Weapon List") s_weapon_list_definition
	{
		string_id_legacy nicename("Weapon Name") weapon_name;
		string_id_legacy nicename("Weapon Class") weapon_class;
	};

	struct nicename("Raw Information Groups") s_raw_information_groups_definition
	{
		int32_t nicename("Member Count") member_count;
		int32_t nicename("[zone] Asset Datum") zone_asset_datum;
		uint16_t nicename("[easy read] Index") easy_read_index;
		uint16_t nicename("[easy read] Salt") easy_read_salt;
		int32_t nicename("Useless Padding") useless_padding;
	};

	s_tag_reference_legacy nicename("Parent Animation Graph") parent_animation_graph_reference;
	b_inheritance_flags nicename("Inheritance Flags") inheritance_flags;
	b_private_flags nicename("Private Flags") private_flags;
	int16_t nicename("Animation Codec Pack") animation_codec_pack;
	int16_t __unknown0;
	int16_t __unknown1;
	s_tag_block_legacy<s_unknown_definition> __unknown2;
	s_tag_block_legacy<s_aim_blending_definition> nicename("Aim Blending") aim_blending_block;
	s_tag_block_legacy<s_pain_definition> nicename("Pain") pain_block;
	s_tag_block_legacy<s_variant_mode_substitution_definition> nicename("Variant Mode Substitution") variant_mode_substitution_block;
	s_tag_block_legacy<s_skeleton_nodes_definition> nicename("Skeleton Nodes") skeleton_nodes_block;
	s_tag_block_legacy<s_sound_references_definition> nicename("Sound References") sound_references_block;
	s_tag_block_legacy<s_effect_references_definition> nicename("Effect References") effect_references_block;
	s_tag_block_legacy<s_blend_screens_definition> nicename("Blend Screens") blend_screens_block;
	s_tag_block_legacy<s_legs_definition> nicename("Legs") legs_block;
	s_tag_reference_legacy nicename("Frame Events") frame_events_reference;
	s_tag_block_legacy<s_animations_definition> nicename("Animations") animations_block;
	s_tag_block_legacy<s_animations_2_definition> nicename("Animations 2") animations_2_block;
	s_tag_block_legacy<s_trigger_animations_definition> nicename("Trigger Animations") trigger_animations_block;
	s_tag_block_legacy<s_animation_groups_definition> nicename("Animation Groups") animation_groups_block;
	s_tag_block_legacy<s_locomotion_definition> nicename("Locomotion") locomotion_block;
	s_tag_block_legacy<s_movement_groups_definition> nicename("Movement Groups") movement_groups_block;
	s_tag_block_legacy<s_limb_ik_definition> nicename("Limb ik") limb_ik_block;
	s_tag_block_legacy<s_limb_ik_groups_definition> nicename("Limb ik Groups") limb_ik_groups_block;
	s_tag_block_legacy<s_limb_positioning_definition> nicename("Limb Positioning") limb_positioning_block;
	int16_t __unknown3;
	int16_t __unknown4;
	s_tag_block_legacy<s_modes1_definition> nicename("Modes") modes_block;
	s_tag_block_legacy<s_vehicle_suspension_definition> nicename("Vehicle Suspension") vehicle_suspension_block;
	s_tag_block_legacy<s_object_overlays_definition> nicename("Object Overlays") object_overlays_block;
	/* Inheritance : The Node Map block should have the same count as the Inherited Graph's nodes. Each Local Node value corresponds to the nodes of THIS graph. If there is no matching node, -1 is acceptable.
	   The Node Map Flags reflect which nodes in the Node Map are used, meaning a bit should be unchecked if it is -1 in the map.
	   Root z Offset allows for differences in height. Updates in realtime so poke around until it looks how you want.
	   Starting at Reach, a new Inheritance block was added, use that. ("New")
	   Unlike Halo 3, Graph Index is obsolete, so inheritance is done right inside the Animations block with a tag reference and animation index. */
	s_tag_block_legacy<s_inheritance_list_definition> nicename("Inheritance List") inheritance_list_block;
	s_tag_block_legacy<s_new_inheritance_list_definition> nicename("New Inheritance List") new_inheritance_list_block;
	s_tag_block_legacy<s_weapon_list_definition> nicename("Weapon List") weapon_list_block;
	b_unknown_arm_nodes_1 nicename("Unknown Arm Nodes 1") unknown_arm_nodes_1;
	b_unknown_arm_nodes_2 nicename("Unknown Arm Nodes 2") unknown_arm_nodes_2;
	b_unknown_arm_nodes_3 nicename("Unknown Arm Nodes 3") unknown_arm_nodes_3;
	b_unknown_arm_nodes_4 nicename("Unknown Arm Nodes 4") unknown_arm_nodes_4;
	b_unknown_arm_nodes_5 nicename("Unknown Arm Nodes 5") unknown_arm_nodes_5;
	b_unknown_arm_nodes_6 nicename("Unknown Arm Nodes 6") unknown_arm_nodes_6;
	b_unknown_arm_nodes_7 nicename("Unknown Arm Nodes 7") unknown_arm_nodes_7;
	b_unknown_arm_nodes_8 nicename("Unknown Arm Nodes 8") unknown_arm_nodes_8;
	b_unknown_nodes_1 nicename("Unknown Nodes 1") unknown_nodes_1;
	b_unknown_nodes_2 nicename("Unknown Nodes 2") unknown_nodes_2;
	b_unknown_nodes_3 nicename("Unknown Nodes 3") unknown_nodes_3;
	b_unknown_nodes_4 nicename("Unknown Nodes 4") unknown_nodes_4;
	b_unknown_nodes_5 nicename("Unknown Nodes 5") unknown_nodes_5;
	b_unknown_nodes_6 nicename("Unknown Nodes 6") unknown_nodes_6;
	b_unknown_nodes_7 nicename("Unknown Nodes 7") unknown_nodes_7;
	b_unknown_nodes_8 nicename("Unknown Nodes 8") unknown_nodes_8;
	s_data_reference_legacy nicename("Last Import Results") last_import_results_data_reference;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_tag_block_legacy<s_raw_information_groups_definition> nicename("Raw Information Groups") raw_information_groups_block;
};

