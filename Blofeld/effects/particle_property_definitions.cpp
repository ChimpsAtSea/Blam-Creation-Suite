#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(particle_property_real_point3d_struct_new)
{
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
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
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
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
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_real, "runtime m_constant_value!" ),
	FIELD( _field_word_integer, "runtime m_flags!" ),
	FIELD( _field_byte_flags, "force flags!" ),
	FIELD( _field_pad, "DSFDSGLKJ", 1 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(particle_property_real_vector3d_struct_new)
{
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
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
	FIELD( _field_char_enum, "Input Variable" ),
	FIELD( _field_char_enum, "Range Variable" ),
	FIELD( _field_char_enum, "Output Modifier" ),
	FIELD( _field_char_enum, "Output Modifier Input" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_real, "runtime m_constant_value!" ),
	FIELD( _field_word_integer, "runtime m_flags!" ),
	FIELD( _field_pad, "DSFDSGLKJ", 2 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

