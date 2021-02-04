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
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DIRECTIONALLIGHTRIGBLOCK_ID)
	{
		{ _field_long_flags, "Location", &lightRigLocation },
		FIELD_CUSTOM("Theta", nullptr, _field_id_slider_editor),
		{ _field_real, "Theta", _field_id_slider_editor },
		FIELD_CUSTOM("Phi", nullptr, _field_id_slider_editor),
		{ _field_real, "Phi", _field_id_slider_editor },
		{ _field_real, "Distance from location" },
		{ _field_tag_reference, "Midnight light", &global_midnight_light_definition_reference },
		{ _field_terminator }
	};

	#define SCRIPTABLELIGHTRIGBLOCK_ID { 0x789C5227, 0xB8FC47A1, 0xB56613BE, 0xDDD920CA }
	TAG_BLOCK(
		scriptableLightRigBlock_block,
		"scriptableLightRigBlock",
		e_scriptableLightRigMax,
		"ScriptableLightRig",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCRIPTABLELIGHTRIGBLOCK_ID)
	{
		FIELD_EXPLANATION("Scriptable Light Rig", nullptr, ""),
		{ _field_string_id, "string", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "light rig", &global_lightRig_reference },
		{ _field_terminator }
	};

	#define LIGHT_RIG_STRUCT_DEFINITION_ID { 0x0E085FEC, 0xFF264344, 0x9801B28D, 0xE302AD8D }
	TAG_STRUCT(
		light_rig_struct_definition,
		"light_rig_struct_definition",
		"LightRig",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		LIGHT_RIG_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Character Light Rig", nullptr, ""),
		FIELD_CUSTOM("Environment vmf lobe weight", nullptr, _field_id_slider_editor),
		{ _field_real, "Environment vmf lobe weight", _field_id_slider_editor },
		{ _field_real_rgb_color, "Rig fill color" },
		FIELD_CUSTOM("Rig fill scale", nullptr, _field_id_slider_editor),
		{ _field_real, "Rig fill scale", _field_id_slider_editor },
		{ _field_block, "Directional light rigs", &directionalLightRigBlock_block },
		{ _field_real_rgb_color, "Rig vmf lobe color" },
		FIELD_CUSTOM("Rig vmf lobe intensity", nullptr, _field_id_slider_editor),
		{ _field_real, "Rig vmf lobe intensity", _field_id_slider_editor },
		FIELD_CUSTOM("Rig vmf lobe theta", nullptr, _field_id_slider_editor),
		{ _field_real, "Rig vmf lobe theta", _field_id_slider_editor },
		FIELD_CUSTOM("Rig vmf lobe phi", nullptr, _field_id_slider_editor),
		{ _field_real, "Rig vmf lobe phi", _field_id_slider_editor },
		FIELD_CUSTOM("Rig vmf lobe scale", nullptr, _field_id_slider_editor),
		{ _field_real, "Rig vmf lobe scale", _field_id_slider_editor },
		FIELD_CUSTOM("Rig vmf lobe vs fill scale", nullptr, _field_id_slider_editor),
		{ _field_real, "Rig vmf lobe vs fill scale", _field_id_slider_editor },
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

