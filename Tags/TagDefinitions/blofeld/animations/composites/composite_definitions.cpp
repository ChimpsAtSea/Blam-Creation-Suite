#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_BLOCK_FROM_STRUCT(
		g_compositeTag_block,
		"g_compositeTag",
		MAX_COMPOSITES_PER_GRAPH,
		g_compositeTag_struct);

	#define COMPOSITEAXISDEFINITION_ID { 0x168DE62E, 0x9B0A4844, 0x8A388EE4, 0xE440F78E }
	TAG_BLOCK(
		CompositeAxisDefinition_block,
		"CompositeAxisDefinition",
		MAX_VALUES_PER_COMPOSITE_ENTRY,
		"CompositeAxis",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMPOSITEAXISDEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_string_id, "animation source", FIELD_FLAG_READ_ONLY },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_function),
		{ _field_string_id, "input function" },
		{ _field_real_bounds, "animation bounds" },
		{ _field_real_bounds, "input bounds" },
		{ _field_real_bounds, "clamp bounds" },
		{ _field_real, "blend limit", FIELD_FLAG_READ_ONLY },
		{ _field_block, "dead zones", &CompositeDeadZoneDefinition_block },
		{ _field_char_integer, "divisions", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "priority", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "update", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "functionIndex", FIELD_FLAG_READ_ONLY },
		{ _field_long_flags, "flags", FIELD_FLAG_READ_ONLY, &CompositeAxisFlags },
		{ _field_terminator }
	};

	#define COMPOSITEDEADZONEDEFINITION_ID { 0x48E34FCA, 0x2C9E462F, 0xAD47F2DC, 0xFFF4A197 }
	TAG_BLOCK(
		CompositeDeadZoneDefinition_block,
		"CompositeDeadZoneDefinition",
		MAX_DEAD_ZONES_PER_COMPOSITE_AXIS,
		"CompositeDeadZone",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMPOSITEDEADZONEDEFINITION_ID)
	{
		{ _field_real_bounds, "bounds" },
		{ _field_real, "rate" },
		{ _field_real, "center", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "radius", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "amount", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "delay", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define COMPOSITEENTRYDEFINITION_ID { 0x76AF9875, 0xE0254663, 0xA0BF321B, 0x0EEE3D79 }
	TAG_BLOCK(
		CompositeEntryDefinition_block,
		"CompositeEntryDefinition",
		MAX_ENTRIES_PER_COMPOSITE,
		"CompositeEntry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMPOSITEENTRYDEFINITION_ID)
	{
		{ _field_string_id, "source", FIELD_FLAG_INDEX },
		{ _field_block, "values", FIELD_FLAG_READ_ONLY, &CompositeEntryValueDefinition_block },
		{ _field_long_integer, "overridden", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "animIndex", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "slideAxis", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("PAD", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define COMPOSITEENTRYVALUEDEFINITION_ID { 0x2C6E4B32, 0xE3824A07, 0xB95A6F5D, 0x1FF851B6 }
	TAG_BLOCK(
		CompositeEntryValueDefinition_block,
		"CompositeEntryValueDefinition",
		MAX_VALUES_PER_COMPOSITE_ENTRY,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMPOSITEENTRYVALUEDEFINITION_ID)
	{
		{ _field_real, "value", FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define COMPOSITEPHASESETDEFINITION_ID { 0x1C6DD71A, 0x07ED4420, 0x97E43A00, 0x5F2604DA }
	TAG_BLOCK(
		CompositePhaseSetDefinition_block,
		"CompositePhaseSetDefinition",
		MAX_PHASE_SETS_PER_COMPOSITE,
		"CompositePhaseSet",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMPOSITEPHASESETDEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_string_id, "timing source" },
		{ _field_block, "sync points", &SyncKeyBlock_block },
		{ _field_data, "sync frames", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_data, "facets", FIELD_FLAG_READ_ONLY },
		{ _field_data, "neighbors", FIELD_FLAG_READ_ONLY },
		{ _field_data, "containment", FIELD_FLAG_READ_ONLY },
		{ _field_data, "example grid", FIELD_FLAG_READ_ONLY },
		{ _field_real_bounds, "normalized bounds" },
		{ _field_char_integer, "offset", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("PAD", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "timingAnimIndex", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SYNCKEYBLOCK_ID { 0xFB3CC58F, 0xFAD949D9, 0x8879258F, 0x357D1085 }
	TAG_BLOCK(
		SyncKeyBlock_block,
		"SyncKeyBlock",
		Composite::MAX_SYNC_KEYS,
		"c_animation_frame_event_type",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SYNCKEYBLOCK_ID)
	{
		{ _field_enum, "key", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &frame_event_type_new },
		{ _field_terminator }
	};

	#define STRINGBLOCK_ID { 0xB75016D8, 0xEA3C4FFD, 0x87191515, 0x56803132 }
	TAG_BLOCK(
		StringBlock_block,
		"StringBlock",
		k_kilo,
		"string_id",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRINGBLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define G_COMPOSITETAG_STRUCT_ID { 0xCE71BB1A, 0x50AB45ED, 0x90C7C874, 0x047FF664 }
	TAG_STRUCT_V6(
		g_compositeTag_struct,
		"g_compositeTag_struct",
		"CompositeTag",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		G_COMPOSITETAG_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "axes", FIELD_FLAG_READ_ONLY, &CompositeAxisDefinition_block },
		{ _field_block, "anims", FIELD_FLAG_READ_ONLY, &CompositeEntryDefinition_block },
		{ _field_block, "sets", FIELD_FLAG_READ_ONLY, &CompositePhaseSetDefinition_block },
		{ _field_block, "strings", FIELD_FLAG_READ_ONLY, &StringBlock_block },
		{ _field_string_id, "timing source" },
		{ _field_short_integer, "timingAnimIndex", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("PAD", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	STRINGS(CompositeAxisFlags)
	{
		"wrapped",
		"clamped"
	};
	STRING_LIST(CompositeAxisFlags, CompositeAxisFlags_strings, _countof(CompositeAxisFlags_strings));



} // namespace blofeld

