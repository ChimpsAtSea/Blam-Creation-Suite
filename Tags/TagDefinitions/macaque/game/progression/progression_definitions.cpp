#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
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
		PROGRESSION_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "ordnance points gained on killing another player" },
		{ _field_long_integer, "ordnance points gained on killing an NPC" },
		{ _field_long_integer, "ordnance points lost on death" },
		{ _field_tag_reference, "droppod UI remote strike", &global_equipment_reference },
		{ _field_tag_reference, "drop pod (object)", &scenery_reference$3 },
		{ _field_tag_reference, "drop pod warning (effect)", &global_effect_reference },
		{ _field_tag_reference, "drop pod locator (effect)", &global_effect_reference },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_progression_reference, PROGRESSION_TAG);

} // namespace macaque

} // namespace blofeld

