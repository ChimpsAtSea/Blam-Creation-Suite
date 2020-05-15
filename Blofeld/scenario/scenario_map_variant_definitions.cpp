#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(map_variant_palette, k_maximum_map_variant_palettes)
{
	{ _field_string_id, "name^" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "pad", 3 },
	{ _field_block, "entries", &map_variant_palette_entry_block },
	{ _field_terminator },
};

TAG_BLOCK(map_variant_palette_entry, k_maximum_map_variant_palette_entries)
{
	{ _field_string_id, "name^" },
	{ _field_block, "variants", &map_variant_object_variant_block },
	{ _field_long_integer, "maximum allowed#if this is <= 0, these are \'unlimited\' (up to a reasonable code-defined maximum)" },
	{ _field_long_integer, "price per instance" },
	{ _field_terminator },
};

TAG_BLOCK(map_variant_object_variant, k_maximum_object_variants_per_map_variant_palette_entry)
{
	{ _field_string_id, "display name^" },
	{ _field_tag_reference, "object" },
	{ _field_string_id, "variant name" },
	{ _field_struct, "resource dependencies!*" },
	{ _field_terminator },
};

} // namespace blofeld

