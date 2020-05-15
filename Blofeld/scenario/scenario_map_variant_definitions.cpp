#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(map_variant_palette, k_maximum_map_variant_palettes)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad", 3 ),
	FIELD( _field_block, "entries", &map_variant_palette_entry_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(map_variant_palette_entry, k_maximum_map_variant_palette_entries)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_block, "variants", &map_variant_object_variant_block ),
	FIELD( _field_long_integer, "maximum allowed#if this is <= 0, these are \'unlimited\' (up to a reasonable code-defined maximum)" ),
	FIELD( _field_long_integer, "price per instance" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(map_variant_object_variant, k_maximum_object_variants_per_map_variant_palette_entry)
{
	FIELD( _field_string_id, "display name^" ),
	FIELD( _field_tag_reference, "object" ),
	FIELD( _field_string_id, "variant name" ),
	FIELD( _field_struct, "resource dependencies!*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

