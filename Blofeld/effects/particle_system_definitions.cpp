#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(gpu_property_function_color_struct)
{
	FIELD( _field_block, "runtime gpu_property_block!", &gpu_property_block ),
	FIELD( _field_block, "runtime gpu_functions_block!", &gpu_function_block ),
	FIELD( _field_block, "runtime gpu_colors_block!", &gpu_color_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(particle_system_definition_block_new, c_particle_system_definition::k_maximum_particle_systems_per_block)
{
	FIELD( _field_custom ),
	FIELD( _field_char_enum, "priority" ),
	FIELD( _field_pad, "CXAEIHGADNF", 3 ),
	FIELD( _field_tag_reference, "particle" ),
	FIELD( _field_long_block_index, "location" ),
	FIELD( _field_enum, "coordinate system" ),
	FIELD( _field_enum, "environment" ),
	FIELD( _field_enum, "disposition" ),
	FIELD( _field_enum, "camera mode" ),
	FIELD( _field_char_enum, "game mode" ),
	FIELD( _field_pad, "pad0", 1 ),
	FIELD( _field_short_integer, "sort bias#use values between -10 and 10 to move closer and farther from camera (positive is closer)" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real_bounds, "percent velocity to inherit#flag must be checked above" ),
	FIELD( _field_real, "size scale#multiplied by all \"size\" related fields, like scale, velocity, acceleration" ),
	FIELD( _field_real, "camera offset:world units#the particle is pushed away from the camera this distance (can be negative)" ),
	FIELD( _field_custom, "Estimate overdraw threshold" ),
	FIELD( _field_real, "Pixel budget:ms" ),
	FIELD( _field_real, "near fade range:world units#distance beyond cutoff over which particles fade" ),
	FIELD( _field_real, "near fade cutoff:world units#distance in front of camera where fade is complete*" ),
	FIELD( _field_real, "near fade override:world units#distance in front of camera where fade is complete" ),
	FIELD( _field_real, "far fade range:world units#distance before cutoff over which particles fade" ),
	FIELD( _field_real, "far fade cutoff:world units#distance from camera where fade is complete" ),
	FIELD( _field_real, "LOD in distance#" ),
	FIELD( _field_real, "LOD feather in delta#minimum is 0.0001" ),
	FIELD( _field_real, "inverse LOD feather in!" ),
	FIELD( _field_real, "LOD out distance#defaults to 20.0" ),
	FIELD( _field_real, "LOD feather out delta#0 defaults to 5.0, minimum is 0.0001" ),
	FIELD( _field_real, "inverse LOD feather out!" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "emitters", &particle_system_emitter_definition_block ),
	FIELD( _field_real, "runtime max lifespan!" ),
	FIELD( _field_real, "runtime overdraw!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(particle_system_emitter_definition_block, c_particle_system_definition::k_maximum_emitters_per_definition)
{
	FIELD( _field_custom ),
	FIELD( _field_string_id, "emitter name^" ),
	FIELD( _field_custom, "EMITTER SETTINGS|8FAF8D" ),
	FIELD( _field_char_enum, "emission shape" ),
	FIELD( _field_byte_flags, "flags!" ),
	FIELD( _field_byte_flags, "emitter flags" ),
	FIELD( _field_char_enum, "particle axis (for models)" ),
	FIELD( _field_char_enum, "particle reference axis" ),
	FIELD( _field_pad, "Pad0", 3 ),
	FIELD( _field_tag_reference, "custom shape" ),
	FIELD( _field_tag_reference, "boat hull" ),
	FIELD( _field_real, "bounding radius estimate*:world units#used if override is zero" ),
	FIELD( _field_real, "bounding radius override:world units#used if non-zero" ),
	FIELD( _field_real_point_3d, "axis scale#NOTE - setting this will break automatic bounding sphere calculation, you must enter radius manually" ),
	FIELD( _field_real_vector_2d, "uv scrolling:tiles per second" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "translational offset:world units#XYZ controls that offset the emitter\'s origin from the original location", &particle_property_real_point3d_struct_new_struct_definition ),
	FIELD( _field_struct, "relative direction#yaw/pitch that changes the initial rotation of the emitter", &particle_property_real_euler_angles2d_struct_new_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "emission radius:world units#defines the size of the emitter", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "emission angle:degrees#determines the angle at which particles are emitted", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "emission axis angle:degrees#determines the max tilt for particle axis", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "EMISSION SETTINGS|8FAF8D" ),
	FIELD( _field_struct, "particle starting count#number of particles that are spawned at the birth of the effect", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle max count:0=unlimited#max number of particles allowed to exist at one time", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle emission rate:particles per second#number of particles that are spawned every second from the emitters", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle emission per distance:particles per world unit#number of particles that are spawned every world unit of motion from the emitters", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle lifespan:seconds#the number of seconds a particle will live after emission", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "PARTICLE MOTION|8FAF8D" ),
	FIELD( _field_custom, "particle physics template" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "particle movement", &particle_physics_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_block, "particle attractor/repulsor", &emitterGlobalForceBlock ),
	FIELD( _field_block, "particle clip sphere", &emitterClipSphereBlock ),
	FIELD( _field_struct, "particle self-acceleration:world units per second per second", &particle_property_real_vector3d_struct_new_struct_definition ),
	FIELD( _field_struct, "particle initial velocity{particle velocity}:world units per second", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle rotation:.25=90°, .5=180°, 1=360° ... adds to physics", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle initial rotation rate{particle angular velocity}:360 degree rotations per second", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "PARTICLE APPEARANCE|8FAF8D" ),
	FIELD( _field_struct, "particle size:world units", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle scale:multiple of size", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle scale x:multiple of size", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle scale y:multiple of size", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle tint:RGB#controls the overall tint of the particle", &particle_property_color_struct_new_struct_definition ),
	FIELD( _field_struct, "particle alpha", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle alpha black point:0=normal, 1=clamped", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_struct, "particle alpha white point:1=normal, 0=clamped", &particle_property_scalar_struct_new_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_long_integer, "runtime m_constant_per_particle_properties!" ),
	FIELD( _field_long_integer, "runtime m_constant_over_time_properties!" ),
	FIELD( _field_long_integer, "runtime m_used_particle_states!" ),
	FIELD( _field_struct, "runtime m_gpu_data!", &gpu_property_function_color_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emitterGlobalForceBlock, 4)
{
	FIELD( _field_struct, "global force", &effect_global_force_struct_definition_struct_definition ),
	FIELD( _field_real_vector_3d, "offset" ),
	FIELD( _field_real_vector_3d, "direction (for cylinder forces)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(emitterClipSphereBlock, 1)
{
	FIELD( _field_real_vector_3d, "offset" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gpu_property_block, k_max_gpu_properties)
{
	FIELD( _field_array, "runtime gpu_property_sub_array!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gpu_function_block, k_max_gpu_functions)
{
	FIELD( _field_array, "runtime gpu_function_sub_array!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(gpu_color_block, k_max_gpu_colors)
{
	FIELD( _field_array, "runtime gpu_color_sub_array!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

