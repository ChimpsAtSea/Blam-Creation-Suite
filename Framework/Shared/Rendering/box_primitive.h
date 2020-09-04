#pragma once

struct BoxPrimitiveData
{
	float position_x = 0.0f;
	float position_y = 0.0f;
	float position_z = 0.0f;
	float dimensions_x = 0.0f;
	float dimensions_y = 0.0f;
	float dimensions_z = 0.0f;
	float color_r = 1.0f;
	float color_g = 1.0f;
	float color_b = 1.0f;
	float color_a = 1.0f;
	//float maxX = 0.0f;
	//float maxY = 0.0f;
	//float maxZ = 0.0f;
	//float minX = 0.0f;
	//float minY = 0.0f;
	//float minZ = 0.0f;
};

class c_box_primitive : public BoxPrimitiveData
{
public:
	c_box_primitive();
	c_box_primitive(
		float position_x,
		float position_y,
		float position_z,
		float dimensions_x,
		float dimensions_y,
		float dimensions_z,
		float color_r,
		float color_g,
		float color_b,
		float color_a
	);
	~c_box_primitive();

	inline void set_color(
		float color_r,
		float color_g,
		float color_b,
		float color_a
	)
	{
		color_r = color_r;
		color_g = color_g;
		color_b = color_b;
		color_a = color_a;
	}


	inline void update_as_centered_box(float position_x, float position_y, float position_z)
	{
		update_as_centered_box(
			position_x,
			position_y,
			position_z,
			dimensions_x,
			dimensions_y,
			dimensions_z
		);
	}

	inline void UpdateAsAABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ)
	{
		dimensions_x = maxX - minX;
		dimensions_y = maxY - minY;
		dimensions_z = maxZ - minZ;

		position_x = minX - dimensions_x * 0.5f;
		position_y = minY - dimensions_y * 0.5f;
		position_z = minZ - dimensions_z * 0.5f;

		//maxX = maxX;
		//maxY = maxY;
		//maxZ = maxZ;
		//minX = minX;
		//minY = minY;
		//minZ = minZ;
	}

	inline void update_as_corner_and_extent_box(float position_x, float position_y, float position_z, float dimensions_x, float dimensions_y, float dimensions_z)
	{
		position_x = position_x + dimensions_x * 0.5f;
		position_y = position_y + dimensions_y * 0.5f;
		position_z = position_z + dimensions_z * 0.5f;
		dimensions_x = dimensions_x;
		dimensions_y = dimensions_y;
		dimensions_z = dimensions_z;

		//minX = position_x;
		//minY = position_y;
		//minZ = position_z;
		//maxX = position_x + dimensions_x;
		//maxY = position_y + dimensions_y;
		//maxZ = position_z + dimensions_z;
	}

	inline void update_as_centered_box(float position_x, float position_y, float position_z, float dimensions_x, float dimensions_y, float dimensions_z)
	{
		position_x = position_x;
		position_y = position_y;
		position_z = position_z;
		dimensions_x = dimensions_x;
		dimensions_y = dimensions_y;
		dimensions_z = dimensions_z;

		const float halfWidth = dimensions_x * 0.5f;
		const float halfHeight = dimensions_y * 0.5f;
		const float halfDepth = dimensions_z * 0.5f;

		//maxX = position_x + halfWidth;
		//maxY = position_y + halfHeight;
		//maxZ = position_z + halfDepth;
		//minX = position_x - halfWidth;
		//minY = position_y - halfHeight;
		//minZ = position_z - halfDepth;
	}


	inline bool SetIsVisible(bool isVisible)
	{
		is_visible = isVisible;
	}

	inline bool IsVisible() const
	{
		return is_visible;
	}

private:
	bool is_visible = true;
};

