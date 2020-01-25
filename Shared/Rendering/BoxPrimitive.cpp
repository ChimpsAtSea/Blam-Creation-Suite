#include "shared-private-pch.h"

BoxPrimitive::BoxPrimitive()
{
	PrimitiveRenderManager::RegisterBoxPrimitive(this);
}

BoxPrimitive::BoxPrimitive(
	float positionX, 
	float positionY, 
	float positionZ, 
	float dimensionsX, 
	float dimensionsY, 
	float dimensionsZ,
	float colorR,
	float colorG,
	float colorB,
	float colorA
):BoxPrimitive()
{
	UpdateAsCenteredBox(positionX, positionY, positionZ, dimensionsX, dimensionsY, dimensionsZ);
	SetColor(colorR, colorB, colorG, colorA);
}

BoxPrimitive::~BoxPrimitive()
{
	PrimitiveRenderManager::UnregisterBoxPrimitive(this);
}
