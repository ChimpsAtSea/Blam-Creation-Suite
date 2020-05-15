#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(performane_throttle, 7)
{
	{ _field_long_flags, "flags" },
	{ _field_real, "water tessellation scale" },
	{ _field_real, "decorator fade dist scale:0 = off" },
	{ _field_real, "effect lod distance scale{effect lod limit}" },
	{ _field_custom, "Object settings" },
	{ _field_real, "instance fade modifier!" },
	{ _field_real, "object fade modifier#scales down the distances at which objects first imposter and then fade out" },
	{ _field_real, "object detail fade modifier" },
	{ _field_real, "object lighting time limit:s 0=0.001s#per frame time limit to spend sampling new lighting radiosity" },
	{ _field_custom },
	{ _field_custom, "IO settings" },
	{ _field_real, "IO fade modifier#scales down the distances at which IOs imposter" },
	{ _field_custom },
	{ _field_custom, "Dynamic light settings" },
	{ _field_long_integer, "max forward dynamic lights{max gpu dynamic lights}#will quickly fade gpu lights when we try to render more than this many:0 = off" },
	{ _field_real, "forward dynamic light fade distance scale{gpu light fade distance scale}#scales the size used for distance-fade (set smaller to make it fade earlier)" },
	{ _field_long_integer, "max screenspace dynamic lights#will quickly fade screenspace lights when we try to render more than this many:0 = off" },
	{ _field_real, "screenspace light fade distance scale#scales the size used for distance-fade (set smaller to make it fade earlier)" },
	{ _field_long_integer, "max effect lights (screenspace)#limits the number of effect lights we allow to be active at a time (eg. needler needles lighting up objects):0 = off" },
	{ _field_custom },
	{ _field_custom, "Shadow settings" },
	{ _field_long_integer, "max shadow casting objects:0 = off" },
	{ _field_real, "shadow quality lod#scales resolution of object shadows:[0.0 to 1.0]" },
	{ _field_real, "floating shadow quality lod#scales resolution of floating shadow:[0.0 to 1.0], 0 = off" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(performance_throttles, PERFORMANCE_THROTTLES_TAG)
{
	{ _field_explanation, "Performance Throttles" },
	{ _field_block, "Performance Throttles", &performane_throttle_block },
	{ _field_terminator },
};

} // namespace blofeld

