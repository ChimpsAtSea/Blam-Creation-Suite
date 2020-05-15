#pragma once

namespace blofeld
{

extern s_tag_block sound_response_data_block;
extern s_tag_block sound_response_permutation_block;
extern s_tag_block sound_combine_response_block;
extern s_tag_block sound_incident_response_data_block;

constexpr unsigned long SOUND_RESPONSE_TAG = 'sgrp';

extern s_tag_block sound_response_block;
extern s_tag_group sound_response_group;
constexpr unsigned long SOUND_INCIDENT_RESPONSE_TAG = 'sirg';

extern s_tag_block sound_incident_response_block;
extern s_tag_group sound_incident_response_group;
} // namespace blofeld

