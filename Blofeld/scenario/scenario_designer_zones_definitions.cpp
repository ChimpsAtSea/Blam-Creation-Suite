#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(scenario_designer_zone_block, k_maximum_designer_zone_count)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "references*", &scenarioDesignerZoneTagReferenceBlock_block ),
		FIELD( _field_custom, "biped" ),
		FIELD( _field_block, "biped", &biped_block_index_flags_block_block ),
		FIELD( _field_custom, "vehicle" ),
		FIELD( _field_block, "vehicle", &vehicle_block_index_flags_block_block ),
		FIELD( _field_custom, "weapon" ),
		FIELD( _field_block, "weapon", &weapon_block_index_flags_block_block ),
		FIELD( _field_custom, "equipment" ),
		FIELD( _field_block, "equipment", &equipment_block_index_flags_block_block ),
		FIELD( _field_custom, "scenery" ),
		FIELD( _field_block, "scenery", &scenery_block_index_flags_block_block ),
		FIELD( _field_custom, "machine" ),
		FIELD( _field_block, "machine", &machine_block_index_flags_block_block ),
		FIELD( _field_custom, "terminal" ),
		FIELD( _field_block, "terminal", &terminal_block_index_flags_block_block ),
		FIELD( _field_custom, "control" ),
		FIELD( _field_block, "control", &control_block_index_flags_block_block ),
		FIELD( _field_custom, "dispenser" ),
		FIELD( _field_block, "dispenser", &dispenser_block_index_flags_block_block ),
		FIELD( _field_custom, "sound_scenery" ),
		FIELD( _field_block, "sound_scenery", &sound_scenery_block_index_flags_block_block ),
		FIELD( _field_custom, "crate" ),
		FIELD( _field_block, "crate", &crate_block_index_flags_block_block ),
		FIELD( _field_custom, "creature" ),
		FIELD( _field_block, "creature", &creature_block_index_flags_block_block ),
		FIELD( _field_custom, "giant" ),
		FIELD( _field_block, "giant", &giant_block_index_flags_block_block ),
		FIELD( _field_custom, "effect_scenery" ),
		FIELD( _field_block, "effect_scenery", &effect_scenery_block_index_flags_block_block ),
		FIELD( _field_custom, "character" ),
		FIELD( _field_block, "character", &character_block_index_flags_block_block ),
		FIELD( _field_custom, "spawner" ),
		FIELD( _field_block, "spawner", &spawner_block_index_flags_block_block ),
		FIELD( _field_custom, "budget_reference" ),
		FIELD( _field_block, "budget_reference", &budget_reference_block_index_flags_block_block ),
		FIELD( _field_custom, "bink" ),
		FIELD( _field_block, "bink", &bink_block_index_flags_block_block ),
		FIELD( _field_block, "resource dependencies*!", &scenarioDesignerResourceDependenciesBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioDesignerZoneTagReferenceBlock, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK*k_scenario_designer_zone_palette_count)
	{
		FIELD( _field_tag_reference, "tag^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(biped_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vehicle_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(weapon_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(equipment_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenery_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(machine_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(terminal_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(control_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(dispenser_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_scenery_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(crate_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(creature_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(giant_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(effect_scenery_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(character_block_index_flags_block, 64)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(spawner_block_index_flags_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(budget_reference_block_index_flags_block, k_maximum_hs_references_per_context)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(bink_block_index_flags_block, MAXIMUM_BINK_PALETTE_ENTRIES_PER_BLOCK)
	{
		FIELD( _field_short_block_index, "palette index^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(scenarioDesignerResourceDependenciesBlock, 16*1024)
	{
		FIELD( _field_tag_reference, "tag^" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

