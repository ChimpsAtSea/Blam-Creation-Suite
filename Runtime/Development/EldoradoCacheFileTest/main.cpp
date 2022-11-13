#include "eldoradocachefiletest-private-pch.h"

#include <Generated/high_level_eldorado_pc32/highlevel-eldorado-pc32-public-pch.h>

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
				try
				{
					s_engine_platform_build engine_platform_build = { _engine_type_eldorado, _platform_type_pc_32bit, _build_eldorado_1_106708_cert_ms23 };

					c_cache_file_reader* cache_file_reader;
					BCS_RESULT open_cache_file_reader_result = ::open_cache_file_reader("C:\\!Eldorado\\", engine_platform_build, true, true, &cache_file_reader);
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

					if (BCS_FAILED(rs = high_level_transplant_context_destroy_v2(context)))
					{
						return rs;
					}

					///auto cache_cluster_transplant = new() c_high_level_cache_cluster_transplant(*cache_cluster);



				}
				catch (BCS_RESULT _rs)
				{
					BCS_FAILED_CHAIN(rs, _rs);
				}
				catch (...)
				{
					BCS_FAILED_CHAIN(rs, BCS_E_FATAL);
				}

				tag_definitions_register_result = blofeld::tag_definitions_unregister();
				BCS_FAILED_CHAIN(rs, tag_definitions_register_result);
			}
			tag_definition_registry_init_result = blofeld::tag_definition_registry_deinit();
			BCS_FAILED_CHAIN(rs, tag_definition_registry_init_result);
		}
		BCS_FAILED_CHAIN(rs, console_result);
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
