#pragma pack_matrix( row_major )

Texture2D mainTexture : register(t0);

SamplerState aSampler : register(s0);

cbuffer CamData : register(b0)
{
    float4 EyePosWorld;
	float4x4 View;			
	float4x4 Projection;
}

cbuffer InstanceData : register(b1)
{
    float4x4 World;
    float4x4 WorldInv;
};

cbuffer FogData : register(b2)
{	
    float FogStart;
    float FogRange;
    float4 FogColor;
}

//--------------------------------------------------------------------------------------

struct VS_INPUT
{
    float3 Pos : POSITION;
	float2 Tex : TEXCOORD;	// u v maps
};

struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float4 PosMS : POSITION;
	float2 Tex : TEXCOORD;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS( VS_INPUT input)
{    
	VS_OUTPUT output;
    output.PosMS = float4(input.Pos, 1.0f);
    output.Pos = output.PosMS;
	output.Pos = mul(output.Pos, World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Tex = input.Tex;
	return output;
}


//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(VS_OUTPUT input) : SV_Target
{
    float4 msEyePos = mul(EyePosWorld, WorldInv);	
	
	// Compute fog density as function of distance to eye
    float distToEye = length(msEyePos - input.PosMS);
    float FogPercent = saturate((distToEye - FogStart) / FogRange); // See https://msdn.microsoft.com/en-us/library/windows/desktop/bb509645(v=vs.85).aspx
	
	// blend fog texture with fog level	
    return (mainTexture.Sample(aSampler, input.Tex) * (1 - FogPercent)) + FogColor * FogPercent;
}