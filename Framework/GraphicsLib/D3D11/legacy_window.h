//#pragma once
//
//enum e_window_icon
//{
//	_window_icon_default,
//	_window_icon_blam_creation_suite,
//	_window_icon_mandrill,
//	k_number_of_window_icons
//};
//
//class c_window
//{
//public:
//	c_window() = delete;
//	c_window(c_window const&) = delete;
//	c_window& operator=(c_window const&) = delete;
//
//	c_window(
//		HINSTANCE instance_handle, 
//		const wchar_t* window_title, 
//		const wchar_t* application_name, 
//		e_window_icon window_icon,
//		int show_cmd = SW_SHOW);
//	~c_window();
//
//	void update(bool allow_callbacks = true);
//	void set_title(const wchar_t* title);
//	void set_post_message_thread_id(HANDLE thread_handle);
//	bool is_focused();
//
//	inline uint32_t get_width_integer() const { return width_integer; }
//	inline uint32_t get_height_integer() const { return height_integer; }
//	inline float get_width_float() const { return width_float; }
//	inline float get_height_float() const { return height_float; }
//	inline float get_aspect_ratio() const { return aspect_ratio; }
//	inline HWND get_window_handle() const { return window_handle; }
//
//	c_callback<LRESULT(HWND, UINT, WPARAM, LPARAM)> on_window_procedure;
//	c_callback<void()> on_update;
//	c_callback<void()> on_destroy;
//	c_callback<void(uint32_t width, uint32_t height)> on_resize;
//
//protected:
//
//	static LRESULT CALLBACK window_procedure(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);
//	LRESULT window_procedure_impl(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);
//	void update_window_size();
//
//	HINSTANCE instance_handle;
//	HICON icon_handle;
//	HWND window_handle;
//	HANDLE post_message_thread_handle;
//	DWORD post_message_thread_id;
//	uint32_t width_integer;
//	uint32_t height_integer;
//	float width_float;
//	float height_float;
//	float aspect_ratio;
//};
//
