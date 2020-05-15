#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(airstrike_battery, AirStrikeDefinition::k_max_airstrike_batteries)
{
	{ _field_real, "launch radius:wu#each shot will be fired with a random offset in this radius in the x/y plane above the target location" },
	{ _field_real, "launch z height:wu#strike will be launched at this plane height above the target location" },
	{ _field_real, "launch warmup:seconds#seconds to wait before launching the strike" },
	{ _field_real, "launch arrival:seconds#seconds to wait until the launch site marker is removed" },
	{ _field_real, "launch cooldown:seconds#seconds to wait before the next launch will be ready" },
	{ _field_real, "launch duration:seconds#how long a launch should take to fire all rounds" },
	{ _field_long_integer, "shots per launch#number of rounds to fire per launch" },
	{ _field_tag_reference, "fire effect#the effect that will be created when the strike fires." },
	{ _field_tag_reference, "fire effect (indoor)#the effect that will be created when the strike fires and is indoors" },
	{ _field_block, "fire offsets", &airstrike_fire_location_block },
	{ _field_terminator },
};

TAG_BLOCK(airstrike_fire_location, s_airstrike_battery_definition::max_fire_locations)
{
	{ _field_real_point_2d, "offset" },
	{ _field_terminator },
};

TAG_GROUP(airstrike, AIRSTRIKE_TAG)
{
	{ _field_block, "batteries", &airstrike_battery_block },
	{ _field_terminator },
};

} // namespace blofeld

