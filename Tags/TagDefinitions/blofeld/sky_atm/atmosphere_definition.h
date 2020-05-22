#pragma once

namespace blofeld
{

	constexpr unsigned long ATMOSPHERE_FOG_TAG = 'fogg';

	extern s_tag_group atmosphere_fog_group;

	extern s_tag_struct_definition soloFogFunctionBlock_block_struct;
	extern s_tag_block_definition soloFogFunctionBlock_block;
	extern s_tag_struct_definition atmosphere_definition_block_block_struct;
	extern s_tag_block_definition atmosphere_definition_block_block;

	extern s_tag_struct_definition solo_fog_parameters_struct_definition_struct_definition;
	extern s_tag_struct_definition fog_light_struct_definition_struct_definition;
	extern s_tag_struct_definition VolumeFogParametersDefinition_struct_definition;
	extern s_tag_struct_definition LightShaftParametersDefinition_struct_definition;

	extern const char* atmosphere_flags_strings[];
	extern s_string_list_definition atmosphere_flags;

	extern s_tag_reference_definition global_atmosphere_definition_reference;

} // namespace blofeld

