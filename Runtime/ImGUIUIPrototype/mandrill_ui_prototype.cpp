#include <Platform\platform-public-pch.h>
#include <Shared\shared-public-pch.h>

bool g_game_running = false;
bool g_window_open = false;

void render_menu_bar()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("New");
			ImGui::MenuItem("Open");
			ImGui::MenuItem("Close");
			ImGui::Separator();
			ImGui::MenuItem("Save");
			ImGui::MenuItem("Save As");
			ImGui::Separator();
			ImGui::MenuItem("Compile");
			ImGui::Separator();
			ImGui::MenuItem("Save Workspace");
			ImGui::MenuItem("Load Workspace");
			ImGui::Separator();
			ImGui::MenuItem("Exit");
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			ImGui::MenuItem("Undo");
			ImGui::Separator();
			ImGui::MenuItem("Cut");
			ImGui::MenuItem("Copy");
			ImGui::MenuItem("Paste");
			ImGui::MenuItem("Clear");
			ImGui::Separator();
			ImGui::MenuItem("Expert Mode");
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Tools"))
		{
			ImGui::MenuItem("Push to game");
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{
			ImGui::MenuItem("Explorer Bar");
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Help"))
		{
			ImGui::MenuItem("Read Me");
			ImGui::MenuItem("About");
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}
}

int style_color_count = 0;
int style_var_count = 0;
void mandrill_theme()
{
#define push_color4_float(color, r, g, b, a) style_color_count++; ImGui::PushStyleColor(color, ImVec4(float(r), float(g), float(b), float(a)))
#define push_color3_float(color, r, g, b) push_color4_float(color, r, g, b, 1.0f)
#define push_color4(color, r, g, b, a) push_color4_float(color, float(r) / 255.0f, float(g) / 255.0f, float(b) / 255.0f, 1.0f)
#define push_color3(color, r, g, b) push_color4(color, r, g, b, 255)
#define push_color(color, value) style_color_count++; ImGui::PushStyleColor(color, value)
#define push_style(style, ...) style_var_count++; ImGui::PushStyleVar(style, __VA_ARGS__)

#define HIGH(v) { 0.502f, 0.075f, 0.256f, v }
#define MED(v) { 0.455f, 0.198f, 0.301f, v }
#define LOW(v) { 0.232f, 0.201f, 0.271f, v }
#define BG(v) { 0.200f, 0.220f, 0.270f, v }
#define TEXT(v) { 0.930f, 0.965f, 0.945f, v }

	style_color_count = 0;
	style_var_count = 0;

	push_color(ImGuiCol_Text, TEXT(0.78f));
	push_color(ImGuiCol_TextDisabled, TEXT(0.28f));
	push_color(ImGuiCol_WindowBg, ImVec4(0.13f, 0.14f, 0.17f, 1.00f));
	push_color(ImGuiCol_ChildBg, BG(0.58f));
	push_color(ImGuiCol_PopupBg, BG(0.9f));
	push_color(ImGuiCol_Border, ImVec4(0.31f, 0.31f, 1.00f, 0.00f));
	push_color(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
	push_color(ImGuiCol_FrameBg, BG(1.00f));
	push_color(ImGuiCol_FrameBgHovered, MED(0.78f));
	push_color(ImGuiCol_FrameBgActive, MED(1.00f));
	push_color(ImGuiCol_TitleBg, LOW(1.00f));
	push_color(ImGuiCol_TitleBgActive, HIGH(1.00f));
	push_color(ImGuiCol_TitleBgCollapsed, BG(0.75f));
	push_color(ImGuiCol_MenuBarBg, BG(0.47f));
	push_color(ImGuiCol_ScrollbarBg, BG(1.00f));
	push_color(ImGuiCol_ScrollbarGrab, ImVec4(0.09f, 0.15f, 0.16f, 1.00f));
	push_color(ImGuiCol_ScrollbarGrabHovered, MED(0.78f));
	push_color(ImGuiCol_ScrollbarGrabActive, MED(1.00f));
	push_color(ImGuiCol_CheckMark, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_SliderGrab, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_SliderGrabActive, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_Button, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_ButtonHovered, MED(0.86f));
	push_color(ImGuiCol_ButtonActive, MED(1.00f));
	push_color(ImGuiCol_Header, MED(0.76f));
	push_color(ImGuiCol_HeaderHovered, MED(0.86f));
	push_color(ImGuiCol_HeaderActive, HIGH(1.00f));
	//push_color(ImGuiCol_Column, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	//push_color(ImGuiCol_ColumnHovered, MED(0.78f));
	//push_color(ImGuiCol_ColumnActive, MED(1.00f));
	push_color(ImGuiCol_ResizeGrip, ImVec4(0.47f, 0.77f, 0.83f, 0.04f));
	push_color(ImGuiCol_ResizeGripHovered, MED(0.78f));
	push_color(ImGuiCol_ResizeGripActive, MED(1.00f));
	push_color(ImGuiCol_PlotLines, TEXT(0.63f));
	push_color(ImGuiCol_PlotLinesHovered, MED(1.00f));
	push_color(ImGuiCol_PlotHistogram, TEXT(0.63f));
	push_color(ImGuiCol_PlotHistogramHovered, MED(1.00f));
	push_color(ImGuiCol_TextSelectedBg, MED(0.43f));
	push_color(ImGuiCol_ModalWindowDarkening, BG(0.73f));

	push_color(ImGuiCol_Tab, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	push_color(ImGuiCol_TabHovered, MED(0.78f));
	push_color(ImGuiCol_TabActive, MED(1.00f));
	push_color(ImGuiCol_TabUnfocused, LOW(0.78f));


	//push_color3(ImGuiCol_WindowBg, 33, 33, 33);
	push_color3(ImGuiCol_MenuBarBg, 96, 96, 96);

	push_style(ImGuiStyleVar_WindowPadding, { 4, 8 });
	push_style(ImGuiStyleVar_ScrollbarSize, { 20 });
	push_style(ImGuiStyleVar_ItemInnerSpacing, { 5, 4 });

	push_style(ImGuiStyleVar_WindowRounding, { 0 });
	push_style(ImGuiStyleVar_ScrollbarRounding, { 0 });
	push_style(ImGuiStyleVar_TabRounding, { 0 });

	//#undef HIGH
	//#undef MED
	//#undef LOW
	//#undef BG
	//#undef TEXT

#undef push_color4_float
#undef push_color3_float
#undef push_color4
#undef push_color3
#undef push_style
}

void mandrill_theme_end()
{
	ImGui::PopStyleColor(style_color_count);
	ImGui::PopStyleVar(style_var_count);
}

enum e_node_type
{
	_node_type_folder,
	_node_type_file,
};

struct s_node
{
	e_node_type type;
	const char* name;
	bool is_open;
	uint32_t num_nodes;
	s_node* children[];
};

s_node file1 = { _node_type_file, "file1", false, 0, {} };
s_node objects = { _node_type_folder, "objects", false, 1, {&file1} };
s_node file2 = { _node_type_file, "file2", false, 0, {} };
s_node tags = { _node_type_folder, "tags", true, 2, { &objects, &file2 } };





s_node assault_rifle = { _node_type_file, "assault_rifle.weapon", false, 0, {} };
s_node weapons = { _node_type_folder, "weapons", false, 1, {&assault_rifle} };
s_node warthog = { _node_type_file, "warthog.vehicle", false, 0, {} };
s_node vehicles = { _node_type_folder, "vehicles", false, 1, {&warthog} };
s_node objects2 = { _node_type_folder, "objects", false, 2, {&vehicles, &weapons} };
s_node shaders = { _node_type_folder, "shaders", false, 0, {} };

s_node root = { _node_type_folder, "$root", true, 2, { &objects2, &shaders } };




void render_tree_node(s_node& node)
{
	ImGui::PushID(&node);
	ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_OpenOnArrow;

	const char* format_string = "%s";
	const char* icon_string = "";
	switch (node.type)
	{
	case _node_type_folder:
		flags |= ImGuiTreeNodeFlags_OpenOnDoubleClick;
		if (node.is_open)
		{
			flags |= ImGuiTreeNodeFlags_DefaultOpen;
			icon_string = ICON_FA_FOLDER_OPEN;
			format_string = ICON_FA_FOLDER_OPEN" %s";
		}
		else
		{
			icon_string = ICON_FA_FOLDER;
			format_string = ICON_FA_FOLDER" %s";
		}
		break;
	case _node_type_file:
		flags |= ImGuiTreeNodeFlags_OpenOnDoubleClick;
		flags |= ImGuiTreeNodeFlags_Leaf;
		icon_string = ICON_FA_FILE;
		format_string = ICON_FA_FILE" %s";
		break;
	}

	bool is_tree_open = ImGui::TreeNodeEx("##hiddenlavel", flags);
	ImGui::SameLine();

	//ImGui::PushStyleColor(ImGuiCol_Text, MED(1.00f));
	//ImGui::Text("%s ", icon_string);
	//ImGui::PopStyleColor();
	//ImGui::SameLine();
	//ImGui::Text(node.name);

	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	ImVec2 pos0 = ImGui::GetCursorScreenPos();
	ImVec2 pos1 = { pos0.x + ImGui::CalcTextSize(icon_string).x + ImGui::CalcTextSize(" ").x, pos0.y };

	draw_list->AddText(pos0, ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), icon_string);
	draw_list->AddText(pos1, ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), node.name);

	ImGui::Dummy({});
	if (is_tree_open)
	{
		for (uint32_t i = 0; i < node.num_nodes; i++)
		{
			render_tree_node(*node.children[i]);
		}

		ImGui::TreePop();
	}
	node.is_open = is_tree_open;

	ImGui::PopID();
}

void search_box()
{
	const char* search_reccomendation = "<search for tag>";
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::Dummy({ 10.0f, 0.0f });
	ImGui::SameLine();
	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth() - 70.0f);
	static char search_buffer[128];
	ImGuiInputTextFlags input_text_flags = 0;
	ImVec2 pos = ImGui::GetCursorScreenPos();
	ImGui::InputText("##Search", search_buffer, _countof(search_buffer), input_text_flags);
	if (!ImGui::IsItemActive() && search_buffer[0] == 0)
	{
		draw_list->AddText({ pos.x + 4.0f, pos.y + 4.0f }, ImGui::ColorConvertFloat4ToU32(TEXT(0.25)), search_reccomendation);
	}
	ImGui::SameLine();
	ImGui::Button(ICON_FA_TIMES, { 30.0f, 0.0f });
	ImGui::SameLine();
	ImGui::Dummy({ 10.0f, 0.0f });
}

