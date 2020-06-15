
constexpr bool primitive_display_scalar(e_legacy_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case _legacy_primitive_type_int8:
	case _legacy_primitive_type_int16:
	case _legacy_primitive_type_int32:
	case _legacy_primitive_type_int64:
	case _legacy_primitive_type_uint8:
	case _legacy_primitive_type_uint16:
	case _legacy_primitive_type_uint32:
	case _legacy_primitive_type_uint64:
	case _legacy_primitive_type_float:
	case _legacy_primitive_type_double:
	case _legacy_primitive_type_boolean8:
	case _legacy_primitive_type_boolean16:
	case _legacy_primitive_type_boolean32:
	case _legacy_primitive_type_boolean64:
	case _legacy_primitive_type_enum8:
	case _legacy_primitive_type_enum16:
	case _legacy_primitive_type_enum32:
	case _legacy_primitive_type_enum64:
	case _legacy_primitive_type_undefined8:
	case _legacy_primitive_type_undefined16:
	case _legacy_primitive_type_undefined32:
	case _legacy_primitive_type_undefined64:
		return true;
	}
	return false;
}

constexpr bool primitive_display_bitfield(e_legacy_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case _legacy_primitive_type_bitfield8:
	case _legacy_primitive_type_bitfield16:
	case _legacy_primitive_type_bitfield32:
	case _legacy_primitive_type_bitfield64:
		return true;
	}
	return false;
}

constexpr bool primitive_display_bitflag(e_legacy_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case _legacy_primitive_type_bitflag8:
	case _legacy_primitive_type_bitflag16:
	case _legacy_primitive_type_bitflag32:
	case _legacy_primitive_type_bitflag64:
		return true;
	}
	return false;
}

template<e_legacy_primitive_type primitive_type, typename T>
void render_primitive_gui_legacy(void* field_data, const c_reflection_field_legacy& reflection_field)
{
	bool unknownItemsVisible = c_old_mandrill_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	//const char* field_type_name = primitive_type_to_string(primitive_type);
	const char* field_type_name = reflection_field.type_info.type_nice_name;

	ImGui::PushID(field_data);

	ImGui::Columns(3, NULL, false);
	ImGui::SetColumnOffset(1, c_mandrill_legacy_tag_editor_gui_tab::g_current_recursion_padding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.nice_name);
	ImGui::NextColumn();
	ImGui::SetColumnWidth(2, 500);

	if constexpr (primitive_display_scalar(primitive_type))
	{
		ImGuiDataType imguiDataType = primitive_type_to_imgui_data_type(primitive_type);
		ImGui::InputScalar(field_type_name, imguiDataType, field_data);
	}

	if constexpr (primitive_display_bitfield(primitive_type))
	{
		// #TODO: This is absolutely horrible way to edit this data and we should write
		// an imgui scalar command that works with bitfields

		uint32_t* pFieldBitFieldDataPointer = static_cast<uint32_t*>(field_data);
		ImGui::Text("#BitField START");
		int bitfieldStart = 0;
		int bitfieldEnd = 1;
		for (int i = bitfieldStart; i < bitfieldEnd; i++)
		{
			int bitmask = 1 << i;
			ImGui::CheckboxFlags(field_type_name, pFieldBitFieldDataPointer, bitmask);
		}
		ImGui::Text("#BitField END");
	}

	if constexpr (primitive_display_bitflag(primitive_type))
	{
		uint32_t* pFieldBitFlagDataPointer = static_cast<uint32_t*>(field_data);
		int bitmask = 1; // #TODO: Get a correct bitmask
		ImGui::CheckboxFlags(field_type_name, pFieldBitFlagDataPointer, bitmask);
	}

	if constexpr (primitive_type == _legacy_primitive_type_char8)
	{
		char* string_data = static_cast<char*>(field_data);
		ImGui::InputText("char[]", string_data, reflection_field.array_size);
	}

	if constexpr (primitive_type == _legacy_primitive_type_char16)
	{
		static char buffer[256] = {};
		ImGui::InputText("wchar_t[]", buffer, 0);
	}

	if constexpr (primitive_type == _legacy_primitive_type_static_string8)
	{
		//char* string_data = static_cast<c_static_string<>>(field_data);
		static char buffer[256] = {};
		ImGui::InputText("ascii", buffer, 0);
	}

	if constexpr (primitive_type == _legacy_primitive_type_static_string16)
	{
		static char buffer[256] = {};
		ImGui::InputText("unicode", buffer, 0);
	}
	
	ImGui::Columns(1);

	ImGui::PopID();
}

template void render_primitive_gui_legacy<_legacy_primitive_type_int8, int8_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_int16, int16_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_int32, int32_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_int64, int64_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_uint8, uint8_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_uint16, uint16_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_uint32, uint32_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_uint64, uint64_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_float, float>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_float, double>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_boolean8, bool8_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_boolean16, bool16_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_boolean32, bool32_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_boolean64, bool64_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_enum8, enum8_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_enum16, enum16_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_enum32, enum32_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_enum64, enum64_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitfield8, bitfield8_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitfield16, bitfield16_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitfield32, bitfield32_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitfield64, bitfield64_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitflag8, bitflag8_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitflag16, bitflag16_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitflag32, bitflag32_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_bitflag64, bitflag64_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_undefined8, s_undefined8_legacy>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_undefined16, s_undefined16_legacy>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_undefined32, s_undefined32_legacy>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_undefined64, s_undefined64_legacy>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_char8, char>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_char16, wchar_t>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_static_string8, char>(void* field_data, const c_reflection_field_legacy& reflection_field);
template void render_primitive_gui_legacy<_legacy_primitive_type_static_string16, wchar_t>(void* field_data, const c_reflection_field_legacy& reflection_field);

