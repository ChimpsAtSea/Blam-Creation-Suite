#pragma once

#include <cseries/cseries.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_ai_equipment_trait_appearance_active_camo_choices
{
	_ai_equipment_trait_appearance_active_camo_unchanged,
	_ai_equipment_trait_appearance_active_camo_off,
	_ai_equipment_trait_appearance_active_camo_poor,
	_ai_equipment_trait_appearance_active_camo_good,
	_ai_equipment_trait_appearance_active_camo_excellent,
	_ai_equipment_trait_appearance_active_camo_invisible,
	k_number_of_ai_equipment_trait_appearance_active_camo_choices
};

struct s_ai_equipment_trait_appearance
{
	c_enum<e_ai_equipment_trait_appearance_active_camo_choices, char> active_camo;
	char : 8;
	char : 8;
	char : 8;
};
static_assert(sizeof(s_ai_equipment_trait_appearance) == 0x4);

struct s_ai_equipment_traits
{
	c_typed_tag_block<s_ai_equipment_trait_appearance> appearance_traits;
};
static_assert(sizeof(s_ai_equipment_traits) == 0xC);

/* ---------- prototypes/AI_TRAITS.CPP */

/*
0001:00630a64       ??_C@_0BM@LFJAACMC@no?5AI?5globals?0?5this?5is?5bad?$CB?$AA@ 82631064     ailib:ai_traits.obj
0001:00630a80       ??_C@_0CG@OEKALOGO@no?5traits?5block?5defined?5for?5visi@ 82631080     ailib:ai_traits.obj
0001:00630aa8       ??_C@_0BA@KFGKEFGB@ai_globals_data?$AA@ 826310a8     ailib:ai_traits.obj
0001:00630ab8       ??_C@_0DP@PNINLDEO@c?3?2midnight?2main?2shared?2engine?2s@ 826310b8     ailib:ai_traits.obj
0001:00630af8       ??_C@_0CF@PFDBCLDH@no?5traits?5block?5defined?5for?5soun@ 826310f8     ailib:ai_traits.obj
0001:00630b20       ??_C@_0CE@PELFDICC@no?5traits?5block?5defined?5for?5luck@ 82631120     ailib:ai_traits.obj
0001:00630b44       ??_C@_0CH@OJGHIJHD@no?5traits?5block?5defined?5for?5gren@ 82631144     ailib:ai_traits.obj
0005:001d1e10       ?checksum@c_ai_traits@@QBAJJ@Z 829c1e10 f   ailib:ai_traits.obj
0005:0025eec0       ?get_luck_traits@c_ai_traits@@QAAPBUs_ai_globals_trait_luck_definition@@XZ 82a4eec0 f   ailib:ai_traits.obj
0005:0025f1c8       ?get_grenade_traits@c_ai_traits@@QAAPBUs_ai_globals_trait_grenade_definition@@XZ 82a4f1c8 f   ailib:ai_traits.obj
0005:00278c30       ?get_weapon_traits@c_ai_traits@@QBA?AV?$c_enum@W4e_ai_trait_weapon@@E$0A@$03Us_default_enum_string_resolver@@$0A@@@XZ 82a68c30 f   ailib:ai_traits.obj
0005:00280b28       ?set@c_ai_traits@@QAAXPBV1@_N@Z 82a70b28 f   ailib:ai_traits.obj
0005:034236d0       ?clear@c_ai_traits@@QAAXXZ 85c136d0 f   ailib:ai_traits.obj
0005:034237d0       ?set_defaults@c_ai_traits@@QAAXXZ 85c137d0 f   ailib:ai_traits.obj
0005:034237f8       ?setFromTag@c_ai_traits@@QAAXPBUs_game_engine_ai_traits@@_N@Z 85c137f8 f   ailib:ai_traits.obj
0005:03423ae8       ?get_vision_traits@c_ai_traits@@QAAPBUs_ai_globals_trait_vision_definition@@XZ 85c13ae8 f   ailib:ai_traits.obj
0005:03423df0       ?get_sound_traits@c_ai_traits@@QAAPBUs_ai_globals_trait_sound_definition@@XZ 85c13df0 f   ailib:ai_traits.obj
0005:034240f8       ?get_equipment_drop@c_ai_traits@@QBA_NXZ 85c140f8 f   ailib:ai_traits.obj
0005:03424158       ?get_assassination_immunity@c_ai_traits@@QBA_NXZ 85c14158 f   ailib:ai_traits.obj
0005:034241b8       ?get_headshot_immunity@c_ai_traits@@QBA_NXZ 85c141b8 f   ailib:ai_traits.obj
0005:03424218       ?get_damage_resistance_percentage@c_ai_traits@@QBAMXZ 85c14218 f   ailib:ai_traits.obj
0005:03424278       ?get_damage_modifier_percentage@c_ai_traits@@QBAMXZ 85c14278 f   ailib:ai_traits.obj
0005:034242d8       ??B?$c_enum_no_init@W4e_damage_resistance_percentage_setting@@E$0A@$0N@Us_default_enum_string_resolver@@$0A@@@QBA?AW4e_damage_resistance_percentage_setting@@XZ 85c142d8 f i ailib:ai_traits.obj
0005:034242e8       ??B?$c_enum_no_init@W4e_damage_modifier_percentage_setting@@E$0A@$0N@Us_default_enum_string_resolver@@$0A@@@QBA?AW4e_damage_modifier_percentage_setting@@XZ 85c142e8 f i ailib:ai_traits.obj
0005:034242f8       ?get_value@?$c_game_engine_option_real@Us_damage_resistance_option_metadata@@@@QBAMXZ 85c142f8 f i ailib:ai_traits.obj
0005:03424338       ?initialize@?$c_game_engine_option@Us_damage_resistance_option_metadata@@@@QAAXXZ 85c14338 f i ailib:ai_traits.obj
0005:03424370       ?get_value@?$c_game_engine_option_real@Us_damage_modifier_option_metadata@@@@QBAMXZ 85c14370 f i ailib:ai_traits.obj
0005:034243b0       ?initialize@?$c_game_engine_option@Us_damage_modifier_option_metadata@@@@QAAXXZ 85c143b0 f i ailib:ai_traits.obj
0005:034243e8       ?get_vision_traits_block_index@c_ai_traits@@QBAFXZ 85c143e8 f i ailib:ai_traits.obj
0005:03424448       ?get_sound_traits_block_index@c_ai_traits@@QBAFXZ 85c14448 f i ailib:ai_traits.obj
0005:034244b8       ?get_luck_traits_block_index@c_ai_traits@@QBAFXZ 85c144b8 f i ailib:ai_traits.obj
0005:03424528       ?get_grenade_traits_block_index@c_ai_traits@@QBAFXZ 85c14528 f i ailib:ai_traits.obj
*/
