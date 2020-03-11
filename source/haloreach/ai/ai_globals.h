#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_ai_globals_group_tag = 'aigl';

/* ---------- types */

struct s_ai_globals_squad_template_definition
{
	// TODO
};

struct s_ai_globals_performance_template_definition
{
	// TODO
};

struct s_squad_template_iterator
{
	// TODO
};

struct s_performance_template_iterator
{
	// TODO
};

struct s_ai_globals_data
{
	// TODO
};

struct s_ai_globals_definition
{
	// TODO
};

/* ---------- globals */

extern s_tag_group g_ai_globals_group;

/* ---------- prototypes/AI_GLOBALS.CPP */

void ai_globals_initialize();
void ai_globals_initialize_for_new_map();
void ai_globals_dispose();
void ai_globals_update();

bool ai_globals_dialogue_enabled();

long ai_globals_get_formation_index(s_ai_globals_data *, int, long);

void ai_globals_squad_template_iterator_new(s_ai_globals_data *, s_squad_template_iterator *);
s_ai_globals_squad_template_definition *ai_globals_squad_template_iterator_next(s_squad_template_iterator *);

long ai_globals_get_squad_template_index(s_ai_globals_data *, long);

void ai_globals_performance_template_iterator_new(s_ai_globals_data *, s_performance_template_iterator *);
s_ai_globals_performance_template_definition *ai_globals_performance_template_iterator_next(s_performance_template_iterator *);

long ai_globals_get_performance_template_index(s_ai_globals_data *, long);

void ai_globals_resolve_references(s_ai_globals_data *);

