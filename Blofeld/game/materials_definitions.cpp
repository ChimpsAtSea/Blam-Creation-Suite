#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(materials, k_maximum_editable_material_types)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "parent name" ),
	FIELD( _field_short_integer, "runtime material index!" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_string_id, "general armor" ),
	FIELD( _field_string_id, "specific armor" ),
	FIELD( _field_struct, "wet proxies" ),
	FIELD( _field_short_integer, "runtime dry base material index!" ),
	FIELD( _field_pad, "RMBP1", 2 ),
	FIELD( _field_struct, "physics properties" ),
	FIELD( _field_tag_reference, "breakable surface" ),
	FIELD( _field_struct, "sweeteners" ),
	FIELD( _field_tag_reference, "material effects" ),
	FIELD( _field_block, "underwater proxies", &underwater_proxies_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(underwater_proxies, k_maximum_material_types)
{
	FIELD( _field_explanation, "when this material is encounted under a material of this type ..." ),
	FIELD( _field_string_id, "underwater material" ),
	FIELD( _field_explanation, "... we report it as this material" ),
	FIELD( _field_string_id, "proxy material" ),
	FIELD( _field_short_integer, "underwater material type*!" ),
	FIELD( _field_short_integer, "proxy material type*!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(runtime_materials, k_maximum_material_types)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "parent name" ),
	FIELD( _field_short_integer, "runtime material index!" ),
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_string_id, "general armor" ),
	FIELD( _field_string_id, "specific armor" ),
	FIELD( _field_struct, "wet proxies" ),
	FIELD( _field_short_integer, "runtime dry base material index!" ),
	FIELD( _field_pad, "RMBP1", 2 ),
	FIELD( _field_struct, "physics properties" ),
	FIELD( _field_tag_reference, "breakable surface" ),
	FIELD( _field_struct, "sweeteners" ),
	FIELD( _field_tag_reference, "material effects" ),
	FIELD( _field_block, "underwater proxies", &underwater_proxies_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

