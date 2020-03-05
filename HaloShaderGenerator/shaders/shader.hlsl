cbuffer ParametersPS : register(b13)
{
	float4 ___albedo_color;
	float ___approximate_specular_type;
}


Texture2D texture0;
SamplerState g_samLinear
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;
	AddressV = Wrap;
};

struct Input
{
	float4 position : SV_Position;
	float clip_distance : SV_ClipDistance;
	float2 texcoord0 : TEXCOORD0;
	float3 texcoord1 : TEXCOORD1;
	float3 texcoord2 : TEXCOORD2;
	float3 texcoord3 : TEXCOORD3;
	float3 texcoord4 : TEXCOORD4;
};

struct Output
{
	float4 target0;
	float4 target1;
};

Output main(Input input) : SV_Target
{
	Output output;

	output.target0.xyz = ___albedo_color.xyz;
	output.target0.w = 0;

	output.target1.xyz = input.texcoord1 * 0.5 + 0.5;
	output.target1.w = ___approximate_specular_type;

	return output;
}
