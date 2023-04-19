#include "eldoradocachefiletest-private-pch.h"

#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldoradotagdefinitions-public-pch.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>

s_engine_platform_build engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };

template<typename t_target_type>
BCS_RESULT iterate_prototype_structures(h_prototype& prototype, void(*callback)(t_target_type&))
{
	if (t_target_type* target_type = high_level_cast<t_target_type*>(&prototype))
	{
		callback(*target_type);
	}

	using namespace blofeld;

	BCS_RESULT rs = BCS_S_OK;

	h_prototype_serialization_info const& prototype_serialization_info = prototype.get_serialization_information();
	for (unsigned int field_serialization_index = 0; field_serialization_index < prototype_serialization_info.num_field_serialization_infos; field_serialization_index++)
	{
		h_field_serialization_info const& field_serialization_info = prototype_serialization_info.field_serialization_infos[field_serialization_index];
		s_tag_field const& tag_field = prototype_serialization_info.tag_struct_definition.fields[field_serialization_info.blofeld_field_index];

		if (field_serialization_info.pointer_to_member == nullptr)
		{
			continue;
		}

			switch (tag_field.field_type)
			{
			case _field_struct:
			{
				h_prototype* struct_prototype = high_level_cast<h_prototype*>(&field_data);
				ASSERT(struct_prototype != nullptr);

				if (BCS_FAILED(rs = iterate_prototype_structures(*struct_prototype, callback)))
				{
					return rs;
				}
			}
			break;
			case _field_array:
			{
				h_array* _array = high_level_cast<h_array*>(&field_data);
				ASSERT(_array != nullptr);

				for (h_prototype* array_prototype : *_array)
				{
					if (BCS_FAILED(rs = iterate_prototype_structures(*array_prototype, callback)))
					{
						return rs;
					}
				}
			}
			break;
			case _field_block:
			{
				h_block* block = high_level_cast<h_block*>(&field_data);
				ASSERT(block != nullptr);

				for (h_prototype* block_prototype : *block)
				{
					if (BCS_FAILED(rs = iterate_prototype_structures(*block_prototype, callback)))
					{
						return rs;
					}
				}
			}
			break;
			}
		}
	}

	return rs;
}

