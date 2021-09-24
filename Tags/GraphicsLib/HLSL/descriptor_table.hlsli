#pragma once

#ifdef __cplusplus
#define _register_space(index) (index)
#else
#define _register_space(index) space#index
#endif

#define k_engine_perdraw_cbv				0
#define k_engine_perview_cbv				1
#define k_engine_perframe_cbv				2
#define k_engine_perdraw_srv_vs_only		3
#define k_engine_perdraw_srv_ps_only		4
#define k_engine_perdraw_srv_all			5
#define k_engine_perview_srv_vs_only		6
#define k_engine_perview_srv_ps_only		7
#define k_engine_perview_srv_all			8
#define k_engine_perframe_srv_vs_only		9
#define k_engine_perframe_srv_ps_only		10
#define k_engine_perframe_srv_all			11
#define k_shader_perdraw_cbv				12
#define k_shader_perdraw_srv_vs_only		13
#define k_shader_perdraw_srv_ps_only		14
#define k_shader_perdraw_srv_all			15
#define k_shader_perdraw_uav				18
#define k_num_shader_descriptor_table_count 19
