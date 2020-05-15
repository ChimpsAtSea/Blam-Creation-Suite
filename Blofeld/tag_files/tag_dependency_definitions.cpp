#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(one_dependency, k_kilo*10)
{
	{ _field_tag_reference, "tag reference" },
	{ _field_terminator },
};

TAG_GROUP(dependency, DEPENDENCY_TAG)
{
	{ _field_block, "dependency list", &one_dependency_block },
	{ _field_terminator },
};

} // namespace blofeld

