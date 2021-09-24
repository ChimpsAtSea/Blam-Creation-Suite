#pragma once

namespace blofeld
{
	constexpr unsigned long SKY_ATM_PARAMETERS_TAG = 'skya';
	extern s_tag_group sky_atm_parameters_group; // #CUSTOM
	extern s_tag_block_definition sky_atm_parameters_block; // #CUSTOM
	extern s_tag_struct_definition sky_atm_parameters_block_struct_definition; // #CUSTOM

	extern s_tag_block_definition sky_atm_parameters_underwater_properties_block; // #CUSTOM
	extern s_tag_struct_definition sky_atm_parameters_underwater_properties_block_struct_definition; // #CUSTOM
	extern s_tag_block_definition sky_atm_parameters_atmosphere_properties_block; // #CUSTOM
	extern s_tag_struct_definition sky_atm_parameters_atmosphere_properties_block_struct_definition; // #CUSTOM

	constexpr unsigned long ATMOSPHERE_FOG_TAG = 'fogg';
	extern s_tag_group atmosphere_fog_group; // atmosphere_definition_block


	extern s_tag_block_definition atmosphere_definition_block;
	extern s_tag_struct_definition atmosphere_definition_block_struct_definition; // atmosphere_definition_block
	extern s_tag_block_definition soloFogFunctionBlock_block;
	extern s_tag_struct_definition soloFogFunctionBlock_block_struct_definition; // soloFogFunctionBlock_block

	extern s_tag_struct_definition solo_fog_parameters_struct_definition;
	extern s_tag_struct_definition fog_light_struct_definition;
	extern s_tag_struct_definition VolumeFogParametersDefinition;
	extern s_tag_struct_definition LightShaftParametersDefinition;

	extern s_string_list_definition atmosphere_flags;

	extern s_tag_reference_definition global_sky_atmosphere_definition_reference;
	extern s_tag_reference_definition global_atmosphere_definition_reference;


} // namespace blofeld

