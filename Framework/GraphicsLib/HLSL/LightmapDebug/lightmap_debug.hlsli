
struct VertexInput {
	float3 Position : POSITION;
	float2 UV : TEXCOORD0;
};

struct VertexOutput {
					float4 HPosition	: SV_POSITION;
					float3 Position		: TEXCOORD0;
					float3 Normal		: TEXCOORD1;
					float3 Tangent		: TEXCOORD2;
					float3 Binormal		: TEXCOORD3;
					float2 UV			: TEXCOORD4;
};

struct PixelOutput {
	float3 Position		: SV_Target0;
	float3 Normal		: SV_Target1;
	float3 Tangent		: SV_Target2;
	float3 Binormal		: SV_Target3;
	float2 UV			: SV_Target4;
};
