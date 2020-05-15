#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(animation_graph_sound_reference, k_max_sound_references_per_graph)
{
	{ _field_tag_reference, "sound^" },
	{ _field_word_flags, "flags" },
	{ _field_word_flags, "internal_flags!" },
	{ _field_tag_reference, "model#optional. only allow this event when used on this model" },
	{ _field_string_id, "variant#optional. only allow this event when used on this model variant" },
	{ _field_terminator },
};

TAG_BLOCK(animation_graph_effect_reference, k_max_effect_references_per_graph)
{
	{ _field_tag_reference, "effect^" },
	{ _field_word_flags, "flags" },
	{ _field_word_flags, "internal_flags!" },
	{ _field_tag_reference, "model#optional. only allow this event when used on this model" },
	{ _field_string_id, "variant#optional. only allow this event when used on this model variant" },
	{ _field_terminator },
};

TAG_BLOCK(import_animation_event, 2*k_max_animations_per_graph)
{
	{ _field_string_id, "animation name^*!" },
	{ _field_long_integer, "animation frame count^*!" },
	{ _field_block, "animation events", &import_frame_event_block },
	{ _field_block, "sound events", &animation_sound_event_block },
	{ _field_block, "effect events", &animation_effects_event_block },
	{ _field_block, "dialogue events", &animation_dialogue_event_block },
	{ _field_block, "script events", &animation_script_event_block },
	{ _field_terminator },
};

TAG_BLOCK(import_frame_event, k_max_frame_events)
{
	{ _field_string_id, "event name*" },
	{ _field_string_id, "animation name!*" },
	{ _field_short_integer, "frame" },
	{ _field_short_integer, "frame offset" },
	{ _field_enum, "type*" },
	{ _field_pad, "pad", 2 },
	{ _field_long_integer, "unique ID*!#(Do not change this)" },
	{ _field_terminator },
};

TAG_BLOCK(animation_sound_event, k_max_frame_events)
{
	{ _field_short_block_index, "frame event" },
	{ _field_pad, "pad", 2 },
	{ _field_short_block_index, "sound" },
	{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
	{ _field_custom },
	{ _field_string_id, "marker name" },
	{ _field_terminator },
};

TAG_BLOCK(animation_effects_event, k_max_frame_events)
{
	{ _field_short_block_index, "frame event" },
	{ _field_pad, "pad", 2 },
	{ _field_short_block_index, "effect" },
	{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
	{ _field_custom },
	{ _field_string_id, "marker name" },
	{ _field_char_enum, "damage effect reporting type" },
	{ _field_pad, "pad_2", 3 },
	{ _field_terminator },
};

TAG_BLOCK(animation_dialogue_event, k_max_frame_events)
{
	{ _field_short_block_index, "frame event" },
	{ _field_enum, "dialogue event" },
	{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
	{ _field_pad, "pad", 2 },
	{ _field_terminator },
};

TAG_BLOCK(animation_script_event, k_max_frame_events)
{
	{ _field_short_block_index, "frame event" },
	{ _field_short_integer, "frame offset#If a frame event is set, this number is relative to frame event, otherwise it\'s absolute." },
	{ _field_string_id, "script name" },
	{ _field_terminator },
};

TAG_BLOCK(additional_node_data, k_max_nodes_per_animation)
{
	{ _field_string_id, "node name^" },
	{ _field_real_quaternion, "default rotation*" },
	{ _field_real_point_3d, "default translation*" },
	{ _field_real, "default scale*" },
	{ _field_real_point_3d, "min bounds" },
	{ _field_real_point_3d, "max bounds" },
	{ _field_terminator },
};

TAG_BLOCK(model_animation_tag_resource_group, k_max_animations_per_graph*3)
{
	{ _field_long_integer, "reference_count*" },
	{ _field_pageable, "tag_resource" },
	{ _field_terminator },
};

TAG_GROUP(frame_event_list, FRAME_EVENT_LIST_TAG)
{
	{ _field_explanation, "IMPORTANT TAG NOTES" },
	{ _field_block, "sound references|ABCDCC", &animation_graph_sound_reference_block },
	{ _field_block, "effect references|ABCDCC", &animation_graph_effect_reference_block },
	{ _field_block, "frame events|ABCDCC", &import_animation_event_block },
	{ _field_terminator },
};

TAG_GROUP(model_animation_graph, MODEL_ANIMATION_GRAPH_TAG)
{
	{ _field_struct, "definitions" },
	{ _field_struct, "content" },
	{ _field_struct, "run time data" },
	{ _field_block, "additional node data", &additional_node_data_block },
	{ _field_block, "tag resource groups", &model_animation_tag_resource_group_block },
	{ _field_struct, "codec data*!" },
	{ _field_terminator },
};

} // namespace blofeld

