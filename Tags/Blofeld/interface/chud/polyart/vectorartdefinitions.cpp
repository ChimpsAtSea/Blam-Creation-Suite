#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(vectorart_asset, VECTORART_ASSET_TAG)
	{
		{ _field_char_enum, "runtime flags*!", &g_polyartAssetStateFlags },
		{ _field_pad, "MERP", 3 },
		{ _field_real, "antialiasing extent size" },
		{ _field_real, "import fudge factor (suggested 0.5)" },
		{ _field_real_point_2d, "bounds*" },
		{ _field_real, "curve smoothness" },
		{ _field_block, "vertices*", &polyartVertexBlock_block },
		{ _field_block, "indices*", &polyartIndexBlock_block },
		{ _field_block, "pc vertex buffers*", &vertexBuffersBlock_block },
		{ _field_block, "pc index buffers*", &indexBuffersBlock_block },
		{ _field_api_interop, "vertex buffer interop*" },
		{ _field_api_interop, "index buffer interop*" },
		{ _field_terminator }
	};

} // namespace blofeld

