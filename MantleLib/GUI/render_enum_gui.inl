
void render_enum_gui(void* field_data, const c_reflection_field& reflection_field)
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
	case e_primitive_type::Enum8:
		current_value = *reinterpret_cast<uint8_t*>(field_data);
		break;
	case e_primitive_type::Enum16:
		current_value = *reinterpret_cast<uint16_t*>(field_data);
		break;
	case e_primitive_type::Enum32:
		current_value = *reinterpret_cast<uint32_t*>(field_data);
		break;
	case e_primitive_type::Enum64:
		current_value = *reinterpret_cast<uint64_t*>(field_data);
		break;
	DEBUG_ONLY(default: throw);
	}

	const s_reflection_enum_value* current_reflection_enum_value = nullptr;
	uint32_t const enum_value_count = reflection_field.enum_info.reflection_enum_type->values_count;
	for (uint32_t enum_value_index = 0; enum_value_index < enum_value_count; enum_value_index++)
	{
		const s_reflection_enum_value& enum_value = reflection_field.enum_info.reflection_enum_type->values[enum_value_index];
		if (enum_value.value == current_value)
		{
			current_reflection_enum_value = &enum_value;
			break;
		}
	}

	bool begin_combo_result;
	if (current_reflection_enum_value)
	{
		begin_combo_result = ImGui::BeginCombo("##enum_combo", current_reflection_enum_value->name);
	}
	else
	{
		char buffer[128];
		snprintf(buffer, _countof(buffer)-1, "%s (%llu)", reflection_field.enum_info.type_name, current_value);
		begin_combo_result = ImGui::BeginCombo("##enum_combo", buffer);
	}

	if (begin_combo_result)
	{
		for (uint32_t enum_value_index = 0; enum_value_index < enum_value_count; enum_value_index++)
		{
			const s_reflection_enum_value& enum_value = reflection_field.enum_info.reflection_enum_type->values[enum_value_index];

			if (ImGui::Selectable(enum_value.name))
			{
				switch (reflection_field.enum_info.m_primitiveTypeIndex)
				{
				case e_primitive_type::Enum8:
					*reinterpret_cast<uint8_t*>(field_data) = static_cast<uint8_t>(enum_value.value);
					break;
				case e_primitive_type::Enum16:
					*reinterpret_cast<uint16_t*>(field_data) = static_cast<uint16_t>(enum_value.value);
					break;
				case e_primitive_type::Enum32:
					*reinterpret_cast<uint32_t*>(field_data) = static_cast<uint32_t>(enum_value.value);
					break;
				case e_primitive_type::Enum64:
					*reinterpret_cast<uint64_t*>(field_data) = static_cast<uint64_t>(enum_value.value);
					break;
				DEBUG_ONLY(default: throw);
				}
			}
		}

		ImGui::EndCombo();
	}
	ImGui::SameLine();
	ImGui::Text(pFieldTypeName);

	ImGui::Columns(1);

	ImGui::PopID();
}