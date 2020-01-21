#pragma once

template<>
inline const ReflectionType& GetReflectionType<StringID>()
{
	static ReflectionType reflectionData = 
	{
		"StringID", "StringID", 
		0x4u,
		1ui32,
		{
			{ "stringid", "Stringid", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x0ui32, 0x4ui16, 0ui32, false },
			{ }
		}
	};

	return reflectionData;
}

template<>
inline const ReflectionType& GetReflectionType<DataReference>()
{
	static ReflectionType reflectionData = 
	{
		"DataReference", "DataReference", 
		0x14u,
		5ui32,
		{
			{ "size", "Size", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x0ui32, 0x4ui16, 0ui32, false },
			{ "stream_flags", "Stream Flags", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x4ui32, 0x4ui16, 0ui32, false },
			{ "stream_offset", "Stream Offset", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x8ui32, 0x4ui16, 0ui32, false },
			{ "address", "Address", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xCui32, 0x4ui16, 0ui32, false },
			{ "definition_address", "Definition Address", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x10ui32, 0x4ui16, 0ui32, false },
			{ }
		}
	};

	return reflectionData;
}

template<>
inline const ReflectionType& GetReflectionType<TagReference>()
{
	static ReflectionType reflectionData = 
	{
		"TagReference", "TagReference", 
		0x10u,
		4ui32,
		{
			{ "tagGroupName", "TagGroupName", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Enum32, "Enum32"}, 0x0ui32, 0x4ui16, 0ui32, false },
			{ "nameLength", "NameLength", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x4ui32, 0x4ui16, 0ui32, false },
			{ "nameOffset", "NameOffset", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x8ui32, 0x4ui16, 0ui32, false },
			{ "index", "Index", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0xCui32, 0x4ui16, 0ui32, false },
			{ }
		}
	};

	return reflectionData;
}

template<>
inline const ReflectionType& GetReflectionType<TagBlock>()
{
	static ReflectionType reflectionData = 
	{
		"TagBlock", "TagBlock", 
		0xCu,
		3ui32,
		{
			{ "count", "Count", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x0ui32, 0x4ui16, 0ui32, false },
			{ "address", "Address", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x4ui32, 0x4ui16, 0ui32, false },
			{ "definition_address", "Definition Address", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x8ui32, 0x4ui16, 0ui32, false },
			{ }
		}
	};

	return reflectionData;
}

