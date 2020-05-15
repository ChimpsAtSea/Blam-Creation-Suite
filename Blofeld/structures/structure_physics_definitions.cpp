#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(soft_surfaces_definition, 1)
{
	{ _field_pad, "CLASS_NONE", 4 },
	{ _field_real, "class biped#max - .2f" },
	{ _field_real, "class dead biped#max - .09f" },
	{ _field_real, "class crates + vehicles#max - .2f" },
	{ _field_real, "class debris#max - .04f" },
	{ _field_pad, "CLASS_ALL", 4 },
	{ _field_terminator },
};

} // namespace blofeld

