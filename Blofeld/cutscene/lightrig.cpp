#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(light_rig_struct_definition)
{
	FIELD( _field_explanation, "Character Light Rig" ),
	FIELD( _field_custom, "Environment vmf lobe weight" ),
	FIELD( _field_real, "Environment vmf lobe weight" ),
	FIELD( _field_real_rgb_color, "Rig fill color" ),
	FIELD( _field_custom, "Rig fill scale" ),
	FIELD( _field_real, "Rig fill scale" ),
	FIELD( _field_block, "Directional light rigs", &directionalLightRigBlock ),
	FIELD( _field_real_rgb_color, "Rig vmf lobe color" ),
	FIELD( _field_custom, "Rig vmf lobe intensity" ),
	FIELD( _field_real, "Rig vmf lobe intensity" ),
	FIELD( _field_custom, "Rig vmf lobe theta" ),
	FIELD( _field_real, "Rig vmf lobe theta" ),
	FIELD( _field_custom, "Rig vmf lobe phi" ),
	FIELD( _field_real, "Rig vmf lobe phi" ),
	FIELD( _field_custom, "Rig vmf lobe scale" ),
	FIELD( _field_real, "Rig vmf lobe scale" ),
	FIELD( _field_custom, "Rig vmf lobe vs fill scale" ),
	FIELD( _field_real, "Rig vmf lobe vs fill scale" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(directionalLightRigBlock, lightRigDirectionalCount)
{
	FIELD( _field_long_flags, "Location" ),
	FIELD( _field_custom, "Theta" ),
	FIELD( _field_real, "Theta" ),
	FIELD( _field_custom, "Phi" ),
	FIELD( _field_real, "Phi" ),
	FIELD( _field_real, "Distance from location:" ),
	FIELD( _field_tag_reference, "Midnight light" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scriptableLightRigBlock, e_scriptableLightRigMax)
{
	FIELD( _field_explanation, "Scriptable Light Rig" ),
	FIELD( _field_string_id, "string^" ),
	FIELD( _field_tag_reference, "light rig" ),
	FIELD( _field_terminator )
};

TAG_GROUP(light_rig_block, LIGHT_RIG_TAG)
{
	FIELD( _field_explanation, "Character Light Rig" ),
	FIELD( _field_custom, "Environment vmf lobe weight" ),
	FIELD( _field_real, "Environment vmf lobe weight" ),
	FIELD( _field_real_rgb_color, "Rig fill color" ),
	FIELD( _field_custom, "Rig fill scale" ),
	FIELD( _field_real, "Rig fill scale" ),
	FIELD( _field_block, "Directional light rigs", &directionalLightRigBlock ),
	FIELD( _field_real_rgb_color, "Rig vmf lobe color" ),
	FIELD( _field_custom, "Rig vmf lobe intensity" ),
	FIELD( _field_real, "Rig vmf lobe intensity" ),
	FIELD( _field_custom, "Rig vmf lobe theta" ),
	FIELD( _field_real, "Rig vmf lobe theta" ),
	FIELD( _field_custom, "Rig vmf lobe phi" ),
	FIELD( _field_real, "Rig vmf lobe phi" ),
	FIELD( _field_custom, "Rig vmf lobe scale" ),
	FIELD( _field_real, "Rig vmf lobe scale" ),
	FIELD( _field_custom, "Rig vmf lobe vs fill scale" ),
	FIELD( _field_real, "Rig vmf lobe vs fill scale" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

