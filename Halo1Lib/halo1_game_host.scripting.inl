#include "halo1lib-private-pch.h"

// TODO: all of the following things

//#pragma pack(push, 4)
//struct hs_script_op_halo1
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
//uintptr_t hs_function_table_halo1_offset(e_engine_type engine_type, e_build build)
//{
//	if (engine_type == _engine_type_halo1)
//	{
//		switch (build)
//		{
//		//case _build_mcc_1_1350_0_0: return 0x0;
//		//case _build_mcc_1_1367_0_0: return 0x0;
//		//case _build_mcc_1_1377_0_0: return 0x0;
//		//case _build_mcc_1_1384_0_0: return 0x0;
//		//case _build_mcc_1_1387_0_0: return 0x0;
//		case _build_mcc_1_1389_0_0: return 0x180E9C8B0;
//		}
//	}
//	return ~uintptr_t();
//}
//hs_script_op_halo1 *(&hs_function_table_halo1)[] = reference_symbol<hs_script_op_halo1 *[]>("hs_function_table_halo1", hs_function_table_halo1_offset);
//
//uintptr_t hs_evaluate_arguments_halo1_offset(e_engine_type engine_type, e_build build)
//{
//	if (engine_type == _engine_type_halo1)
//	{
//		switch (build)
//		{
//		//case _build_mcc_1_1350_0_0: return;
//		//case _build_mcc_1_1367_0_0: return;
//		//case _build_mcc_1_1377_0_0: return;
//		//case _build_mcc_1_1384_0_0: return;
//		//case _build_mcc_1_1387_0_0: return;
//		case _build_mcc_1_1389_0_0: return 0x18070BAA0;
//		}
//	}
//	return ~uintptr_t();
//}
//
//template<typename t_parameter>
//FunctionHookEx<hs_evaluate_arguments_halo1_offset, t_parameter __fastcall (unsigned short expression_index, short parameters_count, short *parameters, char execute)> hs_evaluate_arguments_halo1;
//
//uintptr_t hs_return_halo1_offset(e_engine_type engine_type, e_build build)
//{
//	if (engine_type == _engine_type_halo1)
//	{
//		switch (build)
//		{
//		//case _build_mcc_1_1350_0_0: return;
//		//case _build_mcc_1_1367_0_0: return;
//		//case _build_mcc_1_1377_0_0: return;
//		//case _build_mcc_1_1384_0_0: return;
//		//case _build_mcc_1_1387_0_0: return;
//		case _build_mcc_1_1389_0_0: return 0x18070B690;
//		}
//	}
//	return ~uintptr_t();
//}
//FunctionHookEx<hs_return_halo1_offset, __int64 __fastcall (unsigned short expression_index, unsigned int handle)> hs_return_halo1;
//
//hs_script_op_halo1 *hs_function_get_halo1(short opcode)
//{
//	REFERENCE_ASSERT(hs_function_table_halo1);
//	return hs_function_table_halo1[opcode];
//}
//
//template<typename t_parameter>
//t_parameter &hs_macro_function_evaluate_halo1(short opcode, unsigned short expression_index, char execute)
//{
//	hs_script_op_halo1 *hs_function = hs_function_get_halo1(opcode);
//	return *hs_evaluate_arguments_halo1<t_parameter *>(expression_index, hs_function->parameter_count, &hs_function->parameter_types, execute);
//}