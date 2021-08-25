#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		tracer_system_group,
		TRACER_SYSTEM_TAG,
		nullptr,
		INVALID_TAG,
		tracer_system_block );

	TAG_BLOCK_FROM_STRUCT(
		tracer_system_block,
		"tracer_system_block",
		1,
		tracer_system_struct_definition);

	#define TRACERDEFINITIONBLOCK_ID { 0x81823DCD, 0xDFAE42E3, 0xA663A919, 0xB715B497 }
	TAG_BLOCK(
		tracerDefinitionBlock_block,
		"tracerDefinitionBlock",
		TracerSystemDefinition::k_maxTracers,
		"TracerDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRACERDEFINITIONBLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_string_id, "tracer name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &tracerFlags },
		FIELD_CUSTOM("Tracer Shape", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_char_enum, "profile shape", &tracerProfileShapeEnum },
		{ _field_byte_integer, "number of n-gon sides" },
		FIELD_PAD("tracpad", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_real, "origin fade range", "distance beyond cutoff over which tracers fade", "world units", MAKE_OLD_NAMES("origin fade distance") },
		{ _field_real, "origin fade cutoff", "distance from tracer origin where fade begins", "world units" },
		{ _field_real, "edge fade range", "degrees beyond cutoff over which tracers fade", "degrees" },
		{ _field_real, "edge fade cutoff", "degrees away from edge-on where fade is total", "degrees" },
		{ _field_struct, "profile lifespan", "seconds", &tracerProperty_real_Struct },
		{ _field_struct, "profile self acceleration", "world units per second-squared", &tracerProperty_real_vector3d_Struct },
		{ _field_struct, "length", "world units", &tracerProperty_real_Struct },
		{ _field_struct, "offset", "world units", &tracerProperty_real_Struct },
		{ _field_struct, "profile size", "world units", &tracerProperty_real_Struct },
		{ _field_struct, "profile density", "profiles per world unit", &tracerProperty_real_Struct },
		{ _field_struct, "profile offset", "world units", &tracerProperty_real_point2d_Struct },
		{ _field_struct, "profile rotation", "degrees", &tracerProperty_real_Struct },
		{ _field_struct, "profile rotation rate", "degrees per second", &tracerProperty_real_Struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Tracer Appearance", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_word_flags, "appearance flags", &tracerAppearanceFlags },
		{ _field_short_integer, "sort bias", "use values between -10 and 10 to move closer and farther from camera (positive is closer)" },
		FIELD_CUSTOM("material", nullptr, FIELD_FLAG_NONE, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_begin),
		{ _field_struct, "actual material?", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hide_end),
		{ _field_real_vector_2d, "uv tiling", "u is tiles/world unit, v is absolute tiles", "u lengthwise, v crosswise" },
		{ _field_real_vector_2d, "uv scrolling", nullptr, "tiles per second" },
		{ _field_real, "angle fade range", "radial (from tracer axis) degrees beyond beginning angle over which tracer fades", "degrees" },
		{ _field_real, "angle fade begin", "radial (from tracer axis) degrees away from face-on where fade begins", "degrees" },
		{ _field_struct, "profile color", &tracerProperty_real_rgb_color_Struct },
		{ _field_struct, "profile alpha", &tracerProperty_real_Struct },
		{ _field_struct, "profile alpha2", &tracerProperty_real_Struct },
		{ _field_struct, "profile black point", &tracerProperty_real_Struct },
		{ _field_struct, "profile palette", &tracerProperty_real_Struct },
		{ _field_struct, "profile intensity", &tracerProperty_real_Struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_dword_integer, "runtime m_constantPerProfileProperties", FIELD_FLAG_UNKNOWN0 },
		{ _field_dword_integer, "runtime m_usedStates", FIELD_FLAG_UNKNOWN0 },
		{ _field_dword_integer, "runtime m_maxProfileCount", FIELD_FLAG_UNKNOWN0 },
		{ _field_struct, "runtime m_gpuData", FIELD_FLAG_UNKNOWN0, &gpu_property_function_color_struct },
		{ _field_terminator }
	};

	#define TRACER_SYSTEM_STRUCT_DEFINITION_ID { 0xD599167D, 0x903449CE, 0x94785CCF, 0x2DF03016 }
	TAG_STRUCT(
		tracer_system_struct_definition,
		"tracer_system_struct_definition",
		"TracerSystemDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRACER_SYSTEM_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "tracer system flags", &tracerSystemFlags },
		FIELD_EXPLANATION("far lod", nullptr, FIELD_FLAG_NONE, "These don\'t actually do anything unless you use \"tracer lod\" in one of your curves."),
		{ _field_real, "far lod start" },
		{ _field_real, "far lod end" },
		{ _field_real, "far lod start value" },
		{ _field_real, "far lod end value" },
		{ _field_block, "tracers", &tracerDefinitionBlock_block },
		{ _field_terminator }
	};

	#define TRACERPROPERTY_REAL_STRUCT_ID { 0x91513A4E, 0x20A34CBB, 0x9722BA95, 0x3B66FE62 }
	TAG_STRUCT(
		tracerProperty_real_Struct,
		"tracerProperty_real_Struct",
		"TracerProperty_real",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRACERPROPERTY_REAL_STRUCT_ID)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum, _field_id_fnop },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define TRACERPROPERTY_REAL_VECTOR3D_STRUCT_ID { 0xBE4687B3, 0xC8B74B16, 0x86F2D1AC, 0x27137B34 }
	TAG_STRUCT(
		tracerProperty_real_vector3d_Struct,
		"tracerProperty_real_vector3d_Struct",
		"TracerProperty_real_vector3d",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRACERPROPERTY_REAL_VECTOR3D_STRUCT_ID)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum, _field_id_fnop },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_vector_3d, "Starting interpolant" },
		{ _field_real_vector_3d, "Ending interpolant" },
		{ _field_terminator }
	};

	#define TRACERPROPERTY_REAL_POINT2D_STRUCT_ID { 0x0837F421, 0x9742425D, 0xB30CA589, 0x0DC66361 }
	TAG_STRUCT(
		tracerProperty_real_point2d_Struct,
		"tracerProperty_real_point2d_Struct",
		"TracerProperty_real_point2d",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRACERPROPERTY_REAL_POINT2D_STRUCT_ID)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum, _field_id_fnop },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real_vector_2d, "Starting interpolant" },
		{ _field_real_vector_2d, "Ending interpolant" },
		{ _field_terminator }
	};

	#define TRACERPROPERTY_REAL_RGB_COLOR_STRUCT_ID { 0xFD7B022D, 0xC01E4F52, 0x9D862B19, 0xC6CBF906 }
	TAG_STRUCT(
		tracerProperty_real_rgb_color_Struct,
		"tracerProperty_real_rgb_color_Struct",
		"TracerProperty_real_rgb_color",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRACERPROPERTY_REAL_RGB_COLOR_STRUCT_ID)
	{
		{ _field_char_enum, "Input Variable", &tracerStateInputEnum, _field_id_function_input_scalar },
		{ _field_char_enum, "Range Variable", &tracerStateInputEnum, _field_id_function_input_range },
		{ _field_char_enum, "Output Modifier", &tracerStateOutputModEnum, _field_id_fnop },
		{ _field_char_enum, "Output Modifier Input", &tracerStateInputEnum, _field_id_function_output_modifier },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "Mapping", &mapping_function },
		{ _field_real, "runtime m_constant_value", FIELD_FLAG_UNKNOWN0 },
		{ _field_word_integer, "runtime m_flags", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("DSFDSGLKJ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	STRINGS(tracerStateInputEnum)
	{
		"profile age",
		"profile position",
		"unused",
		"profile random",
		"profile correlation 1",
		"profile correlation 2",
		"profile correlation 3",
		"profile correlation 4",
		"game time",
		"tracer random",
		"tracer correlation 1",
		"tracer correlation 2",
		"tracer speed",
		"tracer length",
		"system age",
		"system lod",
		"effect a scale",
		"effect b scale",
		"invalid state --- please set again"
	};
	STRING_LIST(tracerStateInputEnum, tracerStateInputEnum_strings, _countof(tracerStateInputEnum_strings));

	STRINGS(tracerStateOutputModEnum)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(tracerStateOutputModEnum, tracerStateOutputModEnum_strings, _countof(tracerStateOutputModEnum_strings));

	STRINGS(tracerProfileShapeEnum)
	{
		"aligned ribbon",
		"cross",
		"n-gon",
		"horizontal",
		"vertical"
	};
	STRING_LIST(tracerProfileShapeEnum, tracerProfileShapeEnum_strings, _countof(tracerProfileShapeEnum_strings));

	STRINGS(tracerFlags)
	{
		"disabled for debugging"
	};
	STRING_LIST(tracerFlags, tracerFlags_strings, _countof(tracerFlags_strings));

	STRINGS(tracerAppearanceFlags)
	{
		"tint from lightmap",
		"double-sided",
		"profile opacity from scale a",
		"random u offset",
		"random v offset",
		"can render low res"
	};
	STRING_LIST(tracerAppearanceFlags, tracerAppearanceFlags_strings, _countof(tracerAppearanceFlags_strings));

	STRINGS(tracerSystemFlags)
	{
		"point-to-point#skips the update step, and ignores lifespan, for point-to-point effects",
		"draw in first person pass (dangerous)#use this only if the entire tracer is in \"first person space\"; can lead to depth artifacts if misused",
		"disable when zoomed"
	};
	STRING_LIST(tracerSystemFlags, tracerSystemFlags_strings, _countof(tracerSystemFlags_strings));



} // namespace blofeld

