#pragma once

namespace blofeld
{



	constexpr unsigned long INSTANCE_IMPOSTER_DEFINITION_TAG = 'iimz';
	extern s_tag_group instance_imposter_definition_group; // instance_imposter_definition_block


	extern s_tag_block_definition instance_imposter_definition_block;
	extern s_tag_block_definition instance_imposter_block;
	extern s_tag_struct_definition instance_imposter_block_struct_definition; // instance_imposter_block
	extern s_tag_block_definition instance_imposter_checksum_block;
	extern s_tag_struct_definition instance_imposter_checksum_block_struct_definition; // instance_imposter_checksum_block

	extern s_tag_struct_definition instance_imposter_definition_struct_definition; // tag group

	extern c_versioned_string_list instance_imposter_flags_definition_strings;
	extern s_string_list_definition instance_imposter_flags_definition;
	extern c_versioned_string_list instance_imposter_element_flags_definition_strings;
	extern s_string_list_definition instance_imposter_element_flags_definition;

	extern s_tag_reference_definition global_instance_imposter_reference;



} // namespace blofeld