void explorer_bar()
{
	ImGui::Dummy({ 0.0f, 10.0f });

	search_box();

	ImGui::Dummy({ 0.0f, 10.0f });
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 25, 8 });
	if (ImGui::BeginTabBar("##fileview"))
	{
		if (ImGui::BeginTabItem("Tags"))
		{
			ImGui::Dummy({ 0.0f, 1.0f });
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4, 4 });
			for (uint32_t i = 0; i < root.num_nodes; i++)
			{
				render_tree_node(*root.children[i]);
			}
			ImGui::EndTabItem();
			ImGui::PopStyleVar();
		}
		if (ImGui::BeginTabItem("Files"))
		{
			ImGui::Dummy({ 0.0f, 1.0f });
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 4, 4 });
			render_tree_node(tags);
			ImGui::EndTabItem();
			ImGui::PopStyleVar();
		}

		ImGui::EndTabBar();
	}
	ImGui::PopStyleVar();
}

void tag_fields()
{
	for (int i = 0; i < 2; i++)
	{
		ImGui::PushID(i);
		static char buffer[128];
		ImGui::InputText("text", buffer, _countof(buffer));
		static int value = 100;
		ImGui::InputInt("integer", &value);
		static float color[4]{};
		ImGui::ColorEdit4("text", color);
		ImGui::InputInt("integer1", &value);
		ImGui::InputInt("integer2", &value);
		ImGui::InputInt("integer3", &value);
		ImGui::InputInt("integer4", &value);
		ImGui::InputInt("integer5", &value);
		ImGui::PopID();
	}
}

