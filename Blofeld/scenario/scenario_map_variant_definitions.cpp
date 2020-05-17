#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(mapVariantPaletteDependencyBlock, k_maximum_simultaneous_tag_instances)
	{
		FIELD( _field_tag, "tag" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(resourceHandleBlock, k_maximum_simultaneous_tag_instances)
	{
		FIELD( _field_long_integer, "resourceHandle" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(map_variant_object_variant_block, k_maximum_object_variants_per_map_variant_palette_entry)
	{
		FIELD( _field_string_id, "display name^" ),
		FIELD( _field_tag_reference, "object" ),
		FIELD( _field_string_id, "variant name" ),
		FIELD( _field_struct, "resource dependencies!*", &mapVariantResourceManifest_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(map_variant_palette_entry_block, k_maximum_map_variant_palette_entries)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_block, "variants", &map_variant_object_variant_block_block ),
		FIELD( _field_long_integer, "maximum allowed#if this is <= 0, these are \'unlimited\' (up to a reasonable code-defined maximum)" ),
		FIELD( _field_long_integer, "price per instance" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(map_variant_palette_block, k_maximum_map_variant_palettes)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_byte_flags, "flags", &map_variant_palette_flags ),
		FIELD( _field_pad, "pad", 3 ),
		FIELD( _field_block, "entries", &map_variant_palette_entry_block_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(mapVariantResourceManifest)
	{
		FIELD( _field_block, "attachedResourceOwners", &mapVariantPaletteDependencyBlock_block ),
		FIELD( _field_block, "topLevelResourceOwners", &mapVariantPaletteDependencyBlock_block ),
		FIELD( _field_block, "attachedResources", &resourceHandleBlock_block ),
		FIELD( _field_block, "orphanedResources", &resourceHandleBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(map_variant_palette_flags, 1)
	{
		OPTION("hidden#this palette is only visible in superforge, and objects within it are only editable in superforge"),
	};

} // namespace blofeld

