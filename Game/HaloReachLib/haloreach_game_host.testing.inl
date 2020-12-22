

uintptr_t sub_180030594_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x180030594);

	return ~uintptr_t();
}
c_function_hook_ex<sub_180030594_offset, char __fastcall (__int64 a1, __int64 a2)> sub_180030594 = { "sub_180030594", [](__int64 a1, __int64 a2)
{
	auto result = sub_180030594(a1, a2);
	return result;
} };

uintptr_t sub_18001384C_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18001384C);

	return ~uintptr_t();
}
c_function_hook_ex<sub_18001384C_offset, int __fastcall (char* Buffer, size_t BufferCount, char* Format, va_list ArgList)> sub_18001384C = { "sub_18001384C", [](char* Buffer, size_t BufferCount, char* Format, va_list ArgList)
{
	auto result = sub_18001384C(Buffer, BufferCount, Format, ArgList);
	if (sub_180030594.reference_counter > 0)
	{
		c_console::write_line(__FUNCTION__ " Buffer:'%s'", Buffer);
	}
	return result;
} };

//uintptr_t sub_1800333D0_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800333D0);
//
//	return ~uintptr_t();
//}
//c_function_hook_ex<sub_1800333D0_offset, void __fastcall (const char* unknown, const char* reason)> sub_1800333D0 = { "sub_1800333D0", [](const char* unknown, const char* reason)
//{
//	c_console::write_line(__FUNCTION__ " unknown:'%s' reason:'%s'", unknown, reason);
//	sub_1800333D0(unknown, reason);
//} };

#define simple_void_logger(offset) \
uintptr_t CONCAT(sub_##offset, _offset)(e_engine_type engine_type, e_build build)								\
{																										\
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x##offset);									\
	return ~uintptr_t();																				\
}																										\
c_function_hook_ex<sub_##offset##_offset, void __fastcall ()> sub_##offset = { "sub_" #offset, []()		\
{																										\
	c_console::write_line("sub_" #offset);																\
	sub_##offset();																						\
} };

simple_void_logger(180010F2C);
simple_void_logger(180010E38);
simple_void_logger(180010D70);
simple_void_logger(180010B7C);
simple_void_logger(180010974);
simple_void_logger(18001076C);
simple_void_logger(180010584);
simple_void_logger(180010294);
simple_void_logger(1800101B8);

uintptr_t sub_1803FDA48_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1803FDA48);

	return ~uintptr_t();
}
c_function_hook_ex<sub_1803FDA48_offset, __int64 __fastcall (__int64 a1)> sub_1803FDA48 = { "sub_1803FDA48", [](__int64 a1)
{
	auto result = sub_1803FDA48(a1);
	return result;
} };

// #TODO investigate this validation function!!!

uintptr_t sub_18004F224_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18004F224);

	return ~uintptr_t();
}
c_function_hook_ex<sub_18004F224_offset, char __fastcall (__int64 a1, _DWORD* a2)> sub_18004F224 = { "sub_18004F224", [](__int64 a1, _DWORD* a2)
{
	auto result = sub_18004F224(a1, a2);
	c_console::write_line("sub_18004F224 (second validation function) returned %i", static_cast<int>(result));
	result = 1;
	return result;
} };

uintptr_t c_datamine_ctor_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800C2FE8);

	return ~uintptr_t();
}
FunctionHookVarArgsEx<c_datamine_ctor_offset, __int64 __fastcall (__int64 _this, __int64 a2, const char* name, __int64 arg_count, ...)> c_datamine_ctor = { "c_datamine_ctor", [](__int64 _this, __int64 a2, const char* name, __int64 arg_count, ...)
{
	auto result = c_datamine_ctor(_this, a2, name, 0);
	printf("c_datamine> %lli '%s' %lli", a2, name, arg_count);
	{
		va_list arguments;
		va_start(arguments, arg_count);
		for (__int64 i = 0; i < arg_count; i++)
		{
			printf(" '%s'", va_arg(arguments, const char*));
		}
		va_end(arguments);
	}
	printf("\n");
	result = 1;

	return result;
} };

//
//uintptr_t sub_1800333D0_offset(e_engine_type engine_type, e_build build)
//{
//	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1800333D0);
//
//	return ~uintptr_t();
//}
//FunctionHookVarArgsEx<sub_1800333D0_offset, __int64 __fastcall (__int64 _this, __int64 a2, const char* name, __int64 arg_count, ...)> sub_1800333D0 = { "sub_1800333D0", [](__int64 _this, __int64 a2, const char* name, __int64 arg_count, ...)
//{
//	auto result = sub_1800333D0(_this, a2, name, 0);
//	printf("c_datamine> %lli '%s' %lli", a2, name, arg_count);
//	{
//		va_list arguments;
//		va_start(arguments, arg_count);
//		for (__int64 i = 0; i < arg_count; i++)
//		{
//			printf(" '%s'", va_arg(arguments, const char*));
//		}
//		va_end(arguments);
//	}
//	printf("\n");
//	result = 1;
//
//	return result;
//} };
//
//sub_1800333D0(v17, "failed to open '%s', GetLastError()==%d", FileName, v12);

uintptr_t DamagedMediaHaltAndDisplayError_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1802A6068);

	return ~uintptr_t();
}
FunctionHookVarArgsEx<DamagedMediaHaltAndDisplayError_offset, void __fastcall (const char* str, ...)> DamagedMediaHaltAndDisplayError = { "DamagedMediaHaltAndDisplayError", [](const char* string, ...)
{
	va_list arguments;
	va_start(arguments, string);
	c_fixed_string_2048 buffer;
	buffer.vformat(string, arguments);
	va_end(arguments);
	c_console::write_line("DamagedMediaHaltAndDisplayError> %s", buffer.c_str());
} };


void* (&page_offset_table)[] = reference_symbol<void* []>("page_offset_table", _engine_type_haloreach, _build_mcc_1_1955_0_0, 0x1836726C0);

uintptr_t sub_18004CD88_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_haloreach, _build_mcc_1_1955_0_0, 0x18004CD88);

	return ~uintptr_t();
}
c_function_hook_ex<sub_18004CD88_offset, void* __fastcall (__int64 a1, __int64 a2, __int64 alignment, char a4)> sub_18004CD88 = { "sub_18004CD88", [](__int64 a1, __int64 a2, __int64 alignment, char a4)
{
	void* result = sub_18004CD88(a1, a2, alignment, a4);
	void* page_offset = page_offset_table[5];
	intptr_t offset = (char*)result - (char*)page_offset;
	//c_console::write_line("sub_18004CD88 allocator> 0x%llx 0x%llx 0x%llx 0x%x", a1, a2, alignment, static_cast<int>(a4));
	c_console::write_line("sub_18004CD88 allocator> 0x%llX (offset: 0x%llX) : 0x%llX 0x%X", result, offset, alignment, static_cast<int>(a4));
	return result;
} };
