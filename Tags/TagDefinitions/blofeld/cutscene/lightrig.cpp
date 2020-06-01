#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(light_rig, LIGHT_RIG_TAG, light_rig_block_block );

	TAG_BLOCK(directionalLightRigBlock, lightRigDirectionalCount)
	{
		{ _field_long_flags, "Location", &lightRigLocation },
		{ _field_custom, "Theta" },
		{ _field_real, "Theta" },
		{ _field_custom, "Phi" },
		{ _field_real, "Phi" },
		{ _field_real, "Distance from location:" },
		{ _field_tag_reference, "Midnight light", &global_midnight_light_definition_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(light_rig_block, 1, light_rig_struct_definition_struct_definition );

	TAG_BLOCK(scriptableLightRigBlock, e_scriptableLightRigMax)
	{
		{ _field_explanation, "Scriptable Light Rig", "" },
		{ _field_string_id, "string^" },
		{ _field_tag_reference, "light rig", &global_lightRig_reference },
		{ _field_terminator }
	};

	TAG_STRUCT(light_rig_struct_definition)
	{
		{ _field_explanation, "Character Light Rig", "" },
		{ _field_custom, "Environment vmf lobe weight" },
		{ _field_real, "Environment vmf lobe weight" },
		{ _field_real_rgb_color, "Rig fill color" },
		{ _field_custom, "Rig fill scale" },
		{ _field_real, "Rig fill scale" },
		{ _field_block, "Directional light rigs", &directionalLightRigBlock_block },
		{ _field_real_rgb_color, "Rig vmf lobe color" },
		{ _field_custom, "Rig vmf lobe intensity" },
		{ _field_real, "Rig vmf lobe intensity" },
		{ _field_custom, "Rig vmf lobe theta" },
		{ _field_real, "Rig vmf lobe theta" },
		{ _field_custom, "Rig vmf lobe phi" },
		{ _field_real, "Rig vmf lobe phi" },
		{ _field_custom, "Rig vmf lobe scale" },
		{ _field_real, "Rig vmf lobe scale" },
		{ _field_custom, "Rig vmf lobe vs fill scale" },
		{ _field_real, "Rig vmf lobe vs fill scale" },
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

} // namespace blofeld

