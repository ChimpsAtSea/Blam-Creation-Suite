#include "eldoradocachefiletest-private-pch.h"

#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldoradotagdefinitions-public-pch.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>

#include <geometrylib/geometrylib-public-pch.h>

s_engine_platform_build engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };

BCS_RESULT iterate_prototype_references(h_prototype& prototype, void(*callback)(void* userdata, h_tag_reference&), void* userdata)
{
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

		h_type& field_data = prototype.*field_serialization_info.pointer_to_member;

		switch (tag_field.field_type)
		{
		case _field_tag_reference:
		{
			h_tag_reference* tag_reference = high_level_cast<h_tag_reference*>(&field_data);
			ASSERT(tag_reference != nullptr);

			callback(userdata, *tag_reference);
		}
		break;
		case _field_struct:
		{
			h_prototype* struct_prototype = high_level_cast<h_prototype*>(&field_data);
			ASSERT(struct_prototype != nullptr);

			if (BCS_FAILED(rs = iterate_prototype_references(*struct_prototype, callback, userdata)))
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
				if (BCS_FAILED(rs = iterate_prototype_references(*array_prototype, callback, userdata)))
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
				if (BCS_FAILED(rs = iterate_prototype_references(*block_prototype, callback, userdata)))
				{
					return rs;
				}
			}
		}
		break;
		}
	}

	return rs;
}

template<typename t_lambda>
BCS_RESULT iterate_prototype_references(h_prototype& prototype, t_lambda lambda)
{
	return iterate_prototype_references(
		prototype,
		[](void* userdata, h_tag_reference& target)
		{
			t_lambda* _lambda = static_cast<t_lambda*>(userdata);
			return (*_lambda)(target);
		},
		&lambda);
}

BCS_RESULT iterate_prototype_references(h_prototype& prototype, void(*callback)(h_tag_reference&))
{
	return iterate_prototype_references(
		prototype,
		[](void* userdata, h_tag_reference& target)
		{
			void(*callback)(h_tag_reference&) = reinterpret_cast<decltype(callback)>(userdata);
			return callback(target);
		},
		&callback);
}

template<typename t_target_type>
BCS_RESULT iterate_prototype_structures(h_prototype& prototype, void(*callback)(void* userdata, t_target_type&), void* userdata)
{
	if (t_target_type* target_type = high_level_cast<t_target_type*>(&prototype))
	{
		callback(userdata, *target_type);
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

		h_type& field_data = prototype.*field_serialization_info.pointer_to_member;

		switch (tag_field.field_type)
		{
		case _field_struct:
		{
			h_prototype* struct_prototype = high_level_cast<h_prototype*>(&field_data);
			ASSERT(struct_prototype != nullptr);

			if (BCS_FAILED(rs = iterate_prototype_structures(*struct_prototype, callback, userdata)))
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
				if (BCS_FAILED(rs = iterate_prototype_structures(*array_prototype, callback, userdata)))
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
				if (BCS_FAILED(rs = iterate_prototype_structures(*block_prototype, callback, userdata)))
				{
					return rs;
				}
			}
		}
		break;
		}
	}

	return rs;
}

template<typename t_target_type, typename t_lambda>
BCS_RESULT iterate_prototype_structures(h_prototype& prototype, t_lambda lambda)
{
	return iterate_prototype_structures<t_target_type>(
		prototype,
		[](void* userdata, t_target_type& target)
		{
			t_lambda* _lambda = static_cast<t_lambda*>(userdata);
			return (*_lambda)(target);
		},
		&lambda);
}

template<typename t_target_type>
BCS_RESULT iterate_prototype_structures(h_prototype& prototype, void(*callback)(t_target_type&))
{
	return iterate_prototype_structures<t_target_type>(
		prototype,
		[](void* userdata, t_target_type& target)
		{
			void(*callback)(t_target_type&) = reinterpret_cast<decltype(callback)>(userdata);
			return callback(target);
		},
		&callback);
}

void postprocess_rename_tags(const char* output_directory, h_tag_instance& tag_instance)
{
	char tag_instance_name_buffer[256];
	sprintf(tag_instance_name_buffer, "eldorado\\%s\\%s", tag_instance.tag_group.blofeld_tag_group.name, tag_instance.get_file_name_without_extension());
	tag_instance.set_file_path_without_extension(tag_instance_name_buffer);
}

class h_prototype_resource :
	public h_resource
{
public:
	h_prototype* prototype;

	h_prototype_resource(h_prototype* _prototype) :
		h_resource(),
		prototype(_prototype)
	{

	}

	virtual ~h_prototype_resource()
	{

	}

	virtual BCS_RESULT add_reference(s_resource_details& resource_details, bool create_prototype) override
	{
		resource_details = {};
		resource_details.prototype = prototype;
		return BCS_S_OK;
	}

	virtual BCS_RESULT remove_reference() override
	{
		return BCS_S_OK;
	}

	virtual const char* get_debug_type_string() override
	{
		return "h_prototype_resource";
	}
};

