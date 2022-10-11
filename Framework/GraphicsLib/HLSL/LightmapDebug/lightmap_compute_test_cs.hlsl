#include "lightmap_debug.hlsli"

RWStructuredBuffer<float4> sb;

[numthreads(1, 1, 1)]
void main(uint3 DispatchThreadID : SV_DispatchThreadID)
{
	float4 read = sb[DispatchThreadID.x];
	float4 write = float4((float)DispatchThreadID.x, 0, 0, 0);
	sb[DispatchThreadID.x] = write;
}
