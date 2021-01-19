#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		light_rig_group,
		LIGHT_RIG_TAG,
		nullptr,
		INVALID_TAG,
		light_rig_block );

	TAG_BLOCK_FROM_STRUCT(
		light_rig_block,
		"light_rig_block",
		1,
		light_rig_struct_definition);

	#define DIRECTIONALLIGHTRIGBLOCK_ID { 0x43FD2D59, 0x55BC4E17, 0x93A3350A, 0x7CE1DD69 }
	TAG_BLOCK(
		directionalLightRigBlock_block,
		"directionalLightRigBlock",
		lightRigDirectionalCount,
		"DirectionalLightRig",
		DIRECTIONALLIGHTRIGBLOCK_ID)
	{
		{ _field_long_flags, "Location", &lightRigLocation },
		FIELD_CUSTOM("Theta", _custom_field_slider_editor),
		{ _field_real, "Theta", nullptr, 'sled' },
		FIELD_CUSTOM("Phi", _custom_field_slider_editor),
		{ _field_real, "Phi", nullptr, 'sled' },
		{ _field_real, "Distance from location:" },
		{ _field_tag_reference, "Midnight light", &global_midnight_light_definition_reference },
		{ _field_terminator }
	};

	#define SCRIPTABLELIGHTRIGBLOCK_ID { 0x789C5227, 0xB8FC47A1, 0xB56613BE, 0xDDD920CA }
	TAG_BLOCK(
		scriptableLightRigBlock_block,
		"scriptableLightRigBlock",
		e_scriptableLightRigMax,
		"ScriptableLightRig",
		SCRIPTABLELIGHTRIGBLOCK_ID)
	{
		{ _field_explanation, "Scriptable Light Rig", "" },
		{ _field_string_id, "string^" },
		{ _field_tag_reference, "light rig", &global_lightRig_reference },
		{ _field_terminator }
	};

	#define LIGHT_RIG_STRUCT_DEFINITION_ID { 0x0E085FEC, 0xFF264344, 0x9801B28D, 0xE302AD8D }
	TAG_STRUCT(
		light_rig_struct_definition,
		"light_rig_struct_definition",
		"LightRig",
		LIGHT_RIG_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Character Light Rig", "" },
		FIELD_CUSTOM("Environment vmf lobe weight", _custom_field_slider_editor),
		{ _field_real, "Environment vmf lobe weight", nullptr, 'sled' },
		{ _field_real_rgb_color, "Rig fill color" },
		FIELD_CUSTOM("Rig fill scale", _custom_field_slider_editor),
		{ _field_real, "Rig fill scale", nullptr, 'sled' },
		{ _field_block, "Directional light rigs", &directionalLightRigBlock_block },
		{ _field_real_rgb_color, "Rig vmf lobe color" },
		FIELD_CUSTOM("Rig vmf lobe intensity", _custom_field_slider_editor),
		{ _field_real, "Rig vmf lobe intensity", nullptr, 'sled' },
		FIELD_CUSTOM("Rig vmf lobe theta", _custom_field_slider_editor),
		{ _field_real, "Rig vmf lobe theta", nullptr, 'sled' },
		FIELD_CUSTOM("Rig vmf lobe phi", _custom_field_slider_editor),
		{ _field_real, "Rig vmf lobe phi", nullptr, 'sled' },
		FIELD_CUSTOM("Rig vmf lobe scale", _custom_field_slider_editor),
		{ _field_real, "Rig vmf lobe scale", nullptr, 'sled' },
		FIELD_CUSTOM("Rig vmf lobe vs fill scale", _custom_field_slider_editor),
		{ _field_real, "Rig vmf lobe vs fill scale", nullptr, 'sled' },
		{ _field_terminator }
	};

	STRINGS(lightRigLocation)
	{
		"follow object",
		"position at marker"
	};
	STRING_LIST(lightRigLocation, lightRigLocation_strings, _countof(lightRigLocation_strings));

	TAG_REFERENCE(global_midnight_light_definition_reference, LIGHT_TAG);

	TAG_REFERENCE(global_lightRig_reference, LIGHT_RIG_TAG);

} // namespace macaque

} // namespace blofeld

