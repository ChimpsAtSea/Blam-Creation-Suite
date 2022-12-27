#define PLATFORM_ENABLE_DEFAULT_NEW
#define PLATFORM_EXCLUDE_BANNED
#include <platform/platform-public-pch.h>

#ifdef BCS_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

extern "C" int bcs_main();

int bcs_entry(
	void* instance,
	const wchar_t* command_line,
	int show_cmd)
{
	BCS_FAIL_RETURN(register_process_module_by_pointer(instance));
	BCS_RESULT platform_result = init_platform();
	BCS_RESULT command_line_result = init_command_line(command_line);
	
	int return_value = bcs_main();
	
	if (BCS_SUCCEEDED(command_line_result)) command_line_result = deinit_command_line();
	if (BCS_SUCCEEDED(platform_result)) platform_result = deinit_platform();
	
	BCS_FAIL_RETURN(command_line_result);
	BCS_FAIL_RETURN(platform_result);
	
	return return_value;
}

#ifdef BCS_WIN32_DESKTOP_APPLICATION

int WINAPI wWinMain(
	HINSTANCE instance,
	HINSTANCE previous_instance,
	LPWSTR command_line,
    int show_cmd)
{
    return bcs_entry(instance, command_line, show_cmd);
}

#elif defined(BCS_WIN32)

extern "C" IMAGE_DOS_HEADER __ImageBase;

int wmain()
{
    STARTUPINFOW startup_info;
    GetStartupInfo(&startup_info);
    LPWSTR command_line = GetCommandLineW();
    return bcs_entry(&__ImageBase, command_line, startup_info.wShowWindow);
}

#else

int main(int argc, char* argv[])
{	
	wchar_t* command_line = nullptr;
    int return_value = bcs_entry(nullptr, command_line, 0);
	return return_value;
}

#endif
