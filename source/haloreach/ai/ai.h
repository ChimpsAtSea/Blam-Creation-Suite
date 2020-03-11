#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_ai_sound_volume
{
    _ai_sound_volume_silent,
    _ai_sound_volume_medium,
    _ai_sound_volume_loud,
    _ai_sound_volume_shout,
    _ai_sound_volume_quiet,
    k_number_of_ai_sound_volumes
};

/* ---------- globals */

extern s_enum_definition g_ai_sound_volume_enum;

/* ---------- prototypes/AI.CPP */

void ai_initialize();
void ai_dispose();
void ai_update();

void ai_get_center_of_mass(long object_index, s_real_point3d *center_of_mass);

/*
0001:000011dc       ??_C@_0N@PCOCHLJM@ai_update_ms?$AA@ 820017dc     ailib:ai.obj
0001:00623210       ?k_element_count@?$s_static_array@J$0JME@@@2JB 82623810     ailib:ai.obj
0001:0062338c       ?g_suppress_pathfinding_generation@@3_NB 8262398c     ailib:ai.obj
0001:0062338d       ?g_xbox_enable_pathfinding_generation@@3_NB 8262398d     ailib:ai.obj
0001:006233c8       ??_7area_definition@@6B@   826239c8     ailib:ai.obj
0001:006233e8       ??_C@_0BA@NJJFIBEC@ai_global_state?$AA@ 826239e8     ailib:ai.obj
0001:006233f8       ??_C@_0DI@KHCHJAEP@c?3?2midnight?2main?2shared?2engine?2s@ 826239f8     ailib:ai.obj
0001:00623430       ??_C@_09KDHDPDHI@activated?$AA@ 82623a30     ailib:ai.obj
0001:0062343c       ??_C@_0BI@KOPOELHB@?$CIHavokAIManager?3?3Get?$CI?$CJ?$CJ?$AA@ 82623a3c     ailib:ai.obj
0001:00623454       __real@44250000            82623a54     ailib:ai.obj
0001:00623458       __real@44570000            82623a58     ailib:ai.obj
0001:0062345c       ??_C@_0CO@KJNLMFOL@?$FLA?3?$CFd?$CII?3?$CFd?$CJ?$FN?5?$FLB?3?$CFd?$FN?5?$FLV?3?$CFd?$CIT?3?$CFd?$CJ?$FN@ 82623a5c     ailib:ai.obj
0001:0062348c       ??_C@_0BD@EGGKHNDN@ai_general_systems?$AA@ 82623a8c     ailib:ai.obj
0001:006234a0       ??_C@_06BLHKMLKP@AI_upd?$AA@ 82623aa0     ailib:ai.obj
0001:006234a8       ??_C@_09EPLOMCJK@ai_update?$AA@ 82623aa8     ailib:ai.obj
0001:006234b4       ??_C@_09KHCGFOIA@?$CFd?5swarms?$AA@ 82623ab4     ailib:ai.obj
0001:006234c0       ??_C@_0EF@INALGHA@working_memory_size?5?$DO?$DN?5sizeof?$CIst@ 82623ac0     ailib:ai.obj
0001:00623508       ??_C@_08DLMOHGLB@squad?5?$CFs?$AA@ 82623b08     ailib:ai.obj
0001:00623514       ??_C@_0BD@MBCKHMLH@squadless?9actor?5?$CFs?$AA@ 82623b14     ailib:ai.obj
0001:00623528       ??_C@_0BG@HDPACBCC@ai_test_line_of_sight?$AA@ 82623b28     ailib:ai.obj
0001:00623540       ??_C@_09GJNOGJEM@LOF?5?9?5Geo?$AA@ 82623b40     ailib:ai.obj
0001:00623550       ??_C@_0GD@LMJKKAEK@ai_test_ballistic_line_of_fire?5i@ 82623b50     ailib:ai.obj
0001:006235b4       ??_C@_0BG@HKLCNLF@?$CINONE?5?$CB?$DN?5actor_index?$CJ?$AA@ 82623bb4     ailib:ai.obj
0001:006235cc       ??_C@_0BP@HNEPOGCD@ai_test_ballistic_line_of_fire?$AA@ 82623bcc     ailib:ai.obj
0001:006235ec       ??_C@_0BF@LNMCPFNG@betrayal?9glance?9time?$AA@ 82623bec     ailib:ai.obj
0001:00623604       ??_C@_0BL@OHNCFKEK@general_properties?4valid?$CI?$CJ?$AA@ 82623c04     ailib:ai.obj
0001:00623620       ??_C@_0CI@COCLKLAG@allegiance?5between?5teams?5?$CFs?5and?5@ 82623c20     ailib:ai.obj
0001:00623648       ??_C@_08ELLPFBJE@reformed?$AA@ 82623c48     ailib:ai.obj
0001:00623654       ??_C@_0N@PLDCHNDI@?5permanently?$AA@ 82623c54     ailib:ai.obj
0001:00623664       ??_C@_0BE@EACLALIK@equipment_noise_def?$AA@ 82623c64     ailib:ai.obj
0001:00623678       ??_C@_0CB@MHDIOFEI@?$CInoisemakerAbilityIndex?5?$CB?$DN?5NONE?$CJ@ 82623c78     ailib:ai.obj
0001:0062369c       ??_C@_0CO@FFGEDJJG@AI?5WARNING?5Invalid?5danger?5level?5@ 82623c9c     ailib:ai.obj
0001:006236d0       ??_C@_0FG@JFFKENBE@cannot?5create?5mounted?5weapons?5fo@ 82623cd0     ailib:ai.obj
0001:00623728       ??_C@_0DA@IJAAAEIG@ai_global_state?9?$DOmounted_weapon_@ 82623d28     ailib:ai.obj
0001:00623758       ??_C@_0HA@HDPAANLA@VALID_COUNT?$CIai_global_state?9?$DOmou@ 82623d58     ailib:ai.obj
0001:006237c8       ??_C@_0BB@DEPIBEEA@?$CK?$CK?$CK?5AI?5Reset?5?$CK?$CK?$CK?$AA@ 82623dc8     ailib:ai.obj
0001:006237dc       ??_C@_0DB@KLLIBAMI@effect_type?$DO?$DN0?5?$CG?$CG?5effect_type?$DMk_@ 82623ddc     ailib:ai.obj
0001:00623810       ??_C@_0CN@INCLPMLC@volume?$DO?$DN0?5?$CG?$CG?5volume?$DMk_ai_sound_v@ 82623e10     ailib:ai.obj
0001:00623840       ??_C@_0CB@FMOOJNDC@character_definition_index?$CB?$DNNONE@ 82623e40     ailib:ai.obj
0001:00623864       ??_C@_0BF@BDHLINKJ@Ran?5out?5of?5spawners?4?$AA@ 82623e64     ailib:ai.obj
0001:00623880       ??_C@_0EN@KGPGOCFG@?$CIdistance_to_effect?5?$DO?$DN?50?$CJ?5?$CG?$CG?5?$CIdi@ 82623e80     ailib:ai.obj
0001:006238d0       ??_C@_06GFOOFMKH@?$CFs?1?$CFs?5?$AA@ 82623ed0     ailib:ai.obj
0001:006238d8       ??_C@_0L@KHOCBAML@squadless?5?$AA@ 82623ed8     ailib:ai.obj
0001:006238e4       ??_7?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@6B@ 82623ee4     ailib:ai.obj
0005:000503c0       ?ai_get_center_of_mass@@YAXJPATreal_point3d@@@Z 828403c0 f   ailib:ai.obj
0005:000b71b8       ?ai_update@@YAXXZ          828a71b8 f   ailib:ai.obj
0005:000c6d70       ?ai_test_line_of_sight@@YAFJPBTreal_point3d@@Us_cluster_reference@@01F_NJJ22PAJPA_N@Z 828b6d70 f   ailib:ai.obj
0005:001abc38       ?ai_test_line_of_sight@@YAFJPBTreal_point3d@@Us_cluster_reference@@01F_NJJ22PAJPA_NPAT1@@Z 8299bc38 f   ailib:ai.obj
0005:002419f0       ?ai_chance_this_tick@@YAMM@Z 82a319f0 f   ailib:ai.obj
0005:03389a48       ?RealPointMin@?A0xdbe281ef@@YA?ATreal_point3d@@ABT2@0@Z 85b79a48 f   ailib:ai.obj
0005:03389ad8       ?RealPointMax@?A0xdbe281ef@@YA?ATreal_point3d@@ABT2@0@Z 85b79ad8 f   ailib:ai.obj
0005:03389b68       ?__tls_set_g_ai_globals_allocator@@YAXPAX@Z 85b79b68 f   ailib:ai.obj
0005:03389b80       ?visual_studio_is_the_greatest_piece_of_software_ever_exclamation_mark@@YAXXZ 85b79b80 f   ailib:ai.obj
0005:03389cd0       ??0c_character_engage_properties_internal@@QAA@XZ 85b79cd0 f i ailib:ai.obj
0005:03389d00       ??0area_definition@@QAA@XZ 85b79d00 f i ailib:ai.obj
0005:03389d48       ??1area_definition@@UAA@XZ 85b79d48 f i ailib:ai.obj
0005:03389d70       ??0c_uncover_state_data@@QAA@XZ 85b79d70 f i ailib:ai.obj
0005:03389da0       ??0c_fight_state_data@@QAA@XZ 85b79da0 f i ailib:ai.obj
0005:03389dd0       ??0c_obey_state_data@@QAA@XZ 85b79dd0 f i ailib:ai.obj
0005:03389e00       ??0c_enter_vehicle_state_data@@QAA@XZ 85b79e00 f i ailib:ai.obj
0005:03389e30       ??0c_flee_state_data@@QAA@XZ 85b79e30 f i ailib:ai.obj
0005:03389e60       ??0c_guard_state_data@@QAA@XZ 85b79e60 f i ailib:ai.obj
0005:03389e90       ??0s_task_record@@QAA@XZ   85b79e90 f i ailib:ai.obj
0005:03389ec0       ??0c_cover_state_data@@QAA@XZ 85b79ec0 f i ailib:ai.obj
0005:03389ef0       ??0c_sync_attack_state_data@@QAA@XZ 85b79ef0 f i ailib:ai.obj
0005:03389f28       ??0c_presearch_data@@QAA@XZ 85b79f28 f i ailib:ai.obj
0005:03389f58       ??0c_search_state_data@@QAA@XZ 85b79f58 f i ailib:ai.obj
0005:03389f88       ??0actor_debug_info@@QAA@XZ 85b79f88 f i ailib:ai.obj
0005:03389fc8       ??_Garea_definition@@UAAPAXI@Z 85b79fc8 f i ailib:ai.obj
0005:03389fc8       ??_Earea_definition@@UAAPAXI@Z 85b79fc8 f i ailib:ai.obj
0005:0338a010       ??0c_behavior_state@@QAA@XZ 85b7a010 f i ailib:ai.obj
0005:0338a040       ??0s_behavior_input@@QAA@XZ 85b7a040 f i ailib:ai.obj
0005:0338a070       ?ai_initialize@@YAXXZ      85b7a070 f   ailib:ai.obj
0005:0338a198       ?ai_dispose@@YAXXZ         85b7a198 f   ailib:ai.obj
0005:0338a1d8       ?ai_initialize_for_new_map@@YAXXZ 85b7a1d8 f   ailib:ai.obj
0005:0338a288       ?ai_dispose_from_old_map@@YAXXZ 85b7a288 f   ailib:ai.obj
0005:0338a328       ?ai_initialize_for_new_structure_bsp@@YAXK@Z 85b7a328 f   ailib:ai.obj
0005:0338a6b0       ?ai_dispose_from_old_structure_bsp@@YAXK@Z 85b7a6b0 f   ailib:ai.obj
0005:0338a7e8       ?ai_initialize_for_saved_game@@YAXJ@Z 85b7a7e8 f   ailib:ai.obj
0005:0338a828       ?ai_place@@YAXW4e_game_mode@@@Z 85b7a828 f   ailib:ai.obj
0005:0338a888       ?actor_resurrection_biped_safe@@YA_NJ@Z 85b7a888 f   ailib:ai.obj
0005:0338ab60       ?ai_adjust_damage@@YA_NJJPAUs_damage_data@@PAM@Z 85b7ab60 f   ailib:ai.obj
0005:0338b130       ?ai_erase@@YAXJ_N@Z        85b7b130 f   ailib:ai.obj
0005:0338b208       ?ai_release_inactive_swarms@@YAJJPAEJPA_NPADJ@Z 85b7b208 f   ailib:ai.obj
0005:0338b468       ?ai_find_inactive_squads@@YAXJPAEJ@Z 85b7b468 f   ailib:ai.obj
0005:0338b808       ?ai_release_inactive_squads@@YAJJPAEJPA_NPADJ@Z 85b7b808 f   ailib:ai.obj
0005:0338bbd0       ?ai_find_location@@YA_NPBTreal_point3d@@PAUs_location@@@Z 85b7bbd0 f   ailib:ai.obj
0005:0338bc28       ?ai_test_line_of_fire@@YA_NJJPBTreal_point3d@@PBTvector3d@@PAJ@Z 85b7bc28 f   ailib:ai.obj
0005:0338c3d8       ?ai_test_line_of_fire_geometry@@YA_NJJMPBTreal_point3d@@0@Z 85b7c3d8 f   ailib:ai.obj
0005:0338c5d0       ??0AIDebugLineOfSightDesc@@QAA@PBD@Z 85b7c5d0 f i ailib:ai.obj
0005:0338c608       ??1AIDebugLineOfSightDesc@@QAA@XZ 85b7c608 f i ailib:ai.obj
0005:0338c628       ?ai_test_ballistic_line_of_fire@@YA_N_NJPBTreal_point3d@@MPBTvector3d@@MJ0@Z 85b7c628 f   ailib:ai.obj
0005:0338cdd0       ?ai_try_vehicle_eviction@@YA_NJJ_N@Z 85b7cdd0 f   ailib:ai.obj
0005:0338cfc8       ?ai_get_situation_danger_score@@YAMJ@Z 85b7cfc8 f   ailib:ai.obj
0005:0338d1a0       ?ai_get_weapon_score@@YAMJJM@Z 85b7d1a0 f   ailib:ai.obj
0005:0338d5d8       ?ai_get_unit_responsible_for_damage@@YAJJ_N@Z 85b7d5d8 f   ailib:ai.obj
0005:0338d738       ?ai_handle_death@@YAXJJFJMM@Z 85b7d738 f   ailib:ai.obj
0005:0338e238       ?ai_handle_targetable_object_allegiance_change@@YAXJW4e_campaign_team@@@Z 85b7e238 f   ailib:ai.obj
0005:0338e3e8       ?ai_handle_allegiance_status_changed@@YAXW4e_campaign_team@@0_N11@Z 85b7e3e8 f   ailib:ai.obj
0005:0338e738       ?ai_update_team_status@@YAXXZ 85b7e738 f   ailib:ai.obj
0005:0338e888       ?ai_get_active_clusters@@YA_NJPAKJ@Z 85b7e888 f   ailib:ai.obj
0005:0338ea30       ?ai_handle_bump@@YAXJJPBTvector3d@@@Z 85b7ea30 f   ailib:ai.obj
0005:0338eb48       ?ai_handle_noisemaker@@YAXJ@Z 85b7eb48 f   ailib:ai.obj
0005:0338edd0       ?ai_handle_equipment_release@@YAXJJ@Z 85b7edd0 f   ailib:ai.obj
0005:0338ef88       ?ai_handle_damage@@YAXJJFJMMPBTvector3d@@_N@Z 85b7ef88 f   ailib:ai.obj
0005:0338f398       ?ai_handle_stun@@YAXJMPBTvector3d@@@Z 85b7f398 f   ailib:ai.obj
0005:0338f420       ?ai_handle_projectile_attach@@YAXJJ@Z 85b7f420 f   ailib:ai.obj
0005:0338f578       ?ai_danger_level@@YAMF@Z   85b7f578 f   ailib:ai.obj
0005:0338f7d0       ?ai_chance_in_delta_time@@YAMMM@Z 85b7f7d0 f   ailib:ai.obj
0005:0338f8a8       ?ai_create_mounted_weapons_for_unit@@YAXJ@Z 85b7f8a8 f   ailib:ai.obj
0005:0338faa0       ?ai_handle_deleted_object@@YAXJ@Z 85b7faa0 f   ailib:ai.obj
0005:03390178       ?ai_handle_squad_editing@@YAXXZ 85b80178 f   ailib:ai.obj
0005:03390198       ?ai_reset@@YAXXZ           85b80198 f   ailib:ai.obj
0005:033901c8       ?ai_shutdown@@YA_NXZ       85b801c8 f   ailib:ai.obj
0005:03390330       ?ai_startup@@YAXXZ         85b80330 f   ailib:ai.obj
0005:03390360       ?ai_handle_unit_effect@@YAXJW4e_sound_type@@W4e_ai_sound_volume@@@Z 85b80360 f   ailib:ai.obj
0005:03390688       ?ai_handle_weapon_trade@@YAXJJJJ@Z 85b80688 f   ailib:ai.obj
0005:033906e0       ?ai_handle_get_attention@@YAXJJ@Z 85b806e0 f   ailib:ai.obj
0005:03390728       ?ai_handle_effect_creation@@YAXJFJFMMPBUreal_matrix4x3@@0@Z 85b80728 f   ailib:ai.obj
0005:03390a30       ??0actor_spawn_definition@@QAA@XZ 85b80a30 f i ailib:ai.obj
0005:03390a60       ?ai_enemies_can_see_player@@YA_NPAJ@Z 85b80a60 f   ailib:ai.obj
0005:03391300       ?ai_enemies_attacking_players@@YA_NPAJPAK@Z 85b81300 f   ailib:ai.obj
0005:03391388       ?ai_should_target_object@@YA_NW4e_campaign_team@@J@Z 85b81388 f   ailib:ai.obj
0005:03391538       ?ai_handle_spatial_effect@@YAXJPBTreal_point3d@@FFF@Z 85b81538 f   ailib:ai.obj
0005:03391ce8       ?ai_handle_projectile_impact@@YAXJJABTreal_point3d@@@Z 85b81ce8 f   ailib:ai.obj
0005:03391d38       ?ai_verify_tags@@YAXXZ     85b81d38 f   ailib:ai.obj
0005:03391de8       ?ai_describe_actor@@YAPADJJ_NPADJ@Z 85b81de8 f   ailib:ai.obj
0005:03392098       ?ai_test_spawn_conditions@@YA_NPBUs_ai_spawn_conditions@@@Z 85b82098 f   ailib:ai.obj
0005:03392130       ?get_datum@?$c_data_iterator@Utracking_datum@@@@QBAPAUtracking_datum@@XZ 85b82130 f i ailib:ai.obj
0005:03392140       ??0?$Reference@Uprojectile_definition@@@Tag@@QAA@XZ 85b82140 f i ailib:ai.obj
0005:03392170       ??8?$c_enum_no_init@W4e_actor_lod@@E$00$03Us_default_enum_string_resolver@@$00@@QBA_NW4e_actor_lod@@@Z 85b82170 f i ailib:ai.obj
0005:03392198       ?reserve_memory@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@QAAPAXPBD0IJ@Z 85b82198 f i ailib:ai.obj
0005:03392280       ?full@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QBA_NXZ 85b82280 f i ailib:ai.obj
0005:03392320       ?GetCount@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QBAJXZ 85b82320 f i ailib:ai.obj
0005:03392330       ?push@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAAJXZ 85b82330 f i ailib:ai.obj
0005:033923e0       ??A?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAAAAUline_of_fire_pill@@J@Z 85b823e0 f i ailib:ai.obj
0005:03392488       ?get_top@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAAPAUline_of_fire_pill@@XZ 85b82488 f i ailib:ai.obj
0005:033924c0       ?begin@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAAPAUline_of_fire_pill@@XZ 85b824c0 f i ailib:ai.obj
0005:033924d0       ?end@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAAPAUline_of_fire_pill@@XZ 85b824d0 f i ailib:ai.obj
0005:033924f0       ??0?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAA@XZ 85b824f0 f i ailib:ai.obj
0005:03392508       ?get_datum@?$c_data_iterator@Uprop_ref_datum@@@@QBAPAUprop_ref_datum@@XZ 85b82508 f i ailib:ai.obj
0005:03392518       ?valid@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@QBA_NXZ 85b82518 f i ailib:ai.obj
0005:033925a0       ?valid@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QBA_NXZ 85b825a0 f i ailib:ai.obj
0005:033925e8       ?valid@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QBA_NJ@Z 85b825e8 f i ailib:ai.obj
0005:033926b0       ?top@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QBAJXZ 85b826b0 f i ailib:ai.obj
0005:03392748       ?get@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QAAPAUline_of_fire_pill@@J@Z 85b82748 f i ailib:ai.obj
0005:033927f0       ?empty@?$c_static_stack@Uline_of_fire_pill@@$0CA@@@QBA_NXZ 85b827f0 f i ailib:ai.obj
0005:03392890       ??0?$c_flags@W4e_task_record_flags@@G$0L@Us_default_enum_string_resolver@@@@QAA@XZ 85b82890 f i ailib:ai.obj
0005:03392928       ??$?AH@?$s_static_array@G$0CAA@@@QAAAAGH@Z 85b82928 f i ailib:ai.obj
0005:033929c8       ??0?$c_flags@W4e_debug_behavior_failure_flags@@G$08Us_default_enum_string_resolver@@@@QAA@XZ 85b829c8 f i ailib:ai.obj
0005:03392a60       ?test@?$c_flags_no_init@W4e_squad_runtime_flags@@F$0BA@Us_default_enum_string_resolver@@@@QBA_NW4e_squad_runtime_flags@@@Z 85b82a60 f i ailib:ai.obj
0005:03392b28       ?clear@?$c_flags_no_init@W4e_task_record_flags@@G$0L@Us_default_enum_string_resolver@@@@QAAXXZ 85b82b28 f i ailib:ai.obj
0005:03392b40       ?is_clear@?$c_flags_no_init@W4e_task_record_flags@@G$0L@Us_default_enum_string_resolver@@@@QBA_NXZ 85b82b40 f i ailib:ai.obj
0005:03392b90       ??$valid@H@?$s_static_array@G$0CAA@@@SA_NH@Z 85b82b90 f i ailib:ai.obj
0005:03392bd0       ?clear@?$c_flags_no_init@W4e_debug_behavior_failure_flags@@G$08Us_default_enum_string_resolver@@@@QAAXXZ 85b82bd0 f i ailib:ai.obj
0005:03392be8       ?is_clear@?$c_flags_no_init@W4e_debug_behavior_failure_flags@@G$08Us_default_enum_string_resolver@@@@QBA_NXZ 85b82be8 f i ailib:ai.obj
0005:03392c38       ?valid_bit@?$c_flags_no_init@W4e_squad_runtime_flags@@F$0BA@Us_default_enum_string_resolver@@@@SA_NW4e_squad_runtime_flags@@@Z 85b82c38 f i ailib:ai.obj
0005:03392c80       ?flag_size_type@?$c_flags_no_init@W4e_squad_runtime_flags@@F$0BA@Us_default_enum_string_resolver@@@@CAFW4e_squad_runtime_flags@@@Z 85b82c80 f i ailib:ai.obj
0005:03392ca0       ?make_mask_with_all_valid_bits_on_size_type@?$c_flags_no_init@W4e_task_record_flags@@G$0L@Us_default_enum_string_resolver@@@@CAGXZ 85b82ca0 f i ailib:ai.obj
0005:03392cd0       ?make_mask_with_all_valid_bits_on_size_type@?$c_flags_no_init@W4e_debug_behavior_failure_flags@@G$08Us_default_enum_string_resolver@@@@CAGXZ 85b82cd0 f i ailib:ai.obj
0005:03392d00       ?make_N_bit_mask_size_type@?$c_flags_no_init@W4e_task_record_flags@@G$0L@Us_default_enum_string_resolver@@@@CAGW4e_task_record_flags@@@Z 85b82d00 f i ailib:ai.obj
0005:03392d30       ?make_N_bit_mask_size_type@?$c_flags_no_init@W4e_debug_behavior_failure_flags@@G$08Us_default_enum_string_resolver@@@@CAGW4e_debug_behavior_failure_flags@@@Z 85b82d30 f i ailib:ai.obj
0005:03392d60       ?collision_test_flags_and@@YA?AUs_collision_test_flags@@U1@0@Z 85b82d60 f i ailib:ai.obj
0005:03392db8       ?collision_test_flags_invert@@YA?AUs_collision_test_flags@@U1@@Z 85b82db8 f i ailib:ai.obj
0005:03392e08       ??3area_definition@@SAXPAX@Z 85b82e08 f i ailib:ai.obj
0005:03392e90       ?get_object_index@prop_datum@@QBAJXZ 85b82e90 f i ailib:ai.obj
0005:03392ea0       ??S?$c_flags_no_init@W4e_collision_test_flag@@K$0BO@Us_default_enum_string_resolver@@@@QBA?AV0@XZ 85b82ea0 f i ailib:ai.obj
0005:03392ef8       ??I?$c_flags_no_init@W4e_collision_test_flag@@K$0BO@Us_default_enum_string_resolver@@@@QBA?AV0@ABV0@@Z 85b82ef8 f i ailib:ai.obj
0005:03392f50       ??I?$c_flags_no_init@W4e_collision_test_objects_flag@@K$0BC@Us_default_enum_string_resolver@@@@QBA?AV0@ABV0@@Z 85b82f50 f i ailib:ai.obj
0005:03392fa8       ??0?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@QAA@XZ 85b82fa8 f i ailib:ai.obj
0005:03393000       ?allocate@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@UAAPAXIPBDJ000@Z 85b83000 f i ailib:ai.obj
0005:03393050       ?deallocate@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@UAAXPAXPBDJ@Z 85b83050 f i ailib:ai.obj
0005:03393088       ?free_memory@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@QAAXXZ 85b83088 f i ailib:ai.obj
0005:03393198       ??1?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@QAA@XZ 85b83198 f i ailib:ai.obj
000a:025ae170       ?g_detailedPixAiEnabled@@3_NA 88be3d70     ailib:ai.obj
000a:025ae174       ?display_basic_counters@@3JA 88be3d74     ailib:ai.obj
000a:025ae18c       ?g_ai_globals_allocator@@3V?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_globals_allocator@@YAXPAX@Z@@A 88be3d8c     ailib:ai.obj
000b:000012c8       ?ai_global_state@@3PAUs_ai_global_state@@A 88d22ac8     ailib:ai.obj
0005:0338b778       ?compare_releasable_inactive_squads@@YA_NPBX00@Z 85b7b778 f   ailib:ai.obj
0005:0338be60       ?ai_find_line_of_fire_friend_pills@@YAXJPAV?$c_static_stack@Uline_of_fire_pill@@$0CA@@@@Z 85b7be60 f   ailib:ai.obj
0005:0338c2d0       ?ai_generate_line_of_fire_pill@@YAXJJMPAUline_of_fire_pill@@@Z 85b7c2d0 f   ailib:ai.obj
0005:03390ad8       ?actor_endangering_player@@YAJ_N0PAK@Z 85b80ad8 f   ailib:ai.obj
0005:033914a0       ?ai_flush_spatial_effects@@YAXXZ 85b814a0 f   ailib:ai.obj
0005:03d7f1a8       ??__Ek_log_complex_geometry_edge_length_cutoff@@YAXXZ 8656f1a8 f   ailib:ai.obj
0005:03d7f1d8       ??__Ek_log_complex_geometry_edge_length_max@@YAXXZ 8656f1d8 f   ailib:ai.obj
0005:03d7f208       ??__Ek_log_complex_geometry_edge_length_min@@YAXXZ 8656f208 f   ailib:ai.obj
0005:03d7f238       ??__Ek_vehicle_suspension_inverse_ray_test_overcast_factor@@YAXXZ 8656f238 f   ailib:ai.obj
0005:03d7f258       ??__Ek_indentity_azimuth_image@@YAXXZ 8656f258 f   ailib:ai.obj
0005:03d7f298       ??__Ek_MaximumNavPointDistanceSquared@@YAXXZ 8656f298 f   ailib:ai.obj
0005:03d7f2b8       ??__Eg_ai_globals_allocator@@YAXXZ 8656f2b8 f   ailib:ai.obj
0005:03d7f2f0       ??__Eai_update_stop_watch@@YAXXZ 8656f2f0 f   ailib:ai.obj
0005:03e167c0       ??__Fg_ai_globals_allocator@@YAXXZ 866067c0 f   ailib:ai.obj
0005:03e167e8       ??__Fai_update_stop_watch@@YAXXZ 866067e8 f   ailib:ai.obj
*/