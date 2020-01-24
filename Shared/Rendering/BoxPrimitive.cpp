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

void BoxPrimitive::UpdateAsCenteredBox(float positionX, float positionY, float positionZ)
{
	UpdateAsCenteredBox(
		positionX,
		positionY,
		positionZ,
		m_dimensionsX,
		m_dimensionsY,
		m_dimensionsZ
	);
}

void BoxPrimitive::UpdateAsAABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
{
	m_maxX = maxX;
	m_maxY = maxY;
	m_maxZ = maxZ;
	m_minX = minX;
	m_minY = minY;
	m_minZ = minZ;
	m_dimensionsX = maxX - minX;
	m_dimensionsY = maxY - minY;
	m_dimensionsZ = maxZ - minZ;
	m_volume = m_dimensionsX * m_dimensionsY * m_dimensionsZ;

	m_positionX = minX - m_dimensionsX * 0.5f;
	m_positionY = minY - m_dimensionsY * 0.5f;
	m_positionZ = minZ - m_dimensionsZ * 0.5f;
}

void BoxPrimitive::UpdateAsPositionAndExtentBox(float positionX, float positionY, float positionZ, float dimensionsX, float dimensionsY, float dimensionsZ)
{
	m_minX = positionX;
	m_minY = positionY;
	m_minZ = positionZ;
	m_maxX = positionX + dimensionsX;
	m_maxY = positionY + dimensionsY;
	m_maxZ = positionZ + dimensionsZ;
	m_dimensionsX = dimensionsX;
	m_dimensionsY = dimensionsY;
	m_dimensionsZ = dimensionsZ;
	m_volume = m_dimensionsX * m_dimensionsY * m_dimensionsZ;

	m_positionX = m_minX - dimensionsX * 0.5f;
	m_positionY = m_minY - dimensionsY * 0.5f;
	m_positionZ = m_minZ - dimensionsZ * 0.5f;
}

void BoxPrimitive::UpdateAsCenteredBox(float positionX, float positionY, float positionZ, float dimensionsX, float dimensionsY, float dimensionsZ)
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