/*
0001:00630c60       ??_C@_0EA@FCCOEKLF@c?3?2midnight?2main?2shared?2engine?2s@ 82631260     ailib:ai_globals.obj
0001:00630ca0       ??_C@_0CL@OCKDHLAB@global?5spawn?5formation?5?8?$CFs?8?5does@ 826312a0     ailib:ai_globals.obj
0001:00630ccc       ??_C@_0CK@DLFAIHAJ@global?5squad?5template?5?8?$CFs?8?5doesn@ 826312cc     ailib:ai_globals.obj
0001:00630cf8       ??_C@_0DA@IMMLLHBI@global?5performance?5template?5?8?$CFs?8@ 826312f8     ailib:ai_globals.obj
0001:00630d28       ??_C@_0CC@HFFFAEBD@g_character_properties_cache_dat@ 82631328     ailib:ai_globals.obj
0001:00630d4c       ??_C@_0BL@NAKKNHDO@character?5properties?5cache?$AA@ 8263134c     ailib:ai_globals.obj
0001:00630d68       ??_C@_0BL@DIGFMEFP@failed?5to?5load?5ai?5globals?$CB?$AA@ 82631368     ailib:ai_globals.obj
0001:00630d88       ??_C@_0EL@ONCNDFNK@ai_global_state?9?$DOmission_critica@ 82631388     ailib:ai_globals.obj
0001:00630dd4       ??_C@_0CP@KPEECGH@game_tick_rate?$CI?$CJ?$DO?$DNk_num_mission_@ 826313d4     ailib:ai_globals.obj
0001:00630e04       ??_C@_0CJ@MGHPNKKG@actor?9?$DOmeta?4properties_cache_ind@ 82631404     ailib:ai_globals.obj
0001:00630e30       ??_C@_0CJ@GGABCMBM@actor?9?$DOmeta?4properties_cache_ind@ 82631430     ailib:ai_globals.obj
0001:00630e5c       ??_C@_0BL@NNBBHKMD@ai?5globals?5not?5initialized?$AA@ 8263145c     ailib:ai_globals.obj
0001:00630e78       ??_C@_0BL@FCEEPALN@num?5full?5detail?5actors?3?5?$CFd?$AA@ 82631478     ailib:ai_globals.obj
0001:00630e98       ??_C@_0GD@IMBOHCJI@dialogue?3?5we?5currently?5only?5supp@ 82631498     ailib:ai_globals.obj
0001:00630f00       ??_C@_0GL@CFMCCBOO@dialogue?3?5we?5currently?5only?5supp@ 82631500     ailib:ai_globals.obj
0001:00630f6c       ??_7?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@6B@ 8263156c     ailib:ai_globals.obj
0005:00230a08       ?ai_globals_update@@YAXXZ  82a20a08 f   ailib:ai_globals.obj
0005:00281270       ?ai_globals_dialogue_enabled@@YA_NXZ 82a71270 f   ailib:ai_globals.obj
0005:03424598       ?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z 85c14598 f   ailib:ai_globals.obj
0005:034245d0       ?ai_globals_get_formation_index@@YAJPBUs_ai_globals_data@@HJ@Z 85c145d0 f   ailib:ai_globals.obj
0005:034247a8       ?ai_globals_squad_template_iterator_new@@YAXPBUs_ai_globals_data@@PAUs_squad_template_iterator@@@Z 85c147a8 f   ailib:ai_globals.obj
0005:03424848       ?ai_globals_squad_template_iterator_next@@YAPAUs_ai_globals_squad_template_definition@@PAUs_squad_template_iterator@@@Z 85c14848 f   ailib:ai_globals.obj
0005:03424af0       ?ai_globals_get_squad_template_index@@YAJPBUs_ai_globals_data@@J@Z 85c14af0 f   ailib:ai_globals.obj
0005:03424c90       ?ai_globals_performance_template_iterator_new@@YAXPBUs_ai_globals_data@@PAUs_performance_template_iterator@@@Z 85c14c90 f   ailib:ai_globals.obj
0005:03424d30       ?ai_globals_performance_template_iterator_next@@YAPAUs_ai_globals_performance_template_definition@@PAUs_performance_template_iterator@@@Z 85c14d30 f   ailib:ai_globals.obj
0005:03424fd8       ?ai_globals_get_performance_template_index@@YAJPBUs_ai_globals_data@@J@Z 85c14fd8 f   ailib:ai_globals.obj
0005:03425178       ?ai_globals_resolve_references@@YAXPAUs_ai_globals_data@@@Z 85c15178 f   ailib:ai_globals.obj
0005:03425180       ?ai_globals_initialize@@YAXXZ 85c15180 f   ailib:ai_globals.obj
0005:03425258       ?ai_globals_initialize_for_new_map@@YAXXZ 85c15258 f   ailib:ai_globals.obj
0005:034257f8       ?actor_teleport_state_reset@@YAXPAUai_mission_critical_actor@@@Z 85c157f8 f   ailib:ai_globals.obj
0005:034258a8       ?ai_globals_handle_deleted_actor@@YAXJ@Z 85c158a8 f   ailib:ai_globals.obj
0005:03425c60       ?ai_globals_get_traits@@YAPAVc_ai_traits@@XZ 85c15c60 f   ailib:ai_globals.obj
0005:03425d20       ?ai_globals_get_ai_active@@YA_NXZ 85c15d20 f   ailib:ai_globals.obj
0005:03425db8       ?ai_globals_set_ai_active@@YAX_N@Z 85c15db8 f   ailib:ai_globals.obj
0005:03425e58       ?ai_globals_set_fast_and_dumb@@YAX_N@Z 85c15e58 f   ailib:ai_globals.obj
0005:03425ef8       ?ai_globals_num_full_detail_actors@@YAXXZ 85c15ef8 f   ailib:ai_globals.obj
0005:034260b0       ?ai_globals_set_full_detail_actors@@YAXF@Z 85c160b0 f   ailib:ai_globals.obj
0005:03426150       ?ai_globals_grenades_enabled@@YAX_N@Z 85c16150 f   ailib:ai_globals.obj
0005:034261f0       ?ai_globals_infection_suppress@@YAXJ@Z 85c161f0 f   ailib:ai_globals.obj
0005:034262d0       ?ai_globals_dialogue_enable@@YAX_N@Z 85c162d0 f   ailib:ai_globals.obj
0005:03426370       ?ai_globals_dialogue_updating_enable@@YAX_N@Z 85c16370 f   ailib:ai_globals.obj
0005:03426410       ?ai_globals_dialogue_suppress@@YAXM@Z 85c16410 f   ailib:ai_globals.obj
0005:034264e0       ?ai_globals_player_dialogue_enable@@YAX_N@Z 85c164e0 f   ailib:ai_globals.obj
0005:03426580       ?ai_globals_player_dialogue_enabled@@YA_NXZ 85c16580 f   ailib:ai_globals.obj
0005:03426618       ?ai_globals_actor_dialogue_enable@@YAXJ_N@Z 85c16618 f   ailib:ai_globals.obj
0005:034267e8       ?ai_globals_actor_dialogue_enabled@@YA_NJ@Z 85c167e8 f   ailib:ai_globals.obj
0005:03426870       ?ai_globals_actor_dialogue_effect_enable@@YAXJ_N@Z 85c16870 f   ailib:ai_globals.obj
0005:03426a40       ?ai_globals_actor_dialogue_effect_enabled@@YA_NJ@Z 85c16a40 f   ailib:ai_globals.obj
0005:03426ac8       ?clear@?$c_flags_no_init@W4e_actor_teleport_restriction_flags@@G$04Us_default_enum_string_resolver@@@@QAAXXZ 85c16ac8 f i ailib:ai_globals.obj
0005:03426ae0       ?set@?$c_flags_no_init@W4e_actor_teleport_restriction_flags@@G$04Us_default_enum_string_resolver@@@@QAAXW4e_actor_teleport_restriction_flags@@_N@Z 85c16ae0 f i ailib:ai_globals.obj
0005:03426bd0       ?valid_bit@?$c_flags_no_init@W4e_actor_teleport_restriction_flags@@G$04Us_default_enum_string_resolver@@@@SA_NW4e_actor_teleport_restriction_flags@@@Z 85c16bd0 f i ailib:ai_globals.obj
0005:03426c18       ?flag_size_type@?$c_flags_no_init@W4e_actor_teleport_restriction_flags@@G$04Us_default_enum_string_resolver@@@@CAGW4e_actor_teleport_restriction_flags@@@Z 85c16c18 f i ailib:ai_globals.obj
0005:03426c38       ??0?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@QAA@XZ 85c16c38 f i ailib:ai_globals.obj
0005:03426c90       ?allocate@?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@UAAPAXIPBDJ000@Z 85c16c90 f i ailib:ai_globals.obj
0005:03426ce0       ?deallocate@?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@UAAXPAXPBDJ@Z 85c16ce0 f i ailib:ai_globals.obj
0005:03426d18       ?reserve_memory@?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@QAAPAXPBD0IJ@Z 85c16d18 f i ailib:ai_globals.obj
0005:03426e00       ?free_memory@?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@QAAXXZ 85c16e00 f i ailib:ai_globals.obj
0005:03426f10       ?valid@?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@QBA_NXZ 85c16f10 f i ailib:ai_globals.obj
0005:03426f98       ??1?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@QAA@XZ 85c16f98 f i ailib:ai_globals.obj
000a:026c8370       ?g_character_properties_cache_data_allocator@@3V?$t_restricted_allocation_manager@$00$0A@$0A@$1?__tls_set_g_character_properties_cache_data_allocator@@YAXPAX@Z@@A 88cfdf70     ailib:ai_globals.obj
000b:000012ec       ?g_character_properties_cache_data@@3PAUs_data_array@@A 88d22aec     ailib:ai_globals.obj
0005:03425920       ?ai_build_character_properties_cache@@YAXXZ 85c15920 f   ailib:ai_globals.obj
0005:034259a0       ?actor_refresh_character_properties_cache_entry@@YAXJ@Z 85c159a0 f   ailib:ai_globals.obj
0005:03425ae8       ?actor_new_character_properties_cache_entry@@YAXJ@Z 85c15ae8 f   ailib:ai_globals.obj
0005:03425c08       ?ai_globals_build_ai_traits@@YAXXZ 85c15c08 f   ailib:ai_globals.obj
0005:03d803e8       ??__Ek_eighth_circle@@YAXXZ 865703e8 f   ailib:ai_globals.obj
0005:03d80400       ??__Ek_log_complex_geometry_edge_length_cutoff@@YAXXZ 86570400 f   ailib:ai_globals.obj
0005:03d80430       ??__Ek_log_complex_geometry_edge_length_max@@YAXXZ 86570430 f   ailib:ai_globals.obj
0005:03d80460       ??__Ek_log_complex_geometry_edge_length_min@@YAXXZ 86570460 f   ailib:ai_globals.obj
0005:03d80490       ??__Ek_indentity_azimuth_image@@YAXXZ 86570490 f   ailib:ai_globals.obj
0005:03d804d0       ??__Ek_MaximumNavPointDistanceSquared@@YAXXZ 865704d0 f   ailib:ai_globals.obj
0005:03d804f0       ??__Eg_character_properties_cache_data_allocator@@YAXXZ 865704f0 f   ailib:ai_globals.obj
0005:03e16a18       ??__Fg_character_properties_cache_data_allocator@@YAXXZ 86606a18 f   ailib:ai_globals.obj
*/
