#pragma once

struct BoxPrimitiveData
{
	float m_positionX = 0.0f;
	float m_positionY = 0.0f;
	float m_positionZ = 0.0f;
	float m_dimensionsX = 0.0f;
	float m_dimensionsY = 0.0f;
	float m_dimensionsZ = 0.0f;
	float m_colorR = 1.0f;
	float m_colorG = 1.0f;
	float m_colorB = 1.0f;
	float m_colorA = 1.0f;
	//float m_maxX = 0.0f;
	//float m_maxY = 0.0f;
	//float m_maxZ = 0.0f;
	//float m_minX = 0.0f;
	//float m_minY = 0.0f;
	//float m_minZ = 0.0f;
};

class BoxPrimitive : public BoxPrimitiveData
{
public:
	BoxPrimitive();
	BoxPrimitive(
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
	);
	~BoxPrimitive();

	inline void SetColor(
		float colorR,
		float colorG,
		float colorB,
		float colorA
	)
	{
		m_colorR = colorR;
		m_colorG = colorG;
		m_colorB = colorB;
		m_colorA = colorA;
	}


	inline void UpdateAsCenteredBox(float positionX, float positionY, float positionZ)
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

	inline void UpdateAsAABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
	{
		m_dimensionsX = maxX - minX;
		m_dimensionsY = maxY - minY;
		m_dimensionsZ = maxZ - minZ;

		m_positionX = minX - m_dimensionsX * 0.5f;
		m_positionY = minY - m_dimensionsY * 0.5f;
		m_positionZ = minZ - m_dimensionsZ * 0.5f;

		//m_maxX = maxX;
		//m_maxY = maxY;
		//m_maxZ = maxZ;
		//m_minX = minX;
		//m_minY = minY;
		//m_minZ = minZ;
	}

	inline void UpdateAsCornerAndExtentBox(float positionX, float positionY, float positionZ, float dimensionsX, float dimensionsY, float dimensionsZ)
	{
		m_positionX = positionX + dimensionsX * 0.5f;
		m_positionY = positionY + dimensionsY * 0.5f;
		m_positionZ = positionZ + dimensionsZ * 0.5f;
		m_dimensionsX = dimensionsX;
		m_dimensionsY = dimensionsY;
		m_dimensionsZ = dimensionsZ;

		//m_minX = positionX;
		//m_minY = positionY;
		//m_minZ = positionZ;
		//m_maxX = positionX + dimensionsX;
		//m_maxY = positionY + dimensionsY;
		//m_maxZ = positionZ + dimensionsZ;
	}

	inline void UpdateAsCenteredBox(float positionX, float positionY, float positionZ, float dimensionsX, float dimensionsY, float dimensionsZ)
	{
		m_positionX = positionX;
		m_positionY = positionY;
		m_positionZ = positionZ;
		m_dimensionsX = dimensionsX;
		m_dimensionsY = dimensionsY;
		m_dimensionsZ = dimensionsZ;

		const float halfWidth = dimensionsX * 0.5f;
		const float halfHeight = dimensionsY * 0.5f;
		const float halfDepth = dimensionsZ * 0.5f;

		//m_maxX = positionX + halfWidth;
		//m_maxY = positionY + halfHeight;
		//m_maxZ = positionZ + halfDepth;
		//m_minX = positionX - halfWidth;
		//m_minY = positionY - halfHeight;
		//m_minZ = positionZ - halfDepth;
	}


	inline bool SetIsVisible(bool isVisible)
	{
		m_isVisible = isVisible;
	}

	inline bool IsVisible() const
	{
		return m_isVisible;
	}

private:
	bool m_isVisible = true;
};

