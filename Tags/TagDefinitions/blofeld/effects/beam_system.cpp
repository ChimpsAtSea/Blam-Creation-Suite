#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{
	STRINGS(beam_system_output_kind)
	{
		"none",
		"additive",
		"multiply"
	};
	STRING_LIST(beam_system_output_kind, beam_system_output_kind_strings, _countof(beam_system_output_kind_strings));

	V5_TAG_STRUCT_V6(beam_system_gpu_data_struct)
	{
		{ _field_legacy, _field_block, "runtime gpu_property_block!", &gpu_property_block },
		{ _field_legacy, _field_block, "runtime gpu_functions_block!", &gpu_property_block },
		{ _field_legacy, _field_block, "runtime gpu_colors_block!", &gpu_color_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT_V6(beam_system_unknown_struct)
	{
		{ _field_legacy, _field_char_integer, "input" },
		{ _field_legacy, _field_char_integer, "input range" },
		{ _field_legacy, _field_char_enum, "output kind", &beam_system_output_kind },
		{ _field_legacy, _field_char_integer, "output" },
		{ _field_legacy, _field_data, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	TAG_REFERENCE(beam_render_method_definition_reference, blofeld::RENDER_METHOD_DEFINITION_TAG);
	TAG_REFERENCE(beam_render_method_reference);

	V5_TAG_BLOCK(beam_system_entry_block, 65536)
	{
		{ _field_legacy, _field_string_id, "name" },
		{ _field_legacy, _field_explanation, "Render Method" },
		{ _field_legacy, _field_struct, "render method", &render_method_struct_definition },
		{ _field_legacy, _field_word_flags, "appearance flags", &tracerAppearanceFlags },
		{ _field_legacy, _field_custom, "Tracer Shape" },
		{ _field_legacy, _field_char_enum, "profile shape", &tracerProfileShapeEnum },
		{ _field_legacy, _field_byte_integer, "number of n-gon sides" },
		{ _field_legacy, _field_real_vector_2d, "uv tiling rate" },
		{ _field_legacy, _field_real_vector_2d, "uv scrolling rate" },
		{ _field_legacy, _field_real, "origin fade range{origin fade distance}:world units#distance beyond cutoff over which tracers fade" },
		{ _field_legacy, _field_real, "origin fade cutoff:world units#distance from tracer origin where fade begins" },
		{ _field_legacy, _field_real, "edge fade range:degrees#degrees beyond cutoff over which tracers fade" },
		{ _field_legacy, _field_real, "edge fade cutoff:degrees#degrees away from edge-on where fade is total" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },

		{ _field_legacy, _field_struct, "length#world units", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "offset#world units", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "profile density#profiles per world unit", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "profile offset#world units", &tracerProperty_real_point2d_Struct },

		{ _field_legacy, _field_struct, "profile rotation#degrees", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "thickness", &tracerProperty_real_Struct },

		{ _field_legacy, _field_struct, "profile color", &tracerProperty_real_rgb_color_Struct },
		{ _field_legacy, _field_struct, "profile alpha", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "profile black point", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "profile palette", &tracerProperty_real_Struct },
		{ _field_legacy, _field_struct, "profile intensity", &tracerProperty_real_Struct },

		{ _field_legacy, _field_dword_integer, "runtime m_constantPerProfileProperties!" },
		{ _field_legacy, _field_dword_integer, "runtime m_usedStates!" },
		{ _field_legacy, _field_dword_integer, "runtime m_maxProfileCount!" },
		{ _field_legacy, _field_struct, "runtime m_gpuData!", &gpu_property_function_color_struct },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_GROUP(beam_system, BEAM_SYSTEM_TAG)
	{
		{ _field_legacy, _field_block, "beam system", &beam_system_entry_block },
		{ _field_legacy, _field_terminator }
	};

}