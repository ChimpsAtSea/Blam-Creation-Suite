#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		controller_mapping_group,
		CONTROLLER_MAPPING_TAG,
		nullptr,
		INVALID_TAG,
		controller_mapping_block );

	TAG_BLOCK_FROM_STRUCT(
		controller_mapping_block,
		"controller_mapping_block",
		1,
		controller_mapping_struct_definition);

	#define CONTROLLER_MAPPING_STRUCT_DEFINITION_ID { 0x7011BE12, 0xFF694D9C, 0xA21928C1, 0x41187886 }
	TAG_STRUCT_V6(
		controller_mapping_struct_definition,
		"controller_mapping_struct_definition",
		"s_controller_mapping_definition",
		SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CONTROLLER_MAPPING_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "auto zoom out ticks", "set to 0 for instant unzoom on trigger release (trigger style) or 15 for toggle (thumbstick style)" },
		FIELD_EXPLANATION_EX("Start/Back", nullptr, FIELD_FLAG_NONE, "Start and Back buttons are not remappable and do not appear in this list."),
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
		FIELD_SKIP_EX("start", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_SKIP_EX("back", nullptr, FIELD_FLAG_NONE, 2),
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
		{ _field_enum, "hero assist", "aka sprint", &gamepad_button_definition },
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

