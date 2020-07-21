#include "halo1lib-private-pch.h"

// TODO: all of the following things

//#pragma pack(push, 4)
//struct halo1_hs_script_op
//{
//	short return_type;
//	short flags;
//	long __unused4;
//	const char *name;
//	void(__fastcall *print_help_maybe)(short opcode_maybe, unsigned short expression_index);
//	void(__fastcall *evaluate)(short opcode, unsigned short expression_index, char execute);
//	const char *description;
//	const char *parameter_info;
//	short parameter_count;
//	short parameter_types[2];
//
//	void replace_evaluate(LPVOID new_evaluate)
//	{
//		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
//		memcpy_virtual(&evaluate, &new_evaluate, sizeof(void *));
//		//printf("0x%08llX\n", *(UINT64 *)&evaluate);
//	}
//	void print_parameter_info()
//	{
//		printf("%s\n", parameter_info);
//	}
//};
//#pragma pack(pop)
//
//uintptr_t halo1_hs_function_table_offset(e_engine_type engine_type, e_build build)
//{
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1367_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x0);
//	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180E9C8B0);
//	return ~uintptr_t();
//}
//halo1_hs_script_op *(&halo1_hs_function_table)[] = reference_symbol<halo1_hs_script_op *[]>("halo1_hs_function_table", halo1_hs_function_table_offset);
//
//uintptr_t halo1_hs_evaluate_arguments_offset(e_engine_type engine_type, e_build build)
//{
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1367_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x0);
//	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18070BAA0);
//	return ~uintptr_t();
//}
//
//template<typename t_parameter>
//FunctionHookEx<halo1_hs_evaluate_arguments_offset, t_parameter __fastcall (unsigned short expression_index, short parameters_count, short *parameters, char execute)> halo1_hs_evaluate_arguments;
//
//uintptr_t halo1_hs_return_offset(e_engine_type engine_type, e_build build)
//{
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1350_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1367_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1377_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1384_0_0, 0x0);
//	//OFFSET(_engine_type_halo1, _build_mcc_1_1387_0_0, 0x0);
//	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x18070B690);
//	return ~uintptr_t();
//}
//FunctionHookEx<halo1_hs_return_offset, __int64 __fastcall (unsigned short expression_index, unsigned int handle)> halo1_hs_return;
//
//halo1_hs_script_op *halo1_hs_function_get(short opcode)
//{
//	REFERENCE_ASSERT(halo1_hs_function_table);
//	return halo1_hs_function_table[opcode];
//}
//
//template<typename t_parameter>
//t_parameter &halo1_hs_macro_function_evaluate(short opcode, unsigned short expression_index, char execute)
//{
//	halo1_hs_script_op *hs_function = halo1_hs_function_get(opcode);
//	return *halo1_hs_evaluate_arguments<t_parameter *>(expression_index, hs_function->parameter_count, &halo1_hs_function->parameter_types, execute);
//}