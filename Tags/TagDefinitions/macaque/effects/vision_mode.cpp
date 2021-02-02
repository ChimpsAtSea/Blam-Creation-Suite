#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		vision_mode_group,
		VISION_MODE_TAG,
		nullptr,
		INVALID_TAG,
		vision_mode_block );

	TAG_BLOCK_FROM_STRUCT(
		vision_mode_block,
		"vision_mode_block",
		1,
		vision_mode_struct_definition);

	#define VISIONMODESCREENPASSBLOCK_ID { 0xDBA6FC3A, 0x53E34D64, 0x8C64E09E, 0x0D93FF32 }
	TAG_BLOCK(
		visionModeScreenPassBlock_block,
		"visionModeScreenPassBlock",
		VisionModeScreenPass::k_maxCount,
		"VisionModeScreenPass",
		VISIONMODESCREENPASSBLOCK_ID)
	{
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_terminator }
	};

	#define VISIONMODEENVIRONMENTPASSBLOCK_ID { 0xF2A2B65D, 0x20F942FA, 0x8B733470, 0x88639DE7 }
	TAG_BLOCK(
		visionModeEnvironmentPassBlock_block,
		"visionModeEnvironmentPassBlock",
		VisionModeEnvironmentPass::k_maxCount,
		"VisionModeEnvironmentPass",
		VISIONMODEENVIRONMENTPASSBLOCK_ID)
	{
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_terminator }
	};

	#define VISIONMODEBIPEDPASSESBLOCK_ID { 0xDBABEC3A, 0x24E35564, 0xAB6DE0FE, 0xDF9AF532 }
	TAG_BLOCK(
		visionModeBipedPassesBlock_block,
		"visionModeBipedPassesBlock",
		VisionModeBipedPasses::k_maxCount,
		"VisionModeBipedPasses",
		VISIONMODEBIPEDPASSESBLOCK_ID)
	{
		{ _field_long_flags, "flags", &visionModeBipedPassesFlags },
		{ _field_real, "max radius" },
		{ _field_real, "falloff begin radius", "between this and max radius, we go smoothly from on to off" },
		{ _field_real, "motion sensor inactive fade time", "if \"linked to motion sensor\" is checked, this is how long it takes to fade after you stop activity" },
		{ _field_real, "active camo visible velocity", "if a unit has active camo and is moving faster than this, it will be shown" },
		{ _field_block, "biped passes", &visionModeBipedPassBlock_block },
		{ _field_block, "biped threat values (optional)", &visionModeBipedThreatBlock_block },
		{ _field_terminator }
	};

	#define VISIONMODEBIPEDPASSBLOCK_ID { 0xDBABFC3A, 0x23E35D64, 0xAB64E00E, 0x0F94F532 }
	TAG_BLOCK(
		visionModeBipedPassBlock_block,
		"visionModeBipedPassBlock",
		VisionModeBipedPass::k_maxCount,
		"VisionModeBipedPass",
		VISIONMODEBIPEDPASSBLOCK_ID)
	{
		{ _field_long_flags, "flags", &visionModeBipedPassFlags },
		{ _field_long_flags, "render for", &visionModeBipedTeamTypes },
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_terminator }
	};

	#define VISIONMODEBIPEDTHREATBLOCK_ID { 0xDAF6FC3A, 0x53E33D54, 0x8C65E09E, 0x0D23FF32 }
	TAG_BLOCK(
		visionModeBipedThreatBlock_block,
		"visionModeBipedThreatBlock",
		VisionModeBipedThreat::k_maxCount,
		"VisionModeBipedThreat",
		VISIONMODEBIPEDTHREATBLOCK_ID)
	{
		{ _field_real, "threat per kill" },
		{ _field_real, "threat per death", "can be negative" },
		{ _field_real, "threat per weapon scariness point", "keys off the \"AI scariness\" field of each weapon" },
		{ _field_real_bounds, "min/max threat range", "below/above these values are pinned" },
		{ _field_terminator }
	};

	#define VISIONMODEORDNANCEVEHICLEPASSBLOCK_ID { 0x29638700, 0x39274991, 0xBEF2154D, 0x8D3E10ED }
	TAG_BLOCK(
		visionModeOrdnanceVehiclePassBlock_block,
		"visionModeOrdnanceVehiclePassBlock",
		VisionModeOrdnanceVehiclePass::k_maxCount,
		"VisionModeOrdnanceVehiclePass",
		VISIONMODEORDNANCEVEHICLEPASSBLOCK_ID)
	{
		{ _field_block, "vehicle types", &visionModeOrdnanceVehicleTypeBlock_block },
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_terminator }
	};

	#define VISIONMODEORDNANCEVEHICLETYPEBLOCK_ID { 0x68D143E5, 0xAD3144A5, 0x8961C068, 0x1465B6C2 }
	TAG_BLOCK(
		visionModeOrdnanceVehicleTypeBlock_block,
		"visionModeOrdnanceVehicleTypeBlock",
		VisionModeOrdnanceVehicleType::k_maxCount,
		"VisionModeOrdnanceVehicleType",
		VISIONMODEORDNANCEVEHICLETYPEBLOCK_ID)
	{
		{ _field_tag_reference, "vehicle type", &Tag::Reference<struct vehicle_definition>::s_defaultDefinition },
		{ _field_tag_reference, "icon", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_real_vector_2d, "icon size" },
		{ _field_terminator }
	};

	#define VISIONMODEORDNANCECROSSHAIRBLOCK_ID { 0x35958DB3, 0x7A3643C2, 0xA948119D, 0xCBEBEE4C }
	TAG_BLOCK(
		visionModeOrdnanceCrosshairBlock_block,
		"visionModeOrdnanceCrosshairBlock",
		VisionModeOrdnanceCrosshair::k_maxCount,
		"VisionModeOrdnanceCrosshair",
		VISIONMODEORDNANCECROSSHAIRBLOCK_ID)
	{
		FIELD_CUSTOM("material", nullptr, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_begin),
		{ _field_struct, "actual material", &material_struct },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_hidd_end),
		{ _field_terminator }
	};

	#define VISION_MODE_STRUCT_DEFINITION_ID { 0xD73807F4, 0x3EA54508, 0x8524E277, 0xEF130B5C }
	TAG_STRUCT(
		vision_mode_struct_definition,
		"vision_mode_struct_definition",
		"VisionModeDefinition",
		VISION_MODE_STRUCT_DEFINITION_ID)
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

} // namespace macaque

} // namespace blofeld

