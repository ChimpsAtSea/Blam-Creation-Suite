#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(light_rig, LIGHT_RIG_TAG, light_rig_block_block )

TAG_BLOCK_FROM_STRUCT(light_rig_block, 1, light_rig_struct_definition_struct_definition );

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

TAG_STRUCT(light_rig_struct_definition)
{
	FIELD( _field_explanation, "Character Light Rig" ),
	FIELD( _field_custom, "Environment vmf lobe weight" ),
	FIELD( _field_real, "Environment vmf lobe weight" ),
	FIELD( _field_real_rgb_color, "Rig fill color" ),
	FIELD( _field_custom, "Rig fill scale" ),
	FIELD( _field_real, "Rig fill scale" ),
	FIELD( _field_block, "Directional light rigs", &directionalLightRigBlock_block ),
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

