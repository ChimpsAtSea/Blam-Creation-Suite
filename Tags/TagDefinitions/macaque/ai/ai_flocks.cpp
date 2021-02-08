#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		flock_group,
		FLOCK_TAG,
		nullptr,
		INVALID_TAG,
		flock_block );

	TAG_BLOCK_FROM_STRUCT(
		flock_block,
		"flock_block",
		1,
		flock_struct_definition);

	#define FLOCK_PALETTE_BLOCK_ID { 0xCCF2B116, 0x70BD49A2, 0x8CE686B1, 0xB579473F }
	TAG_BLOCK(
		flock_palette_block,
		"flock_palette_block",
		k_max_flock_instances_per_map,
		"s_flock_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLOCK_PALETTE_BLOCK_ID)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &flock_reference },
		{ _field_terminator }
	};

	#define FLOCK_INSTANCE_BLOCK_ID { 0x5CBA5AB0, 0x8CE54E4B, 0xA721F105, 0xB30B5958 }
	TAG_BLOCK(
		flock_instance_block,
		"flock_instance_block",
		k_max_flock_instances_per_map,
		"s_flock_instance",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		FLOCK_INSTANCE_BLOCK_ID)
	{
		{ _field_string_id, "flock name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "flock definition", &flock_palette_block },
		{ _field_short_block_index, "bsp", &scenario_structure_bsp_reference_block },
		{ _field_short_block_index, "bounding volume", &scenario_trigger_volume_block },
		{ _field_word_flags, "flags", &flock_flags },
		{ _field_real, "ecology margin", "distance from ecology boundary that creature begins to be repulsed", "wus" },
		{ _field_block, "sources", &flock_source_block },
		{ _field_block, "destinations", &flock_destination_block },
		{ _field_real_bounds, "production frequency bounds", "How frequently boids are produced at one of the sources (limited by the max boid count)", "boids/sec" },
		{ _field_real_bounds, "scale" },
		{ _field_real, "source scale to 0 radius", "Distance from a source at which the creature scales to full size", "wus" },
		{ _field_real, "sink scale to 0 radius", "Distance from a sink at which the creature begins to scale to zero", "wus" },
		{ _field_real, "flock destroy duration", "The number of seconds it takes to kill all units in the flock if it gets destroyed", "sec" },
		{ _field_short_block_index, "boid creature", &scenario_creature_palette_block },
		{ _field_short_block_index, "big battle creature", &big_battle_creature_palette_block },
		{ _field_short_bounds, "boid count" },
		{ _field_short_block_index, "enemy flock", &flock_instance_block },
		FIELD_PAD("post-enemy-flock", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "enemy flock max target distance" },
		{ _field_terminator }
	};

	#define FLOCK_SOURCE_BLOCK_ID { 0x2BFCB061, 0x9A1B4921, 0x890FF041, 0xA74697FE }
	TAG_BLOCK(
		flock_source_block,
		"flock_source_block",
		k_max_sources_per_flock,
		"s_flock_source",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLOCK_SOURCE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_flags, "source flags", &flock_source_flags },
		{ _field_real_vector_3d, "position" },
		{ _field_real_euler_angles_2d, "starting yaw, pitch", nullptr, "degrees" },
		{ _field_real, "radius" },
		{ _field_real, "weight", "probability of producing at this source" },
		{ _field_char_integer, "bsp_index", FIELD_FLAG_UNKNOWN0 },
		{ _field_byte_integer, "cluster index", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("post-cluster-ref", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define FLOCK_DESTINATION_BLOCK_ID { 0xD589E46E, 0x232B452B, 0x903E75E4, 0x6F72DBA3 }
	TAG_BLOCK(
		flock_destination_block,
		"flock_destination_block",
		k_max_destinations_per_flock,
		"s_flock_destination",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLOCK_DESTINATION_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_enum, "type", FIELD_FLAG_INDEX, &destination_type_enum },
		{ _field_real_vector_3d, "position" },
		{ _field_real, "radius" },
		{ _field_real, "max destination volume penetration", "The farthest the boid will go inside our destination volume", "wu" },
		{ _field_short_block_index, "destination volume", &scenario_trigger_volume_block },
		FIELD_PAD("post-destination-volume", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define FLOCK_STRUCT_DEFINITION_ID { 0xF0130A08, 0xA0EF4DC7, 0xA0CA92E4, 0xBC18D80B }
	TAG_STRUCT(
		flock_struct_definition,
		"flock_struct_definition",
		"s_flock_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		FLOCK_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Simple flocking", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "forward weight", "weight given to boid's desire to fly straight ahead" },
		{ _field_real, "leveling force weight", "weight given to boids desire to fly level" },
		{ _field_real, "destination weight", "weight given to boid's desire to fly towards its sinks" },
		{ _field_real, "average throttle", "throttle at which boids will naturally fly" },
		{ _field_real, "maximum throttle", "maximum throttle applicable" },
		{ _field_real, "movement weight threshold", "The threshold of accumulated weight over which movement occurs" },
		{ _field_real, "danger radius", "distance within which boids will avoid a dangerous object (e.g. the player)", "wus" },
		{ _field_real, "danger weight", "weight given to boid's desire to avoid danger" },
		{ _field_real, "target weight", "weight given to boid's desire to attack fly after their target, if they have one" },
		{ _field_real, "target distance", "distance within which we aggressively pursue a target", "wus" },
		{ _field_real, "target delay time", "amount of time we need to be locked onto a target before we might start killing it", "seconds" },
		{ _field_real, "target kill chance", "probability of killing your target in one second", "chance per second" },
		{ _field_real, "ai destroy chance", "if targetted by AI, the probability of dying in one second", "chance per second" },
		FIELD_EXPLANATION("Perlin noise parameters", nullptr, FIELD_FLAG_NONE, "Recommended initial values: \n\trandom offset scale= 0.2 \n\toffset period bounds= 1, 3"),
		{ _field_real, "random offset weight", "weight given to boid's random heading offset" },
		{ _field_real_bounds, "random offset period", nullptr, "seconds" },
		FIELD_EXPLANATION("Complex Flocking", nullptr, FIELD_FLAG_NONE, "WARNING: In flocks with a neighborhood radius of 0, creatures are not influenced by the other creatures around them. THESE ARE MUCH CHEAPER.\n"),
		{ _field_real, "neighborhood radius", "distance within which one boid is affected by another", "world units" },
		{ _field_angle, "perception angle", "angle-from-forward within which one boid can perceive and react to another", "degrees" },
		{ _field_real, "avoidance weight", "weight given to boid's desire to avoid collisions with other boids, when within the avoidance radius" },
		{ _field_real, "avoidance radius", "distance that a boid tries to maintain from another", "world units" },
		{ _field_real, "alignment weight", "weight given to boid's desire to align itself with neighboring boids" },
		{ _field_real, "position weight", "weight given to boid's desire to be near flock center" },
		{ _field_real, "position min radius", "distance to flock center beyond which an attracting force is applied", "wus" },
		{ _field_real, "position max radius", "distance to flock center at which the maximum attracting force is applied", "wus" },
		{ _field_terminator }
	};

	STRINGS(flock_source_flags)
	{
		"ground source"
	};
	STRING_LIST(flock_source_flags, flock_source_flags_strings, _countof(flock_source_flags_strings));

	STRINGS(destination_type_enum)
	{
		"sink",
		"front",
		"circle"
	};
	STRING_LIST(destination_type_enum, destination_type_enum_strings, _countof(destination_type_enum_strings));

	STRINGS(flock_flags)
	{
		"not initially created",
		"hard boundaries on volume",
		"flock initially stopped",
		"flock initially perched",
		"one creature per source",
		"scared by AI",
		"creatures respect kill volumes",
		"big battle squad"
	};
	STRING_LIST(flock_flags, flock_flags_strings, _countof(flock_flags_strings));

} // namespace macaque

} // namespace blofeld

