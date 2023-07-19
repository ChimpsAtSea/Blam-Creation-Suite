#include "geometrylib-private-pch.h"

c_geometry_mesh::~c_geometry_mesh()
{

}

BCS_RESULT c_geometry_mesh::copy_to_render_buffer(
	e_geometry_mesh_property property,
	uint32_t set_index,
	e_graphics_data_format format,
	c_graphics_buffer& buffer) const
{
	BCS_RESULT rs = BCS_S_OK;

	void* buffer_data;
	if (BCS_SUCCEEDED(rs = buffer.map_data_write_begin(buffer_data)))
	{
		BCS_RESULT rs2 = get_property(
			property,
			0,
			0,
			set_index,
			format,
			buffer_data);

		if (BCS_FAILED(rs = buffer.map_data_write_end(buffer_data)))
		{
			return rs;
		}

		if (BCS_FAILED(rs2))
		{
			return rs;
		}
	}

	return rs;
}