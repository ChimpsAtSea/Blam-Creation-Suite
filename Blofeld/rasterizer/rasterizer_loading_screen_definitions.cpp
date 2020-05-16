#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(load_screen, LOAD_SCREEN_TAG, loadScreenBlock_block )

TAG_BLOCK(loadScreenBlock, 1)
{
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "Model parameters" ),
	FIELD( _field_tag_reference, "source render model" ),
	FIELD( _field_real, "spawn rate multiplier#the higher this number, the sooner the model is fully spawned in" ),
	FIELD( _field_real_point_3d, "source scan position#the direction in model space that the scan starts from.\nIgnored if do not sort vertex order flag is set above" ),
	FIELD( _field_real, "scale factor#model scale to match camera space" ),
	FIELD( _field_explanation, "Camera parameters" ),
	FIELD( _field_real_point_3d, "camera position" ),
	FIELD( _field_real_point_3d, "camera target position" ),
	FIELD( _field_real, "camera orbit period#0 means camera is stationary" ),
	FIELD( _field_explanation, "Particles" ),
	FIELD( _field_real, "particle scale#scale factor for individual particles" ),
	FIELD( _field_real, "particle acceleration#This is the acceleration rate when particles spawn in and move to their ultimate destination.  Higher numbers move faster." ),
	FIELD( _field_real, "particle initial offset multiplier#If flag particles spawn radially is set, this is the multiple of the particle location along the radial axis.\nIf not, this the random spawn distance from the particle destination." ),
	FIELD( _field_explanation, "Generated data" ),
	FIELD( _field_long_integer, "computed model vertex count:vertices" ),
	FIELD( _field_block, "model vertices*", &vertexBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vertexBlock, 77824)
{
	FIELD( _field_real_point_3d, "point*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

