#pragma once

namespace blofeld
{

extern s_tag_block default_stimulus_suppressor_block;
extern s_tag_block vocalization_definitions_block;
extern s_tag_block response_block;
extern s_tag_block vocalization_patterns_block;
extern s_tag_block dialogue_data_block;
extern s_tag_block involuntary_data_block;
extern s_tag_block predicted_data_block;

constexpr unsigned long AI_DIALOGUE_GLOBALS_TAG = 'adlg';

extern s_tag_block ai_dialogue_globals_block;
extern s_tag_group ai_dialogue_globals_group;
} // namespace blofeld

