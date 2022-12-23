struct PerObject
{
	float4x4	mModel;
	float4		mColor;
	float4		rubbish[59];
};

cbuffer PerDraw : register(b1) {
	PerObject Objects[16];
};

cbuffer PerFrame : register(b0) {
	float4x4	mView;
	float4x4	mProj;
};

struct VertexInput {
	float3 Position : POSITION;
};

struct VertexOutput {
					float4 HPosition	: SV_POSITION;
					float3 LPosition	: TEXCOORD0;
	nointerpolation float4 Color		: TEXCOORD1;
};


