#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(polyart_asset, POLYART_ASSET_TAG)
{
	FIELD( _field_char_enum, "runtime flags*!" ),
	FIELD( _field_char_enum, "Polyart vertex type" ),
	FIELD( _field_char_integer, "uvSet index" ),
	FIELD( _field_pad, "MERP", 1 ),
	FIELD( _field_real, "antialiasing extent size" ),
	FIELD( _field_block, "placement data", &polyartCameraBlock_block ),
	FIELD( _field_block, "vertices*", &polyartVertexBlock_block ),
	FIELD( _field_block, "indices*", &polyartIndexBlock_block ),
	FIELD( _field_block, "pc vertex buffers*", &vertexBuffersBlock_block ),
	FIELD( _field_block, "pc index buffers*", &indexBuffersBlock_block ),
	FIELD( _field_api_interop, "vertex buffer interop*" ),
	FIELD( _field_api_interop, "index buffer interop*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(polyartCameraBlock, 1)
{
	FIELD( _field_real, "horizontal fov" ),
	FIELD( _field_real, "vertical fov" ),
	FIELD( _field_real, "near z plane distance" ),
	FIELD( _field_real, "far z plane distance" ),
	FIELD( _field_real_point_3d, "camera position" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

