#include "opusframework-private-pch.h"

BoxPrimitive::BoxPrimitive()
{
	memset(this, 0, sizeof(*this));
	m_isVisible = true;
	SetColor(1.0f, 1.0f, 1.0f, 1.0f);
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
	m_isVisible = true;
	Update(positionX, positionY, positionZ, dimensionsX, dimensionsY, dimensionsZ);
	SetColor(colorR, colorB, colorG, colorA);
}

BoxPrimitive::~BoxPrimitive()
{
	PrimitiveRenderManager::UnregisterBoxPrimitive(this);
}

void BoxPrimitive::Update(float positionX, float positionY, float positionZ)
{
	Update(
		positionX,
		positionY,
		positionZ,
		m_dimensionsX,
		m_dimensionsY,
		m_dimensionsZ
	);
}

void BoxPrimitive::Update(float positionX, float positionY, float positionZ, float dimensionsX, float dimensionsY, float dimensionsZ)
{
	m_positionX = positionX;
	m_positionY = positionY;
	m_positionZ = positionZ;
	m_dimensionsX = dimensionsX;
	m_dimensionsY = dimensionsY;
	m_dimensionsZ = dimensionsZ;

	m_volume = dimensionsX * dimensionsY * dimensionsZ;

	const float halfWidth = dimensionsX * 0.5f;
	const float halfHeight = dimensionsY * 0.5f;
	const float halfDepth = dimensionsZ * 0.5f;

	m_maxX = positionX + halfWidth;
	m_maxY = positionY + halfHeight;
	m_maxZ = positionZ + halfDepth;
	m_minX = positionX - halfWidth;
	m_minY = positionY - halfHeight;
	m_minZ = positionZ - halfDepth;
}			 
