#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(global_damage_info, 1)
{
	{ _field_long_flags, "flags" },
	{ _field_string_id, "global indirect material name#absorbes AOE or child damage" },
	{ _field_custom_short_block_index, "indirect damage section#absorbes AOE or child damage" },
	{ _field_pad, "XN", 2 },
	{ _field_pad, "LPVYKO", 4 },
	{ _field_char_enum, "collision damage reporting type" },
	{ _field_char_enum, "response damage reporting type" },
	{ _field_pad, "MQ", 2 },
	{ _field_pad, "MYON", 20 },
	{ _field_explanation, "body" },
	{ _field_struct, "body" },
	{ _field_pad, "IKEIDYSCX", 64 },
	{ _field_explanation, "shield" },
	{ _field_struct, "shield" },
	{ _field_block, "damage sections", &global_damage_section_block },
	{ _field_block, "nodes*", &global_damage_nodes_block },
	{ _field_short_integer, "runtime shield material type!*" },
	{ _field_short_integer, "runtime indirect material type!*" },
	{ _field_real, "runtime shield recharge velocity!*" },
	{ _field_real, "runtime overcharge velocity!*" },
	{ _field_real, "runtime health recharge velocity!*" },
	{ _field_block, "damage seats", &damage_seat_info_block },
	{ _field_block, "damage constraints", &damage_constraint_info_block },
	{ _field_explanation, "overshield" },
	{ _field_terminator },
};

TAG_BLOCK(global_damage_section, MAXIMUM_DAMAGE_SECTIONS_PER_MODEL)
{
	{ _field_string_id, "name^" },
	{ _field_explanation, "damage section flags" },
	{ _field_long_flags, "flags" },
	{ _field_real_fraction, "vitality percentage:[0.1]#percentage of total object vitality" },
	{ _field_block, "instant responses", &instantaneous_damage_repsonse_block },
	{ _field_block, "unused0", &g_null_block },
	{ _field_block, "unused1", &g_null_block },
	{ _field_real, "stun time:seconds" },
	{ _field_real, "recharge time:seconds" },
	{ _field_real, "runtime recharge velocity!*" },
	{ _field_string_id, "resurrection restored region name" },
	{ _field_short_integer, "runtime resurrection restored region index!*" },
	{ _field_pad, "AG", 2 },
	{ _field_terminator },
};

TAG_BLOCK(instantaneous_damage_repsonse, MAXIMUM_RESPONSES_PER_DAMAGE_SECTION)
{
	{ _field_enum, "response type" },
	{ _field_explanation, "Constraint damage type" },
	{ _field_enum, "constraint damage type" },
	{ _field_explanation, "Constraint destruction" },
	{ _field_string_id, "constraint/group name" },
	{ _field_explanation, "Damage response flags" },
	{ _field_long_flags, "flags" },
	{ _field_long_flags, "flags2" },
	{ _field_real_fraction, "damage threshold#response fires after crossing this threshold.  1=full health" },
	{ _field_long_flags, "body threshold flags" },
	{ _field_real, "body damage threshold#response fires after object body damage crosses this threshold, numbers can be negative.  You need to set the flag \"body threshold active\" for this number to be used. 1=full health" },
	{ _field_tag_reference, "transition effect (generic){transition effect}" },
	{ _field_tag_reference, "transition effect (specific)" },
	{ _field_struct, "damage effect" },
	{ _field_string_id, "region" },
	{ _field_enum, "new state" },
	{ _field_short_integer, "runtime region index!*" },
	{ _field_string_id, "region (secondary)" },
	{ _field_enum, "new state (secondary)" },
	{ _field_short_integer, "runtime region index (secondary)!*" },
	{ _field_short_block_index, "destroy instance group#all possible instances from this group will be destroyed" },
	{ _field_enum, "custom response behavior" },
	{ _field_string_id, "custom response label" },
	{ _field_string_id, "effect marker name" },
	{ _field_struct, "damage effect marker" },
	{ _field_explanation, "Response delay" },
	{ _field_real, "response delay#in seconds" },
	{ _field_tag_reference, "delay effect" },
	{ _field_string_id, "delay effect marker name" },
	{ _field_real, "response delay premature damage threshold" },
	{ _field_explanation, "seat ejaculation" },
	{ _field_string_id, "ejecting seat label" },
	{ _field_explanation, "skip fraction" },
	{ _field_real_fraction, "skip fraction" },
	{ _field_explanation, "destroyed child object marker name" },
	{ _field_string_id, "destroyed child object marker name" },
	{ _field_explanation, "total damage threshold" },
	{ _field_real_fraction, "total damage threshold" },
	{ _field_terminator },
};

TAG_BLOCK(global_damage_nodes, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_short_integer, "runtime damage part!*" },
	{ _field_pad, "EOT", 2 },
	{ _field_pad, "SBFL", 12 },
	{ _field_terminator },
};

TAG_BLOCK(damage_seat_info, MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL)
{
	{ _field_string_id, "seat label^" },
	{ _field_real_fraction, "direct damage scale#0==no damage, 1==full damage" },
	{ _field_real, "damage transfer fall-off radius" },
	{ _field_real, "maximum transfer damage scale" },
	{ _field_real, "minimum transfer damage scale" },
	{ _field_block, "region-specific-damage", &damage_seat_region_setting_block },
	{ _field_terminator },
};

TAG_BLOCK(damage_seat_region_setting, 1)
{
	{ _field_explanation, "region-state-specific-damage" },
	{ _field_string_id, "damage region name" },
	{ _field_short_integer, "runtime damage region index!*" },
	{ _field_pad, "EOQ", 2 },
	{ _field_real, "direct damage scale (minor)" },
	{ _field_real, "Max. transfer scale (minor)" },
	{ _field_real, "min. transfer scale (minor)" },
	{ _field_real, "direct damage scale (medium)" },
	{ _field_real, "Max. transfer scale (medium)" },
	{ _field_real, "min. transfer scale (medium)" },
	{ _field_real, "direct damage scale (major)" },
	{ _field_real, "Max. transfer scale (major)" },
	{ _field_real, "min. transfer scale (major)" },
	{ _field_terminator },
};

TAG_BLOCK(damage_constraint_info, MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL)
{
	{ _field_string_id, "physics model constraint name" },
	{ _field_string_id, "damage constraint name" },
	{ _field_string_id, "damage constraint group name" },
	{ _field_real, "group probability scale" },
	{ _field_short_integer, "runtime constraint type!*" },
	{ _field_short_integer, "runtime constraint index!*" },
	{ _field_terminator },
};

} // namespace blofeld