void tag_editor()
{
	if (ImGui::BeginTabBar("##tagsview"))
	{
		if (ImGui::BeginTabItem("assault_rifle.weapon"))
		{
			tag_fields();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("warthog.vehicle"))
		{
			tag_fields();
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
}

void cache_file_tab()
{
	ImGui::PushID(100);
	if (ImGui::BeginTabItem("Halo Reach", nullptr))
	{
		ImGui::Columns(2, "##navigation");
		RUNONCE(ImGui::SetColumnOffset(1, 500));
		ImGui::Separator();
		{
			ImGui::BeginChild("left column", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), false, ImGuiWindowFlags_NoScrollbar);

			explorer_bar();

			ImGui::EndChild();
		}
		ImGui::NextColumn();
		{
			ImGui::BeginChild("right column", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), false);

			tag_editor();

			ImGui::EndChild();
		}
		ImGui::Columns(1);

		ImGui::EndTabItem();
	}
	ImGui::PopID();
}


void mandrill_init()
{
	mandrill_theme();
}

void mandrill()
{
	float margin = 4.0f;
	ImGui::SetNextWindowPos({ margin, margin }, ImGuiCond_Always);
	ImGui::SetNextWindowSize({ c_window_win32::get_width_float() - margin * 2.0f, c_window_win32::get_height_float() - margin * 2.0f }, ImGuiCond_Always);

	ImGuiWindowFlags imgui_window_flags = 0;
	imgui_window_flags |= ImGuiWindowFlags_NoCollapse;
	imgui_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	if (!g_game_running)
	{
		imgui_window_flags |= ImGuiWindowFlags_NoTitleBar;
		imgui_window_flags |= ImGuiWindowFlags_NoMove;
		imgui_window_flags |= ImGuiWindowFlags_NoResize;
	}
	if (ImGui::Begin("##mandrill", &g_window_open, imgui_window_flags))
	{
		ImGuiIO& io = ImGui::GetIO();

		render_menu_bar();

		if (ImGui::BeginTabBar("##root"))
		{
			cache_file_tab();

			ImGui::EndTabBar();
		}

	}
	ImGui::End();
}

void mandrill_deinit()
{
	mandrill_theme_end();
}
