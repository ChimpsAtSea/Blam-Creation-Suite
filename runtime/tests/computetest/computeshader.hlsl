
RWStructuredBuffer<uint> structured_buffer;

[numthreads(1, 1, 1)]
void main(uint3 DispatchThreadID : SV_DispatchThreadID)
{
	uint read = structured_buffer[DispatchThreadID.x];
	uint modify = read + DispatchThreadID.x;
	structured_buffer[DispatchThreadID.x] = modify; // write
}
