#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(CompositeDeadZoneDefinition, MAX_DEAD_ZONES_PER_COMPOSITE_AXIS)
	{
		{ _field_real_bounds, "bounds" },
		{ _field_real, "rate" },
		{ _field_real, "center*!" },
		{ _field_real, "radius*!" },
		{ _field_real, "amount*!" },
		{ _field_long_integer, "delay*!" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(CompositeAxisDefinition, MAX_VALUES_PER_COMPOSITE_ENTRY)
	{
		{ _field_string_id, "name*!^" },
		{ _field_string_id, "animation source*" },
		{ _field_custom },
		{ _field_string_id, "input function" },
		{ _field_real_bounds, "animation bounds" },
		{ _field_real_bounds, "input bounds" },
		{ _field_real_bounds, "clamp bounds" },
		{ _field_real, "blend limit*" },
		{ _field_block, "dead zones", &CompositeDeadZoneDefinition_block },
		{ _field_char_integer, "divisions*" },
		{ _field_char_integer, "priority*" },
		{ _field_char_integer, "update*" },
		{ _field_char_integer, "functionIndex*" },
		{ _field_long_flags, "flags*", &CompositeAxisFlags },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(CompositeEntryValueDefinition, MAX_VALUES_PER_COMPOSITE_ENTRY)
	{
		{ _field_real, "value^" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(CompositeEntryDefinition, MAX_ENTRIES_PER_COMPOSITE)
	{
		{ _field_string_id, "source^" },
		{ _field_block, "values*", &CompositeEntryValueDefinition_block },
		{ _field_long_integer, "overridden*!" },
		{ _field_short_integer, "animIndex*!" },
		{ _field_char_integer, "slideAxis*" },
		{ _field_pad, "PAD", 1 },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(SyncKeyBlock, Composite::MAX_SYNC_KEYS)
	{
		{ _field_enum, "key*^", &frame_event_type_new },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(CompositePhaseSetDefinition, MAX_PHASE_SETS_PER_COMPOSITE)
	{
		{ _field_string_id, "name*^" },
		{ _field_string_id, "timing source" },
		{ _field_block, "sync points", &SyncKeyBlock_block },
		{ _field_data, "sync frames*!" },
		{ _field_data, "facets*" },
		{ _field_data, "neighbors*" },
		{ _field_data, "containment*" },
		{ _field_data, "example grid*" },
		{ _field_real_bounds, "normalized bounds" },
		{ _field_char_integer, "offset*" },
		{ _field_pad, "PAD", 1 },
		{ _field_short_integer, "timingAnimIndex*!" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(StringBlock, k_kilo)
	{
		{ _field_string_id, "name*^" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(g_compositeTag, MAX_COMPOSITES_PER_GRAPH, g_compositeTag_struct_struct_definition );

	V5_TAG_STRUCT(g_compositeTag_struct)
	{
		{ _field_string_id, "name*^" },
		{ _field_block, "axes*", &CompositeAxisDefinition_block },
		{ _field_block, "anims*", &CompositeEntryDefinition_block },
		{ _field_block, "sets*", &CompositePhaseSetDefinition_block },
		{ _field_block, "strings*", &StringBlock_block },
		{ _field_string_id, "timing source" },
		{ _field_short_integer, "timingAnimIndex*!" },
		{ _field_pad, "PAD", 2 },
		{ _field_terminator }
	};

	STRINGS(CompositeAxisFlags)
	{
		"wrapped",
		"clamped"
	};
	STRING_LIST(CompositeAxisFlags, CompositeAxisFlags_strings, _countof(CompositeAxisFlags_strings));

} // namespace blofeld

