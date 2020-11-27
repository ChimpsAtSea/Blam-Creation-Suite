#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(particle, PARTICLE_TAG, particle_block_block );

	TAG_BLOCK(gpu_variants_block, sizeof(c_particle_definition::s_gpu_data::s_frames)/sizeof(real_vector4d))
	{
		{ _field_array, "runtime m_count!", &gpu_single_constant_register_array_array },
		{ _field_terminator }
	};

	TAG_BLOCK(attachment_block, 4)
	{
		{ _field_byte_flags, "flags", &attachment_flags },
		{ _field_pad, "gerrrrr", 3 },
		{ _field_tag_reference, "type", &attachment_block_type_reference },
		{ _field_char_enum, "trigger", &attachment_type_enum },
		{ _field_byte_integer, "skip fraction:[0-127]#0 will always play, 127 will be extremely rare" },
		{ _field_char_enum, "primary scale", &game_state_type_enum },
		{ _field_char_enum, "secondary scale", &game_state_type_enum },
		{ _field_terminator }
	};

	TAG_BLOCK(gpu_sprite_block, 1)
	{
		{ _field_array, "runtime gpu_sprite_array!", &gpu_single_constant_register_array_array },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(particle_block, 1, particle_struct_definition_struct_definition );

	TAG_ARRAY(gpu_single_constant_register_array, sizeof(real_vector4d)/sizeof(real))
	{
		{ _field_real, "runtime gpu_real!" },
		{ _field_terminator }
	};

	TAG_REFERENCE(particle_struct_unknown_reference);

	TAG_STRUCT(particle_struct_definition)
	{
		{ _field_custom },
		{ _field_long_flags, "main flags", &particle_main_flags },
		{ _field_block, "attachments", &attachment_block_block },
		{ _field_explanation, "PARTICLE APPEARANCE", "" },
		{ _field_long_flags, "appearance flags", &particle_appearance_flags },
		{ _field_enum, "particle billboard style", &particle_billboard_type_enum },
		{ _field_pad, "NQCLLBQ", 2 },
		{ _field_short_integer, "first sequence index" },
		{ _field_short_integer, "sequence count" },
		{ _field_real, "low res switch distance:wu#the distance at which we switch from low res (close) to high res (far)" },
		{ _field_real_point_2d, "center offset" },
		{ _field_real, "curvature:0=flat, 1=hemisphere" },
		{ _field_real, "angle fade range:degrees#degrees beyond cutoff over which particles fade" },
		{ _field_real, "angle fade cutoff:degrees#degrees away from edge-on where fade is total" },
		{ _field_real, "motion blur translation scale#affects billboard tilt from observer motion" },
		{ _field_real, "motion blur rotation scale#affects billboard tilt from observer turning" },
		{ _field_real, "motion blur aspect scale#affects aspect ratio stretching from particle and observer motion" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_explanation, "Render Method" },
		{ _field_struct, "render method", &render_method_struct_definition_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },

		{ _field_version_less_or_equal, _engine_type_haloreach, 10 },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_real, "unknown@" },
		{ _field_tag_reference, "unknown@", &particle_struct_unknown_reference },

		{ _field_custom },
		{ _field_custom },
		{ _field_struct, "aspect ratio", &particle_property_scalar_struct_new_struct_definition },
		{ _field_struct, "color:RGB#controls how the color of the particle changes as a function of its input", &particle_property_color_struct_new_struct_definition },
		{ _field_struct, "intensity#multiplies color to give dynamic range outside [0,1]", &particle_property_scalar_struct_new_struct_definition },
		{ _field_struct, "alpha#separate from color, controls how the particle fades as a function of its input", &particle_property_scalar_struct_new_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_real, "tint factor:0=modulate, 1=tint#switches between modulate (multiply) and tint(preserve whites)" },

		{ _field_explanation, "PARTICLE ANIMATION", "" },
		{ _field_long_flags, "animation flags", &particle_animation_flags },

		{ _field_struct, "frame index#0=first frame, 1=last frame", &particle_property_scalar_struct_new_struct_definition },
		{ _field_struct, "animation rate:index cycles per second", &particle_property_scalar_struct_new_struct_definition },
		{ _field_struct, "palette animation:v coord of palette", &particle_property_scalar_struct_new_struct_definition },
		{ _field_explanation, "Mesh data, if this is a mesh particle", "" },
		{ _field_tag_reference, "Model", &particle_model_reference$2 },

		{ _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_custom, "OLD DEPRECATED shader definition" },
		{ _field_custom, "shader" },
		{ _field_custom },
		{ _field_custom },
		{ _field_struct, "actual shader\?", &shader_particle_struct_definition_struct_definition },
		{ _field_custom },

		{ _field_dword_integer, "runtime m_used_particle_states!" },
		{ _field_dword_integer, "runtime m_constant_per_particle_properties!" },
		{ _field_dword_integer, "runtime m_constant_over_time_properties!" },
		{ _field_struct, "runtime m_gpu_data!", &gpu_data_struct$2_struct_definition },

		{ _field_terminator }
	};

	TAG_STRUCT(gpu_data_struct$2)
	{
		{ _field_block, "runtime m_sprite!", &gpu_sprite_block_block },
		{ _field_block, "runtime m_frames!", &gpu_variants_block_block },
		{ _field_terminator }
	};

	STRINGS(particle_main_flags)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"dies at rest",
				"dies on structure collision",
				"dies in water",
				"dies in air",
				"has sweetener",
				"uses cheap shader"
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"bit 7"
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"dies at rest",
				"dies on structure collision",
				"dies in water",
				"dies in air",
				"has sweetener",
				"uses cheap shader"
			}
		}
	};
	STRING_LIST(particle_main_flags, particle_main_flags_strings, _countof(particle_main_flags_strings));

	STRINGS(particle_appearance_flags)
	{
		"random u mirror",
		"random v mirror",
		"random starting rotation",
		"tint from lightmap",
		"tint from diffuse texture",
		"bitmap authored vertically",
		"intensity affects alpha",
		"fade when viewed edge-on",
		"motion blur",
		"double-sided",
		"low res#renders heavy overdraw particles faster",
		"low res tighter mask#requires depth fade",
		"never kill verts on GPU (expensive)",
		"particle velocity relative to camera#makes parallel and perpindicular to velocity behave differently based upon camera motion",
		"_unknown_particle_appearance_flag_15",
		"_unknown_particle_appearance_flag_16",
		"_unknown_particle_appearance_flag_17",
		"_unknown_particle_appearance_flag_18",
	};
	STRING_LIST(particle_appearance_flags, particle_appearance_flags_strings, _countof(particle_appearance_flags_strings));

	STRINGS(particle_animation_flags)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"frame animation one shot",
				"can animate backwards"
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"bit 3",
				"bit 4"
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"frame animation one shot",
				"can animate backwards"
			}
		}
	};
	STRING_LIST(particle_animation_flags, particle_animation_flags_strings, _countof(particle_animation_flags_strings));

	STRINGS(particle_billboard_type_enum)
	{
		"screen facing",
		"camera facing",
		"parallel to direction",
		"perpendicular to direction",
		"vertical",
		"horizontal",
		"local vertical",
		"local horizontal",
		"world (particle models)",
		"velocity horizontal (particle models)"
	};
	STRING_LIST(particle_billboard_type_enum, particle_billboard_type_enum_strings, _countof(particle_billboard_type_enum_strings));

	STRINGS(attachment_type_enum)
	{
		"birth",
		"collision",
		"death",
		"first collision"
	};
	STRING_LIST(attachment_type_enum, attachment_type_enum_strings, _countof(attachment_type_enum_strings));

	STRINGS(attachment_flags)
	{
		"disabled for debugging"
	};
	STRING_LIST(attachment_flags, attachment_flags_strings, _countof(attachment_flags_strings));

} // namespace blofeld

