#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(global_periodic_functions_enum, 12)
	{
		OPTION("one"),
		OPTION("zero"),
		OPTION("cosine"),
		OPTION("cosine (variable period)"),
		OPTION("diagonal wave"),
		OPTION("diagonal wave (variable period)"),
		OPTION("slide"),
		OPTION("slide (variable period)"),
		OPTION("noise"),
		OPTION("jitter"),
		OPTION("wander"),
		OPTION("spark"),
	};

	TAG_ENUM(global_transition_functions_enum, 8)
	{
		OPTION("linear"),
		OPTION("early"),
		OPTION("very early"),
		OPTION("late"),
		OPTION("very late"),
		OPTION("cosine"),
		OPTION("one"),
		OPTION("zero"),
	};

	TAG_ENUM(global_reverse_transition_functions_enum, 8)
	{
		OPTION("linear"),
		OPTION("late"),
		OPTION("very late"),
		OPTION("early"),
		OPTION("very early"),
		OPTION("cosine"),
		OPTION("zero"),
		OPTION("one"),
	};

} // namespace blofeld

