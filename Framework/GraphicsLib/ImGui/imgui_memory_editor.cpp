#include "graphicslib-private-pch.h"

#define _PRISizeT   "I"

enum DataFormat
{
	DataFormat_Bin = 0,
	DataFormat_Dec = 1,
	DataFormat_Hex = 2,
	DataFormat_COUNT
};

struct s_memory_editor_state
{
	// [Internal State]
	size_t          DataPreviewAddr;
	size_t          DataEditingAddr;
	size_t          GotoAddr;
	size_t          HighlightMin;
	size_t          HighlightMax;
	ImGuiDataType   PreviewDataType;
	int             PreviewEndianess;
	bool            ContentsWidthChanged;
	bool            DataEditingTakeFocus;
	char            DataInputBuf[32];
	char            AddrInputBuf[32];
};

struct Sizes
{
	int     AddrDigitsCount;
	float   LineHeight;
	float   GlyphWidth;
	float   HexCellWidth;
	float   SpacingBetweenMidCols;
	float   PosHexStart;
	float   PosHexEnd;
	float   PosAsciiStart;
	float   PosAsciiEnd;
	float   WindowWidth;

	Sizes() { memset(this, 0, sizeof(*this)); }
};

s_imgui_memory_editor_settings::s_imgui_memory_editor_settings()
{
	Open = true; // set to false when DrawWindow() was closed. ignore if not using DrawWindow().
	ReadOnly = false; // disable any editing.
	Cols = 16; // number of columns to display.
	OptShowOptions = true; // display options button/context menu. when disabled, options will be locked unless you provide your own UI for them.
	OptShowDataPreview = false; // display a footer previewing the decimal/binary/hex/float representation of the currently selected bytes.
	OptShowHexII = false; // display values in HexII representation instead of regular hexadecimal: hide null/zero bytes, ascii values as ".X".
	OptShowAscii = true; // display ASCII representation on the right side.
	OptGreyOutZeroes = true; // display null/zero bytes using the TextDisabled color.
	OptUpperCaseHex = true; // display hexadecimal values as "FF" instead of "ff".
	OptMidColsCount = 8; // set to 0 to disable extra spacing between every mid-cols.
	OptAddrDigitsCount = 0; // number of addr digits to display (default calculated based on maximum displayed addr).
	OptFooterExtraHeight = 0; // space to reserve at the bottom of the widget to add custom widgets
}

static void CalcSizes(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, Sizes& s, size_t mem_size, size_t base_display_addr)
{
	ImGuiStyle& style = ImGui::GetStyle();
	s.AddrDigitsCount = settings.OptAddrDigitsCount;
	if (s.AddrDigitsCount == 0)
		for (size_t n = base_display_addr + mem_size - 1; n > 0; n >>= 4)
			s.AddrDigitsCount++;
	s.LineHeight = ImGui::GetTextLineHeight();
	s.GlyphWidth = ImGui::CalcTextSize("F").x + 1;                  // We assume the font is mono-space
	s.HexCellWidth = (float)(int)(s.GlyphWidth * 2.5f);             // "FF " we include trailing space in the width to easily catch clicks everywhere
	s.SpacingBetweenMidCols = (float)(int)(s.HexCellWidth * 0.25f); // Every settings.OptMidColsCount columns we add a bit of extra spacing
	s.PosHexStart = (s.AddrDigitsCount + 2) * s.GlyphWidth;
	s.PosHexEnd = s.PosHexStart + (s.HexCellWidth * settings.Cols);
	s.PosAsciiStart = s.PosAsciiEnd = s.PosHexEnd;
	if (settings.OptShowAscii)
	{
		s.PosAsciiStart = s.PosHexEnd + s.GlyphWidth * 1;
		if (settings.OptMidColsCount > 0)
			s.PosAsciiStart += (float)((settings.Cols + settings.OptMidColsCount - 1) / settings.OptMidColsCount) * s.SpacingBetweenMidCols;
		s.PosAsciiEnd = s.PosAsciiStart + settings.Cols * s.GlyphWidth;
	}
	s.WindowWidth = s.PosAsciiEnd + style.ScrollbarSize + style.WindowPadding.x * 2 + s.GlyphWidth;
}

