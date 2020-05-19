#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(polyart_asset, POLYART_ASSET_TAG)
	{
		{ _field_char_enum, "runtime flags*!", &g_polyartAssetStateFlags },
		{ _field_char_enum, "Polyart vertex type", &PolyartVertexFormatTypeEnum },
		{ _field_char_integer, "uvSet index" },
		{ _field_pad, "MERP", 1 },
		{ _field_real, "antialiasing extent size" },
		{ _field_block, "placement data", &polyartCameraBlock_block },
		{ _field_block, "vertices*", &polyartVertexBlock_block },
		{ _field_block, "indices*", &polyartIndexBlock_block },
		{ _field_block, "pc vertex buffers*", &vertexBuffersBlock_block },
		{ _field_block, "pc index buffers*", &indexBuffersBlock_block },
		{ _field_api_interop, "vertex buffer interop*" },
		{ _field_api_interop, "index buffer interop*" },
		{ _field_terminator }
	};

	TAG_BLOCK(polyartCameraBlock, 1)
	{
		{ _field_real, "horizontal fov" },
		{ _field_real, "vertical fov" },
		{ _field_real, "near z plane distance" },
		{ _field_real, "far z plane distance" },
		{ _field_real_point_3d, "camera position" },
		{ _field_terminator }
	};

} // namespace blofeld

