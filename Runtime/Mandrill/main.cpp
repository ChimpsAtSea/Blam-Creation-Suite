#include "mandrill-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Mandrill Debug";
#else
static constexpr const char window_title[] = "Mandrill";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

//BCS_RESULT window_register_callbacks()
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	c_imgui_context* imgui_context;
//	if (BCS_FAILED(rs = rs = window_render_context->get_imgui_context(imgui_context)))
//	{
//		return rs;
//	}
//
//	if (BCS_FAILED(rs = imgui_context->render_callback.add_callback(render_user_interface, render_user_interface_handle)))
//	{
//		return rs;
//	}
//
//	return rs;
//}
//
//BCS_RESULT window_unregister_callbacks()
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	c_imgui_context* imgui_context;
//	if (BCS_FAILED(rs = rs = window_render_context->get_imgui_context(imgui_context)))
//	{
//		return rs;
//	}
//
//	if (BCS_FAILED(rs = imgui_context->render_callback.remove_callback(render_user_interface_handle)))
//	{
//		return rs;
//	}
//
//	return rs;
//}
//
//BCS_RESULT register_device_recovery_callbacks()
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	BCS_FAIL_RETURN(rs = window_render_context->on_device_lost.add_callback(window_unregister_callbacks, render_on_device_lost_handle));
//	BCS_FAIL_RETURN(rs = window_render_context->on_device_recover.add_callback(window_register_callbacks, render_on_device_recover_handle));
//
//	return rs;
//}
//
//BCS_RESULT unregister_device_recovery_callbacks()
//{
//	BCS_RESULT rs = BCS_S_OK;
//
//	BCS_FAIL_RETURN(rs = window_render_context->on_device_lost.remove_callback(render_on_device_lost_handle));
//	BCS_FAIL_RETURN(rs = window_render_context->on_device_recover.remove_callback(render_on_device_recover_handle));
//
//	return rs;
//}

extern "C" int bcs_main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_RESULT rs = BCS_S_OK;

	BCS_RESULT device_communication_result = init_device_communication();
	if (BCS_SUCCEEDED(device_communication_result) || device_communication_result == BCS_E_UNSUPPORTED)
	{
		BCS_RESULT console_result = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Mandrill") : BCS_S_OK;
		if (BCS_SUCCEEDED(console_result))
		{
			BCS_RESULT window_create_result = window_create(window_title, "mandrill", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, true, true, window);
			if (BCS_SUCCEEDED(window_create_result))
			{
				BCS_RESULT render_context_window_result = render_context_window_create(*window, graphics_background_color, window_render_context);
				if (BCS_SUCCEEDED(window_create_result))
				{
					BCS_RESULT tag_definition_registry_init_result = blofeld::tag_definition_registry_init();
					if (BCS_SUCCEEDED(tag_definition_registry_init_result))
					{
						BCS_RESULT tag_definitions_register_result = blofeld::tag_definitions_register();
						if (BCS_SUCCEEDED(tag_definitions_register_result))
						{
							try
							{
								mandrill_user_interface = new() c_mandrill_user_interface(
									*window_render_context,
									false,
									launch_filepath_command_line_argument);

								window_render_context->render();

								delete mandrill_user_interface;
							}
							catch (BCS_RESULT _rs)
							{
								BCS_FAILED_CHAIN(rs, _rs);
							}
							catch (...)
							{
								BCS_FAILED_CHAIN(rs, BCS_E_FATAL);
							}

							tag_definitions_register_result = blofeld::tag_definitions_unregister();
							BCS_FAILED_CHAIN(rs, tag_definitions_register_result);
						}
						tag_definition_registry_init_result = blofeld::tag_definition_registry_deinit();
						BCS_FAILED_CHAIN(rs, tag_definition_registry_init_result);
					}
					render_context_window_result = render_context_destroy(window_render_context);
					BCS_FAILED_CHAIN(rs, render_context_window_result);
				}
				window_create_result = window_destroy(window);
				BCS_FAILED_CHAIN(rs, window_create_result);
			}
			BCS_FAILED_CHAIN(rs, console_result);
		}
		device_communication_result = deinit_device_communication();
		BCS_FAILED_CHAIN(rs, device_communication_result);
	}

	bool write_memory_allocations = command_line_has_argument("writememoryallocations");

	BCS_RESULT symbol_manager_cleanup_result = symbol_manager_cleanup();
	BCS_FAIL_RETURN(symbol_manager_cleanup_result);

	if (write_memory_allocations || c_mandrill_user_interface::get_write_memory_allocations_at_exit_setting())
	{
		::write_memory_allocations();
	}
	if (console_is_verbose())
	{
		print_memory_allocations();
	}

	return rs;
}
