#pragma once
class BoxPrimitive
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

	void SetColor(
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

	void Update(
		float positionX,
		float positionY,
		float positionZ
	);	

	void Update(
		float positionX,
		float positionY,
		float positionZ,
		float dimensionsX,
		float dimensionsY,
		float dimensionsZ
	);

	bool SetIsVisible(bool isVisible)
	{
		m_isVisible = isVisible;
	}

	bool IsVisible() const
	{
		return m_isVisible && m_volume > 0;
	}

public:
	float m_positionX = 0.0f;
	float m_positionY = 0.0f;
	float m_positionZ = 0.0f;
	float m_dimensionsX = 0.0f;
	float m_dimensionsY = 0.0f;
	float m_dimensionsZ = 0.0f;
	float m_colorR;
	float m_colorG;
	float m_colorB;
	float m_colorA;
	float m_volume = 0.0f;
	float m_maxX = 0.0f;
	float m_maxY = 0.0f;
	float m_maxZ = 0.0f;
	float m_minX = 0.0f;
	float m_minY = 0.0f;
	float m_minZ = 0.0f;

private:
	bool m_isVisible = 0.0f;
};

