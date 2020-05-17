#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(performance_template, PERFORMANCE_TEMPLATE_TAG)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "script name#The name of a custom script used to drive the performance. If none is given, a default script is uses that goes through the lines in sequence" ),
		FIELD( _field_block, "Actors", &performance_template_actor_block_block ),
		FIELD( _field_block, "Lines", &scenario_performance_line_block_block ),
		FIELD( _field_block, "Points", &performance_template_point_block_block ),
		FIELD( _field_terminator )
	};

	TAG_GROUP_FROM_BLOCK(scenario, SCENARIO_TAG, scenario_block_block );

	TAG_GROUP_FROM_BLOCK(scenario_required_resource, SCENARIO_REQUIRED_RESOURCE_TAG, scenario_required_resource_block_block );

	TAG_BLOCK(scenario_profiles_block, MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_real_fraction, "starting health damage:[0,1]" ),
		FIELD( _field_real_fraction, "starting shield damage:[0,1]" ),
		FIELD( _field_tag_reference, "primary weapon" ),
		FIELD( _field_short_integer, "primaryrounds loaded#-1 = weapon default" ),
		FIELD( _field_short_integer, "primaryrounds total#-1 = weapon default" ),
		FIELD( _field_real, "primaryage remaining#0.0 = default, 1.0 = full" ),
		FIELD( _field_tag_reference, "secondary weapon" ),
		FIELD( _field_short_integer, "secondaryrounds loaded#-1 = weapon default" ),
		FIELD( _field_short_integer, "secondaryrounds total#-1 = weapon default" ),
		FIELD( _field_real, "secondaryage remaining#0.0 = default, 1.0 = full" ),
		FIELD( _field_char_integer, "starting fragmentation grenade count" ),
		FIELD( _field_char_integer, "starting plasma grenade count" ),
		FIELD( _field_char_integer, "starting grenade 3 count" ),
		FIELD( _field_char_integer, "starting grenade 4 count" ),
		FIELD( _field_char_integer, "starting grenade 5 count" ),
		FIELD( _field_char_integer, "starting grenade 6 count" ),
		FIELD( _field_char_integer, "starting grenade 7 count" ),
		FIELD( _field_char_integer, "starting grenade 8 count" ),
		FIELD( _field_tag_reference, "starting equipment" ),
		FIELD( _field_string_id, "starting tactical package" ),
		FIELD( _field_string_id, "starting support upgrade" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_pad, "AHDVHJE", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(performance_template_actor_block, MAXIMUM_ACTORS_PER_PERFORMANCE)
	{
		FIELD( _field_long_flags, "flags", &scenario_performance_actor_flags_definition ),
		FIELD( _field_string_id, "Actor name^" ),
		FIELD( _field_tag_reference, "Actor type" ),
		FIELD( _field_tag_reference, "Vehicle type" ),
		FIELD( _field_string_id, "Vehicle seat label" ),
		FIELD( _field_tag_reference, "Weapon type" ),
		FIELD( _field_pad, "pad0", 2 ),
		FIELD( _field_custom_short_block_index, "Spawn Point" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_script_fragment_block, MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_enum, "fragment placement", &scenario_performance_fragment_placement_definition ),
		FIELD( _field_enum, "fragment type", &scenario_performance_fragment_type_definition ),
		FIELD( _field_long_string, "fragment#maximum 256 characters, type just branch condition (with brackets) in case of branches" ),
		FIELD( _field_long_string, "branch target#the script to branch to (with any arguments to it). Used only if type is branch" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_point_interaction_block, MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_long_flags, "interaction type", &scenario_performance_line_point_interaction_type_definition ),
		FIELD( _field_custom_short_block_index, "point" ),
		FIELD( _field_custom_short_block_index, "actor" ),
		FIELD( _field_string_id, "object name" ),
		FIELD( _field_string_id, "throttle style" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_animation_block, MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_word_flags, "flags", &scenario_performance_line_animation_flags_definition ),
		FIELD( _field_pad, "pad0", 2 ),
		FIELD( _field_string_id, "stance" ),
		FIELD( _field_string_id, "animation^" ),
		FIELD( _field_real, "duration" ),
		FIELD( _field_real, "probability" ),
		FIELD( _field_real, "throttle transition time:seconds" ),
		FIELD( _field_long_integer, "transition frame count#The number of frames from the end of the animation to start transitioning out" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_sync_action_actor_block, MAXIMUM_ACTORS_PER_PERFORMANCE)
	{
		FIELD( _field_custom_short_block_index, "Actor type" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_sync_action_block, MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_string_id, "sync action name" ),
		FIELD( _field_real, "probability" ),
		FIELD( _field_custom_short_block_index, "attach to point" ),
		FIELD( _field_word_flags, "flags", &scenario_performance_line_sync_action_flag_type_definition ),
		FIELD( _field_block, "Actors", &scenario_performance_line_sync_action_actor_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_scenery_sync_action_block, MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_string_id, "scenery object name" ),
		FIELD( _field_string_id, "sync action name" ),
		FIELD( _field_string_id, "stance name" ),
		FIELD( _field_real, "probability" ),
		FIELD( _field_word_flags, "flags", &scenario_performance_line_scenery_sync_action_flag_type_definition ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_block, "Actors", &scenario_performance_line_sync_action_actor_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_dialog_block, MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_string_id, "dialog" ),
		FIELD( _field_real, "probability" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_sound_block, MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE)
	{
		FIELD( _field_tag_reference, "sound effect" ),
		FIELD( _field_custom_short_block_index, "attach to point" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_string_id, "attach to object named" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_line_block, MAXIMUM_LINES_PER_PERFORMANCE)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_custom_short_block_index, "Actor" ),
		FIELD( _field_word_flags, "flags", &scenario_performance_line_flags ),
		FIELD( _field_short_integer, "sleep minimum:ticks" ),
		FIELD( _field_short_integer, "sleep maximum:ticks" ),
		FIELD( _field_long_enum, "Line progress type", &scenario_performance_line_progress_definition ),
		FIELD( _field_block, "Script fragments", &scenario_performance_line_script_fragment_block_block ),
		FIELD( _field_block, "Point interaction", &scenario_performance_line_point_interaction_block_block ),
		FIELD( _field_block, "Animations", &scenario_performance_line_animation_block_block ),
		FIELD( _field_block, "Sync Actions", &scenario_performance_line_sync_action_block_block ),
		FIELD( _field_block, "Scenery Sync Actions", &scenario_performance_line_scenery_sync_action_block_block ),
		FIELD( _field_block, "Dialog lines", &scenario_performance_line_dialog_block_block ),
		FIELD( _field_block, "Sounds", &scenario_performance_line_sound_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(performance_template_point_block, 32)
	{
		FIELD( _field_string_id, "Point name^" ),
		FIELD( _field_real_vector_3d, "Relative Position#The offset of the performance point from the center of the performance" ),
		FIELD( _field_real_euler_angles_2d, "Relative Facing#The facing at the point in the space of the performance" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioBspReferenceBlock, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "structure design^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_child_references_block, MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "tag^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_structure_bsp_reference_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "structure bsp^" ),
		FIELD( _field_tag_reference, "local structure bsp^*!" ),
		FIELD( _field_tag_reference, "structure metadata*" ),
		FIELD( _field_explanation, "Size Class" ),
		FIELD( _field_long_enum, "size class", &scenario_structure_size_enum ),
		FIELD( _field_long_enum, "refinement size class", &scenario_structure_refinement_size_enum ),
		FIELD( _field_real, "hacky ambient min luminance" ),
		FIELD( _field_real, "direct/draft ambient min luminance" ),
		FIELD( _field_real, "structure vertex sink#this is the most that we can sink a soft surface link snow in the structure_bsp via vertex painting." ),
		FIELD( _field_word_flags, "flags", &scenario_structure_bsp_reference_flags_definition ),
		FIELD( _field_short_block_index, "default sky" ),
		FIELD( _field_tag_reference, "bsp specific cubemap" ),
		FIELD( _field_tag_reference, "wind" ),
		FIELD( _field_tag_reference, "authored light probe" ),
		FIELD( _field_tag_reference, "vehicle authored light probe" ),
		FIELD( _field_real, "max shadow count scale#scale up or down the max number of shadows as set in the throttle tag per bsp" ),
		FIELD( _field_real, "decorator sunlight minimum:[0.0 to 1.0]#0.0 means allow fully dark in the shadows, higher values will brighten up the shadowed decorators" ),
		FIELD( _field_custom, "volumetric light shafts" ),
		FIELD( _field_struct, "volumetric light shaft settings", &scenarioVolumetricLightShaftSettingsStruct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "floating shadows" ),
		FIELD( _field_struct, "floating shadow settings", &scenarioFloatingShadowSettingsStruct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_explanation, "Clones" ),
		FIELD( _field_long_block_flags, "cloned bsp flags" ),
		FIELD( _field_struct, "lightmap setting{lightmap resolution buckets}", &scenario_lightmap_setting_struct_struct_definition ),
		FIELD( _field_real, "custom gravity scale#0==nogravity, 1==full, set the custom gravity scale flag to make this parameter active" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_design_reference_block, MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "structure design^" ),
		FIELD( _field_tag_reference, "local structure design^*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_sky_reference_block, MAXIMUM_SKIES_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "sky" ),
		FIELD( _field_real, "cloud scale#mapping to the world unit" ),
		FIELD( _field_real, "cloud speed#cloud movement speed" ),
		FIELD( _field_real, "cloud direction#cloud movement direction, 0-360 degree" ),
		FIELD( _field_tag_reference, "cloud texture#red channel is used" ),
		FIELD( _field_short_block_index, "name^" ),
		FIELD( _field_pad, "post-name-pad", 2 ),
		FIELD( _field_long_block_flags, "active on bsps!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_bsp_checksum_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_dword_integer, "bsp checksum*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_cluster_pvs_bit_vector_block, ((((MAXIMUM_CLUSTERS_PER_STRUCTURE)+(k_int32_bits-1))>>k_int32_bits_bits)))
	{
		FIELD( _field_dword_integer, "dword*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_bsp_bits_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_block, "bits*!", &scenario_zone_set_cluster_pvs_bit_vector_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_cluster_pvs_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_block, "cluster pvs bit vectors*!", &scenario_zone_set_bsp_bits_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_cluster_reference_block, MAXIMUM_CLUSTERS_PER_STRUCTURE*MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_char_integer, "bsp index*!" ),
		FIELD( _field_byte_integer, "cluster index*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_bsp_seam_cluster_mappings_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_block, "root clusters*!", &scenario_zone_set_cluster_reference_block_block ),
		FIELD( _field_block, "attached clusters*!", &scenario_zone_set_cluster_reference_block_block ),
		FIELD( _field_block, "connected clusters*!", &scenario_zone_set_cluster_reference_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_bsp_pvs_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_block, "cluster pvs*!", &scenario_zone_set_cluster_pvs_block_block ),
		FIELD( _field_block, "cluster pvs doors closed*!", &scenario_zone_set_cluster_pvs_block_block ),
		FIELD( _field_block, "bsp cluster mapings*!", &scenario_zone_set_bsp_seam_cluster_mappings_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_pvs_block, k_maximum_scenario_zone_set_count+1)
	{
		FIELD( _field_dword_integer, "structure bsp mask*!" ),
		FIELD( _field_short_integer, "version*!" ),
		FIELD( _field_word_flags, "flags*!", &scenario_zone_set_pvs_flags ),
		FIELD( _field_block, "bsp checksums*!", &scenario_zone_set_bsp_checksum_block_block ),
		FIELD( _field_block, "structure bsp pvs*!", &scenario_zone_set_bsp_pvs_block_block ),
		FIELD( _field_block, "portal=>device mapping*!", &structure_portal_device_mapping_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_budget_override_block, 1)
	{
		FIELD( _field_long_integer, "env bitmap:megs" ),
		FIELD( _field_long_integer, "env object bitmap:megs" ),
		FIELD( _field_long_integer, "env geometry:megs" ),
		FIELD( _field_long_integer, "env object geometry:megs" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_lipsync_block, SHORT_MAX)
	{
		FIELD( _field_tag_reference, "dummy" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_zone_set_block, k_maximum_scenario_zone_set_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_string, "name string*!" ),
		FIELD( _field_long_block_index, "pvs index*!" ),
		FIELD( _field_long_flags, "flags", &scenario_zone_set_flags_definition ),
		FIELD( _field_long_block_flags, "bsp zone flags" ),
		FIELD( _field_long_block_flags, "structure design zone flags" ),
		FIELD( _field_long_block_flags, "runtime bsp zone flags*!" ),
		FIELD( _field_long_block_flags, "sruntime tructure design zone flags*!" ),
		FIELD( _field_long_block_flags, "required designer zones{designer zone flags}" ),
		FIELD( _field_qword_integer, "runtime designer zone flags*!" ),
		FIELD( _field_long_block_flags, "cinematic zones" ),
		FIELD( _field_long_block_index, "hint previous zone set" ),
		FIELD( _field_long_block_index, "audibility index*!" ),
		FIELD( _field_block, "planar fog visibility*!", &planar_fog_zone_set_visibility_definition_block_block ),
		FIELD( _field_block, "budget overrides", &scenario_zone_set_budget_override_block_block ),
		FIELD( _field_tag_reference, "streaming_reference_tag" ),
		FIELD( _field_real_point_3d, "world bounds min#Physics world will include this min point" ),
		FIELD( _field_real_point_3d, "world bounds max#Physics world will include this max point" ),
		FIELD( _field_block, "lipsync sounds", &scenario_zone_set_lipsync_block_block ),
		FIELD( _field_tag_reference, "cinematic soundbank#only for cinematics. If you try to use this for anything else without talking to me, i will stab you in the face" ),
		FIELD( _field_real_rgb_color, "sky clear color#linear color, must check override flag above to use" ),
		FIELD( _field_pad, "pad4", 4 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_lighting_zone_set_block, k_maximum_scenario_zone_set_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_block_flags, "rendered bsp flags" ),
		FIELD( _field_long_block_flags, "extra bsp flags" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_function_block, MAXIMUM_FUNCTIONS_PER_SCENARIO)
	{
		FIELD( _field_long_flags, "flags", &scenario_function_flags ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_real, "period:seconds#this is the period for the above function (lower values make the function oscillate quickly, higher values make it oscillate slowly)" ),
		FIELD( _field_short_block_index, "scale period by#multiply this function by the above period" ),
		FIELD( _field_enum, "function", &global_periodic_functions_enum ),
		FIELD( _field_short_block_index, "scale function by#multiply this function by the result of the above function" ),
		FIELD( _field_enum, "wobble function#the curve used for the wobble", &global_periodic_functions_enum ),
		FIELD( _field_real, "wobble period:seconds#the length of time it takes for the magnitude of this function to complete a wobble" ),
		FIELD( _field_real, "wobble magnitude:percent#the amount of random wobble in the magnitude" ),
		FIELD( _field_real_fraction, "square wave threshold#if non-zero, all values above the square wave threshold are snapped to 1.0, and all values below it are snapped to 0.0 to create a square wave." ),
		FIELD( _field_short_integer, "step count#the number of discrete values to snap to (e.g., a step count of 5 would snap the function to 0.00,0.25,0.50,0.75 or 1.00)" ),
		FIELD( _field_enum, "map to", &global_transition_functions_enum ),
		FIELD( _field_short_integer, "sawtooth count#the number of times this function should repeat (e.g., a sawtooth count of 5 would give the function a value of 1.0 at each of 0.25,0.50,0.75 as well as at 1.0" ),
		FIELD( _field_pad, "WBP", 2 ),
		FIELD( _field_short_block_index, "scale result by#multiply this function (from a weapon, vehicle, etc.) final result of all of the above math" ),
		FIELD( _field_enum, "bounds mode#controls how the bounds, below, are used", &function_bounds_mode_enum ),
		FIELD( _field_real_fraction_bounds, "bounds" ),
		FIELD( _field_real, "runtime inverse bounds range!" ),
		FIELD( _field_pad, "OFLIM", 2 ),
		FIELD( _field_short_block_index, "turn off with#if the specified function is off, so is this function" ),
		FIELD( _field_pad, "FX", 16 ),
		FIELD( _field_real, "runtime reciprocal sawtooth count!" ),
		FIELD( _field_real, "runtime reciprocal bounds range!" ),
		FIELD( _field_real, "runtime reciprocal step count!" ),
		FIELD( _field_real, "runtime one over period!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(editor_comment_block, MAXIMUM_EDITOR_COMMENTS)
	{
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_long_enum, "type!", &editor_comment_type_enum_definition ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_string, "comment" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(dont_use_me_scenario_environment_object_block, MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "bsp*" ),
		FIELD( _field_short_integer, "runtime object type!" ),
		FIELD( _field_long_integer, "unique id*" ),
		FIELD( _field_pad, "WOQHKQB", 4 ),
		FIELD( _field_tag, "object definition tag*" ),
		FIELD( _field_long_integer, "object*^" ),
		FIELD( _field_pad, "YMRTLZ", 44 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_object_names_block, MAXIMUM_OBJECT_NAMES_PER_SCENARIO)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_custom_short_block_index, "object_type!" ),
		FIELD( _field_custom_short_block_index, "scenario_datum_index!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioAttachedEffectsBlock, ScenarioAttachedEffect::k_maxLoopingEffectsAllowed)
	{
		FIELD( _field_long_integer, "cutscene flag index" ),
		FIELD( _field_tag_reference, "effect reference^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioAttachedLensFlaresBlock, ScenarioAttachedEffect::k_maxLensFlaresAllowed)
	{
		FIELD( _field_long_integer, "cutscene flag index" ),
		FIELD( _field_tag_reference, "lens flare reference^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioAttachedLightConesBlock, ScenarioAttachedLightCone::k_maxLightConesAllowed)
	{
		FIELD( _field_long_integer, "cutscene flag index" ),
		FIELD( _field_tag_reference, "light cone reference^" ),
		FIELD( _field_real_argb_color, "color" ),
		FIELD( _field_real_point_2d, "size" ),
		FIELD( _field_real, "intensity" ),
		FIELD( _field_tag_reference, "intensity curve" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_soft_ceilings_block, MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO)
	{
		FIELD( _field_word_flags, "flags", &scenario_soft_ceiling_flags_definition ),
		FIELD( _field_word_flags, "runtime flags*!", &scenario_soft_ceiling_flags_definition ),
		FIELD( _field_string_id, "name" ),
		FIELD( _field_enum, "type", &soft_ceiling_type_enum ),
		FIELD( _field_pad, "my name is", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_players_block, MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK)
	{
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_angle, "facing:degrees" ),
		FIELD( _field_angle, "pitch:degrees" ),
		FIELD( _field_short_integer, "insertion point index" ),
		FIELD( _field_word_flags, "flags", &scenario_player_flags ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_pad, "ANDYNDGE", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(trigger_volume_point_block, k_maximum_points_per_sector)
	{
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_2d, "normal" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(trigger_volume_runtime_triangles_block, k_maximum_points_per_sector-2)
	{
		FIELD( _field_real_plane_3d, "plane 0*!" ),
		FIELD( _field_real_plane_3d, "plane 1*!" ),
		FIELD( _field_real_plane_3d, "plane 2*!" ),
		FIELD( _field_real_plane_3d, "plane 3*!" ),
		FIELD( _field_real_plane_3d, "plane 4*!" ),
		FIELD( _field_real_point_2d, "vertex 0*!" ),
		FIELD( _field_real_point_2d, "vertex 1*!" ),
		FIELD( _field_real_point_2d, "vertex 2*!" ),
		FIELD( _field_pad, "pad0", 8 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(scenario_trigger_volume_block, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO, scenario_trigger_volume_struct_struct_definition );

	TAG_BLOCK(scenario_zone_set_switch_trigger_volume_block, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
	{
		FIELD( _field_word_flags, "flags", &scenario_zone_set_switch_trigger_volume_flags_definition ),
		FIELD( _field_short_block_index, "begin zone set" ),
		FIELD( _field_short_block_index, "trigger volume" ),
		FIELD( _field_short_block_index, "commit zone set" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_decals_block, MAXIMUM_DECALS_PER_SCENARIO)
	{
		FIELD( _field_custom ),
		FIELD( _field_short_block_index, "decal palette index" ),
		FIELD( _field_byte_flags, "flags", &decal_placement_flags ),
		FIELD( _field_pad, "post-decal-palette-index-pad", 1 ),
		FIELD( _field_struct, "manual bsp flags*", &manualBspFlagsReferences_struct_definition ),
		FIELD( _field_real_quaternion, "rotation*" ),
		FIELD( _field_real_point_3d, "position*" ),
		FIELD( _field_real, "scale x{scale}" ),
		FIELD( _field_real, "scale y" ),
		FIELD( _field_real, "cull angle" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_decal_palette_block, MAXIMUM_DECAL_PALETTES_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "reference^" ),
		FIELD( _field_long_integer, "max static bucket size*!" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_detail_object_collection_palette_block, MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE)
	{
		FIELD( _field_tag_reference, "name^" ),
		FIELD( _field_pad, "XBMYUIKEJ", 32 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cutscene_flag_block, MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO)
	{
		FIELD( _field_pad, "MMNGQBXC", 4 ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_3d, "facing" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_short_block_index, "source bsp*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cutscene_camera_point_block, MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO)
	{
		FIELD( _field_word_flags, "flags", &scenario_cutscene_camera_flags ),
		FIELD( _field_enum, "type", &scenario_cutscene_camera_types ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_custom ),
		FIELD( _field_pad, "pad", 4 ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_3d, "orientation" ),
		FIELD( _field_short_block_index, "zone set" ),
		FIELD( _field_pad, "padd", 2 ),
		FIELD( _field_useless_pad ),
		FIELD( _field_useless_pad ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_kill_trigger_volumes_block, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
	{
		FIELD( _field_short_block_index, "trigger volume" ),
		FIELD( _field_byte_flags, "flags", &kill_volume_flags ),
		FIELD( _field_pad, "pad", 1 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_safe_zone_trigger_volumes_block, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
	{
		FIELD( _field_short_block_index, "trigger volume" ),
		FIELD( _field_byte_flags, "flags", &kill_volume_flags ),
		FIELD( _field_pad, "pad", 1 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(trigger_volume_mopp_code_block, 1)
	{
		FIELD( _field_long_integer, "trigger volume checksum" ),
		FIELD( _field_block, "mopp code*!", &mopp_code_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_requisition_trigger_volumes_block, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
	{
		FIELD( _field_short_block_index, "trigger volume" ),
		FIELD( _field_word_flags, "flags", &scenario_requisition_trigger_volume_flags_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_location_name_trigger_volumes_block, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
	{
		FIELD( _field_short_block_index, "trigger volume" ),
		FIELD( _field_string, "name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioUnsafeSpawnZoneTriggerVolumesBlock, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
	{
		FIELD( _field_short_block_index, "trigger volume" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_atmosphere_palette_block, MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE)
	{
		FIELD( _field_string_id, "name!" ),
		FIELD( _field_word_integer, "Atmosphere Setting Index!" ),
		FIELD( _field_pad, "XQLJZUE", 2 ),
		FIELD( _field_tag_reference, "atmosphere^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_camera_fx_palette_block, MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "cluster camera_fx tag:if empty, uses default#if empty, uses default" ),
		FIELD( _field_byte_flags, "flags", &camera_fx_palette_flags ),
		FIELD( _field_pad, "EKJFER", 3 ),
		FIELD( _field_real, "forced exposure:stops#the target exposure (ONLY USED WHEN FORCE EXPOSURE IS CHECKED)" ),
		FIELD( _field_real, "forced auto-exposure screen brightness:[0.0001-1]#how bright you want the screen to be (ONLY USED WHEN FORCE AUTO EXPOSURE IS CHECKED)" ),
		FIELD( _field_real, "exposure min:stops" ),
		FIELD( _field_real, "exposure max:stops" ),
		FIELD( _field_real, "inherent bloom" ),
		FIELD( _field_real, "bloom intensity" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_weather_palette_block, MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "rain" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cluster_points_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_real_point_3d, "centroid*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cluster_acoustics_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_short_block_index, "type^" ),
		FIELD( _field_pad, "XQQ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cluster_atmosphere_properties_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_short_block_index, "type^" ),
		FIELD( _field_pad, "XQQ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cluster_camera_fx_properties_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_short_block_index, "type^" ),
		FIELD( _field_pad, "XQQ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cluster_weather_properties_block, MAXIMUM_CLUSTERS_PER_STRUCTURE)
	{
		FIELD( _field_short_block_index, "type^" ),
		FIELD( _field_pad, "XQQ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cluster_data_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		FIELD( _field_tag_reference, "bsp^*" ),
		FIELD( _field_long_integer, "bsp checksum*" ),
		FIELD( _field_block, "cluster centroids*", &scenario_cluster_points_block_block ),
		FIELD( _field_long_block_index, "default acoustic palette" ),
		FIELD( _field_block, "acoustics{background sounds}*", &scenario_cluster_acoustics_block_block ),
		FIELD( _field_block, "atmospheric properties*", &scenario_cluster_atmosphere_properties_block_block ),
		FIELD( _field_block, "camera fx properties*", &scenario_cluster_camera_fx_properties_block_block ),
		FIELD( _field_block, "weather properties*", &scenario_cluster_weather_properties_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_spawn_data_block, 1)
	{
		FIELD( _field_real, "game object reset height" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(SoundSubtitleBlock, MAXIMUM_SUBTITLES_PER_SCENARIO)
	{
		FIELD( _field_long_integer, "tagIndex" ),
		FIELD( _field_string_id, "subtitleName" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cheap_particle_system_palette_block, s_scenario_cheap_particle_emitter_palette_entry::k_maximum_scenario_cheap_particle_system_palette_entries)
	{
		FIELD( _field_tag_reference, "definition^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cheap_particle_systems_block, s_scenario_cheap_particle_system::k_maximum_scenario_cheap_particle_systems)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_pad, "VLKSJLER", 2 ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_3d, "rotation" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_cinematic_lighting_palette_block, k_maximum_scenario_cinematic_lighting_palette_entry_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_tag_reference, "cinematic_lighting_tag" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_airprobes_block, k_max_airprobes_per_scenario)
	{
		FIELD( _field_real_point_3d, "airprobe position" ),
		FIELD( _field_string_id, "airprobe name^" ),
		FIELD( _field_long_integer, "BSP index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_budget_references_block, k_maximum_budget_references_per_scenario)
	{
		FIELD( _field_tag_reference, "reference^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(model_references_block, SHORT_MAX)
	{
		FIELD( _field_tag_reference, "model reference^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_actor_block, MAXIMUM_ACTORS_PER_PERFORMANCE)
	{
		FIELD( _field_long_flags, "flags", &scenario_performance_actor_flags_definition ),
		FIELD( _field_string_id, "Actor name^" ),
		FIELD( _field_short_block_index, "Actor type" ),
		FIELD( _field_short_block_index, "Weapon type" ),
		FIELD( _field_short_block_index, "Vehicle type" ),
		FIELD( _field_custom_short_block_index, "debug spawn point" ),
		FIELD( _field_string_id, "Vehicle seat label" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performance_task_block, MAXIMUM_TASKS_PER_PERFORMANCE)
	{
		FIELD( _field_short_block_index, "objective" ),
		FIELD( _field_custom_short_block_index, "task" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenario_performances_block, MAXIMUM_PERFORMANCES_PER_SCENARIO)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "script name#The name of a custom script used to drive the performance. If none is given, a default script is uses that goes through the lines in sequence" ),
		FIELD( _field_string_id, "global name#The name of a script global that will be declared for this performance." ),
		FIELD( _field_word_flags, "flags", &performance_flags ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_custom_short_block_index, "Point set" ),
		FIELD( _field_pad, "padding", 2 ),
		FIELD( _field_block, "Actors", &scenario_performance_actor_block_block ),
		FIELD( _field_block, "Lines", &scenario_performance_line_block_block ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_real_euler_angles_2d, "template facing" ),
		FIELD( _field_real, "thespian radius{performance radius}#The radius inside which actors have to be in order to start." ),
		FIELD( _field_real, "attraction radius#The radius inside which actors become attracted to the thespian origin." ),
		FIELD( _field_real_fraction, "attraction probability per second:[0,1]#The probability that an actor be attracted once inside the thespian radius, every second." ),
		FIELD( _field_string_id, "template" ),
		FIELD( _field_long_integer, "template index!" ),
		FIELD( _field_block, "tasks!", &scenario_performance_task_block_block ),
		FIELD( _field_custom ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioRandomOrdnanceDropPointBlock, k_maximum_random_ordnance_drop_points)
	{
		FIELD( _field_short_block_index, "Drop point" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioRandomOrdnanceDropSetBlock, k_maximum_scenario_ordnance_drop_sets)
	{
		FIELD( _field_word_flags, "drop set flags", &ordnance_dropset_flags ),
		FIELD( _field_pad, "ODSF", 2 ),
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_integer, "count" ),
		FIELD( _field_tag_reference, "Ordnance List" ),
		FIELD( _field_block, "Drop point list", &scenarioRandomOrdnanceDropPointBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(ScenarioUnitRecordingBlock, k_maximum_unit_recordings_per_scenario, ScenarioUnitRecordingBlock_struct_struct_definition );

	TAG_BLOCK(loadScreenReferenceBlock, SHORT_MAX)
	{
		FIELD( _field_explanation, "Map IDs" ),
		FIELD( _field_long_integer, "Map ID#Only valid for main menu - otherwise always use first reference" ),
		FIELD( _field_tag_reference, "Load Screen Reference" ),
		FIELD( _field_real, "Tint Gradient Lookup V Coordinate#Value between 0.0 and 1.0 determines which line to use for tint.\nA negative value will choose a random tint from the palette." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(scenario_block, 1, scenario_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(scenario_required_resource_block, 1, scenario_required_resource_struct_definition_struct_definition );

	TAG_ARRAY(scenarioFloatingShadowCascadeSettingsArray, 4)
	{
		FIELD( _field_custom, "CASCADE" ),
		FIELD( _field_real, "cascade half-width" ),
		FIELD( _field_real, "cascade length" ),
		FIELD( _field_real, "cascade offset" ),
		FIELD( _field_real, "bias" ),
		FIELD( _field_real, "filter width" ),
		FIELD( _field_real, "sun direction offset#if we want to slide the frustum up closer to the sun so that not as much of the frustum is below the ground" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

	TAG_ARRAY(object_salt_storage_array, k_maximum_number_of_object_salts)
	{
		FIELD( _field_long_integer, "salt!*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(manualBspFlagsReferences)
	{
		FIELD( _field_custom, "manual bsp flags" ),
		FIELD( _field_block, "references block*!", &scenarioBspReferenceBlock_block ),
		FIELD( _field_long_integer, "flags*!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_struct_definition)
	{
		FIELD( _field_block, "child scenarios", &scenario_child_references_block_block ),
		FIELD( _field_custom, "link to scenario lightmap" ),
		FIELD( _field_enum, "type", &scenario_type_enum ),
		FIELD( _field_word_flags, "flags", &scenario_flags ),
		FIELD( _field_long_flags, "runtime trigger volume flags*!", &scenario_runtime_trigger_volume_flags ),
		FIELD( _field_long_integer, "campaign id" ),
		FIELD( _field_long_integer, "map id" ),
		FIELD( _field_string_id, "map name#Used to associate external resources with this map - e.g. PDA camera setting block names." ),
		FIELD( _field_tag_reference, "Scenario sound bank#Scenario-specific sound bank." ),
		FIELD( _field_tag_reference, "Scenario sound bank Number 2#Another scenario-specific sound bank. All will be loaded." ),
		FIELD( _field_tag_reference, "Scenario sound bank Number 3#Another scenario-specific sound bank. All will be loaded." ),
		FIELD( _field_tag_reference, "Scenario sound bank Number 4#Another scenario-specific sound bank. All will be loaded." ),
		FIELD( _field_string_id, "Inside reverb name#This reverb will be used for inside areas when the listener is outside." ),
		FIELD( _field_long_integer, "Inside reverb hash ID!" ),
		FIELD( _field_short_integer, "sound permutation mission id" ),
		FIELD( _field_pad, "pad", 2 ),
		FIELD( _field_long_integer, "minimum structure bsp importer version*!" ),
		FIELD( _field_angle, "local north" ),
		FIELD( _field_real, "local sea level:wu#used to calculate aircraft altitude" ),
		FIELD( _field_real, "altitude cap:wu" ),
		FIELD( _field_real_point_3d, "sandbox origin point#forge coordinates are relative to this point" ),
		FIELD( _field_real, "sandbox budget" ),
		FIELD( _field_string_id, "default vehicle set#when vehicle set is \"map default,\" this vehicle set is used" ),
		FIELD( _field_tag_reference, "game performance throttles{performance thorttles}" ),
		FIELD( _field_block, "structure bsps", &scenario_structure_bsp_reference_block_block ),
		FIELD( _field_block, "structure designs", &scenario_design_reference_block_block ),
		FIELD( _field_tag_reference, "structure seams" ),
		FIELD( _field_tag_reference, "local structure seams*!" ),
		FIELD( _field_block, "skies", &scenario_sky_reference_block_block ),
		FIELD( _field_block, "zone set pvs*!", &scenario_zone_set_pvs_block_block ),
		FIELD( _field_block, "zone set audibility*!", &game_audibility_block_block ),
		FIELD( _field_block, "zone sets", &scenario_zone_set_block_block ),
		FIELD( _field_block, "lighting zone sets!", &scenario_lighting_zone_set_block_block ),
		FIELD( _field_block, "predicted resources*", &g_null_block_block ),
		FIELD( _field_block, "functions", &scenario_function_block_block ),
		FIELD( _field_data, "editor scenario data" ),
		FIELD( _field_block, "comments", &editor_comment_block_block ),
		FIELD( _field_block, "unused scenario environment objects!", &dont_use_me_scenario_environment_object_block_block ),
		FIELD( _field_block, "object names*", &scenario_object_names_block_block ),
		FIELD( _field_block, "scenery", &scenario_scenery_block_block ),
		FIELD( _field_block, "scenery palette", &scenario_scenery_palette_block_block ),
		FIELD( _field_block, "bipeds", &scenario_biped_block_block ),
		FIELD( _field_block, "biped palette", &scenario_biped_palette_block_block ),
		FIELD( _field_block, "vehicles", &scenario_vehicle_block_block ),
		FIELD( _field_block, "vehicle palette", &scenario_vehicle_palette_block_block ),
		FIELD( _field_block, "equipment", &scenario_equipment_block_block ),
		FIELD( _field_block, "equipment palette", &scenario_equipment_palette_block_block ),
		FIELD( _field_block, "weapons", &scenario_weapon_block_block ),
		FIELD( _field_block, "weapon palette", &scenario_weapon_palette_block_block ),
		FIELD( _field_block, "device groups", &device_group_block_block ),
		FIELD( _field_block, "machines", &scenario_machine_block_block ),
		FIELD( _field_block, "machine palette", &scenario_machine_palette_block_block ),
		FIELD( _field_block, "terminals", &scenario_terminal_block_block ),
		FIELD( _field_block, "terminal palette", &scenario_terminal_palette_block_block ),
		FIELD( _field_block, "controls", &scenario_control_block_block ),
		FIELD( _field_block, "control palette", &scenario_control_palette_block_block ),
		FIELD( _field_block, "dispensers", &ScenarioDispenserBlock_block ),
		FIELD( _field_block, "dispenser palette", &ScenarioDispenserPaletteBlock_block ),
		FIELD( _field_block, "sound scenery", &scenario_sound_scenery_block_block ),
		FIELD( _field_block, "sound scenery palette", &scenario_sound_scenery_palette_block_block ),
		FIELD( _field_block, "giants", &scenario_giant_block_block ),
		FIELD( _field_block, "giant palette", &scenario_giant_palette_block_block ),
		FIELD( _field_block, "effect scenery", &scenario_effect_scenery_block_block ),
		FIELD( _field_block, "effect scenery palette", &scenario_effect_scenery_palette_block_block ),
		FIELD( _field_block, "spawners", &scenario_spawner_block_block ),
		FIELD( _field_block, "spawner palette", &scenario_spawner_palette_block_block ),
		FIELD( _field_block, "bink palette", &binkPaletteBlock_block ),
		FIELD( _field_block, "scenario attached effects", &scenarioAttachedEffectsBlock_block ),
		FIELD( _field_block, "scenario attached lens flares", &scenarioAttachedLensFlaresBlock_block ),
		FIELD( _field_block, "scenario attached light cones", &scenarioAttachedLightConesBlock_block ),
		FIELD( _field_block, "map variant palettes", &map_variant_palette_block_block ),
		FIELD( _field_tag_reference, "multiplayer object types" ),
		FIELD( _field_char_enum, "multiplayer map size", &multiplayer_map_size_enum ),
		FIELD( _field_pad, "mulmapsizepad", 3 ),
		FIELD( _field_block, "Playtest req palette#requisition for SvE, activated via an init.txt option for playtest balance", &scenario_requisition_palette_block_block ),
		FIELD( _field_real, "player requisition frequency:seconds" ),
		FIELD( _field_long_integer, "initial game currency:SpaceBucks" ),
		FIELD( _field_block, "soft ceilings", &scenario_soft_ceilings_block_block ),
		FIELD( _field_block, "player starting profile", &scenario_profiles_block_block ),
		FIELD( _field_block, "player starting locations", &scenario_players_block_block ),
		FIELD( _field_block, "trigger volumes", &scenario_trigger_volume_block_block ),
		FIELD( _field_block, "acoustic sectors", &scenario_acoustic_sector_block_block ),
		FIELD( _field_block, "acoustic transitions", &scenario_acoustic_transition_block_block ),
		FIELD( _field_block, "atmosphere dumplings", &scenario_atmosphere_dumpling_block_block ),
		FIELD( _field_block, "weather dumplings", &scenario_weather_dumpling_block_block ),
		FIELD( _field_block, "recorded animations", &recorded_animation_block_block ),
		FIELD( _field_block, "zone set switch trigger volumes~", &scenario_zone_set_switch_trigger_volume_block_block ),
		FIELD( _field_block, "named location volumes", &scenario_named_location_volume_block_block ),
		FIELD( _field_explanation, "SPAWN INFLUENCE OVERRIDES" ),
		FIELD( _field_tag_reference, "Spawn Settings" ),
		FIELD( _field_explanation, "RENDER FLUFF" ),
		FIELD( _field_block, "decals", &scenario_decals_block_block ),
		FIELD( _field_block, "decal palette", &scenario_decal_palette_block_block ),
		FIELD( _field_long_integer, "largest zoneset static decal memory size:kilobytes#this is memory for the largest possible zoneset - default (0) is 2048" ),
		FIELD( _field_data, "static decal memory data*" ),
		FIELD( _field_real, "decal depth bias override (USE WITH CAUTION)#you should not need to do this -- this is for a mission with strange collision geo" ),
		FIELD( _field_block, "detail object collection palette", &scenario_detail_object_collection_palette_block_block ),
		FIELD( _field_block, "style pallette", &style_palette_block_block ),
		FIELD( _field_block, "squad groups", &squad_groups_block_block ),
		FIELD( _field_block, "squads", &squads_block_block ),
		FIELD( _field_block, "zones", &zone_block_block ),
		FIELD( _field_block, "squad patrols", &squad_patrol_block_block ),
		FIELD( _field_block, "actual cues!", &ai_cue_block_block ),
		FIELD( _field_block, "full cues{cues}", &ai_full_cue_block_block ),
		FIELD( _field_block, "quick cues", &ai_quick_cue_block_block ),
		FIELD( _field_block, "mission scenes", &ai_scene_block_block ),
		FIELD( _field_block, "character palette", &character_palette_block_block ),
		FIELD( _field_tag_reference, "ai pathfinding data" ),
		FIELD( _field_block, "ai user hint data", &user_hint_block_block ),
		FIELD( _field_block, "ai recording references", &ai_recording_reference_block_block ),
		FIELD( _field_struct, "script data*!", &hs_script_data_struct_struct_definition ),
		FIELD( _field_block, "manual script file references", &hs_source_reference_block_block ),
		FIELD( _field_tag_reference, "compiled global scripts*!" ),
		FIELD( _field_block, "scripting data", &cs_script_data_block_block ),
		FIELD( _field_block, "cutscene flags", &scenario_cutscene_flag_block_block ),
		FIELD( _field_block, "cutscene camera points", &scenario_cutscene_camera_point_block_block ),
		FIELD( _field_block, "cutscene titles", &scenario_cutscene_title_block_block ),
		FIELD( _field_tag_reference, "custom object names" ),
		FIELD( _field_tag_reference, "chapter title text" ),
		FIELD( _field_block, "scenario kill triggers", &scenario_kill_trigger_volumes_block_block ),
		FIELD( _field_block, "scenario safe zone triggers", &scenario_safe_zone_trigger_volumes_block_block ),
		FIELD( _field_block, "scenario trigger volumes mopp code*!", &trigger_volume_mopp_code_block_block ),
		FIELD( _field_block, "scenario requisition triggers", &scenario_requisition_trigger_volumes_block_block ),
		FIELD( _field_block, "scenario location name triggers", &scenario_location_name_trigger_volumes_block_block ),
		FIELD( _field_block, "scenario unsafe spawn trigger volumes", &scenarioUnsafeSpawnZoneTriggerVolumesBlock_block ),
		FIELD( _field_short_block_index, "scenario ordnance bounds trigger volume" ),
		FIELD( _field_pad, "ordnandy", 2 ),
		FIELD( _field_block, "Orders", &orders_block_block ),
		FIELD( _field_block, "Triggers", &triggers_block_block ),
		FIELD( _field_block, "acoustics palette{background sound palette}", &scenario_acoustics_palette_block_definition_block ),
		FIELD( _field_block, "atmosphere", &scenario_atmosphere_palette_block_block ),
		FIELD( _field_block, "camera fx palette", &scenario_camera_fx_palette_block_block ),
		FIELD( _field_block, "weather palette", &scenario_weather_palette_block_block ),
		FIELD( _field_block, "scenario cluster data", &scenario_cluster_data_block_block ),
		FIELD( _field_array, "object_salts*", &object_salt_storage_array_array ),
		FIELD( _field_block, "spawn data", &scenario_spawn_data_block_block ),
		FIELD( _field_tag_reference, "sound effect collection" ),
		FIELD( _field_block, "crates", &scenario_crate_block_block ),
		FIELD( _field_block, "crate palette", &scenario_crate_palette_block_block ),
		FIELD( _field_block, "flock palette", &flock_palette_block_block ),
		FIELD( _field_block, "flocks", &flock_instance_block_block ),
		FIELD( _field_tag_reference, "subtitles" ),
		FIELD( _field_block, "soundSubtitles*!", &SoundSubtitleBlock_block ),
		FIELD( _field_block, "creatures", &scenario_creature_block_block ),
		FIELD( _field_block, "creature palette", &scenario_creature_palette_block_block ),
		FIELD( _field_block, "big battle creature palette", &big_battle_creature_palette_block_block ),
		FIELD( _field_block, "editor folders!", &g_scenario_editor_folder_block_block ),
		FIELD( _field_tag_reference, "game engine strings" ),
		FIELD( _field_pad, "QVUC", 4 ),
		FIELD( _field_block, "mission dialogue", &ai_scenario_mission_dialogue_block_block ),
		FIELD( _field_tag_reference, "voiceover" ),
		FIELD( _field_tag_reference, "objectives" ),
		FIELD( _field_tag_reference, "interpolators" ),
		FIELD( _field_block, "shared references", &hs_references_block_block ),
		FIELD( _field_tag_reference, "camera effects" ),
		FIELD( _field_tag_reference, "global screen effect#ignores the falloff curves" ),
		FIELD( _field_tag_reference, "global ssao" ),
		FIELD( _field_tag_reference, "atmosphere globals#settings that apply to the entire scenario" ),
		FIELD( _field_tag_reference, "new lightmaps" ),
		FIELD( _field_tag_reference, "performance throttles" ),
		FIELD( _field_block, "ai objectives", &objectives_block_block ),
		FIELD( _field_block, "designer zones", &scenario_designer_zone_block_block ),
		FIELD( _field_block, "zone debugger!", &scenario_zone_debugger_block_definition_block ),
		FIELD( _field_block, "decorators", &scenario_decorator_block_block ),
		FIELD( _field_block, "neuticle palette", &scenario_cheap_particle_system_palette_block_block ),
		FIELD( _field_block, "neuticles", &scenario_cheap_particle_systems_block_block ),
		FIELD( _field_explanation, "Scriptable Light Rigs" ),
		FIELD( _field_block, "scriptable light rigs", &scriptableLightRigBlock_block ),
		FIELD( _field_block, "cinematics", &scenario_cinematics_block_block ),
		FIELD( _field_block, "cinematic lighting palette", &scenario_cinematic_lighting_palette_block_block ),
		FIELD( _field_block, "override player representations", &player_representation_block_block ),
		FIELD( _field_block, "campaign metagame", &campaign_metagame_scenario_block_block ),
		FIELD( _field_block, "soft surfaces", &soft_surfaces_definition_block_block ),
		FIELD( _field_block, "cubemaps", &scenario_cubemap_block_block ),
		FIELD( _field_block, "airprobes", &scenario_airprobes_block_block ),
		FIELD( _field_block, "budget references", &scenario_budget_references_block_block ),
		FIELD( _field_block, "model references*", &model_references_block_block ),
		FIELD( _field_block, "thespian{performances}", &scenario_performances_block_block ),
		FIELD( _field_block, "puppetShows", &PuppetShowsBlock_block ),
		FIELD( _field_tag_reference, "location name globals" ),
		FIELD( _field_explanation, "garbage collection" ),
		FIELD( _field_block, "garbage collection", &garbage_collection_block_block ),
		FIELD( _field_tag_reference, "hud screen reference#appears for the player through the scenario" ),
		FIELD( _field_tag_reference, "required resources" ),
		FIELD( _field_tag_reference, "variant globals" ),
		FIELD( _field_tag_reference, "ordnance map bitmap" ),
		FIELD( _field_real_fraction_bounds, "ordnance map depth bounds" ),
		FIELD( _field_explanation, "Random ordnance" ),
		FIELD( _field_word_flags, "ordnance flags", &ordnance_flags ),
		FIELD( _field_pad, "SRO", 2 ),
		FIELD( _field_tag_reference, "drop pod (scenery)#if set, overrides that in progression globals" ),
		FIELD( _field_long_integer, "Ordnance drop count" ),
		FIELD( _field_long_integer, "Ordnance max active count#zero means unlimited" ),
		FIELD( _field_real_bounds, "Time between random drops:seconds" ),
		FIELD( _field_string, "Initial drop name" ),
		FIELD( _field_real, "Initial drop delay:seconds#from start of play til fanfare begins" ),
		FIELD( _field_real, "Initial drop fanfare duration:seconds" ),
		FIELD( _field_string, "Normal drop name:blank string will match all sets" ),
		FIELD( _field_string, "Player drop name" ),
		FIELD( _field_real, "Nav marker visibility proximity:wu" ),
		FIELD( _field_real, "Nav marker premium visibility proximity:wu" ),
		FIELD( _field_block, "Drop sets", &scenarioRandomOrdnanceDropSetBlock_block ),
		FIELD( _field_explanation, "Ordnance personal" ),
		FIELD( _field_tag_reference, "Scenario Ordnance List" ),
		FIELD( _field_block, "Unit Recordings", &ScenarioUnitRecordingBlock_block ),
		FIELD( _field_block, "Exit load screen#for non-mainmenu, we always use the first one", &loadScreenReferenceBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenarioVolumetricLightShaftSettingsStruct)
	{
		FIELD( _field_byte_flags, "flags", &scenarioVolumetricLightShaftSettingsFlags ),
		FIELD( _field_pad, "pad the byte flag", 3 ),
		FIELD( _field_real_vector_3d, "source direction" ),
		FIELD( _field_real_rgb_color, "shaft color tint" ),
		FIELD( _field_real, "exposure level" ),
		FIELD( _field_real, "decay" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenarioFloatingShadowSettingsStruct)
	{
		FIELD( _field_byte_integer, "number of cascades" ),
		FIELD( _field_byte_integer, "has been initialized" ),
		FIELD( _field_char_enum, "quality", &floatingShadowQualityDefinition ),
		FIELD( _field_char_enum, "resolution", &floatingShadowBufferResolution ),
		FIELD( _field_real, "static shadow sharpening" ),
		FIELD( _field_array, "frustums*", &scenarioFloatingShadowCascadeSettingsArray_array ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_lightmap_setting_struct)
	{
		FIELD( _field_explanation, "Lightmap resolution for each buckets" ),
		FIELD( _field_real, "lightmap res lowest" ),
		FIELD( _field_real, "lightmap res 2nd low" ),
		FIELD( _field_real, "lightmap res 3rd low" ),
		FIELD( _field_real, "lightmap res medium" ),
		FIELD( _field_real, "lightmap res 3rd high" ),
		FIELD( _field_real, "lightmap res 2nd high" ),
		FIELD( _field_real, "lightmap res highest" ),
		FIELD( _field_byte_flags, "lightmap flags", &scenario_lightmap_per_bsp_flags ),
		FIELD( _field_pad, "pad the byte flag", 3 ),
		FIELD( _field_real, "analytical light bounce modifier (when per bsp flag is on)" ),
		FIELD( _field_real, "non analytical light bounce modifier (when per bsp flag is on)" ),
		FIELD( _field_long_block_flags, "extra lighting bsp flags#neighbor bsp that occlude or contribute light (including bounce light)" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_trigger_volume_struct)
	{
		FIELD( _field_explanation, "naming" ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_short_block_index, "object name" ),
		FIELD( _field_short_integer, "runtime node index!" ),
		FIELD( _field_string_id, "node name" ),
		FIELD( _field_enum, "type", &trigger_volume_type_enum ),
		FIELD( _field_pad, "padding", 2 ),
		FIELD( _field_real_vector_3d, "forward!" ),
		FIELD( _field_real_vector_3d, "up!" ),
		FIELD( _field_real_point_3d, "position" ),
		FIELD( _field_custom_long_block_index, "packedKeyOffaceref~!" ),
		FIELD( _field_custom_long_block_index, "navMeshUIDOffaceref~!" ),
		FIELD( _field_real_point_3d, "extents" ),
		FIELD( _field_real, "z sink#this is only valid for sector type trigger volumes" ),
		FIELD( _field_block, "sector points", &trigger_volume_point_block_block ),
		FIELD( _field_block, "runtime triangles*!", &trigger_volume_runtime_triangles_block_block ),
		FIELD( _field_real, "runtime sector bounds x0*!" ),
		FIELD( _field_real, "runtime sector bounds x1*!" ),
		FIELD( _field_real, "runtime sector bounds y0*!" ),
		FIELD( _field_real, "runtime sector bounds y1*!" ),
		FIELD( _field_real, "runtime sector bounds z0*!" ),
		FIELD( _field_real, "runtime sector bounds z1*!" ),
		FIELD( _field_real, "C!" ),
		FIELD( _field_short_block_index, "kill trigger volume*" ),
		FIELD( _field_short_block_index, "editor folder!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(ScenarioUnitRecordingBlock_struct)
	{
		FIELD( _field_string, "name^" ),
		FIELD( _field_long_integer, "sampling rate" ),
		FIELD( _field_long_integer, "num samples*" ),
		FIELD( _field_long_integer, "Unit Recording version*!" ),
		FIELD( _field_data, "Unit Recording Data*!" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(scenario_required_resource_struct_definition)
	{
		FIELD( _field_block, "resources", &scenario_budget_references_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(function_bounds_mode_enum, 3)
	{
		OPTION("clip"),
		OPTION("clip and normalize"),
		OPTION("scale to fit"),
	};

	TAG_ENUM(scenario_function_flags, 4)
	{
		OPTION("scripted#the level script will set this value; the other settings here will be ignored."),
		OPTION("invert#result of function is one minus actual result"),
		OPTION("additive"),
		OPTION("always active#function does not deactivate when at or below lower bound"),
	};

	TAG_ENUM(scenario_soft_ceiling_flags_definition, 4)
	{
		OPTION("ignore bipeds"),
		OPTION("ignore vehicles"),
		OPTION("ignore camera"),
		OPTION("ignore huge vehicles"),
	};

	TAG_ENUM(scenario_player_flags, 2)
	{
		OPTION("survival mode"),
		OPTION("survival mode elite"),
	};

	TAG_ENUM(kill_volume_flags, 2)
	{
		OPTION("don\'t kill immediately"),
		OPTION("only kill players"),
	};

	TAG_ENUM(scenario_requisition_trigger_volume_flags_definition, 6)
	{
		OPTION("defender can buy"),
		OPTION("attacker can buy"),
		OPTION("can buy weapons"),
		OPTION("can buy equipment"),
		OPTION("can buy vehicles"),
		OPTION("can buy custom apps"),
	};

	TAG_ENUM(trigger_volume_type_enum, 2)
	{
		OPTION("bounding box"),
		OPTION("sector"),
	};

	TAG_ENUM(scenario_zone_set_switch_trigger_volume_flags_definition, 1)
	{
		OPTION("teleport vehicles"),
	};

	TAG_ENUM(scenario_zone_set_pvs_flags, 1)
	{
		OPTION("empty debug pvs*!"),
	};

	TAG_ENUM(scenario_zone_set_flags_definition, 5)
	{
		OPTION("begin loading next level"),
		OPTION("debug purposes only"),
		OPTION("interal zone set*!"),
		OPTION("disable sky clearing"),
		OPTION("override sky clear color"),
	};

	TAG_ENUM(scenario_structure_size_enum, 10)
	{
		OPTION("32x32"),
		OPTION("64x64"),
		OPTION("128x128"),
		OPTION("256x256 - 0.4 Meg{0.3Meg_256x256}"),
		OPTION("512x512 - 1.5 Meg{1Meg_512x512}"),
		OPTION("768x768 - 3.4 Meg{2.25Meg_768x768}"),
		OPTION("1024x1024 - 6 Meg{4Meg_1024x1024}"),
		OPTION("1280x1280 - 9.4 Meg{6.3Meg_1280x1280}"),
		OPTION("1536x1536 - 13.5 Meg{9Meg_1536x1536}"),
		OPTION("1792x1792 - 18.4Meg{12.3Meg_1792x1792}"),
	};

	TAG_ENUM(scenario_structure_refinement_size_enum, 4)
	{
		OPTION(" 4.0 Meg (Default)"),
		OPTION(" 1.0 Meg"),
		OPTION(" 2.0 Meg"),
		OPTION(" 6.0 Meg"),
	};

	TAG_ENUM(scenario_structure_bsp_reference_flags_definition, 16)
	{
		OPTION("default sky enabled!"),
		OPTION("per vertex only lightmap"),
		OPTION("never lightmap"),
		OPTION("generate fake small lightmaps"),
		OPTION("ray trace adjacent bsps on sky hits"),
		OPTION("lightmaps use conservative subcharts"),
		OPTION("lightmaps reduce stretch hack"),
		OPTION("lightmaps use extended gathering (very slow)"),
		OPTION("lightmaps final gather ignores backfacing hits"),
		OPTION("not a normally playable space in an MP map (check this on shared BSPs)"),
		OPTION("shared bsp"),
		OPTION("dont use extra lighting bsps for cubemaps"),
		OPTION("custom gravity scale"),
		OPTION("disable streaming subregions"),
		OPTION("do not desaturate decorators"),
		OPTION("make all shadows blob"),
	};

	TAG_ENUM(scenarioVolumetricLightShaftSettingsFlags, 1)
	{
		OPTION("enable volumetric light shafts for this BSP"),
	};

	TAG_ENUM(floatingShadowQualityDefinition, 3)
	{
		OPTION("8 tap"),
		OPTION("12 tap"),
		OPTION("6 tap"),
	};

	TAG_ENUM(floatingShadowBufferResolution, 2)
	{
		OPTION("512x512"),
		OPTION("800x800"),
	};

	TAG_ENUM(scenario_lightmap_per_bsp_flags, 1)
	{
		OPTION("analytical bounce uses per bsp setting"),
	};

	TAG_ENUM(scenario_performance_actor_flags_definition, 1)
	{
		OPTION("actor is critical"),
	};

	TAG_ENUM(scenario_performance_line_animation_flags_definition, 3)
	{
		OPTION("Loop"),
		OPTION("Loop until task transition"),
		OPTION("Die on animation completion"),
	};

	TAG_ENUM(scenario_performance_line_sync_action_flag_type_definition, 2)
	{
		OPTION("Share initiator stance"),
		OPTION("Initiator is origin"),
	};

	TAG_ENUM(scenario_performance_line_scenery_sync_action_flag_type_definition, 1)
	{
		OPTION("Share initiator stance"),
	};

	TAG_ENUM(scenario_performance_fragment_placement_definition, 2)
	{
		OPTION("Pre-Line"),
		OPTION("Post-Line"),
	};

	TAG_ENUM(scenario_performance_fragment_type_definition, 3)
	{
		OPTION("Default"),
		OPTION("Conditional Sleep"),
		OPTION("Branch"),
	};

	TAG_ENUM(scenario_performance_line_point_interaction_type_definition, 9)
	{
		OPTION("Face point"),
		OPTION("Aim at point"),
		OPTION("Look at point"),
		OPTION("Shoot at point"),
		OPTION("Go by point"),
		OPTION("Go to point"),
		OPTION("Go to and align"),
		OPTION("Go to thespian center"),
		OPTION("Teleport to point"),
	};

	TAG_ENUM(scenario_performance_line_progress_definition, 5)
	{
		OPTION("Immediate (play)"),
		OPTION("Block until all done"),
		OPTION("Block until line done"),
		OPTION("Queue blocking"),
		OPTION("Queue immediate"),
	};

	TAG_ENUM(scenario_performance_line_flags, 1)
	{
		OPTION("Disable"),
	};

	TAG_ENUM(performance_flags, 4)
	{
		OPTION("not initially placed"),
		OPTION("allow replay"),
		OPTION("infinite radius"),
		OPTION("actors in search"),
	};

	TAG_ENUM(decal_placement_flags, 1)
	{
		OPTION("force planar#force decal to be 2 triangle quad.  does not clip to geometry"),
	};

	TAG_ENUM(editor_comment_type_enum_definition, 1)
	{
		OPTION("generic"),
	};

	TAG_ENUM(scenario_type_enum, 5)
	{
		OPTION("solo"),
		OPTION("multiplayer"),
		OPTION("main menu"),
		OPTION("multiplayer shared"),
		OPTION("single player shared"),
	};

	TAG_ENUM(scenario_flags, 15)
	{
		OPTION("always draw sky!#always draw sky 0, even if no +sky polygons are visible"),
		OPTION("don\'t strip pathfinding#always leave pathfinding in, even for a multiplayer scenario"),
		OPTION("symmetric multiplayer map!"),
		OPTION("quick loading (cinematic only) scenario"),
		OPTION("characters use previous mission weapons"),
		OPTION("lightmaps smooth palettes with neighbors!"),
		OPTION("snap to white at start"),
		OPTION("override globals!"),
		OPTION("big vehicle use center point for light sampling!"),
		OPTION("don\'t use campaign sharing"),
		OPTION("ignore size and can\'t ship"),
		OPTION("always run lightmaps per-bsp"),
		OPTION("in space#so we can hide hud elements like the compass"),
		OPTION("survival#so we can strip the elite from the global player representations"),
		OPTION("do not strip variants#so we can test the impact of variant stripping"),
	};

	TAG_ENUM(scenario_runtime_trigger_volume_flags, 2)
	{
		OPTION("has hard safe volume!*"),
		OPTION("has soft safe volume!*"),
	};

	TAG_ENUM(camera_fx_palette_flags, 5)
	{
		OPTION("force exposure"),
		OPTION("force auto-exposure"),
		OPTION("override exposure bounds"),
		OPTION("override inherent bloom"),
		OPTION("override bloom intensity"),
	};

	TAG_ENUM(ordnance_flags, 1)
	{
		OPTION("suppress incident fanfare ui"),
	};

	TAG_ENUM(ordnance_dropset_flags, 4)
	{
		OPTION("initial drop#will be used for initial drops"),
		OPTION("player drop#will be used for personal drops"),
		OPTION("random drop#will be used for random drops"),
		OPTION("objective drop#will be used for objective-based drops"),
	};

	TAG_ENUM(multiplayer_map_size_enum, 3)
	{
		OPTION("small"),
		OPTION("medium"),
		OPTION("large"),
	};

} // namespace blofeld

