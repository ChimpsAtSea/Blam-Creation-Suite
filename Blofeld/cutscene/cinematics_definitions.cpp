#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(cinematic_scene_reference, MAX_CINEMATIC_SCENE_COUNT)
{
	FIELD( _field_tag_reference, "scene" ),
	FIELD( _field_tag_reference, "data" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_scene_object, 10000)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_string_id, "variant name" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_custom, "lightmap shadow flags" ),
	FIELD( _field_array, "lightmap shadow flags" ),
	FIELD( _field_custom, "high res flags" ),
	FIELD( _field_array, "high res flags" ),
	FIELD( _field_long_flags, "override creation flags" ),
	FIELD( _field_explanation, "Custom override creation condition" ),
	FIELD( _field_struct, "custom don\'t create condition" ),
	FIELD( _field_block, "attachments", &scene_object_attachment_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scene_object_attachment, 10000)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "VKJSLKHF", 3 ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "object marker name" ),
	FIELD( _field_string_id, "attachment object name^" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "attachment marker name" ),
	FIELD( _field_tag_reference, "attachment type" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot, MAX_CINEMATIC_SHOT_COUNT)
{
	FIELD( _field_custom, "loop now" ),
	FIELD( _field_custom, "Header" ),
	FIELD( _field_struct, "header" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_custom, "environment darken:0 - 1#this works best with auto-exposure off" ),
	FIELD( _field_real, "environment darken:0 - 1#this works best with auto-exposure off" ),
	FIELD( _field_custom, "forced exposure:stops#will disable auto-exposure" ),
	FIELD( _field_real, "forced exposure:stops#will disable auto-exposure" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Settings" ),
	FIELD( _field_long_flags, "settings flags" ),
	FIELD( _field_real, "Lightmap Direct Scalar" ),
	FIELD( _field_real, "Lightmap Indirect Scalar" ),
	FIELD( _field_real, "Sun Scalar" ),
	FIELD( _field_tag_reference, "Atmosphere Fog" ),
	FIELD( _field_tag_reference, "Camera Effects" ),
	FIELD( _field_tag_reference, "Cubemap" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "lighting", &cinematic_shot_lighting_block ),
	FIELD( _field_block, "clip", &cinematic_shot_clip_block ),
	FIELD( _field_block, "music", &cinematic_shot_music_block ),
	FIELD( _field_block, "object functions", &cinematic_shot_object_function_block ),
	FIELD( _field_block, "screen effects", &cinematic_shot_screen_effect_block ),
	FIELD( _field_block, "user input constraints", &cinematic_shot_user_input_constraints_block ),
	FIELD( _field_block, "texture movies", &cinematicShotTextureMovieBlock_block ),
	FIELD( _field_custom, "Footer" ),
	FIELD( _field_struct, "footer" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_lighting, 10000)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_tag_reference, "lighting" ),
	FIELD( _field_long_block_index, "subject^" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_clip, k_maximum_scene_shot_clip_plane_count)
{
	FIELD( _field_real_point_3d, "plane center" ),
	FIELD( _field_real_point_3d, "plane direction" ),
	FIELD( _field_custom, "frame start" ),
	FIELD( _field_long_integer, "frame start" ),
	FIELD( _field_custom, "frame end" ),
	FIELD( _field_long_integer, "frame end" ),
	FIELD( _field_block, "subject objects", &cinematic_shot_clip_subject_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_clip_subject, k_maximum_scene_shot_clip_subject_count)
{
	FIELD( _field_long_block_index, "index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_music, 10000)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_tag_reference, "music/foley" ),
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_object_function, 10000)
{
	FIELD( _field_long_block_index, "object" ),
	FIELD( _field_string_id, "function name" ),
	FIELD( _field_block, "keyframes", &cinematic_shot_object_function_keyframe_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_object_function_keyframe, 10000)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_real, "value" ),
	FIELD( _field_real, "interpolation time:ticks" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_screen_effect, 10000)
{
	FIELD( _field_tag_reference, "screen effect" ),
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_custom, "stop frame" ),
	FIELD( _field_long_integer, "stop frame" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "BLAHWWW", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_user_input_constraints, 10000)
{
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_long_integer, "ticks" ),
	FIELD( _field_rectangle_2d, "maximum look angles" ),
	FIELD( _field_real, "frictional force" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematicShotTextureMovieBlock, 10000)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_tag_reference, "bink movie" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematicStructureLightingBlock, 32)
{
	FIELD( _field_tag_reference, "structure lighting info^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematicSceneDataObjectBlock, 10000)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_string_id, "identifier*" ),
	FIELD( _field_tag_reference, "model animation graph*" ),
	FIELD( _field_tag_reference, "object type*" ),
	FIELD( _field_custom, "shots active flags*" ),
	FIELD( _field_array, "shots active flags*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematicDataShotBlock, MAX_CINEMATIC_SHOT_COUNT)
{
	FIELD( _field_block, "dialogue", &cinematic_shot_dialogue_block ),
	FIELD( _field_block, "effects", &cinematic_shot_effect_block ),
	FIELD( _field_block, "custom script", &cinematic_shot_custom_script_block ),
	FIELD( _field_long_integer, "frame count*" ),
	FIELD( _field_block, "frame data*", &cinematic_shot_frame_block ),
	FIELD( _field_block, "dynamic frame data*!", &cinematic_shot_frame_dynamic_block ),
	FIELD( _field_block, "constant frame data*!", &cinematic_shot_frame_constant_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_dialogue, 10000)
{
	FIELD( _field_tag_reference, "dialogue*" ),
	FIELD( _field_tag_reference, "female dialogue*" ),
	FIELD( _field_custom, "frame*" ),
	FIELD( _field_long_integer, "frame*" ),
	FIELD( _field_real, "scale*" ),
	FIELD( _field_string_id, "lipsync actor*" ),
	FIELD( _field_string_id, "default sound effect" ),
	FIELD( _field_string_id, "subtitle" ),
	FIELD( _field_string_id, "female subtitle" ),
	FIELD( _field_string_id, "character" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_effect, 10000)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_char_enum, "state" ),
	FIELD( _field_pad, "CMVOIRLKSD", 2 ),
	FIELD( _field_tag_reference, "effect" ),
	FIELD( _field_real, "size scale" ),
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name" ),
	FIELD( _field_long_block_index, "marker parent" ),
	FIELD( _field_string_id, "function a" ),
	FIELD( _field_string_id, "function b" ),
	FIELD( _field_long_integer, "node id!" ),
	FIELD( _field_long_integer, "sequence id!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_custom_script, 10000)
{
	FIELD( _field_byte_flags, "flags!" ),
	FIELD( _field_pad, "CMVOIRLKSD", 3 ),
	FIELD( _field_custom, "frame" ),
	FIELD( _field_long_integer, "frame" ),
	FIELD( _field_struct, "script" ),
	FIELD( _field_long_integer, "node id!" ),
	FIELD( _field_long_integer, "sequence id!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_frame, 10000)
{
	FIELD( _field_struct, "camera frame" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_frame_dynamic, 10000)
{
	FIELD( _field_struct, "dynamic camera frame" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_frame_constant, 10000)
{
	FIELD( _field_long_integer, "frame index" ),
	FIELD( _field_struct, "constant camera frame" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_shot_extra_camera, 10000)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_string_id, "type" ),
	FIELD( _field_block, "shots", &cinematic_extra_camera_shot_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_extra_camera_shot, 10000)
{
	FIELD( _field_block, "frame data", &cinematic_extra_camera_frame_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_extra_camera_frame, 10000)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_struct, "frame data" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematics_globals, 1)
{
	FIELD( _field_tag_reference, "cinematic anchor reference" ),
	FIELD( _field_real, "cinematic film aperture" ),
	FIELD( _field_real, "cinematic skip ui up time" ),
	FIELD( _field_real_fraction_bounds, "subtitle rect width#percentage towards the center - 0=default, 0.5=center of the screen" ),
	FIELD( _field_real_fraction_bounds, "subtitle rect height#0=default, 0.5=center of the screen" ),
	FIELD( _field_real_rgb_color, "default subtitle color" ),
	FIELD( _field_real_rgb_color, "default subtitle shadow color" ),
	FIELD( _field_block, "cinematic characters", &cinematic_characters_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cinematic_characters, 16)
{
	FIELD( _field_string_id, "character name^" ),
	FIELD( _field_real_rgb_color, "subtitle color" ),
	FIELD( _field_real_rgb_color, "shadow color" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_cutscene_title, k_maximum_scenario_cutscene_titles)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_real_fraction_bounds, "text bounds X" ),
	FIELD( _field_real_fraction_bounds, "text bounds Y" ),
	FIELD( _field_enum, "justification" ),
	FIELD( _field_enum, "vertical justification" ),
	FIELD( _field_enum, "font" ),
	FIELD( _field_pad, "padding", 2 ),
	FIELD( _field_rgb_color, "text color" ),
	FIELD( _field_rgb_color, "shadow color" ),
	FIELD( _field_real, "fade in time [seconds]" ),
	FIELD( _field_real, "up time [seconds]" ),
	FIELD( _field_real, "fade out time [seconds]" ),
	FIELD( _field_real, "letter print time:seconds" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_cinematics, MAXIMUM_SCENARIO_CINEMATICS)
{
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "SDJLKANF", 3 ),
	FIELD( _field_tag_reference, "name^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(cinematic, CINEMATIC_TAG)
{
	FIELD( _field_custom, "custom playback" ),
	FIELD( _field_struct, "cinematic playback!" ),
	FIELD( _field_struct, "scenario and zone set" ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_enum, "channel type" ),
	FIELD( _field_pad, "PADDING", 2 ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "easing in time#seconds" ),
	FIELD( _field_real, "easing out time#seconds" ),
	FIELD( _field_tag_reference, "transition settings" ),
	FIELD( _field_tag_reference, "bink movie" ),
	FIELD( _field_string, "bink movie on disc" ),
	FIELD( _field_custom, "Header" ),
	FIELD( _field_struct, "header" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "scenes", &cinematic_scene_reference_block ),
	FIELD( _field_custom, "Footer" ),
	FIELD( _field_struct, "footer" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "If The Player Skips" ),
	FIELD( _field_struct, "early exit" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP(cinematic_scene, CINEMATIC_SCENE_TAG)
{
	FIELD( _field_custom, "loop now" ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "anchor" ),
	FIELD( _field_enum, "reset object lighting" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_tag_reference, "data*" ),
	FIELD( _field_custom, "Header" ),
	FIELD( _field_struct, "header" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "objects*", &cinematic_scene_object_block ),
	FIELD( _field_block, "shots", &cinematic_shot_block ),
	FIELD( _field_block, "lights", &cinematicStructureLightingBlock_block ),
	FIELD( _field_custom, "Footer" ),
	FIELD( _field_struct, "footer" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP(cinematic_scene_data, CINEMATIC_SCENE_DATA_TAG)
{
	FIELD( _field_block, "objects*", &cinematicSceneDataObjectBlock_block ),
	FIELD( _field_block, "shots*", &cinematicDataShotBlock_block ),
	FIELD( _field_block, "extra camera frame data*", &cinematic_shot_extra_camera_block ),
	FIELD( _field_long_integer, "version*" ),
	FIELD( _field_terminator )
};

TAG_GROUP(cinematic_transition, CINEMATIC_TRANSITION_TAG)
{
	FIELD( _field_custom, "fade out from game" ),
	FIELD( _field_struct, "fade out from game struct" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "fade in to cinematic" ),
	FIELD( _field_struct, "fade in to cinematic struct" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "fade out from cinematic" ),
	FIELD( _field_struct, "fade out from cinematic struct" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "fade post core load" ),
	FIELD( _field_struct, "fade post core load struct" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "fade in to game" ),
	FIELD( _field_struct, "fade in to game struct" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

