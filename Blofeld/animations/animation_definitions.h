#pragma once

namespace blofeld
{

extern s_tag_block animation_graph_sound_reference_block;
extern s_tag_block animation_graph_effect_reference_block;
extern s_tag_block import_animation_event_block;
extern s_tag_block import_frame_event_block;
extern s_tag_block animation_sound_event_block;
extern s_tag_block animation_effects_event_block;
extern s_tag_block animation_dialogue_event_block;
extern s_tag_block animation_script_event_block;
extern s_tag_block additional_node_data_block;
extern s_tag_block model_animation_tag_resource_group_block;

constexpr unsigned long FRAME_EVENT_LIST_TAG = 'frms';

extern s_tag_block frame_event_list_block;
extern s_tag_group frame_event_list_group;
constexpr unsigned long MODEL_ANIMATION_GRAPH_TAG = 'jmad';

extern s_tag_block model_animation_graph_block;
extern s_tag_group model_animation_graph_group;
} // namespace blofeld

