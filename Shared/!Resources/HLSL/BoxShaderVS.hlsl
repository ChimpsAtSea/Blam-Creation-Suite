#include "BoxShader.hlsli"

VertexOutput main(VertexInput input, uint iInstanceID : SV_InstanceID)
{
	PerObject object = Objects[iInstanceID];
	VertexOutput output;

	float3 vPosition = input.Position.xzy;

	output.Color = object.mColor;
	output.LPosition = vPosition * 2.0f; // position is -0.5 to 0.5 convert to -1.0 to 1.0
	output.HPosition = mul(float4(vPosition, 1.0), object.mModel);
	output.HPosition = mul(output.HPosition, mView);
	output.HPosition = mul(output.HPosition, mProj);

	return output;
}
