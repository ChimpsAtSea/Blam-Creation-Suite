#pragma once

struct nicename("Performance Throttles") group('perf') s_performance_throttles_definition
{
	struct nicename("Performance") s_performance_block_definition;

	int32_t __unknown; 
	s_tag_block_definition<s_performance_block_definition> nicename("Performance") performance_block; 

	struct nicename("performance") s_performance_block_definition
	{
		int32_t nicename("Flags") flags; 
		float nicename("Water") water; 
		float nicename("Decorators") decorators; 
		float nicename("Effects") effects; 
		float nicename("Instanced Geometry") instanced_geometry; 
		float nicename("Object Fade") object_fade; 
		float nicename("Object LOD") object_lod; 
		float nicename("Object Draw Distance") object_draw_distance; 
		float nicename("Decals") decals; 
		float nicename("Instanced Geometry LOD") instanced_geometry_lod; 
		int32_t nicename("CPU Light Count") cpu_light_count; 
		float nicename("CPU Light Quality") cpu_light_quality; 
		int32_t nicename("GPU Light Count") gpu_light_count; 
		float nicename("GPU Light Quality") gpu_light_quality; 
		int32_t __unknown_count; 
		float __unknown_quality; 
		int32_t nicename("Shadow Count") shadow_count; 
		float nicename("Shadow Quality") shadow_quality; 
		float nicename("Floating Shadow Quality") floating_shadow_quality; 
	};
};
