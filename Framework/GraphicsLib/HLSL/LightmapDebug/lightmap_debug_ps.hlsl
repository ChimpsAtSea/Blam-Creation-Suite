#include "lightmap_debug.hlsli"

PixelOutput main(VertexOutput input) : SV_Target
{
	PixelOutput output;

	output.Position = input.Position;
	output.Normal = input.Normal;
	output.Tangent = input.Tangent;
	output.Binormal = input.Binormal;
	output.UV = input.UV;

	return output;
}
