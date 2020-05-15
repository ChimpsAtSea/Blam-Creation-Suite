#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(cheap_particle_type, s_cheap_particle_type::k_maximum_types)
{
	{ _field_string_id, "name^" },
	{ _field_custom, "physics" },
	{ _field_real, "drag" },
	{ _field_real, "gravity" },
	{ _field_real, "turbulence" },
	{ _field_long_block_index, "turbulence type#the type of turbulence this particle will experience" },
	{ _field_custom },
	{ _field_custom, "collision" },
	{ _field_real, "depth_range#depth range over which the particle will collide" },
	{ _field_real, "elasticity#energy remaining after collision bounce" },
	{ _field_real, "death#percentage change [0-1] that the particle will die on collision" },
	{ _field_long_block_index, "change type#the type this particle will change into on collision" },
	{ _field_custom },
	{ _field_custom, "render" },
	{ _field_long_enum, "orientation" },
	{ _field_explanation, "render parameters" },
	{ _field_real_argb_color, "color0" },
	{ _field_real, "intensity0" },
	{ _field_real, "fade start:[0,1]#point in particles lifetime at which fade begins" },
	{ _field_real_bounds, "size:world units" },
	{ _field_real, "motion blur stretch#how much the particle stretches as it moves" },
	{ _field_long_block_index, "texture" },
	{ _field_real, "texture y scale#scales the texture in the y direction" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(cheap_particle_bitmap_reference, s_cheap_particle_type_library::k_max_textures)
{
	{ _field_tag_reference, "bitmap^" },
	{ _field_terminator },
};

TAG_BLOCK(cheapParticleTurbulenceTypeBlock, CheapParticleTurbulenceType::k_maxTypes)
{
	{ _field_string_id, "name^" },
	{ _field_tag_reference, "turbulence:texture used to turbulate particles" },
	{ _field_real, "turb du dt#change in u coordinate over time" },
	{ _field_real, "turb dv dt#change in v coordinate over time" },
	{ _field_real, "turb du dp#change in u coordinate per particle" },
	{ _field_real, "turb dv dp#change in v coordinate per particle" },
	{ _field_terminator },
};

TAG_GROUP(cheap_particle_emitter, CHEAP_PARTICLE_EMITTER_TAG)
{
	{ _field_word_flags, "flags" },
	{ _field_word_integer, "version!" },
	{ _field_real, "spawn rate!:particles per second" },
	{ _field_explanation, "SPAWN RATE" },
	{ _field_struct, "spawnrate" },
	{ _field_explanation, "LOD" },
	{ _field_real, "distance fade start:world_units#the distance where the number of spawned particles starts to be reduced" },
	{ _field_real, "distance fade end:world units#the distance where the number of spawned particles is zero" },
	{ _field_explanation, "TYPES" },
	{ _field_custom, "types" },
	{ _field_string_id, "type 0" },
	{ _field_real, "weight 0" },
	{ _field_string_id, "type 1" },
	{ _field_real, "weight 1" },
	{ _field_string_id, "type 2" },
	{ _field_real, "weight 2" },
	{ _field_string_id, "type 3" },
	{ _field_real, "weight 3" },
	{ _field_custom },
	{ _field_explanation, "LIFETIME" },
	{ _field_real_bounds, "lifetime:seconds" },
	{ _field_explanation, "EMITTER PARAMETERS" },
	{ _field_tag_reference, "position texture" },
	{ _field_real, "position scale" },
	{ _field_real, "position flatten" },
	{ _field_tag_reference, "velocity texture" },
	{ _field_real_bounds, "directionality:[0-1]#Blends between a random direction and the forward direction" },
	{ _field_real_bounds, "speed scale#scales the initial speed of the particle" },
	{ _field_real_bounds, "subframe offset:frames#spawns particle at subframe time" },
	{ _field_explanation, "PARTICLE PARAMETERS" },
	{ _field_real, "rotation randomness:[0-1]#how much the particle is randomly rotated" },
	{ _field_real, "particle scale modifier:[0-2]#modifies the inherent scale of the particles" },
	{ _field_explanation, "LIGHTING PARAMETERS" },
	{ _field_real, "lighting contrast#increase or decrease contrast between bright and dark areas" },
	{ _field_real, "lighting offset#adjust overall brightness in all areas" },
	{ _field_real, "lighting min#clamps darkest particles to this exposure" },
	{ _field_real, "lighting max#clamps brightest particles to this exposure" },
	{ _field_real_quaternion, "spawn_params0!" },
	{ _field_real_quaternion, "spawn_params1!" },
	{ _field_real_quaternion, "spawn_params2!" },
	{ _field_real_quaternion, "spawn_params3!" },
	{ _field_real_quaternion, "spawn_params4!" },
	{ _field_tag_reference, "global type library!" },
	{ _field_terminator },
};

TAG_GROUP(cheap_particle_type_library, CHEAP_PARTICLE_TYPE_LIBRARY_TAG)
{
	{ _field_custom, "compile" },
	{ _field_block, "types", &cheap_particle_type_block },
	{ _field_block, "textures", &cheap_particle_bitmap_reference_block },
	{ _field_tag_reference, "random:texture used to generate random values per particle" },
	{ _field_block, "turbulence types", &cheapParticleTurbulenceTypeBlock_block },
	{ _field_tag_reference, "type_texture!" },
	{ _field_tag_reference, "render_texture!" },
	{ _field_tag_reference, "turbulenceTexture!" },
	{ _field_terminator },
};

} // namespace blofeld

