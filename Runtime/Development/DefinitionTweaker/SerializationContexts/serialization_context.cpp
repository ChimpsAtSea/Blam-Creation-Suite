#include "definitiontweaker-private-pch.h"

c_serialization_context::c_serialization_context(c_serialization_context& _parent_serialization_context, const void* _data_start, std::string _name) :
	engine_platform_build(_parent_serialization_context.engine_platform_build),
	max_serialization_error_type(_serialization_error_type_ok),
	data_start(_data_start),
	data_end(nullptr),
	parent_serialization_context(&_parent_serialization_context),
	serialization_errors_count(),
	child_serialization_errors_count(),
	all_serialization_errors_count(),
	serialization_errors(),
	child_serialization_errors(),
	all_serialization_errors(),
	serialization_errors_storage_count(),
	child_serialization_errors_storage_count(),
	all_serialization_errors_storage_count(),
	mutex(),
	name(_name)
{

}

c_serialization_context::c_serialization_context(s_engine_platform_build _engine_platform_build, const void* _data_start, std::string _name) :
	engine_platform_build(_engine_platform_build),
	max_serialization_error_type(_serialization_error_type_ok),
	data_start(_data_start),
	data_end(nullptr),
	parent_serialization_context(nullptr),
	serialization_errors_count(),
	child_serialization_errors_count(),
	all_serialization_errors_count(),
	serialization_errors(),
	child_serialization_errors(),
	all_serialization_errors(),
	serialization_errors_storage_count(),
	child_serialization_errors_storage_count(),
	all_serialization_errors_storage_count(),
	mutex(),
	name(_name)
{

}

c_serialization_context::~c_serialization_context()
{
	for (unsigned int serialization_error_index = 0; serialization_error_index < serialization_errors_count; serialization_error_index++)
	{
		c_serialization_error* serialization_error = serialization_errors[serialization_error_index];
		delete serialization_error;
	}
}

void c_serialization_context::enqueue_serialization_error(c_serialization_error* serialization_error)
{
	mutex.lock();

	serialization_errors_count++;
	if (serialization_errors_storage_count < k_target_serialization_error_count)
	{
		serialization_errors = trivial_realloc(c_serialization_error*, serialization_errors, serialization_errors_storage_count + 1);
		serialization_errors[serialization_errors_storage_count++] = serialization_error;
	}
	all_serialization_errors_count++;
	if (all_serialization_errors_storage_count < k_target_serialization_error_count * 4)
	{
		all_serialization_errors = trivial_realloc(c_serialization_error*, all_serialization_errors, all_serialization_errors_storage_count + 1);
		all_serialization_errors[all_serialization_errors_storage_count++] = serialization_error;
	}
	max_serialization_error_type = __max(max_serialization_error_type, serialization_error->error_type);

	mutex.unlock();

	if (c_serialization_context* current_serialization_context = parent_serialization_context)
	{
		do
		{
			current_serialization_context->mutex.lock();

			current_serialization_context->child_serialization_errors_count++;
			if (current_serialization_context->child_serialization_errors_storage_count < k_target_serialization_error_count * 4)
			{
				current_serialization_context->child_serialization_errors = trivial_realloc(
					c_serialization_error*, 
					current_serialization_context->child_serialization_errors, 
					current_serialization_context->child_serialization_errors_storage_count + 1);
				current_serialization_context->child_serialization_errors[current_serialization_context->child_serialization_errors_storage_count++] = serialization_error;
			}
			current_serialization_context->all_serialization_errors_count++;
			if (current_serialization_context->all_serialization_errors_storage_count < k_target_serialization_error_count * 4)
			{
				current_serialization_context->all_serialization_errors = trivial_realloc(
					c_serialization_error*, 
					current_serialization_context->all_serialization_errors, 
					current_serialization_context->all_serialization_errors_storage_count + 1);
				current_serialization_context->all_serialization_errors[current_serialization_context->all_serialization_errors_storage_count++] = serialization_error;
			}
			current_serialization_context->max_serialization_error_type = __max(current_serialization_context->max_serialization_error_type, serialization_error->error_type);

			current_serialization_context->mutex.unlock();
		
		} while (current_serialization_context = current_serialization_context->parent_serialization_context);
	}
}

void c_serialization_context::render_hover_tooltip()
{
	if (ImGui::IsItemHovered() && all_serialization_errors_count > 0)
	{
		ImGui::BeginTooltip();

		unsigned int num_rendered_errors = 0;
		for (unsigned int serialization_error_index = 0; serialization_error_index < serialization_errors_storage_count; serialization_error_index++)
		{
			if (num_rendered_errors < 15)
			{
				c_serialization_error* serialization_error = serialization_errors[serialization_error_index];

				ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[serialization_error->error_type]);
				ImGui::TextUnformatted("E");
				ImGui::SameLine();
				num_rendered_errors++;
				serialization_error->render();
				ImGui::PopStyleColor();
			}
			else break;
		}
		if (serialization_errors_count > 0 && child_serialization_errors_count > 0)
		{
			ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
		}
		for (unsigned int child_serialization_error_index = 0; child_serialization_error_index < child_serialization_errors_storage_count; child_serialization_error_index++)
		{
			if (num_rendered_errors < 15)
			{
				c_serialization_error* serialization_error = child_serialization_errors[child_serialization_error_index];

				ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[serialization_error->error_type]);
				ImGui::TextUnformatted("C");
				ImGui::SameLine();
				num_rendered_errors++;
				serialization_error->render();
				ImGui::PopStyleColor();
			}
			else break;
		}
		if (num_rendered_errors < all_serialization_errors_count)
		{
			unsigned int num_remaining_errors = all_serialization_errors_count - num_rendered_errors;
			ImGui::Text("%zu more errors...", num_remaining_errors);
		}
		ImGui::EndTooltip();
	}
}
