#pragma once

/*
0001:0000093c       __real@3f7e147b            82000f3c     ailib:actor_perception.obj
0001:00000940       __real@3b23d70b            82000f40     ailib:actor_perception.obj
0001:00000958       __real@3ba3d700            82000f58     ailib:actor_perception.obj
0001:00000a00       __real@3f680347            82001000     ailib:actor_perception.obj
0001:000041e0       ??_C@_0N@NICHOPNE@vehicle?5idle?$AA@ 820047e0     ailib:actor_perception.obj
0001:00640f4c       ??_C@_0BA@FJDBPELD@vehicle?5combat?5?$AA@ 8264154c     ailib:actor_perception.obj
0001:00640f5c       ??_C@_0O@HCHHLOAD@vehicle?5alert?$AA@ 8264155c     ailib:actor_perception.obj
0001:006410f0       ??_C@_0CB@KKFOGJCL@prop_should_refresh_status?$CIpref?$CJ@ 826416f0     ailib:actor_perception.obj
0001:00641114       ??_C@_0DF@DEPGEFKJ@VALID_INDEX?$CIpref?9?$DOtype?0?5NUMBEROF@ 82641714     ailib:actor_perception.obj
0001:0064114c       ??_C@_0CB@OIKFEPGN@pref?9?$DOactor_index?5?$DN?$DN?5actor_index@ 8264174c     ailib:actor_perception.obj
0001:00641170       ??_C@_0EG@MPDOJEOI@c?3?2midnight?2main?2shared?2engine?2s@ 82641770     ailib:actor_perception.obj
0001:006411b8       ??_C@_0BI@CGCDIKAN@actor_perception_update?$AA@ 826417b8     ailib:actor_perception.obj
0001:006411d0       ??_C@_0BJ@EBPEFDNM@?$CBtracking_prop_ref?$CIpref?$CJ?$AA@ 826417d0     ailib:actor_perception.obj
0001:006411ec       ??_C@_0BK@MABPFBEF@prop_state_machine_update?$AA@ 826417ec     ailib:actor_perception.obj
0001:00641208       ??_C@_0CK@CEMJKMMJ@Ran?5out?5of?5TRACKING_DATUMs?$CB?5?$CItel@ 82641808     ailib:actor_perception.obj
0001:00641234       ??_C@_0CK@NLCDOIJK@pref?9?$DOstatus?$CB?$DN_prop_status_unack@ 82641834     ailib:actor_perception.obj
0001:00641260       ??_C@_0BF@NJKEFODE@track_prop_ref?$CIpref?$CJ?$AA@ 82641860     ailib:actor_perception.obj
0001:00641278       ??_C@_0CF@DHAAPHMP@pref_count?5?$DM?5k_maximum_props_per@ 82641878     ailib:actor_perception.obj
0001:006412a0       ??_C@_0CA@GCHADONB@actor_acknowledged_props_update?$AA@ 826418a0     ailib:actor_perception.obj
0001:006412c0       ??_C@_0BL@HAODEENO@partial_distance_reference?$AA@ 826418c0     ailib:actor_perception.obj
0001:006412dc       ??_C@_0BI@LDALCJLP@full_distance_reference?$AA@ 826418dc     ailib:actor_perception.obj
0001:006412f4       ??_C@_0CE@OIJAMMKO@known_state?9?$DOlast_update_time?$CB?$DNN@ 826418f4     ailib:actor_perception.obj
0001:00641318       ??_C@_0BJ@NHGJHGGM@actor_prop_state_refresh?$AA@ 82641918     ailib:actor_perception.obj
0001:00641334       ??_C@_0BE@LCCFHEBO@prop_status_refresh?$AA@ 82641934     ailib:actor_perception.obj
0001:00641348       ??_C@_0BD@OIAOILBM@Perception?5?9?5Light?$AA@ 82641948     ailib:actor_perception.obj
0001:0064135c       ??_C@_0CJ@DEPEOGFN@prop_compute_light_perception_pr@ 8264195c     ailib:actor_perception.obj
0001:00641388       ??_C@_0BC@NJHBEAAB@Perception?5?9?5Full?$AA@ 82641988     ailib:actor_perception.obj
0001:0064139c       ??_C@_0CI@BLPIPPBF@prop_compute_full_perception_pro@ 8264199c     ailib:actor_perception.obj
0001:006413c4       ??_C@_0BG@EIFKEMEI@hologram?9ignore_timer?$AA@ 826419c4     ailib:actor_perception.obj
0001:006413dc       ??_C@_0BK@DMFCMEFM@hologram?9detection?9change?$AA@ 826419dc     ailib:actor_perception.obj
0001:006413f8       ??_C@_0DB@BFPCHGG@prop_unit?9?$DOunitFlags?4test?$CI_unit_@ 826419f8     ailib:actor_perception.obj
0001:0064142c       ??_C@_0BN@NDIPEIPF@prop_hologram_status_refresh?$AA@ 82641a2c     ailib:actor_perception.obj
0001:0064144c       ??_C@_0CG@CHIJKEAC@damaging_prop_ref_index?5?$CB?$DN?50x000@ 82641a4c     ailib:actor_perception.obj
0001:00641474       ??_C@_0BL@FLFJDCJH@unassailability?5expiration?$AA@ 82641a74     ailib:actor_perception.obj
0001:00641490       ??_C@_0DH@JBJEPBAJ@?$CIfireteam_weight?5?$DO?$DN?50?40f?$CJ?5?$CG?$CG?5?$CIfi@ 82641a90     ailib:actor_perception.obj
0001:006414c8       ??_C@_0DJ@NDLHBHCH@?$CIpreference_bonus?5?$DO?$DN?50?40f?$CJ?5?$CG?$CG?5?$CIp@ 82641ac8     ailib:actor_perception.obj
0001:00641504       ??_C@_0DB@NAEJHEFA@?$CItarget_bonus?5?$DO?$DN?50?40f?$CJ?5?$CG?$CG?5?$CItarge@ 82641b04     ailib:actor_perception.obj
0001:00641538       ??_C@_0DD@NIDMCDGP@?$CIstatus_weight?5?$DO?$DN?50?40f?$CJ?5?$CG?$CG?5?$CIstat@ 82641b38     ailib:actor_perception.obj
0001:0064156c       ??_C@_0DB@GKBMKJLJ@?$CIrange_weight?5?$DO?$DN?50?40f?$CJ?5?$CG?$CG?5?$CIrange@ 82641b6c     ailib:actor_perception.obj
0001:006415a0       ??_C@_0BH@KKAFIENL@actor_situation_update?$AA@ 82641ba0     ailib:actor_perception.obj
0001:006415b8       ??_C@_0DH@HFHNILFH@actor?9?$DOsituation?4highest_prop_cl@ 82641bb8     ailib:actor_perception.obj
0001:006415f0       ??_C@_0BF@DCANFHEP@combat?9idle?9vocalize?$AA@ 82641bf0     ailib:actor_perception.obj
0001:00641608       ??_C@_0FO@IBIKEBBF@VALID_INDEX?$CIg_movement_force_com@ 82641c08     ailib:actor_perception.obj
0001:00641668       ??_C@_0FG@DCMPHPIE@VALID_INDEX?$CIactor?9?$DOsituation?4hig@ 82641c68     ailib:actor_perception.obj
0001:006416c0       ??_C@_05JEANFOJL@cprop?$AA@ 82641cc0     ailib:actor_perception.obj
0001:006416c8       ??_C@_0DN@PGFKKMG@VALID_INDEX?$CIdiscovery_type?0?5k_ho@ 82641cc8     ailib:actor_perception.obj
0001:00641708       ??_C@_0BF@PCCHEMDM@actor_emotion_update?$AA@ 82641d08     ailib:actor_perception.obj
0001:00641720       ??_C@_0BF@EEIJIIIN@out_awareness_factor?$AA@ 82641d20     ailib:actor_perception.obj
0001:00641738       ??_C@_0BG@HMLIBOFE@out_perception_factor?$AA@ 82641d38     ailib:actor_perception.obj
0001:00641750       ??_C@_0BF@POOMNMCG@interested?5ticks?3?5?$CFi?$AA@ 82641d50     ailib:actor_perception.obj
0001:00641768       ??_C@_0BH@NJFJCIMO@uninterested?5ticks?3?5?$CFi?$AA@ 82641d68     ailib:actor_perception.obj
0005:0008e4f8       ?actor_perception_set_target@@YAXJJ@Z 8287e4f8 f   ailib:actor_perception.obj
0005:000c3e18       ?actor_prop_facing_category@@YAFPBTvector3d@@0M@Z 828b3e18 f   ailib:actor_perception.obj
0005:000c5c60       ?actor_has_scary_weapon@@YA_NJ@Z 828b5c60 f   ailib:actor_perception.obj
0005:000d4958       ??$actor_get_character_definition_properties@Vc_character_emotions_properties_internal@@$0JA@@@YAXJAAV?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@@Z 828c4958 f i ailib:actor_perception.obj
0005:000d5d68       ?actor_visibility_test_frustum@@YAXJPBTvector3d@@000MMPAM1PA_N@Z 828c5d68 f   ailib:actor_perception.obj
0005:000d5eb0       ?actor_visibility_at_point@@YAFJPBUactor_position_data@@PBTreal_point3d@@1M_N2PA_N3PAM@Z 828c5eb0 f   ailib:actor_perception.obj
0005:000e3bd0       ?prop_status_refresh@@YAXJJPAUactor_position_data@@PBU1@@Z 828d3bd0 f   ailib:actor_perception.obj
0005:0011c380       ?actor_perception_find_target_data@@YAXJPAUactor_position_data@@@Z 8290c380 f   ailib:actor_perception.obj
0005:0011e150       ?actor_compute_prop_salience@@YAXJJW4e_prop_stimulus@@@Z 8290e150 f   ailib:actor_perception.obj
0005:001209b0       ?actor_perception_update@@YAXJ@Z 829109b0 f   ailib:actor_perception.obj
0005:00120f68       ?actor_prop_state_refresh@@YAXJJPBUactor_position_data@@0_N@Z 82910f68 f   ailib:actor_perception.obj
0005:001222a0       ?actor_situation_update@@YAXJ@Z 829122a0 f   ailib:actor_perception.obj
0005:001226a0       ?actor_get_perception_mode@@YA?AW4e_perception_mode@@J@Z 829126a0 f   ailib:actor_perception.obj
0005:00122878       ?actor_perception_find_sense_position@@YA_NJPBTreal_point3d@@PAUactor_position_data@@@Z 82912878 f   ailib:actor_perception.obj
0005:00188980       ?actor_is_majorly_scary@@YA_NJ@Z 82978980 f   ailib:actor_perception.obj
0005:00188a90       ?actor_get_inherent_scariness@@YAMJ@Z 82978a90 f   ailib:actor_perception.obj
0005:0018a948       ?actor_perception_forget_recent_damage@@YAXJ@Z 8297a948 f   ailib:actor_perception.obj
0005:00199aa8       ?actor_emotion_update@@YAXJ@Z 82989aa8 f   ailib:actor_perception.obj
0005:001bb9c8       ??$actor_get_character_definition_properties@Vc_character_target_properties_internal@@$0MA@@@YAXJAAV?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@@Z 829ab9c8 f i ailib:actor_perception.obj
0005:001bbab0       ??$actor_get_cached_character_properties@V?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@@@YA_NJJAAV?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@@Z 829abab0 f i ailib:actor_perception.obj
0005:001cf3c8       ?actor_get_vision_distances@@YAXJMMMPAM0PA_N@Z 829bf3c8 f   ailib:actor_perception.obj
0005:002200a8       ?actor_audibility_at_point@@YAFJPBUactor_position_data@@PBTreal_point3d@@PBUs_location@@FMF@Z 82a100a8 f   ailib:actor_perception.obj
0005:034d2830       ?force_prop_position_refresh@@YAXJJ@Z 85cc2830 f   ailib:actor_perception.obj
0005:034d35b8       ?actor_perception_find_killer_prop_index@@YAJJJ_N@Z 85cc35b8 f   ailib:actor_perception.obj
0005:034d3738       ?actor_perception_find_recent_damaging_prop_ref_index@@YAJJ_N@Z 85cc3738 f   ailib:actor_perception.obj
0005:034d3950       ?actor_perception_unreachable@@YAXJJ_N0@Z 85cc3950 f   ailib:actor_perception.obj
0005:034d3a18       ?actor_perception_unassailable@@YAXJJ_N0@Z 85cc3a18 f   ailib:actor_perception.obj
0005:034d3b18       ?actor_perception_clear_unassailability@@YAXJ@Z 85cc3b18 f   ailib:actor_perception.obj
0005:034d3b78       ?actor_compute_prop_salience_all@@YAXJ@Z 85cc3b78 f   ailib:actor_perception.obj
0005:034d3bd0       ?actor_compute_prop_salience@@YAXJJ@Z 85cc3bd0 f   ailib:actor_perception.obj
0005:034d4b60       ?actor_prop_is_majorly_scary@@YA_NJ@Z 85cc4b60 f   ailib:actor_perception.obj
0005:034d4bf8       ?actor_prop_has_scary_weapon@@YA_NJ@Z 85cc4bf8 f   ailib:actor_perception.obj
0005:034d5220       ?actor_perception_discovered_hologram@@YAXJJW4e_hologram_discovery_type@@J@Z 85cc5220 f   ailib:actor_perception.obj
0005:034d5340       ?actor_perception_aiming_vector_test_blockage@@YAFPBTreal_point3d@@PBTvector3d@@0JPAT2@PAM@Z 85cc5340 f   ailib:actor_perception.obj
0005:034d5ed0       ?target_get_prop_class@@YAFPBUactor_datum@@@Z 85cc5ed0 f   ailib:actor_perception.obj
0005:034d5f48       ?debug_render_vehicle_interest@@YAXXZ 85cc5f48 f   ailib:actor_perception.obj
0005:034d6138       ??0?$c_enum@W4e_prop_stimulus@@D$0?0$03Us_default_enum_string_resolver@@$0?0@@QAA@W4e_prop_stimulus@@@Z 85cc6138 f i ailib:actor_perception.obj
0005:034d6158       ??0?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@QAA@XZ 85cc6158 f i ailib:actor_perception.obj
0005:034d6170       ??0?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@QAA@XZ 85cc6170 f i ailib:actor_perception.obj
0005:034d6188       ??$character_definition_properties_get_direct@Vc_character_target_properties_internal@@$0MA@@@YAPAVc_character_target_properties_internal@@JPBVc_stimulus_flags@@@Z 85cc6188 f i ailib:actor_perception.obj
0005:034d6250       ??$actor_get_cached_character_properties@V?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@@@YA_NJJAAV?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@@Z 85cc6250 f i ailib:actor_perception.obj
0005:034d63f8       ??$character_definition_properties_get_direct@Vc_character_emotions_properties_internal@@$0JA@@@YAPAVc_character_emotions_properties_internal@@JPBVc_stimulus_flags@@@Z 85cc63f8 f i ailib:actor_perception.obj
0005:034d64c0       ??$character_definition_property_block_get@$0MA@@@YAPAUs_tag_block@@JPBVc_stimulus_flags@@@Z 85cc64c0 f i ailib:actor_perception.obj
0005:034d6570       ??$character_definition_property_block_get@$0JA@@@YAPAUs_tag_block@@JPBVc_stimulus_flags@@@Z 85cc6570 f i ailib:actor_perception.obj
0005:034d6620       ?set_object_index@prop_datum@@QAAXJ@Z 85cc6620 f i ailib:actor_perception.obj
000a:00101eb4       ?g_perception_mode_names@@3PAPBDA 86737ab4     ailib:actor_perception.obj
000a:00101ed4       ?g_fireteam_target_selection_preference_bonus@@3MA 86737ad4     ailib:actor_perception.obj
0005:034d1660       ?prop_state_machine_update@@YAXJJ@Z 85cc1660 f   ailib:actor_perception.obj
0005:034d1fc8       ?actor_acknowledged_props_update@@YAXJ@Z 85cc1fc8 f   ailib:actor_perception.obj
0005:034d25f0       ?perception_qsort_compare_tracks@@YAHPBX0@Z 85cc25f0 f   ailib:actor_perception.obj
0005:034d2638       ?update_prop_timers@@YAXJJ@Z 85cc2638 f   ailib:actor_perception.obj
0005:034d28a0       ?prop_compute_light_perception_properties@@YAXJJPAUactor_position_data@@PBU1@PAF22@Z 85cc28a0 f   ailib:actor_perception.obj
0005:034d2c08       ?prop_compute_full_perception_properties@@YAXJJPAUactor_position_data@@PBU1@PAFPAM222@Z 85cc2c08 f   ailib:actor_perception.obj
0005:034d3158       ?prop_hologram_status_refresh@@YAXJJ_NPAUactor_position_data@@PBU1@@Z 85cc3158 f   ailib:actor_perception.obj
0005:034d3c08       ?actor_situation_dialog_update@@YAXJF@Z 85cc3c08 f   ailib:actor_perception.obj
0005:034d3e00       ?actor_combat_status_update@@YAXJ@Z 85cc3e00 f   ailib:actor_perception.obj
0005:034d4580       ?calculate_prop_class@@YAFJW4e_ai_posture@@PBUprop_ref_datum@@@Z 85cc4580 f   ailib:actor_perception.obj
0005:034d4940       ?calculate_awareness@@YAXPBUprop_ref_datum@@PAUprop_view@@@Z 85cc4940 f   ailib:actor_perception.obj
0005:034d4c78       ?unit_has_scary_weapon@@YA_NJ@Z 85cc4c78 f   ailib:actor_perception.obj
0005:034d4dc0       ?calculate_scariness@@YAXJPBUprop_ref_datum@@PBUprop_datum@@PAUprop_view@@@Z 85cc4dc0 f   ailib:actor_perception.obj
0005:034d4fc0       ?actor_perception_dialogue_handle_target_changed@@YAXJJ@Z 85cc4fc0 f   ailib:actor_perception.obj
0005:034d56a8       ?get_awareness_delta@@YAMJJ@Z 85cc56a8 f   ailib:actor_perception.obj
0005:034d5988       ?get_inverse_awareness_delta@@YAMJJ@Z 85cc5988 f   ailib:actor_perception.obj
0005:034d5ab0       ?get_active_camouflage_perception@@YAXABV?$c_character_runtime_properties@Vc_character_perception_properties_internal@@@@MMPAM1@Z 85cc5ab0 f   ailib:actor_perception.obj
0005:03d85348       ??__Ek_cosine60@@YAXXZ     86575348 f   ailib:actor_perception.obj
0005:03d85360       ??__Ek_log_complex_geometry_edge_length_cutoff@@YAXXZ 86575360 f   ailib:actor_perception.obj
0005:03d85390       ??__Ek_log_complex_geometry_edge_length_max@@YAXXZ 86575390 f   ailib:actor_perception.obj
0005:03d853c0       ??__Ek_log_complex_geometry_edge_length_min@@YAXXZ 865753c0 f   ailib:actor_perception.obj
0005:03d853f0       ??__Ek_vehicle_suspension_inverse_ray_test_overcast_factor@@YAXXZ 865753f0 f   ailib:actor_perception.obj
0005:03d85410       ??__Ek_indentity_azimuth_image@@YAXXZ 86575410 f   ailib:actor_perception.obj
0005:03d85450       ??__Ek_MaximumNavPointDistanceSquared@@YAXXZ 86575450 f   ailib:actor_perception.obj
*/