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

	TAG_STRUCT(beam_system_unknown_struct)
	{
		{ _field_char_integer, "input" },
		{ _field_char_integer, "input range" },
		{ _field_char_enum, "output kind", &beam_system_output_kind },
		{ _field_char_integer, "output" },
		{ _field_data, "unknown" },
		{ _field_real, "unknown" },
		{ _field_long_integer, "unknown" },
		{ _field_terminator }
	};

	TAG_REFERENCE(beam_render_method_definition_reference, blofeld::RENDER_METHOD_DEFINITION_TAG);
	TAG_REFERENCE(beam_render_method_reference);

	TAG_BLOCK(beam_system_entry, 65536)
	{
		{ _field_string_id, "name" },
		{ _field_explanation, "Render Method" },
		{ _field_struct, "render method", &render_method_struct_definition_struct_definition },
		{ _field_word_flags, "appearance flags", &tracerAppearanceFlags },
		{ _field_custom, "Tracer Shape" },
		{ _field_char_enum, "profile shape", &tracerProfileShapeEnum },
		{ _field_byte_integer, "number of n-gon sides" },
		{ _field_real_vector_2d, "uv tiling rate" },
		{ _field_real_vector_2d, "uv scrolling rate" },
		{ _field_real, "origin fade range{origin fade distance}:world units#distance beyond cutoff over which tracers fade" },
		{ _field_real, "origin fade cutoff:world units#distance from tracer origin where fade begins" },
		{ _field_real, "edge fade range:degrees#degrees beyond cutoff over which tracers fade" },
		{ _field_real, "edge fade cutoff:degrees#degrees away from edge-on where fade is total" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },
		{ _field_real, "unknown" },

		{ _field_struct, "length#world units", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "offset#world units", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile density#profiles per world unit", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile offset#world units", &tracerProperty_real_point2d_Struct_struct_definition },

		{ _field_struct, "profile rotation#degrees", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "thickness", &tracerProperty_real_Struct_struct_definition },

		{ _field_struct, "profile color", &tracerProperty_real_rgb_color_Struct_struct_definition },
		{ _field_struct, "profile alpha", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile black point", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile palette", &tracerProperty_real_Struct_struct_definition },
		{ _field_struct, "profile intensity", &tracerProperty_real_Struct_struct_definition },

		{ _field_dword_integer, "runtime m_constantPerProfileProperties!" },
		{ _field_dword_integer, "runtime m_usedStates!" },
		{ _field_dword_integer, "runtime m_maxProfileCount!" },
		{ _field_struct, "runtime m_gpuData!", &gpu_property_function_color_struct_struct_definition },

		{ _field_terminator }
	};

	TAG_GROUP(beam_system, BEAM_SYSTEM_TAG)
	{
		{ _field_block, "beam system", &beam_system_entry_block },
		{ _field_terminator }
	};

}