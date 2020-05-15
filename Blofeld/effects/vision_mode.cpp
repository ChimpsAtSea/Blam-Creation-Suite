#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(visionModeScreenPassBlock, VisionModeScreenPass::k_maxCount)
{
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(visionModeEnvironmentPassBlock, VisionModeEnvironmentPass::k_maxCount)
{
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(visionModeBipedPassesBlock, VisionModeBipedPasses::k_maxCount)
{
	{ _field_long_flags, "flags" },
	{ _field_real, "max radius" },
	{ _field_real, "falloff begin radius#between this and max radius, we go smoothly from on to off" },
	{ _field_real, "motion sensor inactive fade time#if \"linked to motion sensor\" is checked, this is how long it takes to fade after you stop activity" },
	{ _field_real, "active camo visible velocity#if a unit has active camo and is moving faster than this, it will be shown" },
	{ _field_block, "biped passes", &visionModeBipedPassBlock_block },
	{ _field_block, "biped threat values (optional)", &visionModeBipedThreatBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(visionModeBipedPassBlock, VisionModeBipedPass::k_maxCount)
{
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "render for" },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(visionModeBipedThreatBlock, VisionModeBipedThreat::k_maxCount)
{
	{ _field_real, "threat per kill" },
	{ _field_real, "threat per death#can be negative" },
	{ _field_real, "threat per weapon scariness point#keys off the \"AI scariness\" field of each weapon" },
	{ _field_real_bounds, "min/max threat range#below/above these values are pinned" },
	{ _field_terminator },
};

TAG_BLOCK(visionModeOrdnanceVehiclePassBlock, VisionModeOrdnanceVehiclePass::k_maxCount)
{
	{ _field_block, "vehicle types", &visionModeOrdnanceVehicleTypeBlock_block },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(visionModeOrdnanceVehicleTypeBlock, VisionModeOrdnanceVehicleType::k_maxCount)
{
	{ _field_tag_reference, "vehicle type" },
	{ _field_tag_reference, "icon" },
	{ _field_real_vector_2d, "icon size" },
	{ _field_terminator },
};

TAG_BLOCK(visionModeOrdnanceCrosshairBlock, VisionModeOrdnanceCrosshair::k_maxCount)
{
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(vision_mode, VISION_MODE_TAG)
{
	{ _field_long_flags, "flags" },
	{ _field_real, "disabled lighting transparent exposure boost" },
	{ _field_block, "screen pass", &visionModeScreenPassBlock_block },
	{ _field_block, "environment pass", &visionModeEnvironmentPassBlock_block },
	{ _field_block, "biped passes", &visionModeBipedPassesBlock_block },
	{ _field_block, "ordnance vehicle pass", &visionModeOrdnanceVehiclePassBlock_block },
	{ _field_block, "ordnance crosshair", &visionModeOrdnanceCrosshairBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

