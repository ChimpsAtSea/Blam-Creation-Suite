#include "geometrylib-private-pch.h"

c_radiance_transfer_engine_gpu::c_radiance_transfer_engine_gpu(
	unsigned int _order,
	unsigned short _resolution,
	bool _use_shadows,
	bool _calculate_subsurface) :
	c_radiance_transfer_engine(),
	geometry_meshes(),
	num_geometry_meshes(),
	geometries(),
	num_geometries(),
	order(_order),
	resolution(_resolution),
	num_coefficient_planes((order + 1)* (order + 1)),
	use_shadows(_use_shadows),
	calculate_subsurface(_calculate_subsurface),

	graphics(nullptr),
	raytracing_test_shader_binary(nullptr),
	raytracing_global_register_layout(nullptr),
	raytracing_test_shader_pipeline(nullptr),
	runtime_configuration_buffer(nullptr),
	samples_direction_buffer(nullptr),
	samples_sh_coefficients_buffer(nullptr),

	graphics_start_debug_capture_result(BCS_E_NOT_RUN),

	num_samples(resolution* resolution),
	num_sample_sh_coefficients(num_samples* num_coefficient_planes),
	spherical_harmonic_evaluation()
{

	BCS_RESULT graphics_create_result = graphics_create(_graphics_architecture_d3d12_raytracing, true, graphics);
	BCS_FAIL_THROW(graphics_create_result);

	graphics_start_debug_capture_result = graphics->start_debug_capture();

	void* raytracing_shader_binary_data;
	SIZE_T raytracing_shader_binary_size;
	BCS_RESULT read_raytracing_shader_binary_result = resources_read_local_resource_to_memory(
		"radiance_transfer.cso",
		raytracing_shader_binary_data,
		raytracing_shader_binary_size);
	BCS_FAIL_THROW(read_raytracing_shader_binary_result);

	BCS_RESULT raytracing_test_shader_binary_create_result = graphics_shader_binary_create(
		graphics,
		raytracing_shader_binary_data,
		raytracing_shader_binary_size,
		raytracing_test_shader_binary);
	BCS_FAIL_THROW(read_raytracing_shader_binary_result);

	//s_graphics_register_layout_description raytracing_global_register_layouts[k_num_radiance_transfer_registers];

	s_graphics_register_layout_description& runtime_configuration_buffer_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_runtime_configuration_buffer];
	runtime_configuration_buffer_register_layout_description.semantic = _graphics_register_layout_shader_resource;
	runtime_configuration_buffer_register_layout_description.register_index = 0;
	runtime_configuration_buffer_register_layout_description.register_count = 1;
	runtime_configuration_buffer_register_layout_description.register_space = 0;
	runtime_configuration_buffer_register_layout_description.num_32_bit_values = 0;
	runtime_configuration_buffer_register_layout_description.use_table = false;
	runtime_configuration_buffer_register_layout_description.sampler_layout_description = nullptr;

	s_graphics_register_layout_description& samples_direction_buffer_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_samples_direction_buffer];
	samples_direction_buffer_register_layout_description.semantic = _graphics_register_layout_shader_resource;
	samples_direction_buffer_register_layout_description.register_index = 1;
	samples_direction_buffer_register_layout_description.register_count = 1;
	samples_direction_buffer_register_layout_description.register_space = 0;
	samples_direction_buffer_register_layout_description.num_32_bit_values = 0;
	samples_direction_buffer_register_layout_description.use_table = false;
	samples_direction_buffer_register_layout_description.sampler_layout_description = nullptr;

	s_graphics_register_layout_description& samples_sh_coefficients_buffer_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_samples_sh_coefficients_buffer];
	samples_sh_coefficients_buffer_register_layout_description.semantic = _graphics_register_layout_shader_resource;
	samples_sh_coefficients_buffer_register_layout_description.register_index = 2;
	samples_sh_coefficients_buffer_register_layout_description.register_count = 1;
	samples_sh_coefficients_buffer_register_layout_description.register_space = 0;
	samples_sh_coefficients_buffer_register_layout_description.num_32_bit_values = 0;
	samples_sh_coefficients_buffer_register_layout_description.use_table = false;
	samples_sh_coefficients_buffer_register_layout_description.sampler_layout_description = nullptr;

	s_graphics_register_layout_description& geometry_configuration_buffer_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_geometry_configuration_buffer];
	geometry_configuration_buffer_register_layout_description.semantic = _graphics_register_layout_shader_resource;
	geometry_configuration_buffer_register_layout_description.register_index = 3;
	geometry_configuration_buffer_register_layout_description.register_count = 1;
	geometry_configuration_buffer_register_layout_description.register_space = 0;
	geometry_configuration_buffer_register_layout_description.num_32_bit_values = 0;
	geometry_configuration_buffer_register_layout_description.use_table = false;
	geometry_configuration_buffer_register_layout_description.sampler_layout_description = nullptr;

	s_graphics_register_layout_description& geometry_vertex_buffer_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_geometry_vertex_buffer];
	geometry_vertex_buffer_register_layout_description.semantic = _graphics_register_layout_shader_resource;
	geometry_vertex_buffer_register_layout_description.register_index = 4;
	geometry_vertex_buffer_register_layout_description.register_count = 1;
	geometry_vertex_buffer_register_layout_description.register_space = 0;
	geometry_vertex_buffer_register_layout_description.num_32_bit_values = 0;
	geometry_vertex_buffer_register_layout_description.use_table = false;
	geometry_vertex_buffer_register_layout_description.sampler_layout_description = nullptr;

	s_graphics_register_layout_description& geometry_acceleration_structure_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_geometry_acceleration_structure];
	geometry_acceleration_structure_register_layout_description.semantic = _graphics_register_layout_acceleration_structure;
	geometry_acceleration_structure_register_layout_description.register_index = 5;
	geometry_acceleration_structure_register_layout_description.register_count = 1;
	geometry_acceleration_structure_register_layout_description.register_space = 0;
	geometry_acceleration_structure_register_layout_description.num_32_bit_values = 0;
	geometry_acceleration_structure_register_layout_description.use_table = false;
	geometry_acceleration_structure_register_layout_description.sampler_layout_description = nullptr;

	s_graphics_register_layout_description& radiance_transfer_buffer_register_layout_description =
		raytracing_global_register_layouts[_radiance_transfer_register_radiance_transfer_buffer];
	radiance_transfer_buffer_register_layout_description.semantic = _graphics_register_layout_unordered_access;
	radiance_transfer_buffer_register_layout_description.register_index = 0;
	radiance_transfer_buffer_register_layout_description.register_count = 1;
	radiance_transfer_buffer_register_layout_description.register_space = 0;
	radiance_transfer_buffer_register_layout_description.num_32_bit_values = 0;
	radiance_transfer_buffer_register_layout_description.use_table = false;
	radiance_transfer_buffer_register_layout_description.sampler_layout_description = nullptr;

	BCS_RESULT raytracing_global_register_layout_create_result = graphics_register_layout_create(
		graphics,
		_graphics_register_layout_type_global_raytracing,
		raytracing_global_register_layouts,
		_countof(raytracing_global_register_layouts),
		raytracing_global_register_layout,
		"raytracing_global_register_layout");
	BCS_FAIL_THROW(raytracing_global_register_layout_create_result);

	BCS_RESULT raytracing_test_shader_pipeline_create_result = graphics_shader_pipeline_raytracing_create(
		graphics,
		raytracing_global_register_layout,
		nullptr,
		raytracing_test_shader_binary,
		L"RaygenShader",
		L"ClosestHitShader",
		L"MissShader",
		L"HitGroup",
		raytracing_test_shader_pipeline,
		"raytracing_pipeline");
	BCS_FAIL_THROW(raytracing_test_shader_pipeline_create_result);

	BCS_RESULT runtime_configuration_buffer_create_result = graphics_buffer_create(
		graphics,
		_graphics_buffer_type_generic,
		sizeof(s_radiance_transfer_geometry_gpu_runtime_configuration),
		runtime_configuration_buffer,
		"runtime_configuration_buffer");
	BCS_FAIL_THROW(runtime_configuration_buffer_create_result);

	BCS_RESULT samples_direction_buffer_create_result = graphics_buffer_create(
		graphics,
		_graphics_buffer_type_generic,
		sizeof(float3),
		num_samples,
		samples_direction_buffer,
		"samples_direction_buffer");
	BCS_FAIL_THROW(samples_direction_buffer_create_result);

	BCS_RESULT samples_sh_coefficients_buffer_create_result = graphics_buffer_create(
		graphics,
		_graphics_buffer_type_generic,
		sizeof(float),
		num_sample_sh_coefficients,
		samples_sh_coefficients_buffer,
		"samples_sh_coefficients_buffer");
	BCS_FAIL_THROW(samples_sh_coefficients_buffer_create_result);

	tracked_free(raytracing_shader_binary_data);

	init_samples();
}

