#include "mandrilllib-private-pch.h"

void c_custom_tool_base::render()
{
	ImGui::PushID(this);

	ImGuiWindowFlags window_flags = 0;
	ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1);
	//ImGui::BeginChild("ChildL", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.5f, 260), false, window_flags);

	content_height = __max(content_height, ImGui::GetFrameHeight());
	if (content_height < maximum_height)
	{
		window_flags |= ImGuiWindowFlags_NoScrollbar;
	}
	else
	{
		content_height = maximum_height;
	}
	float width = ImGui::GetWindowContentRegionWidth();
	ImGui::BeginChild(title, ImVec2(width, content_height), false, window_flags);
	ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
	if (is_open)
	{
		flags |= ImGuiTreeNodeFlags_DefaultOpen;
	}
	is_open = ImGui::CollapsingHeader(title, flags);
	content_height = ImGui::GetItemRectSize().y;
	if (is_open)
	{
		ImGui::BeginGroup();
		{
			render_contents();
		}
		ImGui::EndGroup();
		content_height = ImGui::GetFrameHeight() + ImGui::GetItemRectSize().y + ImGui::GetStyle().ItemSpacing.y;
	}
	else
	{
		content_height = ImGui::GetFrameHeight();
	}
	//ImGui::EndChild();
	ImGui::EndChild();
	ImGui::PopStyleVar();

	ImGui::PopID();
}



