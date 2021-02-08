#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		effect_global_force_group,
		EFFECT_GLOBAL_FORCE_TAG,
		nullptr,
		INVALID_TAG,
		effect_global_force_block );

	TAG_BLOCK_FROM_STRUCT(
		effect_global_force_block,
		"effect_global_force_block",
		1,
		effect_global_force_struct_definition);

	#define EFFECT_GLOBAL_FORCE_STRUCT_DEFINITION_ID { 0x0D721FE1, 0x75B148BB, 0x8B019D51, 0x0CDCE867 }
	TAG_STRUCT(
		effect_global_force_struct_definition,
		"effect_global_force_struct_definition",
		"EffectGlobalForceDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_GLOBAL_FORCE_STRUCT_DEFINITION_ID)
	{
		{ _field_byte_flags, "flags", &globalForceFlags },
		FIELD_PAD("grog", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_real, "force strength", "positive pushes out, negative pulls in" },
		{ _field_real, "sphere falloff begin", "doesn't work on cylinders, due to shader constant constraints", "wus" },
		{ _field_real, "sphere falloff end", "doesn't work on cylinders, due to shader constant constraints", "wus" },
		{ _field_terminator }
	};

	STRINGS(globalForceFlags)
	{
		"is infinitely long cylinder"
	};
	STRING_LIST(globalForceFlags, globalForceFlags_strings, _countof(globalForceFlags_strings));

} // namespace macaque

} // namespace blofeld