c_radiance_transfer_engine_gpu::~c_radiance_transfer_engine_gpu()
{
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		c_radiance_transfer_geometry_gpu& geometry = geometries[geometry_index];

		trivial_free(geometry.surface_coefficient_planes);
		trivial_free(geometry.subsurface_coefficient_planes);
		trivial_free(geometry.coefficients);
	}

	trivial_free(geometry_meshes);
	trivial_free(geometries);

	deinit_samples();

	BCS_RESULT samples_sh_coefficients_buffer_destroy_result = graphics_buffer_destroy(samples_sh_coefficients_buffer);
	ASSERT(BCS_SUCCEEDED(samples_sh_coefficients_buffer_destroy_result));
	BCS_RESULT samples_direction_buffer_destroy_result = graphics_buffer_destroy(samples_direction_buffer);
	ASSERT(BCS_SUCCEEDED(samples_direction_buffer_destroy_result));
	BCS_RESULT runtime_configuration_buffer_destroy_result = graphics_buffer_destroy(runtime_configuration_buffer);
	ASSERT(BCS_SUCCEEDED(runtime_configuration_buffer_destroy_result));
	BCS_RESULT raytracing_test_shader_pipeline_destroy_result = graphics_shader_pipeline_destroy(raytracing_test_shader_pipeline);
	ASSERT(BCS_SUCCEEDED(raytracing_test_shader_pipeline_destroy_result));
	BCS_RESULT raytracing_global_register_layout_destroy_result = graphics_register_layout_destroy(raytracing_global_register_layout);
	ASSERT(BCS_SUCCEEDED(raytracing_global_register_layout_destroy_result));
	BCS_RESULT raytracing_test_shader_binary_destroy_result = graphics_shader_binary_destroy(raytracing_test_shader_binary);
	ASSERT(BCS_SUCCEEDED(raytracing_test_shader_binary_destroy_result));

	if (BCS_SUCCEEDED(graphics_start_debug_capture_result))
	{
		BCS_RESULT graphics_end_debug_capture_result = graphics->end_debug_capture();
		ASSERT(BCS_SUCCEEDED(graphics_end_debug_capture_result));
	}

	BCS_RESULT graphics_destroy_result = graphics_destroy(graphics);
	ASSERT(BCS_SUCCEEDED(graphics_destroy_result));
}

