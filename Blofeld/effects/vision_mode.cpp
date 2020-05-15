#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(visionModeScreenPassBlock, VisionModeScreenPass::k_maxCount)
{
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeEnvironmentPassBlock, VisionModeEnvironmentPass::k_maxCount)
{
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeBipedPassesBlock, VisionModeBipedPasses::k_maxCount)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "max radius" ),
	FIELD( _field_real, "falloff begin radius#between this and max radius, we go smoothly from on to off" ),
	FIELD( _field_real, "motion sensor inactive fade time#if \"linked to motion sensor\" is checked, this is how long it takes to fade after you stop activity" ),
	FIELD( _field_real, "active camo visible velocity#if a unit has active camo and is moving faster than this, it will be shown" ),
	FIELD( _field_block, "biped passes", &visionModeBipedPassBlock_block ),
	FIELD( _field_block, "biped threat values (optional)", &visionModeBipedThreatBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeBipedPassBlock, VisionModeBipedPass::k_maxCount)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "render for" ),
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeBipedThreatBlock, VisionModeBipedThreat::k_maxCount)
{
	FIELD( _field_real, "threat per kill" ),
	FIELD( _field_real, "threat per death#can be negative" ),
	FIELD( _field_real, "threat per weapon scariness point#keys off the \"AI scariness\" field of each weapon" ),
	FIELD( _field_real_bounds, "min/max threat range#below/above these values are pinned" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeOrdnanceVehiclePassBlock, VisionModeOrdnanceVehiclePass::k_maxCount)
{
	FIELD( _field_block, "vehicle types", &visionModeOrdnanceVehicleTypeBlock_block ),
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeOrdnanceVehicleTypeBlock, VisionModeOrdnanceVehicleType::k_maxCount)
{
	FIELD( _field_tag_reference, "vehicle type" ),
	FIELD( _field_tag_reference, "icon" ),
	FIELD( _field_real_vector_2d, "icon size" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(visionModeOrdnanceCrosshairBlock, VisionModeOrdnanceCrosshair::k_maxCount)
{
	FIELD( _field_custom, "material" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "actual material\?" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP(vision_mode, VISION_MODE_TAG)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real, "disabled lighting transparent exposure boost" ),
	FIELD( _field_block, "screen pass", &visionModeScreenPassBlock_block ),
	FIELD( _field_block, "environment pass", &visionModeEnvironmentPassBlock_block ),
	FIELD( _field_block, "biped passes", &visionModeBipedPassesBlock_block ),
	FIELD( _field_block, "ordnance vehicle pass", &visionModeOrdnanceVehiclePassBlock_block ),
	FIELD( _field_block, "ordnance crosshair", &visionModeOrdnanceCrosshairBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