template<>
inline const ReflectionType& GetReflectionType<s_scenario_definition>()
{
	static ReflectionType reflectionData = 
	{
		"s_scenario_definition", "Scenario", 
		0x884u,
		242ui32,
		{
			{ "map_type", "Map Type", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Enum16, "Enum16"}, 0x0ui32, 0x2ui16, 0ui32, false },
			{ "flags", "Flags", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt16, "UInt16"}, 0x2ui32, 0x2ui16, 0ui32, false },
			{ "__unknown4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x4ui32, 0x4ui16, 0ui32, true },
			{ "campaign_id", "Campaign Id", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x8ui32, 0x4ui16, 0ui32, false },
			{ "map_id", "Map Id", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xCui32, 0x4ui16, 0ui32, false },
			{ "scenario_name", "Scenario Name", ReflectionTypeInfo{ ReflectionTypeCategory::Structure, PrimitiveType::Undefined, "StringID"}, 0x10ui32, 0x4ui16, 0ui32, false },
			{ "campaign_level_index", "Campaign Level Index", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int16, "Int16"}, 0x14ui32, 0x2ui16, 0ui32, false },
			{ "__unknown16", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int16, "Int16"}, 0x16ui32, 0x2ui16, 0ui32, true },
			{ "__unknown18", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x18ui32, 0x4ui16, 0ui32, true },
			{ "local_north", "Local North", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Float, "Float"}, 0x1Cui32, 0x4ui16, 0ui32, false },
			{ "__unknown20", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Float, "Float"}, 0x20ui32, 0x4ui16, 0ui32, true },
			{ "__unknown24", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Float, "Float"}, 0x24ui32, 0x4ui16, 0ui32, true },
			{ "__unknown28", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x28ui32, 0x4ui16, 0ui32, true },
			{ "__unknown2C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown30", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Float, "Float"}, 0x30ui32, 0x4ui16, 0ui32, true },
			{ "sandbox_budget", "Sandbox Budget", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Float, "Float"}, 0x34ui32, 0x4ui16, 0ui32, false },
			{ "default_vehicle_filter", "Default Vehicle Filter", ReflectionTypeInfo{ ReflectionTypeCategory::Structure, PrimitiveType::Undefined, "StringID"}, 0x38ui32, 0x4ui16, 0ui32, false },
			{ "performance_throttle_profile_reference", "Performance Throttle Profile", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x3Cui32, 0x10ui16, 0ui32, false },
			{ "structure_sbsps_block", "Structure Sbsps", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x4Cui32, 0xCui16, 0ui32, false },
			{ "structure_design_block", "Structure Design", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x58ui32, 0xCui16, 0ui32, false },
			{ "__unknown64_reference", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x64ui32, 0x10ui16, 0ui32, true },
			{ "__unknown74_reference", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x74ui32, 0x10ui16, 0ui32, true },
			{ "sky_references_block", "Sky References", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x84ui32, 0xCui16, 0ui32, false },
			{ "bsp_groups_block", "Bsp Groups", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x90ui32, 0xCui16, 0ui32, false },
			{ "scenario_bsp_audibility_block", "Scenario Bsp Audibility", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x9Cui32, 0xCui16, 0ui32, false },
			{ "scenario_zoneset_groups_block", "Scenario Zoneset Groups", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0xA8ui32, 0xCui16, 0ui32, false },
			{ "__unknownB4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xB4ui32, 0x4ui16, 0ui32, true },
			{ "__unknownB8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xB8ui32, 0x4ui16, 0ui32, true },
			{ "__unknownBC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xBCui32, 0x4ui16, 0ui32, true },
			{ "__unknownC0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xC0ui32, 0x4ui16, 0ui32, true },
			{ "__unknownC4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xC4ui32, 0x4ui16, 0ui32, true },
			{ "__unknownC8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xC8ui32, 0x4ui16, 0ui32, true },
			{ "__unknownCC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xCCui32, 0x4ui16, 0ui32, true },
			{ "__unknownD0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xD0ui32, 0x4ui16, 0ui32, true },
			{ "__unknownD4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xD4ui32, 0x4ui16, 0ui32, true },
			{ "__unknownD8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xD8ui32, 0x4ui16, 0ui32, true },
			{ "__unknownDC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xDCui32, 0x4ui16, 0ui32, true },
			{ "__unknownE0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xE0ui32, 0x4ui16, 0ui32, true },
			{ "editor_scenario_data_data_reference", "Editor Scenario Data", ReflectionTypeInfo{ ReflectionTypeCategory::DataReference, PrimitiveType::Undefined, "DataReference"}, 0xE4ui32, 0x14ui16, 0ui32, false },
			{ "__unknownF8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xF8ui32, 0x4ui16, 0ui32, true },
			{ "__unknownFC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0xFCui32, 0x4ui16, 0ui32, true },
			{ "__unknown100", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x100ui32, 0x4ui16, 0ui32, true },
			{ "object_names_block", "Object Names", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x104ui32, 0xCui16, 0ui32, false },
			{ "scenery_block", "Scenery", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x110ui32, 0xCui16, 0ui32, false },
			{ "scenery_palette_block", "Scenery Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x11Cui32, 0xCui16, 0ui32, false },
			{ "bipeds_block", "Bipeds", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x128ui32, 0xCui16, 0ui32, false },
			{ "biped_palette_block", "Biped Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x134ui32, 0xCui16, 0ui32, false },
			{ "vehicles_block", "Vehicles", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x140ui32, 0xCui16, 0ui32, false },
			{ "vehicle_palette_block", "Vehicle Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x14Cui32, 0xCui16, 0ui32, false },
			{ "equipment_block", "Equipment", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x158ui32, 0xCui16, 0ui32, false },
			{ "equipment_palette_block", "Equipment Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x164ui32, 0xCui16, 0ui32, false },
			{ "weapons_block", "Weapons", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x170ui32, 0xCui16, 0ui32, false },
			{ "weapon_palette_block", "Weapon Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x17Cui32, 0xCui16, 0ui32, false },
			{ "device_groups_block", "Device Groups", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x188ui32, 0xCui16, 0ui32, false },
			{ "machines_block", "Machines", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x194ui32, 0xCui16, 0ui32, false },
			{ "machine_palette_block", "Machine Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1A0ui32, 0xCui16, 0ui32, false },
			{ "terminals_block", "Terminals", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1ACui32, 0xCui16, 0ui32, false },
			{ "terminal_palette_block", "Terminal Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1B8ui32, 0xCui16, 0ui32, false },
			{ "controls_block", "Controls", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1C4ui32, 0xCui16, 0ui32, false },
			{ "control_palette_block", "Control Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1D0ui32, 0xCui16, 0ui32, false },
			{ "sound_scenery_block", "Sound Scenery", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1DCui32, 0xCui16, 0ui32, false },
			{ "sound_scenery_palette_block", "Sound Scenery Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1E8ui32, 0xCui16, 0ui32, false },
			{ "giants_block", "Giants", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x1F4ui32, 0xCui16, 0ui32, false },
			{ "giant_palette_block", "Giant Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x200ui32, 0xCui16, 0ui32, false },
			{ "effect_scenery_block", "Effect Scenery", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x20Cui32, 0xCui16, 0ui32, false },
			{ "effect_scenery_palette_block", "Effect Scenery Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x218ui32, 0xCui16, 0ui32, false },
			{ "light_volumes_block", "Light Volumes", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x224ui32, 0xCui16, 0ui32, false },
			{ "light_volumes_palette_block", "Light Volumes Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x230ui32, 0xCui16, 0ui32, false },
			{ "sandbox_palette_block", "Sandbox Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x23Cui32, 0xCui16, 0ui32, false },
			{ "legacy_sandbox_info_block", "Legacy Sandbox Info", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x248ui32, 0xCui16, 0ui32, false },
			{ "__unknown254_reference", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x254ui32, 0x10ui16, 0ui32, true },
			{ "__unknown264", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x264ui32, 0x4ui16, 0ui32, true },
			{ "__unknown268", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x268ui32, 0x4ui16, 0ui32, true },
			{ "__unknown26C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x26Cui32, 0x4ui16, 0ui32, true },
			{ "soft_ceilings_block", "Soft Ceilings", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x270ui32, 0xCui16, 0ui32, false },
			{ "player_starting_profile_block", "Player Starting Profile", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x27Cui32, 0xCui16, 0ui32, false },
			{ "player_starting_locations_block", "Player Starting Locations", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x288ui32, 0xCui16, 0ui32, false },
			{ "trigger_volumes_block", "Trigger Volumes", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x294ui32, 0xCui16, 0ui32, false },
			{ "__unknown2A0_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x2A0ui32, 0xCui16, 0ui32, true },
			{ "__unknown2AC_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x2ACui32, 0xCui16, 0ui32, true },
			{ "__unknown2B8_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x2B8ui32, 0xCui16, 0ui32, true },
			{ "__unknown2C4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2C4ui32, 0x4ui16, 0ui32, true },
			{ "__unknown2C8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2C8ui32, 0x4ui16, 0ui32, true },
			{ "__unknown2CC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2CCui32, 0x4ui16, 0ui32, true },
			{ "__unknown2D0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2D0ui32, 0x4ui16, 0ui32, true },
			{ "__unknown2D4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2D4ui32, 0x4ui16, 0ui32, true },
			{ "__unknown2D8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x2D8ui32, 0x4ui16, 0ui32, true },
			{ "zoneset_switch_trigger_volumes_block", "Zoneset Switch Trigger Volumes", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x2DCui32, 0xCui16, 0ui32, false },
			{ "location_name_callouts_block", "Location Name Callouts", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x2E8ui32, 0xCui16, 0ui32, false },
			{ "airstrike_globals_reference", "Airstrike Globals", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x2F4ui32, 0x10ui16, 0ui32, false },
			{ "__unknown304", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x304ui32, 0x4ui16, 0ui32, true },
			{ "__unknown308", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x308ui32, 0x4ui16, 0ui32, true },
			{ "__unknown30C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x30Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown310_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x310ui32, 0xCui16, 0ui32, true },
			{ "__unknown31C_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x31Cui32, 0xCui16, 0ui32, true },
			{ "__unknown328_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x328ui32, 0xCui16, 0ui32, true },
			{ "__unknown334_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x334ui32, 0xCui16, 0ui32, true },
			{ "__unknown340", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x340ui32, 0x4ui16, 0ui32, true },
			{ "__unknown344", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x344ui32, 0x4ui16, 0ui32, true },
			{ "__unknown348", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x348ui32, 0x4ui16, 0ui32, true },
			{ "__unknown34C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x34Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown350", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x350ui32, 0x4ui16, 0ui32, true },
			{ "__unknown354", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x354ui32, 0x4ui16, 0ui32, true },
			{ "__unknown358", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x358ui32, 0x4ui16, 0ui32, true },
			{ "__unknown35C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x35Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown360", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x360ui32, 0x4ui16, 0ui32, true },
			{ "__unknown364", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x364ui32, 0x4ui16, 0ui32, true },
			{ "__unknown368", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x368ui32, 0x4ui16, 0ui32, true },
			{ "__unknown36C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x36Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown370", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x370ui32, 0x4ui16, 0ui32, true },
			{ "__unknown374", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x374ui32, 0x4ui16, 0ui32, true },
			{ "__unknown378", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x378ui32, 0x4ui16, 0ui32, true },
			{ "decals_block", "Decals", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x37Cui32, 0xCui16, 0ui32, false },
			{ "decal_palette_block", "Decal Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x388ui32, 0xCui16, 0ui32, false },
			{ "__unknown394", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x394ui32, 0x4ui16, 0ui32, true },
			{ "__unknown398", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x398ui32, 0x4ui16, 0ui32, true },
			{ "__unknown39C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x39Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown3A0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3A0ui32, 0x4ui16, 0ui32, true },
			{ "__unknown3A4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3A4ui32, 0x4ui16, 0ui32, true },
			{ "__unknown3A8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3A8ui32, 0x4ui16, 0ui32, true },
			{ "squad_groups_block", "Squad Groups", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x3ACui32, 0xCui16, 0ui32, false },
			{ "squads_block", "Squads", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x3B8ui32, 0xCui16, 0ui32, false },
			{ "zones_block", "Zones", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x3C4ui32, 0xCui16, 0ui32, false },
			{ "__unknown3D0_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x3D0ui32, 0xCui16, 0ui32, true },
			{ "ai_cues_block", "Ai Cues", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x3DCui32, 0xCui16, 0ui32, false },
			{ "__unknown3E8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3E8ui32, 0x4ui16, 0ui32, true },
			{ "__unknown3EC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3ECui32, 0x4ui16, 0ui32, true },
			{ "__unknown3F0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3F0ui32, 0x4ui16, 0ui32, true },
			{ "__unknown3F4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3F4ui32, 0x4ui16, 0ui32, true },
			{ "__unknown3F8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3F8ui32, 0x4ui16, 0ui32, true },
			{ "__unknown3FC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x3FCui32, 0x4ui16, 0ui32, true },
			{ "__unknown400", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x400ui32, 0x4ui16, 0ui32, true },
			{ "__unknown404", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x404ui32, 0x4ui16, 0ui32, true },
			{ "__unknown408", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x408ui32, 0x4ui16, 0ui32, true },
			{ "character_palette_block", "Character Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x40Cui32, 0xCui16, 0ui32, false },
			{ "__unknown418", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x418ui32, 0x4ui16, 0ui32, true },
			{ "__unknown41C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x41Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown420", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x420ui32, 0x4ui16, 0ui32, true },
			{ "ai_pathfinding_data_block", "Ai Pathfinding Data", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x424ui32, 0xCui16, 0ui32, false },
			{ "__unknown430", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x430ui32, 0x4ui16, 0ui32, true },
			{ "__unknown434", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x434ui32, 0x4ui16, 0ui32, true },
			{ "__unknown438", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x438ui32, 0x4ui16, 0ui32, true },
			{ "script_strings_data_reference", "Script Strings", ReflectionTypeInfo{ ReflectionTypeCategory::DataReference, PrimitiveType::Undefined, "DataReference"}, 0x43Cui32, 0x14ui16, 0ui32, false },
			{ "scripts_block", "Scripts", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x450ui32, 0xCui16, 0ui32, false },
			{ "globals_block", "Globals", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x45Cui32, 0xCui16, 0ui32, false },
			{ "script_references_block", "Script References", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x468ui32, 0xCui16, 0ui32, false },
			{ "__unknown474", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x474ui32, 0x4ui16, 0ui32, true },
			{ "__unknown478", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x478ui32, 0x4ui16, 0ui32, true },
			{ "__unknown47C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x47Cui32, 0x4ui16, 0ui32, true },
			{ "scripting_data_block", "Scripting Data", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x480ui32, 0xCui16, 0ui32, false },
			{ "cutscene_flags_block", "Cutscene Flags", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x48Cui32, 0xCui16, 0ui32, false },
			{ "cutscene_camera_points_block", "Cutscene Camera Points", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x498ui32, 0xCui16, 0ui32, false },
			{ "cutscene_titles_block", "Cutscene Titles", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x4A4ui32, 0xCui16, 0ui32, false },
			{ "custom_object_name_strings_reference", "Custom Object Name Strings", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x4B0ui32, 0x10ui16, 0ui32, false },
			{ "chapter_title_strings_reference", "Chapter Title Strings", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x4C0ui32, 0x10ui16, 0ui32, false },
			{ "scenario_resources_block", "Scenario Resources", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x4D0ui32, 0xCui16, 0ui32, false },
			{ "unit_seats_mapping_block", "Unit Seats Mapping", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x4DCui32, 0xCui16, 0ui32, false },
			{ "scenario_kill_triggers_block", "Scenario Kill Triggers", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x4E8ui32, 0xCui16, 0ui32, false },
			{ "scenario_safe_triggers_block", "Scenario Safe Triggers", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x4F4ui32, 0xCui16, 0ui32, false },
			{ "scenario_mopp_triggers_block", "Scenario Mopp Triggers", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x500ui32, 0xCui16, 0ui32, false },
			{ "__unknown50C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x50Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown510", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x510ui32, 0x4ui16, 0ui32, true },
			{ "__unknown514", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x514ui32, 0x4ui16, 0ui32, true },
			{ "__unknown518", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x518ui32, 0x4ui16, 0ui32, true },
			{ "__unknown51C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x51Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown520", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x520ui32, 0x4ui16, 0ui32, true },
			{ "script_expressions_block", "Script Expressions", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x524ui32, 0xCui16, 0ui32, false },
			{ "__unknown530", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x530ui32, 0x4ui16, 0ui32, true },
			{ "__unknown534", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x534ui32, 0x4ui16, 0ui32, true },
			{ "__unknown538", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x538ui32, 0x4ui16, 0ui32, true },
			{ "__unknown53C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x53Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown540", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x540ui32, 0x4ui16, 0ui32, true },
			{ "__unknown544", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x544ui32, 0x4ui16, 0ui32, true },
			{ "background_sound_environment_palette_block", "Background Sound Environment Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x548ui32, 0xCui16, 0ui32, false },
			{ "fog_block", "Fog", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x554ui32, 0xCui16, 0ui32, false },
			{ "camera_fx_block", "Camera Fx", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x560ui32, 0xCui16, 0ui32, false },
			{ "weather_block", "Weather", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x56Cui32, 0xCui16, 0ui32, false },
			{ "scenario_cluster_data_block", "Scenario Cluster Data", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x578ui32, 0xCui16, 0ui32, false },
			{ "object_salts_array", "Object Salts Array", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::Int32, "Int32"}, 0x584ui32, 0x4ui16, 32ui32, false },
			{ "spawn_data_block", "Spawn Data", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x604ui32, 0xCui16, 0ui32, false },
			{ "sound_effects_collection_reference", "Sound Effects Collection", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x610ui32, 0x10ui16, 0ui32, false },
			{ "crates_block", "Crates", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x620ui32, 0xCui16, 0ui32, false },
			{ "crate_palette_block", "Crate Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x62Cui32, 0xCui16, 0ui32, false },
			{ "flock_palette_block", "Flock Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x638ui32, 0xCui16, 0ui32, false },
			{ "flocks_block", "Flocks", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x644ui32, 0xCui16, 0ui32, false },
			{ "subtitle_strings_reference", "Subtitle Strings", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x650ui32, 0x10ui16, 0ui32, false },
			{ "__unknown660", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x660ui32, 0x4ui16, 0ui32, true },
			{ "__unknown664", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x664ui32, 0x4ui16, 0ui32, true },
			{ "__unknown668", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x668ui32, 0x4ui16, 0ui32, true },
			{ "creature_palette_block", "Creature Palette", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x66Cui32, 0xCui16, 0ui32, false },
			{ "big_battle_creatures_block", "Big Battle Creatures", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x678ui32, 0xCui16, 0ui32, false },
			{ "editor_folders_block", "Editor Folders", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x684ui32, 0xCui16, 0ui32, false },
			{ "territory_location_name_strings_reference", "Territory Location Name Strings", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x690ui32, 0x10ui16, 0ui32, false },
			{ "__unknown6A0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x6A0ui32, 0x4ui16, 0ui32, true },
			{ "__unknown6A4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x6A4ui32, 0x4ui16, 0ui32, true },
			{ "mission_dialogue_block", "Mission Dialogue", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x6A8ui32, 0xCui16, 0ui32, false },
			{ "objective_strings_reference", "Objective Strings", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x6B4ui32, 0x10ui16, 0ui32, false },
			{ "scenario_interpolator_reference", "Scenario Interpolator", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x6C4ui32, 0x10ui16, 0ui32, false },
			{ "__unknown6D4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x6D4ui32, 0x4ui16, 0ui32, true },
			{ "__unknown6D8", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x6D8ui32, 0x4ui16, 0ui32, true },
			{ "__unknown6DC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x6DCui32, 0x4ui16, 0ui32, true },
			{ "default_camera_fx_reference", "Default Camera Fx", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x6E0ui32, 0x10ui16, 0ui32, false },
			{ "default_screen_fx_reference", "Default Screen Fx", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x6F0ui32, 0x10ui16, 0ui32, false },
			{ "ambient_occlusion_profile_reference", "Ambient Occlusion Profile", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x700ui32, 0x10ui16, 0ui32, false },
			{ "sky_parameters_reference", "Sky Parameters", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x710ui32, 0x10ui16, 0ui32, false },
			{ "fog_parameters_reference", "Fog Parameters", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x720ui32, 0x10ui16, 0ui32, false },
			{ "global_lighting_reference", "Global Lighting", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x730ui32, 0x10ui16, 0ui32, false },
			{ "lightmap_reference", "Lightmap", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x740ui32, 0x10ui16, 0ui32, false },
			{ "performance_throttles_reference", "Performance Throttles", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x750ui32, 0x10ui16, 0ui32, false },
			{ "__unknown760_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x760ui32, 0xCui16, 0ui32, true },
			{ "ai_objectives_block", "Ai Objectives", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x76Cui32, 0xCui16, 0ui32, false },
			{ "designer_zonesets_block", "Designer Zonesets", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x778ui32, 0xCui16, 0ui32, false },
			{ "__unknown784_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x784ui32, 0xCui16, 0ui32, true },
			{ "__unknown790", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x790ui32, 0x4ui16, 0ui32, true },
			{ "__unknown794", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x794ui32, 0x4ui16, 0ui32, true },
			{ "__unknown798", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x798ui32, 0x4ui16, 0ui32, true },
			{ "particle_emitters_block", "Particle Emitters", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x79Cui32, 0xCui16, 0ui32, false },
			{ "__unknown7A8_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x7A8ui32, 0xCui16, 0ui32, true },
			{ "cinematics_block", "Cinematics", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x7B4ui32, 0xCui16, 0ui32, false },
			{ "cinematic_lights_block", "Cinematic Lights", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x7C0ui32, 0xCui16, 0ui32, false },
			{ "__unknown7CC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x7CCui32, 0x4ui16, 0ui32, true },
			{ "__unknown7D0", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x7D0ui32, 0x4ui16, 0ui32, true },
			{ "__unknown7D4", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x7D4ui32, 0x4ui16, 0ui32, true },
			{ "scenario_metagame_block", "Scenario Metagame", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x7D8ui32, 0xCui16, 0ui32, false },
			{ "__unknown7E4_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x7E4ui32, 0xCui16, 0ui32, true },
			{ "__unknown7F0_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x7F0ui32, 0xCui16, 0ui32, true },
			{ "__unknown7FC", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x7FCui32, 0x4ui16, 0ui32, true },
			{ "__unknown800", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x800ui32, 0x4ui16, 0ui32, true },
			{ "__unknown804", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x804ui32, 0x4ui16, 0ui32, true },
			{ "__unknown808", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x808ui32, 0x4ui16, 0ui32, true },
			{ "__unknown80C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x80Cui32, 0x4ui16, 0ui32, true },
			{ "__unknown810", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x810ui32, 0x4ui16, 0ui32, true },
			{ "__unknown814", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x814ui32, 0x4ui16, 0ui32, true },
			{ "__unknown818", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x818ui32, 0x4ui16, 0ui32, true },
			{ "__unknown81C", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::Primitive, PrimitiveType::UInt32, "UInt32"}, 0x81Cui32, 0x4ui16, 0ui32, true },
			{ "vignettes_block", "Vignettes", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x820ui32, 0xCui16, 0ui32, false },
			{ "map_location_globals_reference", "Map Location Globals", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x82Cui32, 0x10ui16, 0ui32, false },
			{ "__unknown83C_block", "Unknown", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x83Cui32, 0xCui16, 0ui32, true },
			{ "mission_hud_reference", "Mission Hud", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x848ui32, 0x10ui16, 0ui32, false },
			{ "required_resources_reference", "Required Resources", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x858ui32, 0x10ui16, 0ui32, false },
			{ "variant_globals_reference", "Variant Globals", ReflectionTypeInfo{ ReflectionTypeCategory::TagReference, PrimitiveType::Undefined, "TagReference"}, 0x868ui32, 0x10ui16, 0ui32, false },
			{ "compiled_data_block", "Compiled Data", ReflectionTypeInfo{ ReflectionTypeCategory::TagBlock, PrimitiveType::Undefined, "TagBlock"}, 0x878ui32, 0xCui16, 0ui32, false },
			{ }
		}
	};

	return reflectionData;
}

