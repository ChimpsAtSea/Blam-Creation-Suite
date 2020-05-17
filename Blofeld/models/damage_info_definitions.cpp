#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(model_state_enum_definition, 5)
	{
		OPTION("default"),
		OPTION("minor damage"),
		OPTION("medium damage"),
		OPTION("major damage"),
		OPTION("destroyed"),
	};

	TAG_ENUM(object_damage_aftermath_special_damage_type_enum, 5)
	{
		OPTION("none"),
		OPTION("headshot"),
		OPTION("melee"),
		OPTION("collision"),
		OPTION("assassination"),
	};

	TAG_ENUM(model_damage_info_flags_definition, 17)
	{
		OPTION("takes shield damage for children"),
		OPTION("takes body damage for children"),
		OPTION("always shields friendly damage"),
		OPTION("passes area damage to children"),
		OPTION("parent never takes body damage for us"),
		OPTION("only damaged by explosives"),
		OPTION("parent never takes shield damage for us"),
		OPTION("cannot die from damage"),
		OPTION("passes attached damage to riders"),
		OPTION("shield depletion is permanent"),
		OPTION("shield depletion force hard ping"),
		OPTION("AI do not damage without player"),
		OPTION("health regrows while dead"),
		OPTION("shield recharge plays only when empty"),
		OPTION("IGNORE force minimum transfer"),
		OPTION("orphan from postprocess autogen#check this to take control of the new damage info tag block"),
		OPTION("only damaged by boarding damage"),
	};

	TAG_ENUM(damage_section_flags_definition, 12)
	{
		OPTION("absorbs body damage"),
		OPTION("takes full dmg when object dies"),
		OPTION("cannot die with riders"),
		OPTION("takes full dmg when obj dstryd"),
		OPTION("restored on ressurection"),
		OPTION("unused0!"),
		OPTION("unused1!"),
		OPTION("heatshottable"),
		OPTION("ignores shields"),
		OPTION("takes full dmg when shield depl"),
		OPTION("networked (e.g. armor lock)"),
		OPTION("allow damage response overflow"),
	};

	TAG_ENUM(damage_response_type_enum_definition, 3)
	{
		OPTION("receives all damage"),
		OPTION("receives area effect damage"),
		OPTION("receives local damage"),
	};

	TAG_ENUM(damage_response_constraint_damage_type_enum_definition, 5)
	{
		OPTION("none"),
		OPTION("destroy one of group#sets the attached body of this constraint free"),
		OPTION("destroy entire group#sets the attached body of all constraints free"),
		OPTION("loosen one of group#takes this constraint out of the rigid state - activates it"),
		OPTION("loosen entire group#takes all constraints out of the rigid state - activates them"),
	};

	TAG_ENUM(damage_response_set1, 32)
	{
		OPTION("kills object#when the response fires the object dies regardless of its current health"),
		OPTION("inhibits melee attack#from halo 1 - disallows melee for a unit"),
		OPTION("inhibits weapon attack#from halo 1 - disallows weapon fire for a unit"),
		OPTION("inhibits walking#from halo 1 - disallows walking for a unit"),
		OPTION("forces drop weapon#from halo 1 - makes the unit drop its current weapon"),
		OPTION("kills weapon primary trigger"),
		OPTION("kills weapon secondary trigger"),
		OPTION("destroys object#when the response fires the object is destroyed"),
		OPTION("damages weapon primary trigger#destroys the primary trigger on the unit\'s current weapon"),
		OPTION("damages weapon secondary trigger#destroys the secondary trigger on the unit\'s current weapon"),
		OPTION("light damage left turn"),
		OPTION("major damage left turn"),
		OPTION("light damage right turn"),
		OPTION("major damage right turn"),
		OPTION("light damage engine"),
		OPTION("major damage engine"),
		OPTION("kills object (no player solo)"),
		OPTION("causes detonation"),
		OPTION("fires on creation"),
		OPTION("kills variant objects"),
		OPTION("force unattached effects"),
		OPTION("fires under threshold"),
		OPTION("triggers special death"),
		OPTION("only on special death"),
		OPTION("only NOT on special death"),
		OPTION("buckles giants"),
		OPTION("causes sp detonation"),
		OPTION("skip sounds on generic effect"),
		OPTION("kills giants"),
		OPTION("skip sounds on special death"),
		OPTION("cause head dismemberment"),
		OPTION("cause left leg dismemberment"),
	};

	TAG_ENUM(damage_response_set2, 4)
	{
		OPTION("cause right leg dismemberment"),
		OPTION("cause left arm dismemberment"),
		OPTION("cause right arm dismemberment"),
		OPTION("allow damage recharge overflow"),
	};

	TAG_ENUM(damage_response_body_threshold_flags_definition, 1)
	{
		OPTION("body threshold active#this resoponse fires when the body healh fraction crosses this boundary"),
	};

	TAG_ENUM(damage_response_custom_response_behavior_enum_definition, 3)
	{
		OPTION("plays always"),
		OPTION("plays if labels match"),
		OPTION("plays if labels differ"),
	};

	TAG_ENUM(new_model_damage_info_flags_definition, 5)
	{
		OPTION("takes damage for children#useful for bipeds shielding/taking damage for weapons"),
		OPTION("parent never takes damage for us#useful for attached shields"),
		OPTION("cannot die from damage"),
		OPTION("dies with riders"),
		OPTION("passes area damage to children"),
	};

	TAG_ENUM(new_damage_section_flags_definition, 10)
	{
		OPTION("starts inactive#this section will be initialized with zero health and will be stunned indefinitely"),
		OPTION("takes full dmg when object dies"),
		OPTION("takes full dmg when obj dstryd"),
		OPTION("restored on ressurection"),
		OPTION("headshot#takes extra headshot damage when shot"),
		OPTION("depletion is permanent"),
		OPTION("recharges while dead"),
		OPTION("play recharge effect only when empty"),
		OPTION("networked (note that primary body and shield are always networked)"),
		OPTION("can recharge independently#always a shield layer to recharge even if there is an inner shield layer that is stunned"),
	};

	TAG_ENUM(newDamageResponseFlagsPart1, 32)
	{
		OPTION("kills object#when the response fires the object dies regardless of its current health"),
		OPTION("inhibits melee attack#from halo 1 - disallows melee for a unit"),
		OPTION("inhibits weapon attack#from halo 1 - disallows weapon fire for a unit"),
		OPTION("inhibits walking#from halo 1 - disallows walking for a unit"),
		OPTION("forces drop weapon#from halo 1 - makes the unit drop its current weapon"),
		OPTION("kills weapon primary trigger"),
		OPTION("kills weapon secondary trigger"),
		OPTION("destroys object#when the response fires the object is destroyed"),
		OPTION("damages weapon primary trigger#destroys the primary trigger on the unit\'s current weapon"),
		OPTION("damages weapon secondary trigger#destroys the secondary trigger on the unit\'s current weapon"),
		OPTION("kills object (no player solo)"),
		OPTION("causes detonation"),
		OPTION("kills variant objects"),
		OPTION("force unattached effects"),
		OPTION("fires under threshold"),
		OPTION("triggers special death"),
		OPTION("only on special death"),
		OPTION("only NOT on special death"),
		OPTION("buckles giants"),
		OPTION("causes sp detonation"),
		OPTION("skip sounds on generic effect"),
		OPTION("kills giants"),
		OPTION("skip sounds on special death"),
		OPTION("force hard ping"),
		OPTION("can refire#can fire again if the section ever recharges past its threshold"),
		OPTION("can skip transition effects#will not spawn effects if previous response also fired"),
		OPTION("cause head dismemberment"),
		OPTION("cause left leg dismemberment"),
		OPTION("cause right leg dismemberment"),
		OPTION("cause left arm dismemberment"),
		OPTION("cause right arm dismemberment"),
		OPTION("allow damage recharge overflow"),
	};

	TAG_ENUM(newDamageResponseFlagsPart2, 1)
	{
		OPTION("hides object if destroyed by response on predicted client#if the destroys object flag and this flag are both checked, the object will be hidden on predicted clients when the response fires (hologram hack)"),
	};

	TAG_ENUM(damage_transfer_flags_definition, 7)
	{
		OPTION("transfer damage to damage section"),
		OPTION("transfer damage to parent"),
		OPTION("transfer damage to children"),
		OPTION("transfer damage to seats"),
		OPTION("transfer direct damage"),
		OPTION("transfer AOE exposed damage"),
		OPTION("transfer AOE obstructed damage"),
	};

	TAG_ENUM(damage_transfer_function_enum_definition, 3)
	{
		OPTION("percent"),
		OPTION("points"),
		OPTION("ceiling"),
	};

	TAG_BLOCK(global_damage_info_block, 1)
	{
		FIELD( _field_long_flags, "flags", &model_damage_info_flags_definition ),
		FIELD( _field_string_id, "global indirect material name#absorbes AOE or child damage" ),
		FIELD( _field_custom_short_block_index, "indirect damage section#absorbes AOE or child damage" ),
		FIELD( _field_pad, "XN", 2 ),
		FIELD( _field_pad, "LPVYKO", 4 ),
		FIELD( _field_char_enum, "collision damage reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_char_enum, "response damage reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_pad, "MQ", 2 ),
		FIELD( _field_pad, "MYON", 20 ),
		FIELD( _field_explanation, "body" ),
		FIELD( _field_struct, "body", &damage_body_parameters_struct_struct_definition ),
		FIELD( _field_pad, "IKEIDYSCX", 64 ),
		FIELD( _field_explanation, "shield" ),
		FIELD( _field_struct, "shield", &damage_shield_parameters_struct_struct_definition ),
		FIELD( _field_block, "damage sections", &global_damage_section_block_block ),
		FIELD( _field_block, "nodes*", &global_damage_nodes_block_block ),
		FIELD( _field_short_integer, "runtime shield material type!*" ),
		FIELD( _field_short_integer, "runtime indirect material type!*" ),
		FIELD( _field_real, "runtime shield recharge velocity!*" ),
		FIELD( _field_real, "runtime overcharge velocity!*" ),
		FIELD( _field_real, "runtime health recharge velocity!*" ),
		FIELD( _field_block, "damage seats", &damage_seat_info_block_block ),
		FIELD( _field_block, "damage constraints", &damage_constraint_info_block_block ),
		FIELD( _field_explanation, "overshield" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(global_damage_section_block, MAXIMUM_DAMAGE_SECTIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_explanation, "damage section flags" ),
		FIELD( _field_long_flags, "flags", &damage_section_flags_definition ),
		FIELD( _field_real_fraction, "vitality percentage:[0.1]#percentage of total object vitality" ),
		FIELD( _field_block, "instant responses", &instantaneous_damage_repsonse_block_block ),
		FIELD( _field_block, "unused0", &g_null_block_block ),
		FIELD( _field_block, "unused1", &g_null_block_block ),
		FIELD( _field_real, "stun time:seconds" ),
		FIELD( _field_real, "recharge time:seconds" ),
		FIELD( _field_real, "runtime recharge velocity!*" ),
		FIELD( _field_string_id, "resurrection restored region name" ),
		FIELD( _field_short_integer, "runtime resurrection restored region index!*" ),
		FIELD( _field_pad, "AG", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(instantaneous_damage_repsonse_block, MAXIMUM_RESPONSES_PER_DAMAGE_SECTION)
	{
		FIELD( _field_enum, "response type", &damage_response_type_enum_definition ),
		FIELD( _field_explanation, "Constraint damage type" ),
		FIELD( _field_enum, "constraint damage type", &damage_response_constraint_damage_type_enum_definition ),
		FIELD( _field_explanation, "Constraint destruction" ),
		FIELD( _field_string_id, "constraint/group name" ),
		FIELD( _field_explanation, "Damage response flags" ),
		FIELD( _field_long_flags, "flags", &damage_response_set1 ),
		FIELD( _field_long_flags, "flags2", &damage_response_set2 ),
		FIELD( _field_real_fraction, "damage threshold#response fires after crossing this threshold.  1=full health" ),
		FIELD( _field_long_flags, "body threshold flags", &damage_response_body_threshold_flags_definition ),
		FIELD( _field_real, "body damage threshold#response fires after object body damage crosses this threshold, numbers can be negative.  You need to set the flag \"body threshold active\" for this number to be used. 1=full health" ),
		FIELD( _field_tag_reference, "transition effect (generic){transition effect}" ),
		FIELD( _field_tag_reference, "transition effect (specific)" ),
		FIELD( _field_struct, "damage effect", &instantaneous_response_damage_effect_struct_struct_definition ),
		FIELD( _field_string_id, "region" ),
		FIELD( _field_enum, "new state", &model_state_enum_definition ),
		FIELD( _field_short_integer, "runtime region index!*" ),
		FIELD( _field_string_id, "region (secondary)" ),
		FIELD( _field_enum, "new state (secondary)", &model_state_enum_definition ),
		FIELD( _field_short_integer, "runtime region index (secondary)!*" ),
		FIELD( _field_short_block_index, "destroy instance group#all possible instances from this group will be destroyed" ),
		FIELD( _field_enum, "custom response behavior", &damage_response_custom_response_behavior_enum_definition ),
		FIELD( _field_string_id, "custom response label" ),
		FIELD( _field_string_id, "effect marker name" ),
		FIELD( _field_struct, "damage effect marker", &instantaneous_response_damage_effect_marker_struct_struct_definition ),
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

	TAG_BLOCK(global_damage_nodes_block, MAXIMUM_NODES_PER_MODEL)
	{
		FIELD( _field_short_integer, "runtime damage part!*" ),
		FIELD( _field_pad, "EOT", 2 ),
		FIELD( _field_pad, "SBFL", 12 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_seat_info_block, MAXIMUM_DAMAGE_SEAT_INFOS_PER_MODEL)
	{
		FIELD( _field_string_id, "seat label^" ),
		FIELD( _field_real_fraction, "direct damage scale#0==no damage, 1==full damage" ),
		FIELD( _field_real, "damage transfer fall-off radius" ),
		FIELD( _field_real, "maximum transfer damage scale" ),
		FIELD( _field_real, "minimum transfer damage scale" ),
		FIELD( _field_block, "region-specific-damage", &damage_seat_region_setting_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_seat_region_setting_block, 1)
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

	TAG_BLOCK(damage_constraint_info_block, MAXIMUM_DAMAGE_CONSTRAINT_INFOS_PER_MODEL)
	{
		FIELD( _field_string_id, "physics model constraint name" ),
		FIELD( _field_string_id, "damage constraint name" ),
		FIELD( _field_string_id, "damage constraint group name" ),
		FIELD( _field_real, "group probability scale" ),
		FIELD( _field_short_integer, "runtime constraint type!*" ),
		FIELD( _field_short_integer, "runtime constraint index!*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(new_global_damage_section_block, MAXIMUM_DAMAGE_SECTIONS_PER_MODEL)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_long_flags, "flags", &new_damage_section_flags_definition ),
		FIELD( _field_real_fraction, "vitality percentage:[0.1]#percentage of total object vitality" ),
		FIELD( _field_string_id, "shield material name#set this to make this damage section a shield" ),
		FIELD( _field_explanation, "stun" ),
		FIELD( _field_real, "stun time:seconds" ),
		FIELD( _field_real, "minimum stun damage#the minimum damage required to stun this object\'s health" ),
		FIELD( _field_explanation, "recharge" ),
		FIELD( _field_real, "recharge time:seconds" ),
		FIELD( _field_block, "recharge speed curve", &damage_section_recharge_speed_curve_block_block ),
		FIELD( _field_block, "recharge fractions", &damage_section_segmented_recharge_fraction_block ),
		FIELD( _field_tag_reference, "recharging effect" ),
		FIELD( _field_real, "pre recharge effect warn time:seconds#(main shield only) how long before the recharge begins the pre-recharge effect fires" ),
		FIELD( _field_tag_reference, "pre recharge effect#(main shield only)" ),
		FIELD( _field_string_id, "pre recharge effect marker#(main shield only)" ),
		FIELD( _field_tag_reference, "pre recharge abort effect#(main shield only) if the pre-recharge effect is aborted before the actual recharge starts, this effect plays" ),
		FIELD( _field_string_id, "pre recharge abort effect marker#(main shield only)" ),
		FIELD( _field_explanation, "overcharge" ),
		FIELD( _field_real, "overcharge time:seconds#time it takes to reach full \"overcharge fraction\"" ),
		FIELD( _field_real, "overcharge fraction#fraction to which shields will automatically overcharge, values <= 1.0 are ignored" ),
		FIELD( _field_explanation, "decay" ),
		FIELD( _field_real, "pre decay time:seconds#time for this section to be active before it will start to decay" ),
		FIELD( _field_real, "decay time:seconds#time for need for this section to fully decay with full health." ),
		FIELD( _field_explanation, "resurrection" ),
		FIELD( _field_string_id, "resurrection restored region name" ),
		FIELD( _field_block, "instant responses", &new_instantaneous_damage_response_block_block ),
		FIELD( _field_block, "section damage transfers", &damage_transfer_block_block ),
		FIELD( _field_block, "rendering", &damage_section_rendering_paramters_block ),
		FIELD( _field_real, "runtime recharge velocity!*" ),
		FIELD( _field_real, "runtime overcharge velocity!*" ),
		FIELD( _field_short_integer, "runtime resurrection restored region index!*" ),
		FIELD( _field_short_integer, "runtime global shield material type!*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_section_recharge_speed_curve_block, 1)
	{
		FIELD( _field_custom ),
		FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_section_segmented_recharge_fraction, 16)
	{
		FIELD( _field_real_fraction, "vitality percentage:[0.1]#recharge will stop once this percentage of vitality is reached." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(new_instantaneous_damage_response_block, MAXIMUM_RESPONSES_PER_DAMAGE_SECTION)
	{
		FIELD( _field_long_flags, "flags", &newDamageResponseFlagsPart1 ),
		FIELD( _field_long_flags, "flags2", &newDamageResponseFlagsPart2 ),
		FIELD( _field_string_id, "label" ),
		FIELD( _field_real_fraction, "damage threshold#response fires after crossing this threshold.  1=full health" ),
		FIELD( _field_tag_reference, "transition effect (generic){transition effect}" ),
		FIELD( _field_string_id, "generic effect marker{effect marker name}" ),
		FIELD( _field_tag_reference, "transition effect (specific)" ),
		FIELD( _field_string_id, "specific effect marker" ),
		FIELD( _field_struct, "damage effect", &instantaneous_response_damage_effect_struct_struct_definition ),
		FIELD( _field_struct, "damage effect marker", &instantaneous_response_damage_effect_marker_struct_struct_definition ),
		FIELD( _field_tag_reference, "looping effect#will play until the next response is triggered." ),
		FIELD( _field_block, "region_transitions", &damage_response_region_transition_block_block ),
		FIELD( _field_block, "response damage transfers", &damage_transfer_block_block ),
		FIELD( _field_short_block_index, "destroy instance group#all possible instances from this group will be destroyed" ),
		FIELD( _field_enum, "custom response behavior", &damage_response_custom_response_behavior_enum_definition ),
		FIELD( _field_string_id, "custom response label" ),
		FIELD( _field_real, "response delay:seconds#time to wait until firing the response. This delay is pre-empted if another timed response for the same section fires." ),
		FIELD( _field_tag_reference, "delay effect#plays while the timer is counting down" ),
		FIELD( _field_string_id, "delay effect marker name" ),
		FIELD( _field_block, "seat eject", &seat_ejection_block_block ),
		FIELD( _field_real_fraction, "skip fraction#0.0 always fires, 1.0 never fires" ),
		FIELD( _field_string_id, "destroyed child object marker name#when this response fires, any children objects created at the supplied marker name will be destroyed" ),
		FIELD( _field_real_fraction, "total damage threshold#scale on total damage section vitality" ),
		FIELD( _field_string_id, "constraint/group name#can specify a randomly-selected single constraint or the entire group of named constraints" ),
		FIELD( _field_enum, "constraint damage type", &damage_response_constraint_damage_type_enum_definition ),
		FIELD( _field_pad, "IDRBCDT", 2 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_response_region_transition_block, 16)
	{
		FIELD( _field_string_id, "region" ),
		FIELD( _field_enum, "new state", &model_state_enum_definition ),
		FIELD( _field_short_integer, "runtime region index!*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_transfer_block, MAXIMUM_DAMAGE_TRANSFERS_PER_MODEL)
	{
		FIELD( _field_long_flags, "flags", &damage_transfer_flags_definition ),
		FIELD( _field_real, "transfer amount" ),
		FIELD( _field_enum, "transfer function", &damage_transfer_function_enum_definition ),
		FIELD( _field_short_block_index, "damage section" ),
		FIELD( _field_string_id, "seat label" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(seat_ejection_block, 8)
	{
		FIELD( _field_string_id, "seat label^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(damage_section_rendering_paramters, 1)
	{
		FIELD( _field_tag_reference, "3rd person impact parameters" ),
		FIELD( _field_tag_reference, "1st person impact parameters" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(damage_body_parameters_struct)
{
		FIELD( _field_real, "maximum vitality" ),
		FIELD( _field_real, "minimum stun damage#the minimum damage required to stun this object\'s health" ),
		FIELD( _field_real, "stun time:seconds#the length of time the health stay stunned (do not recharge) after taking damage" ),
		FIELD( _field_real, "recharge time:seconds#the length of time it would take for the shields to fully recharge after being completely depleted" ),
		FIELD( _field_real_fraction, "recharge fraction#0 defaults to 1 - to what maximum level the body health will be allowed to recharge" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(damage_shield_parameters_struct)
{
		FIELD( _field_real, "maximum shield vitality#the default initial and maximum shield vitality of this object" ),
		FIELD( _field_string_id, "global shield material name" ),
		FIELD( _field_real, "minimum stun damage#the minimum damage required to stun this object\'s shields" ),
		FIELD( _field_real, "stun time:seconds#the length of time the shields stay stunned (do not recharge) after taking damage" ),
		FIELD( _field_real, "recharge time:seconds#the length of time it would take for the shields to fully recharge after being completely depleted" ),
		FIELD( _field_real, "shield overcharge fraction#fraction to which shields will automatically overcharge, values <= 1.0 are ignored" ),
		FIELD( _field_real, "shield overcharge time#time it takes to reach full \"shield overcharge fraction\"" ),
		FIELD( _field_real, "shield damaged threshold" ),
		FIELD( _field_tag_reference, "shield damaged effect" ),
		FIELD( _field_tag_reference, "shield depleted effect" ),
		FIELD( _field_tag_reference, "shield recharging effect" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(instantaneous_response_damage_effect_struct)
{
		FIELD( _field_tag_reference, "transition damage effect" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(instantaneous_response_damage_effect_marker_struct)
{
		FIELD( _field_string_id, "damage effect marker name" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(model_damage_info_struct)
{
		FIELD( _field_explanation, "Damage Info" ),
		FIELD( _field_long_flags, "flags", &new_model_damage_info_flags_definition ),
		FIELD( _field_real, "maximum vitality#value of zero implies \'damage sections\' should be empty" ),
		FIELD( _field_string_id, "indirect material name#absorbes AOE or child damage" ),
		FIELD( _field_short_block_index, "indirect damage section#absorbes AOE or child damage" ),
		FIELD( _field_short_block_index, "shielded state damage section#the model\'s shielded/unshielded state reflects the depletion of this damage section" ),
		FIELD( _field_char_enum, "collision damage reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_char_enum, "response damage reporting type", &global_damage_reporting_enum_definition ),
		FIELD( _field_pad, "MDIBP0", 2 ),
		FIELD( _field_block, "damage sections", &new_global_damage_section_block_block ),
		FIELD( _field_block, "damage constraints", &damage_constraint_info_block_block ),
		FIELD( _field_block, "nodes*", &global_damage_nodes_block_block ),
		FIELD( _field_short_integer, "runtime indirect material type!*" ),
		FIELD( _field_pad, "MDIBP1", 2 ),
		FIELD( _field_terminator )
};

} // namespace blofeld

