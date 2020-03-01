#include <Shared\shared-public-pch.h>
#include <FSBLib\fsblib-public-pch.h>

static bool s_running = true;
const char* c_console::g_console_executable_name = "FSBDump";

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	c_console::init_console();
	c_console::show_startup_banner();

	while (s_running)
	{
		c_console::Update();
	}
	
	c_console::deinit_console();

	return 0;
}