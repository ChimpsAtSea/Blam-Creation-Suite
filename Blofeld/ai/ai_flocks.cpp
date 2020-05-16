#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(flock, FLOCK_TAG, flock_block_block );

TAG_BLOCK_FROM_STRUCT(flock_block, 1, flock_struct_definition_struct_definition );

TAG_BLOCK(flock_palette_block, k_max_flock_instances_per_map)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(flock_instance_block, k_max_flock_instances_per_map)
{
	FIELD( _field_string_id, "flock name^" ),
	FIELD( _field_short_block_index, "flock definition" ),
	FIELD( _field_short_block_index, "bsp" ),
	FIELD( _field_short_block_index, "bounding volume" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_real, "ecology margin:wus#distance from ecology boundary that creature begins to be repulsed" ),
	FIELD( _field_block, "sources", &flock_source_block_block ),
	FIELD( _field_block, "destinations{sinks}", &flock_destination_block_block ),
	FIELD( _field_real_bounds, "production frequency bounds:boids/sec#How frequently boids are produced at one of the sources (limited by the max boid count)" ),
	FIELD( _field_real_bounds, "scale" ),
	FIELD( _field_real, "source scale to 0 radius:wus#Distance from a source at which the creature scales to full size" ),
	FIELD( _field_real, "sink scale to 0 radius:wus#Distance from a sink at which the creature begins to scale to zero" ),
	FIELD( _field_real, "flock destroy duration:sec#The number of seconds it takes to kill all units in the flock if it gets destroyed" ),
	FIELD( _field_short_block_index, "boid creature" ),
	FIELD( _field_short_block_index, "big battle creature" ),
	FIELD( _field_short_bounds, "boid count" ),
	FIELD( _field_short_block_index, "enemy flock" ),
	FIELD( _field_pad, "post-enemy-flock", 2 ),
	FIELD( _field_real, "enemy flock max target distance" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(flock_source_block, k_max_sources_per_flock)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_flags, "source flags" ),
	FIELD( _field_real_vector_3d, "position" ),
	FIELD( _field_real_euler_angles_2d, "starting yaw, pitch:degrees" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_real, "weight#probability of producing at this source" ),
	FIELD( _field_char_integer, "bsp_index!" ),
	FIELD( _field_byte_integer, "cluster index!" ),
	FIELD( _field_pad, "post-cluster-ref", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(flock_destination_block, k_max_destinations_per_flock)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_long_enum, "type^" ),
	FIELD( _field_real_vector_3d, "position" ),
	FIELD( _field_real, "radius" ),
	FIELD( _field_real, "max destination volume penetration:wu#The farthest the boid will go inside our destination volume" ),
	FIELD( _field_short_block_index, "destination volume" ),
	FIELD( _field_pad, "post-destination-volume", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(flock_struct_definition)
{
	FIELD( _field_explanation, "Simple flocking" ),
	FIELD( _field_real, "forward weight{forward scale}:[0..1]#weight given to boid\'s desire to fly straight ahead" ),
	FIELD( _field_real, "leveling force weight{leveling force scale}:[0..1]#weight given to boids desire to fly level" ),
	FIELD( _field_real, "destination weight{sink scale}:[0..1]#weight given to boid\'s desire to fly towards its sinks" ),
	FIELD( _field_real, "average throttle:[0..1]#throttle at which boids will naturally fly" ),
	FIELD( _field_real, "maximum throttle:[0..1]#maximum throttle applicable" ),
	FIELD( _field_real, "movement weight threshold#The threshold of accumulated weight over which movement occurs" ),
	FIELD( _field_real, "danger radius:wus#distance within which boids will avoid a dangerous object (e.g. the player)" ),
	FIELD( _field_real, "danger weight{danger scale}#weight given to boid\'s desire to avoid danger" ),
	FIELD( _field_real, "target weight{target scale}:[0..1]#weight given to boid\'s desire to attack fly after their target, if they have one" ),
	FIELD( _field_real, "target distance:wus#distance within which we aggressively pursue a target" ),
	FIELD( _field_real, "target delay time:seconds#amount of time we need to be locked onto a target before we might start killing it" ),
	FIELD( _field_real, "target kill chance:chance per second#probability of killing your target in one second" ),
	FIELD( _field_real, "ai destroy chance:chance per second#if targetted by AI, the probability of dying in one second" ),
	FIELD( _field_explanation, "Perlin noise parameters" ),
	FIELD( _field_real, "random offset weight{random offset scale}:[0..1]#weight given to boid\'s random heading offset" ),
	FIELD( _field_real_bounds, "random offset period:seconds" ),
	FIELD( _field_explanation, "Complex Flocking" ),
	FIELD( _field_real, "neighborhood radius:world units#distance within which one boid is affected by another" ),
	FIELD( _field_angle, "perception angle:degrees#angle-from-forward within which one boid can perceive and react to another" ),
	FIELD( _field_real, "avoidance weight{avoidance scale}:[0..1]#weight given to boid\'s desire to avoid collisions with other boids, when within the avoidance radius" ),
	FIELD( _field_real, "avoidance radius:world units#distance that a boid tries to maintain from another" ),
	FIELD( _field_real, "alignment weight{alignment scale}:[0..1]#weight given to boid\'s desire to align itself with neighboring boids" ),
	FIELD( _field_real, "position weight{position scale}:[0..1]#weight given to boid\'s desire to be near flock center" ),
	FIELD( _field_real, "position min radius:wus#distance to flock center beyond which an attracting force is applied" ),
	FIELD( _field_real, "position max radius:wus#distance to flock center at which the maximum attracting force is applied" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

