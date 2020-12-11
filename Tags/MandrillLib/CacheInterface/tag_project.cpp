#include "mandrilllib-private-pch.h"

c_tag_project::c_tag_project(c_cache_cluster& cache_cluster, c_cache_file& cache_file) :
	engine_type(cache_file.get_engine_type()),
	platform_type(cache_file.get_platform_type()),
	build(_build_not_set),
	groups(),
	tags()
{
	c_stopwatch stopwatch;
	stopwatch.start();
	{
		c_high_level_cache_file_transplant cache_file_transplant(cache_cluster, cache_file);

		for (c_high_level_cache_file_transplant::s_group_pair& group_pair : cache_file_transplant.groups_and_interface)
		{
			groups.push_back(&group_pair.high_level_group);
		}

		for (c_high_level_cache_file_transplant::s_tag_pair& tag_pair : cache_file_transplant.tags_and_interface)
		{
			tags.push_back(&tag_pair.high_level_tag);
		}
	}
	stopwatch.stop();
	c_console::write_line_verbose("Finished creating tag project in %.2fms", stopwatch.get_miliseconds());
}

c_tag_project::~c_tag_project()
{
	for (h_tag* tag : tags)
	{
		delete tag;
	}
}
