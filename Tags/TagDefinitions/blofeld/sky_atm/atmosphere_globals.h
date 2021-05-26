#pragma once

namespace blofeld
{



	constexpr unsigned long ATMOSPHERE_GLOBALS_TAG = 'atgf';
	extern s_tag_group atmosphere_globals_group; // atmosphere_globals_block


	extern s_tag_block_definition atmosphere_globals_block;
	extern s_tag_block_definition underwater_setting_block;
	extern s_tag_struct_definition underwater_setting_block_struct_definition; // underwater_setting_block

	extern s_tag_struct_definition atmosphere_globals_struct_definition; // tag group

	extern s_tag_reference_definition global_atmosphere_globals_reference;



} // namespace blofeld

