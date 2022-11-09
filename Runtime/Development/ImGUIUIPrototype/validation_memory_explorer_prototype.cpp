#include "imguiuiprototype-private-pch.h"

#define MANDRILL_THEME_HIGH(v) { 0.502f, 0.075f, 0.256f, v }
#define MANDRILL_THEME_MED(v) { 0.455f, 0.198f, 0.301f, v }
#define MANDRILL_THEME_LOW(v) { 0.232f, 0.201f, 0.271f, v }
#define MANDRILL_THEME_DISABLED_HIGH(v) { 0.224f, 0.224f, 0.224f, v }
#define MANDRILL_THEME_DISABLED_MED(v) { 0.286f, 0.286f, 0.286f, v }
#define MANDRILL_THEME_DISABLED_LOW(v) { 0.215f, 0.215f, 0.215f, v }
#define MANDRILL_THEME_BG(v) { 0.200f, 0.220f, 0.270f, v }
#define MANDRILL_THEME_TEXT(v) { 0.930f, 0.965f, 0.945f, v }
#define MANDRILL_THEME_COMMENT_TEXT(v) { 0.752f, 0.965f, 0.766f, v }
#define MANDRILL_THEME_ERROR_TEXT(v) { 0.950f, 0.475f, 0.475f, v }
#define MANDRILL_THEME_INFO_TEXT(v) { 0.796f, 0.808f, 0.965f, v }
#define MANDRILL_THEME_MENU(v) { 0.377f, 0.377f, 0.377f, v }

