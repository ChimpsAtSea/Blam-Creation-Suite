
struct VertexInput {
	float3 Position		: POSITION;
	float4 Color		: COLOR0;
	float3 Normal		: NORMAL;
	float3 Tangent		: TANGENT;
	float3 Binormal		: BINORMAL;
	float2 UV			: TEXCOORD0;
};

struct VertexOutput {
					float4 HPosition	: SV_POSITION;
					float3 Position		: POSITION;
					float4 Color		: COLOR;
					float3 Normal		: NORMAL;
					float3 Tangent		: TANGENT;
					float3 Binormal		: BINORMAL;
					float2 UV			: TEXCOORD0;
};

struct PixelOutput {
	float3 Position		: SV_Target0;
	float4 Color		: SV_Target1;
	float3 Normal		: SV_Target2;
	float3 Tangent		: SV_Target3;
	float3 Binormal		: SV_Target4;
	float2 UV			: SV_Target5;
};
