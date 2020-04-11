
void render_bitfield_gui(void* field_data, const c_reflection_field& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	const char* pFieldTypeName = reflection_field.enum_info.type_nice_name;
	
	ImGui::PushID(field_data);

	ImGui::Columns(3, NULL, false);
	ImGui::SetColumnOffset(1, c_mantle_tag_gui_tab::g_current_recursion_padding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.nice_name);
	ImGui::NextColumn();
	ImGui::SetColumnWidth(2, 500);

	uint64_t current_value = 0;
	switch (reflection_field.enum_info.m_primitiveTypeIndex)
	{
	case _legacy_primitive_type_bitfield8:
		current_value = *reinterpret_cast<uint8_t*>(field_data);
		break;
	case _legacy_primitive_type_bitfield16:
		current_value = *reinterpret_cast<uint16_t*>(field_data);
		break;
	case _legacy_primitive_type_bitfield32:
		current_value = *reinterpret_cast<uint32_t*>(field_data);
		break;
	case _legacy_primitive_type_bitfield64:
		current_value = *reinterpret_cast<uint64_t*>(field_data);
		break;
	DEBUG_ONLY(default: throw);
	}

	class BitFieldDynamicData
	{
	public:
		BitFieldDynamicData(uint64_t value) :
			bools()
		{
			represented_value = ~value; // force update
			update(value);
		}
		bool bools[64];
		uint64_t represented_value;
		void update(uint64_t value)
		{
			for (uint64_t i = 0; i < 64; i++)
			{
				bools[i] = static_cast<bool>(value >> i & 1);
			}
			represented_value = value;
		}
	};
	static_assert(sizeof(BitFieldDynamicData) <= sizeof(c_mantle_tag_gui_tab::c_imgui_dynamic_data::second), "BitFieldDynamicData is too large");
	bool wasAllocated;
	BitFieldDynamicData& rBitFieldDynamicData = c_mantle_tag_gui_tab::g_current_mantle_tag_tab->get_dynamic_data<BitFieldDynamicData>(field_data, wasAllocated);
	if (wasAllocated) new(&rBitFieldDynamicData) BitFieldDynamicData(current_value);
	else rBitFieldDynamicData.update(current_value);

	uint32_t const enum_value_count = reflection_field.enum_info.reflection_enum_type->values_count;
	float const element_height = 30.0f;
	float height = __min(element_height * 9.5f, element_height * static_cast<float>(enum_value_count));
	if (ImGui::BeginChild("bitfield", ImVec2(500.0f, height)))
	{
		for (uint32_t enum_value_index = 0; enum_value_index < enum_value_count; enum_value_index++)
		{
			const s_reflection_enum_value& enum_value = reflection_field.enum_info.reflection_enum_type->values[enum_value_index];

			if (ImGui::Checkbox(enum_value.name, rBitFieldDynamicData.bools + enum_value_index))
			{
				if (rBitFieldDynamicData.bools[enum_value_index])
				{
					switch (reflection_field.enum_info.m_primitiveTypeIndex)
					{
					case _legacy_primitive_type_bitfield8:
						*reinterpret_cast<uint8_t*>(field_data) |= static_cast<uint8_t>(enum_value.value);
						break;
					case _legacy_primitive_type_bitfield16:
						*reinterpret_cast<uint16_t*>(field_data) |= static_cast<uint16_t>(enum_value.value);
						break;
					case _legacy_primitive_type_bitfield32:
						*reinterpret_cast<uint32_t*>(field_data) |= static_cast<uint32_t>(enum_value.value);
						break;
					case _legacy_primitive_type_bitfield64:
						*reinterpret_cast<uint64_t*>(field_data) |= static_cast<uint64_t>(enum_value.value);
						break;
					DEBUG_ONLY(default: throw);
					}
				}
				else
				{
					switch (reflection_field.enum_info.m_primitiveTypeIndex)
					{
					case _legacy_primitive_type_bitfield8:
						*reinterpret_cast<uint8_t*>(field_data) &= ~static_cast<uint8_t>(enum_value.value);
						break;
					case _legacy_primitive_type_bitfield16:
						*reinterpret_cast<uint16_t*>(field_data) &= ~static_cast<uint16_t>(enum_value.value);
						break;
					case _legacy_primitive_type_bitfield32:
						*reinterpret_cast<uint32_t*>(field_data) &= ~static_cast<uint32_t>(enum_value.value);
						break;
					case _legacy_primitive_type_bitfield64:
						*reinterpret_cast<uint64_t*>(field_data) &= ~static_cast<uint64_t>(enum_value.value);
						break;
					DEBUG_ONLY(default: throw);
					}
				}
			}
		}
	}
	ImGui::EndChild();

	
	ImGui::SameLine();
	ImGui::Text(pFieldTypeName);

	ImGui::Columns(1);

	ImGui::PopID();
}