void c_radiance_transfer_engine_gpu::init_samples()
{
	BCS_RESULT graphics_begin_result = graphics->begin();
	ASSERT(BCS_SUCCEEDED(graphics_begin_result));

	switch (order)
	{
	case 0:
		spherical_harmonic_evaluation = spherical_harmonic_evaluation_order0;
		break;
	case 1:
		spherical_harmonic_evaluation = spherical_harmonic_evaluation_order1;
		break;
	case 2:
		spherical_harmonic_evaluation = spherical_harmonic_evaluation_order2;
		break;
	default:
		throw BCS_E_UNSUPPORTED;
	}

	union
	{
		void* runtime_configuration_gpu_data;
		s_radiance_transfer_geometry_gpu_runtime_configuration* runtime_configuration;
	};
	BCS_RESULT runtime_configuration_buffer_map_data_begin_result = runtime_configuration_buffer->map_data_write_begin(runtime_configuration_gpu_data);
	ASSERT(BCS_SUCCEEDED(runtime_configuration_buffer_map_data_begin_result));

	runtime_configuration->num_samples = num_samples;

	BCS_RESULT runtime_configuration_buffer_map_data_end_result = runtime_configuration_buffer->map_data_write_end(runtime_configuration_gpu_data);
	ASSERT(BCS_SUCCEEDED(runtime_configuration_buffer_map_data_end_result));

	union
	{
		void* samples_gpu_data;
		float3* samples;
	};
	BCS_RESULT samples_direction_buffer_map_data_begin_result = samples_direction_buffer->map_data_write_begin(samples_gpu_data);
	ASSERT(BCS_SUCCEEDED(samples_direction_buffer_map_data_begin_result));

	union
	{
		void* sample_sh_coefficients_gpu_data;
		float* sample_sh_coefficients;
	};
	BCS_RESULT samples_sh_coefficients_buffer_map_data_begin_result = samples_sh_coefficients_buffer->map_data_write_begin(sample_sh_coefficients_gpu_data);
	ASSERT(BCS_SUCCEEDED(samples_sh_coefficients_buffer_map_data_begin_result));

	float* sample_sh_coefficients_position = sample_sh_coefficients;
	float3* samples_position = samples;

	unsigned int seed = 0;
	for (unsigned int i = 0; i < resolution; i++)
	{
		for (unsigned int j = 0; j < resolution; j++)
		{
			int k = i * resolution + j;
			float3& sample = *samples_position;
			float* _sample_sh_coefficients = sample_sh_coefficients_position;

			float r0 = float(xorshift32(seed)) / UINT_MAX;
			float r1 = float(xorshift32(seed)) / UINT_MAX;

			float a = ((float)i + r0) / (float)resolution;
			float b = ((float)j + r1) / (float)resolution;
			float z = 1.0 - 2.0 * a;
			float r = sqrt(max(0.0, 1.0 - z * z));
			float phi = 2.0 * PI * b;

			float x = r * cos(phi);
			float y = r * sin(phi);

			sample = { x, y, z };
			spherical_harmonic_evaluation(x, y, z, _sample_sh_coefficients);

			samples_position++;
			sample_sh_coefficients_position += num_coefficient_planes;
		}
	}

	BCS_RESULT samples_direction_buffer_map_data_end_result = samples_direction_buffer->map_data_write_end(samples_gpu_data);
	ASSERT(BCS_SUCCEEDED(samples_direction_buffer_map_data_end_result));

	BCS_RESULT samples_sh_coefficients_buffer_map_data_end_result = samples_sh_coefficients_buffer->map_data_write_end(sample_sh_coefficients_gpu_data);
	ASSERT(BCS_SUCCEEDED(samples_sh_coefficients_buffer_map_data_end_result));

	BCS_RESULT graphics_end_result = graphics->end();
	ASSERT(BCS_SUCCEEDED(graphics_end_result));
}

