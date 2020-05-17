#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_STRUCT(particle_property_real_point3d_struct_new)
	{
		FIELD( _field_char_enum, "Input Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Range Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &game_state_type_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_real_point_3d, "Starting interpolant" ),
		FIELD( _field_real_point_3d, "Ending interpolant" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(particle_property_real_euler_angles2d_struct_new)
	{
		FIELD( _field_char_enum, "Input Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Range Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &game_state_type_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_real_euler_angles_2d, "Direction at 0" ),
		FIELD( _field_real_euler_angles_2d, "Direction at 1" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(particle_property_scalar_struct_new)
	{
		FIELD( _field_char_enum, "Input Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Range Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &game_state_type_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_byte_flags, "force flags!", &force_flags_definition ),
		FIELD( _field_pad, "DSFDSGLKJ", 1 ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(particle_property_real_vector3d_struct_new)
	{
		FIELD( _field_char_enum, "Input Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Range Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &game_state_type_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_real_vector_3d, "Starting interpolant" ),
		FIELD( _field_real_vector_3d, "Ending interpolant" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(particle_property_color_struct_new)
	{
		FIELD( _field_char_enum, "Input Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Range Variable", &game_state_type_enum ),
		FIELD( _field_char_enum, "Output Modifier", &output_mod_enum ),
		FIELD( _field_char_enum, "Output Modifier Input", &game_state_type_enum ),
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_real, "runtime m_constant_value!" ),
		FIELD( _field_word_integer, "runtime m_flags!" ),
		FIELD( _field_pad, "DSFDSGLKJ", 2 ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(game_state_type_enum, 22)
	{
		OPTION("particle age"),
		OPTION("system age{emitter age}"),
		OPTION("particle random"),
		OPTION("system random{emitter random}"),
		OPTION("particle correlation 1{particle random 1}"),
		OPTION("particle correlation 2{particle random 2}"),
		OPTION("particle correlation 3{particle random 3}"),
		OPTION("particle correlation 4{particle random 4}"),
		OPTION("system correlation 1{emitter correlation 1}{emitter random 1}"),
		OPTION("system correlation 2{emitter correlation 2}{emitter random 2}"),
		OPTION("particle emission time{emitter time}{particle emit time}"),
		OPTION("location lod{system lod}"),
		OPTION("game time"),
		OPTION("effect a scale"),
		OPTION("effect b scale"),
		OPTION("particle rotation{physics rotation}"),
		OPTION("location random"),
		OPTION("distance from emitter"),
		OPTION("particle simulation a"),
		OPTION("particle simulation b"),
		OPTION("particle velocity"),
		OPTION("invalid state --- please set again"),
	};

	TAG_ENUM(output_mod_enum$3, 3)
	{
		OPTION(" "),
		OPTION("Plus"),
		OPTION("Times"),
	};

	TAG_ENUM(force_flags_definition, 1)
	{
		OPTION("force constant"),
	};

} // namespace blofeld

