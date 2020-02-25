#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <assert.h>
#include <detours.h>
#include <stdint.h>

HINSTANCE load_executable(const char* executable_name)
{
	HANDLE executable_file = CreateFileA(executable_name, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	assert(executable_file != INVALID_HANDLE_VALUE);

	LARGE_INTEGER file_size = {};
	BOOL getFileSizeExResult = GetFileSizeEx(executable_file, &file_size);
	assert(getFileSizeExResult != 0);

	//HANDLE executable_file_mapping = CreateFileMappingA(executable_file, NULL, PAGE_READONLY, file_size.HighPart, file_size.LowPart, NULL);
	//void* file_mapping = MapViewOfFile(executable_file_mapping, FILE_MAP_READ, 0, 0, file_size.QuadPart);
	//BOOL unmapViewOfFileResult = UnmapViewOfFile(file_mapping);
	//assert(unmapViewOfFileResult != 0);
	//BOOL closeHandleResult = CloseHandle(executable_file_mapping);
	//assert(closeHandleResult != 0);

	void* executable_data = VirtualAlloc(NULL, static_cast<SIZE_T>(file_size.QuadPart), MEM_RESERVE | MEM_COMMIT | MEM_TOP_DOWN, PAGE_READWRITE);

	DWORD numberOfBytesRead;
	assert(file_size.QuadPart < ~DWORD());
	BOOL readFileResult = ReadFile(executable_file, executable_data, static_cast<DWORD>(file_size.QuadPart), &numberOfBytesRead, NULL);
	assert(readFileResult != 0);
	assert(file_size.QuadPart == numberOfBytesRead);

	HINSTANCE module_handle = NULL;
	{
		const char* raw_module_address = reinterpret_cast<const char*>(executable_data);
		assert(raw_module_address != nullptr);

		const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(raw_module_address);
		assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

		const IMAGE_NT_HEADERS* raw_nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(raw_module_address + dos_header->e_lfanew);
		assert(raw_nt_headers->Signature == IMAGE_NT_SIGNATURE);

		DWORD address_of_entry_point = raw_nt_headers->OptionalHeader.AddressOfEntryPoint;


		intptr_t section_virtual_address = raw_nt_headers->OptionalHeader.ImageBase;
		LPVOID section_virtual_address_ptr = reinterpret_cast<LPVOID>(section_virtual_address);
		DWORD image_size = 64 * 1024 * 1024; // 64mb  // #TODO: Correct image size
		printf("loading %s @ 0x%X\n", executable_name, raw_nt_headers->OptionalHeader.ImageBase);

		char* image_data = static_cast<char*>(section_virtual_address_ptr);
		//char* image_data = static_cast<char*>(VirtualAlloc(section_virtual_address_ptr, image_size, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE));
		//assert(image_data != nullptr);
		//memset(image_data, 0, image_size);
		module_handle = reinterpret_cast<HINSTANCE>(image_data);
		const IMAGE_SECTION_HEADER* raw_section_header = reinterpret_cast<const IMAGE_SECTION_HEADER*>(raw_nt_headers + 1);
		const char* raw_base_section_data = reinterpret_cast<const char*>(raw_section_header + raw_nt_headers->FileHeader.NumberOfSections);

		DWORD oldProtect;
		BOOL virtualProtectResult = VirtualProtect(image_data, raw_nt_headers->OptionalHeader.SizeOfHeaders, PAGE_READWRITE, &oldProtect);
		assert(virtualProtectResult != 0);
		memcpy(image_data, raw_module_address, raw_nt_headers->OptionalHeader.SizeOfHeaders);
		BOOL virtualProtectResult2 = VirtualProtect(image_data, raw_nt_headers->OptionalHeader.SizeOfHeaders, oldProtect, &oldProtect);
		assert(virtualProtectResult2 != 0);
		printf("Loading headers: @%p\n", image_data);

		for (WORD currentSectionIndex = 0; currentSectionIndex < raw_nt_headers->FileHeader.NumberOfSections; currentSectionIndex++)
		{
			const IMAGE_SECTION_HEADER* current_raw_section_header = raw_section_header + currentSectionIndex;

			char section_name_buffer[sizeof(current_raw_section_header->Name) + 1] = {};
			snprintf(section_name_buffer, sizeof(section_name_buffer), "%s", current_raw_section_header->Name);

			const char* raw_section_data = raw_module_address + current_raw_section_header->PointerToRawData;
			char* virtual_section_data = image_data + current_raw_section_header->VirtualAddress;

			printf("Loading section: VA@%p RVA@0x%X SIZE:0x%X '%s'\n", virtual_section_data, current_raw_section_header->VirtualAddress, current_raw_section_header->SizeOfRawData, section_name_buffer);
			memcpy(virtual_section_data, raw_section_data, current_raw_section_header->SizeOfRawData);

		}

		const void* entry_point = image_data + address_of_entry_point;

		assert(entry_point);
	}

	BOOL closeHandleResult2 = CloseHandle(executable_file);
	assert(closeHandleResult2 != 0);

	printf("finished loading %s\n", executable_name);

	return module_handle;
}

void parse_import_address_table(HINSTANCE module)
{
	assert(module != nullptr);

	HANDLE current_process = GetCurrentProcess();

	DWORD import_descriptor_size = 0;
	IMAGE_IMPORT_DESCRIPTOR* const import_descriptor = static_cast<IMAGE_IMPORT_DESCRIPTOR*>(ImageDirectoryEntryToData(module, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &import_descriptor_size));
	assert(import_descriptor_size >= sizeof(IMAGE_IMPORT_DESCRIPTOR));
	assert(import_descriptor != nullptr);

	const char* module_virtual_address = reinterpret_cast<const char*>(module);

	IMAGE_IMPORT_DESCRIPTOR* current_import_descriptor = import_descriptor;
	for (; current_import_descriptor->Name; current_import_descriptor++)
	{
		const char* module_name = module_virtual_address + current_import_descriptor->Name;
		if (module_name == nullptr)
		{
			break;
		}
		printf("Loading module %s\n", module_name);

		DWORD dwFlags = 0;
		if (strcmp(module_name, "binkw32.dll") == 0)
		{
			dwFlags |= DONT_RESOLVE_DLL_REFERENCES;
		}
		HINSTANCE imported_dll = LoadLibraryExA(module_name, NULL, dwFlags);
		assert(imported_dll);

		const IMAGE_THUNK_DATA* image_thunk_data = reinterpret_cast<const IMAGE_THUNK_DATA*>(module_virtual_address + current_import_descriptor->FirstThunk);
		// Replace current function address with new function address
		for (; image_thunk_data->u1.Function; image_thunk_data++)
		{
			const PROC* function_pointer = reinterpret_cast<const PROC*>(&image_thunk_data->u1.Function);
			assert(function_pointer);

			const LPVOID* rva = reinterpret_cast<const LPVOID*>(image_thunk_data);
			FARPROC exported_function = NULL;

#ifdef _WIN64
			if (image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG64)
			{
				ULONGLONG ordinal = IMAGE_ORDINAL64(image_thunk_data->u1.Ordinal);
				printf("\tordinal:%llu\n", ordinal);
				exported_function = GetProcAddress(imported_dll, MAKEINTRESOURCEA(ordinal));
			}
#else
			if (image_thunk_data->u1.Ordinal & IMAGE_ORDINAL_FLAG32)
			{
				DWORD ordinal = IMAGE_ORDINAL32(image_thunk_data->u1.Ordinal);
				printf("\tordinal:%d\n", ordinal);
				exported_function = GetProcAddress(imported_dll, MAKEINTRESOURCEA(ordinal));
			}
#endif
			else
			{
				const char* import_name = module_virtual_address + (image_thunk_data->u1.Function + 2);
				printf("\t%s\n", import_name);
				exported_function = GetProcAddress(imported_dll, import_name);
			}
			assert(exported_function != nullptr); // ensure that we can find the function pointer
			assert(rva != 0);

			BOOL writeProcessMemoryResult = WriteProcessMemory(current_process, const_cast<LPVOID*>(rva), &exported_function, sizeof(exported_function), NULL);
			if (!writeProcessMemoryResult)
			{
				int lastError = GetLastError();
				assert(lastError == ERROR_NOACCESS);

				// failed to write memory due to memory access rights

				DWORD dwOldProtect;
				BOOL virtualProtectResult = VirtualProtect(const_cast<LPVOID*>(rva), sizeof(exported_function), PAGE_WRITECOPY, &dwOldProtect);
				assert(virtualProtectResult != 0);

				BOOL writeProcessMemoryResult2 = WriteProcessMemory(GetCurrentProcess(), const_cast<LPVOID*>(rva), &exported_function, sizeof(exported_function), NULL);
				assert(writeProcessMemoryResult2 != 0);

				BOOL virtualProtectResult2 = VirtualProtect(const_cast<LPVOID*>(rva), sizeof(exported_function), dwOldProtect, &dwOldProtect);
				assert(virtualProtectResult2 != 0);
			}
		}
	}
}

void hook(void* function, void* hook)
{
	DWORD dwOldProtect;
	BOOL virtualProtectResult = VirtualProtect(function, 16, PAGE_WRITECOPY, &dwOldProtect);
	assert(virtualProtectResult != 0);

	char* function_data = reinterpret_cast<char*>(function);
	function_data[0] = 0xe9i8; // jump

	void** jump_dest = reinterpret_cast<void**>(function_data + 1);
	*jump_dest = hook;

	BOOL virtualProtectResult2 = VirtualProtect(function, 16, dwOldProtect, &dwOldProtect);
	assert(virtualProtectResult2 != 0);
}

HMODULE WINAPI GetModuleHandleAHook(_In_opt_ LPCSTR lpModuleName)
{
	if (lpModuleName == NULL)
	{
#ifdef _WIN64
		return GetModuleHandleW(L"project17.exe");
#else
		return GetModuleHandleW(L"eldorado.exe");
#endif
	}
	else
	{
		wchar_t buffer[MAX_PATH + 1]{};
		_snwprintf(buffer, MAX_PATH, L"%S", lpModuleName);
		return GetModuleHandleW(buffer);
	}
}

inline void computed_goto(void* address)
{
	__asm {
		jmp address;
	}
}

struct __declspec(align(4)) tls_data
{
	char* unknown0[2];
	struct data_array* simulation_gamestate_entities;
	struct main_gamestate_timing* main_gamestate_timing;
	struct main_render_timing* main_render_timing;
	struct main_time_globals* main_time_globals;
	struct preferences* preferences;
	char* unknown1C;
	char* threading;
	char* unknown24[4];
	int deterministic_random_seed;
	int filo_related;
	struct game_globals* game_globals;
	struct players_header* players_header;
	struct players_globals* players_globals;
	struct game_engine_globals* game_engine_globals;
	uint8_t* local_game_engine_globals;
	int game_time;
	int breakable_surface;
	data_array* breakable_surface_set_broken_event;
	struct player_mapping* player_mapping_globals;
	struct director_globals* director_globals;
	struct director_scripting* director_scripting;
	struct hs_thread_deterministic_data* hs_thread_deterministic_data;
	int hs_runtime;
	data_array* hs_global_data;
	data_array* hs_distributed_global_data;
	data_array* hs_thread_tracking_data;
	data_array* hs_thread_non_deterministic_data;
	char* unknown80[8];
	data_array* effect;
	data_array* effect_event;
	struct effect_location_globals* effect_location;
	int effect_counts;
	data_array* effect_geometry_sample;
	int effect_messaging_queue;
	int effect_lightprobes;
	int havok_gamestate;
	int halo_managed_memory;
	struct player_control_globals* player_control_globals;
	struct player_control_deterministic* player_control_deterministic;
	data_array* object_looping_sounds;
	int game_sound_globals;
	int game_sound_scripted_impulses;
	int s_structure_seam;
	int visibility_active_portals;
	struct campaign_metagame_globals* campaign_metagame;
	int observer_gamestate;
	struct observer_globals* observer_globals;
	struct rumble_globals* rumble_globals;
	int bink_gamestate;
	int unknownF4;
	struct c_font_cache_mt_safe* c_font_cache_mt_safe;
	int sound_classes;
	struct game_allegiance_globals* game_allegiance;
	int atmosphere_fog;
	int soft_surface;
	int game_sound_player_effects;
	data_array* havok_proxies;
	char* unknown114;
	LPWSTR* SavedGame;
	char* unknown11C[129];
	int cinematic_new;
	struct cinematic_globals* cinematic;
	int cinematic_light;
	struct physics_constants* physics_constants;
	int recorded_animations;
	struct game_save_globals* game_save;
	data_array* screen_effect;
	struct player_effect_globals* player_effect_globals;
	int scenario_interpolator;
	struct survival_mode_globals* survival_mode_globals;
	struct player_training_globals* player_training_globals;
	int kill_trigger_volume_state;
	int deterministic_game_sound;
	data_array* decal_system;
	int decal_counts;
	data_array* decal;
	int decal_messaging_queue;
	struct impact_globals* impact;
	data_array* impacts;
	data_array* impact_arrays;
	data_array* object_list_header;
	data_array* object_list_data;
	struct camera_script_globals* camera_script_globals;
	int particles;
	data_array* particle_system;
	data_array* contrail_system;
	data_array* contrail;
	data_array* contrail_location;
	data_array* contrail_profile;
	data_array* particle_location_data;
	data_array* light_volume_system;
	data_array* light_volume_location;
	data_array* light_volume;
	data_array* beam_system;
	data_array* beam;
	data_array* beam_location;
	int unknown3B0_render_postprocess_color_tweaking;
	int ragdolls;
	data_array* particle_emitter;
	struct rasterizer_game_states* rasterizer_game_states;
	struct hue_saturation_control* hue_saturation_control;
	int unknown3C4;
	struct scripted_exposure_globals* scripted_exposure_globals;
	struct render_hud_globals* render_hud_globals;
	struct water_interaction_ripples* water_interaction_ripples;
	struct render_texture_globals* render_texture_camera_globals;
	int render_game_globals;
	int depth_of_field_game_globals;
	struct cached_object_render_states_globals* cached_object_render_states;
	data_array* particle_emitter_gpu_row;
	data_array* particle_emitter_gpu_1;
	int particle_emitter_gpu_2;
	data_array* beam_gpu;
	data_array* beam_gpu_row;
	int particle_emitter_gpu_3;
	data_array* contrail_gpu_row;
	data_array* contrail_gpu;
	int particle_emitter_gpu_4;
	data_array* light_volume_gpu;
	data_array* light_volume_gpu_row;
	int particle_emitter_gpu_5;
	int rasterizer_implicit_geometry_data;
	int render_object;
	int shield_render_cache_message;
	struct chud_persistent_user_data* chud_persistent_user_data;
	struct chud_persistent_global_data* chud_persistent_global_data;
	data_array* user_widget[4];
	struct first_person_orientation_globals* first_person_orientation_globals;
	struct first_person_weapons* first_person_weapons;
	int cortana_globals;
	int campaign_objectives;
	struct object_header* object_header;
	struct object_globals* object_globals;
	int objects_memory_pool;
	struct object_name_list* object_name_list;
	int object_messaging_queue;
	data_array* collideable_object;
	int damage_globals;
	int unknown464;
	data_array* noncollideable_object;
	int noncollideable_cluster_reference;
	char* unknown470;
	int object_render_data;
	int damage;
	int object_placement;
	struct device_groups_globals* device_groups;
	int object_scripting;
	struct s_object_broadphase* object_broadphase;
	struct object_early_movers* object_early_movers;
	int object_schedule;
	int object_activation_regions;
	data_array* lights;
	int* lights_game_globals;
	data_array* light_data_reference;
	int light_cluster_reference;
	int light_first_data;
	int nondeterministic_render_light_data;
	data_array* widget;
	int recycling_volumes;
	data_array* recycling_group;
	data_array* muffin;
	data_array* leaf_system;
	data_array* antenna;
	struct cloth_globals* cloth;
	char* unknown4CC[17];
	char* unknown528;
	char* unknown52C[2];
	struct actor_globals* actor;
	int actor_firing_position;
	int ai_reference_frame;
	struct ai_globals* ai;
	struct ai_player_state_globals* ai_player_state_globals;
	data_array* vocalization_records;
	struct vocalization_timers* vocalization_timers;
	struct command_script_globals* command_scripts;
	data_array* objectives;
	struct s_task_record_datum* task_records;
	struct squads_globals* squads;
	struct squad_group_globals* squad_group;
	struct swarm_globals* swarm;
	int swarm_spawner;
	int spawner;
	int dynamic_firing_points;
	struct propref_globals* propref;
	struct prop_globals* prop;
	struct tracking_globals* tracking;
	struct joint_state_globals* joint_state;
	struct clump_globals* clump;
	struct squad_patrol_globals* squad_patrol;
	struct flocks_globals* flocks;
	struct formations_globals* formations;
	int vision_mode;
};


typedef DWORD* (__cdecl sub_E23D10_func)(int a1);
sub_E23D10_func* sub_E23D10 = nullptr;
DWORD* __cdecl sub_E23D10_hook(int a1)
{
	static int& g_tls_index = *(int*)(0x0528A2B8);
	tls_data* v2 = *(tls_data**)(__readfsdword(0x2Cu) + 4 * g_tls_index);

	return sub_E23D10(a1);
}

__declspec(dllexport) int main(int argc, const char* argv[])
{
	DWORD custom_tls_index = TlsAlloc();

	HMODULE x = GetModuleHandleA(NULL);

	void* test = (void*)(0x00400000);

	HINSTANCE current_module = GetModuleHandle(NULL);
	DWORD opus_import_descriptor_size;
	IMAGE_TLS_DIRECTORY* const opus_tls_data_directory = static_cast<IMAGE_TLS_DIRECTORY*>(ImageDirectoryEntryToData(current_module, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &opus_import_descriptor_size));

#ifdef _WIN64
	//HINSTANCE custom_module = LoadLibraryA("project17.exe");
	HINSTANCE custom_module = load_executable("project17.exe");
#else
	//HINSTANCE custom_module = load_executable("eldorado.exe");
	HINSTANCE custom_module = load_executable("eldorado.exe");

#endif


	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	*((PVOID*)&sub_E23D10) = (PVOID)0xE23D10;
	LONG detourAttachResult = DetourAttach((PVOID*)&sub_E23D10, sub_E23D10_hook);
	DetourTransactionCommit();

	typedef void (start_func)();
	start_func* start = nullptr;
	char* module_virtual_address = reinterpret_cast<char*>(custom_module);
	assert(module_virtual_address != nullptr);

	const IMAGE_DOS_HEADER* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(module_virtual_address);
	assert(dos_header->e_magic == IMAGE_DOS_SIGNATURE);

	const IMAGE_NT_HEADERS* nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(module_virtual_address + dos_header->e_lfanew);
	assert(nt_headers->Signature == IMAGE_NT_SIGNATURE);

	DWORD address_of_entry_point = nt_headers->OptionalHeader.AddressOfEntryPoint;

	void* entry_point = module_virtual_address + address_of_entry_point;

	start = reinterpret_cast<start_func*>(entry_point);
	assert(start);



	// tls fixup

	{
		assert(opus_import_descriptor_size > 0);
		assert(opus_tls_data_directory != nullptr);

		DWORD custom_import_descriptor_size;
		IMAGE_TLS_DIRECTORY* const custom_tls_data_directory = static_cast<IMAGE_TLS_DIRECTORY*>(ImageDirectoryEntryToData(custom_module, TRUE, IMAGE_DIRECTORY_ENTRY_TLS, &custom_import_descriptor_size));
		

		assert(custom_import_descriptor_size > 0);
		assert(custom_tls_data_directory != nullptr);

		DWORD* g_tls_index_opus			= (DWORD*)(opus_tls_data_directory->AddressOfIndex);
		DWORD* g_tls_index_eldorado		= (DWORD*)(custom_tls_data_directory->AddressOfIndex);

		//*g_tls_index_eldorado = custom_tls_index;

		auto& v2 = *(tls_data**)(__readfsdword(0x2Cu) + 4 * *g_tls_index_opus);

		size_t tls_raw_data_size = custom_tls_data_directory->EndAddressOfRawData - custom_tls_data_directory->StartAddressOfRawData;
		memcpy(v2, (void*)custom_tls_data_directory->StartAddressOfRawData, tls_raw_data_size);

		static void** custom_tls_callbacks = (void**)(custom_tls_data_directory->AddressOfCallBacks);
		for (; *custom_tls_callbacks; custom_tls_callbacks++)
		{
			throw; // not implemented
		}
	}


	parse_import_address_table(custom_module);

	//void* dx_value;
	//void* ds_value;
	//void* cs_value;
	//void* bx_value;
	//__asm {
	//	mov EDX, 0x400000
	//	mov dx_value, EDX
	//	mov ds_value, DS
	//	mov cs_value, CS
	//	mov bx_value, EBX
	//}
	//computed_goto(start);
	//DWORD threadID;
	//HANDLE thread = CreateThread(NULL, nt_headers->OptionalHeader.SizeOfStackCommit, (LPTHREAD_START_ROUTINE)start, NULL, 0, &threadID);
	//WaitForSingleObject(thread, INFINITE);
	start();
	return 0;
}

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}