void postprocess_a(const char* output_directory, h_tag_instance& tag_instance)
{
	using namespace blofeld::eldorado::pc32;

	iterate_prototype_structures<h_vehicle_steering_control_struct>(
		tag_instance.prototype,
		[](h_vehicle_steering_control_struct& steering_control)
		{
			real overdampen_cusp_angle = steering_control.overdampen_cusp_angle;

			overdampen_cusp_angle *= RAD2DEG;

			steering_control.overdampen_cusp_angle = overdampen_cusp_angle;
		});

	iterate_prototype_structures<h_vehicle_turning_control_struct>(
		tag_instance.prototype,
		[](h_vehicle_turning_control_struct& turning_control)
		{
			real maximum_left_turn = turning_control.maximum_left_turn;
			real maximum_right_turn_negative = turning_control.maximum_right_turn_negative;
			real turn_rate = turning_control.turn_rate;

			maximum_left_turn *= RAD2DEG;
			maximum_right_turn_negative *= RAD2DEG;
			turn_rate *= RAD2DEG;

			turning_control.maximum_left_turn = maximum_left_turn;
			turning_control.maximum_right_turn_negative = maximum_right_turn_negative;
			turning_control.turn_rate = turn_rate;
		});

	iterate_prototype_structures<h_chopper_block>(
		tag_instance.prototype,
		[](h_chopper_block& chopper)
		{
			real bank_to_turn_ratio = chopper.bank_to_turn_ratio;

			bank_to_turn_ratio *= RAD2DEG;

			chopper.bank_to_turn_ratio = bank_to_turn_ratio;
		});

	iterate_prototype_structures<h_mantis_block>(
		tag_instance.prototype,
		[](h_mantis_block& mantis)
		{
			real turn_acceleration_limit = mantis.turn_acceleration_limit;

			turn_acceleration_limit *= RAD2DEG;

			mantis.turn_acceleration_limit = turn_acceleration_limit;
		});

	iterate_prototype_structures<h_human_plane_block>(
		tag_instance.prototype,
		[](h_human_plane_block& human_plane)
		{
			real maximum_roll = human_plane.maximum_roll;

			maximum_roll *= RAD2DEG;

			human_plane.maximum_roll = maximum_roll;
		});

	iterate_prototype_structures<h_havok_vehicle_physics_struct>(
		tag_instance.prototype,
		[](h_havok_vehicle_physics_struct& havok_vehicle_physics)
		{
			real ground_maximum_slope_0 = havok_vehicle_physics.ground_maximum_slope_0;
			real ground_maximum_slope_1 = havok_vehicle_physics.ground_maximum_slope_1;

			ground_maximum_slope_0 = acos(ground_maximum_slope_0) * RAD2DEG;
			ground_maximum_slope_1 = acos(ground_maximum_slope_1) * RAD2DEG;

			havok_vehicle_physics.ground_maximum_slope_0 = ground_maximum_slope_0;
			havok_vehicle_physics.ground_maximum_slope_1 = ground_maximum_slope_1;
		});

	

	iterate_prototype_structures<h_global_render_geometry_struct>(
		tag_instance.prototype,
		[](h_global_render_geometry_struct& render_geometry)
		{
			//e_mesh_vertex_type_definition vertex_type = {};
			//if (render_geometry.meshes_block.size())
			//{
			//	vertex_type = render_geometry.meshes_block[0].vertex_type;

			//	render_geometry = {};

			//	auto& mesh = render_geometry.meshes_block.emplace_back();
			//	mesh.vertex_type = vertex_type;
			//	auto& per_mesh_raw_data_block = render_geometry.per_mesh_temporary_block.emplace_back();
			//}



			//return;
			h_render_geometry_api_resource_definition_struct* render_geometry_api_resource = nullptr;
			if (h_resource* resource = render_geometry.api_resource.get_resource())
			{
				s_resource_details resource_details;
				if (BCS_SUCCEEDED(resource->add_reference(resource_details, true)))
				{
					if (h_render_geometry_api_resource_definition_struct* _render_geometry_api_resource = dynamic_cast<decltype(render_geometry_api_resource)>(resource_details.prototype))
					{
						// copy the resource
						render_geometry_api_resource = new() h_render_geometry_api_resource_definition_struct(*_render_geometry_api_resource);

						resource->remove_reference();
					}
				}
			}
			if (render_geometry_api_resource != nullptr)
			{
				h_prototype_resource* prototype_resource = new h_prototype_resource(render_geometry_api_resource);
				render_geometry.api_resource.set_resource(prototype_resource);
			}
			else
			{
				return;
			}

			// h_prototype_block<h_vertex_buffers_block, h_render_geometry_api_resource_definition_struct, 0> pc_vertex_buffers_block;
			// h_prototype_block<h_index_buffers_block, h_render_geometry_api_resource_definition_struct, 1> pc_index_buffers_block;
			// h_prototype_block<h_render_vertex_buffer_block, h_render_geometry_api_resource_definition_struct, 2> xenon_vertex_buffers_block;
			// h_prototype_block<h_render_index_buffer_block, h_render_geometry_api_resource_definition_struct, 3> xenon_index_buffers_block;

			for (h_render_vertex_buffer_block* render_vertex_buffer : render_geometry_api_resource->xenon_vertex_buffers_block)
			{
				//h_prototype_field<int32_t, h_render_vertex_buffer_descriptor_struct, 0> vertex_count;
				//h_prototype_field<short, h_render_vertex_buffer_descriptor_struct, 1> declaration;
				//h_prototype_field<short, h_render_vertex_buffer_descriptor_struct, 2> stride;
				//h_prototype_data<h_render_vertex_buffer_descriptor_struct, 3> vertices;

				h_vertex_buffers_block& vertex_buffer = render_geometry_api_resource->pc_vertex_buffers_block.emplace_back();
				//h_prototype_field<char, h_vertex_buffers_block, 0> declaration_type;
				//h_prototype_field<char, h_vertex_buffers_block, 1> stride;
				//h_prototype_field<int32_t, h_vertex_buffers_block, 2> count;
				//h_prototype_field<int32_t, h_vertex_buffers_block, 3> d3d_hardware_format;

				vertex_buffer.declaration_type = render_vertex_buffer->vertex_buffer_interop.declaration;
				vertex_buffer.stride = render_vertex_buffer->vertex_buffer_interop.stride;
				vertex_buffer.count = render_vertex_buffer->vertex_buffer_interop.vertex_count;
				vertex_buffer.d3d_hardware_format = 0;
			}

			for (h_render_index_buffer_block* render_index_buffer : render_geometry_api_resource->xenon_index_buffers_block)
			{
				// h_prototype_field<int32_t, h_render_index_buffer_descriptor_struct, 0> primitive_type;
				// h_prototype_data<h_render_index_buffer_descriptor_struct, 1> index_data;

				h_index_buffers_block& index_buffer = render_geometry_api_resource->pc_index_buffers_block.emplace_back();

				// h_prototype_field<char, h_index_buffers_block, 0> declaration_type;
				// h_prototype_field<char, h_index_buffers_block, 1> stride;
				// h_prototype_field<int32_t, h_index_buffers_block, 2> count;
				// h_prototype_field<int32_t, h_index_buffers_block, 3> d3d_hardware_format;

				e_mesh_index_buffer_type_definition index_buffer_type = static_cast<e_mesh_index_buffer_type_definition>((int32_t)render_index_buffer->index_buffer_interop.primitive_type);

				index_buffer.declaration_type = render_index_buffer->index_buffer_interop.primitive_type;
				index_buffer.stride = sizeof(short);
				index_buffer.count = render_index_buffer->index_buffer_interop.index_data.size() / sizeof(short);
				index_buffer.d3d_hardware_format = 0;
			}

			bool contains_world_geometry = false;
			for (h_global_mesh_block* mesh : render_geometry.meshes_block)
			{
				if (static_cast<e_mesh_vertex_type_definition>(mesh->vertex_type) == _mesh_vertex_type_definition_world)
				{
					contains_world_geometry = true;
					break;
				}
			}

			for (h_global_mesh_block* mesh : render_geometry.meshes_block)
			{
				struct s_world_vertex
				{
					real_point3d position;
					real_point2d texcoord;
					real_point3d normal;
					real_point3d tangent;
					real_point3d binormal;
				};
				static_assert(sizeof(s_world_vertex) == 0x38);
				struct s_rigid_vertex
				{
					real_point3d position;
					real_point2d texcoord;
					real_point3d normal;
					real_point3d tangent;
					real_point3d binormal;
				};
				static_assert(sizeof(s_rigid_vertex) == 0x38);
				struct s_skinned_vertex
				{
					real_point3d position;
					real_point2d texcoord;
					real_point3d normal;
					real_point3d tangent;
					real_point3d binormal;
					unsigned char indices[4];
					unsigned char weights[4];
				};
				static_assert(sizeof(s_skinned_vertex) == 0x40);
				struct s_particle_model_vertex
				{
					real_point3d position;
					real_point2d texcoord;
					real_point3d normal;
				};
				static_assert(sizeof(s_particle_model_vertex) == 0x20);
				struct s_flat_world_vertex
				{

				};
				struct s_flat_rigid_vertex
				{

				};
				struct s_flat_skinned_vertex
				{

				};
				struct s_screen_vertex
				{

				};
				struct s_debug_vertex
				{
					float debug;
				};
				struct s_transparent_vertex
				{

				};
				struct s_particle_vertex
				{

				};
				struct s_contrail_vertex
				{

				};
				struct s_light_volume_vertex
				{

				};
				struct s_chud_vertex_simple
				{

				};
				struct s_chud_vertex_fancy
				{

				};
				struct s_decorator_vertex
				{
					real_point3d position;
					real_point2d texcoord;
					real_point3d normal;
				};
				static_assert(sizeof(s_decorator_vertex) == 0x20);
				struct s_tiny_position_vertex
				{

				};
				struct s_patchy_fog_vertex
				{

				};
				struct s_water_vertex
				{
					real_point3d local_info;
					real_point3d water_velocity;
					real_point3d base_texcoord;
				};
				static_assert(sizeof(s_water_vertex) == 0x24);
				struct s_ripple_vertex
				{

				};
				struct s_implicit_vertex
				{

				};
				struct s_beam_vertex
				{

				};
				struct s_dual_quat_vertex
				{

				};
				struct s_prt_ambient_vertex
				{
					float coeffcients[1];
				};
				struct s_prt_packed_linear_vertex
				{
					unsigned char coefficients[4];
				};
				struct s_prt_linear_vertex
				{
					float coeffcients[4];
				};
				struct s_prt_quadratic_vertex
				{
					float coeffcients[9];
				};

				short index_buffer_index = mesh->index_buffer_index;

				if (contains_world_geometry)
				{
					h_per_mesh_mopp_block& per_mesh_mopp_block = render_geometry.per_mesh_mopp_block.emplace_back();

					if (unsigned int num_box_requests = mesh->parts_block.size())
					{
						s_mopp_box_request* mopp_box_requests = new s_mopp_box_request[num_box_requests]{};

						for (unsigned int box_request_index = 0; box_request_index < num_box_requests; box_request_index++)
						{
							s_mopp_box_request& mopp_box_request = mopp_box_requests[box_request_index];
							mopp_box_request.half_extents_x = 10000; // #TODO
							mopp_box_request.half_extents_y = 10000; // #TODO
							mopp_box_request.half_extents_z = 10000; // #TODO
						}

						t_mopp_box_result mopp_box_result = box_mopps_request(mopp_box_requests, num_box_requests);
						ASSERT(mopp_box_result);
						delete[] mopp_box_requests;

						struct hkArray_uchar
						{
							unsigned int m_data;
							int m_size;
							int m_capacityAndFlags;
						};

						struct s_mopp_code_info
						{
							float code_info_x;
							float code_info_y;
							float code_info_z;
							float code_info_w;
						};

						struct s_mopp_code
						{
							unsigned int vtable;
							short size;
							short reference_count;
							unsigned int unknown8;
							unsigned int unknownC;
							s_mopp_code_info m_info;
							hkArray_uchar m_data;
							char m_buildType;
						};
						static_assert(sizeof(s_mopp_code) == 0x30);

						s_mopp_code header = {};
						header.size = sizeof(s_mopp_code);
						header.m_info.code_info_x = mopp_box_result->code_info_x;
						header.m_info.code_info_y = mopp_box_result->code_info_y;
						header.m_info.code_info_z = mopp_box_result->code_info_z;
						header.m_info.code_info_w = mopp_box_result->code_info_w;
						header.m_data.m_size = mopp_box_result->mopp_codes_bytes;
						header.m_data.m_capacityAndFlags = mopp_box_result->mopp_codes_bytes;
						header.m_buildType = mopp_box_result->build_type;

						per_mesh_mopp_block.mopp_code.clear();

						per_mesh_mopp_block.mopp_code.append_elements(reinterpret_cast<char const*>(&header), sizeof(header));
						per_mesh_mopp_block.mopp_code.append_elements(static_cast<char const*>(mopp_box_result->mopp_codes), mopp_box_result->mopp_codes_bytes);
						if (unsigned int alignment_over = per_mesh_mopp_block.mopp_code.size() % 16)
						{
							per_mesh_mopp_block.mopp_code.create_elements(16 - alignment_over);
						}

						per_mesh_mopp_block.mopp_code.append_elements(reinterpret_cast<char const*>(&header), sizeof(header));
						per_mesh_mopp_block.mopp_code.append_elements(static_cast<char const*>(mopp_box_result->mopp_codes), mopp_box_result->mopp_codes_bytes);
						if (unsigned int alignment_over = per_mesh_mopp_block.mopp_code.size() % 16)
						{
							per_mesh_mopp_block.mopp_code.create_elements(16 - alignment_over);
						}

						short index_a = 0;
						for (auto& subpart : mesh->subparts_block)
						{
							h_global_geometry_section_strip_index_block& section_strip_index = per_mesh_mopp_block.mopp_reorder_table_block.emplace_back();
							section_strip_index.index = index_a;
							index_a++;
						}

						short index_b = 0;
						for (auto& subpart : mesh->subparts_block)
						{
							h_global_geometry_section_strip_index_block& section_strip_index = per_mesh_mopp_block.mopp_reorder_table_block.emplace_back();
							section_strip_index.index = index_b;
							index_b++;
						}

						short index_c = 0;
						for (auto& part : mesh->parts_block)
						{
							h_global_geometry_section_strip_index_block& section_strip_index = per_mesh_mopp_block.mopp_reorder_table_block.emplace_back();
							section_strip_index.index = mopp_box_result->hit_index_to_shape_index[index_c];
							index_c++;
						}

						short index_d = 0;
						for (auto& part : mesh->parts_block)
						{
							h_global_geometry_section_strip_index_block& section_strip_index = per_mesh_mopp_block.mopp_reorder_table_block.emplace_back();
							section_strip_index.index = mopp_box_result->hit_index_to_shape_index[index_d];
							index_d++;
						}

						box_mopps_destroy(mopp_box_result);
					}
				}

				h_per_mesh_raw_data_block& per_mesh_raw_data = render_geometry.per_mesh_temporary_block.emplace_back();

				if (index_buffer_index != -1)
				{
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
						debug_point;
						break;
					}

					switch (mesh->vertex_type)
					{
					case _mesh_vertex_type_definition_world:
					case _mesh_vertex_type_definition_rigid:
					case _mesh_vertex_type_definition_skinned:
					case _mesh_vertex_type_definition_skinned_dual_quat_blend:
					{
						ASSERT(index_buffer_index < render_geometry_api_resource->xenon_index_buffers_block.size());
					}
					break;
					case _mesh_vertex_type_definition_particle_model:
					{
						ASSERT(render_geometry_api_resource->xenon_index_buffers_block.size() == 0);
					}
					break;
					case _mesh_vertex_type_definition_flat_world:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_flat_rigid:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_flat_skinned:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_screen:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_debug:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_transparent:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_particle:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_contrail:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_light_volume:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_chud_simple:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_chud_fancy:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_decorator:
					{
						ASSERT(index_buffer_index < render_geometry_api_resource->xenon_index_buffers_block.size());
					}
					break;
					case _mesh_vertex_type_definition_position_only:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_patchy_fog:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_water:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_ripple:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_implicit_geometry:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					case _mesh_vertex_type_definition_beam:
					{
						FATAL_ERROR("Not implemented");
					}
					break;
					default:
					{
						FATAL_ERROR("Unexpected mesh vertex type");
					}
					break;
					}

					if (render_geometry_api_resource->xenon_index_buffers_block.size() == 0)
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
					else
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

				int per_mesh_temporary_vertex_buffer_index = mesh->vertex_buffer_indices[0].vertex_buffer_index;
				if (per_mesh_temporary_vertex_buffer_index != -1)
				{
					ASSERT(index_buffer_index != -1);

					h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[per_mesh_temporary_vertex_buffer_index];
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

						raw_vertex.position = real_point3d{};
						raw_vertex.texcoord = real_point2d{};
						raw_vertex.normal = real_point3d{};
						raw_vertex.binormal = real_point3d{};
						raw_vertex.tangent = real_point3d{};
						raw_vertex.lightmap_texcoord = real_point2d{};
						raw_vertex.node_indices[0].node_index = 0;
						raw_vertex.node_indices[1].node_index = -1;
						raw_vertex.node_indices[2].node_index = -1;
						raw_vertex.node_indices[3].node_index = -1;
						raw_vertex.node_weights[0].node_weight = 1.0;
						raw_vertex.node_weights[1].node_weight = 0.0;
						raw_vertex.node_weights[2].node_weight = 0.0;
						raw_vertex.node_weights[3].node_weight = 0.0;
						raw_vertex.vertex_color = real_point3d{};

						switch (mesh->vertex_type)
						{
						case _mesh_vertex_type_definition_world:
						{
							ASSERT(declaration == 1);
							ASSERT(stride == sizeof(s_world_vertex));
							s_world_vertex& vertex = *reinterpret_cast<s_world_vertex*>(vertex_data_position);
							raw_vertex.position = vertex.position;
							raw_vertex.texcoord = vertex.texcoord;
							raw_vertex.normal = vertex.normal;
							raw_vertex.binormal = vertex.binormal;
							raw_vertex.tangent = vertex.tangent;
						}
						break;
						case _mesh_vertex_type_definition_rigid:
						{
							ASSERT(declaration == 2);
							ASSERT(stride == sizeof(s_rigid_vertex));
							s_rigid_vertex& vertex = *reinterpret_cast<s_rigid_vertex*>(vertex_data_position);
							raw_vertex.position = vertex.position;
							raw_vertex.texcoord = vertex.texcoord;
							raw_vertex.normal = vertex.normal;
							raw_vertex.binormal = vertex.binormal;
							raw_vertex.tangent = vertex.tangent;
						}
						break;
						case _mesh_vertex_type_definition_skinned:
						case _mesh_vertex_type_definition_skinned_dual_quat_blend:
						{
							ASSERT(declaration == 3);
							ASSERT(stride == sizeof(s_skinned_vertex));
							s_skinned_vertex& vertex = *reinterpret_cast<s_skinned_vertex*>(vertex_data_position);
							raw_vertex.position = vertex.position;
							raw_vertex.texcoord = vertex.texcoord;
							raw_vertex.normal = vertex.normal;
							raw_vertex.binormal = vertex.binormal;
							raw_vertex.tangent = vertex.tangent;
							raw_vertex.node_indices[0].node_index = vertex.indices[0];
							raw_vertex.node_indices[1].node_index = vertex.indices[1];
							raw_vertex.node_indices[2].node_index = vertex.indices[2];
							raw_vertex.node_indices[3].node_index = vertex.indices[3];
							raw_vertex.node_weights[0].node_weight = float(vertex.weights[0]) / float(UINT8_MAX);
							raw_vertex.node_weights[1].node_weight = float(vertex.weights[1]) / float(UINT8_MAX);
							raw_vertex.node_weights[2].node_weight = float(vertex.weights[2]) / float(UINT8_MAX);
							raw_vertex.node_weights[3].node_weight = float(vertex.weights[3]) / float(UINT8_MAX);
						}
						break;
						case _mesh_vertex_type_definition_particle_model:
						{
							ASSERT(declaration == 25);
							ASSERT(stride == sizeof(s_particle_model_vertex));
							s_particle_model_vertex& vertex = *reinterpret_cast<s_particle_model_vertex*>(vertex_data_position);
							raw_vertex.position = vertex.position;
							raw_vertex.texcoord = vertex.texcoord;
							raw_vertex.normal = vertex.normal;
						}
						break;
						case _mesh_vertex_type_definition_flat_world:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_flat_rigid:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_flat_skinned:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_screen:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_debug:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_transparent:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_particle:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_contrail:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_light_volume:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_chud_simple:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_chud_fancy:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_decorator:
						{
							ASSERT(declaration == 24);
							ASSERT(stride == sizeof(s_decorator_vertex));
							s_decorator_vertex& vertex = *reinterpret_cast<s_decorator_vertex*>(vertex_data_position);
							raw_vertex.position = vertex.position;
							raw_vertex.texcoord = vertex.texcoord;
							raw_vertex.normal = vertex.normal;
						}
						break;
						case _mesh_vertex_type_definition_position_only:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_patchy_fog:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_water:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_ripple:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_implicit_geometry:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						case _mesh_vertex_type_definition_beam:
						{
							FATAL_ERROR("Not implemented");
						}
						break;
						default:
						{
							FATAL_ERROR("Unexpected mesh vertex type");
						}
						break;
						}
						vertex_data_position += stride;
					}
				}

				struct s_static_per_pixel_vertex
				{
					real_point2d texcoord;
				};

				int per_mesh_unknown1_data_vertex_buffer_index = mesh->vertex_buffer_indices[1].vertex_buffer_index;
				if (per_mesh_unknown1_data_vertex_buffer_index != -1)
				{
					debug_point;

					h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[per_mesh_unknown1_data_vertex_buffer_index];
					h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

					int32_t vertex_count = vertex_buffer_interop.vertex_count;
					short declaration = vertex_buffer_interop.declaration;
					short stride = vertex_buffer_interop.stride;
					h_data& vertices = vertex_buffer_interop.vertices;

					char* vertex_data_position = static_cast<char*>(vertices.data());
					for (int32_t vertex_index = 0; vertex_index < vertex_count; vertex_index++)
					{
						switch (declaration)
						{
						case 4:
						{
							ASSERT(declaration == 4);
							ASSERT(stride == sizeof(s_static_per_pixel_vertex));
							s_static_per_pixel_vertex& vertex = *reinterpret_cast<s_static_per_pixel_vertex*>(vertex_data_position);
							// raw_vertex.texcoord = vertex.texcoord;
							debug_point;
						}
						break;
						default:
						{
							FATAL_ERROR("Unexpected vertex declaration type");
						}
						break;
						}
						vertex_data_position += stride;
					}
				}

				struct s_static_per_vertex_color_vertex
				{
					rgb_color color;
				};

				int per_mesh_unknown2_data_vertex_buffer_index = mesh->vertex_buffer_indices[2].vertex_buffer_index;
				if (per_mesh_unknown2_data_vertex_buffer_index != -1)
				{
					debug_point;

					h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[per_mesh_unknown2_data_vertex_buffer_index];
					h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

					int32_t vertex_count = vertex_buffer_interop.vertex_count;
					short declaration = vertex_buffer_interop.declaration;
					short stride = vertex_buffer_interop.stride;
					h_data& vertices = vertex_buffer_interop.vertices;

					char* vertex_data_position = static_cast<char*>(vertices.data());
					for (int32_t vertex_index = 0; vertex_index < vertex_count; vertex_index++)
					{
						switch (declaration)
						{
						case 14:
						{
							ASSERT(declaration == 14);
							ASSERT(stride == sizeof(s_static_per_vertex_color_vertex));
							s_static_per_vertex_color_vertex& vertex = *reinterpret_cast<s_static_per_vertex_color_vertex*>(vertex_data_position);
							// raw_vertex.texcoord = vertex.texcoord;
							debug_point;
						}
						break;
						default:
						{
							FATAL_ERROR("Unexpected vertex declaration type");
						}
						break;
						}
						vertex_data_position += stride;
					}
				}

				h_per_mesh_prt_data_block* per_mesh_prt_data = nullptr;
				switch (mesh->prt_vertex_type)
				{
				case _mesh_transfer_vertex_type_definition_no_prt:
				case _mesh_transfer_vertex_type_definition_prt_ambient:
				case _mesh_transfer_vertex_type_definition_prt_linear:
				case _mesh_transfer_vertex_type_definition_prt_quadratic:
					per_mesh_prt_data = &render_geometry.per_mesh_prt_data_block.emplace_back();
					break;
				}

				int per_mesh_prt_data_vertex_buffer_index = mesh->vertex_buffer_indices[3].vertex_buffer_index;
				if (per_mesh_prt_data_vertex_buffer_index != -1)
				{
					if (render_geometry.user_data_block.size() == 0)
					{
						struct s_render_geometry_user_data_prt_info
						{
							unsigned int unknown0;
							unsigned int unknown4;
							unsigned int num_coefficients;
							unsigned int unknownC;
							unsigned int unknown10;
						};
						s_render_geometry_user_data_prt_info prt_info = {};

						prt_info.unknown0 = 3;
						prt_info.unknown4 = 0;
						int order = 0;
						switch (mesh->prt_vertex_type)
						{
						case _mesh_transfer_vertex_type_definition_no_prt:
							prt_info.num_coefficients = 0;
							order = 0;
							break;
						case _mesh_transfer_vertex_type_definition_prt_ambient:
							prt_info.num_coefficients = 1;
							order = 0;
							break;
						case _mesh_transfer_vertex_type_definition_prt_linear:
							prt_info.num_coefficients = 4;
							order = 1;
							break;
						case _mesh_transfer_vertex_type_definition_prt_quadratic:
							prt_info.num_coefficients = 9;
							order = 2;
							break;
						}
						prt_info.unknownC = 0;
						prt_info.unknown10 = 0;

						auto& prt_user_data = render_geometry.user_data_block.emplace_back();
						
						prt_user_data.user_data.append_elements(reinterpret_cast<char*>(&prt_info), sizeof(prt_info));
						prt_user_data.user_data_header.data_type = _render_geometry_user_data_type_definition_prt_info;
						prt_user_data.user_data_header.data_count = 1;
						prt_user_data.user_data_header.data_size = sizeof(prt_info);
					}

					ASSERT(per_mesh_prt_data != nullptr);

					h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[per_mesh_prt_data_vertex_buffer_index];
					h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

					int32_t vertex_count = vertex_buffer_interop.vertex_count;
					short declaration = vertex_buffer_interop.declaration;
					short stride = vertex_buffer_interop.stride;
					h_data& vertices = vertex_buffer_interop.vertices;

					char* vertex_data_position = static_cast<char*>(vertices.data());
					for (int32_t vertex_index = 0; vertex_index < vertex_count; vertex_index++)
					{
						switch (mesh->prt_vertex_type)
						{
						case _mesh_transfer_vertex_type_definition_no_prt:
						{
							FATAL_ERROR("Invalid PRT type");
						}
						break;
						case _mesh_transfer_vertex_type_definition_prt_ambient:
						{
							ASSERT(declaration == 9);
							ASSERT(stride == sizeof(s_prt_ambient_vertex));
							s_prt_ambient_vertex vertex = *reinterpret_cast<s_prt_ambient_vertex*>(vertex_data_position);
							debug_point;

							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
						}
						break;
						case _mesh_transfer_vertex_type_definition_prt_linear:
						{
							ASSERT(declaration == 10);
							ASSERT(stride == sizeof(s_prt_packed_linear_vertex));
							s_prt_packed_linear_vertex packed_vertex = *reinterpret_cast<s_prt_packed_linear_vertex*>(vertex_data_position);
							debug_point;

							s_prt_linear_vertex vertex = {};


							// #TODO: Decode packed PRT
							//vertex.coeffcients[0] = float(packed_vertex.coefficients[0]) / float(UINT8_MAX);
							//vertex.coeffcients[1] = float(packed_vertex.coefficients[1]) / float(UINT8_MAX);
							//vertex.coeffcients[2] = float(packed_vertex.coefficients[2]) / float(UINT8_MAX);
							//vertex.coeffcients[3] = float(packed_vertex.coefficients[3]) / float(UINT8_MAX);

							vertex.coeffcients[0] = 0.2820947917738781f;
							vertex.coeffcients[1] = 0.0f;
							vertex.coeffcients[2] = 0.0f;
							vertex.coeffcients[3] = 0.0f;

							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
						}
						break;
						case _mesh_transfer_vertex_type_definition_prt_quadratic:
						{
							ASSERT(declaration == 11);
							ASSERT(stride == sizeof(s_prt_quadratic_vertex));
							s_prt_quadratic_vertex vertex = *reinterpret_cast<s_prt_quadratic_vertex*>(vertex_data_position);
							debug_point;

							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
							per_mesh_prt_data->mesh_pca_data.append_elements(reinterpret_cast<char*>(&vertex), sizeof(vertex));
						}
						break;
						}
						vertex_data_position += stride;
					}
				}

				int per_mesh_unknown4_data_vertex_buffer_index = mesh->vertex_buffer_indices[4].vertex_buffer_index;
				ASSERT(per_mesh_unknown4_data_vertex_buffer_index == -1);

				int per_mesh_unknown5_data_vertex_buffer_index = mesh->vertex_buffer_indices[5].vertex_buffer_index;
				ASSERT(per_mesh_unknown5_data_vertex_buffer_index == -1);

				int per_mesh_unknown6_data_vertex_buffer_index = mesh->vertex_buffer_indices[6].vertex_buffer_index;
				if (per_mesh_unknown6_data_vertex_buffer_index != -1)
				{
					debug_point;

					h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[per_mesh_unknown6_data_vertex_buffer_index];
					h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

					int32_t vertex_count = vertex_buffer_interop.vertex_count;
					short declaration = vertex_buffer_interop.declaration;
					short stride = vertex_buffer_interop.stride;
					h_data& vertices = vertex_buffer_interop.vertices;

					char* vertex_data_position = static_cast<char*>(vertices.data());
					for (int32_t vertex_index = 0; vertex_index < vertex_count; vertex_index++)
					{
						switch (mesh->vertex_type)
						{
						case _mesh_vertex_type_definition_world:
						{
							ASSERT(declaration == 1);
							ASSERT(stride == sizeof(s_world_vertex));
							s_world_vertex& vertex = *reinterpret_cast<s_world_vertex*>(vertex_data_position);
							//raw_vertex.position = vertex.position;
							//raw_vertex.texcoord = vertex.texcoord;
							//raw_vertex.normal = vertex.normal;
							//raw_vertex.binormal = vertex.binormal;
							//raw_vertex.tangent = vertex.tangent;
							debug_point;
						}
						break;
						default:
						{
							FATAL_ERROR("Unexpected mesh vertex type");
						}
						break;
						}
						vertex_data_position += stride;
					}
				}



				int per_mesh_unknown7_data_vertex_buffer_index = mesh->vertex_buffer_indices[7].vertex_buffer_index;
				if (per_mesh_unknown7_data_vertex_buffer_index != -1)
				{
					h_raw_water_block& raw_water_data = per_mesh_raw_data.raw_water_data_block.emplace_back();

					debug_point;

					h_render_vertex_buffer_block& vertex_buffer = render_geometry_api_resource->xenon_vertex_buffers_block[per_mesh_unknown7_data_vertex_buffer_index];
					h_render_vertex_buffer_descriptor_struct& vertex_buffer_interop = vertex_buffer.vertex_buffer_interop;

					int32_t vertex_count = vertex_buffer_interop.vertex_count;
					short declaration = vertex_buffer_interop.declaration;
					short stride = vertex_buffer_interop.stride;
					h_data& vertices = vertex_buffer_interop.vertices;

					char* vertex_data_position = static_cast<char*>(vertices.data());
					for (int32_t vertex_index = 0; vertex_index < vertex_count; vertex_index++)
					{
						switch (mesh->vertex_type)
						{
						case _mesh_vertex_type_definition_world:
						{
							ASSERT(declaration == 27);
							ASSERT(stride == sizeof(s_water_vertex));
							s_water_vertex& vertex = *reinterpret_cast<s_water_vertex*>(vertex_data_position);

							h_raw_water_append_block& raw_water_vertex = raw_water_data.raw_water_vertices_block.emplace_back();
							raw_water_vertex.local_info = vertex.local_info;
							raw_water_vertex.water_velocity = vertex.water_velocity;
							raw_water_vertex.base_texcoord = vertex.base_texcoord;

							if (raw_water_data.raw_water_indices_block.size() < USHRT_MAX)
							{
								h_indices_word_block& raw_water_index0 = raw_water_data.raw_water_indices_block.emplace_back();
								raw_water_index0._word = 0;
							}

							if (raw_water_data.raw_water_indices_block.size() < USHRT_MAX)
							{
								h_indices_word_block& raw_water_index1 = raw_water_data.raw_water_indices_block.emplace_back();
								raw_water_index1._word = 0;
							}

							if (raw_water_data.raw_water_indices_block.size() < USHRT_MAX)
							{
								h_indices_word_block& raw_water_index2 = raw_water_data.raw_water_indices_block.emplace_back();
								raw_water_index2._word = 0;
							}


							debug_point;
						}
						break;
						default:
						{
							FATAL_ERROR("Unexpected mesh vertex type");
						}
						break;
						}
						vertex_data_position += stride;
					}
				}

				mesh->vertex_buffer_indices[0] = 0;
				mesh->vertex_buffer_indices[1] = 0;
				mesh->vertex_buffer_indices[2] = 0;
				mesh->vertex_buffer_indices[3] = 0;
				mesh->vertex_buffer_indices[4] = 0;
				mesh->vertex_buffer_indices[5] = 0;
				mesh->vertex_buffer_indices[6] = 0;
				mesh->vertex_buffer_indices[7] = 0;
				mesh->index_buffer_index = -1;
			}

			for (h_global_mesh_block* mesh : render_geometry.meshes_block)
			{
				if (static_cast<short&>(mesh->vertex_buffer_indices[0].vertex_buffer_index) >= render_geometry.per_mesh_temporary_block.size())
				{
					debug_point;
				}
			}

			render_geometry.runtime_flags.set(_render_geometry_flags_processed, false);
			render_geometry.runtime_flags.set(_render_geometry_flags_available, false);
			//render_geometry.api_resource.clear();
		});
}

