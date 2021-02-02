#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
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
		COMPOSITEAXISDEFINITION_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "animation source" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_unknown_function),
		{ _field_string_id, "input function" },
		{ _field_real_bounds, "animation bounds" },
		{ _field_real_bounds, "input bounds" },
		{ _field_real_bounds, "clamp bounds" },
		{ _field_real, "blend limit" },
		{ _field_block, "dead zones", &CompositeDeadZoneDefinition_block },
		{ _field_char_integer, "divisions" },
		{ _field_char_integer, "priority" },
		{ _field_char_integer, "update" },
		{ _field_char_integer, "functionIndex" },
		{ _field_long_flags, "flags", &CompositeAxisFlags },
		{ _field_terminator }
	};

	#define COMPOSITEDEADZONEDEFINITION_ID { 0x48E34FCA, 0x2C9E462F, 0xAD47F2DC, 0xFFF4A197 }
	TAG_BLOCK(
		CompositeDeadZoneDefinition_block,
		"CompositeDeadZoneDefinition",
		MAX_DEAD_ZONES_PER_COMPOSITE_AXIS,
		"CompositeDeadZone",
		COMPOSITEDEADZONEDEFINITION_ID)
	{
		{ _field_real_bounds, "bounds" },
		{ _field_real, "rate" },
		{ _field_real, "center" },
		{ _field_real, "radius" },
		{ _field_real, "amount" },
		{ _field_long_integer, "delay" },
		{ _field_terminator }
	};

	#define COMPOSITEENTRYDEFINITION_ID { 0x76AF9875, 0xE0254663, 0xA0BF321B, 0x0EEE3D79 }
	TAG_BLOCK(
		CompositeEntryDefinition_block,
		"CompositeEntryDefinition",
		MAX_ENTRIES_PER_COMPOSITE,
		"CompositeEntry",
		COMPOSITEENTRYDEFINITION_ID)
	{
		{ _field_string_id, "source" },
		{ _field_block, "values", &CompositeEntryValueDefinition_block },
		{ _field_long_integer, "overridden" },
		{ _field_short_integer, "animIndex" },
		{ _field_char_integer, "slideAxis" },
		FIELD_PAD("PAD", nullptr, 1),
		{ _field_terminator }
	};

	#define COMPOSITEENTRYVALUEDEFINITION_ID { 0x2C6E4B32, 0xE3824A07, 0xB95A6F5D, 0x1FF851B6 }
	TAG_BLOCK(
		CompositeEntryValueDefinition_block,
		"CompositeEntryValueDefinition",
		MAX_VALUES_PER_COMPOSITE_ENTRY,
		"real",
		COMPOSITEENTRYVALUEDEFINITION_ID)
	{
		{ _field_real, "value" },
		{ _field_terminator }
	};

	#define COMPOSITEPHASESETDEFINITION_ID { 0x1C6DD71A, 0x07ED4420, 0x97E43A00, 0x5F2604DA }
	TAG_BLOCK(
		CompositePhaseSetDefinition_block,
		"CompositePhaseSetDefinition",
		MAX_PHASE_SETS_PER_COMPOSITE,
		"CompositePhaseSet",
		COMPOSITEPHASESETDEFINITION_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "timing source" },
		{ _field_block, "sync points", &SyncKeyBlock_block },
		{ _field_data, "sync frames" },
		{ _field_data, "facets" },
		{ _field_data, "neighbors" },
		{ _field_data, "containment" },
		{ _field_data, "example grid" },
		{ _field_real_bounds, "normalized bounds" },
		{ _field_char_integer, "offset" },
		FIELD_PAD("PAD", nullptr, 1),
		{ _field_short_integer, "timingAnimIndex" },
		{ _field_terminator }
	};

	#define SYNCKEYBLOCK_ID { 0xFB3CC58F, 0xFAD949D9, 0x8879258F, 0x357D1085 }
	TAG_BLOCK(
		SyncKeyBlock_block,
		"SyncKeyBlock",
		Composite::MAX_SYNC_KEYS,
		"c_animation_frame_event_type",
		SYNCKEYBLOCK_ID)
	{
		{ _field_enum, "key", &frame_event_type_new },
		{ _field_terminator }
	};

	#define STRINGBLOCK_ID { 0xB75016D8, 0xEA3C4FFD, 0x87191515, 0x56803132 }
	TAG_BLOCK(
		StringBlock_block,
		"StringBlock",
		k_kilo,
		"string_id",
		STRINGBLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	#define G_COMPOSITETAG_STRUCT_ID { 0xCE71BB1A, 0x50AB45ED, 0x90C7C874, 0x047FF664 }
	TAG_STRUCT(
		g_compositeTag_struct,
		"g_compositeTag_struct",
		"CompositeTag",
		G_COMPOSITETAG_STRUCT_ID)
	{
		{ _field_string_id, "name" },
		{ _field_block, "axes", &CompositeAxisDefinition_block },
		{ _field_block, "anims", &CompositeEntryDefinition_block },
		{ _field_block, "sets", &CompositePhaseSetDefinition_block },
		{ _field_block, "strings", &StringBlock_block },
		{ _field_string_id, "timing source" },
		{ _field_short_integer, "timingAnimIndex" },
		FIELD_PAD("PAD", nullptr, 2),
		{ _field_terminator }
	};

	STRINGS(CompositeAxisFlags)
	{
		"wrapped",
		"clamped"
	};
	STRING_LIST(CompositeAxisFlags, CompositeAxisFlags_strings, _countof(CompositeAxisFlags_strings));

} // namespace macaque

} // namespace blofeld

