#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(materials, k_maximum_editable_material_types)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "parent name" },
	{ _field_short_integer, "runtime material index!" },
	{ _field_word_flags, "flags" },
	{ _field_string_id, "general armor" },
	{ _field_string_id, "specific armor" },
	{ _field_struct, "wet proxies" },
	{ _field_short_integer, "runtime dry base material index!" },
	{ _field_pad, "RMBP1", 2 },
	{ _field_struct, "physics properties" },
	{ _field_tag_reference, "breakable surface" },
	{ _field_struct, "sweeteners" },
	{ _field_tag_reference, "material effects" },
	{ _field_block, "underwater proxies", &underwater_proxies_block },
	{ _field_terminator },
};

TAG_BLOCK(underwater_proxies, k_maximum_material_types)
{
	{ _field_explanation, "when this material is encounted under a material of this type ..." },
	{ _field_string_id, "underwater material" },
	{ _field_explanation, "... we report it as this material" },
	{ _field_string_id, "proxy material" },
	{ _field_short_integer, "underwater material type*!" },
	{ _field_short_integer, "proxy material type*!" },
	{ _field_terminator },
};

TAG_BLOCK(runtime_materials, k_maximum_material_types)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "parent name" },
	{ _field_short_integer, "runtime material index!" },
	{ _field_word_flags, "flags" },
	{ _field_string_id, "general armor" },
	{ _field_string_id, "specific armor" },
	{ _field_struct, "wet proxies" },
	{ _field_short_integer, "runtime dry base material index!" },
	{ _field_pad, "RMBP1", 2 },
	{ _field_struct, "physics properties" },
	{ _field_tag_reference, "breakable surface" },
	{ _field_struct, "sweeteners" },
	{ _field_tag_reference, "material effects" },
	{ _field_block, "underwater proxies", &underwater_proxies_block },
	{ _field_terminator },
};

} // namespace blofeld

