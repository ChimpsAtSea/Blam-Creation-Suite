#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(airstrike_struct_definition)
{
	FIELD( _field_block, "batteries", &airstrike_battery_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(airstrike_battery_block, AirStrikeDefinition::k_max_airstrike_batteries)
{
	FIELD( _field_real, "launch radius:wu#each shot will be fired with a random offset in this radius in the x/y plane above the target location" ),
	FIELD( _field_real, "launch z height:wu#strike will be launched at this plane height above the target location" ),
	FIELD( _field_real, "launch warmup:seconds#seconds to wait before launching the strike" ),
	FIELD( _field_real, "launch arrival:seconds#seconds to wait until the launch site marker is removed" ),
	FIELD( _field_real, "launch cooldown:seconds#seconds to wait before the next launch will be ready" ),
	FIELD( _field_real, "launch duration:seconds#how long a launch should take to fire all rounds" ),
	FIELD( _field_long_integer, "shots per launch#number of rounds to fire per launch" ),
	FIELD( _field_tag_reference, "fire effect#the effect that will be created when the strike fires." ),
	FIELD( _field_tag_reference, "fire effect (indoor)#the effect that will be created when the strike fires and is indoors" ),
	FIELD( _field_block, "fire offsets", &airstrike_fire_location_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(airstrike_fire_location_block, s_airstrike_battery_definition::max_fire_locations)
{
	FIELD( _field_real_point_2d, "offset" ),
	FIELD( _field_terminator )
};

TAG_GROUP(airstrike_block, AIRSTRIKE_TAG)
{
	FIELD( _field_block, "batteries", &airstrike_battery_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

