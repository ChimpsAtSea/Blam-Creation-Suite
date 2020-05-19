#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(rewardBlock, eCT_count)
	{
		{ _field_char_enum, "currency type#Type of currency given by this reward.", &currencyTypeEnumDefinition },
		{ _field_pad, "PJB1", 1 },
		{ _field_short_integer, "reward amount#Amount of the given currency to be given with this reward." },
		{ _field_terminator }
	};

	STRINGS(currencyTypeEnumDefinition)
	{
		"cookies",
		"xp"
	};
	STRING_LIST(currencyTypeEnumDefinition, currencyTypeEnumDefinition_strings, _countof(currencyTypeEnumDefinition_strings));

} // namespace blofeld

