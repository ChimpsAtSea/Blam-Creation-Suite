#include "definitiontweaker-private-pch.h"

c_serialization_context::c_serialization_context(c_serialization_context& _parent_serialization_context) :
	engine_platform_build(_parent_serialization_context.engine_platform_build),
	max_serialization_error_type(_tag_serialization_state_good),
	parent_serialization_context(&_parent_serialization_context),
	serialization_errors(),
	child_serialization_errors(),
	all_serialization_errors()
{

}

c_serialization_context::c_serialization_context(s_engine_platform_build _engine_platform_build) :
	engine_platform_build(_engine_platform_build),
	max_serialization_error_type(_tag_serialization_state_good),
	parent_serialization_context(nullptr),
	serialization_errors(),
	child_serialization_errors(),
	all_serialization_errors()
{

}

c_serialization_context::~c_serialization_context()
{
	for (auto seralization_error : serialization_errors)
	{
		delete seralization_error;
	}
}

void c_serialization_context::enqueue_serialization_error(c_serialization_error* serialization_error)
{
	serialization_errors.push_back(serialization_error);
	all_serialization_errors.push_back(serialization_error);
	max_serialization_error_type = __max(max_serialization_error_type, serialization_error->error_type);

	if (c_serialization_context* current_serialization_context = parent_serialization_context)
	{
		do
		{
			current_serialization_context->child_serialization_errors.push_back(serialization_error);
			current_serialization_context->all_serialization_errors.push_back(serialization_error);
			current_serialization_context->max_serialization_error_type = __max(current_serialization_context->max_serialization_error_type, serialization_error->error_type);
		} while (current_serialization_context = current_serialization_context->parent_serialization_context);
	}
}

void c_serialization_context::render_hover_tooltip()
{
	if (ImGui::IsItemHovered() && !all_serialization_errors.empty())
	{
		ImGui::BeginTooltip();
		size_t num_errors = all_serialization_errors.size();
		size_t num_rendered_errors = 0;
		for (c_serialization_error* serialization_error : serialization_errors)
		{
			if (num_rendered_errors < 15)
			{
				num_rendered_errors++;
				serialization_error->render();
			}
		}
		if (!serialization_errors.empty() && !child_serialization_errors.empty())
		{
			ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
		}
		for (c_serialization_error* serialization_error : child_serialization_errors)
		{
			if (num_rendered_errors < 15)
			{
				num_rendered_errors++;
				serialization_error->render();
			}
		}
		if (num_rendered_errors < num_errors)
		{
			unsigned int num_remaining_errors = num_errors - num_rendered_errors;
			ImGui::Text("%zu more errors...", num_remaining_errors);
		}
		ImGui::EndTooltip();
	}
}
