#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(InfinityMissionSeasonImagesDefinition, k_infinityMaximumSeasonCount)
{
	{ _field_explanation, "Season Images" },
	{ _field_long_integer, "season number^" },
	{ _field_tag_reference, "epilogue image#displayed where the missions would be, when the epilogue is selected" },
	{ _field_block, "season images", &InfinityMissionImagesDefinition_block },
	{ _field_terminator },
};

TAG_BLOCK(InfinityMissionImagesDefinition, k_infinityMaximumMissionsPerSeason)
{
	{ _field_tag_reference, "card image^" },
	{ _field_tag_reference, "detail image" },
	{ _field_tag_reference, "lobby image" },
	{ _field_tag_reference, "match image" },
	{ _field_terminator },
};

TAG_BLOCK(pgcr_enemy_to_category_list, k_pgcr_maximum_number_of_categories_per_bucket)
{
	{ _field_string_id, "category display name^" },
	{ _field_short_integer, "sprite index" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad0", 1 },
	{ _field_block, "player types", &pgcr_player_to_category_entry_block },
	{ _field_block, "enemy types", &pgcr_enemy_to_category_entry_block },
	{ _field_terminator },
};

TAG_BLOCK(pgcr_player_to_category_entry, k_pgcr_maximum_number_of_player_entries_per_category)
{
	{ _field_char_enum, "player type" },
	{ _field_pad, "pad0", 3 },
	{ _field_terminator },
};

TAG_BLOCK(pgcr_enemy_to_category_entry, k_pgcr_maximum_number_of_ai_entries_per_category)
{
	{ _field_char_enum, "character type" },
	{ _field_char_enum, "character class" },
	{ _field_pad, "pad0", 2 },
	{ _field_terminator },
};

TAG_BLOCK(pgcr_damage_type_image, k_damage_reporting_type_count)
{
	{ _field_long_enum, "damage type^" },
	{ _field_string_id, "display name" },
	{ _field_tag_reference, "sprite" },
	{ _field_short_integer, "sprite index" },
	{ _field_pad, "pad0", 2 },
	{ _field_terminator },
};

TAG_BLOCK(gui_portrait_pose, k_maxPortraitPoses)
{
	{ _field_string_id, "pose name^" },
	{ _field_string_id, "animation name" },
	{ _field_string_id, "camera view name" },
	{ _field_long_integer, "scenario profile index" },
	{ _field_terminator },
};

TAG_BLOCK(cui_component_screen_reference, k_maximum_number_of_screen_widgets)
{
	{ _field_string_id, "name^#for use in code" },
	{ _field_tag_reference, "cui screen tag" },
	{ _field_terminator },
};

TAG_BLOCK(cui_overlay_camera, k_cui_max_overlay_count)
{
	{ _field_string_id, "resolution name" },
	{ _field_char_enum, "pivot corner" },
	{ _field_pad, "pad0", 3 },
	{ _field_real, "Z near#distance to near clipping plane" },
	{ _field_real, "Z far#distance to far clipping plane" },
	{ _field_real, "X angle degrees#camera angle around the X axis" },
	{ _field_real, "Y angle degrees#camera angle around the Y axis" },
	{ _field_terminator },
};

TAG_BLOCK(cui_player_model_camera_settings_definition, s_cui_player_model_camera_settings_definition::k_maximum_count)
{
	{ _field_explanation, "Camera Settings" },
	{ _field_string_id, "name" },
	{ _field_real_point_3d, "model world position:wu#arbitrary location in the world to place the model" },
	{ _field_real_point_3d, "minimum world position" },
	{ _field_real_point_3d, "maximum world position" },
	{ _field_string_id, "viewed model marker name" },
	{ _field_real_point_3d, "minimum camera offset:wu" },
	{ _field_real_point_3d, "minimum camera focal offset:wu" },
	{ _field_real_point_3d, "maximum camera offset:wu" },
	{ _field_real_point_3d, "maximum camera focal offset:wu" },
	{ _field_real, "initial zoom:[0,1]" },
	{ _field_real, "fov:degrees" },
	{ _field_terminator },
};

TAG_BLOCK(cui_player_model_controller_settings_definition, s_cui_player_model_control_settings_definition::k_maximum_count)
{
	{ _field_string_id, "name" },
	{ _field_real, "zoom speed:wu per tick" },
	{ _field_custom },
	{ _field_struct, "zoom transition function" },
	{ _field_real_euler_angles_2d, "initial rotation:degrees" },
	{ _field_real_euler_angles_2d, "minimum rotation:degrees" },
	{ _field_real_euler_angles_2d, "maximum rotation:degrees" },
	{ _field_real, "rotation speed:degrees per tick" },
	{ _field_terminator },
};

TAG_BLOCK(cui_player_model_transition_settings_definition, s_cui_player_model_transition_settings_definition::k_maximum_count)
{
	{ _field_custom },
	{ _field_struct, "camera transition function" },
	{ _field_terminator },
};

TAG_BLOCK(cui_active_roster_settings, s_cui_active_roster_settings_definition::k_max_count)
{
	{ _field_custom },
	{ _field_struct, "analog scroll function" },
	{ _field_terminator },
};

TAG_BLOCK(campaign_state_screen_script, s_campaign_state_screen_script::k_max_count)
{
	{ _field_long_integer, "map ID" },
	{ _field_string_id, "screen script name" },
	{ _field_tag_reference, "music override" },
	{ _field_terminator },
};

TAG_BLOCK(UserInterfaceGameScreenSequenceStepDefinition, UserInterfaceGameScreenSequenceStep::k_maxCount)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "UMPKIU", 3 },
	{ _field_tag_reference, "screen^" },
	{ _field_short_integer, "startTime:ticks" },
	{ _field_short_integer, "endTime:ticks" },
	{ _field_terminator },
};

