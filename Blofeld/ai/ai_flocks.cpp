#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(flock_palette, k_max_flock_instances_per_map)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

TAG_BLOCK(flock_instance, k_max_flock_instances_per_map)
{
	{ _field_string_id, "flock name^" },
	{ _field_short_block_index, "flock definition" },
	{ _field_short_block_index, "bsp" },
	{ _field_short_block_index, "bounding volume" },
	{ _field_word_flags, "flags" },
	{ _field_real, "ecology margin:wus#distance from ecology boundary that creature begins to be repulsed" },
	{ _field_block, "sources", &flock_source_block },
	{ _field_block, "destinations{sinks}", &flock_destination_block },
	{ _field_real_bounds, "production frequency bounds:boids/sec#How frequently boids are produced at one of the sources (limited by the max boid count)" },
	{ _field_real_bounds, "scale" },
	{ _field_real, "source scale to 0 radius:wus#Distance from a source at which the creature scales to full size" },
	{ _field_real, "sink scale to 0 radius:wus#Distance from a sink at which the creature begins to scale to zero" },
	{ _field_real, "flock destroy duration:sec#The number of seconds it takes to kill all units in the flock if it gets destroyed" },
	{ _field_short_block_index, "boid creature" },
	{ _field_short_block_index, "big battle creature" },
	{ _field_short_bounds, "boid count" },
	{ _field_short_block_index, "enemy flock" },
	{ _field_pad, "post-enemy-flock", 2 },
	{ _field_real, "enemy flock max target distance" },
	{ _field_terminator },
};

TAG_BLOCK(flock_source, k_max_sources_per_flock)
{
	{ _field_string_id, "name^" },
	{ _field_long_flags, "source flags" },
	{ _field_real_vector_3d, "position" },
	{ _field_real_euler_angles_2d, "starting yaw, pitch:degrees" },
	{ _field_real, "radius" },
	{ _field_real, "weight#probability of producing at this source" },
	{ _field_char_integer, "bsp_index!" },
	{ _field_byte_integer, "cluster index!" },
	{ _field_pad, "post-cluster-ref", 2 },
	{ _field_terminator },
};

TAG_BLOCK(flock_destination, k_max_destinations_per_flock)
{
	{ _field_string_id, "name^" },
	{ _field_long_enum, "type^" },
	{ _field_real_vector_3d, "position" },
	{ _field_real, "radius" },
	{ _field_real, "max destination volume penetration:wu#The farthest the boid will go inside our destination volume" },
	{ _field_short_block_index, "destination volume" },
	{ _field_pad, "post-destination-volume", 2 },
	{ _field_terminator },
};

TAG_GROUP(flock, FLOCK_TAG)
{
	{ _field_explanation, "Simple flocking" },
	{ _field_real, "forward weight{forward scale}:[0..1]#weight given to boid\'s desire to fly straight ahead" },
	{ _field_real, "leveling force weight{leveling force scale}:[0..1]#weight given to boids desire to fly level" },
	{ _field_real, "destination weight{sink scale}:[0..1]#weight given to boid\'s desire to fly towards its sinks" },
	{ _field_real, "average throttle:[0..1]#throttle at which boids will naturally fly" },
	{ _field_real, "maximum throttle:[0..1]#maximum throttle applicable" },
	{ _field_real, "movement weight threshold#The threshold of accumulated weight over which movement occurs" },
	{ _field_real, "danger radius:wus#distance within which boids will avoid a dangerous object (e.g. the player)" },
	{ _field_real, "danger weight{danger scale}#weight given to boid\'s desire to avoid danger" },
	{ _field_real, "target weight{target scale}:[0..1]#weight given to boid\'s desire to attack fly after their target, if they have one" },
	{ _field_real, "target distance:wus#distance within which we aggressively pursue a target" },
	{ _field_real, "target delay time:seconds#amount of time we need to be locked onto a target before we might start killing it" },
	{ _field_real, "target kill chance:chance per second#probability of killing your target in one second" },
	{ _field_real, "ai destroy chance:chance per second#if targetted by AI, the probability of dying in one second" },
	{ _field_explanation, "Perlin noise parameters" },
	{ _field_real, "random offset weight{random offset scale}:[0..1]#weight given to boid\'s random heading offset" },
	{ _field_real_bounds, "random offset period:seconds" },
	{ _field_explanation, "Complex Flocking" },
	{ _field_real, "neighborhood radius:world units#distance within which one boid is affected by another" },
	{ _field_angle, "perception angle:degrees#angle-from-forward within which one boid can perceive and react to another" },
	{ _field_real, "avoidance weight{avoidance scale}:[0..1]#weight given to boid\'s desire to avoid collisions with other boids, when within the avoidance radius" },
	{ _field_real, "avoidance radius:world units#distance that a boid tries to maintain from another" },
	{ _field_real, "alignment weight{alignment scale}:[0..1]#weight given to boid\'s desire to align itself with neighboring boids" },
	{ _field_real, "position weight{position scale}:[0..1]#weight given to boid\'s desire to be near flock center" },
	{ _field_real, "position min radius:wus#distance to flock center beyond which an attracting force is applied" },
	{ _field_real, "position max radius:wus#distance to flock center at which the maximum attracting force is applied" },
	{ _field_terminator },
};

} // namespace blofeld

