#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(performance_throttle_flags, 15)
	{
		OPTION("disable object attachment lights"),
		OPTION("disable first person shadow"),
		OPTION("disable cheap particles"),
		OPTION("disable blob shadows"),
		OPTION("disable patchy fog"),
		OPTION("disable screen distortion"),
		OPTION("disable light shafts"),
		OPTION("disable first person depth of field"),
		OPTION("disable motion blur"),
		OPTION("disable particles continue offscreen"),
		OPTION("disable light cones"),
		OPTION("disable water interraction"),
		OPTION("disable water refraction"),
		OPTION("disable decorators"),
		OPTION("disable instance occlusion queries#WARNING Will likely hurt perf on most maps"),
	};

	TAG_GROUP_FROM_BLOCK(performance_throttles, PERFORMANCE_THROTTLES_TAG, performance_throttles_block_block );

	TAG_BLOCK_FROM_STRUCT(performance_throttles_block, 1, performance_throttles_struct_definition_struct_definition );

	TAG_BLOCK(performane_throttle_block, 7)
	{
		FIELD( _field_long_flags, "flags", &performance_throttle_flags ),
		FIELD( _field_real, "water tessellation scale" ),
		FIELD( _field_real, "decorator fade dist scale:0 = off" ),
		FIELD( _field_real, "effect lod distance scale{effect lod limit}" ),
		FIELD( _field_custom, "Object settings" ),
		FIELD( _field_real, "instance fade modifier!" ),
		FIELD( _field_real, "object fade modifier#scales down the distances at which objects first imposter and then fade out" ),
		FIELD( _field_real, "object detail fade modifier" ),
		FIELD( _field_real, "object lighting time limit:s 0=0.001s#per frame time limit to spend sampling new lighting radiosity" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "IO settings" ),
		FIELD( _field_real, "IO fade modifier#scales down the distances at which IOs imposter" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Dynamic light settings" ),
		FIELD( _field_long_integer, "max forward dynamic lights{max gpu dynamic lights}#will quickly fade gpu lights when we try to render more than this many:0 = off" ),
		FIELD( _field_real, "forward dynamic light fade distance scale{gpu light fade distance scale}#scales the size used for distance-fade (set smaller to make it fade earlier)" ),
		FIELD( _field_long_integer, "max screenspace dynamic lights#will quickly fade screenspace lights when we try to render more than this many:0 = off" ),
		FIELD( _field_real, "screenspace light fade distance scale#scales the size used for distance-fade (set smaller to make it fade earlier)" ),
		FIELD( _field_long_integer, "max effect lights (screenspace)#limits the number of effect lights we allow to be active at a time (eg. needler needles lighting up objects):0 = off" ),
		FIELD( _field_custom ),
		FIELD( _field_custom, "Shadow settings" ),
		FIELD( _field_long_integer, "max shadow casting objects:0 = off" ),
		FIELD( _field_real, "shadow quality lod#scales resolution of object shadows:[0.0 to 1.0]" ),
		FIELD( _field_real, "floating shadow quality lod#scales resolution of floating shadow:[0.0 to 1.0], 0 = off" ),
		FIELD( _field_custom ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(performance_throttles_struct_definition)
{
		FIELD( _field_explanation, "Performance Throttles" ),
		FIELD( _field_block, "Performance Throttles", &performane_throttle_block_block ),
		FIELD( _field_terminator )
};

} // namespace blofeld

