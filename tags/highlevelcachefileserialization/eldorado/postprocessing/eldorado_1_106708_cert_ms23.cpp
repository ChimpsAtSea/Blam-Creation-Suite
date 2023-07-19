#include "highlevelcachefileserialization-private-pch.h"

namespace eldorado_1_106708_cert_ms23
{
	static constexpr s_engine_platform_build engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };

	c_postprocessing_fixup rename_tags_fixup(true, postprocessing_rename_tags);
	c_postprocessing_fixup scenario_structure_bsp_fixup(true, postprocessing_scenario_structure_bsp);
	c_postprocessing_fixup scenario_fixup(true, postprocessing_scenario);
	c_postprocessing_fixup nuke_shader_references_fixup(true, postprocessing_nuke_shader_references);
	c_postprocessing_fixup physics_model_fixup(true, postprocessing_physics_model);
	c_postprocessing_fixup bitmaps_fixup(true, postprocessing_bitmaps);
	c_postprocessing_fixup decorator_sets_fixup(true, postprocessing_decorator_sets);
	c_postprocessing_fixup postprocessing_global_render_geometry_fixup(true, postprocessing_global_render_geometry);
	
	c_postprocessing_fixup* const postprocessing_fixups[] =
	{
		&rename_tags_fixup,
		&scenario_structure_bsp_fixup,
		&scenario_fixup,
		&nuke_shader_references_fixup,
		&physics_model_fixup,
		&bitmaps_fixup,
		&decorator_sets_fixup,
		&postprocessing_global_render_geometry_fixup,
	};
	unsigned int const num_postprocessing_fixups = _countof(postprocessing_fixups);

	BCS_RESULT postprocessing_rename_tags(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		c_fixed_string_256 tag_instance_name;
		tag_instance_name.format(
			"eldorado\\%s\\%s",
			target_tag_instance.tag_group.blofeld_tag_group.name,
			target_tag_instance.get_file_name_without_extension());
		target_tag_instance.set_file_path_without_extension(tag_instance_name);

		return BCS_S_OK;
	}

	BCS_RESULT postprocessing_scenario_structure_bsp(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		using namespace blofeld::eldorado::pc32;

		h_scenario_structure_bsp_block_struct* scenario_structure_bsp = dynamic_cast<decltype(scenario_structure_bsp)>(&target_tag_instance.prototype);
		if (scenario_structure_bsp == nullptr)
		{
			return BCS_S_NO_CHANGES_MADE;
		}

		if (scenario_structure_bsp->resource_interface.raw_resources_block.size() == 0)
		{
			scenario_structure_bsp->resource_interface.raw_resources_block.emplace_back();
		}
		h_structure_bsp_raw_resources& raw_resources = scenario_structure_bsp->resource_interface.raw_resources_block[0];

		if (h_resource* tag_resources_resource = scenario_structure_bsp->resource_interface.tag_resources.get_resource())
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

		if (h_resource* cache_file_resources_resource = scenario_structure_bsp->resource_interface.cache_file_resources.get_resource())
		{
			s_resource_details cache_file_resources_details;
			if (BCS_SUCCEEDED(cache_file_resources_resource->add_reference(cache_file_resources_details, true)))
			{
				if (h_structure_bsp_cache_file_tag_resources_struct* cache_file_resources = high_level_cast<decltype(cache_file_resources)>(cache_file_resources_details.prototype))
				{
					scenario_structure_bsp->large_structure_surfaces_block = cache_file_resources->large_structure_surfaces_block;
					scenario_structure_bsp->structure_surface_to_triangle_mapping_block = cache_file_resources->structure_surface_to_triangle_mapping_block;
					scenario_structure_bsp->edge_to_seam_edge_block = cache_file_resources->edge_to_seam_edge_block;
					scenario_structure_bsp->pathfinding_data_block = cache_file_resources->pathfinding_data_block;

					debug_point;
				}
				cache_file_resources_resource->remove_reference();
			}
		}

		scenario_structure_bsp->resource_interface.tag_resources.clear();
		scenario_structure_bsp->resource_interface.cache_file_resources.clear();

		// #NOTE: Test these asap
		scenario_structure_bsp->acoustics_palette_block.clear();
		scenario_structure_bsp->runtime_decals_block.clear();

		scenario_structure_bsp->resource_interface.use_resource_items = 0;

		return BCS_S_OK;
	}

	BCS_RESULT postprocessing_scenario(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		using namespace blofeld::eldorado::pc32;

		h_scenario_struct_definition* scenario = dynamic_cast<decltype(scenario)>(&target_tag_instance.prototype);
		if (scenario == nullptr)
		{
			return BCS_S_NO_CHANGES_MADE;
		}

		for (auto& structure_bsp : scenario->structure_bsps_block)
		{
			structure_bsp->cubemap_bitmap_group_reference.clear();
		}

		scenario->script_string_data.clear();
		scenario->scripts_block.clear();
		scenario->globals_block.clear();
		scenario->scripting_data_block.clear();
		scenario->hs_unit_seats_block.clear();
		scenario->hs_syntax_datums_block.clear();
		scenario->new_lightmaps.clear();
		scenario->cubemaps_block.clear();
		scenario->airprobes_block.clear();

		return BCS_S_OK;
	}

	BCS_RESULT postprocessing_nuke_shader_references(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		iterate_prototype_references(
			target_tag_instance.prototype,
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
					//blofeld::taggroups::SHADER_WATER_TAG,
					blofeld::taggroups::SHADER_ZONLY_TAG,
				};
				for (tag group_tag : shader_group_tags)
				{
					if (tag_reference_group_tag == group_tag)
					{
						tag_reference.set_unqualified_file_path_without_extension(blofeld::taggroups::SHADER_TAG(engine_platform_build.engine_type), "shaders\\invalid");
					}
					debug_point;
				}
				if (tag_reference_group_tag == blofeld::taggroups::SHADER_WATER_TAG)
				{
					tag_reference.set_unqualified_file_path_without_extension(blofeld::taggroups::SHADER_WATER_TAG, "levels\\multi\\riverworld\\shaders\\riverworld_water_rough");
				}
			});
		return BCS_S_OK;
	}

	BCS_RESULT postprocessing_physics_model(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		using namespace blofeld::eldorado::pc32;

		h_physics_model_struct_definition* physics_model = dynamic_cast<decltype(physics_model)>(&target_tag_instance.prototype);
		if (physics_model == nullptr)
		{
			return BCS_S_NO_CHANGES_MADE;
		}

		iterate_prototype_structures<h_havok_primitive_struct>(
			*physics_model,
			[physics_model](h_havok_primitive_struct& havok_primitive)
			{
				short mass_distribution_index = havok_primitive.mass_distribution_index;
				short num_mass_distributions = mass_distribution_index + 1;

				for (short new_mass_distribution_index = physics_model->mass_distributions_block.size(); new_mass_distribution_index < num_mass_distributions; new_mass_distribution_index++)
				{
					auto& mass_distribution = physics_model->mass_distributions_block.emplace_back();
				}

				//auto& mass_distribution = physics_model.mass_distributions_block[mass_distribution_index];

				for (auto& mass_distribution : physics_model->mass_distributions_block)
				{
					// #TODO: Investigate how to restore the mass distribution block

					if (physics_model->rigid_bodies_block.size() > 0)
					{
						// This is bad
						mass_distribution->center_of_mass = physics_model->rigid_bodies_block[0].center_of_mass;
						mass_distribution->havok_w_center_of_mass = physics_model->rigid_bodies_block[0].havok_w_center_of_mass;
						mass_distribution->inertia_tensor_i = physics_model->rigid_bodies_block[0].intertia_tensor_x;
						mass_distribution->havok_w_inertia_tensor_i = physics_model->rigid_bodies_block[0].havok_w_intertia_tensor_x;
						mass_distribution->inertia_tensor_j = physics_model->rigid_bodies_block[0].intertia_tensor_y;
						mass_distribution->havok_w_inertia_tensor_j = physics_model->rigid_bodies_block[0].havok_w_intertia_tensor_y;
						mass_distribution->inertia_tensor_k = physics_model->rigid_bodies_block[0].intertia_tensor_z;
						mass_distribution->havok_w_inertia_tensor_k = physics_model->rigid_bodies_block[0].havok_w_intertia_tensor_z;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).i /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).j /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_i).k /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).i /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).j /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_j).k /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).i /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).j /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
						static_cast<real_vector3d&>(mass_distribution->inertia_tensor_k).k /= (5.0f / 2.0f) * physics_model->rigid_bodies_block[0].mass;
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

		return BCS_S_OK;
	}

	BCS_RESULT postprocessing_bitmaps(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		using namespace blofeld::eldorado::pc32;

		h_bitmap_block_struct* bitmap = dynamic_cast<decltype(bitmap)>(&target_tag_instance.prototype);
		if (bitmap == nullptr)
		{
			return BCS_S_NO_CHANGES_MADE;
		}

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

		return BCS_S_OK;
	}

	real_point3d cross_product(const real_point3d a, const real_point3d b)
	{
		return
		{
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	real_point3d normalize(const real_point3d v)
	{
		float inv_length = 1.0f / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
		return { v.x * inv_length, v.y * inv_length, v.z * inv_length };
	}

	void compute_tangent_binormal(real_point3d const& normal, real_point3d& tangent, real_point3d& binormal)
	{
		// Choose an arbitrary initial tangent vector that is not parallel to the normal
		if (fabsf(normal.x) > fabs(normal.y))
		{
			// If the x component of the normal is greater than the y component,
			// use the cross product with the x-axis as the initial tangent vector
			tangent.x = -normal.z;
			tangent.y = 0.0f;
			tangent.z = normal.x;
		}
		else
		{
			// Otherwise, use the cross product with the y-axis as the initial tangent vector
			tangent.x = 0.0f;
			tangent.y = normal.z;
			tangent.z = -normal.y;
		}

		// Compute the binormal vector by taking the cross product of the normal and tangent
		binormal = cross_product(normal, tangent);

		// Normalize the tangent and binormal vectors
		tangent = normalize(tangent);
		binormal = normalize(binormal);
	}

	BCS_RESULT postprocessing_decorator_sets(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		using namespace blofeld::eldorado::pc32;

		h_decorator_set_block* decorator_set = dynamic_cast<decltype(decorator_set)>(&target_tag_instance.prototype);
		if (decorator_set == nullptr)
		{
			return BCS_S_NO_CHANGES_MADE;
		}

		h_tag_instance* render_model_tag = decorator_set->render_model.get_tag();
		ASSERT(render_model_tag != nullptr);
		h_render_model_block_struct* render_model = high_level_cast<h_render_model_block_struct*>(&render_model_tag->prototype);
		ASSERT(render_model != nullptr);

		decorator_set->texture.set_unqualified_file_path_without_extension(
			blofeld::taggroups::BITMAP_TAG,
			"levels\\shared\\decorators\\foliage\\grass_wild_long\\bitmaps\\grass_wild_long");

		//decorator_set->render_model.set_unqualified_file_path_without_extension(blofeld::taggroups::RENDER_MODEL_TAG, "levels\\shared\\decorators\\wildgrass\\wildgrass");
		//decorator_set->render_model.set_unqualified_file_path_without_extension(blofeld::taggroups::RENDER_MODEL_TAG, "levels\\shared\\decorators\\rat_dead\\rat_dead");

		while (render_model->instance_placements_block.size() > 1)
		{
			render_model->instance_placements_block.remove(1);
		}

		for (auto& per_mesh_temporary : render_model->render_geometry.per_mesh_temporary_block)
		{
			for (auto& vertex : per_mesh_temporary->raw_vertices_block)
			{
				real_point3d& normal = vertex->normal;
				real_point3d& binormal = vertex->binormal;
				real_point3d& tangent = vertex->tangent;

				compute_tangent_binormal(normal, tangent, binormal);

				debug_point;
			}

			for (unsigned int i = per_mesh_temporary->raw_indices_block.size(); i < per_mesh_temporary->raw_vertices_block.size(); i++)
			{
				auto& index = per_mesh_temporary->raw_indices_block.emplace_back();
				index._word = i;
			}
			for (auto& index : per_mesh_temporary->raw_indices_block)
			{
				int x = index->_word.operator const short& ();
			}
		}

		//decorator_set->render_model_instance_name_valid_count = 0;

		int32_t render_model_instance_name_valid_count = decorator_set->render_model_instance_name_valid_count;
		for (int i = 0; i < render_model_instance_name_valid_count; i++)
		{
			c_fixed_string_128 name;
			name.format("decorator%i", i);

			int decorator_model_index_hack = i % render_model->instance_placements_block.size();
			auto& instance_placement = render_model->instance_placements_block[decorator_model_index_hack];


			auto& render_model_instance_name = decorator_set->render_model_instance_names_block.emplace_back();
			render_model_instance_name.name = instance_placement.name;
			auto& decorator_type = decorator_set->decorator_types_block.emplace_back();
			decorator_type.index = -1;
			decorator_type.mesh = i;

			decorator_type.flags.operator c_flags<blofeld::eldorado::pc32::e_decorator_type_flags_definition, unsigned int, 5>& ().set(_decorator_type_flags_definition_random_rotation, true);

			decorator_type.color_0.operator rgb_color& ().red = 1.0f;
			decorator_type.color_0.operator rgb_color& ().green = 1.0f;
			decorator_type.color_0.operator rgb_color& ().blue = 1.0f;
			decorator_type.color_1.operator rgb_color& ().red = 1.0f;
			decorator_type.color_1.operator rgb_color& ().green = 1.0f;
			decorator_type.color_1.operator rgb_color& ().blue = 1.0f;
			decorator_type.color_2.operator rgb_color& ().red = 1.0f;
			decorator_type.color_2.operator rgb_color& ().green = 1.0f;
			decorator_type.color_2.operator rgb_color& ().blue = 1.0f;

			decorator_type.scale_min = 0.7;
			decorator_type.scale_max = 1.0;
			decorator_type.wind_min = 0.8;
			decorator_type.wind_max = 0.9;
			decorator_type.tilt_min = 0.0;
			decorator_type.tilt_max = 5.0;


		}

		ASSERT(decorator_set->decorator_types_block.size() > 0);

		return BCS_S_OK;
	}

	BCS_RESULT postprocessing_global_render_geometry(s_cache_cluster_transplant_context& context, c_tag_instance& source_tag_instance, h_tag_instance& target_tag_instance)
	{
		using namespace blofeld::eldorado::pc32;

		iterate_prototype_structures<h_global_render_geometry_struct>(
			target_tag_instance.prototype,
			[&target_tag_instance](h_global_render_geometry_struct& render_geometry)
			{
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

				for (h_render_vertex_buffer_block* render_vertex_buffer : render_geometry_api_resource->xenon_vertex_buffers_block)
				{
					h_vertex_buffers_block& vertex_buffer = render_geometry_api_resource->pc_vertex_buffers_block.emplace_back();

					vertex_buffer.declaration_type = render_vertex_buffer->vertex_buffer_interop.declaration;
					vertex_buffer.stride = render_vertex_buffer->vertex_buffer_interop.stride;
					vertex_buffer.count = render_vertex_buffer->vertex_buffer_interop.vertex_count;
					vertex_buffer.d3d_hardware_format = 0;
				}

				for (h_render_index_buffer_block* render_index_buffer : render_geometry_api_resource->xenon_index_buffers_block)
				{
					h_index_buffers_block& index_buffer = render_geometry_api_resource->pc_index_buffers_block.emplace_back();

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

							c_fixed_path output;
							output.format("mopps3/mopps%i.bin", num_box_requests);
							filesystem_write_file_from_memory(output, per_mesh_mopp_block.mopp_code.data(), per_mesh_mopp_block.mopp_code.size());

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

						if (mesh->mesh_flags.operator c_flags<blofeld::eldorado::pc32::e_mesh_flags, unsigned int, 5> &().test(e_mesh_flags::_mesh_flags_mesh_is_unindexed_do_not_modify))
						{
							debug_point;
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

								switch (primitive_type)
								{
								case 3:
								case 5:
								{
									h_indices_word_block& raw_index = per_mesh_raw_data.raw_indices_block.emplace_back();
									raw_index._word = *reinterpret_cast<short*>(index_data_position);
									index_data_position += sizeof(short);
								}
								break;
								default:
								{
									FATAL_ERROR("Unexpected mesh index type");
								}
								break;
								}
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
						break;
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

								float x = float(packed_vertex.coefficients[0]) / float(UINT8_MAX);
								float y = float(packed_vertex.coefficients[1]) / float(UINT8_MAX);
								float z = float(packed_vertex.coefficients[2]) / float(UINT8_MAX);
								float w = float(packed_vertex.coefficients[3]) / float(UINT8_MAX);

								x = x * 2.0f - 1.0f;
								y = y * 2.0f - 1.0f;
								z = z * 2.0f - 1.0f;
								w = w * 2.0f - 1.0f;

								vertex.coeffcients[0] = x;
								vertex.coeffcients[1] = y;
								vertex.coeffcients[2] = z;
								vertex.coeffcients[3] = w;

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
								debug_point;

								//raw_water_vertex.base_texcoord.operator real_point3d& ().x = per_mesh_raw_data.raw_vertices_block[vertex_index].texcoord.operator real_point2d & ().x;
								//raw_water_vertex.base_texcoord.operator real_point3d& ().y = per_mesh_raw_data.raw_vertices_block[vertex_index].texcoord.operator real_point2d & ().y;
								raw_water_vertex.local_info.operator real_point3d& ().x = 3.17756;
								raw_water_vertex.local_info.operator real_point3d& ().y = 0.285931;
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


						short index_buffer_tessellation_index = mesh->index_buffer_tessellation;
						ASSERT(index_buffer_tessellation_index >= 0);

						h_render_index_buffer_block& index_buffer = render_geometry_api_resource->xenon_index_buffers_block[index_buffer_index];
						h_render_index_buffer_descriptor_struct& index_buffer_interop = index_buffer.index_buffer_interop;

						int32_t primitive_type = index_buffer_interop.primitive_type;
						h_data& index_data = index_buffer_interop.index_data;

						int32_t index_count = index_data.size() / sizeof(short);

						char* index_data_position = static_cast<char*>(index_data.data());

						for (auto& part : mesh->parts_block)
						{
							if (part->part_flags.test(_part_flags_is_water_surface))
							{
								int32_t index_start = part->index_start;
								int32_t index_end = index_start + index_count;
								int32_t water_index_start = raw_water_data.raw_water_indices_block.size(); // #TODO: Store this in the block

								for (int32_t index_index = index_start; index_index < index_end; index_index++)
								{
									switch (primitive_type)
									{
									case 3:
									case 5:
									{
										h_indices_word_block& raw_index = raw_water_data.raw_water_indices_block.emplace_back();
										raw_index._word = *reinterpret_cast<short*>(index_data_position);
										index_data_position += sizeof(short);
									}
									break;
									default:
									{
										FATAL_ERROR("Unexpected mesh index type");
									}
									break;
									}
								}
							}
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
					mesh->index_buffer_tessellation = -1;
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

		return BCS_S_OK;
	}
}
