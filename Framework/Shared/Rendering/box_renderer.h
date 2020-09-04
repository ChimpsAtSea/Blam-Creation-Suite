#pragma once

class c_box_renderer
{
public:
	struct alignas(256) s_box_per_object_constants
	{
		DirectX::XMMATRIX model_matrix;
		DirectX::XMFLOAT4 color;
	};

	static constexpr uint32_t k_max_boxes_per_frame = 128 * 1024;

	static ID3D11PixelShader* pixel_shader;
	static ID3D11VertexShader* vertex_shader;
	static ID3D11RasterizerState* solid_raster_state;
	static ID3D11RasterizerState* wireframe_raster_state;
	static ID3D11InputLayout* vertex_layout;
	static ID3D11Buffer* vertex_buffer;
	static ID3D11Buffer* solid_index_buffer;
	static ID3D11Buffer* wireframe_index_buffer;
	static volatile uint32_t next_constant_buffer_index;
	static volatile uint32_t next_box_index;
	static ID3D11Buffer* current_instance_constants_buffer;
	static s_box_per_object_constants* box_per_object_constants_array;
	static ID3D11Buffer* instance_constants_buffers[c_primitive_render_manager::k_num_constants_buffers];

	static void begin_render_box();
	static void render_box(
		DirectX::XMFLOAT3 const& position,
		DirectX::XMFLOAT3 const& dimensions,
		DirectX::XMFLOAT4 const& color
	);
	static void end_render_box();
private:
	static void setup_solid_geometry();
	static void setup_wireframe_geometry();
	static void setup_shaders();
	static void setup_constants_buffers();
	static void get_next_constants_buffer();
	static void map_constants_buffer();
	static void unmap_constants_buffer();
	static void render_box_geometry();
};

