
cbuffer PerObject {
	float4x4	mModel;
	float4x4	mView;
	float4x4	mProj;
	float4		mColor;
};

struct VertexInput {
	float3 Position : POSITION;
};

struct VertexOutput {
	float4 HPosition : SV_POSITION;
};

VertexOutput VSMain(VertexInput input)
{
	VertexOutput output;


	output.HPosition = mul(float4(input.Position, 1.0), mModel);
	output.HPosition = mul(output.HPosition, mView);
	output.HPosition = mul(output.HPosition, mProj);

	//output.HPosition = mul(float4(input.Position, 1.0), mProj * mView * mModel);

	return output;
}

float4 PSMain(VertexOutput input) : SV_Target
{
	return mColor;
}

