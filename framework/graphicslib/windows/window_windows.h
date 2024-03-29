#pragma once

using on_window_procedure_callback = bool(void* userdata, HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);

class c_window_windows :
	public c_window
{
public:
	c_window_windows() = delete;
	c_window_windows(const c_window_windows&) = delete;
	c_window_windows& operator=(const c_window_windows&) = delete;

	explicit c_window_windows(
		const char* window_title,
		const char* window_id,
		e_window_icon window_icon,
		uint32_t width,
		uint32_t height,
		float4 background_color,
		bool is_primary_window,
		bool allow_adapter_recovery,
		const char* debug_name);
	BCS_RESULT construct(
		const char* window_title,
		const char* window_id,
		e_window_icon window_icon_type,
		uint32_t init_width,
		uint32_t init_height,
		bool is_primary_window);
	BCS_RESULT destruct();
	~c_window_windows();

	virtual bool update() override;
	virtual bool allow_adapter_recovery() override;

	static LRESULT CALLBACK window_procedure_callback(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);
	LRESULT window_procedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);

	using t_window_procedure_callback = void (HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);
	c_typed_callback<t_window_procedure_callback> on_window_procedure;

	HWND window_handle;
	HBRUSH window_brush;
	HICON window_icon;
	union
	{
		void* process_module;
		HINSTANCE instance_handle;
	};
	const wchar_t* window_class_name;
	float4 background_color;
	bool is_open : 1;
	bool adapter_recovery_enabled : 1;
};

BCS_RESULT window_windows_create(
	const char* window_title,
	const char* window_id,
	e_window_icon window_icon,
	uint32_t width, 
	uint32_t height,
	float4 background_color,
	bool is_primary_window,
	bool allow_adapter_recovery,
	c_window_windows*& window,
	const char* debug_name);
BCS_RESULT window_windows_destroy(c_window_windows* window);
