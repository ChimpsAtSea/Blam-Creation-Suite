#include "lightmap_debug.hlsli"

PixelOutput main(VertexOutput input) : SV_Target
{
	PixelOutput output;

	output.Position = float4(input.Position, 1.0);
	output.Color = input.Color;
	output.Normal = float4(input.Normal, 1.0);
	output.Tangent = float4(input.Tangent, 1.0);
	output.Binormal = float4(input.Binormal, 1.0);
	output.UV = input.UV;

	return output;
}
