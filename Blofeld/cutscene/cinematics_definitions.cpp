#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(cinematic_scene_reference, MAX_CINEMATIC_SCENE_COUNT)
{
	{ _field_tag_reference, "scene" },
	{ _field_tag_reference, "data" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_scene_object, 10000)
{
	{ _field_string_id, "name*^" },
	{ _field_string_id, "variant name" },
	{ _field_long_flags, "flags" },
	{ _field_custom, "lightmap shadow flags" },
	{ _field_array, "lightmap shadow flags" },
	{ _field_custom, "high res flags" },
	{ _field_array, "high res flags" },
	{ _field_long_flags, "override creation flags" },
	{ _field_explanation, "Custom override creation condition" },
	{ _field_struct, "custom don\'t create condition" },
	{ _field_block, "attachments", &scene_object_attachment_block },
	{ _field_terminator },
};

TAG_BLOCK(scene_object_attachment, 10000)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "VKJSLKHF", 3 },
	{ _field_custom },
	{ _field_string_id, "object marker name" },
	{ _field_string_id, "attachment object name^" },
	{ _field_custom },
	{ _field_string_id, "attachment marker name" },
	{ _field_tag_reference, "attachment type" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot, MAX_CINEMATIC_SHOT_COUNT)
{
	{ _field_custom, "loop now" },
	{ _field_custom, "Header" },
	{ _field_struct, "header" },
	{ _field_long_flags, "flags" },
	{ _field_custom, "environment darken:0 - 1#this works best with auto-exposure off" },
	{ _field_real, "environment darken:0 - 1#this works best with auto-exposure off" },
	{ _field_custom, "forced exposure:stops#will disable auto-exposure" },
	{ _field_real, "forced exposure:stops#will disable auto-exposure" },
	{ _field_custom },
	{ _field_custom, "Settings" },
	{ _field_long_flags, "settings flags" },
	{ _field_real, "Lightmap Direct Scalar" },
	{ _field_real, "Lightmap Indirect Scalar" },
	{ _field_real, "Sun Scalar" },
	{ _field_tag_reference, "Atmosphere Fog" },
	{ _field_tag_reference, "Camera Effects" },
	{ _field_tag_reference, "Cubemap" },
	{ _field_custom },
	{ _field_block, "lighting", &cinematic_shot_lighting_block },
	{ _field_block, "clip", &cinematic_shot_clip_block },
	{ _field_block, "music", &cinematic_shot_music_block },
	{ _field_block, "object functions", &cinematic_shot_object_function_block },
	{ _field_block, "screen effects", &cinematic_shot_screen_effect_block },
	{ _field_block, "user input constraints", &cinematic_shot_user_input_constraints_block },
	{ _field_block, "texture movies", &cinematicShotTextureMovieBlock_block },
	{ _field_custom, "Footer" },
	{ _field_struct, "footer" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_lighting, 10000)
{
	{ _field_long_flags, "flags" },
	{ _field_tag_reference, "lighting" },
	{ _field_long_block_index, "subject^" },
	{ _field_custom },
	{ _field_string_id, "marker" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_clip, k_maximum_scene_shot_clip_plane_count)
{
	{ _field_real_point_3d, "plane center" },
	{ _field_real_point_3d, "plane direction" },
	{ _field_custom, "frame start" },
	{ _field_long_integer, "frame start" },
	{ _field_custom, "frame end" },
	{ _field_long_integer, "frame end" },
	{ _field_block, "subject objects", &cinematic_shot_clip_subject_block },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_clip_subject, k_maximum_scene_shot_clip_subject_count)
{
	{ _field_long_block_index, "index" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_music, 10000)
{
	{ _field_long_flags, "flags" },
	{ _field_tag_reference, "music/foley" },
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_object_function, 10000)
{
	{ _field_long_block_index, "object" },
	{ _field_string_id, "function name" },
	{ _field_block, "keyframes", &cinematic_shot_object_function_keyframe_block },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_object_function_keyframe, 10000)
{
	{ _field_long_flags, "flags" },
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_real, "value" },
	{ _field_real, "interpolation time:ticks" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_screen_effect, 10000)
{
	{ _field_tag_reference, "screen effect" },
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_custom, "stop frame" },
	{ _field_long_integer, "stop frame" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "BLAHWWW", 3 },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_user_input_constraints, 10000)
{
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_long_integer, "ticks" },
	{ _field_rectangle_2d, "maximum look angles" },
	{ _field_real, "frictional force" },
	{ _field_terminator },
};

TAG_BLOCK(cinematicShotTextureMovieBlock, 10000)
{
	{ _field_long_flags, "flags" },
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_tag_reference, "bink movie" },
	{ _field_terminator },
};