void c_radiance_transfer_engine_gpu::deinit_samples()
{

}

BCS_RESULT c_radiance_transfer_engine_gpu::add_mesh(c_geometry_mesh& geometry_mesh)
{
	// check if already queued
	for (unsigned int geometry_mesh_index = 0; geometry_mesh_index < num_geometry_meshes; geometry_mesh_index++)
	{
		if (geometry_meshes[geometry_mesh_index] == &geometry_mesh)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
	}

	// check if already baked
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		if (geometries[geometry_index].geometry_mesh == &geometry_mesh)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
	}

	unsigned int geometry_mesh_index = num_geometry_meshes++;
	geometry_meshes = trivial_realloc(c_geometry_mesh*, geometry_meshes, num_geometry_meshes);
	geometry_meshes[geometry_mesh_index] = &geometry_mesh;

	return BCS_S_OK;
}

BCS_RESULT c_radiance_transfer_engine_gpu::bake()
{
	GRAPHICS_EVENT(*graphics, __FUNCTION__);

	// #TODO: Multithread
	for (unsigned int geometry_mesh_index = 0; geometry_mesh_index < num_geometry_meshes; geometry_mesh_index++)
	{
		c_geometry_mesh& geometry_mesh = *geometry_meshes[geometry_mesh_index];
		const char* geometry_mesh_name = geometry_mesh.get_name();
		unsigned int geometry_index = num_geometries++;
		GRAPHICS_EVENT_EX(*graphics, "Geometry Mesh Setup geometry_index:%i '%s'", geometry_index, geometry_mesh_name);

		geometries = trivial_realloc(c_radiance_transfer_geometry_gpu, geometries, num_geometries);
		c_radiance_transfer_geometry_gpu& radiance_transfer_geometry = geometries[geometry_index] = {};
		radiance_transfer_geometry.geometry_mesh = &geometry_mesh;
		radiance_transfer_geometry.radiance_transfer_engine = this;
		radiance_transfer_geometry.state = _radiance_transfer_geometry_gpu_prebake;

		radiance_transfer_geometry.surface_coefficient_planes = trivial_malloc(float*, num_coefficient_planes);
		radiance_transfer_geometry.subsurface_coefficient_planes = nullptr;

		unsigned int num_vertices = geometry_mesh.get_vertex_count();
		unsigned int num_indices = geometry_mesh.get_index_count();
		unsigned int num_storage_coefficients = num_vertices * num_coefficient_planes;
		if (calculate_subsurface)
		{
			radiance_transfer_geometry.subsurface_coefficient_planes = trivial_malloc(float*, num_coefficient_planes);
			num_storage_coefficients += num_storage_coefficients;
		}

		radiance_transfer_geometry.coefficients = trivial_malloc(float, num_storage_coefficients);
		memset(radiance_transfer_geometry.coefficients, 0, sizeof(float) * num_storage_coefficients);

		float* coefficients_position = radiance_transfer_geometry.coefficients;
		for (unsigned int coefficient_plane_index = 0; coefficient_plane_index < num_coefficient_planes; coefficient_plane_index++)
		{
			radiance_transfer_geometry.surface_coefficient_planes[coefficient_plane_index] = coefficients_position;
			coefficients_position += num_vertices;
			if (calculate_subsurface)
			{
				radiance_transfer_geometry.subsurface_coefficient_planes[coefficient_plane_index] = coefficients_position;
				coefficients_position += num_vertices;
			}
		}

		{
			c_fixed_string_128 radiance_transfer_buffer_debug_name;
			radiance_transfer_buffer_debug_name.format("c_radiance_transfer_geometry_gpu::radiance_transfer_buffer [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT radiance_transfer_buffer_create_result = graphics_buffer_create(
				graphics,
				_graphics_buffer_type_unordered_access_view,
				sizeof(float),
				num_coefficient_planes * num_vertices,
				radiance_transfer_geometry.radiance_transfer_buffer,
				radiance_transfer_buffer_debug_name);
			BCS_FAIL_THROW(radiance_transfer_buffer_create_result);
		}

		{
			c_fixed_string_128 geometry_configuration_buffer_debug_name;
			geometry_configuration_buffer_debug_name.format("c_radiance_transfer_geometry_gpu::configuration_buffer [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT geometry_configuration_buffer_create_result = graphics_buffer_create(
				graphics,
				_graphics_buffer_type_generic,
				sizeof(s_radiance_transfer_geometry_gpu_runtime_configuration),
				radiance_transfer_geometry.configuration_buffer,
				geometry_configuration_buffer_debug_name);
			BCS_FAIL_THROW(geometry_configuration_buffer_create_result);

			union
			{
				void* geometry_configuration_gpu_data;
				s_radiance_transfer_geometry_gpu_geometry_configuration* geometry_configuration;
			};
			BCS_RESULT geometry_configuration_buffer_map_data_begin_result = radiance_transfer_geometry.configuration_buffer->map_data_write_begin(geometry_configuration_gpu_data);
			ASSERT(BCS_SUCCEEDED(geometry_configuration_buffer_map_data_begin_result));

			geometry_configuration->num_vertices = num_vertices;
			geometry_configuration->num_coefficient_planes = num_coefficient_planes;
			geometry_configuration->num_storage_coefficients = num_storage_coefficients;

			BCS_RESULT geometry_configuration_buffer_map_data_end_result = radiance_transfer_geometry.configuration_buffer->map_data_write_end(geometry_configuration_gpu_data);
			ASSERT(BCS_SUCCEEDED(geometry_configuration_buffer_map_data_end_result));
		}

		{
			c_fixed_string_128 index_buffer_debug_name;
			index_buffer_debug_name.format("c_radiance_transfer_geometry_gpu::index_buffer [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT geometry_index_buffer_create_result = graphics_buffer_create(
				graphics,
				_graphics_buffer_type_generic,
				sizeof(unsigned int),
				num_indices,
				radiance_transfer_geometry.index_buffer,
				index_buffer_debug_name);
			BCS_FAIL_THROW(geometry_index_buffer_create_result);

			const unsigned int* indices = radiance_transfer_geometry.geometry_mesh->get_mesh_indices_uint();
			radiance_transfer_geometry.index_buffer->write_data(indices, sizeof(unsigned int), num_indices, 0);
		}

		{
			c_fixed_string_128 vertex_buffer_debug_name;
			vertex_buffer_debug_name.format("c_radiance_transfer_geometry_gpu::vertex_buffer [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT geometry_vertex_buffer_create_result = graphics_buffer_create(
				graphics,
				_graphics_buffer_type_generic,
				sizeof(s_radiance_transfer_geometry_gpu_vertex),
				num_vertices,
				radiance_transfer_geometry.vertex_buffer,
				vertex_buffer_debug_name);
			BCS_FAIL_THROW(geometry_vertex_buffer_create_result);

			union
			{
				void* geometry_vertices_gpu_data;
				s_radiance_transfer_geometry_gpu_vertex* geometry_vertices;
			};
			BCS_RESULT geometry_vertex_buffer_map_data_begin_result = radiance_transfer_geometry.vertex_buffer->map_data_write_begin(geometry_vertices_gpu_data);
			ASSERT(BCS_SUCCEEDED(geometry_vertex_buffer_map_data_begin_result));

			const float3* positions = radiance_transfer_geometry.geometry_mesh->get_positions();
			const float3* normals = radiance_transfer_geometry.geometry_mesh->get_normals();
			for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
			{
				geometry_vertices[vertex_index].position = positions[vertex_index];
				geometry_vertices[vertex_index].normal = normals[vertex_index];
			}

			BCS_RESULT geometry_vertex_buffer_map_data_end_result = radiance_transfer_geometry.vertex_buffer->map_data_write_end(geometry_vertices_gpu_data);
			ASSERT(BCS_SUCCEEDED(geometry_vertex_buffer_map_data_end_result));
		}

		{

			union
			{
				s_graphics_vertex_layout_description vertex_layout_descriptions[1];
				struct
				{
					s_graphics_vertex_layout_description vertex_layout_position;
				};
			};

			vertex_layout_position = {};
			vertex_layout_position.semantic = _graphics_vertex_layout_semantic_position;
			vertex_layout_position.semantic_index = 0;
			vertex_layout_position.data_format = _graphics_data_format_r32g32b32_float;
			vertex_layout_position.buffer_index = 0;
			vertex_layout_position.buffer_offset = offsetof(s_radiance_transfer_geometry_gpu_vertex, s_radiance_transfer_geometry_gpu_vertex::position);
			vertex_layout_position.vertex_layout_stepping = _graphics_vertex_layout_stepping_per_vertex;
			vertex_layout_position.buffer_stepping = sizeof(s_radiance_transfer_geometry_gpu_vertex);

			c_fixed_string_128 vertex_layout_debug_name;
			vertex_layout_debug_name.format("c_radiance_transfer_geometry_gpu::vertex_layout [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT vertex_layout_result = graphics_vertex_layout_create(
				graphics,
				vertex_layout_descriptions,
				_countof(vertex_layout_descriptions),
				radiance_transfer_geometry.vertex_layout,
				vertex_layout_debug_name);
			ASSERT(BCS_SUCCEEDED(vertex_layout_result));

			c_fixed_string_128 geometry_debug_name;
			geometry_debug_name.format("c_radiance_transfer_geometry_gpu::geometry [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT graphics_geometry_create_result = graphics_geometry_create(
				graphics,
				radiance_transfer_geometry.index_buffer,
				&radiance_transfer_geometry.vertex_buffer,
				1,
				num_indices,
				num_vertices,
				radiance_transfer_geometry.vertex_layout,
				radiance_transfer_geometry.geometry,
				geometry_debug_name);
			ASSERT(BCS_SUCCEEDED(graphics_geometry_create_result));

			c_fixed_string_128 bottom_level_acceleration_structure_debug_name;
			bottom_level_acceleration_structure_debug_name.format("c_radiance_transfer_geometry_gpu::bottom_level_acceleration_structure [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT graphics_bottom_level_acceleration_structure_create_result = graphics_bottom_level_acceleration_structure_create(
				graphics,
				radiance_transfer_geometry.geometry,
				radiance_transfer_geometry.bottom_level_acceleration_structure,
				bottom_level_acceleration_structure_debug_name);
			ASSERT(BCS_SUCCEEDED(graphics_bottom_level_acceleration_structure_create_result));

			c_fixed_string_128 top_level_acceleration_structure_debug_name;
			top_level_acceleration_structure_debug_name.format("c_radiance_transfer_geometry_gpu::top_level_acceleration_structure [%i] {%s}", geometry_index, geometry_mesh_name);
			BCS_RESULT graphics_top_level_acceleration_structure_create_result = graphics_top_level_acceleration_structure_create(
				graphics,
				radiance_transfer_geometry.top_level_acceleration_structure,
				top_level_acceleration_structure_debug_name);
			ASSERT(BCS_SUCCEEDED(graphics_top_level_acceleration_structure_create_result));

			s_graphics_acceleration_structure_instance acceleration_structure_instance = {};
			acceleration_structure_instance.transform.m[0][0] = 1.0f;
			acceleration_structure_instance.transform.m[1][1] = 1.0f;
			acceleration_structure_instance.transform.m[2][2] = 1.0f;
			acceleration_structure_instance.bottom_level_acceleration_structure = radiance_transfer_geometry.bottom_level_acceleration_structure;
			BCS_RESULT graphics_top_level_acceleration_structure_build_result = radiance_transfer_geometry.top_level_acceleration_structure->acceleration_structure_build(
				&acceleration_structure_instance,
				1);
			ASSERT(BCS_SUCCEEDED(graphics_top_level_acceleration_structure_build_result));
		}
	}

	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		c_radiance_transfer_geometry_gpu& geometry = geometries[geometry_index];
		const char* geometry_mesh_name = geometry.geometry_mesh->get_name();

		if (geometry.state != _radiance_transfer_geometry_gpu_prebake)
		{
			continue;
		}

		BCS_RESULT graphics_begin_result = graphics->begin();
		ASSERT(BCS_SUCCEEDED(graphics_begin_result));

		BCS_RESULT raytracing_register_layout_bind_result = raytracing_global_register_layout->bind();
		ASSERT(BCS_SUCCEEDED(raytracing_register_layout_bind_result));

		raytracing_test_shader_pipeline->bind();

		BCS_RESULT runtime_configuration_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_runtime_configuration_buffer,
			*runtime_configuration_buffer);
		ASSERT(BCS_SUCCEEDED(runtime_configuration_buffer_bind_result));

		BCS_RESULT samples_direction_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_samples_direction_buffer,
			*samples_direction_buffer);
		ASSERT(BCS_SUCCEEDED(samples_direction_buffer_bind_result));

		BCS_RESULT samples_sh_coefficients_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_samples_sh_coefficients_buffer,
			*samples_sh_coefficients_buffer);
		ASSERT(BCS_SUCCEEDED(samples_sh_coefficients_buffer_bind_result));

		GRAPHICS_EVENT_EX(*graphics, "GPU Geometry Bake geometry_index:%i '%s'", geometry_index, geometry_mesh_name);

		BCS_RESULT geometry_configuration_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_geometry_configuration_buffer,
			*geometry.configuration_buffer);
		ASSERT(BCS_SUCCEEDED(geometry_configuration_buffer_bind_result));

		BCS_RESULT geometry_vertex_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_geometry_vertex_buffer,
			*geometry.vertex_buffer);
		ASSERT(BCS_SUCCEEDED(geometry_vertex_buffer_bind_result));

		BCS_RESULT radiance_transfer_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_radiance_transfer_buffer,
			*geometry.radiance_transfer_buffer);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_buffer_bind_result));

		c_graphics_buffer* acceleration_structure_buffer;
		BCS_RESULT top_level_acceleration_structure_get_buffer_result = geometry.top_level_acceleration_structure->get_buffer(acceleration_structure_buffer);
		ASSERT(BCS_SUCCEEDED(top_level_acceleration_structure_get_buffer_result));

		BCS_RESULT acceleration_structure_buffer_bind_result = bind_graphics_buffer(
			*raytracing_global_register_layout,
			_radiance_transfer_register_geometry_acceleration_structure,
			*acceleration_structure_buffer);
		ASSERT(BCS_SUCCEEDED(acceleration_structure_buffer_bind_result));

		unsigned int num_vertices = geometry.geometry_mesh->get_vertex_count();
		raytracing_test_shader_pipeline->dispatch_rays(num_vertices);
		//geometry.radiance_transfer_buffer->copy_readback();

		geometry.state = _radiance_transfer_geometry_gpu_baked;

		raytracing_test_shader_pipeline->unbind();

		BCS_RESULT graphics_end_result = graphics->end();
		ASSERT(BCS_SUCCEEDED(graphics_end_result));
	}

	// #TODO: Multithread
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		c_radiance_transfer_geometry_gpu& geometry = geometries[geometry_index];
		const char* geometry_mesh_name = geometry.geometry_mesh->get_name();

		if (geometry.state != _radiance_transfer_geometry_gpu_baked)
		{
			continue;
		}

		GRAPHICS_EVENT_EX(*graphics, "GPU Geometry Read geometry_index:%i '%s'", geometry_index, geometry_mesh_name);

		BCS_RESULT geometry_configuration_buffer_buffer_destroy_result = graphics_buffer_destroy(geometry.configuration_buffer);
		ASSERT(BCS_SUCCEEDED(geometry_configuration_buffer_buffer_destroy_result));

		BCS_RESULT bottom_level_acceleration_structure_destroy_result = graphics_bottom_level_acceleration_structure_destroy(geometry.bottom_level_acceleration_structure);
		ASSERT(BCS_SUCCEEDED(bottom_level_acceleration_structure_destroy_result));

		BCS_RESULT top_level_acceleration_structure_destroy_result = graphics_top_level_acceleration_structure_destroy(geometry.top_level_acceleration_structure);
		ASSERT(BCS_SUCCEEDED(top_level_acceleration_structure_destroy_result));

		BCS_RESULT geometry_destroy_result = graphics_geometry_destroy(geometry.geometry);
		ASSERT(BCS_SUCCEEDED(geometry_destroy_result));

		BCS_RESULT geometry_vertex_buffer_buffer_destroy_result = graphics_buffer_destroy(geometry.vertex_buffer);
		ASSERT(BCS_SUCCEEDED(geometry_vertex_buffer_buffer_destroy_result));

		BCS_RESULT geometry_index_buffer_buffer_destroy_result = graphics_buffer_destroy(geometry.index_buffer);
		ASSERT(BCS_SUCCEEDED(geometry_index_buffer_buffer_destroy_result));

		union
		{
			void* radiance_transfer_gpu_data;
			float* radiance_transfer;
		};
		BCS_RESULT radiance_transfer_buffer_map_data_begin_result = geometry.radiance_transfer_buffer->map_data_read_begin(radiance_transfer_gpu_data);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_buffer_map_data_begin_result));

		unsigned int num_vertices = geometry.geometry_mesh->get_vertex_count();
		unsigned int num_storage_coefficients = num_vertices * num_coefficient_planes;

		memcpy(geometry.coefficients, radiance_transfer, sizeof(float) * num_storage_coefficients);

		BCS_RESULT radiance_transfer_buffer_map_data_end_result = geometry.radiance_transfer_buffer->map_data_read_end(radiance_transfer_gpu_data);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_buffer_map_data_end_result));

		BCS_RESULT radiance_transfer_buffer_destroy_result = graphics_buffer_destroy(geometry.radiance_transfer_buffer);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_buffer_destroy_result));

		geometry.state = _radiance_transfer_geometry_gpu_finished;
	}

	trivial_free(geometry_meshes);
	geometry_meshes = 0;
	num_geometry_meshes = 0;

	return BCS_S_OK;
}

