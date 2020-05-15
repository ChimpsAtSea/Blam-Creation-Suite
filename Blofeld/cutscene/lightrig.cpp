#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(directionalLightRigBlock, lightRigDirectionalCount)
{
	{ _field_long_flags, "Location" },
	{ _field_custom, "Theta" },
	{ _field_real, "Theta" },
	{ _field_custom, "Phi" },
	{ _field_real, "Phi" },
	{ _field_real, "Distance from location:" },
	{ _field_tag_reference, "Midnight light" },
	{ _field_terminator },
};

TAG_BLOCK(scriptableLightRigBlock, e_scriptableLightRigMax)
{
	{ _field_explanation, "Scriptable Light Rig" },
	{ _field_string_id, "string^" },
	{ _field_tag_reference, "light rig" },
	{ _field_terminator },
};

TAG_GROUP(light_rig, LIGHT_RIG_TAG)
{
	{ _field_explanation, "Character Light Rig" },
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
	{ _field_terminator },
};

} // namespace blofeld

