#include "Common.hlsli"

struct PixelInput
{
    float4 position : SV_Position;
    float3 color : COLOR;
    float2 texCoord : TEXCOORD;
    float3 normal : NORMAL;
    float3 cameraDirection : TEXCOORD1;
    float3 tangent : TANGENT;
    float3 bitangent : BITANGENT;
};

// Texture
Texture2D diffuseMap : register(t0);
Texture2D normalMap : register(t1);
SamplerState diffuseSampler : register(s0);

float4 main(PixelInput input) : SV_TARGET
{
    // Sampling
    float4 texColor = diffuseMap.Sample(diffuseSampler, input.texCoord);

    // Tangent normal (0~1 -> -1~1)
    float4 tangentNormal = normalMap.Sample(diffuseSampler, input.texCoord);
    tangentNormal = tangentNormal * 2 - 1;

    // tangent to world transformation matrix
    float3x3 tangentToWorld = float3x3(normalize(input.tangent), normalize(input.bitangent), normalize(input.normal));
    
    // Light Dir
    float3 lightDir = -float3(500.0f, 500.0f, -500.0f);
    lightDir = normalize(lightDir);
    
    // World Normal
    float3 worldNormal = normalize(mul(tangentNormal.xyz, tangentToWorld));
    
    // Dot (Lambert's cosine law)
    //float nDotl = saturate(dot(worldNormal, -lightDir));

    // Half Lambert
    float nDotl = CalcHalfLambert(worldNormal, lightDir);

    float4 ambient = texColor * float4(0.2f, 0.2f, 0.2f, 1);
    float4 diffuse = texColor * nDotl;
    float4 finalColor = ambient + diffuse;
    
    // Phong (specular)
    //float specular = CalcPhong(worldNormal, lightDir, input.cameraDirection);

    // Blinn-Phong (specular)
    float specular = CalcBlinnPhong(worldNormal, lightDir, input.cameraDirection);
    
    finalColor += float4(0.4f, 0.6f, 0.8f, 1) * specular;
    //return float4(specular, specular, specular, 1);
    return finalColor;
}