BCS_RESULT c_radiance_transfer_engine_gpu::bind_graphics_buffer(
	c_graphics_register_layout& register_layout,
	e_radiance_transfer_register radiance_transfer_register,
	c_graphics_buffer& graphics_buffer)
{
	//BCS_RESULT bind_buffer_result = register_layout.bind_buffer(radiance_transfer_register, 0, graphics_buffer);
	s_graphics_register_layout_description& register_layout_description = raytracing_global_register_layouts[radiance_transfer_register];

	BCS_RESULT bind_buffer_result = register_layout.bind_buffer(
		register_layout_description.semantic,
		register_layout_description.register_index,
		register_layout_description.register_space,
		graphics_buffer);
	ASSERT(BCS_SUCCEEDED(bind_buffer_result));

	return bind_buffer_result;
}

BCS_RESULT c_radiance_transfer_engine_gpu::read(
	c_geometry_mesh& geometry_mesh,
	const float* const*& out_surface_coefficient_planes,
	const float* const*& out_subsurface_coefficient_planes,
	unsigned int& out_num_coefficient_planes)
{
	for (unsigned int geometry_index = 0; geometry_index < num_geometries; geometry_index++)
	{
		c_radiance_transfer_geometry_gpu& geometry = geometries[geometry_index];
		if (geometry.geometry_mesh == &geometry_mesh)
		{
			out_surface_coefficient_planes = geometry.surface_coefficient_planes;
			out_subsurface_coefficient_planes = geometry.subsurface_coefficient_planes;
			out_num_coefficient_planes = num_coefficient_planes;

			return BCS_S_OK;
		}
	}

	return BCS_E_NOT_FOUND;
}