void postprocess(const char* output_directory, h_tag_instance& tag_instance)
{
	char tag_instance_name_buffer[256];
	sprintf(tag_instance_name_buffer, "eldorado\\%s\\%s", tag_instance.tag_group.blofeld_tag_group.name, tag_instance.get_file_name_without_extension());

	tag_instance.set_file_path_without_extension(tag_instance_name_buffer);

	using namespace blofeld::eldorado::pc32;

	iterate_prototype_structures<h_global_geometry_material_block>(
		tag_instance.prototype,
		[](h_global_geometry_material_block& geometry_material)
		{
			geometry_material.render_method.set_unqualified_file_path_without_extension(blofeld::taggroups::SHADER_TAG(engine_platform_build.engine_type), "shaders\\invalid");
		});

	iterate_prototype_structures<h_global_render_geometry_struct>(
		tag_instance.prototype, 
		[](h_global_render_geometry_struct& render_geometry)
		{
			h_resource* resource = render_geometry.api_resource.get_resource();

			s_resource_details resource_details;
			if (BCS_SUCCEEDED(resource->add_reference(resource_details, true)))
			{

				if (h_render_geometry_api_resource_definition_struct* render_geometry_api_resource = dynamic_cast<decltype(render_geometry_api_resource)>(resource_details.prototype))
				{

					for (h_global_mesh_block* mesh : render_geometry.meshes_block)
					{
						h_per_mesh_raw_data_block& per_mesh_raw_data = render_geometry.per_mesh_temporary_block.emplace_back();

						switch (mesh->index_buffer_type)
						{
						case _mesh_index_buffer_type_definition_triangle_strip:
							per_mesh_raw_data.flags.set(_per_mesh_raw_data_flags_indices_are_triangle_strips, true);
							break;
						case _mesh_index_buffer_type_definition_triangle_list:
							per_mesh_raw_data.flags.set(_per_mesh_raw_data_flags_indices_are_triangle_lists, true);
							break;
						case _mesh_index_buffer_type_definition_quad_list:
							per_mesh_raw_data.flags.set(_per_mesh_raw_data_flags_indices_are_quad_lists, true);
							break;
						default:
						case _mesh_index_buffer_type_definition__default:
						case _mesh_index_buffer_type_definition_line_list:
						case _mesh_index_buffer_type_definition_line_strip:
						case _mesh_index_buffer_type_definition_triangle_fan:
							// #TODO: Is this correct???
							break;
						}

						for (h_vertex_buffer_indices_word_array* vertex_buffer_indices_word : mesh->vertex_buffer_indices)
						{
							short vertex_buffer_index = vertex_buffer_indices_word->vertex_buffer_index;
							if (vertex_buffer_index >= 0)
							{
								h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[vertex_buffer_index];
								h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

								int32_t vertex_count = vertex_buffer_interop.vertex_count;
								short declaration = vertex_buffer_interop.declaration;
								short stride = vertex_buffer_interop.stride;
								h_data& vertices = vertex_buffer_interop.vertices;

								char* vertex_data_position = static_cast<char*>(vertices.data());
								for (int32_t vertex_index = 0; vertex_index < vertex_count; vertex_index++)
								{
									h_raw_vertex_block& raw_vertex =
										per_mesh_raw_data.raw_vertices_block.size() < vertex_count ?
										per_mesh_raw_data.raw_vertices_block.emplace_back() :
										per_mesh_raw_data.raw_vertices_block[vertex_index];

									enum e_vertex_buffer_format
									{
										_invalid,
										_world,
										_rigid,
										_skinned,
										_static_per_pixel,
										_unknown5,
										_static_per_vertex,
										_unknown7,
										_unused8,
										_ambient_prt,
										_linear_prt,
										_quadratic_prt,
										_unknownc,
										_unknownd,
										_static_per_vertex_color
									};

									switch (declaration)
									{
									case _world:
									case _rigid:
									{
										real_point3d* position = reinterpret_cast<real_point3d*>(vertex_data_position);
										real_point2d* texcoord = next_contiguous_pointer(real_point2d, position);
										real_point3d* normal = next_contiguous_pointer(real_point3d, texcoord);
										real_point3d* tangent = next_contiguous_pointer(real_point3d, normal);
										real_point3d* binormal = next_contiguous_pointer(real_point3d, tangent);

										raw_vertex.position = *position;
										raw_vertex.texcoord = *texcoord;
										raw_vertex.normal = *normal;
										raw_vertex.tangent = *tangent;
										raw_vertex.binormal = *binormal;
									}
									break;
									case _skinned:
									{
										real_point3d* position = reinterpret_cast<real_point3d*>(vertex_data_position);
										real_point2d* texcoord = next_contiguous_pointer(real_point2d, position);
										real_point3d* normal = next_contiguous_pointer(real_point3d, texcoord);
										real_point3d* tangent = next_contiguous_pointer(real_point3d, normal);
										real_point3d* binormal = next_contiguous_pointer(real_point3d, tangent);

										raw_vertex.position = *position;
										raw_vertex.texcoord = *texcoord;
										raw_vertex.normal = *normal;
										raw_vertex.tangent = *tangent;
										raw_vertex.binormal = *binormal;
									}
									break;
									}

									//h_prototype_array<h_node_indices_array, 4, h_raw_vertex_block, 6> node_indices;
									//h_prototype_array<h_node_weights_complete_array, 4, h_raw_vertex_block, 7> node_weights;

									raw_vertex.node_indices[0].node_index = 0;
									raw_vertex.node_indices[1].node_index = -1;
									raw_vertex.node_indices[2].node_index = -1;
									raw_vertex.node_indices[3].node_index = -1;
									raw_vertex.node_weights[0].node_weight = 1.0;
									raw_vertex.node_weights[1].node_weight = 0.0;
									raw_vertex.node_weights[2].node_weight = 0.0;
									raw_vertex.node_weights[3].node_weight = 0.0;

									vertex_data_position += stride;
								}
							}
						}

						short index_buffer_index = mesh->index_buffer_index;
						if (index_buffer_index >= render_geometry_api_resource->xenon_index_buffers_block.size())
						{
							h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[0];
							h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

							int32_t vertex_count = vertex_buffer_interop.vertex_count;
							int32_t index_count = vertex_count * 3;

							for (int32_t index_index = 0; index_index < index_count; index_index++)
							{
								h_indices_word_block& raw_index = per_mesh_raw_data.raw_indices_block.emplace_back();

								raw_index._word = 0;

							}
						}
						else if (index_buffer_index >= 0)
						{
							h_render_index_buffer_block& index_buffer = render_geometry_api_resource->xenon_index_buffers_block[index_buffer_index];
							h_render_index_buffer_descriptor_struct& index_buffer_interop = index_buffer.index_buffer_interop;

							int32_t primitive_type = index_buffer_interop.primitive_type;
							h_data& index_data = index_buffer_interop.index_data;

							int32_t index_count = index_data.size() / sizeof(short);

							char* index_data_position = static_cast<char*>(index_data.data());
							for (int32_t index_index = 0; index_index < index_count; index_index++)
							{
								h_indices_word_block& raw_index = per_mesh_raw_data.raw_indices_block.emplace_back();

								raw_index._word = *reinterpret_cast<short*>(index_data_position);

								index_data_position += sizeof(short);
							}
						}


					}

					debug_point;
				}



				debug_point;

				resource->remove_reference();
			}

			render_geometry.runtime_flags.set(_render_geometry_flags_processed, false);
			render_geometry.runtime_flags.set(_render_geometry_flags_available, false);
			render_geometry.api_resource.clear();
		});






	if (h_bitmap_block_struct* bitmap = dynamic_cast<decltype(bitmap)>(&tag_instance.prototype))
	{
		debug_point;

		auto x = bitmap->bitmaps_block.get_count();
		for (h_bitmap_data_block_def* bitmap_data : bitmap->bitmaps_block)
		{
			char interleaved_interop = bitmap_data->interleaved_interop;
			if (interleaved_interop >= 0)
			{
				h_bitmap_texture_interop_block_struct& bitmap_texture_interop = bitmap->hardware_textures_block[interleaved_interop];

				h_resource* resource = bitmap_texture_interop.texture_resource.get_resource();
				if (resource)
				{
					s_resource_details resource_details;
					if (BCS_SUCCEEDED(resource->add_reference(resource_details, false)))
					{
						bitmap->processed_pixel_data.append_elements(static_cast<const char*>(resource_details.buffer), resource_details.buffer_size);

						resource->remove_reference();
					}
				}
			}

			bitmap_data->interleaved_interop = -1;
		}
		bitmap->hardware_textures_block.clear();
	}
	if (h_render_model_block_struct* render_model = dynamic_cast<decltype(render_model)>(&tag_instance.prototype))
	{



		debug_point;
	}
}


