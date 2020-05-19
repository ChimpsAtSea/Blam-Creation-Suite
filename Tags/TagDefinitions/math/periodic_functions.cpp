#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	STRINGS(global_periodic_functions_enum)
	{
		"one",
		"zero",
		"cosine",
		"cosine (variable period)",
		"diagonal wave",
		"diagonal wave (variable period)",
		"slide",
		"slide (variable period)",
		"noise",
		"jitter",
		"wander",
		"spark"
	};
	STRING_LIST(global_periodic_functions_enum, global_periodic_functions_enum_strings, _countof(global_periodic_functions_enum_strings));

	STRINGS(global_transition_functions_enum)
	{
		"linear",
		"early",
		"very early",
		"late",
		"very late",
		"cosine",
		"one",
		"zero"
	};
	STRING_LIST(global_transition_functions_enum, global_transition_functions_enum_strings, _countof(global_transition_functions_enum_strings));

	STRINGS(global_reverse_transition_functions_enum)
	{
		"linear",
		"late",
		"very late",
		"early",
		"very early",
		"cosine",
		"zero",
		"one"
	};
	STRING_LIST(global_reverse_transition_functions_enum, global_reverse_transition_functions_enum_strings, _countof(global_reverse_transition_functions_enum_strings));

} // namespace blofeld

