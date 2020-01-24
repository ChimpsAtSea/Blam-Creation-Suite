#include "BoxShader.hlsli"

float4 main(VertexOutput input) : SV_Target
{
	float3 absLocalPos = abs(input.LPosition);

	float maxAxis0 = max(absLocalPos.x, absLocalPos.y);
	float maxAxis1 = max(absLocalPos.x, absLocalPos.z);
	float maxAxis2 = max(absLocalPos.y, absLocalPos.z);

	int axisAtOneCount = 0;
	if (maxAxis0 >= 0.99999f) axisAtOneCount++;
	if (maxAxis1 >= 0.99999f) axisAtOneCount++;
	if (maxAxis2 >= 0.99999f) axisAtOneCount++;

	if (axisAtOneCount != 3)
	{
		discard;
	}
	return input.Color;
}
