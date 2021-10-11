#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define PARTICLE_PROPERTY_REAL_POINT3D_STRUCT_NEW_ID { 0x0BEB218F, 0x6CE546FA, 0xA21161F6, 0xE75582FC }
	TAG_STRUCT(
		particle_property_real_point3d_struct_new,
		"particle_property_real_point3d_struct_new",
		"c_particle_property_real_point3d",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PROPERTY_REAL_POINT3D_STRUCT_NEW_ID)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &game_state_type_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_function_output_modifier },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum, _field_id_function_output_modifier_input },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD_EX("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_point_3d, "Starting interpolant" },
		{ _field_real_point_3d, "Ending interpolant" },
		{ _field_terminator }
	};

	#define PARTICLE_PROPERTY_REAL_EULER_ANGLES2D_STRUCT_NEW_ID { 0x937386F6, 0xD5844EB4, 0x82972518, 0xEF8BF01E }
	TAG_STRUCT(
		particle_property_real_euler_angles2d_struct_new,
		"particle_property_real_euler_angles2d_struct_new",
		"c_particle_property_real_euler_angles2d",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PROPERTY_REAL_EULER_ANGLES2D_STRUCT_NEW_ID)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &game_state_type_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_function_output_modifier },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum, _field_id_function_output_modifier_input },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD_EX("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_euler_angles_2d, "Direction at 0" },
		{ _field_real_euler_angles_2d, "Direction at 1" },
		{ _field_terminator }
	};

	#define PARTICLE_PROPERTY_SCALAR_STRUCT_NEW_ID { 0x64607252, 0xE8084E37, 0x8447409D, 0x9411483C }
	TAG_STRUCT(
		particle_property_scalar_struct_new,
		"particle_property_scalar_struct_new",
		"c_particle_property",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PROPERTY_SCALAR_STRUCT_NEW_ID)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &game_state_type_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_function_output_modifier },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum, _field_id_function_output_modifier_input },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_flags, "force flags", FIELD_FLAG_UNKNOWN0, &force_flags_definition },
		FIELD_PAD_EX("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define PARTICLE_PROPERTY_REAL_VECTOR3D_STRUCT_NEW_ID { 0x02581257, 0x6A544BEE, 0xA48450A0, 0xA5C42FB5 }
	TAG_STRUCT(
		particle_property_real_vector3d_struct_new,
		"particle_property_real_vector3d_struct_new",
		"c_particle_property_real_vector3d",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PROPERTY_REAL_VECTOR3D_STRUCT_NEW_ID)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &game_state_type_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_function_output_modifier },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum, _field_id_function_output_modifier_input },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD_EX("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_vector_3d, "Starting interpolant" },
		{ _field_real_vector_3d, "Ending interpolant" },
		{ _field_terminator }
	};

	#define PARTICLE_PROPERTY_COLOR_STRUCT_NEW_ID { 0x342C0071, 0xBAFB43CF, 0x9FDA5DD6, 0x630D2DCA }
	TAG_STRUCT(
		particle_property_color_struct_new,
		"particle_property_color_struct_new",
		"c_particle_property",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_PROPERTY_COLOR_STRUCT_NEW_ID)
	{
		{ _field_char_enum, "Input Variable", &game_state_type_enum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &game_state_type_enum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &output_mod_enum, _field_id_function_output_modifier },
		{ _field_char_enum, "Output Modifier Input", &game_state_type_enum, _field_id_function_output_modifier_input },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD_EX("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	STRINGS(game_state_type_enum)
	{
		"particle age",
		"system age{emitter age}",
		"particle random",
		"system random{emitter random}",
		"particle correlation 1{particle random 1}",
		"particle correlation 2{particle random 2}",
		"particle correlation 3{particle random 3}",
		"particle correlation 4{particle random 4}",
		"system correlation 1{emitter correlation 1}{emitter random 1}",
		"system correlation 2{emitter correlation 2}{emitter random 2}",
		"particle emission time{emitter time}{particle emit time}",
		"location lod{system lod}",
		"game time",
		"effect a scale",
		"effect b scale",
		"particle rotation{physics rotation}",
		"location random",
		"distance from emitter",
		"particle simulation a",
		"particle simulation b",
		"particle velocity",
		"invalid state --- please set again"
	};
	STRING_LIST(game_state_type_enum, game_state_type_enum_strings, _countof(game_state_type_enum_strings));

	STRINGS(output_mod_enum$3)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$3, output_mod_enum$3_strings, _countof(output_mod_enum$3_strings));

	STRINGS(force_flags_definition)
	{
		"force constant"
	};
	STRING_LIST(force_flags_definition, force_flags_definition_strings, _countof(force_flags_definition_strings));



} // namespace blofeld

