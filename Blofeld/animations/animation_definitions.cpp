#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(animation_graph_sound_reference, k_max_sound_references_per_graph)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_word_flags, "internal_flags!" ),
	FIELD( _field_tag_reference, "model#optional. only allow this event when used on this model" ),
	FIELD( _field_string_id, "variant#optional. only allow this event when used on this model variant" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_graph_effect_reference, k_max_effect_references_per_graph)
{
	FIELD( _field_tag_reference, "effect^" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_word_flags, "internal_flags!" ),
	FIELD( _field_tag_reference, "model#optional. only allow this event when used on this model" ),
	FIELD( _field_string_id, "variant#optional. only allow this event when used on this model variant" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(import_animation_event, 2*k_max_animations_per_graph)
{
	FIELD( _field_string_id, "animation name^*!" ),
	FIELD( _field_long_integer, "animation frame count^*!" ),
	FIELD( _field_block, "animation events", &import_frame_event_block ),
	FIELD( _field_block, "sound events", &animation_sound_event_block ),
	FIELD( _field_block, "effect events", &animation_effects_event_block ),
	FIELD( _field_block, "dialogue events", &animation_dialogue_event_block ),
	FIELD( _field_block, "script events", &animation_script_event_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(import_frame_event, k_max_frame_events)
{
	FIELD( _field_string_id, "event name*" ),
	FIELD( _field_string_id, "animation name!*" ),
	FIELD( _field_short_integer, "frame" ),
	FIELD( _field_short_integer, "frame offset" ),
	FIELD( _field_enum, "type*" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_long_integer, "unique ID*!#(Do not change this)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_sound_event, k_max_frame_events)
{
	FIELD( _field_short_block_index, "frame event" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_short_block_index, "sound" ),
	FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_effects_event, k_max_frame_events)
{
	FIELD( _field_short_block_index, "frame event" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_short_block_index, "effect" ),
	FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "marker name" ),
	FIELD( _field_char_enum, "damage effect reporting type" ),
	FIELD( _field_pad, "pad_2", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_dialogue_event, k_max_frame_events)
{
	FIELD( _field_short_block_index, "frame event" ),
	FIELD( _field_enum, "dialogue event" ),
	FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(animation_script_event, k_max_frame_events)
{
	FIELD( _field_short_block_index, "frame event" ),
	FIELD( _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." ),
	FIELD( _field_string_id, "script name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(additional_node_data, k_max_nodes_per_animation)
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

TAG_GROUP(frame_event_list, FRAME_EVENT_LIST_TAG)
{
	FIELD( _field_explanation, "IMPORTANT TAG NOTES" ),
	FIELD( _field_block, "sound references|ABCDCC", &animation_graph_sound_reference_block ),
	FIELD( _field_block, "effect references|ABCDCC", &animation_graph_effect_reference_block ),
	FIELD( _field_block, "frame events|ABCDCC", &import_animation_event_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(model_animation_graph, MODEL_ANIMATION_GRAPH_TAG)
{
	FIELD( _field_struct, "definitions" ),
	FIELD( _field_struct, "content" ),
	FIELD( _field_struct, "run time data" ),
	FIELD( _field_block, "additional node data", &additional_node_data_block ),
	FIELD( _field_block, "tag resource groups", &model_animation_tag_resource_group_block ),
	FIELD( _field_struct, "codec data*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

