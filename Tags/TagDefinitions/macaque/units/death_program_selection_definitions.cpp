#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		death_program_selector_group,
		DEATH_PROGRAM_SELECTOR_TAG,
		nullptr,
		INVALID_TAG,
		death_program_selector_block );

	TAG_BLOCK_FROM_STRUCT(
		death_program_selector_block,
		"death_program_selector_block",
		1,
		death_program_selector_struct_definition);

	#define DEATH_PROGRAM_SPECIAL_BLOCK_ID { 0x07A79880, 0x13514724, 0xBF5DA9E5, 0x8C25AAA7 }
	TAG_BLOCK(
		death_program_special_block,
		"death_program_special_block",
		k_maximum_death_program_special_types,
		"s_death_program_selector_special",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DEATH_PROGRAM_SPECIAL_BLOCK_ID)
	{
		{ _field_long_enum, "special type", FIELD_FLAG_INDEX, &object_damage_aftermath_special_damage_type_enum },
		{ _field_block, "damage type", &death_program_damage_reporting_block },
		{ _field_terminator }
	};

	#define DEATH_PROGRAM_DAMAGE_REPORTING_BLOCK_ID { 0x2411CA09, 0x6F034AF6, 0x906679AF, 0x012D9482 }
	TAG_BLOCK(
		death_program_damage_reporting_block,
		"death_program_damage_reporting_block",
		k_maximum_death_program_damage_types,
		"s_death_program_selector_damage_type",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DEATH_PROGRAM_DAMAGE_REPORTING_BLOCK_ID)
	{
		{ _field_long_enum, "damage type", FIELD_FLAG_INDEX, &global_damage_reporting_enum_definition },
		{ _field_block, "velocity", &death_program_velocity_gate_block },
		{ _field_terminator }
	};

	#define DEATH_PROGRAM_VELOCITY_GATE_BLOCK_ID { 0x500A180D, 0x00044EBB, 0xB940AA79, 0x9EBAFD18 }
	TAG_BLOCK(
		death_program_velocity_gate_block,
		"death_program_velocity_gate_block",
		k_maximum_death_program_velocity_gates,
		"s_death_program_selector_velocity_gate",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DEATH_PROGRAM_VELOCITY_GATE_BLOCK_ID)
	{
		{ _field_real, "minimum velocity", "this death program will be selected if the biped's velocity is above this number", "wu/s", FIELD_FLAG_INDEX },
		{ _field_long_enum, "death program", &death_program_result_enum },
		{ _field_real, "death program scale", "input to the death program to scale the result (only affects ragdolls)" },
		{ _field_string_id, "death animation stance", "Override stance that contains the death animations for this gait speed when using animate then ragdoll option." },
		{ _field_terminator }
	};

	#define DEATH_PROGRAM_SELECTOR_STRUCT_DEFINITION_ID { 0x4017D7F3, 0x78A848E8, 0x90B37B9F, 0x63AE0A5B }
	TAG_STRUCT(
		death_program_selector_struct_definition,
		"death_program_selector_struct_definition",
		"s_death_program_selector",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		DEATH_PROGRAM_SELECTOR_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("Explanation", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Death Program Selection", nullptr, FIELD_FLAG_NONE, "There are 3 levels of filtering for this.  Certain combinations of the first two levels are either impossible or redundant.  This is because they come from different places in the damage code. I will try to make that clearer here:\n\nThe first level of filtering is a special damage type (none, headshot, melee, collision).  Previously, this was the only data that was used to determine if a dead body ragdolled immediately or not.  These filters should be pretty self-explanatory.\n\nThe second level of filtering is the damage reporting info.  This includes every weapon as well as general categories like melee and explosions.  You should probably only use this to filter for specific weapons and ignore those categories because they are somewhat redundant with the first level of filtering.\n\nThe last level of filtering is a velocity gate.  If the biped being killed is travelling faster than this value, then the specified death program will be used.  When there is more than one velocity gate, the largest one will be used.\n\nThe output of the filtering system (which is part of the last level of filtering) is a death program and a scale value.  The death programs are (animate then ragdoll, headshot ragdoll program, melee ragdoll program, default ragdoll program).  The scale value only affects the ragdoll programs, not the animation.  If the scale value is 0, then the object’s default acceleration scale will be used.\n\nHeadshot ragdoll program: accelerates the body upwards and torques it back in the direction the damage came from.  Scales the effect based on the dying biped’s speed and direction relative to damage\n\nMelee ragdoll program: accelerates ragdoll nodes in the direction of damage, applying more acceleration to the bodies closer to the point of impact.  Also torques the body from the point of impact.\n\nDefault ragdoll program: similar to melee program, but torque is different depending on how far from the center of mass the killing blow came from.\n\nThe headshot program is good for, well, headshots; the melee program is good for melees and collisions and possibly shotguns; and the default program is good for mostly everything else.\n\nInheritance:\n\nCurrently there is only one level of inheritance for each of the first two filters.  If the type of death was collision but none of the collision filters match, then it will search through \"none\" as well.  For the second level, if there is a filter for the weapon type but the velocity gate didn’t match, it will search though \"the guardians\" as well.  The second filtering level looks like it has a lot of opportunity for inheritance relationships, but I didn’t want to implement any without getting some input on what those should be."),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_tag_reference, "parent", &death_program_selector_reference },
		{ _field_block, "special type", &death_program_special_block },
		{ _field_terminator }
	};

	STRINGS(death_program_result_enum)
	{
		"animate then ragdoll",
		"default ragdoll program",
		"headshot ragdoll program",
		"melee ragdoll program"
	};
	STRING_LIST(death_program_result_enum, death_program_result_enum_strings, _countof(death_program_result_enum_strings));

	TAG_REFERENCE(death_program_selector_reference, DEATH_PROGRAM_SELECTOR_TAG);

} // namespace macaque

} // namespace blofeld

