#include "halo3tagfiletest-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Halo 3 Tag File Test Debug";
#else
static constexpr const char window_title[] = "Halo 3 Tag File Test";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };


#include <HighLevel/high_level_halo3/highlevel-halo3-public-pch.h>

class c_tag_file_high_level_transplant
{
public:
	
	void* tag_file_data;
	unsigned long long tag_file_data_size;

	c_tag_file_high_level_transplant(const char* filepath, h_tag& high_level_tag)
	{
		BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
		
		char* header_data = (char*)tag_file_data;
		char* node_data = header_data + 64;

		c_node* root_node = create_data_node(node_data, nullptr);

		c_string_table_node* string_table = root_node->find_first_node<c_string_table_node>();
		c_array_node* array_table = root_node->find_first_node<c_array_node>();
		c_datum_node* data_table = root_node->find_first_node<c_datum_node>();
		c_block_v2_node* block_table = root_node->find_first_node<c_block_v2_node>();
		c_tag_field_types_node* field_types_table = root_node->find_first_node<c_tag_field_types_node>();

		c_binary_data_node* binary_data = root_node->find_first_node<c_binary_data_node>();



		root_node->log();

		debug_point;
	}

	~c_tag_file_high_level_transplant()
	{

	}



};

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if(BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument("console")) ? alloc_console("Halo 3 Tag File Test Console") : BCS_S_OK;
	//BCS_RESULT rs2 = window_create(window_title, "halo3tagfiletest", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, window);
	//BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	//mandrill_user_interface = new c_mandrill_user_interface(
	//	*window_render_context,
	//	false, 
	//	launch_filepath_command_line_argument);

	//window_render_context->render();

	//delete mandrill_user_interface;

	const char* filepath = R"(B:\H3EK\tags\ui\hud\hud_messages.multilingual_unicode_string_list)";
	blofeld::halo3::h_multilingual_unicode_string_list_struct_definition unicode_string_list;
	//auto& x = unicode_string_list.get_blofeld_struct_definition();
	c_tag_file_high_level_transplant high_level_transplant = c_tag_file_high_level_transplant(filepath, unicode_string_list);


	//if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	//if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);
	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	//BCS_FAIL_RETURN(rs3);
	//BCS_FAIL_RETURN(rs2);
	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);
	
	return 0;
}
