#include "BoxShader.hlsli"

float4 main(VertexOutput input) : SV_Target
{
	return input.Color;
}
