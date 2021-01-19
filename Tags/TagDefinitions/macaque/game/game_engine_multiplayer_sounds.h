#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long SOUND_RESPONSE_TAG = 'sgrp';
	extern s_tag_group sound_response_group; // sound_response_block

	constexpr unsigned long SOUND_INCIDENT_RESPONSE_TAG = 'sirg';
	extern s_tag_group sound_incident_response_group; // sound_incident_response_block


	extern s_tag_block_definition sound_response_block;
	extern s_tag_block_definition sound_incident_response_block;
	extern s_tag_block_definition sound_response_data_block;
	extern s_tag_struct_definition sound_response_data_block_struct_definition; // sound_response_data_block
	extern s_tag_block_definition sound_response_permutation_block;
	extern s_tag_struct_definition sound_response_permutation_block_struct_definition; // sound_response_permutation_block
	extern s_tag_block_definition sound_combine_response_block;
	extern s_tag_struct_definition sound_combine_response_block_struct_definition; // sound_combine_response_block
	extern s_tag_block_definition sound_incident_response_data_block;
	extern s_tag_struct_definition sound_incident_response_data_block_struct_definition; // sound_incident_response_data_block

	extern s_tag_struct_definition sound_response_struct_definition; // tag group
	extern s_tag_struct_definition sound_incident_response_struct_definition; // tag group

	extern c_versioned_string_list sound_combine_response_flags_strings;
	extern s_string_list_definition sound_combine_response_flags;
	extern c_versioned_string_list sound_response_queue_flags_strings;
	extern s_string_list_definition sound_response_queue_flags;
	extern c_versioned_string_list sound_audience_flags_strings;
	extern s_string_list_definition sound_audience_flags;
	extern c_versioned_string_list sound_splitscreen_flags_strings;
	extern s_string_list_definition sound_splitscreen_flags;

	extern s_tag_reference_definition sound_response_group_reference;
	extern s_tag_reference_definition sound_incident_response_group_reference;

} // namespace macaque

} // namespace blofeld

