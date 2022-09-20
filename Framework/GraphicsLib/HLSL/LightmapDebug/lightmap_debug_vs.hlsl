#include "lightmap_debug.hlsli"

VertexOutput main(VertexInput input, uint iInstanceID : SV_InstanceID)
{
	VertexOutput output;

	float3 vPosition = input.Position;
	output.HPosition = float4(vPosition.xy * 2.0 - 1.0, 0.0, 1.0);

	output.Position = vPosition.xyz;
	output.Normal = float3(1, 0, 0);
	output.Tangent = float3(0, 1, 0);
	output.Binormal = float3(0, 0, 1);
	output.UV = input.UV;

	return output;
}
