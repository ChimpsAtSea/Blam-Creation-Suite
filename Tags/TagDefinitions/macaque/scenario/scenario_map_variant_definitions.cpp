#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MAP_VARIANT_PALETTE_BLOCK_ID { 0x650FDFED, 0x967F4D74, 0xA8A4A448, 0x74D1A04C }
	TAG_BLOCK(
		map_variant_palette_block,
		"map_variant_palette_block",
		k_maximum_map_variant_palettes,
		"s_map_variant_palette",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MAP_VARIANT_PALETTE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_byte_flags, "flags", &map_variant_palette_flags },
		FIELD_PAD("pad", nullptr, 3),
		{ _field_block, "entries", &map_variant_palette_entry_block },
		{ _field_terminator }
	};

	#define MAP_VARIANT_PALETTE_ENTRY_BLOCK_ID { 0x59340D8A, 0x6B2D46D7, 0x8684F40D, 0x41B5680C }
	TAG_BLOCK(
		map_variant_palette_entry_block,
		"map_variant_palette_entry_block",
		k_maximum_map_variant_palette_entries,
		"s_map_variant_palette_entry",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MAP_VARIANT_PALETTE_ENTRY_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_block, "variants", &map_variant_object_variant_block },
		{ _field_long_integer, "maximum allowed", "if this is <= 0, these are 'unlimited' (up to a reasonable code-defined maximum)" },
		{ _field_long_integer, "price per instance" },
		{ _field_terminator }
	};

	#define MAP_VARIANT_OBJECT_VARIANT_BLOCK_ID { 0x904D356F, 0x1B284614, 0x87F7F4D0, 0x90A8594D }
	TAG_BLOCK(
		map_variant_object_variant_block,
		"map_variant_object_variant_block",
		k_maximum_object_variants_per_map_variant_palette_entry,
		"s_map_variant_object_variant",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MAP_VARIANT_OBJECT_VARIANT_BLOCK_ID)
	{
		{ _field_string_id, "display name" },
		{ _field_tag_reference, "object", &object_reference$9 },
		{ _field_string_id, "variant name" },
		{ _field_struct, "resource dependencies", &mapVariantResourceManifest },
		{ _field_terminator }
	};

	#define MAPVARIANTPALETTEDEPENDENCYBLOCK_ID { 0x2662643F, 0x4E854FC7, 0x9C8653EB, 0xF80B243D }
	TAG_BLOCK(
		mapVariantPaletteDependencyBlock_block,
		"mapVariantPaletteDependencyBlock",
		k_maximum_simultaneous_tag_instances,
		"AnyTagHandle",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MAPVARIANTPALETTEDEPENDENCYBLOCK_ID)
	{
		{ _field_tag, "tag" },
		{ _field_terminator }
	};

	#define RESOURCEHANDLEBLOCK_ID { 0xD5ED98ED, 0xFBF04B93, 0xB1E0B2DC, 0x1F89A529 }
	TAG_BLOCK(
		resourceHandleBlock_block,
		"resourceHandleBlock",
		k_maximum_simultaneous_tag_instances,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RESOURCEHANDLEBLOCK_ID)
	{
		{ _field_long_integer, "resourceHandle" },
		{ _field_terminator }
	};

	#define MAPVARIANTRESOURCEMANIFEST_ID { 0x489BAAF5, 0x2DD44507, 0xB66346C4, 0x27F7ADCB }
	TAG_STRUCT(
		mapVariantResourceManifest,
		"mapVariantResourceManifest",
		"MapVariantObjectResourceManifest",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MAPVARIANTRESOURCEMANIFEST_ID)
	{
		{ _field_block, "attachedResourceOwners", &mapVariantPaletteDependencyBlock_block },
		{ _field_block, "topLevelResourceOwners", &mapVariantPaletteDependencyBlock_block },
		{ _field_block, "attachedResources", &resourceHandleBlock_block },
		{ _field_block, "orphanedResources", &resourceHandleBlock_block },
		{ _field_terminator }
	};

	STRINGS(map_variant_palette_flags)
	{
		"hidden#this palette is only visible in superforge, and objects within it are only editable in superforge"
	};
	STRING_LIST(map_variant_palette_flags, map_variant_palette_flags_strings, _countof(map_variant_palette_flags_strings));

} // namespace macaque

} // namespace blofeld

