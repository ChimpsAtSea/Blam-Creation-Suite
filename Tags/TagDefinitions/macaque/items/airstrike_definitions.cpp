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
		AIRSTRIKE_BATTERY_BLOCK_ID)
	{
		{ _field_real, "launch radius:wu#each shot will be fired with a random offset in this radius in the x/y plane above the target location" },
		{ _field_real, "launch z height:wu#strike will be launched at this plane height above the target location" },
		{ _field_real, "launch warmup:seconds#seconds to wait before launching the strike" },
		{ _field_real, "launch arrival:seconds#seconds to wait until the launch site marker is removed" },
		{ _field_real, "launch cooldown:seconds#seconds to wait before the next launch will be ready" },
		{ _field_real, "launch duration:seconds#how long a launch should take to fire all rounds" },
		{ _field_long_integer, "shots per launch#number of rounds to fire per launch" },
		{ _field_tag_reference, "fire effect#the effect that will be created when the strike fires.", &global_effect_reference },
		{ _field_tag_reference, "fire effect (indoor)#the effect that will be created when the strike fires and is indoors", &global_effect_reference },
		{ _field_block, "fire offsets", &airstrike_fire_location_block },
		{ _field_terminator }
	};

	#define AIRSTRIKE_FIRE_LOCATION_BLOCK_ID { 0xE2478600, 0x27BE4DD0, 0x093DEB6C, 0xD71074B3 }
	TAG_BLOCK(
		airstrike_fire_location_block,
		"airstrike_fire_location_block",
		s_airstrike_battery_definition::max_fire_locations,
		"real_point2d",
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
		AIRSTRIKE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "batteries", &airstrike_battery_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

