#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(cheap_particle_emitter, CHEAP_PARTICLE_EMITTER_TAG, cheap_particle_emitter_block_block )

TAG_GROUP_FROM_BLOCK(cheap_particle_type_library, CHEAP_PARTICLE_TYPE_LIBRARY_TAG, cheap_particle_type_library_block_block )

TAG_BLOCK_FROM_STRUCT(cheap_particle_emitter_block, 1, cheap_particle_emitter_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(cheap_particle_type_library_block, 1, cheap_particle_type_library_struct_definition_struct_definition );

TAG_BLOCK(cheap_particle_type_block, s_cheap_particle_type::k_maximum_types)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_custom, "physics" ),
	FIELD( _field_real, "drag" ),
	FIELD( _field_real, "gravity" ),
	FIELD( _field_real, "turbulence" ),
	FIELD( _field_long_block_index, "turbulence type#the type of turbulence this particle will experience" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "collision" ),
	FIELD( _field_real, "depth_range#depth range over which the particle will collide" ),
	FIELD( _field_real, "elasticity#energy remaining after collision bounce" ),
	FIELD( _field_real, "death#percentage change [0-1] that the particle will die on collision" ),
	FIELD( _field_long_block_index, "change type#the type this particle will change into on collision" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "render" ),
	FIELD( _field_long_enum, "orientation" ),
	FIELD( _field_explanation, "render parameters" ),
	FIELD( _field_real_argb_color, "color0" ),
	FIELD( _field_real, "intensity0" ),
	FIELD( _field_real, "fade start:[0,1]#point in particles lifetime at which fade begins" ),
	FIELD( _field_real_bounds, "size:world units" ),
	FIELD( _field_real, "motion blur stretch#how much the particle stretches as it moves" ),
	FIELD( _field_long_block_index, "texture" ),
	FIELD( _field_real, "texture y scale#scales the texture in the y direction" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cheap_particle_bitmap_reference_block, s_cheap_particle_type_library::k_max_textures)
{
	FIELD( _field_tag_reference, "bitmap^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cheapParticleTurbulenceTypeBlock, CheapParticleTurbulenceType::k_maxTypes)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_tag_reference, "turbulence:texture used to turbulate particles" ),
	FIELD( _field_real, "turb du dt#change in u coordinate over time" ),
	FIELD( _field_real, "turb dv dt#change in v coordinate over time" ),
	FIELD( _field_real, "turb du dp#change in u coordinate per particle" ),
	FIELD( _field_real, "turb dv dp#change in v coordinate per particle" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cheap_particle_emitter_struct_definition)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_word_integer, "version!" ),
	FIELD( _field_real, "spawn rate!:particles per second" ),
	FIELD( _field_explanation, "SPAWN RATE" ),
	FIELD( _field_struct, "spawnrate", &cheap_particle_scalar_object_function_struct_struct_definition ),
	FIELD( _field_explanation, "LOD" ),
	FIELD( _field_real, "distance fade start:world_units#the distance where the number of spawned particles starts to be reduced" ),
	FIELD( _field_real, "distance fade end:world units#the distance where the number of spawned particles is zero" ),
	FIELD( _field_explanation, "TYPES" ),
	FIELD( _field_custom, "types" ),
	FIELD( _field_string_id, "type 0" ),
	FIELD( _field_real, "weight 0" ),
	FIELD( _field_string_id, "type 1" ),
	FIELD( _field_real, "weight 1" ),
	FIELD( _field_string_id, "type 2" ),
	FIELD( _field_real, "weight 2" ),
	FIELD( _field_string_id, "type 3" ),
	FIELD( _field_real, "weight 3" ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "LIFETIME" ),
	FIELD( _field_real_bounds, "lifetime:seconds" ),
	FIELD( _field_explanation, "EMITTER PARAMETERS" ),
	FIELD( _field_tag_reference, "position texture" ),
	FIELD( _field_real, "position scale" ),
	FIELD( _field_real, "position flatten" ),
	FIELD( _field_tag_reference, "velocity texture" ),
	FIELD( _field_real_bounds, "directionality:[0-1]#Blends between a random direction and the forward direction" ),
	FIELD( _field_real_bounds, "speed scale#scales the initial speed of the particle" ),
	FIELD( _field_real_bounds, "subframe offset:frames#spawns particle at subframe time" ),
	FIELD( _field_explanation, "PARTICLE PARAMETERS" ),
	FIELD( _field_real, "rotation randomness:[0-1]#how much the particle is randomly rotated" ),
	FIELD( _field_real, "particle scale modifier:[0-2]#modifies the inherent scale of the particles" ),
	FIELD( _field_explanation, "LIGHTING PARAMETERS" ),
	FIELD( _field_real, "lighting contrast#increase or decrease contrast between bright and dark areas" ),
	FIELD( _field_real, "lighting offset#adjust overall brightness in all areas" ),
	FIELD( _field_real, "lighting min#clamps darkest particles to this exposure" ),
	FIELD( _field_real, "lighting max#clamps brightest particles to this exposure" ),
	FIELD( _field_real_quaternion, "spawn_params0!" ),
	FIELD( _field_real_quaternion, "spawn_params1!" ),
	FIELD( _field_real_quaternion, "spawn_params2!" ),
	FIELD( _field_real_quaternion, "spawn_params3!" ),
	FIELD( _field_real_quaternion, "spawn_params4!" ),
	FIELD( _field_tag_reference, "global type library!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cheap_particle_type_library_struct_definition)
{
	FIELD( _field_custom, "compile" ),
	FIELD( _field_block, "types", &cheap_particle_type_block_block ),
	FIELD( _field_block, "textures", &cheap_particle_bitmap_reference_block_block ),
	FIELD( _field_tag_reference, "random:texture used to generate random values per particle" ),
	FIELD( _field_block, "turbulence types", &cheapParticleTurbulenceTypeBlock_block ),
	FIELD( _field_tag_reference, "type_texture!" ),
	FIELD( _field_tag_reference, "render_texture!" ),
	FIELD( _field_tag_reference, "turbulenceTexture!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(cheap_particle_scalar_object_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

