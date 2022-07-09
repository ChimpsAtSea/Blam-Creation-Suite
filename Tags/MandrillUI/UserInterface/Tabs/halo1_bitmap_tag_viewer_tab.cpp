#include "mandrillui-private-pch.h"

#include <Generated/high_level_halo1_pc64/highlevel-halo1-pc64-public-pch.h>

using namespace blofeld;
using namespace blofeld::halo1::pc64;

c_halo1_bitmap_tag_viewer_tab::c_halo1_bitmap_tag_viewer_tab(c_tag_project& tag_project, h_bitmap& halo1_bitmap_tag, c_mandrill_tab& parent) :
	c_mandrill_tab("Bitmap View", "Bitmap View", &parent, false),
	tag_project(tag_project),
	halo1_bitmap_tag(halo1_bitmap_tag)
{
	render_bitmap_enumerable(halo1_bitmap_tag.bitmaps_block);
}

c_halo1_bitmap_tag_viewer_tab::~c_halo1_bitmap_tag_viewer_tab()
{

}

c_tag_project& c_halo1_bitmap_tag_viewer_tab::get_tag_project() const
{
	return tag_project;
}

h_bitmap& c_halo1_bitmap_tag_viewer_tab::get_tag() const
{
	return halo1_bitmap_tag;
}

void c_halo1_bitmap_tag_viewer_tab::render_impl()
{
	render_bitmap_enumerable(halo1_bitmap_tag.bitmaps_block);
}

bool c_halo1_bitmap_tag_viewer_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	return true;
}

void c_halo1_bitmap_tag_viewer_tab::render_file_dialogue_gui_impl()
{

}

void c_halo1_bitmap_tag_viewer_tab::render_game_layer_impl()
{

}

void c_halo1_bitmap_tag_viewer_tab::render_bitmap(long index, h_bitmap_data& bitmap_data)
{
	ImGui::Text("%i w:%i h:%i d:%i", index, (int)bitmap_data.width, (int)bitmap_data.height, (int)bitmap_data.depth);
}

