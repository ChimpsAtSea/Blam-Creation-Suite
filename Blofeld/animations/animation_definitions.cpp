#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(frame_event_list, FRAME_EVENT_LIST_TAG, frame_event_list_block_block );

	TAG_GROUP(model_animation_graph, MODEL_ANIMATION_GRAPH_TAG)
	{
		FIELD( _field_struct, "definitions", &animation_graph_definitions_struct_struct_definition ),
		FIELD( _field_struct, "content", &animation_graph_contents_struct_struct_definition ),
		FIELD( _field_struct, "run time data", &model_animation_runtime_data_struct_struct_definition ),
		FIELD( _field_block, "additional node data", &additional_node_data_block_block ),
		FIELD( _field_block, "tag resource groups", &model_animation_tag_resource_group_block ),
		FIELD( _field_struct, "codec data*!", &animation_codec_data_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_graph_sound_reference_block, k_max_sound_references_per_graph)
	{
		FIELD( _field_tag_reference, "sound^" ),
		FIELD( _field_word_flags, "flags", &key_event_flags_enum ),
		FIELD( _field_word_flags, "internal_flags!", &key_event_internal_flags_enum ),
		FIELD( _field_tag_reference, "model#optional. only allow this event when used on this model" ),
		FIELD( _field_string_id, "variant#optional. only allow this event when used on this model variant" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_graph_effect_reference_block, k_max_effect_references_per_graph)
	{
		FIELD( _field_tag_reference, "effect^" ),
		FIELD( _field_word_flags, "flags", &key_event_flags_enum ),
		FIELD( _field_word_flags, "internal_flags!", &key_event_internal_flags_enum ),
		FIELD( _field_tag_reference, "model#optional. only allow this event when used on this model" ),
		FIELD( _field_string_id, "variant#optional. only allow this event when used on this model variant" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(import_frame_event_block, k_max_frame_events)
	{
		FIELD( _field_string_id, "event name*" ),
		FIELD( _field_string_id, "animation name!*" ),
		FIELD( _field_short_integer, "frame" ),
		FIELD( _field_short_integer, "frame offset" ),
		FIELD( _field_enum, "type*", &frame_event_type_new ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_long_integer, "unique ID*!#(Do not change this)" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_sound_event_block_extended, k_max_frame_events)
	{
		FIELD( _field_short_block_index, "frame event" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_short_block_index, "sound" ),
		FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_effects_event_block_extended, k_max_frame_events)
	{
		FIELD( _field_short_block_index, "frame event" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_short_block_index, "effect" ),
		FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name" ),
		FIELD( _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_pad, "pad_2", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_dialogue_event_block_extended, k_max_frame_events)
	{
		FIELD( _field_short_block_index, "frame event" ),
		FIELD( _field_enum, "dialogue event", &animation_dialogue_event_enum ),
		FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_script_event_block_extended, k_max_frame_events)
	{
		FIELD( _field_short_block_index, "frame event" ),
		FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
		FIELD( _field_string_id, "script name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(import_animation_event_block, 2*k_max_animations_per_graph)
	{
		FIELD( _field_string_id, "animation name^*!" ),
		FIELD( _field_long_integer, "animation frame count^*!" ),
		FIELD( _field_block, "animation events", &import_frame_event_block_block ),
		FIELD( _field_block, "sound events", &animation_sound_event_block_extended_block ),
		FIELD( _field_block, "effect events", &animation_effects_event_block_extended_block ),
		FIELD( _field_block, "dialogue events", &animation_dialogue_event_block_extended_block ),
		FIELD( _field_block, "script events", &animation_script_event_block_extended_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(frame_event_list_block, 1, frame_event_list_struct_definition_struct_definition );

	TAG_BLOCK(animation_usage_block, k_animation_node_usage_count)
	{
		FIELD( _field_enum, "usage^", &animation_usage_enumeration ),
		FIELD( _field_short_block_index, "node to use" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_node_mask_entry_block, k_max_nodes_per_animation)
	{
		FIELD( _field_short_block_index, "node^" ),
		FIELD( _field_pad, "anbfp", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_node_mask_block, k_animation_maximum_node_mask_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "nodes", &animation_node_mask_entry_block_block ),
		FIELD( _field_array, "node flags!", &g_node_flag_storage_array_array ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_function_block, k_animation_maximum_function_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(mode_or_stance_alias_block, k_animation_maximum_mode_or_stance_aliases)
	{
		FIELD( _field_string_id, "mode or stance" ),
		FIELD( _field_string_id, "alias" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_animation_variant_block, k_animation_maximum_model_variants)
	{
		FIELD( _field_string_id, "variant name^" ),
		FIELD( _field_long_flags, "variant flags", &model_animation_variant_flags ),
		FIELD( _field_block, "mode or stance aliases", &mode_or_stance_alias_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_graph_node_block, k_max_nodes_per_animation)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_short_block_index, "next sibling node index*" ),
		FIELD( _field_short_block_index, "first child node index*" ),
		FIELD( _field_short_block_index, "parent node index*" ),
		FIELD( _field_byte_flags, "model flags*", &animation_node_model_flags ),
		FIELD( _field_byte_flags, "node joint flags", &node_joint_flags ),
		FIELD( _field_byte_flags, "additional flags", &node_info_flags ),
		FIELD( _field_pad, "NOD", 3 ),
		FIELD( _field_real_vector_3d, "base vector*" ),
		FIELD( _field_real, "vector range*" ),
		FIELD( _field_real, "z_pos*" ),
		FIELD( _field_long_integer, "frame_ID1*" ),
		FIELD( _field_long_integer, "frame_ID2*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_blend_screen_block, k_animation_maximum_blend_screens)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_struct, "aiming screen*", &animation_aiming_screen_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(foot_tracking_member_block, k_max_tracked_feet)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "foot marker name^" ),
		FIELD( _field_real_bounds, "foot ik range" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "ankle marker name" ),
		FIELD( _field_real_bounds, "ankle ik range" ),
		FIELD( _field_enum, "default state", &foot_tracking_default_values ),
		FIELD( _field_pad, "f00t1", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_frame_event_block, k_max_frame_events)
	{
		FIELD( _field_enum, "type", &frame_event_type_new ),
		FIELD( _field_short_integer, "frame" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_sound_event_block, k_max_frame_events)
	{
		FIELD( _field_short_block_index, "sound" ),
		FIELD( _field_short_integer, "frame" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_effect_event_block, k_max_frame_events)
	{
		FIELD( _field_short_block_index, "effect" ),
		FIELD( _field_short_integer, "frame" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name" ),
		FIELD( _field_char_enum, "damage effect reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_pad, "eefpd1", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_dialogue_event_block, k_max_frame_events)
	{
		FIELD( _field_enum, "dialogue event", &animation_dialogue_event_enum ),
		FIELD( _field_short_integer, "frame" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_script_event_block, k_max_frame_events)
	{
		FIELD( _field_string_id, "script name" ),
		FIELD( _field_short_integer, "frame" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(object_space_node_data_block, k_max_nodes_per_animation)
	{
		FIELD( _field_short_block_index, "node index{node_index}^" ),
		FIELD( _field_word_flags, "flags*", &object_space_node_flags ),
		FIELD( _field_struct, "parent orientation{orientation}*", &quantized_orientation_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(foot_lock_cycle_block, k_max_cycles_per_tracked_foot)
	{
		FIELD( _field_short_integer, "start locking" ),
		FIELD( _field_short_integer, "locked" ),
		FIELD( _field_short_integer, "start unlocking" ),
		FIELD( _field_short_integer, "unlocked" ),
		FIELD( _field_real_point_3d, "lock point*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(foot_tracking_block, k_max_tracked_feet)
	{
		FIELD( _field_short_block_index, "foot" ),
		FIELD( _field_pad, "f00t2", 2 ),
		FIELD( _field_block, "cycles|ABCDCC", &foot_lock_cycle_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(object_space_offset_node_block, k_max_object_space_offset_node_count)
	{
		FIELD( _field_short_block_index, "object space offset node^" ),
		FIELD( _field_pad, "wsonbp", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(fik_anchor_node_block, k_max_fik_anchor_node_count)
	{
		FIELD( _field_short_block_index, "anchor node^" ),
		FIELD( _field_pad, "dse", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(animation_ik_chain_events, k_animation_maximum_ik_chain_events, animation_ik_chain_events_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_ik_chain_proxies, k_animation_maximum_ik_chain_proxies, animation_ik_chain_proxies_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_facial_wrinkle_events, k_animation_maximum_facial_wrinkle_events, animation_facial_wrinkle_events_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_extended_events, k_animation_maximum_extended_events, animation_extended_events_struct_struct_definition );

	TAG_BLOCK_FROM_STRUCT(animation_object_functions, k_animation_maximum_object_functions, animation_object_functions_struct_struct_definition );

	TAG_BLOCK(shared_model_animation_block, 1)
	{
		FIELD( _field_short_integer, "frame count*" ),
		FIELD( _field_byte_integer, "node count*" ),
		FIELD( _field_char_enum, "animation type*", &animation_type_enum ),
		FIELD( _field_char_enum, "frame info type*", &frame_info_type_enum ),
		FIELD( _field_char_enum, "desired frame info type*", &frame_info_type_enum ),
		FIELD( _field_char_enum, "desired compression", &compression_settings ),
		FIELD( _field_char_enum, "current compression*", &compression_settings ),
		FIELD( _field_word_flags, "internal flags*", &internal_animation_flags ),
		FIELD( _field_short_integer, "compressor_version*" ),
		FIELD( _field_long_integer, "uid*" ),
		FIELD( _field_string_id, "shared id*" ),
		FIELD( _field_long_integer, "node list checksum*" ),
		FIELD( _field_short_integer, "resource_group*" ),
		FIELD( _field_short_integer, "resource_group_member*" ),
		FIELD( _field_real_vector_3d, "heading*!" ),
		FIELD( _field_real, "heading angle*!" ),
		FIELD( _field_real, "average translation magnitude*!" ),
		FIELD( _field_real, "average pivot yaw*!" ),
		FIELD( _field_explanation, "a!" ),
		FIELD( _field_block, "frame events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_frame_event_block_block ),
		FIELD( _field_block, "sound events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_sound_event_block_block ),
		FIELD( _field_block, "effect events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_effect_event_block_block ),
		FIELD( _field_block, "dialogue events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_dialogue_event_block_block ),
		FIELD( _field_block, "script events|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_script_event_block_block ),
		FIELD( _field_explanation, "b!" ),
		FIELD( _field_block, "object-space parent nodes|ABCDCC", &object_space_node_data_block_block ),
		FIELD( _field_block, "foot tracking|ABCDCC", &foot_tracking_block_block ),
		FIELD( _field_block, "object space offset nodes|ABCDCC", &object_space_offset_node_block_block ),
		FIELD( _field_block, "forward-invert kinetic anchor nodes|ABCDCC", &fik_anchor_node_block_block ),
		FIELD( _field_block, "ik chain events*!", &animation_ik_chain_events_block ),
		FIELD( _field_block, "ik chain proxies*!", &animation_ik_chain_proxies_block ),
		FIELD( _field_block, "facial wrinkle events*!", &animation_facial_wrinkle_events_block ),
		FIELD( _field_block, "extended data events*!", &animation_extended_events_block ),
		FIELD( _field_block, "animation object functions", &animation_object_functions_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_pool_block, k_max_animations_per_graph)
	{
		FIELD( _field_string_id, "name*^" ),
		FIELD( _field_custom ),
		FIELD( _field_real, "weight" ),
		FIELD( _field_short_integer, "loop frame index" ),
		FIELD( _field_word_flags, "user flags{playback flags}", &animation_index_flags ),
		FIELD( _field_real, "override blend in time{override blend time}" ),
		FIELD( _field_real, "override blend out time" ),
		FIELD( _field_short_block_index, "parent animation*!" ),
		FIELD( _field_short_block_index, "next animation*!" ),
		FIELD( _field_word_flags, "production flags", &production_status_flags ),
		FIELD( _field_short_block_index, "composite*" ),
		FIELD( _field_explanation, "PCA Group Link" ),
		FIELD( _field_string_id, "pca group name" ),
		FIELD( _field_explanation, "Shared Animation Data" ),
		FIELD( _field_struct, "shared animation reference!", &shared_animation_reference_block_struct_definition ),
		FIELD( _field_block, "shared animation data", &shared_model_animation_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(new_animation_blend_screen_block, k_animation_maximum_blend_screens)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_flags, "flags", &blend_screen_definition_flags ),
		FIELD( _field_real, "weight" ),
		FIELD( _field_real_fraction, "interpolation rate:[0,1]#A value of zero or one means no interpolation." ),
		FIELD( _field_pad, "nabsbfp0", 2 ),
		FIELD( _field_enum, "yaw source", &blend_screen_variable_sources ),
		FIELD( _field_enum, "pitch source", &blend_screen_variable_sources ),
		FIELD( _field_enum, "weight source", &blend_screen_weight_sources ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "yaw source object function" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "pitch source object function" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "weight source object function" ),
		FIELD( _field_short_block_index, "weight function#Function applied to input from weight function source" ),
		FIELD( _field_pad, "nabsbfp1", 2 ),
		FIELD( _field_struct, "animation{animation info}", &animation_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(new_animation_function_overlay_block, k_animation_maximum_function_overlays)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_flags, "flags", &function_overlay_definition_flags ),
		FIELD( _field_explanation, "Frame Ratio or Playback Speed" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "frame ratio object function" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "playback speed object function" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "blend weight object function" ),
		FIELD( _field_struct, "animation", &animation_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(blend_screen_item_definition_block, k_animation_maximum_mixing_board_pose_overlays)
	{
		FIELD( _field_short_block_index, "blend screen^" ),
		FIELD( _field_word_flags, "flags", &pose_overlay_item_definition_block_flags ),
		FIELD( _field_short_block_index, "node mask" ),
		FIELD( _field_pad, "bsidbfp", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(function_overlay_item_definition_block, k_animation_maximum_function_overlays)
	{
		FIELD( _field_short_block_index, "function overlay^" ),
		FIELD( _field_word_flags, "flags", &pose_overlay_item_definition_block_flags ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(overlay_group_definition_block, k_animation_maximum_overlay_groups)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "blend screens{blend screen}|CCBBAA", &blend_screen_item_definition_block_block ),
		FIELD( _field_block, "function overlays|CCBBAA", &function_overlay_item_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_gait_block, k_animation_maximum_gaits)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "slow gait name" ),
		FIELD( _field_string_id, "intermediate gait name#animation name used for the speed variations" ),
		FIELD( _field_string_id, "fast gait name" ),
		FIELD( _field_enum, "move state", &animation_gait_directions ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_gait_item_block, k_animation_maximum_gaits)
	{
		FIELD( _field_short_block_index, "animation gait^" ),
		FIELD( _field_pad, "agibfap", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_gait_group_block, k_animation_maximum_gait_groups)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "animation gaits", &animation_gait_item_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_ik_block, k_max_ik_points)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "source marker#the marker name on this object where the point of attachment is" ),
		FIELD( _field_long_enum, "attach to", &animation_ik_target_enum_definition ),
		FIELD( _field_string_id, "destination marker#the marker name of the attachment destination point" ),
		FIELD( _field_real_point_3d, "pole marker" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_ik_set_item, k_max_ik_points_per_set)
	{
		FIELD( _field_short_block_index, "ik point^" ),
		FIELD( _field_word_flags, "flags", &animation_ik_set_item_flags ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_ik_set, k_max_ik_sets)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "ik points|CCBBAA", &animation_ik_set_item_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_ik_chain_block, k_animation_maximum_ik_chains)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_enum, "type", &animation_ik_chain_type_enumeration ),
		FIELD( _field_pad, "aikcbp", 2 ),
		FIELD( _field_short_block_index, "start node{grandparent node}" ),
		FIELD( _field_short_block_index, "effector node" ),
		FIELD( _field_short_integer, "rank!#calculated during post process where rank is default ordinal for solving" ),
		FIELD( _field_short_integer, "antecedents!#calculated during post process where bit index represents chain index" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(PCAGroupSettingsBlock, k_max_animations_per_graph)
	{
		FIELD( _field_string_id, "Group Name^" ),
		FIELD( _field_long_integer, "Desired Mesh Count" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_entry_block, k_max_animations_per_block)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_short_block_index, "overlay group{pose overlay|overlay}" ),
		FIELD( _field_short_block_index, "ik set" ),
		FIELD( _field_struct, "animation", &animation_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_region_block, k_total_damage_regions)
	{
		FIELD( _field_struct, "animation*", &animation_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_direction_block, k_total_damage_directions)
	{
		FIELD( _field_block, "regions*|AABBCC", &damage_region_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_animation_block, k_max_death_and_damage_actions)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_block, "directions*|AABBCC", &damage_direction_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_transition_destination_block, k_max_transition_animations)
	{
		FIELD( _field_string_id, "mode name#name of the mode this transition ends in" ),
		FIELD( _field_string_id, "state name#name of the state this transition ends in" ),
		FIELD( _field_struct, "animation", &animation_index_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_transition_source_block, k_max_animations_per_block)
	{
		FIELD( _field_string_id, "state name^#name of the state this transition starts in" ),
		FIELD( _field_block, "destinations", &animation_transition_destination_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_velocity_boundaries_block, 1)
	{
		FIELD( _field_array, "velocity boundary entries!", &animation_velocity_boundaries_array ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_set_block, k_max_animation_sets)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_short_block_index, "overlay group{pose overlay|overlay}" ),
		FIELD( _field_short_block_index, "ik set" ),
		FIELD( _field_short_block_index, "gait group|AABBCC" ),
		FIELD( _field_pad, "asbfap", 2 ),
		FIELD( _field_block, "actions|AABBCC", &animation_entry_block_block ),
		FIELD( _field_block, "overlay animations{overlays}|AABBCC", &animation_entry_block_block ),
		FIELD( _field_block, "death and damage|AABBCC", &damage_animation_block_block ),
		FIELD( _field_block, "transitions|AABBCC", &animation_transition_source_block_block ),
		FIELD( _field_block, "velocity boundaries!", &animation_velocity_boundaries_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(weapon_type_block, k_max_weapon_types)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_short_block_index, "overlay group{pose overlay|overlay}" ),
		FIELD( _field_short_block_index, "ik set" ),
		FIELD( _field_block, "sets|AABBCC", &animation_set_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_ik_block_v1, k_max_ik_points)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker#the marker name on the object being attached" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "attach to marker#the marker name object (weapon, vehicle, etc.) the above marker is being attached to" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(ranged_animation_entry_block, k_max_animations_per_block)
	{
		FIELD( _field_short_block_index, "overlay group{pose overlay|overlay}" ),
		FIELD( _field_short_block_index, "ik set" ),
		FIELD( _field_struct, "animation", &animation_index_struct_struct_definition ),
		FIELD( _field_real, "animation parameter#Numerical value associated with the ranged action animation (e.g. velocity for jumps)" ),
		FIELD( _field_real, "animation parameter b" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(triangulation_point_block, k_max_triangulation_tag_points)
	{
		FIELD( _field_real_vector_2d, "point" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(triangulation_triangle_block, k_max_triangulation_tag_triangles)
	{
		FIELD( _field_byte_integer, "vertex1" ),
		FIELD( _field_byte_integer, "vertex2" ),
		FIELD( _field_byte_integer, "vertex3" ),
		FIELD( _field_byte_integer, "link12" ),
		FIELD( _field_byte_integer, "link23" ),
		FIELD( _field_byte_integer, "link31" ),
		FIELD( _field_pad, "aaah", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(triangulation_entry_block, 1)
	{
		FIELD( _field_block, "points", &triangulation_point_block_block ),
		FIELD( _field_block, "triangles", &triangulation_triangle_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_ranged_action_block, k_max_ranged_actions)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_block, "animations", &ranged_animation_entry_block_block ),
		FIELD( _field_block, "triangulation data!", &triangulation_entry_block_block ),
		FIELD( _field_enum, "horizontal source", &ranged_action_variable_sources ),
		FIELD( _field_enum, "vertical source", &ranged_action_variable_sources ),
		FIELD( _field_enum, "start key", &frame_event_type_new ),
		FIELD( _field_enum, "end key", &frame_event_type_new ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_sync_action_same_type_participant, k_max_sync_action_participants)
	{
		FIELD( _field_long_flags, "flags", &animation_sync_action_flags_definition ),
		FIELD( _field_struct, "animation", &animation_index_struct_struct_definition ),
		FIELD( _field_real_point_3d, "start offset*" ),
		FIELD( _field_real_vector_3d, "start facing*" ),
		FIELD( _field_real_point_3d, "end offset*" ),
		FIELD( _field_real, "time_until_hurt*" ),
		FIELD( _field_real_point_3d, "apex offset*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_sync_action_other_type_participant, k_max_sync_action_participants)
	{
		FIELD( _field_long_flags, "flags", &animation_sync_action_other_type_flags_definition ),
		FIELD( _field_tag_reference, "object type" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_sync_action_block, k_max_sync_actions)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "same type participants", &animation_sync_action_same_type_participant_block ),
		FIELD( _field_block, "other participants", &animation_sync_action_other_type_participant_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_sync_action_group_block, k_max_sync_action_groups)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "sync actions", &animation_sync_action_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(weapon_class_block, k_max_weapon_classes)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_short_block_index, "overlay group{pose overlay|overlay}" ),
		FIELD( _field_short_block_index, "ik set" ),
		FIELD( _field_block, "weapon type|AABBCC", &weapon_type_block_block ),
		FIELD( _field_block, "weapon ik|AABBCC", &animation_ik_block_v1_block ),
		FIELD( _field_block, "ranged actions", &animation_ranged_action_block_block ),
		FIELD( _field_block, "sync actions groups", &animation_sync_action_group_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(foot_tracking_defaults, k_max_tracked_feet)
	{
		FIELD( _field_short_block_index, "foot" ),
		FIELD( _field_enum, "default state", &foot_tracking_default_values ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(animation_mode_block, k_max_modes_per_graph)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_short_block_index, "overlay group{pose overlay|overlay}" ),
		FIELD( _field_short_block_index, "ik set" ),
		FIELD( _field_long_flags, "flags*", &animation_mode_flags ),
		FIELD( _field_block, "weapon class|AABBCC", &weapon_class_block_block ),
		FIELD( _field_block, "mode ik|AABBCC", &animation_ik_block_v1_block ),
		FIELD( _field_block, "foot defaults|AABBCC", &foot_tracking_defaults_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vehicle_suspension_block, k_max_vehicle_suspensions)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_struct, "animation*", &animation_index_struct_struct_definition ),
		FIELD( _field_string_id, "function name" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "marker name#this marker should be parented to the vehicle root node" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "contact marker name#this marker should be parented to the wheel node" ),
		FIELD( _field_real, "mass point offset#distance along the vehicle\'s up direction to move the wheel from the marker location" ),
		FIELD( _field_real, "full extension ground_depth!" ),
		FIELD( _field_real, "full compression ground_depth!" ),
		FIELD( _field_explanation, "Destroyed Suspension" ),
		FIELD( _field_string_id, "region name" ),
		FIELD( _field_real, "destroyed mass point offset" ),
		FIELD( _field_real, "destroyed full extension ground_depth!" ),
		FIELD( _field_real, "destroyed full compression ground_depth!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(function_overlay_animation_block, k_max_function_overlays_per_graph)
	{
		FIELD( _field_string_id, "label^" ),
		FIELD( _field_struct, "animation*", &animation_index_struct_struct_definition ),
		FIELD( _field_pad, "VQWLKE", 2 ),
		FIELD( _field_enum, "function controls", &function_overlay_animation_mode ),
		FIELD( _field_string_id, "function" ),
		FIELD( _field_pad, "OHIOJE", 4 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(inherited_animation_node_map_block, k_max_nodes_per_animation)
	{
		FIELD( _field_short_integer, "local node" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(inherited_animation_node_map_flag_block, k_max_nodes_per_animation)
	{
		FIELD( _field_long_integer, "local node flags" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(inherited_animation_block, k_max_animation_inheritence_levels)
	{
		FIELD( _field_tag_reference, "inherited graph*" ),
		FIELD( _field_block, "node map*", &inherited_animation_node_map_block_block ),
		FIELD( _field_block, "node map flags*", &inherited_animation_node_map_flag_block_block ),
		FIELD( _field_long_integer, "inheritance_flags*" ),
		FIELD( _field_real, "uniform translation scale*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(weapon_class_lookup_block, k_max_weapon_types)
	{
		FIELD( _field_string_id, "weapon name^" ),
		FIELD( _field_string_id, "weapon class" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(additional_node_data_block, k_max_nodes_per_animation)
	{
		FIELD( _field_string_id, "node name^" ),
		FIELD( _field_real_quaternion, "default rotation*" ),
		FIELD( _field_real_point_3d, "default translation*" ),
		FIELD( _field_real, "default scale*" ),
		FIELD( _field_real_point_3d, "min bounds" ),
		FIELD( _field_real_point_3d, "max bounds" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_animation_tag_resource_group, k_max_animations_per_graph*3)
	{
		FIELD( _field_long_integer, "reference_count*" ),
		FIELD( _field_pageable, "tag_resource" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(shared_static_data_codec_rotation_block, k_max_animations_per_graph * k_max_nodes_per_animation)
	{
		FIELD( _field_short_integer, "i" ),
		FIELD( _field_short_integer, "j" ),
		FIELD( _field_short_integer, "k" ),
		FIELD( _field_short_integer, "w" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(shared_static_data_codec_translation_block, k_max_animations_per_graph * k_max_nodes_per_animation)
	{
		FIELD( _field_real, "x" ),
		FIELD( _field_real, "y" ),
		FIELD( _field_real, "z" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(shared_static_data_codec_scale_block, k_max_animations_per_graph * k_max_nodes_per_animation)
	{
		FIELD( _field_real, "scale" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(g_node_flag_storage_array, c_node_flags::k_flag_chunk_count)
	{
		FIELD( _field_long_integer, "flag data" ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(animation_velocity_boundaries, k_animation_maximum_velocity_boundary_entries)
	{
		FIELD( _field_real, "values!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(frame_event_list_struct_definition)
	{
		FIELD( _field_explanation, "IMPORTANT TAG NOTES" ),
		FIELD( _field_block, "sound references|ABCDCC", &animation_graph_sound_reference_block_block ),
		FIELD( _field_block, "effect references|ABCDCC", &animation_graph_effect_reference_block_block ),
		FIELD( _field_block, "frame events|ABCDCC", &import_animation_event_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_graph_definitions_struct)
	{
		FIELD( _field_explanation, "GRAPH DATA" ),
		FIELD( _field_tag_reference, "parent animation graph" ),
		FIELD( _field_byte_flags, "inheritance flags", &public_animation_graph_flags ),
		FIELD( _field_byte_flags, "private flags*", &private_animation_graph_flags ),
		FIELD( _field_short_integer, "animation codec pack*" ),
		FIELD( _field_enum, "force compression setting*", &compression_force_settings ),
		FIELD( _field_word_flags, "misc graph flags", &animation_graph_misc_flags ),
		FIELD( _field_long_integer, "skeleton checksum" ),
		FIELD( _field_long_integer, "skeleton checksum lite" ),
		FIELD( _field_tag_reference, "imported events|ABCDCC" ),
		FIELD( _field_block, "node usage*|ABCDCC", &animation_usage_block_block ),
		FIELD( _field_block, "node masks|ABCDCC", &animation_node_mask_block_block ),
		FIELD( _field_block, "functions|ABCDCC", &animation_function_block_block ),
		FIELD( _field_block, "model animation variants|ABCDCC", &model_animation_variant_block_block ),
		FIELD( _field_block, "skeleton nodes*|ABCDCC", &animation_graph_node_block_block ),
		FIELD( _field_block, "sound references|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_graph_sound_reference_block_block ),
		FIELD( _field_block, "effect references|ABCDCC!*#Legacy field - please edit in new frame event tag below", &animation_graph_effect_reference_block_block ),
		FIELD( _field_block, "blend screens|ABCDCC!*#Legacy field - please edit in NEW blend screens tag below", &animation_blend_screen_block_block ),
		FIELD( _field_block, "foot markers|ABCDCC", &foot_tracking_member_block_block ),
		FIELD( _field_block, "animations*|ABCDCC", &animation_pool_block_block ),
		FIELD( _field_block, "NEW blend screens|CCBBAA", &new_animation_blend_screen_block_block ),
		FIELD( _field_block, "NEW function overlays|CCAABB", &new_animation_function_overlay_block_block ),
		FIELD( _field_block, "overlay groups{pose overlays|NEW overlays}|CCBBAA", &overlay_group_definition_block_block ),
		FIELD( _field_block, "gaits|ABCDCC", &animation_gait_block_block ),
		FIELD( _field_block, "gait groups|ABCDCC", &animation_gait_group_block_block ),
		FIELD( _field_block, "ik data|CCBBAA", &animation_ik_block_block ),
		FIELD( _field_block, "ik sets|CCBBAA", &animation_ik_set_block ),
		FIELD( _field_block, "ik chains|CCBBAA", &animation_ik_chain_block_block ),
		FIELD( _field_block, "composites", &g_compositeTag_block ),
		FIELD( _field_struct, "pca data", &PCAAnimationDataStruct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_aiming_screen_struct)
	{
		FIELD( _field_angle, "right yaw per frame" ),
		FIELD( _field_angle, "left yaw per frame" ),
		FIELD( _field_short_integer, "right frame count" ),
		FIELD( _field_short_integer, "left frame count" ),
		FIELD( _field_angle, "down pitch per frame" ),
		FIELD( _field_angle, "up pitch per frame" ),
		FIELD( _field_short_integer, "down pitch frame count" ),
		FIELD( _field_short_integer, "up pitch frame count" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(shared_animation_reference_block)
	{
		FIELD( _field_tag_reference, "graph reference!" ),
		FIELD( _field_short_block_index, "shared animation index!" ),
		FIELD( _field_pad, "sarbp", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(quantized_orientation_struct)
	{
		FIELD( _field_short_integer, "rotation x*" ),
		FIELD( _field_short_integer, "rotation y*" ),
		FIELD( _field_short_integer, "rotation z*" ),
		FIELD( _field_short_integer, "rotation w*" ),
		FIELD( _field_real_point_3d, "default translation*" ),
		FIELD( _field_real, "default scale*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_ik_chain_events_struct)
	{
		FIELD( _field_explanation, "REFERENCE IK CHAIN INFO" ),
		FIELD( _field_string_id, "chain name" ),
		FIELD( _field_enum, "chain type", &animation_ik_chain_type_enumeration ),
		FIELD( _field_short_block_index, "chain start node" ),
		FIELD( _field_short_block_index, "chain effector node" ),
		FIELD( _field_explanation, "IMPORTED IK CHAIN INFO" ),
		FIELD( _field_enum, "chain usage", &animation_ik_chain_event_usage ),
		FIELD( _field_string_id, "proxy marker" ),
		FIELD( _field_long_integer, "proxy id" ),
		FIELD( _field_char_enum, "event type", &animation_ik_chain_event_type ),
		FIELD( _field_byte_integer, "effector transform data index" ),
		FIELD( _field_byte_integer, "effector weight data index" ),
		FIELD( _field_byte_integer, "pole point data index" ),
		FIELD( _field_explanation, "POST PROCESS IK CHAIN INFO" ),
		FIELD( _field_byte_integer, "chain index" ),
		FIELD( _field_pad, "aikcep", 3 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_ik_chain_proxies_struct)
	{
		FIELD( _field_long_integer, "id" ),
		FIELD( _field_custom ),
		FIELD( _field_string_id, "target marker" ),
		FIELD( _field_byte_integer, "proxy transform data index" ),
		FIELD( _field_pad, "aikcpp", 3 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_facial_wrinkle_events_struct)
	{
		FIELD( _field_explanation, "REFERENCE FACIAL WRINKLE EVENT INFO" ),
		FIELD( _field_string_id, "wrinkle name" ),
		FIELD( _field_real, "default value" ),
		FIELD( _field_explanation, "IMPORTED FACIAL WRINKLE INFO" ),
		FIELD( _field_short_integer, "start frame" ),
		FIELD( _field_short_integer, "frame count" ),
		FIELD( _field_char_enum, "region", &animation_facial_wrinkle_region ),
		FIELD( _field_pad, "PADDNG", 3 ),
		FIELD( _field_explanation, "POST PROCESS WRINKLE EVENT INFO" ),
		FIELD( _field_short_integer, "wrinkle data index" ),
		FIELD( _field_pad, "aikcep", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_extended_events_struct)
	{
		FIELD( _field_explanation, "IMPORTED EXTENDED DATA EVENT INFO" ),
		FIELD( _field_string_id, "name" ),
		FIELD( _field_short_integer, "start frame" ),
		FIELD( _field_short_integer, "frame count" ),
		FIELD( _field_real, "default value" ),
		FIELD( _field_short_integer, "data index" ),
		FIELD( _field_pad, "pants", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_object_functions_struct)
	{
		FIELD( _field_string_id, "real_name!*" ),
		FIELD( _field_long_enum, "name", &animation_object_function_name ),
		FIELD( _field_short_integer, "start frame" ),
		FIELD( _field_short_integer, "frame count" ),
		FIELD( _field_struct, "function curve", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_index_struct)
	{
		FIELD( _field_short_integer, "graph index!" ),
		FIELD( _field_short_block_index, "animation" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(PCAAnimationDataStruct)
	{
		FIELD( _field_explanation, "Group Settings" ),
		FIELD( _field_block, "PCA Groups", &PCAGroupSettingsBlock_block ),
		FIELD( _field_explanation, "PCA Animation Tag" ),
		FIELD( _field_tag_reference, "pca animation|ABCDCC" ),
		FIELD( _field_long_integer, "PCA Animation Count*!" ),
		FIELD( _field_long_integer, "PCA Checksum*!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_graph_contents_struct)
	{
		FIELD( _field_explanation, "MODE-n-STATE GRAPH" ),
		FIELD( _field_short_block_index, "default gait group|CCAABB" ),
		FIELD( _field_pad, "agcsfap", 2 ),
		FIELD( _field_block, "modes|AABBCC", &animation_mode_block_block ),
		FIELD( _field_explanation, "SPECIAL CASE ANIMS" ),
		FIELD( _field_block, "vehicle suspension|CCAABB", &vehicle_suspension_block_block ),
		FIELD( _field_block, "function overlays{object overlays}|CCAABB", &function_overlay_animation_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(model_animation_runtime_data_struct)
	{
		FIELD( _field_explanation, "RUN-TIME DATA" ),
		FIELD( _field_block, "inheritence list*|BBAAAA", &inherited_animation_block_block ),
		FIELD( _field_block, "new inheritance list*|BBAAAA", &inherited_animation_block_block ),
		FIELD( _field_block, "weapon list|BBAAAA", &weapon_class_lookup_block_block ),
		FIELD( _field_array, "left arm bit vector!", &g_node_flag_storage_array_array ),
		FIELD( _field_array, "right arm bit vector!", &g_node_flag_storage_array_array ),
		FIELD( _field_data, "animationPlayCounts!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(animation_codec_data_struct)
	{
		FIELD( _field_explanation, "CODEC-SPECIFIC DATA" ),
		FIELD( _field_struct, "shared_static_codec*!", &shared_static_data_codec_graph_data_struct_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(shared_static_data_codec_graph_data_struct)
	{
		FIELD( _field_explanation, "Shared Static Codec" ),
		FIELD( _field_block, "rotations*!", &shared_static_data_codec_rotation_block_block ),
		FIELD( _field_block, "translations*!", &shared_static_data_codec_translation_block_block ),
		FIELD( _field_block, "scale*!", &shared_static_data_codec_scale_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(node_joint_flags, 3)
	{
		OPTION("ball-socket"),
		OPTION("hinge"),
		OPTION("no movement"),
	};

	TAG_ENUM(node_info_flags, 1)
	{
		OPTION("important for imposter"),
	};

	TAG_ENUM(animation_node_model_flags, 6)
	{
		OPTION("primary model"),
		OPTION("secondary model"),
		OPTION("local root"),
		OPTION("left hand"),
		OPTION("right hand"),
		OPTION("left arm member"),
	};

	TAG_ENUM(key_event_flags_enum, 8)
	{
		OPTION("allow on player"),
		OPTION("left arm only"),
		OPTION("right arm only"),
		OPTION("first-person only"),
		OPTION("third-person only"),
		OPTION("forward only"),
		OPTION("reverse only"),
		OPTION("fp no aged weapons"),
	};

	TAG_ENUM(key_event_internal_flags_enum, 1)
	{
		OPTION("model_index_required"),
	};

	TAG_ENUM(animation_type_enum, 4)
	{
		OPTION("none"),
		OPTION("base"),
		OPTION("overlay"),
		OPTION("replacement"),
	};

	TAG_ENUM(frame_info_type_enum, 7)
	{
		OPTION("none"),
		OPTION("dx,dy"),
		OPTION("dx,dy,dyaw"),
		OPTION("dx,dy,dz,dyaw"),
		OPTION("dx,dy,dz,dangle-axis"),
		OPTION("x,y,z - absolute"),
		OPTION("auto"),
	};

	TAG_ENUM(internal_animation_flags, 11)
	{
		OPTION("<unused0>!"),
		OPTION("world relative"),
		OPTION("<unused1>!"),
		OPTION("<unused3>!"),
		OPTION("<unused2>!"),
		OPTION("resource_group"),
		OPTION("compression disabled"),
		OPTION("old production checksum"),
		OPTION("valid production checksum"),
		OPTION("override force compression"),
		OPTION("contains pca data"),
	};

	TAG_ENUM(frame_event_type_new, 27)
	{
		OPTION("none"),
		OPTION("primary keyframe{primary_keyframe}"),
		OPTION("secondary keyframe{secondary_keyframe}"),
		OPTION("tertiary keyframe"),
		OPTION("left foot{left_foot}"),
		OPTION("right foot{right_foot}"),
		OPTION("allow interruption{allow_interruption}"),
		OPTION("do not allow interruption"),
		OPTION("both-feet shuffle"),
		OPTION("body impact"),
		OPTION("left foot lock"),
		OPTION("left foot unlock"),
		OPTION("right foot lock"),
		OPTION("right foot unlock"),
		OPTION("blend range marker"),
		OPTION("stride expansion"),
		OPTION("stride contraction"),
		OPTION("ragdoll keyframe"),
		OPTION("drop weapon keyframe"),
		OPTION("match a"),
		OPTION("match b"),
		OPTION("match c"),
		OPTION("match d"),
		OPTION("jetpack closed"),
		OPTION("jetpack open"),
		OPTION("sound event"),
		OPTION("effect event"),
	};

	TAG_ENUM(compression_settings, 6)
	{
		OPTION("best score&medium compression"),
		OPTION("best compression&rough compression"),
		OPTION("best accuracy&uncompressed"),
		OPTION("old codec"),
		OPTION("reach medium compression"),
		OPTION("reach rough compression"),
	};

	TAG_ENUM(compression_force_settings, 7)
	{
		OPTION("none"),
		OPTION("medium compression"),
		OPTION("rough compression"),
		OPTION("uncompressed"),
		OPTION("old codec"),
		OPTION("reach medium compression"),
		OPTION("reach rough compression"),
	};

	TAG_ENUM(animation_dialogue_event_enum, 15)
	{
		OPTION("bump"),
		OPTION("dive"),
		OPTION("evade"),
		OPTION("lift"),
		OPTION("sigh"),
		OPTION("contempt"),
		OPTION("anger"),
		OPTION("fear"),
		OPTION("relief"),
		OPTION("sprint"),
		OPTION("sprint_end"),
		OPTION("ass_grabber"),
		OPTION("kill_ass"),
		OPTION("ass_grabbed"),
		OPTION("die_ass"),
	};

	TAG_ENUM(animation_index_flags, 16)
	{
		OPTION("disable interpolation in{disable interpolation_in}"),
		OPTION("disable interpolation out{disable interpolation_out}"),
		OPTION("disable mode ik"),
		OPTION("disable weapon ik"),
		OPTION("disable weapon aim/1st person"),
		OPTION("disable look screen"),
		OPTION("disable transition adjustment"),
		OPTION("force weapon ik on"),
		OPTION("use custom blend-in time#when possible, interpolate into this animation using the \'blend in\' time value below"),
		OPTION("enable animated source interpolation"),
		OPTION("disable ik sets"),
		OPTION("disable ik chains"),
		OPTION("translate and scale root only#ignore all transtion and scale on all nodes except the root"),
		OPTION("enable blend-out on replacement anims#fade out this animation as they reach the end of the animation."),
		OPTION("use custom blend-out time#when possible, fade this animation out over the \'blend out\' time below (requires \'enable blend-out\' above, replacement anims only)"),
		OPTION("override player input with motion#use the movement data in this anim instead of player physics (player only)"),
	};

	TAG_ENUM(production_status_flags, 6)
	{
		OPTION("do not monitor changes"),
		OPTION("verify sound events"),
		OPTION("do not inherit for player graphs"),
		OPTION("has errors or warnings"),
		OPTION("keep raw data in tag"),
		OPTION("allow ball-roll on foot#prevents foot-ik from settling"),
	};

	TAG_ENUM(object_space_node_flags, 4)
	{
		OPTION("rotation"),
		OPTION("translation"),
		OPTION("scale"),
		OPTION("motion root"),
	};

	TAG_ENUM(foot_tracking_default_values, 2)
	{
		OPTION("off"),
		OPTION("on"),
	};

	TAG_ENUM(animation_ik_chain_type_enumeration, 1)
	{
		OPTION("standard"),
	};

	TAG_ENUM(animation_ik_chain_event_usage, 7)
	{
		OPTION("none"),
		OPTION("world"),
		OPTION("self"),
		OPTION("parent"),
		OPTION("primary weapon"),
		OPTION("secondary weapon"),
		OPTION("assassination"),
	};

	TAG_ENUM(animation_ik_chain_event_type, 2)
	{
		OPTION("active"),
		OPTION("passive"),
	};

	TAG_ENUM(animation_facial_wrinkle_region, 8)
	{
		OPTION("Upper Brow"),
		OPTION("Center Brow"),
		OPTION("Left Squint"),
		OPTION("Right Squint"),
		OPTION("Left Smile"),
		OPTION("Right Smile"),
		OPTION("Left Sneer"),
		OPTION("Right Sneer"),
	};

	TAG_ENUM(animation_object_function_name, 4)
	{
		OPTION("animation_object_function_a"),
		OPTION("animation_object_function_b"),
		OPTION("animation_object_function_c"),
		OPTION("animation_object_function_d"),
	};

	TAG_ENUM(ranged_action_variable_sources, 7)
	{
		OPTION("none"),
		OPTION("offset x"),
		OPTION("offset y"),
		OPTION("offset z"),
		OPTION("offset horizontal"),
		OPTION("negative offset x"),
		OPTION("negative offset y"),
	};

	TAG_ENUM(blend_screen_definition_flags, 3)
	{
		OPTION("active only when weapon down"),
		OPTION("attempt piece-wise blending"),
		OPTION("allow parent adjustment"),
	};

	TAG_ENUM(function_overlay_definition_flags, 1)
	{
		OPTION("strict looping#loop without blending the first and last frames"),
	};

	TAG_ENUM(blend_screen_variable_sources, 43)
	{
		OPTION("none"),
		OPTION("object function"),
		OPTION("horizontal test"),
		OPTION("vertical test"),
		OPTION("aim yaw"),
		OPTION("aim pitch"),
		OPTION("look yaw"),
		OPTION("look pitch"),
		OPTION("object yaw"),
		OPTION("object pitch"),
		OPTION("acceleration yaw"),
		OPTION("acceleration pitch"),
		OPTION("steering"),
		OPTION("velocity yaw"),
		OPTION("velocity pitch"),
		OPTION("damage gut yaw"),
		OPTION("damage gut pitch"),
		OPTION("damage chest yaw"),
		OPTION("damage chest pitch"),
		OPTION("damage head yaw"),
		OPTION("damage head pitch"),
		OPTION("damage left shoulder yaw"),
		OPTION("damage left shoulder pitch"),
		OPTION("damage left arm yaw"),
		OPTION("damage left arm pitch"),
		OPTION("damage left leg yaw"),
		OPTION("damage left leg pitch"),
		OPTION("damage left foot yaw"),
		OPTION("damage left foot pitch"),
		OPTION("damage right shoulder yaw"),
		OPTION("damage right shoulder pitch"),
		OPTION("damage right arm yaw"),
		OPTION("damage right arm pitch"),
		OPTION("damage right leg yaw"),
		OPTION("damage right leg pitch"),
		OPTION("damage right foot yaw"),
		OPTION("damage right foot pitch"),
		OPTION("defense yaw"),
		OPTION("defense pitch"),
		OPTION("first person pitch"),
		OPTION("first person turn"),
		OPTION("throttle side"),
		OPTION("throttle_forward"),
	};

	TAG_ENUM(blend_screen_weight_sources, 20)
	{
		OPTION("none"),
		OPTION("object function"),
		OPTION("acceleration magnitude"),
		OPTION("velocity magnitude"),
		OPTION("state function a"),
		OPTION("state function b"),
		OPTION("state function c"),
		OPTION("state function d"),
		OPTION("damage chest{damage focus chest}"),
		OPTION("damage gut{damage focus gut}"),
		OPTION("damage head{damage focus head}"),
		OPTION("damage left shoulder{damage focus left shoulder}"),
		OPTION("damage left arm{damage focus left arm}"),
		OPTION("damage left leg{damage focus left leg}"),
		OPTION("damage left foot{damage focus left foot}"),
		OPTION("damage right shoulder{damage focus right shoulder}"),
		OPTION("damage right arm{damage focus right arm}"),
		OPTION("damage right leg{damage focus right leg}"),
		OPTION("damage right foot{damage focus right foot}"),
		OPTION("defense"),
	};

	TAG_ENUM(pose_overlay_item_definition_block_flags, 1)
	{
		OPTION("disable"),
	};

	TAG_ENUM(animation_gait_directions, 6)
	{
		OPTION("move_front"),
		OPTION("move_back"),
		OPTION("move_left"),
		OPTION("move_right"),
		OPTION("turn_left"),
		OPTION("turn_right"),
	};

	TAG_ENUM(animation_ik_target_enum_definition, 4)
	{
		OPTION("parent"),
		OPTION("NYI any child"),
		OPTION("primary weapon"),
		OPTION("secondary weapon"),
	};

	TAG_ENUM(animation_ik_set_item_flags, 1)
	{
		OPTION("disable"),
	};

	TAG_ENUM(animation_sync_action_flags_definition, 4)
	{
		OPTION("Initiator"),
		OPTION("Critical Participant"),
		OPTION("Disabled"),
		OPTION("Airborne"),
	};

	TAG_ENUM(animation_sync_action_other_type_flags_definition, 2)
	{
		OPTION("Supports any type"),
		OPTION("Disabled"),
	};

	TAG_ENUM(animation_mode_flags, 1)
	{
		OPTION("this is a stance"),
	};

	TAG_ENUM(function_overlay_animation_mode, 2)
	{
		OPTION("frame"),
		OPTION("scale"),
	};

	TAG_ENUM(animation_usage_enumeration, 25)
	{
		OPTION("physics control"),
		OPTION("camera control"),
		OPTION("origin marker"),
		OPTION("left clavicle"),
		OPTION("left upperarm"),
		OPTION("pose blend pitch"),
		OPTION("pose blend yaw"),
		OPTION("pedestal"),
		OPTION("pelvis"),
		OPTION("left foot"),
		OPTION("right foot"),
		OPTION("damage root gut"),
		OPTION("damage root chest"),
		OPTION("damage root head"),
		OPTION("damage root left shoulder"),
		OPTION("damage root left arm"),
		OPTION("damage root left leg"),
		OPTION("damage root left foot"),
		OPTION("damage root right shoulder"),
		OPTION("damage root right arm"),
		OPTION("damage root right leg"),
		OPTION("damage root right foot"),
		OPTION("left hand"),
		OPTION("right hand"),
		OPTION("weapon ik"),
	};

	TAG_ENUM(model_animation_variant_flags, 1)
	{
		OPTION("needs mandible replacement"),
	};

	TAG_ENUM(private_animation_graph_flags, 7)
	{
		OPTION("prepared for cache"),
		OPTION("use a single mixing board{unused smelly flag}"),
		OPTION("imported with codec compressors"),
		OPTION("uses data driven animation"),
		OPTION("written to cache"),
		OPTION("animation data reordered"),
		OPTION("ready for use"),
	};

	TAG_ENUM(public_animation_graph_flags, 2)
	{
		OPTION("inherit root trans scale only"),
		OPTION("inherit for use on player"),
	};

	TAG_ENUM(animation_graph_misc_flags, 1)
	{
		OPTION("ignore gaits"),
	};

} // namespace blofeld

