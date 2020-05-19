#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(death_program_selector, DEATH_PROGRAM_SELECTOR_TAG, death_program_selector_block_block );

	TAG_BLOCK(death_program_velocity_gate_block, k_maximum_death_program_velocity_gates)
	{
		{ _field_real, "minimum velocity:wu/s#this death program will be selected if the biped\'s velocity is above this number^" },
		{ _field_long_enum, "death program", &death_program_result_enum },
		{ _field_real, "death program scale#input to the death program to scale the result (only affects ragdolls)" },
		{ _field_string_id, "death animation stance#Override stance that contains the death animations for this gait speed when using animate then ragdoll option." },
		{ _field_terminator }
	};

	TAG_BLOCK(death_program_damage_reporting_block, k_maximum_death_program_damage_types)
	{
		{ _field_long_enum, "damage type^", &global_damage_reporting_enum_definition },
		{ _field_block, "velocity", &death_program_velocity_gate_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(death_program_special_block, k_maximum_death_program_special_types)
	{
		{ _field_long_enum, "special type^", &object_damage_aftermath_special_damage_type_enum },
		{ _field_block, "damage type", &death_program_damage_reporting_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(death_program_selector_block, 1, death_program_selector_struct_definition_struct_definition );

	TAG_STRUCT(death_program_selector_struct_definition)
	{
		{ _field_custom, "Explanation" },
		{ _field_explanation, "Death Program Selection" },
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

