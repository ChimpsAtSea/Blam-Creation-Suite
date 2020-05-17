#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(death_program_selector, DEATH_PROGRAM_SELECTOR_TAG, death_program_selector_block_block );

	TAG_BLOCK(death_program_velocity_gate_block, k_maximum_death_program_velocity_gates)
	{
		FIELD( _field_real, "minimum velocity:wu/s#this death program will be selected if the biped\'s velocity is above this number^" ),
		FIELD( _field_long_enum, "death program", &death_program_result_enum ),
		FIELD( _field_real, "death program scale#input to the death program to scale the result (only affects ragdolls)" ),
		FIELD( _field_string_id, "death animation stance#Override stance that contains the death animations for this gait speed when using animate then ragdoll option." ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(death_program_damage_reporting_block, k_maximum_death_program_damage_types)
	{
		FIELD( _field_long_enum, "damage type^", &global_damage_reporting_enum_definition ),
		FIELD( _field_block, "velocity", &death_program_velocity_gate_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(death_program_special_block, k_maximum_death_program_special_types)
	{
		FIELD( _field_long_enum, "special type^", &object_damage_aftermath_special_damage_type_enum ),
		FIELD( _field_block, "damage type", &death_program_damage_reporting_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(death_program_selector_block, 1, death_program_selector_struct_definition_struct_definition );

	TAG_STRUCT(death_program_selector_struct_definition)
	{
		FIELD( _field_custom, "Explanation" ),
		FIELD( _field_explanation, "Death Program Selection" ),
		FIELD( _field_custom ),
		FIELD( _field_tag_reference, "parent" ),
		FIELD( _field_block, "special type", &death_program_special_block_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(death_program_result_enum, 4)
	{
		OPTION("animate then ragdoll"),
		OPTION("default ragdoll program"),
		OPTION("headshot ragdoll program"),
		OPTION("melee ragdoll program"),
	};

} // namespace blofeld

