#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		airstrike_group,
		AIRSTRIKE_TAG,
		nullptr,
		INVALID_TAG,
		airstrike_block );

	TAG_BLOCK_FROM_STRUCT(
		airstrike_block,
		"airstrike_block",
		1,
		airstrike_struct_definition);

	#define AIRSTRIKE_BATTERY_BLOCK_ID { 0xE2478600, 0x27BE4DD0, 0x9B3DEB6C, 0xD71074B3 }
	TAG_BLOCK(
		airstrike_battery_block,
		"airstrike_battery_block",
		AirStrikeDefinition::k_max_airstrike_batteries,
		"s_airstrike_battery_definition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AIRSTRIKE_BATTERY_BLOCK_ID)
	{
		{ _field_real, "launch radius", "each shot will be fired with a random offset in this radius in the x/y plane above the target location", "wu" },
		{ _field_real, "launch z height", "strike will be launched at this plane height above the target location", "wu" },
		{ _field_real, "launch warmup", "seconds to wait before launching the strike", "seconds" },
		{ _field_real, "launch arrival", "seconds to wait until the launch site marker is removed", "seconds" },
		{ _field_real, "launch cooldown", "seconds to wait before the next launch will be ready", "seconds" },
		{ _field_real, "launch duration", "how long a launch should take to fire all rounds", "seconds" },
		{ _field_long_integer, "shots per launch", "number of rounds to fire per launch" },
		{ _field_tag_reference, "fire effect", &global_effect_reference },
		{ _field_tag_reference, "fire effect (indoor)", &global_effect_reference },
		{ _field_block, "fire offsets", &airstrike_fire_location_block },
		{ _field_terminator }
	};

	#define AIRSTRIKE_FIRE_LOCATION_BLOCK_ID { 0xE2478600, 0x27BE4DD0, 0x093DEB6C, 0xD71074B3 }
	TAG_BLOCK(
		airstrike_fire_location_block,
		"airstrike_fire_location_block",
		s_airstrike_battery_definition::max_fire_locations,
		"real_point2d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AIRSTRIKE_FIRE_LOCATION_BLOCK_ID)
	{
		{ _field_real_point_2d, "offset" },
		{ _field_terminator }
	};

	#define AIRSTRIKE_STRUCT_DEFINITION_ID { 0x74418E97, 0x4B464172, 0xBA070FC0, 0x21EC279C }
	TAG_STRUCT(
		airstrike_struct_definition,
		"airstrike_struct_definition",
		"AirStrikeDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AIRSTRIKE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "batteries", &airstrike_battery_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

