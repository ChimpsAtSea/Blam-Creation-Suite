#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_ARRAY(half_sh_terms, ((3)*(3)))
	{
		{ _field_short_integer, "coefficient*" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(half_rgb_lightprobe_struct)
	{
		{ _field_array, "red sh terms", &half_sh_terms_array },
		{ _field_array, "green sh terms", &half_sh_terms_array },
		{ _field_array, "blue sh terms", &half_sh_terms_array },
		{ _field_short_integer, "analytical visibility" },
		{ _field_terminator }
	};

} // namespace blofeld

