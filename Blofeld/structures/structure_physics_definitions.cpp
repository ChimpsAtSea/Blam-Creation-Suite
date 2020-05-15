#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(soft_surfaces_definition, 1)
{
	FIELD( _field_pad, "CLASS_NONE", 4 ),
	FIELD( _field_real, "class biped#max - .2f" ),
	FIELD( _field_real, "class dead biped#max - .09f" ),
	FIELD( _field_real, "class crates + vehicles#max - .2f" ),
	FIELD( _field_real, "class debris#max - .04f" ),
	FIELD( _field_pad, "CLASS_ALL", 4 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

