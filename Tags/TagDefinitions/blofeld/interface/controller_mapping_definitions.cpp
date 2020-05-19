#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(controller_mapping, CONTROLLER_MAPPING_TAG, controller_mapping_block_block );

	TAG_BLOCK_FROM_STRUCT(controller_mapping_block, 1, controller_mapping_struct_definition_struct_definition );

	TAG_STRUCT(controller_mapping_struct_definition)
	{
		{ _field_long_integer, "auto zoom out ticks#set to 0 for instant unzoom on trigger release (trigger style) or 15 for toggle (thumbstick style)" },
		{ _field_explanation, "Start/Back" },
		{ _field_enum, "jump", &gamepad_button_definition },
		{ _field_enum, "switch weapon", &gamepad_button_definition },
		{ _field_enum, "contextual action", &gamepad_button_definition },
		{ _field_enum, "melee attack", &gamepad_button_definition },
		{ _field_enum, "equipment", &gamepad_button_definition },
		{ _field_enum, "throw grenade", &gamepad_button_definition },
		{ _field_enum, "primary fire", &gamepad_button_definition },
		{ _field_enum, "crouch", &gamepad_button_definition },
		{ _field_enum, "zoom-zoom scope", &gamepad_button_definition },
		{ _field_enum, "switch grenade prev", &gamepad_button_definition },
		{ _field_enum, "switch grenade next", &gamepad_button_definition },
		{ _field_enum, "secondary fire", &gamepad_button_definition },
		{ _field_enum, "tertiary fire", &gamepad_button_definition },
		{ _field_enum, "vehicle trick primary", &gamepad_button_definition },
		{ _field_enum, "vehicle trick secondary", &gamepad_button_definition },
		{ _field_enum, "secondary contextual action", &gamepad_button_definition },
		{ _field_enum, "radio message", &gamepad_button_definition },
		{ _field_skip, "start", 2 },
		{ _field_skip, "back", 2 },
		{ _field_enum, "lean left", &gamepad_button_definition },
		{ _field_enum, "lean right", &gamepad_button_definition },
		{ _field_enum, "night vision", &gamepad_button_definition },
		{ _field_enum, "accept", &gamepad_button_definition },
		{ _field_enum, "cancel", &gamepad_button_definition },
		{ _field_enum, "machinima lower weapon", &gamepad_button_definition },
		{ _field_enum, "machinima camera enable", &gamepad_button_definition },
		{ _field_enum, "machinima camera control", &gamepad_button_definition },
		{ _field_enum, "machinima camera debug", &gamepad_button_definition },
		{ _field_enum, "lift editor", &gamepad_button_definition },
		{ _field_enum, "drop editor", &gamepad_button_definition },
		{ _field_enum, "push to talk", &gamepad_button_definition },
		{ _field_enum, "cinematic skip", &gamepad_button_definition },
		{ _field_enum, "fireteam", &gamepad_button_definition },
		{ _field_enum, "regroup", &gamepad_button_definition },
		{ _field_enum, "activate minimap", &gamepad_button_definition },
		{ _field_enum, "requisition menu", &gamepad_button_definition },
		{ _field_enum, "loadout menu", &gamepad_button_definition },
		{ _field_enum, "hero assist#aka sprint", &gamepad_button_definition },
		{ _field_enum, "ordnance", &gamepad_button_definition },
		{ _field_enum, "skip killcam", &gamepad_button_definition },
		{ _field_enum, "mantis fire primary", &gamepad_button_definition },
		{ _field_enum, "mantis fire secondary", &gamepad_button_definition },
		{ _field_enum, "mantis melee attack", &gamepad_button_definition },
		{ _field_enum, "mantis crouch", &gamepad_button_definition },
		{ _field_terminator }
	};

	STRINGS(gamepad_button_definition)
	{
		"left trigger",
		"right trigger",
		"dpad up",
		"dpad down",
		"dpad left",
		"dpad right",
		"start",
		"back",
		"left thumb",
		"right thumb",
		"button a",
		"button b",
		"button x",
		"button y",
		"left bumper",
		"right bumper"
	};
	STRING_LIST(gamepad_button_definition, gamepad_button_definition_strings, _countof(gamepad_button_definition_strings));

	TAG_REFERENCE(global_controller_mapping_reference, CONTROLLER_MAPPING_TAG);

} // namespace blofeld

