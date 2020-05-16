#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(g_compositeTag_struct)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_block, "axes*", &CompositeAxisDefinition ),
	FIELD( _field_block, "anims*", &CompositeEntryDefinition ),
	FIELD( _field_block, "sets*", &CompositePhaseSetDefinition ),
	FIELD( _field_block, "strings*", &StringBlock ),
	FIELD( _field_string_id, "timing source" ),
	FIELD( _field_short_integer, "timingAnimIndex*!" ),
	FIELD( _field_pad, "PAD", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(g_compositeTag, MAX_COMPOSITES_PER_GRAPH, g_compositeTag_struct_struct_definition );

TAG_BLOCK(CompositeAxisDefinition, MAX_VALUES_PER_COMPOSITE_ENTRY)
{
	FIELD( _field_string_id, "name*!^" ),
	FIELD( _field_string_id, "animation source*" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "input function" ),
	FIELD( _field_real_bounds, "animation bounds" ),
	FIELD( _field_real_bounds, "input bounds" ),
	FIELD( _field_real_bounds, "clamp bounds" ),
	FIELD( _field_real, "blend limit*" ),
	FIELD( _field_block, "dead zones", &CompositeDeadZoneDefinition ),
	FIELD( _field_char_integer, "divisions*" ),
	FIELD( _field_char_integer, "priority*" ),
	FIELD( _field_char_integer, "update*" ),
	FIELD( _field_char_integer, "functionIndex*" ),
	FIELD( _field_long_flags, "flags*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CompositeDeadZoneDefinition, MAX_DEAD_ZONES_PER_COMPOSITE_AXIS)
{
	FIELD( _field_real_bounds, "bounds" ),
	FIELD( _field_real, "rate" ),
	FIELD( _field_real, "center*!" ),
	FIELD( _field_real, "radius*!" ),
	FIELD( _field_real, "amount*!" ),
	FIELD( _field_long_integer, "delay*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CompositeEntryDefinition, MAX_ENTRIES_PER_COMPOSITE)
{
	FIELD( _field_string_id, "source^" ),
	FIELD( _field_block, "values*", &CompositeEntryValueDefinition ),
	FIELD( _field_long_integer, "overridden*!" ),
	FIELD( _field_short_integer, "animIndex*!" ),
	FIELD( _field_char_integer, "slideAxis*" ),
	FIELD( _field_pad, "PAD", 1 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CompositeEntryValueDefinition, MAX_VALUES_PER_COMPOSITE_ENTRY)
{
	FIELD( _field_real, "value^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(CompositePhaseSetDefinition, MAX_PHASE_SETS_PER_COMPOSITE)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_string_id, "timing source" ),
	FIELD( _field_block, "sync points", &SyncKeyBlock ),
	FIELD( _field_data, "sync frames*!" ),
	FIELD( _field_data, "facets*" ),
	FIELD( _field_data, "neighbors*" ),
	FIELD( _field_data, "containment*" ),
	FIELD( _field_data, "example grid*" ),
	FIELD( _field_real_bounds, "normalized bounds" ),
	FIELD( _field_char_integer, "offset*" ),
	FIELD( _field_pad, "PAD", 1 ),
	FIELD( _field_short_integer, "timingAnimIndex*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(SyncKeyBlock, Composite::MAX_SYNC_KEYS)
{
	FIELD( _field_enum, "key*^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(StringBlock, k_kilo)
{
	FIELD( _field_string_id, "name*^" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