static size_t DataTypeGetSize(ImGuiDataType data_type)
{
	const size_t sizes[] = { 1, 1, 2, 2, 4, 4, 8, 8, sizeof(float), sizeof(double) };
	IM_ASSERT(data_type >= 0 && data_type < ImGuiDataType_COUNT);
	return sizes[data_type];
}

// Utilities for Data Preview
static const char* DataTypeGetDesc(ImGuiDataType data_type)
{
	const char* descs[] = { "Int8", "Uint8", "Int16", "Uint16", "Int32", "Uint32", "Int64", "Uint64", "Float", "Double" };
	IM_ASSERT(data_type >= 0 && data_type < ImGuiDataType_COUNT);
	return descs[data_type];
}

static void DrawOptionsLine(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, const Sizes& s, void* mem_data, size_t mem_size, size_t base_display_addr)
{
	IM_UNUSED(mem_data);
	ImGuiStyle& style = ImGui::GetStyle();
	const char* format_range = settings.OptUpperCaseHex ? "Range %0*" _PRISizeT "X..%0*" _PRISizeT "X" : "Range %0*" _PRISizeT "x..%0*" _PRISizeT "x";

	// Options menu
	if (ImGui::Button("Options"))
		ImGui::OpenPopup("context");
	if (ImGui::BeginPopup("context"))
	{
		ImGui::SetNextItemWidth(s.GlyphWidth * 7 + style.FramePadding.x * 2.0f);
		if (ImGui::DragInt("##cols", &settings.Cols, 0.2f, 4, 32, "%d cols")) { state.ContentsWidthChanged = true; if (settings.Cols < 1) settings.Cols = 1; }
		ImGui::Checkbox("Show Data Preview", &settings.OptShowDataPreview);
		ImGui::Checkbox("Show HexII", &settings.OptShowHexII);
		if (ImGui::Checkbox("Show Ascii", &settings.OptShowAscii)) { state.ContentsWidthChanged = true; }
		ImGui::Checkbox("Grey out zeroes", &settings.OptGreyOutZeroes);
		ImGui::Checkbox("Uppercase Hex", &settings.OptUpperCaseHex);

		ImGui::EndPopup();
	}

	ImGui::SameLine();
	ImGui::Text(format_range, s.AddrDigitsCount, base_display_addr, s.AddrDigitsCount, base_display_addr + mem_size - 1);
	ImGui::SameLine();
	ImGui::SetNextItemWidth((s.AddrDigitsCount + 1) * s.GlyphWidth + style.FramePadding.x * 2.0f);
	if (ImGui::InputText("##addr", state.AddrInputBuf, IM_ARRAYSIZE(state.AddrInputBuf), ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_EnterReturnsTrue))
	{
		size_t goto_addr;
		if (sscanf(state.AddrInputBuf, "%" _PRISizeT "X", &goto_addr) == 1)
		{
			state.GotoAddr = goto_addr - base_display_addr;
			state.HighlightMin = state.HighlightMax = (size_t)-1;
		}
	}

	if (state.GotoAddr != (size_t)-1)
	{
		if (state.GotoAddr < mem_size)
		{
			ImGui::BeginChild("##scrolling");
			ImGui::SetScrollFromPosY(ImGui::GetCursorStartPos().y + (state.GotoAddr / settings.Cols) * ImGui::GetTextLineHeight());
			ImGui::EndChild();
			state.DataEditingAddr = state.DataPreviewAddr = state.GotoAddr;
			state.DataEditingTakeFocus = true;
		}
		state.GotoAddr = (size_t)-1;
	}
}

