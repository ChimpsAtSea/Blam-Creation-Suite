#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(InfinityUIImages_struct_definition)
{
	FIELD( _field_block, "seasons", &InfinityMissionSeasonImagesDefinition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(pgcr_enemy_to_category_mapping_definition_struct_definition)
{
	FIELD( _field_block, "character categories", &pgcr_enemy_to_category_list_block ),
	FIELD( _field_block, "vehicle categories", &pgcr_enemy_to_category_list_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(pgcr_damage_type_image_mapping_definition_struct_definition)
{
	FIELD( _field_block, "damage type mapping", &pgcr_damage_type_image_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(portrait_poses_definition_struct_definition)
{
	FIELD( _field_block, "portrait poses", &gui_portrait_pose_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(user_interface_sounds_definition_struct_definition)
{
	FIELD( _field_custom, "Controller Input Events" ),
	FIELD( _field_tag_reference, "tab up" ),
	FIELD( _field_tag_reference, "tab left" ),
	FIELD( _field_tag_reference, "tab right" ),
	FIELD( _field_tag_reference, "tab down" ),
	FIELD( _field_tag_reference, "alt stick up" ),
	FIELD( _field_tag_reference, "alt stick left" ),
	FIELD( _field_tag_reference, "alt stick right" ),
	FIELD( _field_tag_reference, "alt stick down" ),
	FIELD( _field_tag_reference, "alt tab up" ),
	FIELD( _field_tag_reference, "alt tab left" ),
	FIELD( _field_tag_reference, "alt tab right" ),
	FIELD( _field_tag_reference, "alt tab down" ),
	FIELD( _field_tag_reference, "A button pressed" ),
	FIELD( _field_tag_reference, "B button pressed" ),
	FIELD( _field_tag_reference, "X button pressed" ),
	FIELD( _field_tag_reference, "Y button pressed" ),
	FIELD( _field_tag_reference, "left trigger pressed" ),
	FIELD( _field_tag_reference, "right trigger pressed" ),
	FIELD( _field_tag_reference, "D-pad up pressed" ),
	FIELD( _field_tag_reference, "D-pad left pressed" ),
	FIELD( _field_tag_reference, "D-pad right pressed" ),
	FIELD( _field_tag_reference, "D-pad down pressed" ),
	FIELD( _field_tag_reference, "start button pressed" ),
	FIELD( _field_tag_reference, "back button pressed" ),
	FIELD( _field_tag_reference, "left stick pressed" ),
	FIELD( _field_tag_reference, "right stick pressed" ),
	FIELD( _field_tag_reference, "left bumper pressed" ),
	FIELD( _field_tag_reference, "right bumper pressed" ),
	FIELD( _field_tag_reference, "left thumbstick pressed" ),
	FIELD( _field_tag_reference, "right thumbstick pressed" ),
	FIELD( _field_tag_reference, "left stick pressed left" ),
	FIELD( _field_tag_reference, "left stick pressed right" ),
	FIELD( _field_tag_reference, "left stick pressed up" ),
	FIELD( _field_tag_reference, "left stick pressed down" ),
	FIELD( _field_tag_reference, "right stick pressed left" ),
	FIELD( _field_tag_reference, "right stick pressed right" ),
	FIELD( _field_tag_reference, "right stick pressed up" ),
	FIELD( _field_tag_reference, "right stick pressed down" ),
	FIELD( _field_tag_reference, "A button released" ),
	FIELD( _field_tag_reference, "B button released" ),
	FIELD( _field_tag_reference, "X button released" ),
	FIELD( _field_tag_reference, "Y button released" ),
	FIELD( _field_tag_reference, "left trigger released" ),
	FIELD( _field_tag_reference, "right trigger released" ),
	FIELD( _field_tag_reference, "D-pad up released" ),
	FIELD( _field_tag_reference, "D-pad left released" ),
	FIELD( _field_tag_reference, "D-pad right released" ),
	FIELD( _field_tag_reference, "D-pad down released" ),
	FIELD( _field_tag_reference, "start button released" ),
	FIELD( _field_tag_reference, "back button released" ),
	FIELD( _field_tag_reference, "left stick released" ),
	FIELD( _field_tag_reference, "right stick released" ),
	FIELD( _field_tag_reference, "left bumper released" ),
	FIELD( _field_tag_reference, "right bumper released" ),
	FIELD( _field_tag_reference, "left thumbstick released" ),
	FIELD( _field_tag_reference, "right thumbstick released" ),
	FIELD( _field_tag_reference, "left stick released left" ),
	FIELD( _field_tag_reference, "left stick released right" ),
	FIELD( _field_tag_reference, "left stick released up" ),
	FIELD( _field_tag_reference, "left stick released down" ),
	FIELD( _field_tag_reference, "right stick released left" ),
	FIELD( _field_tag_reference, "right stick released right" ),
	FIELD( _field_tag_reference, "right stick released up" ),
	FIELD( _field_tag_reference, "right stick released down" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "General" ),
	FIELD( _field_tag_reference, "error" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Screen" ),
	FIELD( _field_tag_reference, "screen transition in" ),
	FIELD( _field_tag_reference, "screen transition out" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Timers" ),
	FIELD( _field_tag_reference, "game start countdown timer first tick" ),
	FIELD( _field_tag_reference, "game start countdown timer tick" ),
	FIELD( _field_tag_reference, "game start countdown timer final tick" ),
	FIELD( _field_tag_reference, "alternate countdown timer first tick" ),
	FIELD( _field_tag_reference, "alternate countdown timer tick" ),
	FIELD( _field_tag_reference, "alternate countdown timer final tick" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Misc" ),
	FIELD( _field_tag_reference, "matchmaking reveal" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Exit Experience" ),
	FIELD( _field_tag_reference, "game completion" ),
	FIELD( _field_tag_reference, "winning bonus" ),
	FIELD( _field_tag_reference, "hopper bonus" ),
	FIELD( _field_tag_reference, "boost bonus" ),
	FIELD( _field_tag_reference, "fasttrack bonus" ),
	FIELD( _field_tag_reference, "totals" ),
	FIELD( _field_tag_reference, "subrank up" ),
	FIELD( _field_tag_reference, "rank up" ),
	FIELD( _field_tag_reference, "completed" ),
	FIELD( _field_tag_reference, "counter loop" ),
	FIELD( _field_tag_reference, "score bonus" ),
	FIELD( _field_tag_reference, "rewards" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(user_interface_globals_definition_struct_definition)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "Shared Globals" ),
	FIELD( _field_tag_reference, "shared globals" ),
	FIELD( _field_explanation, "Multiplayer Variant Settings Interface" ),
	FIELD( _field_tag_reference, "mp variant settings ui" ),
	FIELD( _field_explanation, "Game Hopper Localization Strings" ),
	FIELD( _field_tag_reference, "game hopper descriptions" ),
	FIELD( _field_explanation, "Screen Widgets" ),
	FIELD( _field_block, "cui screen widgets", &cui_component_screen_reference_block_definition ),
	FIELD( _field_block, "cui overlay cameras", &cui_overlay_camera_block_definition ),
	FIELD( _field_block, "player model camera settings", &cui_player_model_camera_settings_definition ),
	FIELD( _field_block, "player model input settings", &cui_player_model_controller_settings_definition ),
	FIELD( _field_block, "player model camera transition settings", &cui_player_model_transition_settings_definition ),
	FIELD( _field_tag_reference, "purchase globals" ),
	FIELD( _field_tag_reference, "infinity mission images{infinity mission images ref}" ),
	FIELD( _field_block, "active roster settings", &cui_active_roster_settings_block ),
	FIELD( _field_explanation, "PGCR Categories Definitions" ),
	FIELD( _field_tag_reference, "pgcr categories definitions" ),
	FIELD( _field_explanation, "PGCR Damage Types Definitions" ),
	FIELD( _field_tag_reference, "pgcr damage types definitions" ),
	FIELD( _field_explanation, "Campaign State Screen Scripts" ),
	FIELD( _field_block, "campaign state screen scripts", &campaign_state_screen_script_block_definition ),
	FIELD( _field_real, "spawn-timer countdown rate:counts/sec" ),
	FIELD( _field_block, "game intro sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game round end sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game next round sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game end sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game end with killcam sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_tag_reference, "HUD globals#global settings for the HUD. Set this for ingame globals." ),
	FIELD( _field_tag_reference, "portrait poses" ),
	FIELD( _field_block, "swap tags", &SwapTagReferenceDefinition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(user_interface_shared_globals_definition_struct_definition)
{
	FIELD( _field_explanation, "UI Rendering Globals" ),
	FIELD( _field_short_integer, "inc. text update period:milliseconds" ),
	FIELD( _field_short_integer, "inc. text block character:ASCII code" ),
	FIELD( _field_real, "near clip plane distance:objects closer than this are not drawn" ),
	FIELD( _field_real, "projection plane distance:distance at which objects are rendered when z=0 (normal size)" ),
	FIELD( _field_real, "far clip plane distance:objects farther than this are not drawn" ),
	FIELD( _field_explanation, "Global Text Strings" ),
	FIELD( _field_tag_reference, "unicode string list tag" ),
	FIELD( _field_tag_reference, "unicode damage reporting string list tag" ),
	FIELD( _field_tag_reference, "unicode fire team member name string list{unicode fire team member string list tag}" ),
	FIELD( _field_tag_reference, "unicode fire team member service tag string list" ),
	FIELD( _field_explanation, "Main menu music" ),
	FIELD( _field_tag_reference, "main menu music" ),
	FIELD( _field_tag_reference, "main menu alternate music" ),
	FIELD( _field_long_integer, "music fade time:milliseconds" ),
	FIELD( _field_explanation, "Default Text and Shadow Colors" ),
	FIELD( _field_real_argb_color, "text color" ),
	FIELD( _field_real_argb_color, "shadow color" ),
	FIELD( _field_explanation, "Color presets" ),
	FIELD( _field_block, "color presets", &color_presets_block ),
	FIELD( _field_explanation, "Tint colors" ),
	FIELD( _field_block, "tint colors", &tint_colors_block ),
	FIELD( _field_explanation, "Emblem counts" ),
	FIELD( _field_short_integer, "Primary emblem count" ),
	FIELD( _field_short_integer, "Secondary emblem count" ),
	FIELD( _field_explanation, "User interface sounds" ),
	FIELD( _field_tag_reference, "default sounds" ),
	FIELD( _field_explanation, "HaloX Alerts" ),
	FIELD( _field_block, "alert descriptions", &gui_alert_description_block ),
	FIELD( _field_explanation, "HaloX Dialogs" ),
	FIELD( _field_block, "dialog descriptions", &gui_dialog_description_block ),
	FIELD( _field_explanation, "Content Aspect Ratio Scaling" ),
	FIELD( _field_real_vector_2d, "16x9" ),
	FIELD( _field_real_vector_2d, "4x3" ),
	FIELD( _field_explanation, "Blur Constants" ),
	FIELD( _field_real, "horizontal blur factor" ),
	FIELD( _field_real, "vertical blur factor" ),
	FIELD( _field_explanation, "Appearance Model Names" ),
	FIELD( _field_string_id, "mc biped name" ),
	FIELD( _field_string, "mc ai squad name" ),
	FIELD( _field_string_id, "mc ai start pos" ),
	FIELD( _field_string_id, "elite biped name" ),
	FIELD( _field_string, "elite ai squad name" ),
	FIELD( _field_string_id, "elite ai start pos" ),
	FIELD( _field_explanation, "Player Portrait Model Names" ),
	FIELD( _field_string_id, "spartan portrait biped name" ),
	FIELD( _field_string_id, "elite portrait biped name" ),
	FIELD( _field_explanation, "UI Navigation speed" ),
	FIELD( _field_long_integer, "navigation tab delay msec" ),
	FIELD( _field_long_integer, "navigation tab fast wait msec" ),
	FIELD( _field_long_integer, "navigation tab fast delay msec" ),
	FIELD( _field_explanation, "Spinner tab speed" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "spinner tab speed function", &mapping_function_struct_definition ),
	FIELD( _field_long_integer, "max input time (x) on the graph (msec)" ),
	FIELD( _field_explanation, "Attract Mode Settings" ),
	FIELD( _field_long_integer, "delay:seconds" ),
	FIELD( _field_block, "PGCR per player tracked incidents", &pgcr_incident_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(InfinityMissionSeasonImagesDefinition, k_infinityMaximumSeasonCount)
{
	FIELD( _field_explanation, "Season Images" ),
	FIELD( _field_long_integer, "season number^" ),
	FIELD( _field_tag_reference, "epilogue image#displayed where the missions would be, when the epilogue is selected" ),
	FIELD( _field_block, "season images", &InfinityMissionImagesDefinition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(InfinityMissionImagesDefinition, k_infinityMaximumMissionsPerSeason)
{
	FIELD( _field_tag_reference, "card image^" ),
	FIELD( _field_tag_reference, "detail image" ),
	FIELD( _field_tag_reference, "lobby image" ),
	FIELD( _field_tag_reference, "match image" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pgcr_enemy_to_category_list_block, k_pgcr_maximum_number_of_categories_per_bucket)
{
	FIELD( _field_string_id, "category display name^" ),
	FIELD( _field_short_integer, "sprite index" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_block, "player types", &pgcr_player_to_category_entry_block ),
	FIELD( _field_block, "enemy types", &pgcr_enemy_to_category_entry_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pgcr_player_to_category_entry_block, k_pgcr_maximum_number_of_player_entries_per_category)
{
	FIELD( _field_char_enum, "player type" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pgcr_enemy_to_category_entry_block, k_pgcr_maximum_number_of_ai_entries_per_category)
{
	FIELD( _field_char_enum, "character type" ),
	FIELD( _field_char_enum, "character class" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pgcr_damage_type_image_block, k_damage_reporting_type_count)
{
	FIELD( _field_long_enum, "damage type^" ),
	FIELD( _field_string_id, "display name" ),
	FIELD( _field_tag_reference, "sprite" ),
	FIELD( _field_short_integer, "sprite index" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gui_portrait_pose_block, k_maxPortraitPoses)
{
	FIELD( _field_string_id, "pose name^" ),
	FIELD( _field_string_id, "animation name" ),
	FIELD( _field_string_id, "camera view name" ),
	FIELD( _field_long_integer, "scenario profile index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cui_component_screen_reference_block_definition, k_maximum_number_of_screen_widgets)
{
	FIELD( _field_string_id, "name^#for use in code" ),
	FIELD( _field_tag_reference, "cui screen tag" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cui_overlay_camera_block_definition, k_cui_max_overlay_count)
{
	FIELD( _field_string_id, "resolution name" ),
	FIELD( _field_char_enum, "pivot corner" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_real, "Z near#distance to near clipping plane" ),
	FIELD( _field_real, "Z far#distance to far clipping plane" ),
	FIELD( _field_real, "X angle degrees#camera angle around the X axis" ),
	FIELD( _field_real, "Y angle degrees#camera angle around the Y axis" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cui_player_model_camera_settings_definition, s_cui_player_model_camera_settings_definition::k_maximum_count)
{
	FIELD( _field_explanation, "Camera Settings" ),
	FIELD( _field_string_id, "name" ),
	FIELD( _field_real_point_3d, "model world position:wu#arbitrary location in the world to place the model" ),
	FIELD( _field_real_point_3d, "minimum world position" ),
	FIELD( _field_real_point_3d, "maximum world position" ),
	FIELD( _field_string_id, "viewed model marker name" ),
	FIELD( _field_real_point_3d, "minimum camera offset:wu" ),
	FIELD( _field_real_point_3d, "minimum camera focal offset:wu" ),
	FIELD( _field_real_point_3d, "maximum camera offset:wu" ),
	FIELD( _field_real_point_3d, "maximum camera focal offset:wu" ),
	FIELD( _field_real, "initial zoom:[0,1]" ),
	FIELD( _field_real, "fov:degrees" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cui_player_model_controller_settings_definition, s_cui_player_model_control_settings_definition::k_maximum_count)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_real, "zoom speed:wu per tick" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "zoom transition function", &mapping_function_struct_definition ),
	FIELD( _field_real_euler_angles_2d, "initial rotation:degrees" ),
	FIELD( _field_real_euler_angles_2d, "minimum rotation:degrees" ),
	FIELD( _field_real_euler_angles_2d, "maximum rotation:degrees" ),
	FIELD( _field_real, "rotation speed:degrees per tick" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cui_player_model_transition_settings_definition, s_cui_player_model_transition_settings_definition::k_maximum_count)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "camera transition function", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cui_active_roster_settings_block, s_cui_active_roster_settings_definition::k_max_count)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "analog scroll function", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(campaign_state_screen_script_block_definition, s_campaign_state_screen_script::k_max_count)
{
	FIELD( _field_long_integer, "map ID" ),
	FIELD( _field_string_id, "screen script name" ),
	FIELD( _field_tag_reference, "music override" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceGameScreenSequenceStepDefinition, UserInterfaceGameScreenSequenceStep::k_maxCount)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "UMPKIU", 3 ),
	FIELD( _field_tag_reference, "screen^" ),
	FIELD( _field_short_integer, "startTime:ticks" ),
	FIELD( _field_short_integer, "endTime:ticks" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SwapTagReferenceDefinition, SwapTagReferences::k_maxCount)
{
	FIELD( _field_tag_reference, "original tag^" ),
	FIELD( _field_tag_reference, "replacement tag" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(color_presets_block, s_color_preset::k_maximum_color_presets)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(tint_colors_block, 1)
{
	FIELD( _field_block, "text player", &color_list_block ),
	FIELD( _field_block, "text team", &color_list_block ),
	FIELD( _field_block, "bitmap player", &color_list_block ),
	FIELD( _field_block, "bitmap team", &color_list_block ),
	FIELD( _field_custom, "Affiliation" ),
	FIELD( _field_real_argb_color, "bitmap friend" ),
	FIELD( _field_real_argb_color, "bitmap enemy" ),
	FIELD( _field_real_argb_color, "bitmap neutral" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Flood Team Colors" ),
	FIELD( _field_real_argb_color, "bitmap flood" ),
	FIELD( _field_real_argb_color, "bitmap spartans" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(color_list_block, ((k_player_color_index_count)>(k_multiplayer_team_game_team_count+1)?(k_player_color_index_count):(k_multiplayer_team_game_team_count+1)))
{
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gui_alert_description_block, s_gui_alert_description::k_maximum_gui_error_types_count)
{
	FIELD( _field_string_id, "error name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "error category" ),
	FIELD( _field_char_enum, "error icon" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_string_id, "title" ),
	FIELD( _field_string_id, "message" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gui_dialog_description_block, s_gui_dialog_description::k_maximum_gui_dialog_types_count)
{
	FIELD( _field_string_id, "dialog name^" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "pad0", 2 ),
	FIELD( _field_string_id, "title" ),
	FIELD( _field_string_id, "message" ),
	FIELD( _field_string_id, "first_item" ),
	FIELD( _field_string_id, "second_item" ),
	FIELD( _field_string_id, "third_item" ),
	FIELD( _field_string_id, "fourth_item" ),
	FIELD( _field_string_id, "button key" ),
	FIELD( _field_enum, "default item" ),
	FIELD( _field_enum, "b button action" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(pgcr_incident_block, s_cui_pgcr_incident::k_maximum_count)
{
	FIELD( _field_string_id, "incident name^" ),
	FIELD( _field_long_integer, "maximum stat count*#number of times this can happen before the PGCR stops tracking them" ),
	FIELD( _field_terminator )
};

TAG_GROUP(InfinityUIImages_block, INFINITYUIIMAGES_TAG)
{
	FIELD( _field_block, "seasons", &InfinityMissionSeasonImagesDefinition ),
	FIELD( _field_terminator )
};

TAG_GROUP(pgcr_enemy_to_category_mapping_definition_block, PGCR_ENEMY_TO_CATEGORY_MAPPING_DEFINITION_TAG)
{
	FIELD( _field_block, "character categories", &pgcr_enemy_to_category_list_block ),
	FIELD( _field_block, "vehicle categories", &pgcr_enemy_to_category_list_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(pgcr_damage_type_image_mapping_definition_block, PGCR_DAMAGE_TYPE_IMAGE_MAPPING_DEFINITION_TAG)
{
	FIELD( _field_block, "damage type mapping", &pgcr_damage_type_image_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(portrait_poses_definition_block, PORTRAIT_POSES_DEFINITION_TAG)
{
	FIELD( _field_block, "portrait poses", &gui_portrait_pose_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(user_interface_sounds_definition_block, USER_INTERFACE_SOUNDS_DEFINITION_TAG)
{
	FIELD( _field_custom, "Controller Input Events" ),
	FIELD( _field_tag_reference, "tab up" ),
	FIELD( _field_tag_reference, "tab left" ),
	FIELD( _field_tag_reference, "tab right" ),
	FIELD( _field_tag_reference, "tab down" ),
	FIELD( _field_tag_reference, "alt stick up" ),
	FIELD( _field_tag_reference, "alt stick left" ),
	FIELD( _field_tag_reference, "alt stick right" ),
	FIELD( _field_tag_reference, "alt stick down" ),
	FIELD( _field_tag_reference, "alt tab up" ),
	FIELD( _field_tag_reference, "alt tab left" ),
	FIELD( _field_tag_reference, "alt tab right" ),
	FIELD( _field_tag_reference, "alt tab down" ),
	FIELD( _field_tag_reference, "A button pressed" ),
	FIELD( _field_tag_reference, "B button pressed" ),
	FIELD( _field_tag_reference, "X button pressed" ),
	FIELD( _field_tag_reference, "Y button pressed" ),
	FIELD( _field_tag_reference, "left trigger pressed" ),
	FIELD( _field_tag_reference, "right trigger pressed" ),
	FIELD( _field_tag_reference, "D-pad up pressed" ),
	FIELD( _field_tag_reference, "D-pad left pressed" ),
	FIELD( _field_tag_reference, "D-pad right pressed" ),
	FIELD( _field_tag_reference, "D-pad down pressed" ),
	FIELD( _field_tag_reference, "start button pressed" ),
	FIELD( _field_tag_reference, "back button pressed" ),
	FIELD( _field_tag_reference, "left stick pressed" ),
	FIELD( _field_tag_reference, "right stick pressed" ),
	FIELD( _field_tag_reference, "left bumper pressed" ),
	FIELD( _field_tag_reference, "right bumper pressed" ),
	FIELD( _field_tag_reference, "left thumbstick pressed" ),
	FIELD( _field_tag_reference, "right thumbstick pressed" ),
	FIELD( _field_tag_reference, "left stick pressed left" ),
	FIELD( _field_tag_reference, "left stick pressed right" ),
	FIELD( _field_tag_reference, "left stick pressed up" ),
	FIELD( _field_tag_reference, "left stick pressed down" ),
	FIELD( _field_tag_reference, "right stick pressed left" ),
	FIELD( _field_tag_reference, "right stick pressed right" ),
	FIELD( _field_tag_reference, "right stick pressed up" ),
	FIELD( _field_tag_reference, "right stick pressed down" ),
	FIELD( _field_tag_reference, "A button released" ),
	FIELD( _field_tag_reference, "B button released" ),
	FIELD( _field_tag_reference, "X button released" ),
	FIELD( _field_tag_reference, "Y button released" ),
	FIELD( _field_tag_reference, "left trigger released" ),
	FIELD( _field_tag_reference, "right trigger released" ),
	FIELD( _field_tag_reference, "D-pad up released" ),
	FIELD( _field_tag_reference, "D-pad left released" ),
	FIELD( _field_tag_reference, "D-pad right released" ),
	FIELD( _field_tag_reference, "D-pad down released" ),
	FIELD( _field_tag_reference, "start button released" ),
	FIELD( _field_tag_reference, "back button released" ),
	FIELD( _field_tag_reference, "left stick released" ),
	FIELD( _field_tag_reference, "right stick released" ),
	FIELD( _field_tag_reference, "left bumper released" ),
	FIELD( _field_tag_reference, "right bumper released" ),
	FIELD( _field_tag_reference, "left thumbstick released" ),
	FIELD( _field_tag_reference, "right thumbstick released" ),
	FIELD( _field_tag_reference, "left stick released left" ),
	FIELD( _field_tag_reference, "left stick released right" ),
	FIELD( _field_tag_reference, "left stick released up" ),
	FIELD( _field_tag_reference, "left stick released down" ),
	FIELD( _field_tag_reference, "right stick released left" ),
	FIELD( _field_tag_reference, "right stick released right" ),
	FIELD( _field_tag_reference, "right stick released up" ),
	FIELD( _field_tag_reference, "right stick released down" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "General" ),
	FIELD( _field_tag_reference, "error" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Screen" ),
	FIELD( _field_tag_reference, "screen transition in" ),
	FIELD( _field_tag_reference, "screen transition out" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Timers" ),
	FIELD( _field_tag_reference, "game start countdown timer first tick" ),
	FIELD( _field_tag_reference, "game start countdown timer tick" ),
	FIELD( _field_tag_reference, "game start countdown timer final tick" ),
	FIELD( _field_tag_reference, "alternate countdown timer first tick" ),
	FIELD( _field_tag_reference, "alternate countdown timer tick" ),
	FIELD( _field_tag_reference, "alternate countdown timer final tick" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Misc" ),
	FIELD( _field_tag_reference, "matchmaking reveal" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Exit Experience" ),
	FIELD( _field_tag_reference, "game completion" ),
	FIELD( _field_tag_reference, "winning bonus" ),
	FIELD( _field_tag_reference, "hopper bonus" ),
	FIELD( _field_tag_reference, "boost bonus" ),
	FIELD( _field_tag_reference, "fasttrack bonus" ),
	FIELD( _field_tag_reference, "totals" ),
	FIELD( _field_tag_reference, "subrank up" ),
	FIELD( _field_tag_reference, "rank up" ),
	FIELD( _field_tag_reference, "completed" ),
	FIELD( _field_tag_reference, "counter loop" ),
	FIELD( _field_tag_reference, "score bonus" ),
	FIELD( _field_tag_reference, "rewards" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP(user_interface_globals_definition_block, USER_INTERFACE_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "Shared Globals" ),
	FIELD( _field_tag_reference, "shared globals" ),
	FIELD( _field_explanation, "Multiplayer Variant Settings Interface" ),
	FIELD( _field_tag_reference, "mp variant settings ui" ),
	FIELD( _field_explanation, "Game Hopper Localization Strings" ),
	FIELD( _field_tag_reference, "game hopper descriptions" ),
	FIELD( _field_explanation, "Screen Widgets" ),
	FIELD( _field_block, "cui screen widgets", &cui_component_screen_reference_block_definition ),
	FIELD( _field_block, "cui overlay cameras", &cui_overlay_camera_block_definition ),
	FIELD( _field_block, "player model camera settings", &cui_player_model_camera_settings_definition ),
	FIELD( _field_block, "player model input settings", &cui_player_model_controller_settings_definition ),
	FIELD( _field_block, "player model camera transition settings", &cui_player_model_transition_settings_definition ),
	FIELD( _field_tag_reference, "purchase globals" ),
	FIELD( _field_tag_reference, "infinity mission images{infinity mission images ref}" ),
	FIELD( _field_block, "active roster settings", &cui_active_roster_settings_block ),
	FIELD( _field_explanation, "PGCR Categories Definitions" ),
	FIELD( _field_tag_reference, "pgcr categories definitions" ),
	FIELD( _field_explanation, "PGCR Damage Types Definitions" ),
	FIELD( _field_tag_reference, "pgcr damage types definitions" ),
	FIELD( _field_explanation, "Campaign State Screen Scripts" ),
	FIELD( _field_block, "campaign state screen scripts", &campaign_state_screen_script_block_definition ),
	FIELD( _field_real, "spawn-timer countdown rate:counts/sec" ),
	FIELD( _field_block, "game intro sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game round end sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game next round sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game end sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_block, "game end with killcam sequence", &UserInterfaceGameScreenSequenceStepDefinition ),
	FIELD( _field_tag_reference, "HUD globals#global settings for the HUD. Set this for ingame globals." ),
	FIELD( _field_tag_reference, "portrait poses" ),
	FIELD( _field_block, "swap tags", &SwapTagReferenceDefinition ),
	FIELD( _field_terminator )
};

TAG_GROUP(user_interface_shared_globals_definition_block, USER_INTERFACE_SHARED_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_explanation, "UI Rendering Globals" ),
	FIELD( _field_short_integer, "inc. text update period:milliseconds" ),
	FIELD( _field_short_integer, "inc. text block character:ASCII code" ),
	FIELD( _field_real, "near clip plane distance:objects closer than this are not drawn" ),
	FIELD( _field_real, "projection plane distance:distance at which objects are rendered when z=0 (normal size)" ),
	FIELD( _field_real, "far clip plane distance:objects farther than this are not drawn" ),
	FIELD( _field_explanation, "Global Text Strings" ),
	FIELD( _field_tag_reference, "unicode string list tag" ),
	FIELD( _field_tag_reference, "unicode damage reporting string list tag" ),
	FIELD( _field_tag_reference, "unicode fire team member name string list{unicode fire team member string list tag}" ),
	FIELD( _field_tag_reference, "unicode fire team member service tag string list" ),
	FIELD( _field_explanation, "Main menu music" ),
	FIELD( _field_tag_reference, "main menu music" ),
	FIELD( _field_tag_reference, "main menu alternate music" ),
	FIELD( _field_long_integer, "music fade time:milliseconds" ),
	FIELD( _field_explanation, "Default Text and Shadow Colors" ),
	FIELD( _field_real_argb_color, "text color" ),
	FIELD( _field_real_argb_color, "shadow color" ),
	FIELD( _field_explanation, "Color presets" ),
	FIELD( _field_block, "color presets", &color_presets_block ),
	FIELD( _field_explanation, "Tint colors" ),
	FIELD( _field_block, "tint colors", &tint_colors_block ),
	FIELD( _field_explanation, "Emblem counts" ),
	FIELD( _field_short_integer, "Primary emblem count" ),
	FIELD( _field_short_integer, "Secondary emblem count" ),
	FIELD( _field_explanation, "User interface sounds" ),
	FIELD( _field_tag_reference, "default sounds" ),
	FIELD( _field_explanation, "HaloX Alerts" ),
	FIELD( _field_block, "alert descriptions", &gui_alert_description_block ),
	FIELD( _field_explanation, "HaloX Dialogs" ),
	FIELD( _field_block, "dialog descriptions", &gui_dialog_description_block ),
	FIELD( _field_explanation, "Content Aspect Ratio Scaling" ),
	FIELD( _field_real_vector_2d, "16x9" ),
	FIELD( _field_real_vector_2d, "4x3" ),
	FIELD( _field_explanation, "Blur Constants" ),
	FIELD( _field_real, "horizontal blur factor" ),
	FIELD( _field_real, "vertical blur factor" ),
	FIELD( _field_explanation, "Appearance Model Names" ),
	FIELD( _field_string_id, "mc biped name" ),
	FIELD( _field_string, "mc ai squad name" ),
	FIELD( _field_string_id, "mc ai start pos" ),
	FIELD( _field_string_id, "elite biped name" ),
	FIELD( _field_string, "elite ai squad name" ),
	FIELD( _field_string_id, "elite ai start pos" ),
	FIELD( _field_explanation, "Player Portrait Model Names" ),
	FIELD( _field_string_id, "spartan portrait biped name" ),
	FIELD( _field_string_id, "elite portrait biped name" ),
	FIELD( _field_explanation, "UI Navigation speed" ),
	FIELD( _field_long_integer, "navigation tab delay msec" ),
	FIELD( _field_long_integer, "navigation tab fast wait msec" ),
	FIELD( _field_long_integer, "navigation tab fast delay msec" ),
	FIELD( _field_explanation, "Spinner tab speed" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "spinner tab speed function", &mapping_function_struct_definition ),
	FIELD( _field_long_integer, "max input time (x) on the graph (msec)" ),
	FIELD( _field_explanation, "Attract Mode Settings" ),
	FIELD( _field_long_integer, "delay:seconds" ),
	FIELD( _field_block, "PGCR per player tracked incidents", &pgcr_incident_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

