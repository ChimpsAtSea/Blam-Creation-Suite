#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(vision_mode, VISION_MODE_TAG, vision_mode_block_block );

	TAG_BLOCK(visionModeScreenPassBlock, VisionModeScreenPass::k_maxCount)
	{
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeEnvironmentPassBlock, VisionModeEnvironmentPass::k_maxCount)
	{
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeBipedPassBlock, VisionModeBipedPass::k_maxCount)
	{
		{ _field_long_flags, "flags", &visionModeBipedPassFlags },
		{ _field_long_flags, "render for", &visionModeBipedTeamTypes },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeBipedThreatBlock, VisionModeBipedThreat::k_maxCount)
	{
		{ _field_real, "threat per kill" },
		{ _field_real, "threat per death#can be negative" },
		{ _field_real, "threat per weapon scariness point#keys off the \"AI scariness\" field of each weapon" },
		{ _field_real_bounds, "min/max threat range#below/above these values are pinned" },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeBipedPassesBlock, VisionModeBipedPasses::k_maxCount)
	{
		{ _field_long_flags, "flags", &visionModeBipedPassesFlags },
		{ _field_real, "max radius" },
		{ _field_real, "falloff begin radius#between this and max radius, we go smoothly from on to off" },
		{ _field_real, "motion sensor inactive fade time#if \"linked to motion sensor\" is checked, this is how long it takes to fade after you stop activity" },
		{ _field_real, "active camo visible velocity#if a unit has active camo and is moving faster than this, it will be shown" },
		{ _field_block, "biped passes", &visionModeBipedPassBlock_block },
		{ _field_block, "biped threat values (optional)", &visionModeBipedThreatBlock_block },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeOrdnanceVehicleTypeBlock, VisionModeOrdnanceVehicleType::k_maxCount)
	{
		{ _field_tag_reference, "vehicle type", &Tag::Reference<struct vehicle_definition>::s_defaultDefinition },
		{ _field_tag_reference, "icon", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_real_vector_2d, "icon size" },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeOrdnanceVehiclePassBlock, VisionModeOrdnanceVehiclePass::k_maxCount)
	{
		{ _field_block, "vehicle types", &visionModeOrdnanceVehicleTypeBlock_block },
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK(visionModeOrdnanceCrosshairBlock, VisionModeOrdnanceCrosshair::k_maxCount)
	{
		{ _field_custom, "material" },
		{ _field_custom },
		{ _field_struct, "actual material\?", &material_block_struct },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(vision_mode_block, 1, vision_mode_struct_definition_struct_definition );

	TAG_STRUCT(vision_mode_struct_definition)
	{
		{ _field_long_flags, "flags", &visionModeFlags },
		{ _field_real, "disabled lighting transparent exposure boost" },
		{ _field_block, "screen pass", &visionModeScreenPassBlock_block },
		{ _field_block, "environment pass", &visionModeEnvironmentPassBlock_block },
		{ _field_block, "biped passes", &visionModeBipedPassesBlock_block },
		{ _field_block, "ordnance vehicle pass", &visionModeOrdnanceVehiclePassBlock_block },
		{ _field_block, "ordnance crosshair", &visionModeOrdnanceCrosshairBlock_block },
		{ _field_terminator }
	};

	STRINGS(visionModeBipedTeamTypes)
	{
		"friends",
		"enemies",
		"neutrals"
	};
	STRING_LIST(visionModeBipedTeamTypes, visionModeBipedTeamTypes_strings, _countof(visionModeBipedTeamTypes_strings));

	STRINGS(visionModeBipedPassFlags)
	{
		"depth fail only",
		"bipeds as quads#instead of drawing the whole model, just do a quad"
	};
	STRING_LIST(visionModeBipedPassFlags, visionModeBipedPassFlags_strings, _countof(visionModeBipedPassFlags_strings));

	STRINGS(visionModeBipedPassesFlags)
	{
		"shows all bipeds#range values will be ignored",
		"render via back buffer#we draw the bipeds into a back buffer before they are splatted into the front buffer; expensive",
		"draw vehicles too",
		"draw grenades too"
	};
	STRING_LIST(visionModeBipedPassesFlags, visionModeBipedPassesFlags_strings, _countof(visionModeBipedPassesFlags_strings));

	STRINGS(visionModeFlags)
	{
		"disables normal rendering",
		"disables lighting",
		"ordnance map#we need to ask the ordnance map system about some stuff",
		"disables active camo"
	};
	STRING_LIST(visionModeFlags, visionModeFlags_strings, _countof(visionModeFlags_strings));

} // namespace blofeld