char bytes[] = {
	0x52, 0x49, 0x46, 0x46, 0x00, 0x01, 0x66, 0x82, 0x57, 0x41, 0x56, 0x45,
	0x66, 0x6D, 0x74, 0x20, 0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00,
	0x80, 0xBB, 0x00, 0x00, 0xE5, 0xBF, 0x00, 0x00, 0x0C, 0x02, 0x04, 0x00,
	0x20, 0x00, 0x00, 0x02, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x40, 0x00, 0xF0, 0x00,
	0x00, 0x00, 0xCC, 0x01, 0x30, 0xFF, 0x88, 0x01, 0x18, 0xFF, 0x64, 0x61,
	0x74, 0x61, 0x34, 0x66, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x52, 0x49, 0x46, 0x46, 0x00, 0x01, 0x66, 0x82, 0x57, 0x41, 0x56, 0x45,
	0x66, 0x6D, 0x74, 0x20, 0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00,
	0x80, 0xBB, 0x00, 0x00, 0xE5, 0xBF, 0x00, 0x00, 0x0C, 0x02, 0x04, 0x00,
	0x20, 0x00, 0x00, 0x02, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x40, 0x00, 0xF0, 0x00,
	0x00, 0x00, 0xCC, 0x01, 0x30, 0xFF, 0x88, 0x01, 0x18, 0xFF, 0x64, 0x61,
	0x74, 0x61, 0x34, 0x66, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x52, 0x49, 0x46, 0x46, 0x00, 0x01, 0x66, 0x82, 0x57, 0x41, 0x56, 0x45,
	0x66, 0x6D, 0x74, 0x20, 0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00,
	0x80, 0xBB, 0x00, 0x00, 0xE5, 0xBF, 0x00, 0x00, 0x0C, 0x02, 0x04, 0x00,
	0x20, 0x00, 0x00, 0x02, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x40, 0x00, 0xF0, 0x00,
	0x00, 0x00, 0xCC, 0x01, 0x30, 0xFF, 0x88, 0x01, 0x18, 0xFF, 0x64, 0x61,
	0x74, 0x61, 0x34, 0x66, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x52, 0x49, 0x46, 0x46, 0x00, 0x01, 0x66, 0x82, 0x57, 0x41, 0x56, 0x45,
	0x66, 0x6D, 0x74, 0x20, 0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00,
	0x80, 0xBB, 0x00, 0x00, 0xE5, 0xBF, 0x00, 0x00, 0x0C, 0x02, 0x04, 0x00,
	0x20, 0x00, 0x00, 0x02, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x40, 0x00, 0xF0, 0x00,
	0x00, 0x00, 0xCC, 0x01, 0x30, 0xFF, 0x88, 0x01, 0x18, 0xFF, 0x64, 0x61,
	0x74, 0x61, 0x34, 0x66, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
	0x52, 0x49, 0x46, 0x46, 0x00, 0x01, 0x66, 0x82, 0x57, 0x41, 0x56, 0x45,
	0x66, 0x6D, 0x74, 0x20, 0x32, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00,
	0x80, 0xBB, 0x00, 0x00, 0xE5, 0xBF, 0x00, 0x00, 0x0C, 0x02, 0x04, 0x00,
	0x20, 0x00, 0x00, 0x02, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
	0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x40, 0x00, 0xF0, 0x00,
	0x00, 0x00, 0xCC, 0x01, 0x30, 0xFF, 0x88, 0x01, 0x18, 0xFF, 0x64, 0x61,
	0x74, 0x61, 0x34, 0x66, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

ImU32 colors[] =
{
	IM_COL32(0xe6, 0x19, 0x4b, 0x50),
	IM_COL32(0x3c, 0xb4, 0x4b, 0x50),
	IM_COL32(0xff, 0xe1, 0x19, 0x50),
	IM_COL32(0x43, 0x63, 0xd8, 0x50),
	IM_COL32(0xf5, 0x82, 0x31, 0x50),
	IM_COL32(0x91, 0x1e, 0xb4, 0x50),
	IM_COL32(0x46, 0xf0, 0xf0, 0x50),
	IM_COL32(0xf0, 0x32, 0xe6, 0x50),
	IM_COL32(0xbc, 0xf6, 0x0c, 0x50),
	IM_COL32(0xfa, 0xbe, 0xbe, 0x50),
	IM_COL32(0x00, 0x80, 0x80, 0x50),
	IM_COL32(0xe6, 0xbe, 0xff, 0x50),
	IM_COL32(0x9a, 0x63, 0x24, 0x50),
	IM_COL32(0xff, 0xfa, 0xc8, 0x50),
	IM_COL32(0x80, 0x00, 0x00, 0x50),
	IM_COL32(0xaa, 0xff, 0xc3, 0x50),
	IM_COL32(0x80, 0x80, 0x00, 0x50),
	IM_COL32(0xff, 0xd8, 0xb1, 0x50),
	IM_COL32(0x00, 0x00, 0x75, 0x50),
};

ImU32 hole_colors[] =
{
	IM_COL32(0xe6, 0x19, 0x4b, 0x10),
	IM_COL32(0x3c, 0xb4, 0x4b, 0x10),
	IM_COL32(0xff, 0xe1, 0x19, 0x10),
	IM_COL32(0x43, 0x63, 0xd8, 0x10),
	IM_COL32(0xf5, 0x82, 0x31, 0x10),
	IM_COL32(0x91, 0x1e, 0xb4, 0x10),
	IM_COL32(0x46, 0xf0, 0xf0, 0x10),
	IM_COL32(0xf0, 0x32, 0xe6, 0x10),
	IM_COL32(0xbc, 0xf6, 0x0c, 0x10),
	IM_COL32(0xfa, 0xbe, 0xbe, 0x10),
	IM_COL32(0x00, 0x80, 0x80, 0x10),
	IM_COL32(0xe6, 0xbe, 0xff, 0x10),
	IM_COL32(0x9a, 0x63, 0x24, 0x10),
	IM_COL32(0xff, 0xfa, 0xc8, 0x10),
	IM_COL32(0x80, 0x00, 0x00, 0x10),
	IM_COL32(0xaa, 0xff, 0xc3, 0x10),
	IM_COL32(0x80, 0x80, 0x00, 0x10),
	IM_COL32(0xff, 0xd8, 0xb1, 0x10),
	IM_COL32(0x00, 0x00, 0x75, 0x10),
};

ImU32 border_colors[] =
{
	IM_COL32(0xe6, 0x19, 0x4b, 0xFF),
	IM_COL32(0x3c, 0xb4, 0x4b, 0xFF),
	IM_COL32(0xff, 0xe1, 0x19, 0xFF),
	IM_COL32(0x43, 0x63, 0xd8, 0xFF),
	IM_COL32(0xf5, 0x82, 0x31, 0xFF),
	IM_COL32(0x91, 0x1e, 0xb4, 0xFF),
	IM_COL32(0x46, 0xf0, 0xf0, 0xFF),
	IM_COL32(0xf0, 0x32, 0xe6, 0xFF),
	IM_COL32(0xbc, 0xf6, 0x0c, 0xFF),
	IM_COL32(0xfa, 0xbe, 0xbe, 0xFF),
	IM_COL32(0x00, 0x80, 0x80, 0xFF),
	IM_COL32(0xe6, 0xbe, 0xff, 0xFF),
	IM_COL32(0x9a, 0x63, 0x24, 0xFF),
	IM_COL32(0xff, 0xfa, 0xc8, 0xFF),
	IM_COL32(0x80, 0x00, 0x00, 0xFF),
	IM_COL32(0xaa, 0xff, 0xc3, 0xFF),
	IM_COL32(0x80, 0x80, 0x00, 0xFF),
	IM_COL32(0xff, 0xd8, 0xb1, 0xFF),
	IM_COL32(0x00, 0x00, 0x75, 0xFF),
};

struct s_interval
{
	const char* name;
	const char* start;
	const char* end;
	bool is_hole;
};

unsigned int byte_hover_index = UINT_MAX;

static ImVec2& operator-=(ImVec2& a, ImVec2& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

static ImVec2& operator+=(ImVec2& a, ImVec2& b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

static ImVec2 operator*(ImVec2 a, float b)
{
	a.x *= b;
	a.y *= b;
	return a;
}

static ImVec2& operator*=(ImVec2& a, float b)
{
	a.x *= b;
	a.y *= b;
	return a;
}

bool range_intersection(const char* a1, const char* a2, const char* b1, const char* b2)
{
	return __max(a1, b1) < __min(a2, b2);
}

int display_items_start = 0;
int display_items_end = 0;

void draw_memory_explorer(const char* const bytes, unsigned int const num_bytes)
{
	ImGuiStyle& style = ImGui::GetStyle();

	std::vector<s_interval> intervals;
	intervals.push_back({ "test1", bytes, bytes + 5 });
	intervals.push_back({ "test2", bytes + 5, bytes + 10 });
	intervals.push_back({ "test3", bytes + 10, bytes + 10 });
	intervals.push_back({ "test4", bytes + 1, bytes + 3 });
	intervals.push_back({ "test4", bytes + 20, bytes + 30 });

	unsigned int tick_byte_hover_index = byte_hover_index;
	byte_hover_index = UINT_MAX;

	unsigned int num_columns = 16;
	unsigned int num_rows = ROUND_UP_VALUE(num_bytes, num_columns) / num_columns;

	ImGui::Text("%i %i", display_items_start, display_items_end);

	using t_interval_vector = std::vector<unsigned int>;

	t_interval_vector* interval_byte_associations = new t_interval_vector[num_bytes];

	for (unsigned int byte_index = 0; byte_index < num_bytes; byte_index++)
	{
		const char* byte_address = bytes + byte_index;
		for (unsigned int interval_index = 0; interval_index < intervals.size(); interval_index++)
		{
			s_interval& interval = intervals[interval_index];
			//if (interval.start >= byte_address && byte_address < interval.end)
			if (range_intersection(byte_address, byte_address + 1, interval.start, interval.end))
			{
				interval_byte_associations[byte_index].push_back(interval_index);
			}
		}
	}

	for (unsigned int byte_index = 0; byte_index < num_bytes; byte_index++)
	{
		t_interval_vector& interval_byte_association = interval_byte_associations[byte_index];
		if (interval_byte_association.empty())
		{
			unsigned int interval_index = static_cast<unsigned int>(intervals.size());
			s_interval& interval = intervals.emplace_back();

			unsigned int hole_start_index = byte_index;
			unsigned int hole_end_index = byte_index;
			for (; byte_index < num_bytes; byte_index++, hole_end_index++)
			{
				t_interval_vector& interval_byte_association = interval_byte_associations[byte_index];
				if (interval_byte_association.empty())
				{
					interval_byte_association.push_back(interval_index);
				}
				else
				{
					break;
				}
			}
			interval.name = "hole";
			interval.start = bytes + hole_start_index;
			interval.end = bytes + hole_end_index;
			interval.is_hole = true;
			debug_point;
		}
	}

	// std::sort(intervals.begin(), intervals.end(), [](s_interval& a, s_interval& b) { return a.start < b.start; });

	if (tick_byte_hover_index == UINT_MAX)
	{
		ImGui::Text("Index: -");
	}
	else
	{
		if (num_bytes < 0x100)
		{
			ImGui::Text("Index: 0x%02X", tick_byte_hover_index);
		}
		else if (num_bytes < 0x1000)
		{
			ImGui::Text("Index: 0x%03X", tick_byte_hover_index);
		}
		else if (num_bytes < 0x10000)
		{
			ImGui::Text("Index: 0x%04X", tick_byte_hover_index);
		}
		else if (num_bytes < 0x1000000)
		{
			ImGui::Text("Index: 0x%06X", tick_byte_hover_index);
		}
		else
		{
			ImGui::Text("Index: 0x%08X", tick_byte_hover_index);
		}
	}

	if (ImGui::BeginChild("test", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar))
	{
		ImVec2 character_size = ImGui::CalcTextSize("X") + style.ItemSpacing;
		ImGui::CalcListClipping(num_rows, character_size.y, &display_items_start, &display_items_end);

		unsigned int byte_index = 0;
		for (unsigned int row_index = 0; row_index < num_rows; row_index++)
		{
			if (row_index >= static_cast<unsigned int>(display_items_start) && row_index < static_cast<unsigned int>(display_items_end))
			{

				unsigned int address = row_index * num_columns;

				unsigned int hover_row_index = tick_byte_hover_index / num_columns;
				if (hover_row_index == row_index)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.6f));
				}

				if (num_bytes < 0x100)
				{
					ImGui::Text("0x%02X", address);
				}
				else if (num_bytes < 0x1000)
				{
					ImGui::Text("0x%03X", address);
				}
				else if (num_bytes < 0x10000)
				{
					ImGui::Text("0x%04X", address);
				}
				else if (num_bytes < 0x1000000)
				{
					ImGui::Text("0x%06X", address);
				}
				else
				{
					ImGui::Text("0x%08X", address);
				}

				ImGui::PopStyleColor();

				ImGui::SameLine();
				unsigned int const column_byte_index_start = byte_index;
				for (unsigned int column_index = 0; column_index < num_columns; column_index++, byte_index++)
				{
					if (byte_index < num_bytes)
					{
						t_interval_vector& interval_byte_association = interval_byte_associations[byte_index];
						char byte = bytes[byte_index];

						ImVec2 cursor_pos = ImGui::GetCursorPos();
						ImGui::PushStyleColor(ImGuiCol_Text, 0);
						ImGui::Text("%02hhX", byte);
						ImGui::PopStyleColor();

						ImGuiStyle& style = ImGui::GetStyle();
						ImVec2 min_rect = ImGui::GetItemRectMin();
						ImVec2 max_rect = ImGui::GetItemRectMax();
						min_rect -= style.ItemSpacing * 0.5f;
						max_rect += style.ItemSpacing * 0.5f;

						bool is_mouse_hover = ImGui::IsMouseHoveringRect(min_rect, max_rect);
						if (is_mouse_hover)
						{
							byte_hover_index = byte_index;

							ImGui::BeginTooltip();
							for (unsigned int interval_index : interval_byte_association)
							{
								ImU32 color = border_colors[interval_index % _countof(colors)];
								ImGui::PushStyleColor(ImGuiCol_Text, color);
								s_interval& interval = intervals[interval_index];

								ImVec2 cursor_pos = ImGui::GetCursorPos();
								ImGui::TextUnformatted(interval.name);
								//ImVec2 cursor_pos_end = ImGui::GetCursorPos();
								//ImGui::SetCursorPos(cursor_pos + ImVec2{ 1.0f, 0.0f });
								//ImGui::TextUnformatted(interval.name);
								//ImGui::SetCursorPos(cursor_pos + ImVec2{ 0.0f, 1.0f });
								//ImGui::TextUnformatted(interval.name);
								//ImGui::SetCursorPos(cursor_pos + ImVec2{ 1.0f, 1.0f });
								//ImGui::TextUnformatted(interval.name);
								//ImGui::SetCursorPos(cursor_pos_end);

								ImGui::PopStyleColor();
							}
							ImGui::EndTooltip();
						}

						for (unsigned int interval_index : interval_byte_association)
						{
							s_interval& interval = intervals[interval_index];
							ImDrawList& draw_list = *ImGui::GetWindowDrawList();

							if (interval.is_hole)
							{
								ImU32 border_color = hole_colors[interval_index % _countof(colors)];
								if (interval.start == bytes + byte_index)
								{
									draw_list.AddLine({ min_rect.x, min_rect.y + 1 }, { min_rect.x, max_rect.y - 1 }, border_color);
								}
								if (interval.end == bytes + byte_index + 1)
								{
									draw_list.AddLine({ max_rect.x - 1, min_rect.y + 1 }, { max_rect.x - 1, max_rect.y - 1 }, border_color);
								}
								draw_list.AddLine({ min_rect.x, min_rect.y }, { max_rect.x, min_rect.y }, border_color);
								draw_list.AddLine({ min_rect.x, max_rect.y - 1 }, { max_rect.x, max_rect.y - 1 }, border_color);

								ImU32 hole_color = hole_colors[interval_index % _countof(colors)];
								draw_list.AddRectFilled(min_rect, max_rect, hole_color);
							}
							else
							{
								ImU32 color = colors[interval_index % _countof(colors)];
								draw_list.AddRectFilled(min_rect, max_rect, color);
							}
						}

						if (interval_byte_association.size() > 1)
						{
							ImDrawList& draw_list = *ImGui::GetWindowDrawList();
							unsigned int alpha = __clamp(0, 255, 85 * interval_byte_association.size());
							draw_list.AddLine({ min_rect.x, max_rect.y }, { max_rect.x, max_rect.y }, IM_COL32(255, 255, 0, alpha));
						}

						if (tick_byte_hover_index == byte_index)
						{
							if (interval_byte_association.size() > 1)
							{
								ImDrawList& draw_list = *ImGui::GetWindowDrawList();
								draw_list.AddRectFilled(min_rect, max_rect, IM_COL32(255, 0, 0, 127));
							}
							else
							{
								ImDrawList& draw_list = *ImGui::GetWindowDrawList();
								draw_list.AddRectFilled(min_rect, max_rect, IM_COL32(255, 255, 255, 50));
							}
						}

						{
							ImGui::SetCursorPos(cursor_pos);

							if (tick_byte_hover_index == byte_index)
							{
								ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
							}

							ImGui::Text("%02hhX", byte);

							if (tick_byte_hover_index == byte_index)
							{
								ImGui::PopStyleColor();
							}
						}
					}
					else
					{
						ImGui::TextUnformatted("  ");
					}
					ImGui::SameLine();
				}
				if (hover_row_index == row_index)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.6f));
				}
				ImGui::Text(" | ");
				ImGui::PopStyleColor();
				ImGui::SameLine();
				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f });
				byte_index = column_byte_index_start;
				for (unsigned int column_index = 0; column_index < num_columns && byte_index < num_bytes; column_index++, byte_index++)
				{
					char byte = bytes[byte_index];

					if (tick_byte_hover_index == byte_index)
					{
						ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
					}
					else if (byte > 0 && isprint(byte))
					{
						ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.6f));
					}
					else
					{
						ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.3f));
					}

					if (byte > 0 && isprint(byte))
					{
						ImGui::Text("%.1s", &byte);
					}
					else
					{
						ImGui::TextUnformatted(".");
					}

					ImGui::PopStyleColor();

					ImGui::SameLine();
				}
				ImGui::PopStyleVar();
				ImGui::Dummy({});

			}
			else
			{
				ImGui::TextUnformatted("");
			}
		}
		ImGui::EndChild();
	}

	delete[] interval_byte_associations;
}

