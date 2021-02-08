#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define REWARDBLOCK_ID { 0xF59C2E93, 0xFF814434, 0xB447120D, 0x3229DE7F }
	TAG_BLOCK(
		rewardBlock_block,
		"rewardBlock",
		eCT_count,
		"RewardDefinition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		REWARDBLOCK_ID)
	{
		{ _field_char_enum, "currency type", "Type of currency given by this reward.", &currencyTypeEnumDefinition },
		FIELD_PAD("PJB1", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "reward amount", "Amount of the given currency to be given with this reward." },
		{ _field_terminator }
	};

	STRINGS(currencyTypeEnumDefinition)
	{
		"cookies",
		"xp"
	};
	STRING_LIST(currencyTypeEnumDefinition, currencyTypeEnumDefinition_strings, _countof(currencyTypeEnumDefinition_strings));

} // namespace macaque

} // namespace blofeld

