#include "eldoradocachefiletest-private-pch.h"

#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldoradotagdefinitions-public-pch.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>

#include <geometrylib/geometrylib-public-pch.h>

s_engine_platform_build engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };

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
						const char* eldorado_directory;
						BCS_RESULT get_eldorado_directory_result = command_line_get_argument("eldoradodir", eldorado_directory);
						if (BCS_SUCCEEDED(get_eldorado_directory_result))
						{
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

							if (BCS_FAILED(rs = high_level_transplant_context_execute_v2(*context)))
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

										postprocess_a(output_directory, tag_instance);
									});

								parallel_invoke(
									0u,
									num_tag_instances,
									[&](unsigned int tag_index)
									{
										h_tag_instance& tag_instance = *tag_instances[tag_index];

										postprocess_write(output_directory, tag_instance);
									});
							}

							if (BCS_FAILED(rs = high_level_transplant_context_destroy_v2(*context, true)))
							{
								return rs;
							}
						}
						rs = BCS_FAILED_CHAIN(rs, get_eldorado_directory_result);

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

	BCS_FAIL_RETURN(rs);

	return 0;
}
