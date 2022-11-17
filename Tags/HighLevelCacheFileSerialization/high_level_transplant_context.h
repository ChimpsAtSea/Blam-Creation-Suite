#pragma once

struct s_cache_cluster_transplant_context;
class c_cache_cluster;
class c_tag_instance;

BCS_SHARED extern BCS_RESULT high_level_transplant_init_transplant_entries_v2(s_cache_cluster_transplant_context* context, unsigned int thread_index, unsigned int thread_count);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_groups_initialize_v2(s_cache_cluster_transplant_context* context, unsigned int thread_index, unsigned int thread_count);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_create_v2(c_cache_cluster& cache_cluster, s_cache_cluster_transplant_context*& context);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_execute_v2(s_cache_cluster_transplant_context* context);
BCS_SHARED extern BCS_RESULT high_level_transplant_context_destroy_v2(s_cache_cluster_transplant_context* context);

BCS_RESULT transplant_prototype(c_tag_instance& tag_instance, char const*& tag_data_position, h_prototype& prototype);
