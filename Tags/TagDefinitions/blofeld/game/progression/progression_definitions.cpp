#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		progression_group,
		PROGRESSION_TAG,
		nullptr,
		INVALID_TAG,
		progressionGlobalsBlock_block );

	#define PROGRESSION_STRUCT_DEFINITION_ID { 0x00593DE7, 0x36974F01, 0xB8742966, 0x4420D58A }
	TAG_BLOCK(
		progressionGlobalsBlock_block,
		"progressionGlobalsBlock",
		1,
		"ProgressionGlobals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROGRESSION_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "ordnance points gained on killing another player" },
		{ _field_long_integer, "ordnance points gained on killing an NPC" },
		{ _field_long_integer, "ordnance points lost on death" },
		{ _field_tag_reference, "droppod UI remote strike", "special version of RS used by player to position droppod location", &global_equipment_reference },
		{ _field_tag_reference, "drop pod (object)", &scenery_reference$3 },
		{ _field_tag_reference, "drop pod warning (effect)", "spawned at drop location at start of fanfare delay", &global_effect_reference },
		{ _field_tag_reference, "drop pod locator (effect)", "used by random ordnance drop system for air drops", &global_effect_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_progression_reference, PROGRESSION_TAG);



} // namespace blofeld