static bool IsBigEndian()
{
	uint16_t x = 1;
	char c[2];
	memcpy(c, &x, 2);
	return c[0] != 0;
}

static void* EndianessCopyBigEndian(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, void* _dst, void* _src, size_t s, int is_little_endian)
{
	if (is_little_endian)
	{
		uint8_t* dst = (uint8_t*)_dst;
		uint8_t* src = (uint8_t*)_src + s - 1;
		for (int i = 0, n = (int)s; i < n; ++i)
			memcpy(dst++, src--, 1);
		return _dst;
	}
	else
	{
		return memcpy(_dst, _src, s);
	}
}

static void* EndianessCopyLittleEndian(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, void* _dst, void* _src, size_t s, int is_little_endian)
{
	if (is_little_endian)
	{
		return memcpy(_dst, _src, s);
	}
	else
	{
		uint8_t* dst = (uint8_t*)_dst;
		uint8_t* src = (uint8_t*)_src + s - 1;
		for (int i = 0, n = (int)s; i < n; ++i)
			memcpy(dst++, src--, 1);
		return _dst;
	}
}

static void* EndianessCopy(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, void* dst, void* src, size_t size)
{
	static void* (*fp)(s_memory_editor_state&, s_imgui_memory_editor_settings&, void*, void*, size_t, int) = NULL;
	if (fp == NULL)
		fp = IsBigEndian() ? EndianessCopyBigEndian : EndianessCopyLittleEndian;
	return fp(state, settings, dst, src, size, state.PreviewEndianess);
}

static const char* FormatBinary(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, const uint8_t* buf, int width)
{
	IM_ASSERT(width <= 64);
	size_t out_n = 0;
	static char out_buf[64 + 8 + 1];
	int n = width / 8;
	for (int j = n - 1; j >= 0; --j)
	{
		for (int i = 0; i < 8; ++i)
			out_buf[out_n++] = (buf[j] & (1 << (7 - i))) ? '1' : '0';
		out_buf[out_n++] = ' ';
	}
	IM_ASSERT(out_n < IM_ARRAYSIZE(out_buf));
	out_buf[out_n] = 0;
	return out_buf;
}

// [Internal]
static void DrawPreviewData(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, size_t addr, const ImU8* mem_data, size_t mem_size, ImGuiDataType data_type, DataFormat data_format, char* out_buf, size_t out_buf_size)
{
	uint8_t buf[8];
	size_t elem_size = DataTypeGetSize(data_type);
	size_t size = addr + elem_size > mem_size ? mem_size - addr : elem_size;
	if (settings.ReadFn)
		for (int i = 0, n = (int)size; i < n; ++i)
			buf[i] = settings.ReadFn(mem_data, addr + i);
	else
		memcpy(buf, mem_data + addr, size);

	if (data_format == DataFormat_Bin)
	{
		uint8_t binbuf[8];
		EndianessCopy(state, settings, binbuf, buf, size);
		snprintf(out_buf, out_buf_size, "%s", FormatBinary(state, settings, binbuf, (int)size * 8));
		return;
	}

	out_buf[0] = 0;
	switch (data_type)
	{
	case ImGuiDataType_S8:
	{
		int8_t int8 = 0;
		EndianessCopy(state, settings, &int8, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%hhd", int8); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%02x", int8 & 0xFF); return; }
		break;
	}
	case ImGuiDataType_U8:
	{
		uint8_t uint8 = 0;
		EndianessCopy(state, settings, &uint8, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%hhu", uint8); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%02x", uint8 & 0XFF); return; }
		break;
	}
	case ImGuiDataType_S16:
	{
		int16_t int16 = 0;
		EndianessCopy(state, settings, &int16, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%hd", int16); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%04x", int16 & 0xFFFF); return; }
		break;
	}
	case ImGuiDataType_U16:
	{
		uint16_t uint16 = 0;
		EndianessCopy(state, settings, &uint16, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%hu", uint16); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%04x", uint16 & 0xFFFF); return; }
		break;
	}
	case ImGuiDataType_S32:
	{
		int32_t int32 = 0;
		EndianessCopy(state, settings, &int32, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%d", int32); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%08x", int32); return; }
		break;
	}
	case ImGuiDataType_U32:
	{
		uint32_t uint32 = 0;
		EndianessCopy(state, settings, &uint32, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%u", uint32); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%08x", uint32); return; }
		break;
	}
	case ImGuiDataType_S64:
	{
		int64_t int64 = 0;
		EndianessCopy(state, settings, &int64, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%lld", (int64_t)int64); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%016llx", (int64_t)int64); return; }
		break;
	}
	case ImGuiDataType_U64:
	{
		uint64_t uint64 = 0;
		EndianessCopy(state, settings, &uint64, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%llu", (int64_t)uint64); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "0x%016llx", (int64_t)uint64); return; }
		break;
	}
	case ImGuiDataType_Float:
	{
		float float32 = 0.0f;
		EndianessCopy(state, settings, &float32, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%f", float32); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "%a", float32); return; }
		break;
	}
	case ImGuiDataType_Double:
	{
		double float64 = 0.0;
		EndianessCopy(state, settings, &float64, buf, size);
		if (data_format == DataFormat_Dec) { snprintf(out_buf, out_buf_size, "%f", float64); return; }
		if (data_format == DataFormat_Hex) { snprintf(out_buf, out_buf_size, "%a", float64); return; }
		break;
	}
	case ImGuiDataType_COUNT:
		break;
	} // Switch
	IM_ASSERT(0); // Shouldn't reach
}

