
constexpr bool primitive_display_scalar(e_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case e_primitive_type::Int8:
	case e_primitive_type::Int16:
	case e_primitive_type::Int32:
	case e_primitive_type::Int64:
	case e_primitive_type::UInt8:
	case e_primitive_type::UInt16:
	case e_primitive_type::UInt32:
	case e_primitive_type::UInt64:
	case e_primitive_type::Float:
	case e_primitive_type::Double:
	case e_primitive_type::Boolean8:
	case e_primitive_type::Boolean16:
	case e_primitive_type::Boolean32:
	case e_primitive_type::Boolean64:
	case e_primitive_type::Enum8:
	case e_primitive_type::Enum16:
	case e_primitive_type::Enum32:
	case e_primitive_type::Enum64:
	case e_primitive_type::Undefined8:
	case e_primitive_type::Undefined16:
	case e_primitive_type::Undefined32:
	case e_primitive_type::Undefined64:
		return true;
	}
	return false;
}

constexpr bool primitive_display_bitfield(e_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case e_primitive_type::BitField8:
	case e_primitive_type::BitField16:
	case e_primitive_type::BitField32:
	case e_primitive_type::BitField64:
		return true;
	}
	return false;
}

constexpr bool primitive_display_bitflag(e_primitive_type primitive_type)
{
	switch (primitive_type)
	{
	case e_primitive_type::BitFlag8:
	case e_primitive_type::BitFlag16:
	case e_primitive_type::BitFlag32:
	case e_primitive_type::BitFlag64:
		return true;
	}
	return false;
}

template<e_primitive_type primitive_type, typename T>
void render_primitive_gui(void* field_data, const c_reflection_field& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	const char* pFieldTypeName = e_primitive_typeToString(primitive_type);

	ImGui::PushID(field_data);

	ImGui::Columns(3, NULL, false);
	ImGui::SetColumnOffset(1, c_mantle_tag_gui_tab::g_current_recursion_padding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.nice_name);
	ImGui::NextColumn();
	ImGui::SetColumnWidth(2, 500);

	if constexpr (primitive_display_scalar(primitive_type))
	{
		ImGuiDataType imguiDataType = e_primitive_typeToImGuiDataType(primitive_type);
		ImGui::InputScalar(pFieldTypeName, imguiDataType, field_data);
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
			ImGui::CheckboxFlags(pFieldTypeName, pFieldBitFieldDataPointer, bitmask);
		}
		ImGui::Text("#BitField END");
	}

	if constexpr (primitive_display_bitflag(primitive_type))
	{
		uint32_t* pFieldBitFlagDataPointer = static_cast<uint32_t*>(field_data);
		int bitmask = 1; // #TODO: Get a correct bitmask
		ImGui::CheckboxFlags(pFieldTypeName, pFieldBitFlagDataPointer, bitmask);
	}

	if constexpr (primitive_type == e_primitive_type::RawCharacter)
	{
		char* string_data = static_cast<char*>(field_data);
		ImGui::InputText("char[]", string_data, reflection_field.array_size);
	}

	if constexpr (primitive_type == e_primitive_type::RawWideCharacter)
	{
		static char buffer[256] = {};
		ImGui::InputText("wchar_t[]", buffer, 0);
	}

	if constexpr (primitive_type == e_primitive_type::StaticString)
	{
		//char* string_data = static_cast<c_static_string<>>(field_data);
		static char buffer[256] = {};
		ImGui::InputText("ascii", buffer, 0);
	}

	if constexpr (primitive_type == e_primitive_type::StaticWideString)
	{
		static char buffer[256] = {};
		ImGui::InputText("unicode", buffer, 0);
	}
	
	ImGui::Columns(1);

	ImGui::PopID();
}

template void render_primitive_gui<e_primitive_type::Int8, int8_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Int16, int16_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Int32, int32_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Int64, int64_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::UInt8, uint8_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::UInt16, uint16_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::UInt32, uint32_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::UInt64, uint64_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Float, float>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Double, double>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Boolean8, bool8_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Boolean16, bool16_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Boolean32, bool32_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Boolean64, bool64_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Enum8, enum8_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Enum16, enum16_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Enum32, enum32_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Enum64, enum64_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitField8, bitfield8_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitField16, bitfield16_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitField32, bitfield32_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitField64, bitfield64_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitFlag8, bitflag8_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitFlag16, bitflag16_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitFlag32, bitflag32_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::BitFlag64, bitflag64_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Undefined8, Undefined8>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Undefined16, Undefined16>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Undefined32, Undefined32>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::Undefined64, Undefined64>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::RawCharacter, char>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::RawWideCharacter, wchar_t>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::StaticString, char>(void* field_data, const c_reflection_field& reflection_field);
template void render_primitive_gui<e_primitive_type::StaticWideString, wchar_t>(void* field_data, const c_reflection_field& reflection_field);

