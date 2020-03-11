#pragma once

/* ---------- constants */

enum
{
    k_character_group_tag = 'char'
};

/* ---------- prototypes/CHARACTER_DEFINITIONS.CPP */

/*
0001:00631048       ?k_num_character_definition_cache_entries@@3FB 82631648     ailib:character_definitions.obj
0001:00631050       ??_C@_0EL@DEAJIGFA@c?3?2midnight?2main?2shared?2engine?2s@ 82631650     ailib:character_definitions.obj
0001:006310a0       ??_C@_0FB@EIDGIGIM@result?$DN?$DNcharacter_movement_set_g@ 826316a0     ailib:character_definitions.obj
0001:006310f4       ??_C@_0BN@MJKNHHBH@movement_variant_index?$CB?$DNNONE?$AA@ 826316f4     ailib:character_definitions.obj
0001:00631114       ??_C@_0BF@KLNJDEAI@movement?9set?9variant?$AA@ 82631714     ailib:character_definitions.obj
0001:0063112c       ??_C@_0BM@KDLBBAGO@movement?9set?9variant?9chance?$AA@ 8263172c     ailib:character_definitions.obj
0001:00631148       ??_C@_0N@EANBNIIB@temp_mapping?$AA@ 82631748     ailib:character_definitions.obj
0001:00631158       ??_C@_0CA@MKHJLFG@movement_set?5?$CFs?5has?5no?5variants?$AA@ 82631758     ailib:character_definitions.obj
0001:00631178       ??_C@_0N@HKFAPFLC@movement_set?$AA@ 82631778     ailib:character_definitions.obj
0001:00631188       ??_C@_0BL@NALOAHFB@out_movement_variant_index?$AA@ 82631788     ailib:character_definitions.obj
0001:006311a4       ??_C@_0BH@GONKDBBE@out_movement_set_index?$AA@ 826317a4     ailib:character_definitions.obj
0001:006311bc       ??_C@_0BP@PLPPFLKJ@out_character_definition_index?$AA@ 826317bc     ailib:character_definitions.obj
0001:006311dc       ??_C@_0CB@LALCOHFO@result?9?$DOactor_index?$DN?$DNactor_index@ 826317dc     ailib:character_definitions.obj
0001:00631200       ??_C@_0BE@GANCNPKI@m_actor_index?$CB?$DNNONE?$AA@ 82631800     ailib:character_definitions.obj
0001:00631214       ??_C@_0DC@DBNNAOKF@m_actor_index?$DN?$DNNONE?5?$HM?$HM?5m_actor_i@ 82631814     ailib:character_definitions.obj
0001:00631248       ??_C@_0CL@CBHMGCBC@stimulus_type?4m_stimulus?$DN?$DN_stimu@ 82631848     ailib:character_definitions.obj
0001:00631274       ??_C@_0BG@BGIKJOPC@stimulus_type?4valid?$CI?$CJ?$AA@ 82631874     ailib:character_definitions.obj
0001:0063128c       ??_C@_0DI@JHBIOOKI@VALID_INDEX?$CIstimulus_type?4m_stim@ 8263188c     ailib:character_definitions.obj
0005:00037418       ?set@?$c_character_runtime_properties@Vc_character_grenade_properties_internal@@@@QAAXPBVc_character_grenade_properties_internal@@@Z 82827418 f i ailib:character_definitions.obj
0005:00074248       ?apply_modifiers@character_firing_pattern@@QAAXXZ 82864248 f   ailib:character_definitions.obj
0005:000ada70       ?character_get_movement_mapping@@YAPBUcharacter_movement_mapping@@JFF@Z 8289da70 f   ailib:character_definitions.obj
0005:000c48d8       ?checksum@c_character_vehicle_properties_internal@@SAJJJ@Z 828b48d8 f   ailib:character_definitions.obj
0005:000cc850       ?character_select_movement_mapping@@YA_NJJPAJPAF1@Z 828bc850 f   ailib:character_definitions.obj
0005:000cca10       ?character_movement_set_select_variant@@YAPBUcharacter_movement_mapping@@JFPAF@Z 828bca10 f   ailib:character_definitions.obj
0005:00114418       ?actor_perception_properties_get@@YAXJAAV?$c_character_runtime_properties@Vc_character_perception_properties_internal@@@@@Z 82904418 f   ailib:character_definitions.obj
0005:00115918       ?actor_weapon_properties_get@@YAXJAAV?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@@Z 82905918 f   ailib:character_definitions.obj
0005:00175140       ?actor_get_character_properties_cache@@YAPBVc_character_properties_cache_datum@@J@Z 82965140 f   ailib:character_definitions.obj
0005:001a65a0       ?checksum@?$c_character_properties_base@Vc_character_movement_properties_internal@@@@SAJJJ@Z 829965a0 f i ailib:character_definitions.obj
0005:001a65b0       ?actor_generate_character_properties_checksum@@YAJJ@Z 829965b0 f   ailib:character_definitions.obj
0005:001a66b0       ?character_definition_iterator_next@@YAJPAUs_character_definition_iterator@@@Z 829966b0 f   ailib:character_definitions.obj
0005:001a6908       ?test@c_stimulus_flags@@QBA_NUc_stimulus_type@@@Z 82996908 f i ailib:character_definitions.obj
0005:001a6a80       ?set@c_stimulus_flags@@QAAXUc_stimulus_type@@J_N@Z 82996a80 f i ailib:character_definitions.obj
0005:001a6ec0       ?character_definition_iterator_new@@YAXPAUs_character_definition_iterator@@JPBVc_stimulus_flags@@@Z 82996ec0 f   ailib:character_definitions.obj
0005:001a7228       ?actor_vehicle_properties_get@@YAXJJAAV?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@@Z 82997228 f   ailib:character_definitions.obj
0005:001a7408       ?character_movement_set_get_by_name@@YAPBUcharacter_movement_set@@JJPAFPAJ@Z 82997408 f   ailib:character_definitions.obj
0005:001a7570       ?actor_firing_point_evaluation_properties_get@@YAXJW4e_evaluation_mode@@AAV?$c_character_runtime_properties@Vc_character_firing_point_evaluation_properties_internal@@@@@Z 82997570 f   ailib:character_definitions.obj
0005:001aa750       ?checksum@c_character_weapon_properties_internal@@SAJJJ@Z 8299a750 f   ailib:character_definitions.obj
0005:001aa790       ?checksum@c_character_perception_properties_internal@@SAJJJ@Z 8299a790 f   ailib:character_definitions.obj
0005:001d8310       ?character_definition_iterator_new@@YAXPAUs_character_definition_iterator@@J@Z 829c8310 f   ailib:character_definitions.obj
0005:00207c78       ?actor_weapon_properties_get@@YAXJJAAV?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@@Z 829f7c78 f   ailib:character_definitions.obj
0005:00220000       ?actor_firing_pattern_controls_fire_rate@@YA_NJJ@Z 82a10000 f   ailib:character_definitions.obj
0005:002326c8       ?actor_firing_pattern_properties_get@@YAXJJAAVc_character_firing_pattern_properties@@@Z 82a226c8 f   ailib:character_definitions.obj
0005:0023ee28       ?actor_grenade_properties_get@@YAXJAAV?$c_character_runtime_properties@Vc_character_grenade_properties_internal@@@@@Z 82a2ee28 f   ailib:character_definitions.obj
0005:0025ed38       ?apply_modifiers@c_character_grenade_properties_internal@@QAAXPAV1@@Z 82a4ed38 f   ailib:character_definitions.obj
0005:03427778       ?apply_modifiers@c_character_vitality_properties_internal@@QAAXPAV1@@Z 85c17778 f   ailib:character_definitions.obj
0005:034277e0       ?apply_modifiers@c_character_perception_properties_internal@@QAAXPAV1@@Z 85c177e0 f   ailib:character_definitions.obj
0005:03427968       ?apply_modifiers@c_character_movement_properties_internal@@QAAXPAV1@@Z 85c17968 f   ailib:character_definitions.obj
0005:03427a38       ?apply_modifiers@c_character_evasion_properties_internal@@QAAXPAV1@@Z 85c17a38 f   ailib:character_definitions.obj
0005:03427b40       ?apply_modifiers@c_character_retreat_properties_internal@@QAAXPAV1@@Z 85c17b40 f   ailib:character_definitions.obj
0005:03427c10       ?apply_modifiers@c_character_charge_properties_internal@@QAAXPAV1@@Z 85c17c10 f   ailib:character_definitions.obj
0005:03427d48       ?character_definition_weapon_properties_get@@YAPAVc_character_weapon_properties_internal@@JJ@Z 85c17d48 f   ailib:character_definitions.obj
0005:03427ff8       ?character_grenade_properties_get@@YAPAVc_character_grenade_properties_internal@@JF@Z 85c17ff8 f   ailib:character_definitions.obj
0005:03428138       ?actor_vehicle_boarding_properties_get@@YAPBUs_character_vehicle_boarding_properties@@JJABV?$c_character_runtime_properties@Vc_character_boarding_properties_internal@@@@@Z 85c18138 f   ailib:character_definitions.obj
0005:03428230       ?actor_flying_movement_properties_get@@YAXJJAAV?$c_character_runtime_properties@Vc_character_flying_movement_properties_internal@@@@@Z 85c18230 f   ailib:character_definitions.obj
0005:03428358       ?character_equipment_block_get@@YAPAUs_tag_block@@J@Z 85c18358 f   ailib:character_definitions.obj
0005:034283f8       ?character_equipment_use_get_skip_fraction@@YAMPAUcharacter_equipment_usage@@@Z 85c183f8 f   ailib:character_definitions.obj
0005:03428580       ?actor_charge_difficulty_limits_get@@YAPAUcharacter_charge_difficulty_limits@@J@Z 85c18580 f   ailib:character_definitions.obj
0005:03428638       ?character_variants_get@@YAPAUs_tag_block@@J@Z 85c18638 f   ailib:character_definitions.obj
0005:034286d8       ?character_get_activity_object@@YAPBUcharacter_activity_objects@@JFF@Z 85c186d8 f   ailib:character_definitions.obj
0005:03428898       ?character_get_movement_set@@YAPBUcharacter_movement_set@@JF@Z 85c18898 f   ailib:character_definitions.obj
0005:03428998       ?cache_evaluate@c_character_weapon_properties_internal@@SA_NJPBUs_tag_block@@PAX@Z 85c18998 f   ailib:character_definitions.obj
0005:03428a90       ?cache_evaluate@c_character_vehicle_properties_internal@@SA_NJPBUs_tag_block@@PAX@Z 85c18a90 f   ailib:character_definitions.obj
0005:03428b90       ?cache_evaluate@c_character_perception_properties_internal@@SA_NJPBUs_tag_block@@PAX@Z 85c18b90 f   ailib:character_definitions.obj
0005:03428c50       ?actor_build_character_properties_cache@@YAXJJ@Z 85c18c50 f   ailib:character_definitions.obj
0005:03428e70       ?cache_evaluate@?$c_character_properties_base@Vc_character_general_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c18e70 f i ailib:character_definitions.obj
0005:03428ee8       ?cache_clear@?$c_character_properties_base@Vc_character_general_properties_internal@@@@SAXPAX@Z 85c18ee8 f i ailib:character_definitions.obj
0005:03428f10       ?checksum@?$c_character_properties_base@Vc_character_general_properties_internal@@@@SAJJJ@Z 85c18f10 f i ailib:character_definitions.obj
0005:03428f20       ?cache_evaluate@?$c_character_properties_base@Vc_character_emotions_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c18f20 f i ailib:character_definitions.obj
0005:03428f98       ?cache_clear@?$c_character_properties_base@Vc_character_emotions_properties_internal@@@@SAXPAX@Z 85c18f98 f i ailib:character_definitions.obj
0005:03428fc0       ?checksum@?$c_character_properties_base@Vc_character_emotions_properties_internal@@@@SAJJJ@Z 85c18fc0 f i ailib:character_definitions.obj
0005:03428fd0       ?cache_evaluate@?$c_character_properties_base@Vc_character_vitality_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c18fd0 f i ailib:character_definitions.obj
0005:03429048       ?cache_clear@?$c_character_properties_base@Vc_character_vitality_properties_internal@@@@SAXPAX@Z 85c19048 f i ailib:character_definitions.obj
0005:03429070       ?checksum@?$c_character_properties_base@Vc_character_vitality_properties_internal@@@@SAJJJ@Z 85c19070 f i ailib:character_definitions.obj
0005:03429080       ?cache_clear@?$c_character_properties_base@Vc_character_perception_properties_internal@@@@SAXPAX@Z 85c19080 f i ailib:character_definitions.obj
0005:034290a8       ??8?$c_enum_no_init@W4e_perception_mode@@F$0A@$07Us_default_enum_string_resolver@@$0A@@@QBA_NW4e_perception_mode@@@Z 85c190a8 f i ailib:character_definitions.obj
0005:034290d8       ?cache_evaluate@?$c_character_properties_base@Vc_character_target_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c190d8 f i ailib:character_definitions.obj
0005:03429150       ?cache_clear@?$c_character_properties_base@Vc_character_target_properties_internal@@@@SAXPAX@Z 85c19150 f i ailib:character_definitions.obj
0005:03429178       ?checksum@?$c_character_properties_base@Vc_character_target_properties_internal@@@@SAJJJ@Z 85c19178 f i ailib:character_definitions.obj
0005:03429188       ?cache_evaluate@?$c_character_properties_base@Vc_character_look_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19188 f i ailib:character_definitions.obj
0005:03429200       ?cache_clear@?$c_character_properties_base@Vc_character_look_properties_internal@@@@SAXPAX@Z 85c19200 f i ailib:character_definitions.obj
0005:03429228       ?checksum@?$c_character_properties_base@Vc_character_look_properties_internal@@@@SAJJJ@Z 85c19228 f i ailib:character_definitions.obj
0005:03429238       ?cache_evaluate@?$c_character_properties_base@Vc_character_movement_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19238 f i ailib:character_definitions.obj
0005:034292b0       ?cache_clear@?$c_character_properties_base@Vc_character_movement_properties_internal@@@@SAXPAX@Z 85c192b0 f i ailib:character_definitions.obj
0005:034292d8       ?cache_evaluate@?$c_character_properties_base@Vc_character_engage_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c192d8 f i ailib:character_definitions.obj
0005:03429350       ?cache_clear@?$c_character_properties_base@Vc_character_engage_properties_internal@@@@SAXPAX@Z 85c19350 f i ailib:character_definitions.obj
0005:03429378       ?checksum@?$c_character_properties_base@Vc_character_engage_properties_internal@@@@SAJJJ@Z 85c19378 f i ailib:character_definitions.obj
0005:03429388       ?cache_evaluate@?$c_character_properties_base@Vc_character_evasion_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19388 f i ailib:character_definitions.obj
0005:03429400       ?cache_clear@?$c_character_properties_base@Vc_character_evasion_properties_internal@@@@SAXPAX@Z 85c19400 f i ailib:character_definitions.obj
0005:03429428       ?checksum@?$c_character_properties_base@Vc_character_evasion_properties_internal@@@@SAJJJ@Z 85c19428 f i ailib:character_definitions.obj
0005:03429438       ?cache_evaluate@?$c_character_properties_base@Vc_character_cover_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19438 f i ailib:character_definitions.obj
0005:034294b0       ?cache_clear@?$c_character_properties_base@Vc_character_cover_properties_internal@@@@SAXPAX@Z 85c194b0 f i ailib:character_definitions.obj
0005:034294d8       ?checksum@?$c_character_properties_base@Vc_character_cover_properties_internal@@@@SAJJJ@Z 85c194d8 f i ailib:character_definitions.obj
0005:034294e8       ?cache_evaluate@?$c_character_properties_base@Vc_character_retreat_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c194e8 f i ailib:character_definitions.obj
0005:03429560       ?cache_clear@?$c_character_properties_base@Vc_character_retreat_properties_internal@@@@SAXPAX@Z 85c19560 f i ailib:character_definitions.obj
0005:03429588       ?checksum@?$c_character_properties_base@Vc_character_retreat_properties_internal@@@@SAJJJ@Z 85c19588 f i ailib:character_definitions.obj
0005:03429598       ?cache_evaluate@?$c_character_properties_base@Vc_character_charge_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19598 f i ailib:character_definitions.obj
0005:03429610       ?cache_clear@?$c_character_properties_base@Vc_character_charge_properties_internal@@@@SAXPAX@Z 85c19610 f i ailib:character_definitions.obj
0005:03429638       ?checksum@?$c_character_properties_base@Vc_character_charge_properties_internal@@@@SAJJJ@Z 85c19638 f i ailib:character_definitions.obj
0005:03429648       ?cache_clear@?$c_character_properties_base@Vc_character_weapon_properties_internal@@@@SAXPAX@Z 85c19648 f i ailib:character_definitions.obj
0005:03429670       ?cache_clear@?$c_character_properties_base@Vc_character_vehicle_properties_internal@@@@SAXPAX@Z 85c19670 f i ailib:character_definitions.obj
0005:03429698       ?cache_evaluate@?$c_character_properties_base@Vc_character_idle_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19698 f i ailib:character_definitions.obj
0005:03429710       ?cache_clear@?$c_character_properties_base@Vc_character_idle_properties_internal@@@@SAXPAX@Z 85c19710 f i ailib:character_definitions.obj
0005:03429738       ?checksum@?$c_character_properties_base@Vc_character_idle_properties_internal@@@@SAJJJ@Z 85c19738 f i ailib:character_definitions.obj
0005:03429748       ?cache_evaluate@?$c_character_properties_base@Vc_character_vocalization_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19748 f i ailib:character_definitions.obj
0005:034297c0       ?cache_clear@?$c_character_properties_base@Vc_character_vocalization_properties_internal@@@@SAXPAX@Z 85c197c0 f i ailib:character_definitions.obj
0005:034297e8       ?checksum@?$c_character_properties_base@Vc_character_vocalization_properties_internal@@@@SAJJJ@Z 85c197e8 f i ailib:character_definitions.obj
0005:034297f8       ?cache_evaluate@?$c_character_properties_base@Vc_character_fight_circle_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c197f8 f i ailib:character_definitions.obj
0005:03429870       ?cache_clear@?$c_character_properties_base@Vc_character_fight_circle_properties_internal@@@@SAXPAX@Z 85c19870 f i ailib:character_definitions.obj
0005:03429898       ?checksum@?$c_character_properties_base@Vc_character_fight_circle_properties_internal@@@@SAJJJ@Z 85c19898 f i ailib:character_definitions.obj
0005:034298a8       ?cache_evaluate@?$c_character_properties_base@Vc_character_hamstring_charge_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c198a8 f i ailib:character_definitions.obj
0005:03429920       ?cache_clear@?$c_character_properties_base@Vc_character_hamstring_charge_properties_internal@@@@SAXPAX@Z 85c19920 f i ailib:character_definitions.obj
0005:03429948       ?checksum@?$c_character_properties_base@Vc_character_hamstring_charge_properties_internal@@@@SAJJJ@Z 85c19948 f i ailib:character_definitions.obj
0005:03429958       ?cache_evaluate@?$c_character_properties_base@Vc_character_forerunner_properties_internal@@@@SA_NJPBUs_tag_block@@PAX@Z 85c19958 f i ailib:character_definitions.obj
0005:034299d0       ?cache_clear@?$c_character_properties_base@Vc_character_forerunner_properties_internal@@@@SAXPAX@Z 85c199d0 f i ailib:character_definitions.obj
0005:034299f8       ?checksum@?$c_character_properties_base@Vc_character_forerunner_properties_internal@@@@SAJJJ@Z 85c199f8 f i ailib:character_definitions.obj
0005:03429a08       ?set@?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@QAAXPBVc_character_weapon_properties_internal@@@Z 85c19a08 f i ailib:character_definitions.obj
0005:03429a68       ?copy@?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@QAAXABV1@@Z 85c19a68 f i ailib:character_definitions.obj
0005:03429aa0       ?invalidate@?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@QAAXXZ 85c19aa0 f i ailib:character_definitions.obj
0005:03429ab8       ?static_set@?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@SAXPAXPBVc_character_weapon_properties_internal@@@Z 85c19ab8 f i ailib:character_definitions.obj
0005:03429ae8       ?static_valid@?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@SA_NPAX@Z 85c19ae8 f i ailib:character_definitions.obj
0005:03429b10       ?copy@?$c_character_runtime_properties@Vc_character_perception_properties_internal@@@@QAAXABV1@@Z 85c19b10 f i ailib:character_definitions.obj
0005:03429b48       ?static_set@?$c_character_runtime_properties@Vc_character_perception_properties_internal@@@@SAXPAXPBVc_character_perception_properties_internal@@@Z 85c19b48 f i ailib:character_definitions.obj
0005:03429b78       ?set@?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@QAAXPBVc_character_vehicle_properties_internal@@@Z 85c19b78 f i ailib:character_definitions.obj
0005:03429bd8       ?copy@?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@QAAXABV1@@Z 85c19bd8 f i ailib:character_definitions.obj
0005:03429c10       ?static_set@?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@SAXPAXPBVc_character_vehicle_properties_internal@@@Z 85c19c10 f i ailib:character_definitions.obj
0005:03429c40       ?static_valid@?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@SA_NPAX@Z 85c19c40 f i ailib:character_definitions.obj
0005:03429c68       ?set@?$c_character_runtime_properties@Vc_character_firing_point_evaluation_properties_internal@@@@QAAXPBVc_character_firing_point_evaluation_properties_internal@@@Z 85c19c68 f i ailib:character_definitions.obj
0005:03429cc8       ?set@?$c_character_runtime_properties@Vc_character_flying_movement_properties_internal@@@@QAAXPBVc_character_flying_movement_properties_internal@@@Z 85c19cc8 f i ailib:character_definitions.obj
0005:03429d28       ?apply_modifiers@?$c_character_properties_base@Vc_character_firing_point_evaluation_properties_internal@@@@SAXPAV1@@Z 85c19d28 f i ailib:character_definitions.obj
0005:03429d30       ?apply_modifiers@?$c_character_properties_base@Vc_character_weapon_properties_internal@@@@SAXPAV1@@Z 85c19d30 f i ailib:character_definitions.obj
0005:03429d38       ?apply_modifiers@?$c_character_properties_base@Vc_character_vehicle_properties_internal@@@@SAXPAV1@@Z 85c19d38 f i ailib:character_definitions.obj
0005:03429d40       ?apply_modifiers@?$c_character_properties_base@Vc_character_flying_movement_properties_internal@@@@SAXPAV1@@Z 85c19d40 f i ailib:character_definitions.obj
0005:03429d48       ?static_set@?$c_character_runtime_properties@Vc_character_movement_properties_internal@@@@SAXPAXPBVc_character_movement_properties_internal@@@Z 85c19d48 f i ailib:character_definitions.obj
0005:03429d78       ?static_invalidate@?$c_character_runtime_properties@Vc_character_movement_properties_internal@@@@SAXPAX@Z 85c19d78 f i ailib:character_definitions.obj
0005:03429da0       ?static_set@?$c_character_runtime_properties@Vc_character_general_properties_internal@@@@SAXPAXPBVc_character_general_properties_internal@@@Z 85c19da0 f i ailib:character_definitions.obj
0005:03429dd0       ?static_invalidate@?$c_character_runtime_properties@Vc_character_general_properties_internal@@@@SAXPAX@Z 85c19dd0 f i ailib:character_definitions.obj
0005:03429df8       ?static_set@?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@SAXPAXPBVc_character_emotions_properties_internal@@@Z 85c19df8 f i ailib:character_definitions.obj
0005:03429e28       ?static_valid@?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@SA_NPAX@Z 85c19e28 f i ailib:character_definitions.obj
0005:03429e50       ?static_invalidate@?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@SAXPAX@Z 85c19e50 f i ailib:character_definitions.obj
0005:03429e78       ?static_set@?$c_character_runtime_properties@Vc_character_vitality_properties_internal@@@@SAXPAXPBVc_character_vitality_properties_internal@@@Z 85c19e78 f i ailib:character_definitions.obj
0005:03429ea8       ?static_invalidate@?$c_character_runtime_properties@Vc_character_vitality_properties_internal@@@@SAXPAX@Z 85c19ea8 f i ailib:character_definitions.obj
0005:03429ed0       ?static_set@?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@SAXPAXPBVc_character_engage_properties_internal@@@Z 85c19ed0 f i ailib:character_definitions.obj
0005:03429f00       ?static_valid@?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@SA_NPAX@Z 85c19f00 f i ailib:character_definitions.obj
0005:03429f28       ?static_invalidate@?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@SAXPAX@Z 85c19f28 f i ailib:character_definitions.obj
0005:03429f50       ?static_set@?$c_character_runtime_properties@Vc_character_charge_properties_internal@@@@SAXPAXPBVc_character_charge_properties_internal@@@Z 85c19f50 f i ailib:character_definitions.obj
0005:03429f80       ?static_invalidate@?$c_character_runtime_properties@Vc_character_charge_properties_internal@@@@SAXPAX@Z 85c19f80 f i ailib:character_definitions.obj
0005:03429fa8       ?static_set@?$c_character_runtime_properties@Vc_character_cover_properties_internal@@@@SAXPAXPBVc_character_cover_properties_internal@@@Z 85c19fa8 f i ailib:character_definitions.obj
0005:03429fd8       ?static_invalidate@?$c_character_runtime_properties@Vc_character_cover_properties_internal@@@@SAXPAX@Z 85c19fd8 f i ailib:character_definitions.obj
0005:0342a000       ?static_set@?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@SAXPAXPBVc_character_evasion_properties_internal@@@Z 85c1a000 f i ailib:character_definitions.obj
0005:0342a030       ?static_valid@?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@SA_NPAX@Z 85c1a030 f i ailib:character_definitions.obj
0005:0342a058       ?static_invalidate@?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@SAXPAX@Z 85c1a058 f i ailib:character_definitions.obj
0005:0342a080       ?static_set@?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@SAXPAXPBVc_character_idle_properties_internal@@@Z 85c1a080 f i ailib:character_definitions.obj
0005:0342a0b0       ?static_valid@?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@SA_NPAX@Z 85c1a0b0 f i ailib:character_definitions.obj
0005:0342a0d8       ?static_invalidate@?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@SAXPAX@Z 85c1a0d8 f i ailib:character_definitions.obj
0005:0342a100       ?static_set@?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@SAXPAXPBVc_character_retreat_properties_internal@@@Z 85c1a100 f i ailib:character_definitions.obj
0005:0342a130       ?static_valid@?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@SA_NPAX@Z 85c1a130 f i ailib:character_definitions.obj
0005:0342a158       ?static_invalidate@?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@SAXPAX@Z 85c1a158 f i ailib:character_definitions.obj
0005:0342a180       ?static_set@?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@SAXPAXPBVc_character_look_properties_internal@@@Z 85c1a180 f i ailib:character_definitions.obj
0005:0342a1b0       ?static_valid@?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@SA_NPAX@Z 85c1a1b0 f i ailib:character_definitions.obj
0005:0342a1d8       ?static_invalidate@?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@SAXPAX@Z 85c1a1d8 f i ailib:character_definitions.obj
0005:0342a200       ?static_set@?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@SAXPAXPBVc_character_vocalization_properties_internal@@@Z 85c1a200 f i ailib:character_definitions.obj
0005:0342a230       ?static_invalidate@?$c_character_runtime_properties@Vc_character_vocalization_properties_internal@@@@SAXPAX@Z 85c1a230 f i ailib:character_definitions.obj
0005:0342a258       ?static_set@?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@SAXPAXPBVc_character_target_properties_internal@@@Z 85c1a258 f i ailib:character_definitions.obj
0005:0342a288       ?static_valid@?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@SA_NPAX@Z 85c1a288 f i ailib:character_definitions.obj
0005:0342a2b0       ?static_invalidate@?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@SAXPAX@Z 85c1a2b0 f i ailib:character_definitions.obj
0005:0342a2d8       ?static_set@?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@SAXPAXPBVc_character_hamstring_charge_properties_internal@@@Z 85c1a2d8 f i ailib:character_definitions.obj
0005:0342a308       ?static_valid@?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@SA_NPAX@Z 85c1a308 f i ailib:character_definitions.obj
0005:0342a330       ?static_invalidate@?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@SAXPAX@Z 85c1a330 f i ailib:character_definitions.obj
0005:0342a358       ?static_set@?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@SAXPAXPBVc_character_fight_circle_properties_internal@@@Z 85c1a358 f i ailib:character_definitions.obj
0005:0342a388       ?static_valid@?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@SA_NPAX@Z 85c1a388 f i ailib:character_definitions.obj
0005:0342a3b0       ?static_invalidate@?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@SAXPAX@Z 85c1a3b0 f i ailib:character_definitions.obj
0005:0342a3d8       ?static_set@?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@SAXPAXPBVc_character_forerunner_properties_internal@@@Z 85c1a3d8 f i ailib:character_definitions.obj
0005:0342a408       ?static_valid@?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@SA_NPAX@Z 85c1a408 f i ailib:character_definitions.obj
0005:0342a430       ?static_invalidate@?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@SAXPAX@Z 85c1a430 f i ailib:character_definitions.obj
0005:0342a458       ?static_invalidate@?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@SAXPAX@Z 85c1a458 f i ailib:character_definitions.obj
0005:0342a480       ?static_invalidate@?$c_character_runtime_properties@Vc_character_perception_properties_internal@@@@SAXPAX@Z 85c1a480 f i ailib:character_definitions.obj
0005:0342a4a8       ?invalidate@?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@QAAXXZ 85c1a4a8 f i ailib:character_definitions.obj
0005:0342a4c0       ?static_invalidate@?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@SAXPAX@Z 85c1a4c0 f i ailib:character_definitions.obj
0005:0342a4e8       ?invalidate@?$c_character_runtime_properties@Vc_character_firing_point_evaluation_properties_internal@@@@QAAXXZ 85c1a4e8 f i ailib:character_definitions.obj
0005:0342a500       ?invalidate@?$c_character_runtime_properties@Vc_character_grenade_properties_internal@@@@QAAXXZ 85c1a500 f i ailib:character_definitions.obj
0005:0342a518       ?invalidate@?$c_character_runtime_properties@Vc_character_flying_movement_properties_internal@@@@QAAXXZ 85c1a518 f i ailib:character_definitions.obj
0005:0342a530       ?set@?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@QAAXPBVc_character_emotions_properties_internal@@@Z 85c1a530 f i ailib:character_definitions.obj
0005:0342a590       ?valid@?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@QBA_NXZ 85c1a590 f i ailib:character_definitions.obj
0005:0342a5a0       ?invalidate@?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@QAAXXZ 85c1a5a0 f i ailib:character_definitions.obj
0005:0342a5b8       ?set@?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@QAAXPBVc_character_engage_properties_internal@@@Z 85c1a5b8 f i ailib:character_definitions.obj
0005:0342a618       ?valid@?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@QBA_NXZ 85c1a618 f i ailib:character_definitions.obj
0005:0342a628       ?invalidate@?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@QAAXXZ 85c1a628 f i ailib:character_definitions.obj
0005:0342a640       ?set@?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@QAAXPBVc_character_evasion_properties_internal@@@Z 85c1a640 f i ailib:character_definitions.obj
0005:0342a6a0       ?valid@?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@QBA_NXZ 85c1a6a0 f i ailib:character_definitions.obj
0005:0342a6b0       ?invalidate@?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@QAAXXZ 85c1a6b0 f i ailib:character_definitions.obj
0005:0342a6c8       ?set@?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@QAAXPBVc_character_idle_properties_internal@@@Z 85c1a6c8 f i ailib:character_definitions.obj
0005:0342a728       ?valid@?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@QBA_NXZ 85c1a728 f i ailib:character_definitions.obj
0005:0342a738       ?invalidate@?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@QAAXXZ 85c1a738 f i ailib:character_definitions.obj
0005:0342a750       ?set@?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@QAAXPBVc_character_retreat_properties_internal@@@Z 85c1a750 f i ailib:character_definitions.obj
0005:0342a7b0       ?valid@?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@QBA_NXZ 85c1a7b0 f i ailib:character_definitions.obj
0005:0342a7c0       ?invalidate@?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@QAAXXZ 85c1a7c0 f i ailib:character_definitions.obj
0005:0342a7d8       ?set@?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@QAAXPBVc_character_look_properties_internal@@@Z 85c1a7d8 f i ailib:character_definitions.obj
0005:0342a838       ?valid@?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@QBA_NXZ 85c1a838 f i ailib:character_definitions.obj
0005:0342a848       ?invalidate@?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@QAAXXZ 85c1a848 f i ailib:character_definitions.obj
0005:0342a860       ?set@?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@QAAXPBVc_character_target_properties_internal@@@Z 85c1a860 f i ailib:character_definitions.obj
0005:0342a8c0       ?valid@?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@QBA_NXZ 85c1a8c0 f i ailib:character_definitions.obj
0005:0342a8d0       ?invalidate@?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@QAAXXZ 85c1a8d0 f i ailib:character_definitions.obj
0005:0342a8e8       ?set@?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@QAAXPBVc_character_hamstring_charge_properties_internal@@@Z 85c1a8e8 f i ailib:character_definitions.obj
0005:0342a948       ?valid@?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@QBA_NXZ 85c1a948 f i ailib:character_definitions.obj
0005:0342a958       ?invalidate@?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@QAAXXZ 85c1a958 f i ailib:character_definitions.obj
0005:0342a970       ?set@?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@QAAXPBVc_character_fight_circle_properties_internal@@@Z 85c1a970 f i ailib:character_definitions.obj
0005:0342a9d0       ?valid@?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@QBA_NXZ 85c1a9d0 f i ailib:character_definitions.obj
0005:0342a9e0       ?invalidate@?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@QAAXXZ 85c1a9e0 f i ailib:character_definitions.obj
0005:0342a9f8       ?set@?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@QAAXPBVc_character_forerunner_properties_internal@@@Z 85c1a9f8 f i ailib:character_definitions.obj
0005:0342aa58       ?valid@?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@QBA_NXZ 85c1aa58 f i ailib:character_definitions.obj
0005:0342aa68       ?invalidate@?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@QAAXXZ 85c1aa68 f i ailib:character_definitions.obj
0005:0342aa80       ?apply_modifiers@?$c_character_properties_base@Vc_character_emotions_properties_internal@@@@SAXPAV1@@Z 85c1aa80 f i ailib:character_definitions.obj
0005:0342aa88       ?apply_modifiers@?$c_character_properties_base@Vc_character_target_properties_internal@@@@SAXPAV1@@Z 85c1aa88 f i ailib:character_definitions.obj
0005:0342aa90       ?apply_modifiers@?$c_character_properties_base@Vc_character_look_properties_internal@@@@SAXPAV1@@Z 85c1aa90 f i ailib:character_definitions.obj
0005:0342aa98       ?apply_modifiers@?$c_character_properties_base@Vc_character_engage_properties_internal@@@@SAXPAV1@@Z 85c1aa98 f i ailib:character_definitions.obj
0005:0342aaa0       ?apply_modifiers@?$c_character_properties_base@Vc_character_idle_properties_internal@@@@SAXPAV1@@Z 85c1aaa0 f i ailib:character_definitions.obj
0005:0342aaa8       ?apply_modifiers@?$c_character_properties_base@Vc_character_fight_circle_properties_internal@@@@SAXPAV1@@Z 85c1aaa8 f i ailib:character_definitions.obj
0005:0342aab0       ?apply_modifiers@?$c_character_properties_base@Vc_character_hamstring_charge_properties_internal@@@@SAXPAV1@@Z 85c1aab0 f i ailib:character_definitions.obj
0005:0342aab8       ?apply_modifiers@?$c_character_properties_base@Vc_character_forerunner_properties_internal@@@@SAXPAV1@@Z 85c1aab8 f i ailib:character_definitions.obj
0005:0342aac0       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@Vc_character_weapon_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_weapon_properties_internal@@@@PBVc_character_weapon_properties_internal@@@Z 85c1aac0 f i ailib:character_definitions.obj
0005:0342aaf8       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@Vc_character_vehicle_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_vehicle_properties_internal@@@@PBVc_character_vehicle_properties_internal@@@Z 85c1aaf8 f i ailib:character_definitions.obj
0005:0342ab30       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_firing_point_evaluation_properties_internal@@@@Vc_character_firing_point_evaluation_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_firing_point_evaluation_properties_internal@@@@PBVc_character_firing_point_evaluation_properties_internal@@@Z 85c1ab30 f i ailib:character_definitions.obj
0005:0342ab68       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_grenade_properties_internal@@@@Vc_character_grenade_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_grenade_properties_internal@@@@PBVc_character_grenade_properties_internal@@@Z 85c1ab68 f i ailib:character_definitions.obj
0005:0342aba0       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_flying_movement_properties_internal@@@@Vc_character_flying_movement_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_flying_movement_properties_internal@@@@PBVc_character_flying_movement_properties_internal@@@Z 85c1aba0 f i ailib:character_definitions.obj
0005:0342abd8       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@Vc_character_emotions_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_emotions_properties_internal@@@@PBVc_character_emotions_properties_internal@@@Z 85c1abd8 f i ailib:character_definitions.obj
0005:0342ac10       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@Vc_character_engage_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_engage_properties_internal@@@@PBVc_character_engage_properties_internal@@@Z 85c1ac10 f i ailib:character_definitions.obj
0005:0342ac48       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@Vc_character_evasion_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_evasion_properties_internal@@@@PBVc_character_evasion_properties_internal@@@Z 85c1ac48 f i ailib:character_definitions.obj
0005:0342ac80       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@Vc_character_idle_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_idle_properties_internal@@@@PBVc_character_idle_properties_internal@@@Z 85c1ac80 f i ailib:character_definitions.obj
0005:0342acb8       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@Vc_character_retreat_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_retreat_properties_internal@@@@PBVc_character_retreat_properties_internal@@@Z 85c1acb8 f i ailib:character_definitions.obj
0005:0342acf0       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@Vc_character_look_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_look_properties_internal@@@@PBVc_character_look_properties_internal@@@Z 85c1acf0 f i ailib:character_definitions.obj
0005:0342ad28       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@Vc_character_target_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_target_properties_internal@@@@PBVc_character_target_properties_internal@@@Z 85c1ad28 f i ailib:character_definitions.obj
0005:0342ad60       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@Vc_character_hamstring_charge_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_hamstring_charge_properties_internal@@@@PBVc_character_hamstring_charge_properties_internal@@@Z 85c1ad60 f i ailib:character_definitions.obj
0005:0342ad98       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@Vc_character_fight_circle_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_fight_circle_properties_internal@@@@PBVc_character_fight_circle_properties_internal@@@Z 85c1ad98 f i ailib:character_definitions.obj
0005:0342add0       ??$character_runtime_properties_copy@V?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@Vc_character_forerunner_properties_internal@@@@YAXPAV?$c_character_runtime_properties@Vc_character_forerunner_properties_internal@@@@PBVc_character_forerunner_properties_internal@@@Z 85c1add0 f i ailib:character_definitions.obj
0005:0342ae08       ??4c_stimulus_type@@QAAAAU0@ABW4e_stimulus@@@Z 85c1ae08 f i ailib:character_definitions.obj
0005:0342ae38       ?get_stimulus_type@c_stimulus_payload@@QBA?AUc_stimulus_type@@XZ 85c1ae38 f i ailib:character_definitions.obj
0005:0342ae58       ?set@c_stimulus_flags@@QAAXW4e_stimulus@@_N@Z 85c1ae58 f i ailib:character_definitions.obj
0005:0342af68       ??8c_stimulus_type@@QBA_NABU0@@Z 85c1af68 f i ailib:character_definitions.obj
0005:0342afc0       ?valid@c_character_firing_pattern_properties@@QBA_NXZ 85c1afc0 f i ailib:character_definitions.obj
0005:0342afd0       ?invalidate@c_character_firing_pattern_properties@@QAAXXZ 85c1afd0 f i ailib:character_definitions.obj
0005:0342b000       ?set@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@QAAXW4e_stimulus@@_N@Z 85c1b000 f i ailib:character_definitions.obj
0005:0342b1a8       ?valid@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@QBA_NXZ 85c1b1a8 f i ailib:character_definitions.obj
0005:0342b240       ?get_mask_of_second_slice_of_chunk_inclusive@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@KAKW4e_stimulus@@@Z 85c1b240 f i ailib:character_definitions.obj
0005:0342b2d8       ?flag_chunk_index_to_bit_index@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@KA?AW4e_stimulus@@J@Z 85c1b2d8 f i ailib:character_definitions.obj
0005:0342b2e8       ?bit_index_to_flag_chunk_index@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@KAJW4e_stimulus@@@Z 85c1b2e8 f i ailib:character_definitions.obj
0005:0342b2f8       ?get_valid_mask_of_last_chunk@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@KAKXZ 85c1b2f8 f i ailib:character_definitions.obj
0005:0342b338       ?get_mask_of_first_slice_of_chunk_exclusive@?$c_big_flags_typed_no_init@W4e_stimulus@@$0DA@@@KAKW4e_stimulus@@@Z 85c1b338 f i ailib:character_definitions.obj
000a:000fe720       ?character_definition_cache_entries@@3PAUs_character_properties_cache_entry@@A 86734320     ailib:character_definitions.obj
0005:03427d80       ?character_definition_weapon_properties_get@@YAPAVc_character_weapon_properties_internal@@JJPBVc_stimulus_flags@@@Z 85c17d80 f   ailib:character_definitions.obj
0005:03427e88       ?character_firing_pattern_properties_get@@YAPAVc_character_firing_pattern_properties_internal@@JPBVc_stimulus_flags@@J_N@Z 85c17e88 f   ailib:character_definitions.obj
0005:03428030       ?character_grenade_properties_get@@YAPAVc_character_grenade_properties_internal@@JPBVc_stimulus_flags@@F@Z 85c18030 f   ailib:character_definitions.obj
0005:03428dc8       ?actor_clear_character_properties_cache@@YAXPAVc_character_properties_cache_datum@@@Z 85c18dc8 f   ailib:character_definitions.obj
0005:03d80528       ??__Ek_vehicle_suspension_inverse_ray_test_overcast_factor@@YAXXZ 86570528 f   ailib:character_definitions.obj
*/
