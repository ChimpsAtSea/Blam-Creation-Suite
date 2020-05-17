#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(vectorart_asset, VECTORART_ASSET_TAG)
	{
		FIELD( _field_char_enum, "runtime flags*!", &g_polyartAssetStateFlags ),
		FIELD( _field_pad, "MERP", 3 ),
		FIELD( _field_real, "antialiasing extent size" ),
		FIELD( _field_real, "import fudge factor (suggested 0.5)" ),
		FIELD( _field_real_point_2d, "bounds*" ),
		FIELD( _field_real, "curve smoothness" ),
		FIELD( _field_block, "vertices*", &polyartVertexBlock_block ),
		FIELD( _field_block, "indices*", &polyartIndexBlock_block ),
		FIELD( _field_block, "pc vertex buffers*", &vertexBuffersBlock_block ),
		FIELD( _field_block, "pc index buffers*", &indexBuffersBlock_block ),
		FIELD( _field_api_interop, "vertex buffer interop*" ),
		FIELD( _field_api_interop, "index buffer interop*" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