TAG_BLOCK(SwapTagReferenceDefinition, SwapTagReferences::k_maxCount)
{
	{ _field_tag_reference, "original tag^" },
	{ _field_tag_reference, "replacement tag" },
	{ _field_terminator },
};

TAG_BLOCK(color_presets, s_color_preset::k_maximum_color_presets)
{
	{ _field_string_id, "name^" },
	{ _field_real_argb_color, "color" },
	{ _field_terminator },
};

TAG_BLOCK(tint_colors, 1)
{
	{ _field_block, "text player", &color_list_block },
	{ _field_block, "text team", &color_list_block },
	{ _field_block, "bitmap player", &color_list_block },
	{ _field_block, "bitmap team", &color_list_block },
	{ _field_custom, "Affiliation" },
	{ _field_real_argb_color, "bitmap friend" },
	{ _field_real_argb_color, "bitmap enemy" },
	{ _field_real_argb_color, "bitmap neutral" },
	{ _field_custom },
	{ _field_custom, "Flood Team Colors" },
	{ _field_real_argb_color, "bitmap flood" },
	{ _field_real_argb_color, "bitmap spartans" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(color_list, ((k_player_color_index_count)>(k_multiplayer_team_game_team_count+1)?(k_player_color_index_count):(k_multiplayer_team_game_team_count+1)))
{
	{ _field_real_argb_color, "color" },
	{ _field_terminator },
};

TAG_BLOCK(gui_alert_description, s_gui_alert_description::k_maximum_gui_error_types_count)
{
	{ _field_string_id, "error name^" },
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "error category" },
	{ _field_char_enum, "error icon" },
	{ _field_pad, "pad0", 1 },
	{ _field_string_id, "title" },
	{ _field_string_id, "message" },
	{ _field_terminator },
};

TAG_BLOCK(gui_dialog_description, s_gui_dialog_description::k_maximum_gui_dialog_types_count)
{
	{ _field_string_id, "dialog name^" },
	{ _field_word_flags, "flags" },
	{ _field_pad, "pad0", 2 },
	{ _field_string_id, "title" },
	{ _field_string_id, "message" },
	{ _field_string_id, "first_item" },
	{ _field_string_id, "second_item" },
	{ _field_string_id, "third_item" },
	{ _field_string_id, "fourth_item" },
	{ _field_string_id, "button key" },
	{ _field_enum, "default item" },
	{ _field_enum, "b button action" },
	{ _field_terminator },
};

TAG_BLOCK(pgcr_incident, s_cui_pgcr_incident::k_maximum_count)
{
	{ _field_string_id, "incident name^" },
	{ _field_long_integer, "maximum stat count*#number of times this can happen before the PGCR stops tracking them" },
	{ _field_terminator },
};

TAG_GROUP(InfinityUIImages, INFINITYUIIMAGES_TAG)
{
	{ _field_block, "seasons", &InfinityMissionSeasonImagesDefinition_block },
	{ _field_terminator },
};

TAG_GROUP(pgcr_enemy_to_category_mapping_definition, PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_TAG)
{
	{ _field_block, "character categories", &pgcr_enemy_to_category_list_block },
	{ _field_block, "vehicle categories", &pgcr_enemy_to_category_list_block },
	{ _field_terminator },
};

TAG_GROUP(pgcr_damage_type_image_mapping_definition, PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_TAG)
{
	{ _field_block, "damage type mapping", &pgcr_damage_type_image_block },
	{ _field_terminator },
};

TAG_GROUP(portrait_poses_definition, PORTRAIT_POSES_DEFINITION_TAG)
{
	{ _field_block, "portrait poses", &gui_portrait_pose_block },
	{ _field_terminator },
};

TAG_GROUP(user_interface_sounds_definition, USER_INTERFACE_SOUNDS_DEFINITION_TAG)
{
	{ _field_custom, "Controller Input Events" },
	{ _field_tag_reference, "tab up" },
	{ _field_tag_reference, "tab left" },
	{ _field_tag_reference, "tab right" },
	{ _field_tag_reference, "tab down" },
	{ _field_tag_reference, "alt stick up" },
	{ _field_tag_reference, "alt stick left" },
	{ _field_tag_reference, "alt stick right" },
	{ _field_tag_reference, "alt stick down" },
	{ _field_tag_reference, "alt tab up" },
	{ _field_tag_reference, "alt tab left" },
	{ _field_tag_reference, "alt tab right" },
	{ _field_tag_reference, "alt tab down" },
	{ _field_tag_reference, "A button pressed" },
	{ _field_tag_reference, "B button pressed" },
	{ _field_tag_reference, "X button pressed" },
	{ _field_tag_reference, "Y button pressed" },
	{ _field_tag_reference, "left trigger pressed" },
	{ _field_tag_reference, "right trigger pressed" },
	{ _field_tag_reference, "D-pad up pressed" },
	{ _field_tag_reference, "D-pad left pressed" },
	{ _field_tag_reference, "D-pad right pressed" },
	{ _field_tag_reference, "D-pad down pressed" },
	{ _field_tag_reference, "start button pressed" },
	{ _field_tag_reference, "back button pressed" },
	{ _field_tag_reference, "left stick pressed" },
	{ _field_tag_reference, "right stick pressed" },
	{ _field_tag_reference, "left bumper pressed" },
	{ _field_tag_reference, "right bumper pressed" },
	{ _field_tag_reference, "left thumbstick pressed" },
	{ _field_tag_reference, "right thumbstick pressed" },
	{ _field_tag_reference, "left stick pressed left" },
	{ _field_tag_reference, "left stick pressed right" },
	{ _field_tag_reference, "left stick pressed up" },
	{ _field_tag_reference, "left stick pressed down" },
	{ _field_tag_reference, "right stick pressed left" },
	{ _field_tag_reference, "right stick pressed right" },
	{ _field_tag_reference, "right stick pressed up" },
	{ _field_tag_reference, "right stick pressed down" },
	{ _field_tag_reference, "A button released" },
	{ _field_tag_reference, "B button released" },
	{ _field_tag_reference, "X button released" },
	{ _field_tag_reference, "Y button released" },
	{ _field_tag_reference, "left trigger released" },
	{ _field_tag_reference, "right trigger released" },
	{ _field_tag_reference, "D-pad up released" },
	{ _field_tag_reference, "D-pad left released" },
	{ _field_tag_reference, "D-pad right released" },
	{ _field_tag_reference, "D-pad down released" },
	{ _field_tag_reference, "start button released" },
	{ _field_tag_reference, "back button released" },
	{ _field_tag_reference, "left stick released" },
	{ _field_tag_reference, "right stick released" },
	{ _field_tag_reference, "left bumper released" },
	{ _field_tag_reference, "right bumper released" },
	{ _field_tag_reference, "left thumbstick released" },
	{ _field_tag_reference, "right thumbstick released" },
	{ _field_tag_reference, "left stick released left" },
	{ _field_tag_reference, "left stick released right" },
	{ _field_tag_reference, "left stick released up" },
	{ _field_tag_reference, "left stick released down" },
	{ _field_tag_reference, "right stick released left" },
	{ _field_tag_reference, "right stick released right" },
	{ _field_tag_reference, "right stick released up" },
	{ _field_tag_reference, "right stick released down" },
	{ _field_custom },
	{ _field_custom, "General" },
	{ _field_tag_reference, "error" },
	{ _field_custom },
	{ _field_custom, "Screen" },
	{ _field_tag_reference, "screen transition in" },
	{ _field_tag_reference, "screen transition out" },
	{ _field_custom },
	{ _field_custom, "Timers" },
	{ _field_tag_reference, "game start countdown timer first tick" },
	{ _field_tag_reference, "game start countdown timer tick" },
	{ _field_tag_reference, "game start countdown timer final tick" },
	{ _field_tag_reference, "alternate countdown timer first tick" },
	{ _field_tag_reference, "alternate countdown timer tick" },
	{ _field_tag_reference, "alternate countdown timer final tick" },
	{ _field_custom },
	{ _field_custom, "Misc" },
	{ _field_tag_reference, "matchmaking reveal" },
	{ _field_custom },
	{ _field_custom, "Exit Experience" },
	{ _field_tag_reference, "game completion" },
	{ _field_tag_reference, "winning bonus" },
	{ _field_tag_reference, "hopper bonus" },
	{ _field_tag_reference, "boost bonus" },
	{ _field_tag_reference, "fasttrack bonus" },
	{ _field_tag_reference, "totals" },
	{ _field_tag_reference, "subrank up" },
	{ _field_tag_reference, "rank up" },
	{ _field_tag_reference, "completed" },
	{ _field_tag_reference, "counter loop" },
	{ _field_tag_reference, "score bonus" },
	{ _field_tag_reference, "rewards" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(user_interface_globals_definition, USER_INTERFACE_GLOBALS_DEFINITION_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_explanation, "Shared Globals" },
	{ _field_tag_reference, "shared globals" },
	{ _field_explanation, "Multiplayer Variant Settings Interface" },
	{ _field_tag_reference, "mp variant settings ui" },
	{ _field_explanation, "Game Hopper Localization Strings" },
	{ _field_tag_reference, "game hopper descriptions" },
	{ _field_explanation, "Screen Widgets" },
	{ _field_block, "cui screen widgets", &cui_component_screen_reference_block },
	{ _field_block, "cui overlay cameras", &cui_overlay_camera_block },
	{ _field_block, "player model camera settings", &cui_player_model_camera_settings_definition_block },
	{ _field_block, "player model input settings", &cui_player_model_controller_settings_definition_block },
	{ _field_block, "player model camera transition settings", &cui_player_model_transition_settings_definition_block },
	{ _field_tag_reference, "purchase globals" },
	{ _field_tag_reference, "infinity mission images{infinity mission images ref}" },
	{ _field_block, "active roster settings", &cui_active_roster_settings_block },
	{ _field_explanation, "PGCR Categories Definitions" },
	{ _field_tag_reference, "pgcr categories definitions" },
	{ _field_explanation, "PGCR Damage Types Definitions" },
	{ _field_tag_reference, "pgcr damage types definitions" },
	{ _field_explanation, "Campaign State Screen Scripts" },
	{ _field_block, "campaign state screen scripts", &campaign_state_screen_script_block },
	{ _field_real, "spawn-timer countdown rate:counts/sec" },
	{ _field_block, "game intro sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
	{ _field_block, "game round end sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
	{ _field_block, "game next round sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
	{ _field_block, "game end sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
	{ _field_block, "game end with killcam sequence", &UserInterfaceGameScreenSequenceStepDefinition_block },
	{ _field_tag_reference, "HUD globals#global settings for the HUD. Set this for ingame globals." },
	{ _field_tag_reference, "portrait poses" },
	{ _field_block, "swap tags", &SwapTagReferenceDefinition_block },
	{ _field_terminator },
};

TAG_GROUP(user_interface_shared_globals_definition, USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG)
{
	{ _field_explanation, "UI Rendering Globals" },
	{ _field_short_integer, "inc. text update period:milliseconds" },
	{ _field_short_integer, "inc. text block character:ASCII code" },
	{ _field_real, "near clip plane distance:objects closer than this are not drawn" },
	{ _field_real, "projection plane distance:distance at which objects are rendered when z=0 (normal size)" },
	{ _field_real, "far clip plane distance:objects farther than this are not drawn" },
	{ _field_explanation, "Global Text Strings" },
	{ _field_tag_reference, "unicode string list tag" },
	{ _field_tag_reference, "unicode damage reporting string list tag" },
	{ _field_tag_reference, "unicode fire team member name string list{unicode fire team member string list tag}" },
	{ _field_tag_reference, "unicode fire team member service tag string list" },
	{ _field_explanation, "Main menu music" },
	{ _field_tag_reference, "main menu music" },
	{ _field_tag_reference, "main menu alternate music" },
	{ _field_long_integer, "music fade time:milliseconds" },
	{ _field_explanation, "Default Text and Shadow Colors" },
	{ _field_real_argb_color, "text color" },
	{ _field_real_argb_color, "shadow color" },
	{ _field_explanation, "Color presets" },
	{ _field_block, "color presets", &color_presets_block },
	{ _field_explanation, "Tint colors" },
	{ _field_block, "tint colors", &tint_colors_block },
	{ _field_explanation, "Emblem counts" },
	{ _field_short_integer, "Primary emblem count" },
	{ _field_short_integer, "Secondary emblem count" },
	{ _field_explanation, "User interface sounds" },
	{ _field_tag_reference, "default sounds" },
	{ _field_explanation, "HaloX Alerts" },
	{ _field_block, "alert descriptions", &gui_alert_description_block },
	{ _field_explanation, "HaloX Dialogs" },
	{ _field_block, "dialog descriptions", &gui_dialog_description_block },
	{ _field_explanation, "Content Aspect Ratio Scaling" },
	{ _field_real_vector_2d, "16x9" },
	{ _field_real_vector_2d, "4x3" },
	{ _field_explanation, "Blur Constants" },
	{ _field_real, "horizontal blur factor" },
	{ _field_real, "vertical blur factor" },
	{ _field_explanation, "Appearance Model Names" },
	{ _field_string_id, "mc biped name" },
	{ _field_string, "mc ai squad name" },
	{ _field_string_id, "mc ai start pos" },
	{ _field_string_id, "elite biped name" },
	{ _field_string, "elite ai squad name" },
	{ _field_string_id, "elite ai start pos" },
	{ _field_explanation, "Player Portrait Model Names" },
	{ _field_string_id, "spartan portrait biped name" },
	{ _field_string_id, "elite portrait biped name" },
	{ _field_explanation, "UI Navigation speed" },
	{ _field_long_integer, "navigation tab delay msec" },
	{ _field_long_integer, "navigation tab fast wait msec" },
	{ _field_long_integer, "navigation tab fast delay msec" },
	{ _field_explanation, "Spinner tab speed" },
	{ _field_custom },
	{ _field_struct, "spinner tab speed function" },
	{ _field_long_integer, "max input time (x) on the graph (msec)" },
	{ _field_explanation, "Attract Mode Settings" },
	{ _field_long_integer, "delay:seconds" },
	{ _field_block, "PGCR per player tracked incidents", &pgcr_incident_block },
	{ _field_terminator },
};

} // namespace blofeld

