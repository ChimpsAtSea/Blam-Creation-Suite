#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BOAT_ENGINE_DEFINITION_BLOCK_ID { 0x0ABDB591, 0xC7DE0129, 0x9087807F, 0xE1AB4B36 }
	TAG_BLOCK(
		boat_engine_definition_block,
		"boat_engine_definition_block",
		1,
		"s_boat_engine_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		BOAT_ENGINE_DEFINITION_BLOCK_ID)
	{
		{ _field_byte_flags, "flags", &boat_flags },
		FIELD_PAD("blah", nullptr, 3),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_marker),
		{ _field_string_id, "propeller marker name" },
		{ _field_real_fraction, "out of water thrust scale" },
		{ _field_real_fraction, "out of water torque scale" },
		{ _field_real, "propeller radius", "used to interpolate out-of-water thrust", "wu" },
		{ _field_real, "propeller torque scale", "(fake physics mode only)\nScale value for pitch when thrusting" },
		{ _field_real, "reverse linear acceleration" },
		{ _field_real, "linear acceleration" },
		{ _field_real, "angular acceleration" },
		FIELD_EXPLANATION("Stabilization", nullptr, ""),
		{ _field_angle, "stabilization angular acceleration", "how quickly the boat can accelerate to the desired orientation", "deg/s/s" },
		{ _field_angle, "stabilization desired inclination", "how far pitched back the boat tries to achieve (0 is perfectly flat)", "deg" },
		FIELD_EXPLANATION("drag", nullptr, ""),
		{ _field_real, "drag input range velocity", "wu/s" },
		{ _field_struct, "normal drag", &scalar_function_named_struct },
		{ _field_struct, "boost drag", &scalar_function_named_struct },
		{ _field_struct, "air drag", &scalar_function_named_struct },
		{ _field_terminator }
	};

	STRINGS(boat_flags$2)
	{
		"uses fake physics"
	};
	STRING_LIST(boat_flags$2, boat_flags$2_strings, _countof(boat_flags$2_strings));

} // namespace macaque

} // namespace blofeld