void draw_memory_explorer()
{
	draw_memory_explorer(bytes, _countof(bytes));
}

static int mandrill_theme_color_count;
static int mandrill_theme_var_count;
static void mandrill_theme_push()
{
#define push_color4_float(color, r, g, b, a) mandrill_theme_color_count++; ImGui::PushStyleColor(color, ImVec4(float(r), float(g), float(b), float(a)))
#define push_color3_float(color, r, g, b) push_color4_float(color, r, g, b, 1.0f)
#define push_color4(color, r, g, b, a) push_color4_float(color, float(r) / 255.0f, float(g) / 255.0f, float(b) / 255.0f, 1.0f)
#define push_color3(color, r, g, b) push_color4(color, r, g, b, 255)
#define push_color(color, value) mandrill_theme_color_count++; ImGui::PushStyleColor(color, value)
#define push_style(style, ...) mandrill_theme_var_count++; ImGui::PushStyleVar(style, __VA_ARGS__)

	mandrill_theme_color_count = 0;
	mandrill_theme_var_count = 0;

	push_color(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.78f));
	push_color(ImGuiCol_TextDisabled, MANDRILL_THEME_TEXT(0.28f));
	push_color(ImGuiCol_WindowBg, ImVec4(0.13f, 0.14f, 0.17f, 1.00f));
	push_color(ImGuiCol_ChildBg, MANDRILL_THEME_BG(0.15f));
	push_color(ImGuiCol_PopupBg, MANDRILL_THEME_BG(0.9f));
	push_color(ImGuiCol_Border, ImVec4(0.31f, 0.31f, 1.00f, 0.00f));
	push_color(ImGuiCol_BorderShadow, ImVec4(0.00f, 0.00f, 0.00f, 0.00f));
	push_color(ImGuiCol_FrameBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_FrameBgHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_FrameBgActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TitleBg, MANDRILL_THEME_LOW(1.00f));
	push_color(ImGuiCol_TitleBgActive, MANDRILL_THEME_HIGH(1.00f));
	push_color(ImGuiCol_TitleBgCollapsed, MANDRILL_THEME_BG(0.75f));
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_BG(0.47f));
	push_color(ImGuiCol_ScrollbarBg, MANDRILL_THEME_BG(1.00f));
	push_color(ImGuiCol_ScrollbarGrab, ImVec4(0.09f, 0.15f, 0.16f, 1.00f));
	push_color(ImGuiCol_ScrollbarGrabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ScrollbarGrabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_CheckMark, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_SliderGrab, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_SliderGrabActive, ImVec4(0.71f, 0.22f, 0.27f, 1.00f));
	push_color(ImGuiCol_Button, ImVec4(0.47f, 0.77f, 0.83f, 0.14f));
	push_color(ImGuiCol_ButtonHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_ButtonActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_Header, MANDRILL_THEME_MED(0.76f));
	push_color(ImGuiCol_HeaderHovered, MANDRILL_THEME_MED(0.86f));
	push_color(ImGuiCol_HeaderActive, MANDRILL_THEME_HIGH(1.00f));
	//push_color(ImGuiCol_Column, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	//push_color(ImGuiCol_ColumnHovered, MANDRILL_THEME_MED(0.78f));
	//push_color(ImGuiCol_ColumnActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_ResizeGrip, ImVec4(0.47f, 0.77f, 0.83f, 0.04f));
	push_color(ImGuiCol_ResizeGripHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_ResizeGripActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotLines, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotLinesHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_PlotHistogram, MANDRILL_THEME_TEXT(0.63f));
	push_color(ImGuiCol_PlotHistogramHovered, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TextSelectedBg, MANDRILL_THEME_MED(0.43f));
	//push_color(ImGuiCol_ModalWindowDarkening, MANDRILL_THEME_BG(0.73f));

	push_color(ImGuiCol_Tab, ImVec4(0.14f, 0.16f, 0.19f, 1.00f));
	push_color(ImGuiCol_TabHovered, MANDRILL_THEME_MED(0.78f));
	push_color(ImGuiCol_TabActive, MANDRILL_THEME_MED(1.00f));
	push_color(ImGuiCol_TabUnfocused, MANDRILL_THEME_LOW(0.78f));


	//push_color3(ImGuiCol_WindowBg, 33, 33, 33);
	push_color(ImGuiCol_MenuBarBg, MANDRILL_THEME_MENU(1.0f));

	push_style(ImGuiStyleVar_WindowPadding, { 4, 8 });
	push_style(ImGuiStyleVar_ScrollbarSize, { 20 });
	push_style(ImGuiStyleVar_ItemInnerSpacing, { 5, 4 });

	push_style(ImGuiStyleVar_WindowRounding, { 0 });
	push_style(ImGuiStyleVar_ScrollbarRounding, { 0 });
	push_style(ImGuiStyleVar_TabRounding, { 0 });

