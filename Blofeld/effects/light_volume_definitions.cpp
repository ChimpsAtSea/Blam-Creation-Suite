#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(light_volume_system, LIGHT_VOLUME_SYSTEM_TAG, light_volume_system_block_block );

	TAG_BLOCK(light_volume_precompiled_vert_block, c_light_volume_definition::k_max_precompiled_profiles)
	{
		FIELD( _field_word_integer, "r" ),
		FIELD( _field_word_integer, "g" ),
		FIELD( _field_word_integer, "b" ),
		FIELD( _field_word_integer, "thickness" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(light_volume_definition_block, c_light_volume_system_definition::k_max_light_volume)
	{
		FIELD( _field_custom ),
		FIELD( _field_string_id, "light_volume name^" ),
		FIELD( _field_custom, "material" ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "actual material\?", &material_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_word_flags, "appearance flags", &light_volume_appearance_flags ),
		FIELD( _field_pad, "SONGWEOINGEW", 2 ),
		FIELD( _field_real, "brightness ratio#avg. brightness head-on/side-view" ),
		FIELD( _field_long_flags, "flags", &light_volume_flags ),
		FIELD( _field_real, "LOD in distance#defaults to 0.0, ignored if \'lod enabled\' not checked above" ),
		FIELD( _field_real, "LOD feather in delta#defaults to 0.0, ignored if \'lod enabled\' not checked above" ),
		FIELD( _field_real, "inverse LOD feather in!" ),
		FIELD( _field_real, "LOD out distance#defaults to 30.0, ignored if \'lod enabled\' not checked above" ),
		FIELD( _field_real, "LOD feather out delta#defaults to 10.0, ignored if \'lod enabled\' not checked above" ),
		FIELD( _field_real, "inverse LOD feather out!" ),
		FIELD( _field_struct, "length", &light_volume_property_real_struct_definition ),
		FIELD( _field_struct, "offset", &light_volume_property_real_struct_definition ),
		FIELD( _field_struct, "profile_density", &light_volume_property_real_struct_definition ),
		FIELD( _field_struct, "profile_length", &light_volume_property_real_struct_definition ),
		FIELD( _field_struct, "profile_thickness", &light_volume_property_real_struct_definition ),
		FIELD( _field_struct, "profile_color", &light_volume_property_real_rgb_color_struct_definition ),
		FIELD( _field_struct, "profile_alpha", &light_volume_property_real_struct_definition ),
		FIELD( _field_struct, "profile_intensity", &light_volume_property_real_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_dword_integer, "runtime m_constant_per_profile_properties!" ),
		FIELD( _field_dword_integer, "runtime m_used_states!" ),
		FIELD( _field_dword_integer, "runtime m_max_profile_count!" ),
		FIELD( _field_struct, "runtime m_gpu_data!", &gpu_property_function_color_struct_struct_definition ),
		FIELD( _field_block, "precompiled vertices", &light_volume_precompiled_vert_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(light_volume_system_block, 1, light_volume_system_struct_definition_struct_definition );

	TAG_STRUCT(light_volume_system_struct_definition)
	{
		FIELD( _field_block, "light_volumes", &light_volume_definition_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(light_volume_property_real)
	{
		FIELD( _field_char_enum, "Input Variable", &light_volume_state_input_enum ),
		FIELD( _field_char_enum, "Range Variable", &light_volume_state_input_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &light_volume_state_input_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(light_volume_property_real_rgb_color)
	{
		FIELD( _field_char_enum, "Input Variable", &light_volume_state_input_enum ),
		FIELD( _field_char_enum, "Range Variable", &light_volume_state_input_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &light_volume_state_input_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(light_volume_state_input_enum, 10)
	{
		OPTION("profile position"),
		OPTION("game time"),
		OPTION("light volume age"),
		OPTION("light volume random"),
		OPTION("light volume correlation 1"),
		OPTION("light volume correlation 2"),
		OPTION("light volume lod"),
		OPTION("effect a scale"),
		OPTION("effect b scale"),
		OPTION("invalid state --- please set again"),
	};

	TAG_ENUM(output_mod_enum$2, 3)
	{
		OPTION(" "),
		OPTION("Plus"),
		OPTION("Times"),
	};

	TAG_ENUM_EMPTY(light_volume_appearance_flags, 0);

	TAG_ENUM(light_volume_flags, 7)
	{
		OPTION("lod enabled#if not checked, the following flags do not matter, nor do LOD parameters below"),
		OPTION("lod always 1.0{ignore lod (render always)}"),
		OPTION("lod same in splitscreen"),
		OPTION("disable precompiled profiles"),
		OPTION("force precompile profiles"),
		OPTION("can be low res"),
		OPTION("precompiled!"),
	};

} // namespace blofeld