void postprocess(const char* output_directory, h_tag_instance& tag_instance)
{
	using namespace blofeld::eldorado::pc32;

	iterate_prototype_structures<h_cluster_instanced_geometry_shape_struct>(
		tag_instance.prototype,
		[](h_cluster_instanced_geometry_shape_struct& cluster_instanced_geometry_shape)
		{
			debug_point;
		});

	iterate_prototype_structures<h_scenario_structure_bsp_block_struct>(
		tag_instance.prototype,
		[](h_scenario_structure_bsp_block_struct& scenario_structure_bsp)
		{



			////for (unsigned int i = 0; i < 512; i++)
			////{
			////	raw_resources.raw_items.instanced_geometries_definitions_block.emplace_back();
			////}









			////scenario_structure_bsp.import_info_checksum;
			////scenario_structure_bsp.import_version;
			//scenario_structure_bsp.visible_name.clear();
			//scenario_structure_bsp.flags.clear();
			//scenario_structure_bsp.seam_identifiers_block.clear();
			//scenario_structure_bsp.edge_to_seam_edge_block.clear();
			//scenario_structure_bsp.collision_materials_block.clear();
			////scenario_structure_bsp.leaves_block.clear();
			////scenario_structure_bsp.world_bounds_x;
			////scenario_structure_bsp.world_bounds_y;
			////scenario_structure_bsp.world_bounds_z;
			//scenario_structure_bsp.structure_surfaces_block.clear();
			//scenario_structure_bsp.large_structure_surfaces_block.clear();
			//scenario_structure_bsp.structure_surface_to_triangle_mapping_block.clear();
			//scenario_structure_bsp.weather_palette_block.clear();
			//scenario_structure_bsp.atmosphere_palette_block.clear();
			//scenario_structure_bsp.camera_fx_palette_block.clear();
			//scenario_structure_bsp.weather_polyhedra_block.clear();
			//scenario_structure_bsp.detail_objects_block.clear();
			////scenario_structure_bsp.materials_block.clear();
			//scenario_structure_bsp.sky_owner_cluster_block.clear();
			//scenario_structure_bsp.conveyor_surfaces_block.clear();
			//scenario_structure_bsp.breakable_surface_sets_block.clear();
			//scenario_structure_bsp.pathfinding_data_block.clear();
			//scenario_structure_bsp.pathfinding_edges_block.clear();
			//scenario_structure_bsp.acoustics_palette_block.clear();
			//scenario_structure_bsp.background_sound_palette_block.clear();
			//scenario_structure_bsp.sound_environment_palette_block.clear();
			//scenario_structure_bsp.sound_pas_data.clear();
			//scenario_structure_bsp.markers_block.clear();
			//scenario_structure_bsp.marker_light_palette_block.clear();
			//scenario_structure_bsp.marker_light_palette_index_block.clear();
			//scenario_structure_bsp.runtime_decals_block.clear();
			//scenario_structure_bsp.environment_object_palette_block.clear();
			//scenario_structure_bsp.environment_objects_block.clear();
			//scenario_structure_bsp.leaf_map_leaves_block.clear();
			//scenario_structure_bsp.leaf_map_connections_block.clear();
			//scenario_structure_bsp.errors_block.clear();
			//scenario_structure_bsp.instanced_geometry_instances_block.clear();
			//scenario_structure_bsp.decorator_sets_block.clear();

			//scenario_structure_bsp.acoustics_sound_clusters_block.clear();
			//scenario_structure_bsp.ambience_sound_clusters_block.clear();
			//scenario_structure_bsp.reverb_sound_clusters_block.clear();
			//scenario_structure_bsp.transparent_planes_block.clear();
			//scenario_structure_bsp.debug_info_block.clear();
			//scenario_structure_bsp.structure_physics = {};
			//scenario_structure_bsp.audibility_block.clear();
			//scenario_structure_bsp.object_fake_lightprobes_block.clear();


			for (auto& cluster : scenario_structure_bsp.clusters_block)
			{
				cluster->runtime_first_decal_index = -1;
				cluster->runtime_decal_cound = 0;
				cluster->acoustics = -1;
				cluster->acoustics_sound_cluster_index = 0;
				cluster->decorator_groups_block.clear();
			}












			//scenario_structure_bsp.render_geometry.part_sorting_position_block.clear();
			////scenario_structure_bsp.decorator_instance_buffer = {};




			////scenario_structure_bsp.cluster_portals_block.clear();
			//for (auto& cluster : scenario_structure_bsp.clusters_block)
			//{
			//	//cluster->portals_block.clear();
			//}


			////if (raw_resources.raw_items.collision_bsp_block.size() == 0)
			////{
			////	raw_resources.raw_items.collision_bsp_block.emplace_back();
			////}
			////h_global_collision_bsp_block& global_collision_bsp = raw_resources.raw_items.collision_bsp_block[0];

			////for (unsigned int i = 0; i < 512; i++)
			////{
			////	global_collision_bsp.bsp3d_nodes_block.emplace_back();
			////	global_collision_bsp.planes_block.emplace_back();
			////}

			//for (auto& mesh : scenario_structure_bsp.render_geometry.meshes_block)
			//{
			//	mesh->instance_buckets_block.clear();
			//	mesh->mesh_flags.set(e_mesh_flags::_mesh_flags_mesh_has_per_instance_lighting_do_not_modify, false);
			//}

			////h_prototype_block<h_structure_bsp_raw_resources, h_structure_bsp_resource_interface, 0> raw_resources_block;
			////h_prototype_resource_field<h_structure_bsp_tag_resources_struct, h_structure_bsp_resource_interface, 1> tag_resources;
			////h_prototype_resource_field<h_structure_bsp_cache_file_tag_resources_struct, h_structure_bsp_resource_interface, 2> cache_file_resources;

			////h_prototype_block<h_bsp3d_nodes_block_struct, h_global_collision_bsp_block, 0> bsp3d_nodes_block;
			////h_prototype_block<h_planes_block, h_global_collision_bsp_block, 1> planes_block;
			////h_prototype_block<h_collision_leaf_struct, h_global_collision_bsp_block, 2> leaves_block;
			////h_prototype_block<h_bsp2d_references_block, h_global_collision_bsp_block, 3> bsp2d_references_block;
			////h_prototype_block<h_bsp2d_nodes_block, h_global_collision_bsp_block, 4> bsp2d_nodes_block;
			////h_prototype_block<h_surfaces_block, h_global_collision_bsp_block, 5> surfaces_block;
			////h_prototype_block<h_edges_block, h_global_collision_bsp_block, 6> edges_block;
			////h_prototype_block<h_vertices_block, h_global_collision_bsp_block, 7> vertices_block;

			if (scenario_structure_bsp.resource_interface.raw_resources_block.size() == 0)
			{
				scenario_structure_bsp.resource_interface.raw_resources_block.emplace_back();
			}
			h_structure_bsp_raw_resources& raw_resources = scenario_structure_bsp.resource_interface.raw_resources_block[0];

			if (h_resource* tag_resources_resource = scenario_structure_bsp.resource_interface.tag_resources.get_resource())
			{
				s_resource_details tag_resources_details;
				if (BCS_SUCCEEDED(tag_resources_resource->add_reference(tag_resources_details, true)))
				{
					if (h_structure_bsp_tag_resources_struct* tag_resources = high_level_cast<decltype(tag_resources)>(tag_resources_details.prototype))
					{
						raw_resources.raw_items = tag_resources->resource_items;

						debug_point;
					}
					tag_resources_resource->remove_reference();
				}
			}

			if (h_resource* cache_file_resources_resource = scenario_structure_bsp.resource_interface.cache_file_resources.get_resource())
			{
				s_resource_details cache_file_resources_details;
				if (BCS_SUCCEEDED(cache_file_resources_resource->add_reference(cache_file_resources_details, true)))
				{
					if (h_structure_bsp_cache_file_tag_resources_struct* cache_file_resources = high_level_cast<decltype(cache_file_resources)>(cache_file_resources_details.prototype))
					{
						scenario_structure_bsp.large_structure_surfaces_block = cache_file_resources->large_structure_surfaces_block;
						scenario_structure_bsp.structure_surface_to_triangle_mapping_block = cache_file_resources->structure_surface_to_triangle_mapping_block;
						scenario_structure_bsp.edge_to_seam_edge_block = cache_file_resources->edge_to_seam_edge_block;
						scenario_structure_bsp.pathfinding_data_block = cache_file_resources->pathfinding_data_block;

						debug_point;
					}
					cache_file_resources_resource->remove_reference();
				}
			}

			scenario_structure_bsp.resource_interface.tag_resources.clear();
			scenario_structure_bsp.resource_interface.cache_file_resources.clear();

			scenario_structure_bsp.resource_interface.use_resource_items = 0;
		});

	iterate_prototype_structures<h_scenario_struct_definition>(
		tag_instance.prototype,
		[](h_scenario_struct_definition& scenario)
		{
			for (auto& structure_bsp : scenario.structure_bsps_block)
			{
				structure_bsp->structure_design.clear();
				structure_bsp->structure_lighting_info.clear();
				structure_bsp->wind.clear();
				structure_bsp->cubemap_bitmap_group_reference.clear();
			}

			scenario.skies_block.clear();
			scenario.zone_set_pvs_block.clear();
			scenario.zone_set_audibility_block.clear();
			scenario.zone_sets_block.clear();
			scenario.lighting_zone_sets_block.clear();
			scenario.campaign_players_block.clear();
			scenario.unknown_block.clear();
			scenario.predicted_resources_block.clear();
			scenario.functions_block.clear();
			scenario.editor_scenario_data.clear();

			scenario.comments_block.clear();
			scenario.object_names_block.clear();
			scenario.scenery_block.clear();
			scenario.scenery_palette_block.clear();
			scenario.bipeds_block.clear();
			scenario.biped_palette_block.clear();
			scenario.vehicles_block.clear();
			scenario.vehicle_palette_block.clear();
			scenario.equipment_block.clear();
			scenario.equipment_palette_block.clear();
			scenario.weapons_block.clear();
			scenario.weapon_palette_block.clear();
			scenario.device_groups_block.clear();
			scenario.machines_block.clear();
			scenario.machine_palette_block.clear();
			scenario.terminals_block.clear();
			scenario.terminal_palette_block.clear();
			scenario.arg_devices_block.clear();
			scenario.arg_device_palette_block.clear();
			scenario.controls_block.clear();
			scenario.control_palette_block.clear();
			scenario.sound_scenery_block.clear();
			scenario.sound_scenery_palette_block.clear();
			scenario.giants_block.clear();
			scenario.giant_palette_block.clear();
			scenario.effect_scenery_block.clear();
			scenario.effect_scenery_palette_block.clear();
			scenario.light_volumes_block.clear();
			scenario.light_volumes_palette_block.clear();
			scenario.mv_vehicle_palette_block.clear();
			scenario.mv_weapon_palette_block.clear();
			scenario.mv_equipment_palette_block.clear();
			scenario.mv_scenery_palette_block.clear();
			scenario.mv_teleporters_palette_block.clear();
			scenario.mv_goals_palette_block.clear();
			scenario.mv_spawners_palette_block.clear();
			scenario.soft_ceilings_block.clear();
			scenario.player_starting_profile_block.clear();
			//scenario.player_starting_locations_block.clear();
			scenario.trigger_volumes_block.clear();
			scenario.recorded_animations_block.clear();
			scenario.zone_set_switch_trigger_volumes_block.clear();

			scenario.enemy_forbid_influence_block.clear();
			scenario.enemy_bias_influence_block.clear();
			scenario.ally_bias_influence_block.clear();
			scenario.selected_ally_bias_influence_block.clear();
			scenario.dead_teammate_influence_block.clear();
			scenario.weapon_spawn_influencers_block.clear();
			scenario.vehicle_spawn_influencers_block.clear();
			scenario.projectile_spawn_influencers_block.clear();
			scenario.equipment_spawn_influencers_block.clear();
			scenario.koth_hill_influencer_block.clear();
			scenario.oddball_influencer_block.clear();
			scenario.ctf_flag_away_influencer_block.clear();
			scenario.territories_ally_influencer_block.clear();
			scenario.territories_enemy_influencer_block.clear();
			scenario.infection_safe_zone_human_influencer_block.clear();
			scenario.infection_safe_zone_zombie_influencer_block.clear();
			scenario.vip_influencer_block.clear();

			scenario.decals_block.clear();
			scenario.decal_palette_block.clear();

			scenario.detail_object_collection_palette_block.clear();
			scenario.style_pallette_block.clear();
			scenario.squad_groups_block.clear();
			scenario.squads_block.clear();
			scenario.zones_block.clear();
			scenario.squad_patrols_block.clear();
			scenario.mission_scenes_block.clear();
			scenario.character_palette_block.clear();
			scenario.ai_pathfinding_data_block.clear();
			scenario.ai_user_hint_data_block.clear();
			scenario.ai_recording_references_block.clear();
			scenario.script_string_data.clear();
			scenario.scripts_block.clear();
			scenario.globals_block.clear();
			scenario.references_block.clear();
			scenario.source_files_block.clear();
			scenario.scripting_data_block.clear();
			scenario.cutscene_flags_block.clear();
			scenario.cutscene_camera_points_block.clear();
			scenario.cutscene_titles_block.clear();

			scenario.custom_object_names.clear();
			scenario.chapter_title_text.clear();
			scenario.scenario_resources_block.clear();
			scenario.hs_unit_seats_block.clear();
			scenario.scenario_kill_triggers_block.clear();
			scenario.scenario_safe_zone_triggers_block.clear();
			scenario.hs_syntax_datums_block.clear();
			scenario.orders_block.clear();
			scenario.triggers_block.clear();
			scenario.acoustics_palette_block.clear();
			scenario.old_background_sound_palette_block.clear();
			scenario.sound_environment_palette_block.clear();
			scenario.weather_palette_block.clear();
			scenario.atmosphere_block.clear();
			scenario.camera_fx_palette_block.clear();
			scenario.unused2_block.clear();
			scenario.unused3_block.clear();
			scenario.unused4_block.clear();
			scenario.scenario_cluster_data_block.clear();
			scenario.acoustic_spaces_block.clear();
			//scenario.object_salts.clear();
			scenario.spawn_data_block.clear();
			scenario.sound_effect_collection.clear();
			scenario.crates_block.clear();
			scenario.crate_palette_block.clear();
			scenario.flock_palette_block.clear();
			scenario.flocks_block.clear();
			scenario.subtitles.clear();
			scenario.creatures_block.clear();
			scenario.creature_palette_block.clear();
			scenario.editor_folders_block.clear();
			scenario.game_engine_strings.clear();
			scenario.mission_dialogue_block.clear();
			scenario.objectives.clear();
			scenario.interpolators_block.clear();
			scenario.shared_references_block.clear();
			scenario.screen_effect_references_block.clear();
			scenario.simulation_definition_table_block.clear();
			scenario.camera_effects.clear();
			scenario.global_screen_effect.clear();
			scenario.value.clear();
			scenario.atmospheric.clear();
			scenario.chocalate_mountain.clear();
			scenario.new_lightmaps.clear();
			scenario.performance_throttles.clear();
			scenario.reference_frames_block.clear();
			scenario.ai_objectives_block.clear();
			scenario.designer_zones_block.clear();
			scenario.zone_debugger_block.clear();
			scenario.decorators_block.clear();
			scenario.cinematics_block.clear();
			scenario.cinematic_lighting_palette_block.clear();
			scenario.override_player_representations_block.clear();
			scenario.campaign_metagame_block.clear();
			scenario.soft_surfaces_block.clear();
			scenario.cubemaps_block.clear();
			scenario.cortana_effects_block.clear();
			scenario.airprobes_block.clear();
			scenario.budget_references_block.clear();
			scenario.tchou_shader_effect_hack.clear();
			scenario.vision_mode_override.clear();
			scenario.value_block.clear();

			for (auto& object_salt : scenario.object_salts)
			{
				object_salt->salt = 0;
			}

			scenario.type = {};
			scenario.campaign_type = {};
			scenario.flags = {};
			scenario.campaign_id = {};
			scenario.map_id = {};
			scenario.local_north = {};
			scenario.sandbox_budget = {};

			debug_point;
		});

	iterate_prototype_references(
		tag_instance.prototype,
		[](h_tag_reference& tag_reference)
		{
			tag tag_reference_group_tag = tag_reference.get_group_tag();

			const char* name = tag_reference.get_file_path_without_extension();
			if (tag_reference_group_tag == blofeld::taggroups::SCENARIO_LIGHTMAP_BSP_DATA_TAG && strcmp("eldorado\\scenario_lightmap_bsp_data\\tag3A0B", name) == 0)
			{
				debug_point;
			}

			tag shader_group_tags[] =
			{
				blofeld::taggroups::SHADER_BEAM_TAG,
				blofeld::taggroups::SHADER_BLACK_TAG,
				blofeld::taggroups::SHADER_CONTRAIL_TAG,
				blofeld::taggroups::SHADER_CORTANA_TAG,
				blofeld::taggroups::SHADER_CUSTOM_TAG,
				blofeld::taggroups::SHADER_DECAL_TAG,
				blofeld::taggroups::SHADER_FOLIAGE_TAG,
				blofeld::taggroups::SHADER_FUR_STENCIL_TAG,
				blofeld::taggroups::SHADER_FUR_TAG,
				blofeld::taggroups::SHADER_GLASS_TAG,
				blofeld::taggroups::SHADER_HALOGRAM_TAG,
				blofeld::taggroups::SHADER_LIGHT_RESPONSE_TAG,
				blofeld::taggroups::SHADER_LIGHT_VOLUME_TAG,
				blofeld::taggroups::SHADER_MUX_MATERIAL_TAG,
				blofeld::taggroups::SHADER_MUX_TAG,
				blofeld::taggroups::SHADER_PARTICLE_TAG,
				blofeld::taggroups::SHADER_SCREEN_TAG,
				blofeld::taggroups::SHADER_SKIN_TAG,
				blofeld::taggroups::SHADER_TAG(engine_platform_build.engine_type),
				blofeld::taggroups::SHADER_TERRAIN_TAG,
				blofeld::taggroups::SHADER_WATERFALL_TAG,
				blofeld::taggroups::SHADER_WATER_TAG,
				blofeld::taggroups::SHADER_ZONLY_TAG,
			};
			for (tag group_tag : shader_group_tags)
			{
				if (tag_reference_group_tag == group_tag)
				{
					tag_reference.set_unqualified_file_path_without_extension(SHADER_TAG, "shaders\\invalid");
				}
				debug_point;
			}
		});

	iterate_prototype_structures<h_physics_model_struct_definition>(
		tag_instance.prototype,
		[](h_physics_model_struct_definition& physics_model)
		{
			iterate_prototype_structures<h_havok_primitive_struct>(
				physics_model,
				[&physics_model](h_havok_primitive_struct& havok_primitive)
				{
					short mass_distribution_index = havok_primitive.mass_distribution_index;
					short num_mass_distributions = mass_distribution_index + 1;

					for (short new_mass_distribution_index = physics_model.mass_distributions_block.size(); new_mass_distribution_index < num_mass_distributions; new_mass_distribution_index++)
					{
						auto& mass_distribution = physics_model.mass_distributions_block.emplace_back();
					}

					//auto& mass_distribution = physics_model.mass_distributions_block[mass_distribution_index];

					for (auto& mass_distribution : physics_model.mass_distributions_block)
					{
						// #TODO: Investigate how to restore the mass distribution block

						if (physics_model.rigid_bodies_block.size() > 0)
						{
							// This is bad
							mass_distribution->center_of_mass = physics_model.rigid_bodies_block[0].center_of_mass;
							mass_distribution->havok_w_center_of_mass = physics_model.rigid_bodies_block[0].havok_w_center_of_mass;
							mass_distribution->inertia_tensor_i = physics_model.rigid_bodies_block[0].intertia_tensor_x;
							mass_distribution->havok_w_inertia_tensor_i = physics_model.rigid_bodies_block[0].havok_w_intertia_tensor_x;
							mass_distribution->inertia_tensor_j = physics_model.rigid_bodies_block[0].intertia_tensor_y;
							mass_distribution->havok_w_inertia_tensor_j = physics_model.rigid_bodies_block[0].havok_w_intertia_tensor_y;
							mass_distribution->inertia_tensor_k = physics_model.rigid_bodies_block[0].intertia_tensor_z;
							mass_distribution->havok_w_inertia_tensor_k = physics_model.rigid_bodies_block[0].havok_w_intertia_tensor_z;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).i /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).j /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).k /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).i /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).j /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).k /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).i /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).j /= physics_model.rigid_bodies_block[0].mass;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).k /= physics_model.rigid_bodies_block[0].mass;
						}
						else
						{
							// This is REAL bad
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).i = 0.00018561;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).j = 0.00000000;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).k = 0.00000000;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).i = 0.00000000;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).j = 0.00018561;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).k = 0.00000000;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).i = 0.00000000;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).j = 0.00000000;
							static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).k = 0.00018561;
						}
					}

					debug_point;
				});
			debug_point;
		});


	iterate_prototype_structures<h_global_geometry_material_block>(
		tag_instance.prototype,
		[](h_global_geometry_material_block& geometry_material)
		{
			geometry_material.render_method.set_unqualified_file_path_without_extension(blofeld::taggroups::SHADER_TAG(engine_platform_build.engine_type), "shaders\\invalid");
		});

	iterate_prototype_structures<h_scenario_structure_bsp_block_struct>(
		tag_instance.prototype,
		[](h_scenario_structure_bsp_block_struct& scenario_structure_bsp)
		{
			//scenario_structure_bsp.import_info_checksum = {};
			//scenario_structure_bsp.import_version = {};
			//scenario_structure_bsp.visible_name = {};
			//scenario_structure_bsp.flags = {};
			//scenario_structure_bsp.seam_identifiers_block.clear();
			//scenario_structure_bsp.edge_to_seam_edge_block.clear();
			//scenario_structure_bsp.collision_materials_block.clear();
			//scenario_structure_bsp.leaves_block.clear();
			//scenario_structure_bsp.world_bounds_x = {};
			//scenario_structure_bsp.world_bounds_y = {};
			//scenario_structure_bsp.world_bounds_z = {};
			//scenario_structure_bsp.structure_surfaces_block.clear();
			//scenario_structure_bsp.large_structure_surfaces_block.clear();
			//scenario_structure_bsp.structure_surface_to_triangle_mapping_block.clear();
			//scenario_structure_bsp.cluster_portals_block.clear();
			//scenario_structure_bsp.weather_palette_block.clear();
			//scenario_structure_bsp.atmosphere_palette_block.clear();
			//scenario_structure_bsp.camera_fx_palette_block.clear();
			//scenario_structure_bsp.weather_polyhedra_block.clear();
			//scenario_structure_bsp.detail_objects_block.clear();
			////scenario_structure_bsp.clusters_block.clear(); // problems
			//scenario_structure_bsp.materials_block.clear();
			//scenario_structure_bsp.sky_owner_cluster_block.clear();
			//scenario_structure_bsp.conveyor_surfaces_block.clear();
			//scenario_structure_bsp.breakable_surface_sets_block.clear();
			//scenario_structure_bsp.pathfinding_data_block.clear();
			//scenario_structure_bsp.pathfinding_edges_block.clear();
			scenario_structure_bsp.acoustics_palette_block.clear();
			//scenario_structure_bsp.background_sound_palette_block.clear();
			//scenario_structure_bsp.sound_environment_palette_block.clear();
			//scenario_structure_bsp.sound_pas_data.clear();
			//scenario_structure_bsp.markers_block.clear();
			//scenario_structure_bsp.marker_light_palette_block.clear();
			//scenario_structure_bsp.marker_light_palette_index_block.clear();
			scenario_structure_bsp.runtime_decals_block.clear();
			//scenario_structure_bsp.environment_object_palette_block.clear();
			//scenario_structure_bsp.environment_objects_block.clear();
			//scenario_structure_bsp.leaf_map_leaves_block.clear();
			//scenario_structure_bsp.leaf_map_connections_block.clear();
			//scenario_structure_bsp.errors_block.clear();
			////scenario_structure_bsp.instanced_geometry_instances_block.clear(); // problems
			//scenario_structure_bsp.decorator_sets_block.clear();
			//scenario_structure_bsp.decorator_instance_buffer = {};
			//scenario_structure_bsp.acoustics_sound_clusters_block.clear();
			//scenario_structure_bsp.ambience_sound_clusters_block.clear();
			//scenario_structure_bsp.reverb_sound_clusters_block.clear();
			//scenario_structure_bsp.transparent_planes_block.clear();
			//scenario_structure_bsp.debug_info_block.clear();
			////scenario_structure_bsp.structure_physics = {}; // problems
			//scenario_structure_bsp.audibility_block.clear();
			//scenario_structure_bsp.object_fake_lightprobes_block.clear();
			//scenario_structure_bsp.render_geometry = {};
			//scenario_structure_bsp.widget_references_block.clear();
			////scenario_structure_bsp.resource_interface = {}; // problems
			//
			// // problems
			//while (scenario_structure_bsp.clusters_block.size() > 1)
			//{
			//	scenario_structure_bsp.clusters_block.remove(1);
			//}
			////scenario_structure_bsp.clusters_block.clear();
			//scenario_structure_bsp.instanced_geometry_instances_block.clear();
			//scenario_structure_bsp.structure_physics = {};
			//scenario_structure_bsp.resource_interface = {};

			//auto& cluster = scenario_structure_bsp.clusters_block[0];

			//cluster.bounds_x = {};
			//cluster.bounds_y = {};
			//cluster.bounds_z = {};
			//cluster.scenario_sky_index = {};
			//cluster.atmosphere_index = {};
			//cluster.camera_fx_index = {};
			//cluster.acoustics = {};
			//cluster.acoustics_sound_cluster_index = {};
			//cluster.background_sound = {};
			//cluster.sound_environment = {};
			//cluster.weather = {};
			//cluster.background_sound_sound_cluster_index = {};
			//cluster.reverb_sound_cluster_index = {};
			//cluster.runtime_first_decal_index = {};
			//cluster.runtime_decal_cound = {};
			//cluster.flags = {};
			//cluster.predicted_resources_block.clear();
			//cluster.portals_block.clear();
			//cluster.collision_instanced_geometry = {};
			//cluster.mesh_index = {};
			//cluster.seam_indices_block.clear();
			//cluster.decorator_groups_block.clear();
			//cluster.pvs_bound_object_identifiers_block.clear();
			//cluster.pvs_bound_object_references_block.clear();
			//cluster.cluster_cubemaps_block.clear();

			debug_point;
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
	{
		c_high_level_tag_file_writer tag_file_writer(engine_platform_build, output_file_path, tag_instance);
		debug_point;
	}
	//{
	//	void* tag_file_data;
	//	uint64_t tag_file_data_size;
	//	filesystem_read_file_to_memory(output_file_path, tag_file_data, tag_file_data_size);
	//	c_high_level_tag_file_reader* tag_file_reader = new c_high_level_tag_file_reader(engine_platform_build, tag_file_data);

	//	BCS_RESULT rs = BCS_S_OK;

	//	h_prototype* out_prototype;
	//	tag_file_reader->parse_high_level_object(out_prototype);

	//	delete tag_file_reader;

	//	debug_point;
	//}
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



						//{
						//	void* tag_file_data;
						//	uint64_t tag_file_data_size;
						//	if (BCS_SUCCEEDED(filesystem_read_file_to_memory("E:\\SteamLibrary\\steamapps\\common\\H3EK\\tags\\levels\\multi\\guardian\\guardian.scenario_structure_bsp", tag_file_data, tag_file_data_size)))
						//	{
						//		c_high_level_tag_file_reader* tag_file_reader = new c_high_level_tag_file_reader({ _engine_type_halo3, _platform_type_pc_64bit }, tag_file_data);

						//		BCS_RESULT rs = BCS_S_OK;

						//		h_prototype* out_prototype;
						//		tag_file_reader->parse_high_level_object(out_prototype);

						//		delete tag_file_reader;

						//		debug_point;
						//	}
						//	
						//}

						debug_point;





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

									postprocess_rename_tags(output_directory, tag_instance);
								});

							parallel_invoke(
								0u,
								num_tag_instances,
								[&](unsigned int tag_index)
								{
									h_tag_instance& tag_instance = *tag_instances[tag_index];

									postprocess_a(output_directory, tag_instance);
								});

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
