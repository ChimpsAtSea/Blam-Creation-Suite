#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_damage_info, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_string_id, "global indirect material name#absorbes AOE or child damage" ),
	FIELD( _field_custom_short_block_index, "indirect damage section#absorbes AOE or child damage" ),
	FIELD( _field_pad, "XN", 2 ),
	FIELD( _field_pad, "LPVYKO", 4 ),
	FIELD( _field_char_enum, "collision damage reporting type" ),
	FIELD( _field_char_enum, "response damage reporting type" ),
	FIELD( _field_pad, "MQ", 2 ),
	FIELD( _field_pad, "MYON", 20 ),
	FIELD( _field_explanation, "body" ),
	FIELD( _field_struct, "body" ),
	FIELD( _field_pad, "IKEIDYSCX", 64 ),
	FIELD( _field_explanation, "shield" ),
	FIELD( _field_struct, "shield" ),
	FIELD( _field_block, "damage sections", &global_damage_section_block ),
	FIELD( _field_block, "nodes*", &global_damage_nodes_block ),
	FIELD( _field_short_integer, "runtime shield material type!*" ),
	FIELD( _field_short_integer, "runtime indirect material type!*" ),
	FIELD( _field_real, "runtime shield recharge velocity!*" ),
	FIELD( _field_real, "runtime overcharge velocity!*" ),
	FIELD( _field_real, "runtime health recharge velocity!*" ),
	FIELD( _field_block, "damage seats", &damage_seat_info_block ),
	FIELD( _field_block, "damage constraints", &damage_constraint_info_block ),
	FIELD( _field_explanation, "overshield" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_damage_section, MAXIMUM_DAMAGE_SECTIONS_PER_MODEL)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_explanation, "damage section flags" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_real_fraction, "vitality percentage:[0.1]#percentage of total object vitality" ),
	FIELD( _field_block, "instant responses", &instantaneous_damage_repsonse_block ),
	FIELD( _field_block, "unused0", &g_null_block ),
	FIELD( _field_block, "unused1", &g_null_block ),
	FIELD( _field_real, "stun time:seconds" ),
	FIELD( _field_real, "recharge time:seconds" ),
	FIELD( _field_real, "runtime recharge velocity!*" ),
	FIELD( _field_string_id, "resurrection restored region name" ),
	FIELD( _field_short_integer, "runtime resurrection restored region index!*" ),
	FIELD( _field_pad, "AG", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(instantaneous_damage_repsonse, MAXIMUM_RESPONSES_PER_DAMAGE_SECTION)
{
	FIELD( _field_enum, "response type" ),
	FIELD( _field_explanation, "Constraint damage type" ),
	FIELD( _field_enum, "constraint damage type" ),
	FIELD( _field_explanation, "Constraint destruction" ),
	FIELD( _field_string_id, "constraint/group name" ),
	FIELD( _field_explanation, "Damage response flags" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_long_flags, "flags2" ),
	FIELD( _field_real_fraction, "damage threshold#response fires after crossing this threshold.  1=full health" ),
	FIELD( _field_long_flags, "body threshold flags" ),
	FIELD( _field_real, "body damage threshold#response fires after object body damage crosses this threshold, numbers can be negative.  You need to set the flag \"body threshold active\" for this number to be used. 1=full health" ),
	FIELD( _field_tag_reference, "transition effect (generic){transition effect}" ),
	FIELD( _field_tag_reference, "transition effect (specific)" ),
	FIELD( _field_struct, "damage effect" ),
	FIELD( _field_string_id, "region" ),
	FIELD( _field_enum, "new state" ),
	FIELD( _field_short_integer, "runtime region index!*" ),
	FIELD( _field_string_id, "region (secondary)" ),
	FIELD( _field_enum, "new state (secondary)" ),
	FIELD( _field_short_integer, "runtime region index (secondary)!*" ),
	FIELD( _field_short_block_index, "destroy instance group#all possible instances from this group will be destroyed" ),
	FIELD( _field_enum, "custom response behavior" ),
	FIELD( _field_string_id, "custom response label" ),
	FIELD( _field_string_id, "effect marker name" ),
	FIELD( _field_struct, "damage effect marker" ),
	FIELD( _field_explanation, "Response delay" ),
	FIELD( _field_real, "response delay#in seconds" ),
	FIELD( _field_tag_reference, "delay effect" ),
	FIELD( _field_string_id, "delay effect marker name" ),
	FIELD( _field_real, "response delay premature damage threshold" ),
	FIELD( _field_explanation, "seat ejaculation" ),
	FIELD( _field_string_id, "ejecting seat label" ),
	FIELD( _field_explanation, "skip fraction" ),
	FIELD( _field_real_fraction, "skip fraction" ),
	FIELD( _field_explanation, "destroyed child object marker name" ),
	FIELD( _field_string_id, "destroyed child object marker name" ),
	FIELD( _field_explanation, "total damage threshold" ),
	FIELD( _field_real_fraction, "total damage threshold" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_damage_nodes, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_short_integer, "runtime damage part!*" ),
	FIELD( _field_pad, "EOT", 2 ),
	FIELD( _field_pad, "SBFL", 12 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_seat_info, MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL)
{
	FIELD( _field_string_id, "seat label^" ),
	FIELD( _field_real_fraction, "direct damage scale#0==no damage, 1==full damage" ),
	FIELD( _field_real, "damage transfer fall-off radius" ),
	FIELD( _field_real, "maximum transfer damage scale" ),
	FIELD( _field_real, "minimum transfer damage scale" ),
	FIELD( _field_block, "region-specific-damage", &damage_seat_region_setting_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_seat_region_setting, 1)
{
	FIELD( _field_explanation, "region-state-specific-damage" ),
	FIELD( _field_string_id, "damage region name" ),
	FIELD( _field_short_integer, "runtime damage region index!*" ),
	FIELD( _field_pad, "EOQ", 2 ),
	FIELD( _field_real, "direct damage scale (minor)" ),
	FIELD( _field_real, "Max. transfer scale (minor)" ),
	FIELD( _field_real, "min. transfer scale (minor)" ),
	FIELD( _field_real, "direct damage scale (medium)" ),
	FIELD( _field_real, "Max. transfer scale (medium)" ),
	FIELD( _field_real, "min. transfer scale (medium)" ),
	FIELD( _field_real, "direct damage scale (major)" ),
	FIELD( _field_real, "Max. transfer scale (major)" ),
	FIELD( _field_real, "min. transfer scale (major)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(damage_constraint_info, MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL)
{
	FIELD( _field_string_id, "physics model constraint name" ),
	FIELD( _field_string_id, "damage constraint name" ),
	FIELD( _field_string_id, "damage constraint group name" ),
	FIELD( _field_real, "group probability scale" ),
	FIELD( _field_short_integer, "runtime constraint type!*" ),
	FIELD( _field_short_integer, "runtime constraint index!*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

