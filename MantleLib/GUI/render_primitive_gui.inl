
constexpr bool primitive_display_scalar(PrimitiveType primitive_type)
{
	switch (primitive_type)
	{
	case PrimitiveType::Int8:
	case PrimitiveType::Int16:
	case PrimitiveType::Int32:
	case PrimitiveType::Int64:
	case PrimitiveType::UInt8:
	case PrimitiveType::UInt16:
	case PrimitiveType::UInt32:
	case PrimitiveType::UInt64:
	case PrimitiveType::Float:
	case PrimitiveType::Double:
	case PrimitiveType::Boolean8:
	case PrimitiveType::Boolean16:
	case PrimitiveType::Boolean32:
	case PrimitiveType::Boolean64:
	case PrimitiveType::Enum8:
	case PrimitiveType::Enum16:
	case PrimitiveType::Enum32:
	case PrimitiveType::Enum64:
	case PrimitiveType::Undefined8:
	case PrimitiveType::Undefined16:
	case PrimitiveType::Undefined32:
	case PrimitiveType::Undefined64:
		return true;
	}
	return false;
}

constexpr bool primitive_display_bitfield(PrimitiveType primitive_type)
{
	switch (primitive_type)
	{
	case PrimitiveType::BitField8:
	case PrimitiveType::BitField16:
	case PrimitiveType::BitField32:
	case PrimitiveType::BitField64:
		return true;
	}
	return false;
}

constexpr bool primitive_display_bitflag(PrimitiveType primitive_type)
{
	switch (primitive_type)
	{
	case PrimitiveType::BitFlag8:
	case PrimitiveType::BitFlag16:
	case PrimitiveType::BitFlag32:
	case PrimitiveType::BitFlag64:
		return true;
	}
	return false;
}

template<PrimitiveType primitive_type, typename T>
void render_primitive_gui(void* field_data, const ReflectionField& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.m_isHiddenByDefault) return; // skip hidden fields
	const char* pFieldTypeName = PrimitiveTypeToString(primitive_type);

	ImGui::PushID(field_data);

	ImGui::Columns(3, NULL, false);
	ImGui::SetColumnOffset(1, recursionPadding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.m_pMemberName);
	ImGui::NextColumn();
	ImGui::SetColumnWidth(2, 500);

	if constexpr (primitive_display_scalar(primitive_type))
	{
		ImGuiDataType imguiDataType = PrimitiveTypeToImGuiDataType(primitive_type);
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

	ImGui::Columns(1);

	ImGui::PopID();
}

template void render_primitive_gui<PrimitiveType::Int8, int8_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Int16, int16_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Int32, int32_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Int64, int64_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::UInt8, uint8_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::UInt16, uint16_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::UInt32, uint32_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::UInt64, uint64_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Float, float>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Double, double>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Boolean8, bool8_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Boolean16, bool16_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Boolean32, bool32_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Boolean64, bool64_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Enum8, enum8_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Enum16, enum16_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Enum32, enum32_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Enum64, enum64_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitField8, bitfield8_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitField16, bitfield16_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitField32, bitfield32_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitField64, bitfield64_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitFlag8, bitflag8_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitFlag16, bitflag16_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitFlag32, bitflag32_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::BitFlag64, bitflag64_t>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Undefined8, Undefined8>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Undefined16, Undefined16>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Undefined32, Undefined32>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Undefined64, Undefined64>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::Character, char>(void* field_data, const ReflectionField& reflection_field);
template void render_primitive_gui<PrimitiveType::WideCharacter, wchar_t>(void* field_data, const ReflectionField& reflection_field);

