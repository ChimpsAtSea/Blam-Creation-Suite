#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(death_program_selector, DEATH_PROGRAM_SELECTOR_TAG, death_program_selector_block_block );

	V5_TAG_BLOCK(death_program_velocity_gate_block, k_maximum_death_program_velocity_gates)
	{
		{ _field_real, "minimum velocity:wu/s#this death program will be selected if the biped\'s velocity is above this number^" },
		{ _field_long_enum, "death program", &death_program_result_enum },
		{ _field_real, "death program scale#input to the death program to scale the result (only affects ragdolls)" },
		{ _field_string_id, "death animation stance#Override stance that contains the death animations for this gait speed when using animate then ragdoll option." },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(death_program_damage_reporting_block, k_maximum_death_program_damage_types)
	{
		{ _field_long_enum, "damage type^", &global_damage_reporting_enum_definition },
		{ _field_block, "velocity", &death_program_velocity_gate_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(death_program_special_block, k_maximum_death_program_special_types)
	{
		{ _field_long_enum, "special type^", &object_damage_aftermath_special_damage_type_enum },
		{ _field_block, "damage type", &death_program_damage_reporting_block_block },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(death_program_selector_block, 1, death_program_selector_struct_definition_struct_definition );

	V5_TAG_STRUCT(death_program_selector_struct_definition)
	{
		{ _field_custom, "Explanation" },
		{ _field_explanation, "Death Program Selection", "There are 3 levels of filtering for this.  Certain combinations of the first two levels are either impossible or redundant.  This is because they come from different places in the damage code. I will try to make that clearer here:\n\nThe first level of filtering is a special damage type (none, headshot, melee, collision).  Previously, this was the only data that was used to determine if a dead body ragdolled immediately or not.  These filters should be pretty self-explanatory.\n\nThe second level of filtering is the damage reporting info.  This includes every weapon as well as general categories like melee and explosions.  You should probably only use this to filter for specific weapons and ignore those categories because they are somewhat redundant with the first level of filtering.\n\nThe last level of filtering is a velocity gate.  If the biped being killed is travelling faster than this value, then the specified death program will be used.  When there is more than one velocity gate, the largest one will be used.\n\nThe output of the filtering system (which is part of the last level of filtering) is a death program and a scale value.  The death programs are (animate then ragdoll, headshot ragdoll program, melee ragdoll program, default ragdoll program).  The scale value only affects the ragdoll programs, not the animation.  If the scale value is 0, then the object’s default acceleration scale will be used.\n\nHeadshot ragdoll program: accelerates the body upwards and torques it back in the direction the damage came from.  Scales the effect based on the dying biped’s speed and direction relative to damage\n\nMelee ragdoll program: accelerates ragdoll nodes in the direction of damage, applying more acceleration to the bodies closer to the point of impact.  Also torques the body from the point of impact.\n\nDefault ragdoll program: similar to melee program, but torque is different depending on how far from the center of mass the killing blow came from.\n\nThe headshot program is good for, well, headshots; the melee program is good for melees and collisions and possibly shotguns; and the default program is good for mostly everything else.\n\nInheritance:\n\nCurrently there is only one level of inheritance for each of the first two filters.  If the type of death was collision but none of the collision filters match, then it will search through \"none\" as well.  For the second level, if there is a filter for the weapon type but the velocity gate didn’t match, it will search though \"the guardians\" as well.  The second filtering level looks like it has a lot of opportunity for inheritance relationships, but I didn’t want to implement any without getting some input on what those should be." },
		{ _field_custom },
		{ _field_tag_reference, "parent", &death_program_selector_reference },
		{ _field_block, "special type", &death_program_special_block_block },
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

} // namespace blofeld

