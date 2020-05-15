#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(controller_mapping, CONTROLLER_MAPPING_TAG)
{
	{ _field_long_integer, "auto zoom out ticks#set to 0 for instant unzoom on trigger release (trigger style) or 15 for toggle (thumbstick style)" },
	{ _field_explanation, "Start/Back" },
	{ _field_enum, "jump" },
	{ _field_enum, "switch weapon" },
	{ _field_enum, "contextual action" },
	{ _field_enum, "melee attack" },
	{ _field_enum, "equipment" },
	{ _field_enum, "throw grenade" },
	{ _field_enum, "primary fire" },
	{ _field_enum, "crouch" },
	{ _field_enum, "zoom-zoom scope" },
	{ _field_enum, "switch grenade prev" },
	{ _field_enum, "switch grenade next" },
	{ _field_enum, "secondary fire" },
	{ _field_enum, "tertiary fire" },
	{ _field_enum, "vehicle trick primary" },
	{ _field_enum, "vehicle trick secondary" },
	{ _field_enum, "secondary contextual action" },
	{ _field_enum, "radio message" },
	{ _field_skip, "start", 2 },
	{ _field_skip, "back", 2 },
	{ _field_enum, "lean left" },
	{ _field_enum, "lean right" },
	{ _field_enum, "night vision" },
	{ _field_enum, "accept" },
	{ _field_enum, "cancel" },
	{ _field_enum, "machinima lower weapon" },
	{ _field_enum, "machinima camera enable" },
	{ _field_enum, "machinima camera control" },
	{ _field_enum, "machinima camera debug" },
	{ _field_enum, "lift editor" },
	{ _field_enum, "drop editor" },
	{ _field_enum, "push to talk" },
	{ _field_enum, "cinematic skip" },
	{ _field_enum, "fireteam" },
	{ _field_enum, "regroup" },
	{ _field_enum, "activate minimap" },
	{ _field_enum, "requisition menu" },
	{ _field_enum, "loadout menu" },
	{ _field_enum, "hero assist#aka sprint" },
	{ _field_enum, "ordnance" },
	{ _field_enum, "skip killcam" },
	{ _field_enum, "mantis fire primary" },
	{ _field_enum, "mantis fire secondary" },
	{ _field_enum, "mantis melee attack" },
	{ _field_enum, "mantis crouch" },
	{ _field_terminator },
};

} // namespace blofeld

