#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define PARTICLE_SYSTEM_DEFINITION_BLOCK_NEW_ID { 0x1A9DCA45, 0x13064A9F, 0x9D46034E, 0x0C703387 }
	TAG_BLOCK(
		particle_system_definition_block_new_block,
		"particle_system_definition_block_new",
		c_particle_system_definition::k_maximum_particle_systems_per_block,
		"c_particle_system_definition",
		PARTICLE_SYSTEM_DEFINITION_BLOCK_NEW_ID)
	{
		FIELD_CUSTOM(nullptr, _custom_field_unknown_begin),
		{ _field_char_enum, "priority", &global_effect_priority_enum },
		{ _field_pad, "CXAEIHGADNF", 3 },
		{ _field_tag_reference, "particle", &particle_reference },
		{ _field_long_block_index, "location" },
		{ _field_enum, "coordinate system", &coordinate_system_enum },
		{ _field_enum, "environment", &effect_environments },
		{ _field_enum, "disposition", &effect_dispositions },
		{ _field_enum, "camera mode", &effect_camera_modes },
		{ _field_char_enum, "game mode", &effectPartGameModeDefinition },
		{ _field_pad, "pad0", 1 },
		{ _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" },
		{ _field_long_flags, "flags", &particle_system_flags },
		{ _field_real_bounds, "percent velocity to inherit#flag must be checked above" },
		{ _field_real, "size scale#multiplied by all \"size\" related fields, like scale, velocity, acceleration" },
		{ _field_real, "camera offset:world units#the particle is pushed away from the camera this distance (can be negative)" },
		FIELD_CUSTOM("Estimate overdraw threshold", _custom_field_particle_estimate_overdraw_unknown),
		{ _field_real, "Pixel budget:ms" },
		{ _field_real, "near fade range:world units#distance beyond cutoff over which particles fade" },
		{ _field_real, "near fade cutoff:world units#distance in front of camera where fade is complete*" },
		{ _field_real, "near fade override:world units#distance in front of camera where fade is complete" },
		{ _field_real, "far fade range:world units#distance before cutoff over which particles fade" },
		{ _field_real, "far fade cutoff:world units#distance from camera where fade is complete" },
		{ _field_real, "LOD in distance#" },
		{ _field_real, "LOD feather in delta#minimum is 0.0001" },
		{ _field_real, "inverse LOD feather in!" },
		{ _field_real, "LOD out distance#defaults to 20.0" },
		{ _field_real, "LOD feather out delta#0 defaults to 5.0, minimum is 0.0001" },
		{ _field_real, "inverse LOD feather out!" },
		FIELD_CUSTOM(nullptr, _custom_field_unknown_end),
		{ _field_block, "emitters", &particle_system_emitter_definition_block },
		{ _field_real, "runtime max lifespan!" },
		{ _field_real, "runtime overdraw!" },
		{ _field_terminator }
	};

	#define PARTICLE_SYSTEM_EMITTER_DEFINITION_BLOCK_ID { 0xD274EE53, 0x85814DDA, 0x82E8BD20, 0x70B91AB5 }
	TAG_BLOCK(
		particle_system_emitter_definition_block,
		"particle_system_emitter_definition_block",
		c_particle_system_definition::k_maximum_emitters_per_definition,
		"c_particle_emitter_definition",
		PARTICLE_SYSTEM_EMITTER_DEFINITION_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, _custom_field_unknown_begin),
		{ _field_string_id, "emitter name^" },
		FIELD_CUSTOM("EMITTER SETTINGS|8FAF8D", _custom_field_function_group_begin),
		{ _field_char_enum, "emission shape", &emission_shape_enum },
		{ _field_byte_flags, "flags!", &emitter_flags },
		{ _field_byte_flags, "emitter flags", &visible_emitter_flags },
		{ _field_char_enum, "particle axis (for models)", &emission_axis_enum },
		{ _field_char_enum, "particle reference axis", &emission_reference_axis_enum },
		{ _field_pad, "Pad0", 3 },
		{ _field_tag_reference, "custom shape", &particle_emitter_custom_shape_reference },
		{ _field_tag_reference, "boat hull", &particle_emitter_boat_hull_shape_reference },
		{ _field_real, "bounding radius estimate*:world units#used if override is zero" },
		{ _field_real, "bounding radius override:world units#used if non-zero" },
		{ _field_real_point_3d, "axis scale#NOTE - setting this will break automatic bounding sphere calculation, you must enter radius manually" },
		{ _field_real_vector_2d, "uv scrolling:tiles per second" },
		FIELD_CUSTOM(nullptr, _custom_field_unknown_end),
		{ _field_struct, "translational offset:world units#XYZ controls that offset the emitter\'s origin from the original location", &particle_property_real_point3d_struct_new },
		{ _field_struct, "relative direction#yaw/pitch that changes the initial rotation of the emitter", &particle_property_real_euler_angles2d_struct_new },
		FIELD_CUSTOM(nullptr, _custom_field_unknown_begin),
		{ _field_struct, "emission radius:world units#defines the size of the emitter", &particle_property_scalar_struct_new },
		{ _field_struct, "emission angle:degrees#determines the angle at which particles are emitted", &particle_property_scalar_struct_new },
		{ _field_struct, "emission axis angle:degrees#determines the max tilt for particle axis", &particle_property_scalar_struct_new },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("EMISSION SETTINGS|8FAF8D", _custom_field_function_group_begin),
		{ _field_struct, "particle starting count#number of particles that are spawned at the birth of the effect", &particle_property_scalar_struct_new },
		{ _field_struct, "particle max count:0=unlimited#max number of particles allowed to exist at one time", &particle_property_scalar_struct_new },
		{ _field_struct, "particle emission rate:particles per second#number of particles that are spawned every second from the emitters", &particle_property_scalar_struct_new },
		{ _field_struct, "particle emission per distance:particles per world unit#number of particles that are spawned every world unit of motion from the emitters", &particle_property_scalar_struct_new },
		{ _field_struct, "particle lifespan:seconds#the number of seconds a particle will live after emission", &particle_property_scalar_struct_new },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("PARTICLE MOTION|8FAF8D", _custom_field_function_group_begin),
		FIELD_CUSTOM("particle physics template", _custom_field_shader_template),
		FIELD_CUSTOM(nullptr, _custom_field_hidd_begin),
		{ _field_struct, "particle movement", &particle_physics_struct },
		FIELD_CUSTOM(nullptr, _custom_field_hidd_end),
		{ _field_block, "particle attractor/repulsor", &emitterGlobalForceBlock_block },
		{ _field_block, "particle clip sphere", &emitterClipSphereBlock_block },
		{ _field_struct, "particle self-acceleration:world units per second per second", &particle_property_real_vector3d_struct_new },
		{ _field_struct, "particle initial velocity{particle velocity}:world units per second", &particle_property_scalar_struct_new },
		{ _field_struct, "particle rotation:.25=90°, .5=180°, 1=360° ... adds to physics", &particle_property_scalar_struct_new },
		{ _field_struct, "particle initial rotation rate{particle angular velocity}:360 degree rotations per second", &particle_property_scalar_struct_new },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM("PARTICLE APPEARANCE|8FAF8D", _custom_field_function_group_begin),
		{ _field_struct, "particle size:world units", &particle_property_scalar_struct_new },
		{ _field_struct, "particle scale:multiple of size", &particle_property_scalar_struct_new },
		{ _field_struct, "particle scale x:multiple of size", &particle_property_scalar_struct_new },
		{ _field_struct, "particle scale y:multiple of size", &particle_property_scalar_struct_new },
		{ _field_struct, "particle tint:RGB#controls the overall tint of the particle", &particle_property_color_struct_new },
		{ _field_struct, "particle alpha", &particle_property_scalar_struct_new },
		{ _field_struct, "particle alpha black point:0=normal, 1=clamped", &particle_property_scalar_struct_new },
		{ _field_struct, "particle alpha white point:1=normal, 0=clamped", &particle_property_scalar_struct_new },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		FIELD_CUSTOM(nullptr, _custom_field_unknown_end),
		{ _field_long_integer, "runtime m_constant_per_particle_properties!" },
		{ _field_long_integer, "runtime m_constant_over_time_properties!" },
		{ _field_long_integer, "runtime m_used_particle_states!" },
		{ _field_struct, "runtime m_gpu_data!", &gpu_property_function_color_struct },
		{ _field_terminator }
	};

	#define EMITTERGLOBALFORCEBLOCK_ID { 0xE1753503, 0x374E470D, 0xBD9324EE, 0x4C8BECA4 }
	TAG_BLOCK(
		emitterGlobalForceBlock_block,
		"emitterGlobalForceBlock",
		4,
		"ParticleEmitterGlobalForce",
		EMITTERGLOBALFORCEBLOCK_ID)
	{
		{ _field_struct, "global force", &effect_global_force_struct_definition },
		{ _field_real_vector_3d, "offset" },
		{ _field_real_vector_3d, "direction (for cylinder forces)" },
		{ _field_terminator }
	};

	#define EMITTERCLIPSPHEREBLOCK_ID { 0xA39A3EB4, 0x759B4A18, 0xBDB69AF7, 0x7511BBDA }
	TAG_BLOCK(
		emitterClipSphereBlock_block,
		"emitterClipSphereBlock",
		1,
		"ParticleEmitterClipSphere",
		EMITTERCLIPSPHEREBLOCK_ID)
	{
		{ _field_real_vector_3d, "offset" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	#define GPU_PROPERTY_BLOCK_ID { 0xA49C0823, 0x46CF4B62, 0xA45B3947, 0x2D11DA0E }
	TAG_BLOCK(
		gpu_property_block,
		"gpu_property_block",
		k_max_gpu_properties,
		"c_particle_emitter_definition::s_gpu_data::s_property",
		GPU_PROPERTY_BLOCK_ID,
		4)
	{
		{ _field_array, "runtime gpu_property_sub_array!", &gpu_property_sub_array },
		{ _field_terminator }
	};

	#define GPU_FUNCTION_BLOCK_ID { 0xE4F4C1FD, 0x776D4521, 0xAACCF4EA, 0x51350BCD }
	TAG_BLOCK(
		gpu_function_block,
		"gpu_function_block",
		k_max_gpu_functions,
		"c_particle_emitter_definition::s_gpu_data::s_function",
		GPU_FUNCTION_BLOCK_ID,
		4)
	{
		{ _field_array, "runtime gpu_function_sub_array!", &gpu_function_sub_array },
		{ _field_terminator }
	};

	#define GPU_COLOR_BLOCK_ID { 0x77A26FFB, 0x0C164319, 0x81E4C4D3, 0x69DC3749 }
	TAG_BLOCK(
		gpu_color_block,
		"gpu_color_block",
		k_max_gpu_colors,
		"c_particle_emitter_definition::s_gpu_data::s_color",
		GPU_COLOR_BLOCK_ID,
		4)
	{
		{ _field_array, "runtime gpu_color_sub_array!", &gpu_color_sub_array },
		{ _field_terminator }
	};

	#define GPU_PROPERTY_SUB_ARRAY_ID { 0x5E56CDB1, 0xEC34402B, 0xBF36EF1D, 0x9B7468BA }
	TAG_ARRAY(
		gpu_property_sub_array,
		"gpu_property_sub_array",
		c_particle_emitter_gpu::_sizeof_gpu_property/sizeof(real),
		"real",
		GPU_PROPERTY_SUB_ARRAY_ID)
	{
		{ _field_real, "runtime gpu_property_real!" },
		{ _field_terminator }
	};

	#define GPU_FUNCTION_SUB_ARRAY_ID { 0xD6260931, 0xE09141A2, 0x984511D9, 0xA3D78599 }
	TAG_ARRAY(
		gpu_function_sub_array,
		"gpu_function_sub_array",
		c_particle_emitter_gpu::_sizeof_gpu_function/sizeof(real),
		"real",
		GPU_FUNCTION_SUB_ARRAY_ID)
	{
		{ _field_real, "runtime gpu_function_real!" },
		{ _field_terminator }
	};

	#define GPU_COLOR_SUB_ARRAY_ID { 0xEBCC1FB0, 0x84F141D4, 0xA584B00F, 0x8EFF6043 }
	TAG_ARRAY(
		gpu_color_sub_array,
		"gpu_color_sub_array",
		c_particle_emitter_gpu::_sizeof_gpu_color/sizeof(real),
		"real",
		GPU_COLOR_SUB_ARRAY_ID)
	{
		{ _field_real, "runtime gpu_color_real!" },
		{ _field_terminator }
	};

	#define GPU_PROPERTY_FUNCTION_COLOR_STRUCT_ID { 0x33DE2336, 0x7C6242C5, 0xAD5A8C31, 0x992C78EA }
	TAG_STRUCT(
		gpu_property_function_color_struct,
		"gpu_property_function_color_struct",
		"c_particle_emitter_definition::s_gpu_data",
		GPU_PROPERTY_FUNCTION_COLOR_STRUCT_ID)
	{
		{ _field_block, "runtime gpu_property_block!", &gpu_property_block },
		{ _field_block, "runtime gpu_functions_block!", &gpu_function_block },
		{ _field_block, "runtime gpu_colors_block!", &gpu_color_block },
		{ _field_terminator }
	};

	STRINGS(coordinate_system_enum)
	{
		"world",
		"local"
	};
	STRING_LIST(coordinate_system_enum, coordinate_system_enum_strings, _countof(coordinate_system_enum_strings));

	STRINGS(particle_system_flags)
	{
		"particles freeze when offscreen",
		"particles continue as usual when offscreen{skip visibility test}{cinematics}",
		"lod always 1.0{ignore lod (render always)}",
		"lod same in splitscreen",
		"disabled in any splitscreen",
		"disabled in 3- and 4-way splitscreen",
		"disabled for debugging",
		"inherit effect velocity",
		"don\'t render system",
		"render when zoomed",
		"force cpu updating{force cpu rendering}",
		"force gpu updating{force gpu rendering}",
		"override near fade (use with caution)",
		"particles die when effect ends{die when orphaned}",
		"use synchronized random seed#synchronized across particle systems",
		"use world orientation#particle system uses local-space position but up is always \'global up\'",
		"render in spawn order#first particle spawned renders first (at the back), last particle spawned renders last (front)",
		"dynamic particle resolution#use distance and multiplier (below) to tune high- or low-res rendering",
		"particles live forever",
		"disable in vision mode",
		"disable velocity",
		"disable when zoomed",
		"continue when offscreen ignores .performance_throttles tag"
	};
	STRING_LIST(particle_system_flags, particle_system_flags_strings, _countof(particle_system_flags_strings));

	STRINGS(emission_shape_enum)
	{
		"sprayer",
		"disc",
		"globe",
		"implode",
		"tube",
		"halo",
		"impact contour",
		"impact area",
		"debris",
		"line",
		"breakable surface",
		"custom points",
		"boat hull surface",
		"cube",
		"cylinder",
		"unweighted line",
		"plane",
		"jetwash",
		"planar orbit",
		"sphere orbit"
	};
	STRING_LIST(emission_shape_enum, emission_shape_enum_strings, _countof(emission_shape_enum_strings));

	STRINGS(emission_axis_enum)
	{
		"constant",
		"cone",
		"disc",
		"globe"
	};
	STRING_LIST(emission_axis_enum, emission_axis_enum_strings, _countof(emission_axis_enum_strings));

	STRINGS(emission_reference_axis_enum)
	{
		"x",
		"y",
		"z"
	};
	STRING_LIST(emission_reference_axis_enum, emission_reference_axis_enum_strings, _countof(emission_reference_axis_enum_strings));

	STRING_LIST(emitter_flags, empty_string_list, 0);

	STRINGS(visible_emitter_flags)
	{
		"volume emitter particle velocities are random#By default, particles emit radially away from the emitter center.  This option gives them random velocity instead.  This only applies to volume emitters."
	};
	STRING_LIST(visible_emitter_flags, visible_emitter_flags_strings, _countof(visible_emitter_flags_strings));

} // namespace macaque

} // namespace blofeld

