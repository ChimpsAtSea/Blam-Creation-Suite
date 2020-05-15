#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_profiles, MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK)
{
	{ _field_string, "name^" },
	{ _field_real_fraction, "starting health damage:[0,1]" },
	{ _field_real_fraction, "starting shield damage:[0,1]" },
	{ _field_tag_reference, "primary weapon" },
	{ _field_short_integer, "primaryrounds loaded#-1 = weapon default" },
	{ _field_short_integer, "primaryrounds total#-1 = weapon default" },
	{ _field_real, "primaryage remaining#0.0 = default, 1.0 = full" },
	{ _field_tag_reference, "secondary weapon" },
	{ _field_short_integer, "secondaryrounds loaded#-1 = weapon default" },
	{ _field_short_integer, "secondaryrounds total#-1 = weapon default" },
	{ _field_real, "secondaryage remaining#0.0 = default, 1.0 = full" },
	{ _field_char_integer, "starting fragmentation grenade count" },
	{ _field_char_integer, "starting plasma grenade count" },
	{ _field_char_integer, "starting grenade 3 count" },
	{ _field_char_integer, "starting grenade 4 count" },
	{ _field_char_integer, "starting grenade 5 count" },
	{ _field_char_integer, "starting grenade 6 count" },
	{ _field_char_integer, "starting grenade 7 count" },
	{ _field_char_integer, "starting grenade 8 count" },
	{ _field_tag_reference, "starting equipment" },
	{ _field_string_id, "starting tactical package" },
	{ _field_string_id, "starting support upgrade" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_pad, "AHDVHJE", 2 },
	{ _field_terminator },
};

