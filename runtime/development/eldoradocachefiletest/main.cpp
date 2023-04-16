#include "eldoradocachefiletest-private-pch.h"

#include <tagdefinitions/eldorado_pc32_eldorado_1_106708_cert_ms23/eldoradotagdefinitions-public-pch.h>
#include <tagcodegen/eldorado_pc32_eldorado_1_106708_cert_ms23/eldorado-pc32-public-pch.h>

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
						try
						{
							s_engine_platform_build engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };

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

								for (unsigned int tag_index = 0; tag_index < num_tag_instances; tag_index++)
								{
									h_tag_instance& tag_instance = *tag_instances[tag_index];

									const char* extension = tag_instance.get_file_extension();
									if (strcmp(".bitmap", extension) != 0)
									{
										continue;
									}

									using namespace blofeld::eldorado::pc32;

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
													const void* bitmap_resource_data;
													unsigned int bitmap_resource_bytes;
													if (BCS_SUCCEEDED(resource->add_reference(bitmap_resource_data, bitmap_resource_bytes)))
													{
														bitmap->processed_pixel_data.append_elements(static_cast<const char*>(bitmap_resource_data), bitmap_resource_bytes);

														resource->remove_reference();
													}
												}
											}

											bitmap_data->interleaved_interop = -1;
										}
										bitmap->hardware_textures_block.clear();


									}






									const char* tag_file_path = tag_instance.get_file_path();

									c_fixed_string_2048 output_file_path;
									output_file_path.format("%s/%s", output_directory, tag_file_path);

									c_high_level_tag_file_writer tag_file_writer(engine_platform_build, output_file_path, tag_instance);

									debug_point;

									//break;
								}





								debug_point;
							}

							if (BCS_FAILED(rs = high_level_transplant_context_destroy_v2(context, true)))
							{
								return rs;
							}

							///auto cache_cluster_transplant = new() c_high_level_cache_cluster_transplant(*cache_cluster);



						}
						catch (BCS_RESULT _rs)
						{
							rs = BCS_FAILED_CHAIN(rs, _rs);
						}
						catch (...)
						{
							rs = BCS_FAILED_CHAIN(rs, BCS_E_FATAL);
						}

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
