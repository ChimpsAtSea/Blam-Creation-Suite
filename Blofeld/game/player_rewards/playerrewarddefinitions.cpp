#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(rewardBlock, eCT_count)
	{
		FIELD( _field_char_enum, "currency type#Type of currency given by this reward.", &currencyTypeEnumDefinition ),
		FIELD( _field_pad, "PJB1", 1 ),
		FIELD( _field_short_integer, "reward amount#Amount of the given currency to be given with this reward." ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(currencyTypeEnumDefinition, 2)
	{
		OPTION("cookies"),
		OPTION("xp"),
	};

} // namespace blofeld