TAG_BLOCK(cinematicStructureLightingBlock, 32)
{
	{ _field_tag_reference, "structure lighting info^" },
	{ _field_terminator },
};

TAG_BLOCK(cinematicSceneDataObjectBlock, 10000)
{
	{ _field_string_id, "name*^" },
	{ _field_string_id, "identifier*" },
	{ _field_tag_reference, "model animation graph*" },
	{ _field_tag_reference, "object type*" },
	{ _field_custom, "shots active flags*" },
	{ _field_array, "shots active flags*" },
	{ _field_terminator },
};

TAG_BLOCK(cinematicDataShotBlock, MAX_CINEMATIC_SHOT_COUNT)
{
	{ _field_block, "dialogue", &cinematic_shot_dialogue_block },
	{ _field_block, "effects", &cinematic_shot_effect_block },
	{ _field_block, "custom script", &cinematic_shot_custom_script_block },
	{ _field_long_integer, "frame count*" },
	{ _field_block, "frame data*", &cinematic_shot_frame_block },
	{ _field_block, "dynamic frame data*!", &cinematic_shot_frame_dynamic_block },
	{ _field_block, "constant frame data*!", &cinematic_shot_frame_constant_block },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_dialogue, 10000)
{
	{ _field_tag_reference, "dialogue*" },
	{ _field_tag_reference, "female dialogue*" },
	{ _field_custom, "frame*" },
	{ _field_long_integer, "frame*" },
	{ _field_real, "scale*" },
	{ _field_string_id, "lipsync actor*" },
	{ _field_string_id, "default sound effect" },
	{ _field_string_id, "subtitle" },
	{ _field_string_id, "female subtitle" },
	{ _field_string_id, "character" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_effect, 10000)
{
	{ _field_byte_flags, "flags" },
	{ _field_char_enum, "state" },
	{ _field_pad, "CMVOIRLKSD", 2 },
	{ _field_tag_reference, "effect" },
	{ _field_real, "size scale" },
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_custom },
	{ _field_string_id, "marker name" },
	{ _field_long_block_index, "marker parent" },
	{ _field_string_id, "function a" },
	{ _field_string_id, "function b" },
	{ _field_long_integer, "node id!" },
	{ _field_long_integer, "sequence id!" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_custom_script, 10000)
{
	{ _field_byte_flags, "flags!" },
	{ _field_pad, "CMVOIRLKSD", 3 },
	{ _field_custom, "frame" },
	{ _field_long_integer, "frame" },
	{ _field_struct, "script" },
	{ _field_long_integer, "node id!" },
	{ _field_long_integer, "sequence id!" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_frame, 10000)
{
	{ _field_struct, "camera frame" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_frame_dynamic, 10000)
{
	{ _field_struct, "dynamic camera frame" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_frame_constant, 10000)
{
	{ _field_long_integer, "frame index" },
	{ _field_struct, "constant camera frame" },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_shot_extra_camera, 10000)
{
	{ _field_string_id, "name" },
	{ _field_string_id, "type" },
	{ _field_block, "shots", &cinematic_extra_camera_shot_block },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_extra_camera_shot, 10000)
{
	{ _field_block, "frame data", &cinematic_extra_camera_frame_block },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_extra_camera_frame, 10000)
{
	{ _field_long_flags, "flags" },
	{ _field_struct, "frame data" },
	{ _field_terminator },
};

TAG_BLOCK(cinematics_globals, 1)
{
	{ _field_tag_reference, "cinematic anchor reference" },
	{ _field_real, "cinematic film aperture" },
	{ _field_real, "cinematic skip ui up time" },
	{ _field_real_fraction_bounds, "subtitle rect width#percentage towards the center - 0=default, 0.5=center of the screen" },
	{ _field_real_fraction_bounds, "subtitle rect height#0=default, 0.5=center of the screen" },
	{ _field_real_rgb_color, "default subtitle color" },
	{ _field_real_rgb_color, "default subtitle shadow color" },
	{ _field_block, "cinematic characters", &cinematic_characters_block },
	{ _field_terminator },
};

TAG_BLOCK(cinematic_characters, 16)
{
	{ _field_string_id, "character name^" },
	{ _field_real_rgb_color, "subtitle color" },
	{ _field_real_rgb_color, "shadow color" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cutscene_title, k_maximum_scenario_cutscene_titles)
{
	{ _field_string_id, "name^" },
	{ _field_real_fraction_bounds, "text bounds X" },
	{ _field_real_fraction_bounds, "text bounds Y" },
	{ _field_enum, "justification" },
	{ _field_enum, "vertical justification" },
	{ _field_enum, "font" },
	{ _field_pad, "padding", 2 },
	{ _field_rgb_color, "text color" },
	{ _field_rgb_color, "shadow color" },
	{ _field_real, "fade in time [seconds]" },
	{ _field_real, "up time [seconds]" },
	{ _field_real, "fade out time [seconds]" },
	{ _field_real, "letter print time:seconds" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_cinematics, MAXIMUM_SCENARIO_CINEMATICS)
{
	{ _field_byte_flags, "flags" },
	{ _field_pad, "SDJLKANF", 3 },
	{ _field_tag_reference, "name^" },
	{ _field_terminator },
};

TAG_GROUP(cinematic, CINEMATIC_TAG)
{
	{ _field_custom, "custom playback" },
	{ _field_struct, "cinematic playback!" },
	{ _field_struct, "scenario and zone set" },
	{ _field_string_id, "name^" },
	{ _field_enum, "channel type" },
	{ _field_pad, "PADDING", 2 },
	{ _field_long_flags, "flags" },
	{ _field_real, "easing in time#seconds" },
	{ _field_real, "easing out time#seconds" },
	{ _field_tag_reference, "transition settings" },
	{ _field_tag_reference, "bink movie" },
	{ _field_string, "bink movie on disc" },
	{ _field_custom, "Header" },
	{ _field_struct, "header" },
	{ _field_custom },
	{ _field_block, "scenes", &cinematic_scene_reference_block },
	{ _field_custom, "Footer" },
	{ _field_struct, "footer" },
	{ _field_custom },
	{ _field_custom, "If The Player Skips" },
	{ _field_struct, "early exit" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(cinematic_scene, CINEMATIC_SCENE_TAG)
{
	{ _field_custom, "loop now" },
	{ _field_string_id, "name^" },
	{ _field_string_id, "anchor" },
	{ _field_enum, "reset object lighting" },
	{ _field_pad, "pad", 2 },
	{ _field_tag_reference, "data*" },
	{ _field_custom, "Header" },
	{ _field_struct, "header" },
	{ _field_custom },
	{ _field_block, "objects*", &cinematic_scene_object_block },
	{ _field_block, "shots", &cinematic_shot_block },
	{ _field_block, "lights", &cinematicStructureLightingBlock_block },
	{ _field_custom, "Footer" },
	{ _field_struct, "footer" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(cinematic_scene_data, CINEMATIC_SCENE_DATA_TAG)
{
	{ _field_block, "objects*", &cinematicSceneDataObjectBlock_block },
	{ _field_block, "shots*", &cinematicDataShotBlock_block },
	{ _field_block, "extra camera frame data*", &cinematic_shot_extra_camera_block },
	{ _field_long_integer, "version*" },
	{ _field_terminator },
};

TAG_GROUP(cinematic_transition, CINEMATIC_TRANSITION_TAG)
{
	{ _field_custom, "fade out from game" },
	{ _field_struct, "fade out from game struct" },
	{ _field_custom },
	{ _field_custom, "fade in to cinematic" },
	{ _field_struct, "fade in to cinematic struct" },
	{ _field_custom },
	{ _field_custom, "fade out from cinematic" },
	{ _field_struct, "fade out from cinematic struct" },
	{ _field_custom },
	{ _field_custom, "fade post core load" },
	{ _field_struct, "fade post core load struct" },
	{ _field_custom },
	{ _field_custom, "fade in to game" },
	{ _field_struct, "fade in to game struct" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

