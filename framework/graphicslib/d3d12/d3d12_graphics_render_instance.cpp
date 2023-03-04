#include "graphicslib-private-pch.h"

c_graphics_render_instance_d3d12::c_graphics_render_instance_d3d12(
	c_graphics_d3d12& graphics,
	const wchar_t* debug_name) :
	c_graphics_render_instance(),
	s_render_instance_state_d3d12(),
	graphics(graphics),
	graphics_buffer(),
	render_instance_hash()
{
	BCS_FAIL_THROW(graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_unordered_access_view,
		sizeof(r_render_instance_d3d12),
		graphics_buffer));

	set_scale(1.0f);
	set_color({ 1.0f, 1.0f, 1.0f, 1.0f });
}

c_graphics_render_instance_d3d12::~c_graphics_render_instance_d3d12()
{
	BCS_FAIL_THROW(graphics_buffer_destroy(graphics_buffer));
}

static float3 operator*(float3& a, float b)
{
	return { a.x * b, a.y * b, a.z * b };
}

static float3 operator+(float3 a, float3 b)
{
	return { a.x + b.x, a.y + b.x, a.z + b.x };
}

// #TODO: Put to/from functionality into float3
static void float3_to_dxvector(float3& a, DirectX::XMVECTOR& v)
{
	reinterpret_cast<float*>(&v)[0] = a.x;
	reinterpret_cast<float*>(&v)[1] = a.y;
	reinterpret_cast<float*>(&v)[2] = a.z;
	reinterpret_cast<float*>(&v)[3] = 0.0f;
}

// #TODO: Put to/from functionality into float4
static void dxvector_to_float4(DirectX::XMVECTOR& v, float4& b)
{
	b.x = reinterpret_cast<float*>(&v)[0];
	b.y = reinterpret_cast<float*>(&v)[1];
	b.z = reinterpret_cast<float*>(&v)[2];
	b.w = reinterpret_cast<float*>(&v)[3];
}

// #TODO: Put to/from functionality into float4x4
static void dxmatrix_to_float4x4(DirectX::XMMATRIX& m, float4x4& b)
{
	b._11 = m._11; b._12 = m._12; b._13 = m._13; b._14 = m._14;
	b._21 = m._21; b._22 = m._22; b._23 = m._23; b._24 = m._24;
	b._31 = m._31; b._32 = m._32; b._33 = m._33; b._34 = m._34;
	b._41 = m._41; b._42 = m._42; b._43 = m._43; b._44 = m._44;
}

void c_graphics_render_instance_d3d12::update_buffers()
{
	s_render_instance_state_d3d12& render_instance_data = static_cast<s_render_instance_state_d3d12&>(*this);
	XXH64_hash_t current_render_instance_hash = XXH64(&render_instance_data, sizeof(s_render_instance_state_d3d12), 0);
	if (render_instance_hash == current_render_instance_hash)
	{
		return;
	}

	using namespace DirectX;

	XMMATRIX dx_translation_transposed = XMMatrixTranslation(position.x, position.y, position.z);
	XMMATRIX dx_rotation_transposed = XMMatrixRotationQuaternion({ rotation.x,  rotation.y,  rotation.z,  rotation.w });
	XMMATRIX dx_scale_transposed = XMMatrixScaling(scale.x, scale.y, scale.z);
	XMMATRIX dx_transform_transposed = dx_translation_transposed * dx_rotation_transposed * dx_scale_transposed;

	XMMATRIX dx_transform = XMMatrixTranspose(dx_transform_transposed);

	dxmatrix_to_float4x4(dx_transform, transform);

	r_render_instance_d3d12& render_instance_gpu_data = static_cast<r_render_instance_d3d12&>(*this);
	graphics_buffer->write_data(&render_instance_gpu_data, sizeof(r_render_instance_d3d12), 0);

	current_render_instance_hash = XXH64(&render_instance_data, sizeof(s_render_instance_state_d3d12), 0);
	render_instance_hash = current_render_instance_hash;
}

void c_graphics_render_instance_d3d12::get_graphics_buffer(c_graphics_buffer*& out_buffer)
{
	out_buffer = graphics_buffer;
}

void c_graphics_render_instance_d3d12::set_position(float3 position)
{
	this->position = position;
}

void c_graphics_render_instance_d3d12::set_color(float4 color)
{
	this->color = color;
}

void c_graphics_render_instance_d3d12::set_rotation_euler(float3 rotation_euler)
{
	using namespace DirectX;
	XMVECTOR dx_rotation = DirectX::XMQuaternionRotationRollPitchYaw(rotation_euler.x, rotation_euler.y, rotation_euler.z);
	dxvector_to_float4(dx_rotation, rotation);
}

void c_graphics_render_instance_d3d12::set_rotation_quat(float4 rotation_quat)
{
	this->rotation = rotation_quat;
}

void c_graphics_render_instance_d3d12::set_scale(float scale)
{
	this->scale = { scale, scale, scale };
}

void c_graphics_render_instance_d3d12::set_scale_3d(float3 scale_3d)
{
	this->scale = scale_3d;
}

BCS_RESULT graphics_d3d12_render_instance_create(
	c_graphics_d3d12* graphics,
	c_graphics_render_instance_d3d12*& render_instance,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		render_instance = new() c_graphics_render_instance_d3d12(
			*graphics,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_render_instance_destroy(c_graphics_render_instance_d3d12* render_instance)
{
	try
	{
		delete render_instance;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
