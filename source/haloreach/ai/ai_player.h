#pragma once

/*
0001:00000af0       __real@3f5db22d            820010f0     ailib:ai_player.obj
0001:00629560       ??_C@_0N@FEBEDAJJ@g_ai_players?$AA@ 82629b60     ailib:ai_player.obj
0001:00629570       ??_C@_0DP@CHNAEGD@c?3?2midnight?2main?2shared?2engine?2s@ 82629b70     ailib:ai_player.obj
0001:006295b0       ??_C@_0CC@NMLKHFDB@unable?5to?5create?5AI?5player?5state@ 82629bb0     ailib:ai_player.obj
0001:006295d4       ??_C@_0CJ@BCGKGFMF@player_state?9?$DOplayer_index?$CB?$DNplay@ 82629bd4     ailib:ai_player.obj
0001:00629600       ??_C@_0BP@DLJNFBJ@found_player_state_index?$CB?$DNNONE?$AA@ 82629c00     ailib:ai_player.obj
0001:00629620       ??_C@_0BP@KDMHCDKD@found_player_state_index?$DN?$DNNONE?$AA@ 82629c20     ailib:ai_player.obj
0001:00629640       ??_C@_0EC@JCHOIJLC@object_get_type?$CIobject_indices?$FLo@ 82629c40     ailib:ai_player.obj
0001:00629684       ??_C@_0BE@NCMODAOJ@?$CBvehicle_check_done?$AA@ 82629c84     ailib:ai_player.obj
0001:00629698       ??_C@_0EI@CFEAFPID@VALID_INDEX?$CIplayer_state_index?0?5@ 82629c98     ailib:ai_player.obj
0001:006296e0       ??_C@_0EO@NHIDAPPJ@VALID_INDEX?$CIother_player_state_i@ 82629ce0     ailib:ai_player.obj
0001:00629730       ??_C@_0DG@BCABHHG@no?5AI?5player?5state?5found?5for?5pla@ 82629d30     ailib:ai_player.obj
0001:00629768       ??_C@_0EA@PFIMCKAM@TEST_BIT?$CI_object_mask_unit?0?5obje@ 82629d68     ailib:ai_player.obj
0001:006297a8       ??_C@_0CB@HMJMGKHB@actor_player_prop_status_refresh@ 82629da8     ailib:ai_player.obj
0001:006297cc       ??_C@_0CE@KEPJPDJ@actor_player_update_combat_movem@ 82629dcc     ailib:ai_player.obj
0001:006297f0       ??_C@_0BE@LLOIJAMI@actor_player_update?$AA@ 82629df0     ailib:ai_player.obj
0001:00629804       ??_C@_0BI@HBAPNMFH@need?5vehicle?5time?3?5?$CF?42f?$AA@ 82629e04     ailib:ai_player.obj
0001:0062981c       ??_C@_0BM@FNHPBNE@ticks?5since?5threatening?3?5?$CFi?$AA@ 82629e1c     ailib:ai_player.obj
0001:00629838       ??_C@_0BJ@DCFIAFEF@ticks?5since?5shooting?3?5?$CFi?$AA@ 82629e38     ailib:ai_player.obj
0001:00629854       ??_7?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@6B@ 82629e54     ailib:ai_player.obj
0005:000d69f0       ?ai_player_state_delete@@YAXJ@Z 828c69f0 f   ailib:ai_player.obj
0005:000e5b08       ?actor_player_update_combat_movement@@YAXJ@Z 828d5b08 f   ailib:ai_player.obj
0005:00101fd8       ?ai_player_state_update@@YAXXZ 828f1fd8 f   ailib:ai_player.obj
0005:001aadf8       ?actor_player_prop_state_refresh@@YAXJJ@Z 8299adf8 f   ailib:ai_player.obj
0005:001d2a60       ?actor_player_update@@YAXJ@Z 829c2a60 f   ailib:ai_player.obj
0005:001d2ab0       ?actor_player_prop_status_refresh@@YAXJJPBTreal_point3d@@F@Z 829c2ab0 f   ailib:ai_player.obj
0005:001d2b70       ??$actor_get_character_definition_properties@Vc_character_vocalization_properties_internal@@$0BJI@@@YAXJAAV?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@@Z 829c2b70 f i ailib:ai_player.obj
0005:001d2c58       ??$actor_get_cached_character_properties@V?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@@@YA_NJJAAV?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@@Z 829c2c58 f i ailib:ai_player.obj
0005:001f5690       ?ai_players_reset@@YAXXZ   829e5690 f   ailib:ai_player.obj
0005:033e5068       ?__tls_set_g_ai_players_allocator@@YAXPAX@Z 85bd5068 f   ailib:ai_player.obj
0005:033e5160       ?ai_player_initialize@@YAXXZ 85bd5160 f   ailib:ai_player.obj
0005:033e5218       ?ai_players_initialize_for_new_map@@YAXXZ 85bd5218 f   ailib:ai_player.obj
0005:033e5220       ?ai_player_state_create@@YAXJ@Z 85bd5220 f   ailib:ai_player.obj
0005:033e5bc0       ?ai_player_state_handle_deleted_object@@YAXJ@Z 85bd5bc0 f   ailib:ai_player.obj
0005:033e5c50       ?ai_player_index_get@@YAFJ@Z 85bd5c50 f   ailib:ai_player.obj
0005:033e5cc0       ?ai_player_state_get@@YAPAUai_player_state@@J@Z 85bd5cc0 f   ailib:ai_player.obj
0005:033e5db8       ?ai_player_state_needs_vehicle@@YA_NF@Z 85bd5db8 f   ailib:ai_player.obj
0005:033e5e70       ?ai_player_get_fire_team_index@@YAJJ@Z 85bd5e70 f   ailib:ai_player.obj
0005:033e69a8       ?actor_player_is_attacking@@YA_NJPATvector3d@@@Z 85bd69a8 f   ailib:ai_player.obj
0005:033e6a80       ?actor_player_datum_available_to_current_thread@@YA_NXZ 85bd6a80 f   ailib:ai_player.obj
0005:033e6aa0       ?ai_handle_player_multikill@@YAXJ@Z 85bd6aa0 f   ailib:ai_player.obj
0005:033e6b20       ?ai_player_handle_projectile_attach@@YAXJJ@Z 85bd6b20 f   ailib:ai_player.obj
0005:033e6bd8       ?ai_player_handle_died@@YAXJ@Z 85bd6bd8 f   ailib:ai_player.obj
0005:033e6c20       ?debug_render_player_needs_vehicle@@YAXXZ 85bd6c20 f   ailib:ai_player.obj
0005:033e6da0       ?debug_render_player_battle_vector@@YAXXZ 85bd6da0 f   ailib:ai_player.obj
0005:033e6f70       ??0?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@QAA@XZ 85bd6f70 f i ailib:ai_player.obj
0005:033e6f88       ?valid@?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@QBA_NXZ 85bd6f88 f i ailib:ai_player.obj
0005:033e6f98       ?reserve_memory@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@QAAPAXPBD0IJ@Z 85bd6f98 f i ailib:ai_player.obj
0005:033e7080       ?valid@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@QBA_NXZ 85bd7080 f i ailib:ai_player.obj
0005:033e7108       ?set@?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@QAAXPBVc_character_vocalization_properties_internal@@@Z 85bd7108 f i ailib:ai_player.obj
0005:033e7168       ?invalidate@?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@QAAXXZ 85bd7168 f i ailib:ai_player.obj
0005:033e7180       ?apply_modifiers@?$c_character_properties_base@Vc_character_vocalization_properties_internal@@@@SAXPAV1@@Z 85bd7180 f i ailib:ai_player.obj
0005:033e7188       ??$character_definition_properties_get_direct@Vc_character_vocalization_properties_internal@@$0BJI@@@YAPAVc_character_vocalization_properties_internal@@JPBVc_stimulus_flags@@@Z 85bd7188 f i ailib:ai_player.obj
0005:033e7250       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@Vc_character_vocalization_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@PBVc_character_vocalization_properties_internal@@@Z 85bd7250 f i ailib:ai_player.obj
0005:033e7288       ?static_valid@?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@SA_NPAX@Z 85bd7288 f i ailib:ai_player.obj
0005:033e72b0       ??$character_definition_property_block_get@$0BJI@@@YAPAUs_tag_block@@JPBVc_stimulus_flags@@@Z 85bd72b0 f i ailib:ai_player.obj
0005:033e7360       ??0?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@QAA@XZ 85bd7360 f i ailib:ai_player.obj
0005:033e73b8       ?allocate@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@UAAPAXIPBDJ000@Z 85bd73b8 f i ailib:ai_player.obj
0005:033e7408       ?deallocate@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@UAAXPAXPBDJ@Z 85bd7408 f i ailib:ai_player.obj
0005:033e7440       ?free_memory@?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@QAAXXZ 85bd7440 f i ailib:ai_player.obj
0005:033e7550       ??1?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@QAA@XZ 85bd7550 f i ailib:ai_player.obj
000a:026c61d8       ?g_ai_players_allocator@@3V?$t_restricted_allocation_manager@$03$0A@$0A@$1?__tls_set_g_ai_players_allocator@@YAXPAX@Z@@A 88cfbdd8     ailib:ai_player.obj
000b:000012d8       ?g_ai_players@@3PAUai_player_state@@A 88d22ad8     ailib:ai_player.obj
0005:033e5080       ?ai_player_reset@@YAXJ@Z   85bd5080 f   ailib:ai_player.obj
0005:033e5430       ?ai_player_update_looking@@YAXF@Z 85bd5430 f   ailib:ai_player.obj
0005:033e5a08       ?ai_player_update_looking_state@@YAXFF_N@Z 85bd5a08 f   ailib:ai_player.obj
0005:033e5ee0       ?actor_player_update_vehicle_interest@@YAXJ@Z 85bd5ee0 f   ailib:ai_player.obj
0005:033e6780       ?actor_player_looking_update@@YAXJ@Z 85bd6780 f   ailib:ai_player.obj
0005:03d7fb98       ??__Ek_cosine45@@YAXXZ     8656fb98 f   ailib:ai_player.obj
0005:03d7fbb0       ??__Ek_cosine60@@YAXXZ     8656fbb0 f   ailib:ai_player.obj
0005:03d7fbc8       ??__Ek_vehicle_suspension_inverse_ray_test_overcast_factor@@YAXXZ 8656fbc8 f   ailib:ai_player.obj
0005:03d7fbe8       ??__Eg_ai_players_allocator@@YAXXZ 8656fbe8 f   ailib:ai_player.obj
0005:03e16928       ??__Fg_ai_players_allocator@@YAXXZ 86606928 f   ailib:ai_player.obj
*/