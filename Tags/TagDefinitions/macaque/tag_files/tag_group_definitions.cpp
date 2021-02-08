#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define G_NULL_BLOCK_ID { 0x757E48A6, 0x9CAC4CBC, 0xBC46A11C, 0x63F7E2F3 }
	TAG_BLOCK(
		g_null_block,
		"g_null_block",
		0,
		"g_null_block",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		G_NULL_BLOCK_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_terminator }
	};

	TAG_REFERENCE(g_non_traversed_reference_definition);

} // namespace macaque

} // namespace blofeld