void c_halo1_bitmap_tag_viewer_tab::render_bitmap_enumerable(h_enumerable& enumerable)
{
	constexpr float k_min_block_width = 1000.0f;
	constexpr float k_block_header_height = 80.0f;

	unsigned long const count = enumerable.size();

	ImGui::PushID(this);
	ImGuiID const is_open_id = ImGui::GetID("is_open");
	ImGuiID const is_inserting_id = ImGui::GetID("is_inserting");
	ImGuiID const inserting_popup_id = ImGui::GetID("is_inserting");
	ImGuiID const index_id = ImGui::GetID("index");
	ImGuiID const content_width_id = ImGui::GetID("content_width");
	ImGuiID const collapsing_header_id = ImGui::GetID("collapsing_header");
	ImGuiID const inserting_offset_id = ImGui::GetID("inserting_offset");
	ImGuiID const inserting_count_id = ImGui::GetID("inserting_count");

	ImGuiStorage* storage = ImGui::GetStateStorage();
	bool is_open = static_cast<bool>(storage->GetInt(is_open_id, 1));
	bool is_inserting = static_cast<bool>(storage->GetInt(is_inserting_id));
	float content_width = storage->GetFloat(content_width_id, k_min_block_width);
	int32_t index = storage->GetInt(index_id);
	bool is_disabled = count == 0;

#define clamp_rollover(value, max) \
	if (max == 0) value = 0; \
	else if (value < 0) value = static_cast<int32_t>(max - 1); \
	else if (value >= static_cast<int32_t>(max)) value = value % static_cast<int32_t>(max);

	ImVec2 collapsing_header_pos = ImGui::GetCursorPos();

	h_block* block = dynamic_cast<h_block*>(&enumerable);

	ImGui::Dummy({ 0.0f, k_block_header_height });

	clamp_rollover(index, count);

	if (is_open)
	{
		if (count > 0)
		{
			ImGui::BeginGroup();
			ImGui::Dummy({ 8.0f, 8.0f });
			ImGui::SameLine();
			ImGui::BeginGroup();

			h_prototype& object = enumerable.get(index);
			h_bitmap_data* bitmap_data = dynamic_cast<h_bitmap_data*>(&object);
			ASSERT(bitmap_data != nullptr);
			render_bitmap(index, *bitmap_data);

			ImGui::EndGroup();
			ImGui::Dummy({ 8.0f, 8.0f });
			ImGui::EndGroup();

			content_width = ImGui::GetItemRectSize().x;
		}
		else
		{
			content_width = k_min_block_width;
			is_open = false;
		}
	}


	ImVec2 block_finish_pos = ImGui::GetCursorPos();

	ImGui::SetCursorPos(collapsing_header_pos);

	float width = k_min_block_width;
	if (is_open)
	{
		width = __max(k_min_block_width, content_width);
	}

	if (ImGui::BeginChild("##block", ImVec2(width, k_block_header_height), false, ImGuiWindowFlags_NoScrollbar))
	{

		ImGui::Columns(3, "##block_controls", false);
		ImGui::SetColumnWidth(0, width - 80);
		ImGui::SetColumnWidth(1, 40);
		ImGui::SetColumnWidth(2, 40);

		{
			ImGui::Dummy({ 3.0f, 3.0f });
			if (count == 0)
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
				ImGui::PushStyleColor(ImGuiCol_Header, MANDRILL_THEME_DISABLED_MED(0.76f));
				ImGui::PushStyleColor(ImGuiCol_HeaderHovered, MANDRILL_THEME_DISABLED_MED(0.86f));
				ImGui::PushStyleColor(ImGuiCol_HeaderActive, MANDRILL_THEME_DISABLED_HIGH(1.00f));
			}
			c_fixed_string_128 header_str;
			header_str.format("%s : count:%u", "Bitmaps", count);

			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap;
			if (is_open)
			{
				flags |= ImGuiTreeNodeFlags_DefaultOpen;
			}
			is_open = ImGui::TreeNodeBehavior(collapsing_header_id, flags, header_str.c_str());
			if (count == 0)
			{
				ImGui::PopStyleColor(3);
				ImGui::PopItemFlag();
			}
		}
		ImGui::NextColumn();
		{
			ImGui::Dummy({ 0.0f, 3.0f });
			ImGui::SetNextItemWidth(-1);
			ImGui::Button(ICON_FA_GEAR);
		}
		ImGui::NextColumn();
		{
			ImGui::Dummy({ 0.0f, 3.0f });
			ImGui::SetNextItemWidth(-1);
			ImGui::Button(ICON_FA_INFO);
		}
		ImGui::NextColumn();

		ImGui::Columns(1);
		ImGui::Dummy({ 3.0f, 0.0f });
		ImGui::SameLine();
		{
			ImGui::SetNextItemWidth(350);
			if (count > 0)
			{
				// #TODO: advanced block index formatting
				c_fixed_string_128 index_str = "None";
				index_str.format("index: %u", index);
				if (ImGui::BeginCombo("##index", index_str.c_str()))
				{
					ImGui::EndCombo();
				}
			}
			else
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);

				if (ImGui::BeginCombo("##index", "None"))
				{
					ImGui::EndCombo();
				}

				ImGui::PopItemFlag();
			}
		}

		if (is_disabled)
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		}

		ImGui::SameLine();
		if (ImGui::ButtonEx(ICON_FA_PLUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
		{
			int index_amount = 1;
			{
				ImGuiIO& IO = ImGui::GetIO();
				const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
				if (t > 0.0f)
				{
					index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
					index_amount *= static_cast<int>(1.0f + t);
				}
			}

			index += index_amount;
			clamp_rollover(index, count);
		}
		ImGui::SameLine();
		if (ImGui::ButtonEx(ICON_FA_MINUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
		{
			int index_amount = 1;
			{
				ImGuiIO& IO = ImGui::GetIO();
				const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
				if (t > 0.0f)
				{
					index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
					index_amount *= static_cast<int>(1.0f + t);
				}
			}

			index -= index_amount;
			clamp_rollover(index, count);
		}

		if (is_disabled)
		{
			ImGui::PopItemFlag();
		}



		ImGui::SameLine();
		ImGui::Dummy({ 25.0f, 0.0f });

		if (block)
		{
			ImGui::SameLine();
			if (ImGui::Button("Add"))
			{
				block->emplace_back();
				index = enumerable.size() - 1;
			}

			ImGui::SameLine();
			if (ImGui::Button("Insert"))
			{
				ImGui::OpenPopupEx(inserting_popup_id);

				storage->SetInt(inserting_offset_id, static_cast<int>(index));
				storage->SetInt(inserting_count_id, static_cast<int>(1));

				is_inserting = true;
			}

			if (is_disabled)
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
			}

			ImGui::SameLine();
			if (ImGui::Button("Duplicate"))
			{
				h_prototype& object = block->get(index);
				block->emplace_back(object);
				index = enumerable.size() - 1;
			}

			ImGui::SameLine();
			ImGui::Dummy({ 25.0f, 0.0f });

			ImGui::SameLine();
			if (ImGui::Button("Delete"))
			{
				block->remove(index);
				index--;
			}

			ImGui::SameLine();
			if (ImGui::Button("Delete All"))
			{
				block->clear();
				index = 0;
			}

			if (is_disabled)
			{
				ImGui::PopItemFlag();
			}
		}
	}
	ImGui::EndChild();

	ImGui::SetCursorPos(block_finish_pos);

	if (block != nullptr && is_inserting)
	{
		int32_t insert_offset = static_cast<unsigned long>(storage->GetInt(inserting_offset_id));
		unsigned long insert_count = static_cast<unsigned long>(storage->GetInt(inserting_count_id));

		ImGuiIO& io = ImGui::GetIO();
		ImGui::SetNextWindowPos({ io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f }, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
		ImGui::SetNextWindowContentSize({ 800, 600 });
		if (BeginPopupModalEx(is_inserting_id, "Insert", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			if (ImGui::InputScalar("Offset", ImGuiDataType_U32, &insert_offset))
			{
				clamp_rollover(insert_offset, count);
			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_PLUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_offset += index_amount;
				clamp_rollover(insert_offset, count);
			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_MINUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_offset -= index_amount;
				clamp_rollover(insert_offset, count);
			}

			if (ImGui::InputScalar("Count", ImGuiDataType_U32, &insert_count))
			{

			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_PLUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_count += index_amount;
			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_MINUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_count -= index_amount;
			}

			if (ImGui::Selectable("Insert"))
			{
				block->insert_hole(static_cast<unsigned long>(insert_offset), insert_count);
				index = insert_offset;
				is_inserting = false;
			}
			if (ImGui::Selectable("Cancel"))
			{
				is_inserting = false;
			}

			ImGui::EndPopup();
		}

		storage->SetInt(inserting_offset_id, insert_offset);
		storage->SetInt(inserting_count_id, insert_count);
	}

	storage->SetInt(is_open_id, static_cast<int>(is_open));
	storage->SetInt(is_inserting_id, static_cast<int>(is_inserting));
	storage->SetFloat(content_width_id, content_width);
	storage->SetInt(index_id, static_cast<int>(index));

	ImGui::PopID();
}
