#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(custom_damage_response_label, 8)
{
	FIELD( _field_string_id, "custom label#label used to control what damage response will fire.^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_effect_sound, 4)
{
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_word_flags, "damage types" ),
	FIELD( _field_word_flags, "object types" ),
	FIELD( _field_terminator )
};

TAG_GROUP(damage_effect, DAMAGE_EFFECT_TAG)
{
	FIELD( _field_tag_reference, "area of effect behavior equipment#if a reference is here, area of effect damage will attach the equipment to the target" ),
	FIELD( _field_real_bounds, "radius:world units" ),
	FIELD( _field_real_fraction, "cutoff scale:[0,1]" ),
	FIELD( _field_long_flags, "effect flags" ),
	FIELD( _field_explanation, "damage" ),
	FIELD( _field_enum, "side effect" ),
	FIELD( _field_enum, "category" ),
	FIELD( _field_long_enum, "death vocalization" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "secondary flags" ),
	FIELD( _field_real, "headshot damage multiplier#ignored if zero or if headshot flag is not set above; \notherwise, makes headshot not instantly lethal, but multiplies damage done to head by this much.  \n2 does 2x damage to head for headshot.  note that head still has different health than body." ),
	FIELD( _field_real, "AOE core radius:world units#if >0 then higher fidelity obstruction collision checks are preformed. This field has no other ramifications." ),
	FIELD( _field_real, "damage lower bound" ),
	FIELD( _field_real_bounds, "damage upper bound" ),
	FIELD( _field_struct, "damage falloff function" ),
	FIELD( _field_angle, "dmg inner cone angle" ),
	FIELD( _field_struct, "blah" ),
	FIELD( _field_real, "active camouflage damage:[0,1]#how much more visible this damage makes a player who is active camouflaged" ),
	FIELD( _field_real, "stun:[0,1]#amount of stun added to damaged unit" ),
	FIELD( _field_real, "maximum stun:[0,1]#damaged unit\'s stun will never exceed this amount" ),
	FIELD( _field_real, "stun time:seconds#duration of stun due to this damage" ),
	FIELD( _field_long_integer, "damage stun:ticks#how long we stun recovering current body damage" ),
	FIELD( _field_real, "instantaneous acceleration:[0,+inf]" ),
	FIELD( _field_real, "alt instantaneous acceleration:[0,+inf]#This field can be used for an alternative acceleration if the corresponding flags are set, e.g. check vehicle->flags.vehicle wants reduced weapon impulse when airborne" ),
	FIELD( _field_real, "acceleration cap#set to zero to disable cap" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_useless_pad ),
	FIELD( _field_explanation, "DEPRECATED - rider damage scales" ),
	FIELD( _field_real, "rider direct damage scale" ),
	FIELD( _field_real, "rider maximum transfer damage scale" ),
	FIELD( _field_real, "rider minimum transfer damage scale" ),
	FIELD( _field_real, "vehicle damage multiplier" ),
	FIELD( _field_real_fraction, "soft ping pain screen scale:[0,1]#The maximum amount to apply the pain screen pose overlay" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_string_id, "general_damage" ),
	FIELD( _field_string_id, "specific_damage" ),
	FIELD( _field_block, "custom response labels", &custom_damage_response_label_block ),
	FIELD( _field_real, "AI stun radius:world units" ),
	FIELD( _field_real_bounds, "AI stun bounds:(0-1)" ),
	FIELD( _field_real, "shake radius" ),
	FIELD( _field_real, "EMP radius" ),
	FIELD( _field_real, "aoe spike radius" ),
	FIELD( _field_real, "aoe spike damage bump" ),
	FIELD( _field_real, "shield render effects scale" ),
	FIELD( _field_long_integer, "stasis time:ticks#duration of stasis due to this damage, zero disables" ),
	FIELD( _field_real, "stasis time dilation" ),
	FIELD( _field_real, "stasis max biped turning rate" ),
	FIELD( _field_real, "stasis gravity multiplier" ),
	FIELD( _field_real, "equipment hack time:seconds" ),
	FIELD( _field_explanation, "if \'Apply Tree Of Life\'" ),
	FIELD( _field_real, "tree_of_life shield regen modifier#regen velocity of TOL:if non-1.0 this overrides any \'shield recharge rate\' trait" ),
	FIELD( _field_real, "minimum shield level:[0, 1]#when hit, shield will be reset to this percentage of full strength if it is below" ),
	FIELD( _field_real, "shield stun time:seconds#time after damage applied before shield recharges" ),
	FIELD( _field_real, "minimum health level:[0, 1]#when hit, health will be reset to this percentage of full health if it is below" ),
	FIELD( _field_real, "health stun time:seconds#time after damage applied before health recharges" ),
	FIELD( _field_real, "minimum energy level:[0, 1]#like above, TOL reset minimum equipment energy to this" ),
	FIELD( _field_real, "maximum energy level:[0, 1]#cap equipment energy to this" ),
	FIELD( _field_real, "equipment stun time:seconds#time after damage applied before equipment recharges" ),
	FIELD( _field_explanation, "Modifies TOL logic so that (above) unstun will only happen if (below) minimum stun time has passed" ),
	FIELD( _field_real, "shield minimum stun time:seconds" ),
	FIELD( _field_real, "health minimum stun time:seconds" ),
	FIELD( _field_explanation, "damage response" ),
	FIELD( _field_tag_reference, "damage response" ),
	FIELD( _field_explanation, "sound" ),
	FIELD( _field_tag_reference, "old melee sound{sound}" ),
	FIELD( _field_block, "damage sounds", &damage_effect_sound_block ),
	FIELD( _field_useless_pad ),
	FIELD( _field_explanation, "breaking effect" ),
	FIELD( _field_real, "forward velocity:world units per second" ),
	FIELD( _field_real, "forward radius:world units" ),
	FIELD( _field_real, "forward exponent" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_real, "outward velocity:world units per second" ),
	FIELD( _field_real, "outward radius:world units" ),
	FIELD( _field_real, "outward exponent" ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

} // namespace blofeld