#undef push_color4_float
#undef push_color3_float
#undef push_color4
#undef push_color3
#undef push_style
}

static void mandrill_theme_pop()
{
	ImGui::PopStyleColor(mandrill_theme_color_count);
	ImGui::PopStyleVar(mandrill_theme_var_count);
}

constexpr float MANDRILL_THEME_DEFAULT_TEXT_ALPHA = 0.78f;
static t_callback_handle imgui_memory_test_wip_callback_handle;
static bool g_window_open = true;
void validation_memory_explorer_prototype(c_window& window)
{
	mandrill_theme_push();
	//return;
	ImGui::SetNextWindowPos({ 0, 0 }, ImGuiCond_Always);
	ImGui::SetNextWindowSize({ window.width_float, window.height_float }, ImGuiCond_Always);

	ImGuiWindowFlags imgui_window_flags = 0;
	//imgui_window_flags |= ImGuiWindowFlags_NoCollapse;
	//imgui_window_flags |= ImGuiWindowFlags_MenuBar;
	imgui_window_flags |= ImGuiWindowFlags_NoSavedSettings;
	//imgui_window_flags |= ImGuiWindowFlags_NoTitleBar;
	imgui_window_flags |= ImGuiWindowFlags_NoMove;
	imgui_window_flags |= ImGuiWindowFlags_NoResize;
	imgui_window_flags |= ImGuiWindowFlags_NoScrollbar;
	imgui_window_flags |= ImGuiWindowFlags_NoScrollWithMouse;
	if (ImGui::Begin("##mandrill", &g_window_open, imgui_window_flags))
	{
		draw_memory_explorer();
	}
	ImGui::End();

	ImGui::ShowDemoWindow();
	mandrill_theme_pop();
}