void postprocess_write(const char* output_directory, h_tag_instance& tag_instance)
{
	const char* tag_file_path = tag_instance.get_file_path();

	c_fixed_string_2048 output_file_path;
	output_file_path.format("%s/%s", output_directory, tag_file_path);

	c_high_level_tag_file_writer tag_file_writer(engine_platform_build, output_file_path, tag_instance);
}


#include <functional>

template<typename t_index_type, typename t_lambda>
void parallel_invoke(t_index_type start, t_index_type end, t_lambda _lambda)
{
	::parallel_invoke(
		start,
		end,
		(t_parallel_invoke_func<t_index_type>)[](void* userdata, t_index_type index)
		{
			t_lambda& _lambda = *static_cast<t_lambda*>(userdata);
			_lambda(index);
		},
		&_lambda);
}

extern "C" int bcs_main()
{
	BCS_RESULT rs = BCS_S_OK;

	BCS_RESULT console_result = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Eldorado Cache File Test Console") : BCS_S_OK;
	if (BCS_SUCCEEDED(console_result))
	{
		BCS_RESULT tag_definition_registry_init_result = blofeld::tag_definition_registry_init();
		if (BCS_SUCCEEDED(tag_definition_registry_init_result))
		{
			BCS_RESULT tag_definitions_register_result = blofeld::tag_definitions_register();
			if (BCS_SUCCEEDED(tag_definitions_register_result))
			{
				BCS_RESULT high_level_registry_init_result = high_level_registry_init();
				if (BCS_SUCCEEDED(high_level_registry_init_result))
				{
					BCS_RESULT high_level_register_result = high_level_register();
					if (BCS_SUCCEEDED(high_level_register_result))
					{

						const char* eldorado_directory;
						BCS_RESULT get_eldorado_directory_result = command_line_get_argument("eldoradodir", eldorado_directory);
						BCS_FAIL_RETURN(get_eldorado_directory_result);

						c_cache_file_reader* cache_file_reader;
						BCS_RESULT open_cache_file_reader_result = ::open_cache_file_reader(eldorado_directory, engine_platform_build, true, true, &cache_file_reader);
						BCS_FAIL_RETURN(open_cache_file_reader_result);

						c_cache_cluster* cache_cluster;
						BCS_RESULT create_cache_cluster_result = ::create_cache_cluster(&cache_file_reader, 1, engine_platform_build, &cache_cluster);
						BCS_FAIL_RETURN(create_cache_cluster_result);

						s_cache_cluster_transplant_context* context;
						if (BCS_FAILED(high_level_transplant_context_create_v2(*cache_cluster, context)))
						{
							return rs;
						}

						if (BCS_FAILED(rs = high_level_transplant_context_execute_v2(context)))
						{
							return rs;
						}

						const char* output_directory;
						BCS_RESULT get_output_directory_result = command_line_get_argument("outputdir", output_directory);
						if (BCS_SUCCEEDED(get_output_directory_result))
						{
							h_tag_instance** tag_instances;
							unsigned int num_tag_instances;
							if (BCS_FAILED(rs = high_level_transplant_context_get_high_level_tag_instances(*context, tag_instances, num_tag_instances)))
							{
								return rs;
							}

							parallel_invoke(
								0u,
								num_tag_instances,
								[&](unsigned int tag_index)
								{
									h_tag_instance& tag_instance = *tag_instances[tag_index];

									postprocess(output_directory, tag_instance);
								});

							parallel_invoke(
								0u,
								num_tag_instances,
								[&](unsigned int tag_index)
								{
									h_tag_instance& tag_instance = *tag_instances[tag_index];

									postprocess_write(output_directory, tag_instance);
								});

							if (BCS_FAILED(rs = high_level_transplant_context_destroy_v2(context, true)))
							{
								return rs;
							}
						}

						//try
						//{


						//}
						//catch (BCS_RESULT _rs)
						//{
						//	rs = BCS_FAILED_CHAIN(rs, _rs);
						//}
						//catch (...)
						//{
						//	rs = BCS_FAILED_CHAIN(rs, BCS_E_FATAL);
						//}

						high_level_register_result = high_level_unregister();
						rs = BCS_FAILED_CHAIN(rs, high_level_register_result);
					}
					high_level_registry_init_result = high_level_registry_deinit();
					rs = BCS_FAILED_CHAIN(rs, high_level_registry_init_result);
				}
				tag_definitions_register_result = blofeld::tag_definitions_unregister();
				rs = BCS_FAILED_CHAIN(rs, tag_definitions_register_result);
			}
			tag_definition_registry_init_result = blofeld::tag_definition_registry_deinit();
			rs = BCS_FAILED_CHAIN(rs, tag_definition_registry_init_result);
		}
		rs = BCS_FAILED_CHAIN(rs, console_result);
	}

	bool write_memory_allocations = command_line_has_argument("writememoryallocations");
	if (write_memory_allocations)
	{
		::write_memory_allocations();
	}
	if (console_is_verbose())
	{
		print_memory_allocations();
	}

	BCS_FAIL_RETURN(rs);

	return 0;
}
