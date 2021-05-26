#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define BOAT_PHYSICS_DEFINITION_STRUCT_ID { 0x10ACB591, 0xC7CEB2A9, 0xA01201F5, 0xE12ABB68 }
	TAG_STRUCT(
		boat_physics_definition_struct,
		"boat_physics_definition_struct",
		"s_boat_physics_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BOAT_PHYSICS_DEFINITION_STRUCT_ID)
	{
		FIELD_EXPLANATION("water hull physics", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "ground vertical extrusion", "for hull surfaces that drive on ground this is how far we pretend the water is above everything physical" },
		{ _field_terminator }
	};



} // namespace blofeld

