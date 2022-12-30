#pragma once

struct s_cache_cluster_transplant_context;
class c_cache_cluster;
class c_tag_instance;
class c_cache_file_reader;

BCS_SHARED extern BCS_RESULT high_level_transplant_init_transplant_entries_v2(s_cache_cluster_transplant_context* context, unsigned int thread_index, unsigned int thread_count);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_groups_initialize_v2(s_cache_cluster_transplant_context* context, unsigned int thread_index, unsigned int thread_count);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_create_v2(c_cache_cluster& cache_cluster, s_cache_cluster_transplant_context*& context);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_execute_v2(s_cache_cluster_transplant_context* context);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_destroy_v2(s_cache_cluster_transplant_context* context, bool destroy_children);

BCS_SHARED extern BCS_RESULT high_level_transplant_context_get_transplantable_cache_file_readers(
	s_cache_cluster_transplant_context& context,
	c_cache_file_reader**& cache_file_readers,
	unsigned int& num_cache_file_readers);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_get_high_level_tag_groups(
	s_cache_cluster_transplant_context& context,
	h_tag_group**& tag_groups,
	unsigned int& num_tag_groups);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_get_high_level_tag_instances(
	s_cache_cluster_transplant_context& context,
	h_tag_instance**& tag_instances,
	unsigned int& num_tag_instances);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_get_global_tag_by_low_level_tag_instance(
	s_cache_cluster_transplant_context& context,
	c_tag_instance& low_level_tag_instance,
	h_tag_instance*& out_high_level_tag_instance);

BCS_RESULT transplant_prototype(c_tag_instance& tag_instance, char const*& tag_data_position, h_prototype& prototype);