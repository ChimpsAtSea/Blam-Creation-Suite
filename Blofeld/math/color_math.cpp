#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ARRAY(half_sh_terms, ((3)*(3)))
	{
		FIELD( _field_short_integer, "coefficient*" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(half_rgb_lightprobe_struct)
	{
		FIELD( _field_array, "red sh terms", &half_sh_terms_array ),
		FIELD( _field_array, "green sh terms", &half_sh_terms_array ),
		FIELD( _field_array, "blue sh terms", &half_sh_terms_array ),
		FIELD( _field_short_integer, "analytical visibility" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

