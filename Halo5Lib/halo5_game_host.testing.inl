
uintptr_t unk_143285930_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo5, _build_halo5_forge_1_194_6192_2, 0x143285930);
	return ~uintptr_t();
}
_PVFV& unk_143285930 = reference_symbol<_PVFV>("unk_143285930", unk_143285930_offset);

uintptr_t unk_143307FF8_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo5, _build_halo5_forge_1_194_6192_2, 0x143307FF8);
	return ~uintptr_t();
}
_PVFV& unk_143307FF8 = reference_symbol<_PVFV>("unk_143307FF8", unk_143307FF8_offset);


#include <signal.h>

bool caused_error = false;

void SignalHandler(int signal)
{
	printf("Signal %d", signal);
	caused_error = true;
	throw "!Access Violation!";
}

uintptr_t __scrt_common_main_seh_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo5, _build_halo5_forge_1_194_6192_2, 0x1410EB6A8);
	return ~uintptr_t();
}
FunctionHookEx<__scrt_common_main_seh_offset, __int64()> __scrt_common_main_seh = 
{ 
	"__scrt_common_main_seh", 
	[]() 
	{
		_PVFV func_address = (_PVFV)GetEngineVirtualAddress(_engine_type_halo5, 0x14001D8E0);

		char* data_address = GetEngineVirtualAddress(_engine_type_halo5, 0x14473EB88);




		//std::vector<size_t> blacklist_indices =
		//{
		//	0, 19, 51
		//};

		//std::string str = c_command_line::get_command_line_arg("-h5test");

		//std::stringstream ss(str);

		//for (size_t i; ss >> i;) {
		//	blacklist_indices.push_back(i);
		//	if (ss.peek() == ',')
		//		ss.ignore();
		//}

		std::vector<_PVFV> funcs = {&unk_143285930, &unk_143307FF8};

		size_t i = std::stoull(c_command_line::get_command_line_arg("-h5test"));

		
		//for (size_t i = blacklist_indices.end()[-1]; i < funcs.size(); i++)
		{
			//bool is_blacklisted = false;
			//for (size_t blacklist_index : blacklist_indices)
			//{
			//	if (i == blacklist_index)
			//	{
			//		is_blacklisted |= true;
			//		break;
			//	}
			//}

			//if (!is_blacklisted)
			{
				_PVFV func = funcs[i];
				if (func != nullptr)
				{
					//printf("trying:\t%i\n", (int)i);
					//caused_error = false;
					//typedef void (*SignalHandlerPointer)(int);

					//SignalHandlerPointer previousHandler;
					//previousHandler = signal(SIGSEGV, SignalHandler);
					try {
						func();
					}
					catch (...)
					{
						caused_error = true;
					}

					if (caused_error)
					{
						write_line("error:\t%i", (int)i);
					}
				}
			}
		}
		//printf("fin\n");

		//_initterm(&unk_143285930, &unk_143307FF8);

		return __int64(caused_error ? 1 : 0);
		//return __scrt_common_main_seh();
	} 
};
c_data_patch<__scrt_common_main_seh_offset> __scrt_common_main_seh_patch = 
{ 
	[](e_engine_type engine_type, e_build build, char*, DataPatchPackets& packets)
	{
		char* patch_address = GetEngineVirtualAddress(engine_type, 0x1410EB73B);

		static const uint8_t patch[] = { 0xC3 };
		packets.push_back(MAKE_DATAPATCHPACKET(patch_address, sizeof(patch)));
		memcpy_virtual(patch_address, patch, sizeof(patch));
	}
};


