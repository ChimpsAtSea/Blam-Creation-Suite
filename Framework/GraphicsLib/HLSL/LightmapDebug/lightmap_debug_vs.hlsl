#include "lightmap_debug.hlsli"

VertexOutput main(VertexInput input, uint iInstanceID : SV_InstanceID)
{
	VertexOutput output;

	float3 vPosition = input.Position;
	output.HPosition = float4(input.UV * 2.0 - 1.0, 0.0, 1.0);

	output.Position = vPosition.xyz;
	output.Color = input.Color;
	output.Normal = input.Normal;
	output.Tangent = input.Tangent;
	output.Binormal = input.Binormal;
	output.UV = input.UV;

	return output;
}
