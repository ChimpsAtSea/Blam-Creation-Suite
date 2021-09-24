#include "shared-private-pch.h"

// If 'p_open' is specified for a modal popup window, the popup will have a regular close button which will close the popup.
// Note that popup visibility status is owned by Dear ImGui (and manipulated with e.g. OpenPopup) so the actual value of *p_open is meaningless here.
bool BeginPopupModalEx(ImGuiID id, const char* name, bool* p_open, ImGuiWindowFlags flags)
{
	ImGuiContext& g = *GImGui;
	ImGuiWindow* window = g.CurrentWindow;
	if (!ImGui::IsPopupOpen(id, ImGuiPopupFlags_None))
	{
		g.NextWindowData.ClearFlags(); // We behave like Begin() and need to consume those values
		return false;
	}

	// Center modal windows by default
	// FIXME: Should test for (PosCond & window->SetWindowPosAllowFlags) with the upcoming window.
	if ((g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasPos) == 0)
		ImGui::SetNextWindowPos({ g.IO.DisplaySize.x * 0.5f , g.IO.DisplaySize.y * 0.5f }, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

	flags |= ImGuiWindowFlags_Popup | ImGuiWindowFlags_Modal | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
	const bool is_open = ImGui::Begin(name, p_open, flags);
	if (!is_open || (p_open && !*p_open)) // NB: is_open can be 'false' when the popup is completely clipped (e.g. zero size display)
	{
		ImGui::EndPopup();
		if (is_open)
			ImGui::ClosePopupToLevel(g.BeginPopupStack.Size, true);
		return false;
	}
	return is_open;
}