TAG_BLOCK(performance_template_actor, MAXIMUM_ACTORS_PER_PERFORMANCE)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "Actor name^" },
	{ _field_tag_reference, "Actor type" },
	{ _field_tag_reference, "Vehicle type" },
	{ _field_string_id, "Vehicle seat label" },
	{ _field_tag_reference, "Weapon type" },
	{ _field_pad, "pad0", 2 },
	{ _field_custom_short_block_index, "Spawn Point" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line, MAXIMUM_LINES_PER_PERFORMANCE)
{
	{ _field_string_id, "name^" },
	{ _field_custom_short_block_index, "Actor" },
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "sleep minimum:ticks" },
	{ _field_short_integer, "sleep maximum:ticks" },
	{ _field_long_enum, "Line progress type" },
	{ _field_block, "Script fragments", &scenario_performance_line_script_fragment_block },
	{ _field_block, "Point interaction", &scenario_performance_line_point_interaction_block },
	{ _field_block, "Animations", &scenario_performance_line_animation_block },
	{ _field_block, "Sync Actions", &scenario_performance_line_sync_action_block },
	{ _field_block, "Scenery Sync Actions", &scenario_performance_line_scenery_sync_action_block },
	{ _field_block, "Dialog lines", &scenario_performance_line_dialog_block },
	{ _field_block, "Sounds", &scenario_performance_line_sound_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_script_fragment, MAXIMUM_SCRIPT_FRAGMENTS_PER_PERFORMANCE_LINE)
{
	{ _field_enum, "fragment placement" },
	{ _field_enum, "fragment type" },
	{ _field_long_string, "fragment#maximum 256 characters, type just branch condition (with brackets) in case of branches" },
	{ _field_long_string, "branch target#the script to branch to (with any arguments to it). Used only if type is branch" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_point_interaction, MAXIMUM_POINT_INTERACTIONS_PER_PERFORMANCE_LINE)
{
	{ _field_long_flags, "interaction type" },
	{ _field_custom_short_block_index, "point" },
	{ _field_custom_short_block_index, "actor" },
	{ _field_string_id, "object name" },
	{ _field_string_id, "throttle style" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_animation, MAXIMUM_ANIMATIONS_PER_PERFORMANCE_LINE)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "pad0", 2 },
	{ _field_string_id, "stance" },
	{ _field_string_id, "animation^" },
	{ _field_real, "duration" },
	{ _field_real, "probability" },
	{ _field_real, "throttle transition time:seconds" },
	{ _field_long_integer, "transition frame count#The number of frames from the end of the animation to start transitioning out" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_sync_action, MAXIMUM_SYNC_ACTIONS_PER_PERFORMANCE_LINE)
{
	{ _field_string_id, "sync action name" },
	{ _field_real, "probability" },
	{ _field_custom_short_block_index, "attach to point" },
	{ _field_word_flags, "flags" },
	{ _field_block, "Actors", &scenario_performance_line_sync_action_actor_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_sync_action_actor, MAXIMUM_ACTORS_PER_PERFORMANCE)
{
	{ _field_custom_short_block_index, "Actor type" },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_scenery_sync_action, MAXIMUM_SCENERY_SYNC_ACTIONS_PER_PERFORMANCE_LINE)
{
	{ _field_string_id, "scenery object name" },
	{ _field_string_id, "sync action name" },
	{ _field_string_id, "stance name" },
	{ _field_real, "probability" },
	{ _field_word_flags, "flags" },
	{ _field_pad, "pad", 2 },
	{ _field_block, "Actors", &scenario_performance_line_sync_action_actor_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_dialog, MAXIMUM_DIALOG_LINES_PER_PERFORMANCE_LINE)
{
	{ _field_string_id, "dialog" },
	{ _field_real, "probability" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_line_sound, MAXIMUM_SOUNDS_PER_PERFORMANCE_LINE)
{
	{ _field_tag_reference, "sound effect" },
	{ _field_custom_short_block_index, "attach to point" },
	{ _field_pad, "pad", 2 },
	{ _field_string_id, "attach to object named" },
	{ _field_terminator },
};

TAG_BLOCK(performance_template_point, 32)
{
	{ _field_string_id, "Point name^" },
	{ _field_real_vector_3d, "Relative Position#The offset of the performance point from the center of the performance" },
	{ _field_real_euler_angles_2d, "Relative Facing#The facing at the point in the space of the performance" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_child_references, MAXIMUM_CHILD_SCENARIOS_PER_SCENARIO)
{
	{ _field_tag_reference, "tag^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_structure_bsp_reference, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_tag_reference, "structure bsp^" },
	{ _field_tag_reference, "local structure bsp^*!" },
	{ _field_tag_reference, "structure metadata*" },
	{ _field_explanation, "Size Class" },
	{ _field_long_enum, "size class" },
	{ _field_long_enum, "refinement size class" },
	{ _field_real, "hacky ambient min luminance" },
	{ _field_real, "direct/draft ambient min luminance" },
	{ _field_real, "structure vertex sink#this is the most that we can sink a soft surface link snow in the structure_bsp via vertex painting." },
	{ _field_word_flags, "flags" },
	{ _field_short_block_index, "default sky" },
	{ _field_tag_reference, "bsp specific cubemap" },
	{ _field_tag_reference, "wind" },
	{ _field_tag_reference, "authored light probe" },
	{ _field_tag_reference, "vehicle authored light probe" },
	{ _field_real, "max shadow count scale#scale up or down the max number of shadows as set in the throttle tag per bsp" },
	{ _field_real, "decorator sunlight minimum:[0.0 to 1.0]#0.0 means allow fully dark in the shadows, higher values will brighten up the shadowed decorators" },
	{ _field_custom, "volumetric light shafts" },
	{ _field_struct, "volumetric light shaft settings" },
	{ _field_custom },
	{ _field_custom, "floating shadows" },
	{ _field_struct, "floating shadow settings" },
	{ _field_custom },
	{ _field_explanation, "Clones" },
	{ _field_long_block_flags, "cloned bsp flags" },
	{ _field_struct, "lightmap setting{lightmap resolution buckets}" },
	{ _field_real, "custom gravity scale#0==nogravity, 1==full, set the custom gravity scale flag to make this parameter active" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_design_reference, MAXIMUM_STRUCTURE_DESIGNS_PER_SCENARIO)
{
	{ _field_tag_reference, "structure design^" },
	{ _field_tag_reference, "local structure design^*!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_sky_reference, MAXIMUM_SKIES_PER_SCENARIO)
{
	{ _field_tag_reference, "sky" },
	{ _field_real, "cloud scale#mapping to the world unit" },
	{ _field_real, "cloud speed#cloud movement speed" },
	{ _field_real, "cloud direction#cloud movement direction, 0-360 degree" },
	{ _field_tag_reference, "cloud texture#red channel is used" },
	{ _field_short_block_index, "name^" },
	{ _field_pad, "post-name-pad", 2 },
	{ _field_long_block_flags, "active on bsps!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_pvs, k_maximum_scenario_zone_set_count+1)
{
	{ _field_dword_integer, "structure bsp mask*!" },
	{ _field_short_integer, "version*!" },
	{ _field_word_flags, "flags*!" },
	{ _field_block, "bsp checksums*!", &scenario_zone_set_bsp_checksum_block },
	{ _field_block, "structure bsp pvs*!", &scenario_zone_set_bsp_pvs_block },
	{ _field_block, "portal=>device mapping*!", &structure_portal_device_mapping_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_bsp_checksum, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_dword_integer, "bsp checksum*!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_bsp_pvs, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_block, "cluster pvs*!", &scenario_zone_set_cluster_pvs_block },
	{ _field_block, "cluster pvs doors closed*!", &scenario_zone_set_cluster_pvs_block },
	{ _field_block, "bsp cluster mapings*!", &scenario_zone_set_bsp_seam_cluster_mappings_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_cluster_pvs, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_block, "cluster pvs bit vectors*!", &scenario_zone_set_bsp_bits_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_bsp_bits, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_block, "bits*!", &scenario_zone_set_cluster_pvs_bit_vector_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_cluster_pvs_bit_vector, ((((MAXIMUM_CLUSTERS_PER_STRUCTURE)+(k_int32_bits-1))>>k_int32_bits_bits)))
{
	{ _field_dword_integer, "dword*!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_bsp_seam_cluster_mappings, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_block, "root clusters*!", &scenario_zone_set_cluster_reference_block },
	{ _field_block, "attached clusters*!", &scenario_zone_set_cluster_reference_block },
	{ _field_block, "connected clusters*!", &scenario_zone_set_cluster_reference_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_cluster_reference, MAXIMUM_CLUSTERS_PER_STRUCTURE*MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_char_integer, "bsp index*!" },
	{ _field_byte_integer, "cluster index*!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set, k_maximum_scenario_zone_set_count)
{
	{ _field_string_id, "name^" },
	{ _field_long_string, "name string*!" },
	{ _field_long_block_index, "pvs index*!" },
	{ _field_long_flags, "flags" },
	{ _field_long_block_flags, "bsp zone flags" },
	{ _field_long_block_flags, "structure design zone flags" },
	{ _field_long_block_flags, "runtime bsp zone flags*!" },
	{ _field_long_block_flags, "sruntime tructure design zone flags*!" },
	{ _field_long_block_flags, "required designer zones{designer zone flags}" },
	{ _field_qword_integer, "runtime designer zone flags*!" },
	{ _field_long_block_flags, "cinematic zones" },
	{ _field_long_block_index, "hint previous zone set" },
	{ _field_long_block_index, "audibility index*!" },
	{ _field_block, "planar fog visibility*!", &planar_fog_zone_set_visibility_definition_block },
	{ _field_block, "budget overrides", &scenario_zone_set_budget_override_block },
	{ _field_tag_reference, "streaming_reference_tag" },
	{ _field_real_point_3d, "world bounds min#Physics world will include this min point" },
	{ _field_real_point_3d, "world bounds max#Physics world will include this max point" },
	{ _field_block, "lipsync sounds", &scenario_zone_set_lipsync_block },
	{ _field_tag_reference, "cinematic soundbank#only for cinematics. If you try to use this for anything else without talking to me, i will stab you in the face" },
	{ _field_real_rgb_color, "sky clear color#linear color, must check override flag above to use" },
	{ _field_pad, "pad4", 4 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_budget_override, 1)
{
	{ _field_long_integer, "env bitmap:megs" },
	{ _field_long_integer, "env object bitmap:megs" },
	{ _field_long_integer, "env geometry:megs" },
	{ _field_long_integer, "env object geometry:megs" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_lipsync, SHORT_MAX)
{
	{ _field_tag_reference, "dummy" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lighting_zone_set, k_maximum_scenario_zone_set_count)
{
	{ _field_string_id, "name^" },
	{ _field_long_block_flags, "rendered bsp flags" },
	{ _field_long_block_flags, "extra bsp flags" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_function, MAXIMUM_FUNCTIONS_PER_SCENARIO)
{
	{ _field_long_flags, "flags" },
	{ _field_string, "name^" },
	{ _field_real, "period:seconds#this is the period for the above function (lower values make the function oscillate quickly, higher values make it oscillate slowly)" },
	{ _field_short_block_index, "scale period by#multiply this function by the above period" },
	{ _field_enum, "function" },
	{ _field_short_block_index, "scale function by#multiply this function by the result of the above function" },
	{ _field_enum, "wobble function#the curve used for the wobble" },
	{ _field_real, "wobble period:seconds#the length of time it takes for the magnitude of this function to complete a wobble" },
	{ _field_real, "wobble magnitude:percent#the amount of random wobble in the magnitude" },
	{ _field_real_fraction, "square wave threshold#if non-zero, all values above the square wave threshold are snapped to 1.0, and all values below it are snapped to 0.0 to create a square wave." },
	{ _field_short_integer, "step count#the number of discrete values to snap to (e.g., a step count of 5 would snap the function to 0.00,0.25,0.50,0.75 or 1.00)" },
	{ _field_enum, "map to" },
	{ _field_short_integer, "sawtooth count#the number of times this function should repeat (e.g., a sawtooth count of 5 would give the function a value of 1.0 at each of 0.25,0.50,0.75 as well as at 1.0" },
	{ _field_pad, "WBP", 2 },
	{ _field_short_block_index, "scale result by#multiply this function (from a weapon, vehicle, etc.) final result of all of the above math" },
	{ _field_enum, "bounds mode#controls how the bounds, below, are used" },
	{ _field_real_fraction_bounds, "bounds" },
	{ _field_real, "runtime inverse bounds range!" },
	{ _field_pad, "OFLIM", 2 },
	{ _field_short_block_index, "turn off with#if the specified function is off, so is this function" },
	{ _field_pad, "FX", 16 },
	{ _field_real, "runtime reciprocal sawtooth count!" },
	{ _field_real, "runtime reciprocal bounds range!" },
	{ _field_real, "runtime reciprocal step count!" },
	{ _field_real, "runtime one over period!" },
	{ _field_terminator },
};

TAG_BLOCK(editor_comment, MAXIMUM_EDITOR_COMMENTS)
{
	{ _field_real_point_3d, "position" },
	{ _field_long_enum, "type!" },
	{ _field_string, "name^" },
	{ _field_long_string, "comment" },
	{ _field_terminator },
};

TAG_BLOCK(dont_use_me_scenario_environment_object, MAXIMUM_ENVIRONMENT_OBJECTS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "bsp*" },
	{ _field_short_integer, "runtime object type!" },
	{ _field_long_integer, "unique id*" },
	{ _field_pad, "WOQHKQB", 4 },
	{ _field_tag, "object definition tag*" },
	{ _field_long_integer, "object*^" },
	{ _field_pad, "YMRTLZ", 44 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_object_names, MAXIMUM_OBJECT_NAMES_PER_SCENARIO)
{
	{ _field_string_id, "name^" },
	{ _field_custom_short_block_index, "object_type!" },
	{ _field_custom_short_block_index, "scenario_datum_index!" },
	{ _field_terminator },
};

TAG_BLOCK(scenarioAttachedEffectsBlock, ScenarioAttachedEffect::k_maxLoopingEffectsAllowed)
{
	{ _field_long_integer, "cutscene flag index" },
	{ _field_tag_reference, "effect reference^" },
	{ _field_terminator },
};

TAG_BLOCK(scenarioAttachedLensFlaresBlock, ScenarioAttachedEffect::k_maxLensFlaresAllowed)
{
	{ _field_long_integer, "cutscene flag index" },
	{ _field_tag_reference, "lens flare reference^" },
	{ _field_terminator },
};

TAG_BLOCK(scenarioAttachedLightConesBlock, ScenarioAttachedLightCone::k_maxLightConesAllowed)
{
	{ _field_long_integer, "cutscene flag index" },
	{ _field_tag_reference, "light cone reference^" },
	{ _field_real_argb_color, "color" },
	{ _field_real_point_2d, "size" },
	{ _field_real, "intensity" },
	{ _field_tag_reference, "intensity curve" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_soft_ceilings, MAXIMUM_SCENARIO_SOFT_CEILINGS_PER_SCENARIO)
{
	{ _field_word_flags, "flags" },
	{ _field_word_flags, "runtime flags*!" },
	{ _field_string_id, "name" },
	{ _field_enum, "type" },
	{ _field_pad, "my name is", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_players, MAXIMUM_SCENARIO_PLAYERS_PER_BLOCK)
{
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_angle, "facing:degrees" },
	{ _field_angle, "pitch:degrees" },
	{ _field_short_integer, "insertion point index" },
	{ _field_word_flags, "flags" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_pad, "ANDYNDGE", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_trigger_volume, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_explanation, "naming" },
	{ _field_string_id, "name^" },
	{ _field_short_block_index, "object name" },
	{ _field_short_integer, "runtime node index!" },
	{ _field_string_id, "node name" },
	{ _field_enum, "type" },
	{ _field_pad, "padding", 2 },
	{ _field_real_vector_3d, "forward!" },
	{ _field_real_vector_3d, "up!" },
	{ _field_real_point_3d, "position" },
	{ _field_custom_long_block_index, "packedKeyOffaceref~!" },
	{ _field_custom_long_block_index, "navMeshUIDOffaceref~!" },
	{ _field_real_point_3d, "extents" },
	{ _field_real, "z sink#this is only valid for sector type trigger volumes" },
	{ _field_block, "sector points", &trigger_volume_point_block },
	{ _field_block, "runtime triangles*!", &trigger_volume_runtime_triangles_block },
	{ _field_real, "runtime sector bounds x0*!" },
	{ _field_real, "runtime sector bounds x1*!" },
	{ _field_real, "runtime sector bounds y0*!" },
	{ _field_real, "runtime sector bounds y1*!" },
	{ _field_real, "runtime sector bounds z0*!" },
	{ _field_real, "runtime sector bounds z1*!" },
	{ _field_real, "C!" },
	{ _field_short_block_index, "kill trigger volume*" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_terminator },
};

TAG_BLOCK(trigger_volume_point, k_maximum_points_per_sector)
{
	{ _field_real_point_3d, "position" },
	{ _field_real_euler_angles_2d, "normal" },
	{ _field_terminator },
};

TAG_BLOCK(trigger_volume_runtime_triangles, k_maximum_points_per_sector-2)
{
	{ _field_real_plane_3d, "plane 0*!" },
	{ _field_real_plane_3d, "plane 1*!" },
	{ _field_real_plane_3d, "plane 2*!" },
	{ _field_real_plane_3d, "plane 3*!" },
	{ _field_real_plane_3d, "plane 4*!" },
	{ _field_real_point_2d, "vertex 0*!" },
	{ _field_real_point_2d, "vertex 1*!" },
	{ _field_real_point_2d, "vertex 2*!" },
	{ _field_pad, "pad0", 8 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_zone_set_switch_trigger_volume, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_word_flags, "flags" },
	{ _field_short_block_index, "begin zone set" },
	{ _field_short_block_index, "trigger volume" },
	{ _field_short_block_index, "commit zone set" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_decals, MAXIMUM_DECALS_PER_SCENARIO)
{
	{ _field_custom },
	{ _field_short_block_index, "decal palette index" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "post-decal-palette-index-pad", 1 },
	{ _field_struct, "manual bsp flags*" },
	{ _field_real_quaternion, "rotation*" },
	{ _field_real_point_3d, "position*" },
	{ _field_real, "scale x{scale}" },
	{ _field_real, "scale y" },
	{ _field_real, "cull angle" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_decal_palette, MAXIMUM_DECAL_PALETTES_PER_SCENARIO)
{
	{ _field_tag_reference, "reference^" },
	{ _field_long_integer, "max static bucket size*!" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_detail_object_collection_palette, MAXIMUM_DETAIL_OBJECT_LAYERS_PER_STRUCTURE)
{
	{ _field_tag_reference, "name^" },
	{ _field_pad, "XBMYUIKEJ", 32 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cutscene_flag, MAXIMUM_CUTSCENE_FLAGS_PER_SCENARIO)
{
	{ _field_pad, "MMNGQBXC", 4 },
	{ _field_string_id, "name^" },
	{ _field_real_point_3d, "position" },
	{ _field_real_euler_angles_3d, "facing" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_short_block_index, "source bsp*" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cutscene_camera_point, MAXIMUM_CUTSCENE_CAMERA_POINTS_PER_SCENARIO)
{
	{ _field_word_flags, "flags" },
	{ _field_enum, "type" },
	{ _field_string, "name^" },
	{ _field_custom },
	{ _field_pad, "pad", 4 },
	{ _field_real_point_3d, "position" },
	{ _field_real_euler_angles_3d, "orientation" },
	{ _field_short_block_index, "zone set" },
	{ _field_pad, "padd", 2 },
	{ _field_useless_pad },
	{ _field_useless_pad },
	{ _field_terminator },
};

TAG_BLOCK(scenario_kill_trigger_volumes, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_short_block_index, "trigger volume" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad", 1 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_safe_zone_trigger_volumes, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_short_block_index, "trigger volume" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad", 1 },
	{ _field_terminator },
};

TAG_BLOCK(trigger_volume_mopp_code, 1)
{
	{ _field_long_integer, "trigger volume checksum" },
	{ _field_block, "mopp code*!", &mopp_code_definition_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_requisition_trigger_volumes, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_short_block_index, "trigger volume" },
	{ _field_word_flags, "flags" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_location_name_trigger_volumes, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_short_block_index, "trigger volume" },
	{ _field_string, "name" },
	{ _field_terminator },
};

TAG_BLOCK(scenarioUnsafeSpawnZoneTriggerVolumesBlock, MAXIMUM_TRIGGER_VOLUMES_PER_SCENARIO)
{
	{ _field_short_block_index, "trigger volume" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_atmosphere_palette, MAXIMUM_ATMOSPHERE_PALETTE_ENTRIES_PER_STRUCTURE)
{
	{ _field_string_id, "name!" },
	{ _field_word_integer, "Atmosphere Setting Index!" },
	{ _field_pad, "XQLJZUE", 2 },
	{ _field_tag_reference, "atmosphere^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_camera_fx_palette, MAXIMUM_CAMERA_FX_PALETTE_ENTRIES_PER_STRUCTURE)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "cluster camera_fx tag:if empty, uses default#if empty, uses default" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "EKJFER", 3 },
	{ _field_real, "forced exposure:stops#the target exposure (ONLY USED WHEN FORCE EXPOSURE IS CHECKED)" },
	{ _field_real, "forced auto-exposure screen brightness:[0.0001-1]#how bright you want the screen to be (ONLY USED WHEN FORCE AUTO EXPOSURE IS CHECKED)" },
	{ _field_real, "exposure min:stops" },
	{ _field_real, "exposure max:stops" },
	{ _field_real, "inherent bloom" },
	{ _field_real, "bloom intensity" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_weather_palette, MAXIMUM_WEATHER_PALETTE_ENTRIES_PER_STRUCTURE)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "rain" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cluster_data, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
{
	{ _field_tag_reference, "bsp^*" },
	{ _field_long_integer, "bsp checksum*" },
	{ _field_block, "cluster centroids*", &scenario_cluster_points_block },
	{ _field_long_block_index, "default acoustic palette" },
	{ _field_block, "acoustics{background sounds}*", &scenario_cluster_acoustics_block },
	{ _field_block, "atmospheric properties*", &scenario_cluster_atmosphere_properties_block },
	{ _field_block, "camera fx properties*", &scenario_cluster_camera_fx_properties_block },
	{ _field_block, "weather properties*", &scenario_cluster_weather_properties_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cluster_points, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_real_point_3d, "centroid*" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cluster_acoustics, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_short_block_index, "type^" },
	{ _field_pad, "XQQ", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cluster_atmosphere_properties, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_short_block_index, "type^" },
	{ _field_pad, "XQQ", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cluster_camera_fx_properties, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_short_block_index, "type^" },
	{ _field_pad, "XQQ", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cluster_weather_properties, MAXIMUM_CLUSTERS_PER_STRUCTURE)
{
	{ _field_short_block_index, "type^" },
	{ _field_pad, "XQQ", 2 },
	{ _field_terminator },
};

TAG_BLOCK(scenario_spawn_data, 1)
{
	{ _field_real, "game object reset height" },
	{ _field_terminator },
};

TAG_BLOCK(SoundSubtitleBlock, MAXIMUM_SUBTITLES_PER_SCENARIO)
{
	{ _field_long_integer, "tagIndex" },
	{ _field_string_id, "subtitleName" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cheap_particle_system_palette, s_scenario_cheap_particle_emitter_palette_entry::k_maximum_scenario_cheap_particle_system_palette_entries)
{
	{ _field_tag_reference, "definition^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cheap_particle_systems, s_scenario_cheap_particle_system::k_maximum_scenario_cheap_particle_systems)
{
	{ _field_short_block_index, "palette index^" },
	{ _field_pad, "VLKSJLER", 2 },
	{ _field_real_point_3d, "position" },
	{ _field_real_euler_angles_3d, "rotation" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cinematic_lighting_palette, k_maximum_scenario_cinematic_lighting_palette_entry_count)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "cinematic_lighting_tag" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_airprobes, k_max_airprobes_per_scenario)
{
	{ _field_real_point_3d, "airprobe position" },
	{ _field_string_id, "airprobe name^" },
	{ _field_long_integer, "BSP index^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_budget_references, k_maximum_budget_references_per_scenario)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

TAG_BLOCK(model_references, SHORT_MAX)
{
	{ _field_tag_reference, "model reference^" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performances, MAXIMUM_PERFORMANCES_PER_SCENARIO)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "script name#The name of a custom script used to drive the performance. If none is given, a default script is uses that goes through the lines in sequence" },
	{ _field_string_id, "global name#The name of a script global that will be declared for this performance." },
	{ _field_word_flags, "flags" },
	{ _field_short_block_index, "editor folder!" },
	{ _field_custom_short_block_index, "Point set" },
	{ _field_pad, "padding", 2 },
	{ _field_block, "Actors", &scenario_performance_actor_block },
	{ _field_block, "Lines", &scenario_performance_line_block },
	{ _field_real_point_3d, "position" },
	{ _field_real_euler_angles_2d, "template facing" },
	{ _field_real, "thespian radius{performance radius}#The radius inside which actors have to be in order to start." },
	{ _field_real, "attraction radius#The radius inside which actors become attracted to the thespian origin." },
	{ _field_real_fraction, "attraction probability per second:[0,1]#The probability that an actor be attracted once inside the thespian radius, every second." },
	{ _field_string_id, "template" },
	{ _field_long_integer, "template index!" },
	{ _field_block, "tasks!", &scenario_performance_task_block },
	{ _field_custom },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_actor, MAXIMUM_ACTORS_PER_PERFORMANCE)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "Actor name^" },
	{ _field_short_block_index, "Actor type" },
	{ _field_short_block_index, "Weapon type" },
	{ _field_short_block_index, "Vehicle type" },
	{ _field_custom_short_block_index, "debug spawn point" },
	{ _field_string_id, "Vehicle seat label" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_performance_task, MAXIMUM_TASKS_PER_PERFORMANCE)
{
	{ _field_short_block_index, "objective" },
	{ _field_custom_short_block_index, "task" },
	{ _field_terminator },
};

TAG_BLOCK(scenarioRandomOrdnanceDropSetBlock, k_maximum_scenario_ordnance_drop_sets)
{
	{ _field_word_flags, "drop set flags" },
	{ _field_pad, "ODSF", 2 },
	{ _field_string, "name^" },
	{ _field_long_integer, "count" },
	{ _field_tag_reference, "Ordnance List" },
	{ _field_block, "Drop point list", &scenarioRandomOrdnanceDropPointBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(scenarioRandomOrdnanceDropPointBlock, k_maximum_random_ordnance_drop_points)
{
	{ _field_short_block_index, "Drop point" },
	{ _field_terminator },
};

TAG_BLOCK(ScenarioUnitRecordingBlock, k_maximum_unit_recordings_per_scenario)
{
	{ _field_string, "name^" },
	{ _field_long_integer, "sampling rate" },
	{ _field_long_integer, "num samples*" },
	{ _field_long_integer, "Unit Recording version*!" },
	{ _field_data, "Unit Recording Data*!" },
	{ _field_terminator },
};

TAG_BLOCK(loadScreenReferenceBlock, SHORT_MAX)
{
	{ _field_explanation, "Map IDs" },
	{ _field_long_integer, "Map ID#Only valid for main menu - otherwise always use first reference" },
	{ _field_tag_reference, "Load Screen Reference" },
	{ _field_real, "Tint Gradient Lookup V Coordinate#Value between 0.0 and 1.0 determines which line to use for tint.\nA negative value will choose a random tint from the palette." },
	{ _field_terminator },
};

TAG_GROUP(performance_template, PERFORMANCE_TEMPLATE_TAG)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "script name#The name of a custom script used to drive the performance. If none is given, a default script is uses that goes through the lines in sequence" },
	{ _field_block, "Actors", &performance_template_actor_block },
	{ _field_block, "Lines", &scenario_performance_line_block },
	{ _field_block, "Points", &performance_template_point_block },
	{ _field_terminator },
};

TAG_GROUP(scenario, SCENARIO_TAG)
{
	{ _field_block, "child scenarios", &scenario_child_references_block },
	{ _field_custom, "link to scenario lightmap" },
	{ _field_enum, "type" },
	{ _field_word_flags, "flags" },
	{ _field_long_flags, "runtime trigger volume flags*!" },
	{ _field_long_integer, "campaign id" },
	{ _field_long_integer, "map id" },
	{ _field_string_id, "map name#Used to associate external resources with this map - e.g. PDA camera setting block names." },
	{ _field_tag_reference, "Scenario sound bank#Scenario-specific sound bank." },
	{ _field_tag_reference, "Scenario sound bank Number 2#Another scenario-specific sound bank. All will be loaded." },
	{ _field_tag_reference, "Scenario sound bank Number 3#Another scenario-specific sound bank. All will be loaded." },
	{ _field_tag_reference, "Scenario sound bank Number 4#Another scenario-specific sound bank. All will be loaded." },
	{ _field_string_id, "Inside reverb name#This reverb will be used for inside areas when the listener is outside." },
	{ _field_long_integer, "Inside reverb hash ID!" },
	{ _field_short_integer, "sound permutation mission id" },
	{ _field_pad, "pad", 2 },
	{ _field_long_integer, "minimum structure bsp importer version*!" },
	{ _field_angle, "local north" },
	{ _field_real, "local sea level:wu#used to calculate aircraft altitude" },
	{ _field_real, "altitude cap:wu" },
	{ _field_real_point_3d, "sandbox origin point#forge coordinates are relative to this point" },
	{ _field_real, "sandbox budget" },
	{ _field_string_id, "default vehicle set#when vehicle set is \"map default,\" this vehicle set is used" },
	{ _field_tag_reference, "game performance throttles{performance thorttles}" },
	{ _field_block, "structure bsps", &scenario_structure_bsp_reference_block },
	{ _field_block, "structure designs", &scenario_design_reference_block },
	{ _field_tag_reference, "structure seams" },
	{ _field_tag_reference, "local structure seams*!" },
	{ _field_block, "skies", &scenario_sky_reference_block },
	{ _field_block, "zone set pvs*!", &scenario_zone_set_pvs_block },
	{ _field_block, "zone set audibility*!", &game_audibility_block },
	{ _field_block, "zone sets", &scenario_zone_set_block },
	{ _field_block, "lighting zone sets!", &scenario_lighting_zone_set_block },
	{ _field_block, "predicted resources*", &g_null_block },
	{ _field_block, "functions", &scenario_function_block },
	{ _field_data, "editor scenario data" },
	{ _field_block, "comments", &editor_comment_block },
	{ _field_block, "unused scenario environment objects!", &dont_use_me_scenario_environment_object_block },
	{ _field_block, "object names*", &scenario_object_names_block },
	{ _field_block, "scenery", &scenario_scenery_block },
	{ _field_block, "scenery palette", &scenario_scenery_palette_block },
	{ _field_block, "bipeds", &scenario_biped_block },
	{ _field_block, "biped palette", &scenario_biped_palette_block },
	{ _field_block, "vehicles", &scenario_vehicle_block },
	{ _field_block, "vehicle palette", &scenario_vehicle_palette_block },
	{ _field_block, "equipment", &scenario_equipment_block },
	{ _field_block, "equipment palette", &scenario_equipment_palette_block },
	{ _field_block, "weapons", &scenario_weapon_block },
	{ _field_block, "weapon palette", &scenario_weapon_palette_block },
	{ _field_block, "device groups", &device_group_block },
	{ _field_block, "machines", &scenario_machine_block },
	{ _field_block, "machine palette", &scenario_machine_palette_block },
	{ _field_block, "terminals", &scenario_terminal_block },
	{ _field_block, "terminal palette", &scenario_terminal_palette_block },
	{ _field_block, "controls", &scenario_control_block },
	{ _field_block, "control palette", &scenario_control_palette_block },
	{ _field_block, "dispensers", &ScenarioDispenserBlock_block },
	{ _field_block, "dispenser palette", &ScenarioDispenserPaletteBlock_block },
	{ _field_block, "sound scenery", &scenario_sound_scenery_block },
	{ _field_block, "sound scenery palette", &scenario_sound_scenery_palette_block },
	{ _field_block, "giants", &scenario_giant_block },
	{ _field_block, "giant palette", &scenario_giant_palette_block },
	{ _field_block, "effect scenery", &scenario_effect_scenery_block },
	{ _field_block, "effect scenery palette", &scenario_effect_scenery_palette_block },
	{ _field_block, "spawners", &scenario_spawner_block },
	{ _field_block, "spawner palette", &scenario_spawner_palette_block },
	{ _field_block, "bink palette", &binkPaletteBlock_block },
	{ _field_block, "scenario attached effects", &scenarioAttachedEffectsBlock_block },
	{ _field_block, "scenario attached lens flares", &scenarioAttachedLensFlaresBlock_block },
	{ _field_block, "scenario attached light cones", &scenarioAttachedLightConesBlock_block },
	{ _field_block, "map variant palettes", &map_variant_palette_block },
	{ _field_tag_reference, "multiplayer object types" },
	{ _field_char_enum, "multiplayer map size" },
	{ _field_pad, "mulmapsizepad", 3 },
	{ _field_block, "Playtest req palette#requisition for SvE, activated via an init.txt option for playtest balance", &scenario_requisition_palette_block },
	{ _field_real, "player requisition frequency:seconds" },
	{ _field_long_integer, "initial game currency:SpaceBucks" },
	{ _field_block, "soft ceilings", &scenario_soft_ceilings_block },
	{ _field_block, "player starting profile", &scenario_profiles_block },
	{ _field_block, "player starting locations", &scenario_players_block },
	{ _field_block, "trigger volumes", &scenario_trigger_volume_block },
	{ _field_block, "acoustic sectors", &scenario_acoustic_sector_block },
	{ _field_block, "acoustic transitions", &scenario_acoustic_transition_block },
	{ _field_block, "atmosphere dumplings", &scenario_atmosphere_dumpling_block },
	{ _field_block, "weather dumplings", &scenario_weather_dumpling_block },
	{ _field_block, "recorded animations", &recorded_animation_block },
	{ _field_block, "zone set switch trigger volumes~", &scenario_zone_set_switch_trigger_volume_block },
	{ _field_block, "named location volumes", &scenario_named_location_volume_block },
	{ _field_explanation, "SPAWN INFLUENCE OVERRIDES" },
	{ _field_tag_reference, "Spawn Settings" },
	{ _field_explanation, "RENDER FLUFF" },
	{ _field_block, "decals", &scenario_decals_block },
	{ _field_block, "decal palette", &scenario_decal_palette_block },
	{ _field_long_integer, "largest zoneset static decal memory size:kilobytes#this is memory for the largest possible zoneset - default (0) is 2048" },
	{ _field_data, "static decal memory data*" },
	{ _field_real, "decal depth bias override (USE WITH CAUTION)#you should not need to do this -- this is for a mission with strange collision geo" },
	{ _field_block, "detail object collection palette", &scenario_detail_object_collection_palette_block },
	{ _field_block, "style pallette", &style_palette_block },
	{ _field_block, "squad groups", &squad_groups_block },
	{ _field_block, "squads", &squads_block },
	{ _field_block, "zones", &zone_block },
	{ _field_block, "squad patrols", &squad_patrol_block },
	{ _field_block, "actual cues!", &ai_cue_block },
	{ _field_block, "full cues{cues}", &ai_full_cue_block },
	{ _field_block, "quick cues", &ai_quick_cue_block },
	{ _field_block, "mission scenes", &ai_scene_block },
	{ _field_block, "character palette", &character_palette_block },
	{ _field_tag_reference, "ai pathfinding data" },
	{ _field_block, "ai user hint data", &user_hint_block },
	{ _field_block, "ai recording references", &ai_recording_reference_block },
	{ _field_struct, "script data*!" },
	{ _field_block, "manual script file references", &hs_source_reference_block },
	{ _field_tag_reference, "compiled global scripts*!" },
	{ _field_block, "scripting data", &cs_script_data_block },
	{ _field_block, "cutscene flags", &scenario_cutscene_flag_block },
	{ _field_block, "cutscene camera points", &scenario_cutscene_camera_point_block },
	{ _field_block, "cutscene titles", &scenario_cutscene_title_block },
	{ _field_tag_reference, "custom object names" },
	{ _field_tag_reference, "chapter title text" },
	{ _field_block, "scenario kill triggers", &scenario_kill_trigger_volumes_block },
	{ _field_block, "scenario safe zone triggers", &scenario_safe_zone_trigger_volumes_block },
	{ _field_block, "scenario trigger volumes mopp code*!", &trigger_volume_mopp_code_block },
	{ _field_block, "scenario requisition triggers", &scenario_requisition_trigger_volumes_block },
	{ _field_block, "scenario location name triggers", &scenario_location_name_trigger_volumes_block },
	{ _field_block, "scenario unsafe spawn trigger volumes", &scenarioUnsafeSpawnZoneTriggerVolumesBlock_block },
	{ _field_short_block_index, "scenario ordnance bounds trigger volume" },
	{ _field_pad, "ordnandy", 2 },
	{ _field_block, "Orders", &orders_block },
	{ _field_block, "Triggers", &triggers_block },
	{ _field_block, "acoustics palette{background sound palette}", &scenario_acoustics_palette_block },
	{ _field_block, "atmosphere", &scenario_atmosphere_palette_block },
	{ _field_block, "camera fx palette", &scenario_camera_fx_palette_block },
	{ _field_block, "weather palette", &scenario_weather_palette_block },
	{ _field_block, "scenario cluster data", &scenario_cluster_data_block },
	{ _field_array, "object_salts*" },
	{ _field_block, "spawn data", &scenario_spawn_data_block },
	{ _field_tag_reference, "sound effect collection" },
	{ _field_block, "crates", &scenario_crate_block },
	{ _field_block, "crate palette", &scenario_crate_palette_block },
	{ _field_block, "flock palette", &flock_palette_block },
	{ _field_block, "flocks", &flock_instance_block },
	{ _field_tag_reference, "subtitles" },
	{ _field_block, "soundSubtitles*!", &SoundSubtitleBlock_block },
	{ _field_block, "creatures", &scenario_creature_block },
	{ _field_block, "creature palette", &scenario_creature_palette_block },
	{ _field_block, "big battle creature palette", &big_battle_creature_palette_block },
	{ _field_block, "editor folders!", &g_scenario_editor_folder_block },
	{ _field_tag_reference, "game engine strings" },
	{ _field_pad, "QVUC", 4 },
	{ _field_block, "mission dialogue", &ai_scenario_mission_dialogue_block },
	{ _field_tag_reference, "voiceover" },
	{ _field_tag_reference, "objectives" },
	{ _field_tag_reference, "interpolators" },
	{ _field_block, "shared references", &hs_references_block },
	{ _field_tag_reference, "camera effects" },
	{ _field_tag_reference, "global screen effect#ignores the falloff curves" },
	{ _field_tag_reference, "global ssao" },
	{ _field_tag_reference, "atmosphere globals#settings that apply to the entire scenario" },
	{ _field_tag_reference, "new lightmaps" },
	{ _field_tag_reference, "performance throttles" },
	{ _field_block, "ai objectives", &objectives_block },
	{ _field_block, "designer zones", &scenario_designer_zone_block },
	{ _field_block, "zone debugger!", &scenario_zone_debugger_block },
	{ _field_block, "decorators", &scenario_decorator_block },
	{ _field_block, "neuticle palette", &scenario_cheap_particle_system_palette_block },
	{ _field_block, "neuticles", &scenario_cheap_particle_systems_block },
	{ _field_explanation, "Scriptable Light Rigs" },
	{ _field_block, "scriptable light rigs", &scriptableLightRigBlock_block },
	{ _field_block, "cinematics", &scenario_cinematics_block },
	{ _field_block, "cinematic lighting palette", &scenario_cinematic_lighting_palette_block },
	{ _field_block, "override player representations", &player_representation_block },
	{ _field_block, "campaign metagame", &campaign_metagame_scenario_block },
	{ _field_block, "soft surfaces", &soft_surfaces_definition_block },
	{ _field_block, "cubemaps", &scenario_cubemap_block },
	{ _field_block, "airprobes", &scenario_airprobes_block },
	{ _field_block, "budget references", &scenario_budget_references_block },
	{ _field_block, "model references*", &model_references_block },
	{ _field_block, "thespian{performances}", &scenario_performances_block },
	{ _field_block, "puppetShows", &PuppetShowsBlock_block },
	{ _field_tag_reference, "location name globals" },
	{ _field_explanation, "garbage collection" },
	{ _field_block, "garbage collection", &garbage_collection_block },
	{ _field_tag_reference, "hud screen reference#appears for the player through the scenario" },
	{ _field_tag_reference, "required resources" },
	{ _field_tag_reference, "variant globals" },
	{ _field_tag_reference, "ordnance map bitmap" },
	{ _field_real_fraction_bounds, "ordnance map depth bounds" },
	{ _field_explanation, "Random ordnance" },
	{ _field_word_flags, "ordnance flags" },
	{ _field_pad, "SRO", 2 },
	{ _field_tag_reference, "drop pod (scenery)#if set, overrides that in progression globals" },
	{ _field_long_integer, "Ordnance drop count" },
	{ _field_long_integer, "Ordnance max active count#zero means unlimited" },
	{ _field_real_bounds, "Time between random drops:seconds" },
	{ _field_string, "Initial drop name" },
	{ _field_real, "Initial drop delay:seconds#from start of play til fanfare begins" },
	{ _field_real, "Initial drop fanfare duration:seconds" },
	{ _field_string, "Normal drop name:blank string will match all sets" },
	{ _field_string, "Player drop name" },
	{ _field_real, "Nav marker visibility proximity:wu" },
	{ _field_real, "Nav marker premium visibility proximity:wu" },
	{ _field_block, "Drop sets", &scenarioRandomOrdnanceDropSetBlock_block },
	{ _field_explanation, "Ordnance personal" },
	{ _field_tag_reference, "Scenario Ordnance List" },
	{ _field_block, "Unit Recordings", &ScenarioUnitRecordingBlock_block },
	{ _field_block, "Exit load screen#for non-mainmenu, we always use the first one", &loadScreenReferenceBlock_block },
	{ _field_terminator },
};

TAG_GROUP(scenario_required_resource, SCENARIO_REQUIRED_RESOURCE_TAG)
{
	{ _field_block, "resources", &scenario_budget_references_block },
	{ _field_terminator },
};

} // namespace blofeld