static void DrawPreviewLine(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, const Sizes& s, void* mem_data_void, size_t mem_size, size_t base_display_addr)
{
	IM_UNUSED(base_display_addr);
	ImU8* mem_data = (ImU8*)mem_data_void;
	ImGuiStyle& style = ImGui::GetStyle();
	ImGui::AlignTextToFramePadding();
	ImGui::Text("Preview as:");
	ImGui::SameLine();
	ImGui::SetNextItemWidth((s.GlyphWidth * 10.0f) + style.FramePadding.x * 2.0f + style.ItemInnerSpacing.x);
	if (ImGui::BeginCombo("##combo_type", DataTypeGetDesc(state.PreviewDataType), ImGuiComboFlags_HeightLargest))
	{
		for (int n = 0; n < ImGuiDataType_COUNT; n++)
			if (ImGui::Selectable(DataTypeGetDesc((ImGuiDataType)n), state.PreviewDataType == n))
				state.PreviewDataType = (ImGuiDataType)n;
		ImGui::EndCombo();
	}
	ImGui::SameLine();
	ImGui::SetNextItemWidth((s.GlyphWidth * 6.0f) + style.FramePadding.x * 2.0f + style.ItemInnerSpacing.x);
	ImGui::Combo("##combo_endianess", &state.PreviewEndianess, "LE\0BE\0\0");

	char buf[128] = "";
	float x = s.GlyphWidth * 6.0f;
	bool has_value = state.DataPreviewAddr != (size_t)-1;
	if (has_value)
		DrawPreviewData(state, settings, state.DataPreviewAddr, mem_data, mem_size, state.PreviewDataType, DataFormat_Dec, buf, (size_t)IM_ARRAYSIZE(buf));
	ImGui::Text("Dec"); ImGui::SameLine(x); ImGui::TextUnformatted(has_value ? buf : "N/A");
	if (has_value)
		DrawPreviewData(state, settings, state.DataPreviewAddr, mem_data, mem_size, state.PreviewDataType, DataFormat_Hex, buf, (size_t)IM_ARRAYSIZE(buf));
	ImGui::Text("Hex"); ImGui::SameLine(x); ImGui::TextUnformatted(has_value ? buf : "N/A");
	if (has_value)
		DrawPreviewData(state, settings, state.DataPreviewAddr, mem_data, mem_size, state.PreviewDataType, DataFormat_Bin, buf, (size_t)IM_ARRAYSIZE(buf));
	buf[IM_ARRAYSIZE(buf) - 1] = 0;
	ImGui::Text("Bin"); ImGui::SameLine(x); ImGui::TextUnformatted(has_value ? buf : "N/A");
}

