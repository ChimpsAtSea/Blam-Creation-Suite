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

VertexOutput VSMain(VertexInput input, uint iInstanceID : SV_InstanceID)
{
	PerObject object = Objects[iInstanceID];
	VertexOutput output;

	output.Color		= object.mColor;
	output.LPosition	= input.Position * 2.0f; // position is -0.5 to 0.5 convert to -1.0 to 1.0
	output.HPosition	= mul(float4(input.Position, 1.0), object.mModel);
	output.HPosition	= mul(output.HPosition, mView);
	output.HPosition	= mul(output.HPosition, mProj);

	return output;
}

float4 PSMain(VertexOutput input) : SV_Target
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