// Memory Editor contents only
static void DrawContents(s_memory_editor_state& state, s_imgui_memory_editor_settings& settings, void* userdata, void* mem_data_void, size_t mem_size, size_t base_display_addr = 0x0000)
{
	if (settings.Cols < 1)
		settings.Cols = 1;

	ImU8* mem_data = (ImU8*)mem_data_void;
	Sizes s;
	CalcSizes(state, settings, s, mem_size, base_display_addr);
	ImGuiStyle& style = ImGui::GetStyle();

	// We begin into our scrolling region with the 'ImGuiWindowFlags_NoMove' in order to prevent click from moving the window.
	// This is used as a facility since our main click detection code doesn't assign an ActiveId so the click would normally be caught as a window-move.
	const float height_separator = style.ItemSpacing.y;
	float footer_height = settings.OptFooterExtraHeight;
	if (settings.OptShowOptions)
		footer_height += height_separator + ImGui::GetFrameHeightWithSpacing() * 1;
	if (settings.OptShowDataPreview)
		footer_height += height_separator + ImGui::GetFrameHeightWithSpacing() * 1 + ImGui::GetTextLineHeightWithSpacing() * 3;
	ImGui::BeginChild("##scrolling", ImVec2(0, -footer_height), false, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoNav);
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

	// We are not really using the clipper API correctly here, because we rely on visible_start_addr/visible_end_addr for our scrolling function.
	const int line_total_count = (int)((mem_size + settings.Cols - 1) / settings.Cols);
	ImGuiListClipper clipper;
	clipper.Begin(line_total_count, s.LineHeight);
	clipper.Step();
	const size_t visible_start_addr = clipper.DisplayStart * settings.Cols;
	const size_t visible_end_addr = clipper.DisplayEnd * settings.Cols;

	bool data_next = false;

	if (settings.ReadOnly || state.DataEditingAddr >= mem_size)
		state.DataEditingAddr = (size_t)-1;
	if (state.DataPreviewAddr >= mem_size)
		state.DataPreviewAddr = (size_t)-1;

	size_t preview_data_type_size = settings.OptShowDataPreview ? DataTypeGetSize(state.PreviewDataType) : 0;

	size_t data_editing_addr_backup = state.DataEditingAddr;
	size_t data_editing_addr_next = (size_t)-1;
	if (state.DataEditingAddr != (size_t)-1)
	{
		// Move cursor but only apply on next frame so scrolling with be synchronized (because currently we can't change the scrolling while the window is being rendered)
		if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_UpArrow)) && state.DataEditingAddr >= (size_t)settings.Cols) { data_editing_addr_next = state.DataEditingAddr - settings.Cols; state.DataEditingTakeFocus = true; }
		else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_DownArrow)) && state.DataEditingAddr < mem_size - settings.Cols) { data_editing_addr_next = state.DataEditingAddr + settings.Cols; state.DataEditingTakeFocus = true; }
		else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_LeftArrow)) && state.DataEditingAddr > 0) { data_editing_addr_next = state.DataEditingAddr - 1; state.DataEditingTakeFocus = true; }
		else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_RightArrow)) && state.DataEditingAddr < mem_size - 1) { data_editing_addr_next = state.DataEditingAddr + 1; state.DataEditingTakeFocus = true; }
	}
	if (data_editing_addr_next != (size_t)-1 && (data_editing_addr_next / settings.Cols) != (data_editing_addr_backup / settings.Cols))
	{
		// Track cursor movements
		const int scroll_offset = ((int)(data_editing_addr_next / settings.Cols) - (int)(data_editing_addr_backup / settings.Cols));
		const bool scroll_desired = (scroll_offset < 0 && data_editing_addr_next < visible_start_addr + settings.Cols * 2) || (scroll_offset > 0 && data_editing_addr_next > visible_end_addr - settings.Cols * 2);
		if (scroll_desired)
			ImGui::SetScrollY(ImGui::GetScrollY() + scroll_offset * s.LineHeight);
	}

	// Draw vertical separator
	ImVec2 window_pos = ImGui::GetWindowPos();
	if (settings.OptShowAscii)
		draw_list->AddLine(ImVec2(window_pos.x + s.PosAsciiStart - s.GlyphWidth, window_pos.y), ImVec2(window_pos.x + s.PosAsciiStart - s.GlyphWidth, window_pos.y + 9999), ImGui::GetColorU32(ImGuiCol_Border));

	const ImU32 color_text = ImGui::GetColorU32(ImGuiCol_Text);
	const ImU32 color_disabled = settings.OptGreyOutZeroes ? ImGui::GetColorU32(ImGuiCol_TextDisabled) : color_text;

	const char* format_address = settings.OptUpperCaseHex ? "%0*" _PRISizeT "X: " : "%0*" _PRISizeT "x: ";
	const char* format_data = settings.OptUpperCaseHex ? "%0*" _PRISizeT "X" : "%0*" _PRISizeT "x";
	const char* format_byte = settings.OptUpperCaseHex ? "%02X" : "%02x";
	const char* format_byte_space = settings.OptUpperCaseHex ? "%02X " : "%02x ";

	for (int line_i = clipper.DisplayStart; line_i < clipper.DisplayEnd; line_i++) // display only visible lines
	{
		size_t addr = (size_t)(line_i * settings.Cols);
		ImGui::Text(format_address, s.AddrDigitsCount, base_display_addr + addr);

		// Draw Hexadecimal
		for (int n = 0; n < settings.Cols && addr < mem_size; n++, addr++)
		{
			float byte_pos_x = s.PosHexStart + s.HexCellWidth * n;
			if (settings.OptMidColsCount > 0)
				byte_pos_x += (float)(n / settings.OptMidColsCount) * s.SpacingBetweenMidCols;
			ImGui::SameLine(byte_pos_x);

			// Draw highlight
			bool is_highlight_from_user_range = (addr >= state.HighlightMin && addr < state.HighlightMax);
			bool is_highlight_from_user_func = (settings.HighlightFn && settings.HighlightFn(mem_data, addr));
			bool is_highlight_from_preview = (addr >= state.DataPreviewAddr && addr < state.DataPreviewAddr + preview_data_type_size);
			if (is_highlight_from_user_range || is_highlight_from_user_func || is_highlight_from_preview)
			{
				ImVec2 pos = ImGui::GetCursorScreenPos();
				float highlight_width = s.GlyphWidth * 2;
				bool is_next_byte_highlighted = (addr + 1 < mem_size) && ((state.HighlightMax != (size_t)-1 && addr + 1 < state.HighlightMax) || (settings.HighlightFn && settings.HighlightFn(mem_data, addr + 1)));
				if (is_next_byte_highlighted || (n + 1 == settings.Cols))
				{
					highlight_width = s.HexCellWidth;
					if (settings.OptMidColsCount > 0 && n > 0 && (n + 1) < settings.Cols && ((n + 1) % settings.OptMidColsCount) == 0)
						highlight_width += s.SpacingBetweenMidCols;
				}
				draw_list->AddRectFilled(pos, ImVec2(pos.x + highlight_width, pos.y + s.LineHeight), settings.HighlightColor);
			}

			if (state.DataEditingAddr == addr)
			{
				// Display text input on current byte
				bool data_write = false;
				ImGui::PushID((void*)addr);
				if (state.DataEditingTakeFocus)
				{
					ImGui::SetKeyboardFocusHere();
					ImGui::CaptureKeyboardFromApp(true);
					sprintf(state.AddrInputBuf, format_data, s.AddrDigitsCount, base_display_addr + addr);
					sprintf(state.DataInputBuf, format_byte, settings.ReadFn ? settings.ReadFn(mem_data, addr) : mem_data[addr]);
				}
				struct UserData
				{
					// FIXME: We should have a way to retrieve the text edit cursor position more easily in the API, this is rather tedious. This is such a ugly mess we may be better off not using InputText() at all here.
					static int Callback(ImGuiInputTextCallbackData* data)
					{
						UserData* user_data = (UserData*)data->UserData;
						if (!data->HasSelection())
							user_data->CursorPos = data->CursorPos;
						if (data->SelectionStart == 0 && data->SelectionEnd == data->BufTextLen)
						{
							// When not editing a byte, always rewrite its content (this is a bit tricky, since InputText technically "owns" the master copy of the buffer we edit it in there)
							data->DeleteChars(0, data->BufTextLen);
							data->InsertChars(0, user_data->CurrentBufOverwrite);
							data->SelectionStart = 0;
							data->SelectionEnd = 2;
							data->CursorPos = 0;
						}
						return 0;
					}
					char   CurrentBufOverwrite[3];  // Input
					int    CursorPos;               // Output
				};
				UserData user_data;
				user_data.CursorPos = -1;
				sprintf(user_data.CurrentBufOverwrite, format_byte, settings.ReadFn ? settings.ReadFn(mem_data, addr) : mem_data[addr]);
				ImGuiInputTextFlags flags = ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_NoHorizontalScroll | ImGuiInputTextFlags_CallbackAlways;
#if IMGUI_VERSION_NUM >= 18104
				flags |= ImGuiInputTextFlags_AlwaysOverwrite;
#else
				flags |= ImGuiInputTextFlags_AlwaysInsertMode;
#endif
				ImGui::SetNextItemWidth(s.GlyphWidth * 2);
				if (ImGui::InputText("##data", state.DataInputBuf, IM_ARRAYSIZE(state.DataInputBuf), flags, UserData::Callback, &user_data))
					data_write = data_next = true;
				else if (!state.DataEditingTakeFocus && !ImGui::IsItemActive())
					state.DataEditingAddr = data_editing_addr_next = (size_t)-1;
				state.DataEditingTakeFocus = false;
				if (user_data.CursorPos >= 2)
					data_write = data_next = true;
				if (data_editing_addr_next != (size_t)-1)
					data_write = data_next = false;
				unsigned int data_input_value = 0;
				if (data_write && sscanf(state.DataInputBuf, "%X", &data_input_value) == 1)
				{
					if (settings.WriteFn)
						settings.WriteFn(mem_data, addr, (ImU8)data_input_value);
					else
						mem_data[addr] = (ImU8)data_input_value;
				}
				ImGui::PopID();
			}
			else
			{
				// NB: The trailing space is not visible but ensure there's no gap that the mouse cannot click on.
				ImU8 b = settings.ReadFn ? settings.ReadFn(mem_data, addr) : mem_data[addr];

				if (settings.OptShowHexII)
				{
					if ((b >= 32 && b < 128))
						ImGui::Text(".%c ", b);
					else if (b == 0xFF && settings.OptGreyOutZeroes)
						ImGui::TextDisabled("## ");
					else if (b == 0x00)
						ImGui::Text("   ");
					else
						ImGui::Text(format_byte_space, b);
				}
				else
				{
					if (b == 0 && settings.OptGreyOutZeroes)
						ImGui::TextDisabled("00 ");
					else
						ImGui::Text(format_byte_space, b);
				}
				if (!settings.ReadOnly && ImGui::IsItemHovered() && ImGui::IsMouseClicked(0))
				{
					state.DataEditingTakeFocus = true;
					data_editing_addr_next = addr;
				}
			}
		}

		if (settings.OptShowAscii)
		{
			// Draw ASCII values
			ImGui::SameLine(s.PosAsciiStart);
			ImVec2 pos = ImGui::GetCursorScreenPos();
			addr = line_i * settings.Cols;
			ImGui::PushID(line_i);
			if (ImGui::InvisibleButton("ascii", ImVec2(s.PosAsciiEnd - s.PosAsciiStart, s.LineHeight)))
			{
				state.DataEditingAddr = state.DataPreviewAddr = addr + (size_t)((ImGui::GetIO().MousePos.x - pos.x) / s.GlyphWidth);
				state.DataEditingTakeFocus = true;
			}
			ImGui::PopID();
			for (int n = 0; n < settings.Cols && addr < mem_size; n++, addr++)
			{
				if (addr == state.DataEditingAddr)
				{
					draw_list->AddRectFilled(pos, ImVec2(pos.x + s.GlyphWidth, pos.y + s.LineHeight), ImGui::GetColorU32(ImGuiCol_FrameBg));
					draw_list->AddRectFilled(pos, ImVec2(pos.x + s.GlyphWidth, pos.y + s.LineHeight), ImGui::GetColorU32(ImGuiCol_TextSelectedBg));
				}
				unsigned char c = settings.ReadFn ? settings.ReadFn(mem_data, addr) : mem_data[addr];
				char display_c = (c < 32 || c >= 128) ? '.' : c;
				draw_list->AddText(pos, (display_c == c) ? color_text : color_disabled, &display_c, &display_c + 1);
				pos.x += s.GlyphWidth;
			}
		}
	}
	IM_ASSERT(clipper.Step() == false);
	clipper.End();
	ImGui::PopStyleVar(2);
	ImGui::EndChild();

	// Notify the main window of our ideal child content size (FIXME: we are missing an API to get the contents size from the child)
	ImGui::SetCursorPosX(s.WindowWidth);

	if (data_next && state.DataEditingAddr < mem_size)
	{
		state.DataEditingAddr = state.DataPreviewAddr = state.DataEditingAddr + 1;
		state.DataEditingTakeFocus = true;
	}
	else if (data_editing_addr_next != (size_t)-1)
	{
		state.DataEditingAddr = state.DataPreviewAddr = data_editing_addr_next;
	}



	if (settings.CustomUIFn || settings.OptShowOptions)
	{
		ImGui::Separator();
		if (settings.CustomUIFn)
		{
			settings.CustomUIFn(userdata, mem_data, mem_size);
		}
		if (settings.OptShowOptions)
		{
			DrawOptionsLine(state, settings, s, mem_data, mem_size, base_display_addr);
		}
	}

	const bool lock_show_data_preview = settings.OptShowDataPreview;
	if (lock_show_data_preview)
	{
		ImGui::Separator();
		DrawPreviewLine(state, settings, s, mem_data, mem_size, base_display_addr);
	}
}

void imgui_memory_editor(
	s_imgui_memory_editor_settings& settings,
	void* data,
	uint64_t data_size,
	void* userdata)
{
	ImGuiWindow* window = GImGui->CurrentWindow;
	ImGuiStorage* storage = window->DC.StateStorage;

	constexpr int entry_count = sizeof(s_memory_editor_state) / sizeof(void*);
	void** data_storage[entry_count];
	union
	{
		void* entry_data[entry_count];
		s_memory_editor_state memory_editor_state;
	};
	for (int index = 0; index < entry_count; index++)
	{
		ImGuiID data_storage_id = window->GetID(0xa110ca7e + index); // get the next hash id
		entry_data[index] = *(data_storage[index] = storage->GetVoidPtrRef(data_storage_id));
	}

	DrawContents(memory_editor_state, settings, userdata, data, data_size);

	for (int index = 0; index < entry_count; index++)
	{
		*data_storage[index] = entry_data[index];
	}
}
