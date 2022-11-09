#include "definitiontweaker-private-pch.h"

class c_memory_location_serialization_context :
	public c_serialization_context
{
public:
	c_memory_location_serialization_context(c_serialization_context& serialization_context, std::string _name, const void* _data_start, const void* _data_end = nullptr) :
		c_serialization_context(serialization_context, _data_start, _name.c_str(), owns_name_memory = true)
	{
		data_end = _data_end;
	}

	c_memory_location_serialization_context(c_memory_location_serialization_context const&) = delete;

	virtual BCS_RESULT read() override final
	{
		return BCS_S_OK;
	}
	virtual BCS_RESULT traverse() override final
	{
		return BCS_S_OK;
	}
	virtual BCS_RESULT calculate_memory() override final
	{
		return BCS_S_OK;
	}
	virtual void render_tree() override final
	{

	}
};

class c_memory_hole_serialization_context :
	public c_serialization_context
{
public:
	c_memory_hole_serialization_context(c_serialization_context& serialization_context, const void* _data_start, const void* _data_end = nullptr) :
		c_serialization_context(serialization_context, _data_start, "hole", owns_name_memory = false)
	{
		data_end = _data_end;
	}

	c_memory_hole_serialization_context(c_memory_hole_serialization_context const&) = delete;

	virtual BCS_RESULT read() override final
	{
		for (const char* read_position = static_cast<const char*>(data_start); read_position < data_end; read_position++)
		{
			if (*read_position)
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_fatal,
					"memory hole contains non zero data");

				break;
			}
		}

		return BCS_S_OK;
	}
	virtual BCS_RESULT traverse() override final
	{
		return BCS_S_OK;
	}
	virtual BCS_RESULT calculate_memory() override final
	{
		return BCS_S_OK;
	}
	virtual void render_tree() override final
	{

	}
};

c_tag_serialization_context::c_tag_serialization_context(c_group_serialization_context& _group_serialization_context, unsigned int _index, const char* _tag_data_start) :
	c_serialization_context(_group_serialization_context, _tag_data_start, std::to_string(_index).c_str(), owns_name_memory = true),
	tag_header(reinterpret_cast<const eldorado::s_cache_file_tag_instance*>(_tag_data_start)),
	dependencies(),
	data_fixups(),
	resource_fixups(),
	_end(),
	tag_root_structure(),
	expected_main_struct_size(),
	root_struct_serialization_context(),
	group_serialization_context(&_group_serialization_context),
	index(_index),
	definition_tweaker(_group_serialization_context.definition_tweaker),
	memory_intervals(),
	per_byte_context_associations(),
	per_byte_memory_intervals()
{

}

c_tag_serialization_context::c_tag_serialization_context(c_definition_tweaker& _definition_tweaker, s_engine_platform_build _engine_platform_build, unsigned int _index, const char* _tag_data_start) :
	c_serialization_context(_engine_platform_build, _tag_data_start, std::to_string(_index).c_str(), owns_name_memory = true),
	tag_header(reinterpret_cast<const eldorado::s_cache_file_tag_instance*>(_tag_data_start)),
	dependencies(),
	data_fixups(),
	resource_fixups(),
	_end(),
	tag_root_structure(),
	expected_main_struct_size(),
	root_struct_serialization_context(),
	group_serialization_context(nullptr),
	index(_index),
	definition_tweaker(_definition_tweaker),
	memory_intervals(),
	per_byte_context_associations(),
	per_byte_memory_intervals()
{

}

c_tag_serialization_context::~c_tag_serialization_context()
{
	delete root_struct_serialization_context;
	trivial_free(per_byte_context_associations);
}

BCS_RESULT c_tag_serialization_context::read()
{
	data_end = static_cast<const char*>(data_start) + tag_header->total_size;

	if (group_serialization_context)
	{
		dependencies = reinterpret_cast<const int*>(tag_header + 1);
		data_fixups = dependencies + tag_header->dependency_count;
		resource_fixups = data_fixups + tag_header->data_fixup_count;
		_end = resource_fixups + tag_header->resource_fixup_count;

		ASSERT(tag_header->padding == 0);

		if (tag_header->dependency_count == 0)
		{
			dependencies = nullptr;
		}

		if (tag_header->data_fixup_count == 0)
		{
			data_fixups = nullptr;
		}

		if (tag_header->resource_fixup_count == 0)
		{
			resource_fixups = nullptr;
		}
		if (tag_header->resource_fixup_count > 1)
		{
			debug_point;
		}

		tag_root_structure = static_cast<const char*>(data_start) + tag_header->offset;
		expected_main_struct_size = tag_header->total_size - tag_header->offset;

		if (c_runtime_tag_block_definition* block_definition = group_serialization_context->runtime_tag_group_definition.block_definition)
		{
			if (c_runtime_tag_struct_definition* struct_definition = block_definition->struct_definition)
			{
				root_struct_serialization_context = new() c_tag_struct_serialization_context(
					*this,
					*this,
					tag_root_structure,
					*struct_definition,
					expected_main_struct_size);

				root_struct_serialization_context->read();

				unsigned int alignment = 1u << struct_definition->alignment_bits;
				unsigned int aligned_struct_size = ROUND_UP_VALUE(root_struct_serialization_context->struct_size, alignment);
				unsigned int aligned16_struct_size = ROUND_UP_VALUE(root_struct_serialization_context->struct_size, 16);
				int bytes_after_struct = static_cast<int>(expected_main_struct_size) - static_cast<int>(root_struct_serialization_context->struct_size);
				if (bytes_after_struct < 0 || bytes_after_struct >= 16)
				{
					root_struct_serialization_context->enqueue_serialization_error<c_generic_serialization_error>(
						_serialization_error_type_warning,
						"unexpected struct size expected:%u aligned:%u aligned16:%u unaligned:%u",
						expected_main_struct_size,
						aligned_struct_size,
						aligned16_struct_size,
						root_struct_serialization_context->struct_size);
				}
			}
			else
			{
				enqueue_serialization_error<c_generic_serialization_error>(
					_serialization_error_type_fatal,
					"runtime group block '%s' has no struct definition",
					group_serialization_context->runtime_tag_group_definition.block_definition->name.c_str());
			}
		}
		else
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_fatal,
				"runtime group '%s' has no block definition",
				group_serialization_context->runtime_tag_group_definition.name.c_str());
		}
	}
	else
	{
		tag group_tag = tag_header->group_tags[0];
		unsigned int group_tag_swapped = byteswap(group_tag);
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_fatal,
			"couldn't find tag group '%.4s'",
			&group_tag_swapped);
	}
	return BCS_S_OK;
}

BCS_RESULT c_tag_serialization_context::traverse()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping traverse due to issues");
		return BCS_E_FAIL;
	}

	if (root_struct_serialization_context)
	{
		root_struct_serialization_context->traverse();
	}
	return BCS_S_OK;
}

#define range_intersection(a1, a2, b1, b2) __max(reinterpret_cast<intptr_t>(a1), reinterpret_cast<intptr_t>(b1)) < __min(reinterpret_cast<intptr_t>(a2), reinterpret_cast<intptr_t>(b2))

BCS_RESULT c_tag_serialization_context::calculate_memory()
{
	if (max_serialization_error_type >= _serialization_error_type_fatal)
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_serialization_error_type_warning,
			"skipping calculate_memory due to issues");
		return BCS_E_FAIL;
	}

	c_memory_location_serialization_context* header_memory_location = new c_memory_location_serialization_context(*this, "header", tag_header, tag_header + 1);
	memory_intervals.push_back(header_memory_location);

	if (dependencies)
	{
		c_memory_location_serialization_context* header_dependencies_memory_location = new c_memory_location_serialization_context(*this, "header:dependencies", dependencies, dependencies + tag_header->dependency_count);
		memory_intervals.push_back(header_dependencies_memory_location);
	}

	if (data_fixups)
	{
		c_memory_location_serialization_context* header_data_fixups_memory_location = new c_memory_location_serialization_context(*this, "header:data_fixups", data_fixups, data_fixups + tag_header->data_fixup_count);
		memory_intervals.push_back(header_data_fixups_memory_location);
	}

	if (resource_fixups)
	{
		c_memory_location_serialization_context* header_resource_fixups_memory_location = new c_memory_location_serialization_context(*this, "header:resource_fixups", resource_fixups, resource_fixups + tag_header->resource_fixup_count);
		memory_intervals.push_back(header_resource_fixups_memory_location);
	}
	
	memory_intervals.push_back(root_struct_serialization_context);

	if (root_struct_serialization_context)
	{
		root_struct_serialization_context->calculate_memory();
	}

	const char* const bytes = static_cast<const char*>(data_start);
	unsigned int num_bytes = static_cast<const char*>(data_end) - static_cast<const char*>(data_start);

	per_byte_context_associations = trivial_malloc(s_per_byte_context_association, num_bytes);

	// assume that there is at minimum 1 memory interval per byte (should only allocate for overlaps)
	per_byte_memory_intervals.reserve(num_bytes);
	{
		const char* current_data_position = bytes;
		for (unsigned int byte_index = 0; byte_index < num_bytes; byte_index++, current_data_position++)
		{
			s_per_byte_context_association& per_byte_context_association = per_byte_context_associations[byte_index];

			per_byte_context_association.per_byte_memory_intervals_offset = static_cast<unsigned long>(per_byte_memory_intervals.size());
			per_byte_context_association.per_byte_memory_intervals_count = 0;

			for (c_serialization_context* serialization_context : memory_intervals)
			{
				ASSERT(serialization_context->data_end);
				if (current_data_position >= serialization_context->data_start  && current_data_position < serialization_context->data_end)
				{
					//if (range_intersection(current_data_position, current_data_position + 1, serialization_context->data_start, serialization_context->data_end))
					{
						per_byte_memory_intervals.emplace_back(serialization_context);
						per_byte_context_association.per_byte_memory_intervals_count++;
					}
				}
			}
		}
	}

	{
		const char* current_data_position = bytes;
		for (unsigned int byte_index = 0; byte_index < num_bytes; byte_index++, current_data_position++)
		{
			s_per_byte_context_association& per_byte_context_association = per_byte_context_associations[byte_index];
			if (per_byte_context_association.per_byte_memory_intervals_count > 0)
			{
				continue;
			}

			c_memory_hole_serialization_context* memory_hole_serialization_context = new c_memory_hole_serialization_context(*this, current_data_position);
			memory_intervals.emplace_back(memory_hole_serialization_context);

			unsigned int per_byte_memory_intervals_offset = static_cast<unsigned long>(per_byte_memory_intervals.size());
			per_byte_memory_intervals.emplace_back(memory_hole_serialization_context);

			for (; byte_index < num_bytes; byte_index++, current_data_position++)
			{
				s_per_byte_context_association& per_byte_context_association = per_byte_context_associations[byte_index];
				if (per_byte_context_association.per_byte_memory_intervals_count == 0)
				{
					per_byte_context_association.per_byte_memory_intervals_count = 1;
					per_byte_context_association.per_byte_memory_intervals_offset = per_byte_memory_intervals_offset;
				}
				else break;
			}

			memory_hole_serialization_context->data_end = current_data_position;
			memory_hole_serialization_context->read();
		}
	}

	for (unsigned int byte_index = 0; byte_index < num_bytes; byte_index++)
	{
		s_per_byte_context_association& per_byte_context_association = per_byte_context_associations[byte_index];
		if (per_byte_context_association.per_byte_memory_intervals_count > 1)
		{
			enqueue_serialization_error<c_generic_serialization_error>(
				_serialization_error_type_data_validation_error,
				"memory has overlapping data");

			break;
		}
	}

	return BCS_S_OK;
}

void c_tag_serialization_context::render_tree()
{
	ImGui::PushID(index);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (root_struct_serialization_context == nullptr)
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	bool tree_node_result;
	if (group_serialization_context)
	{
		const char* group_name = group_serialization_context->name;
		tree_node_result = ImGui::TreeNodeEx("##tag", flags, "%s [%u]", group_name, index);
	}
	else
	{
		unsigned int group_tag_swapped = byteswap(tag_header->group_tags[0]);
		tree_node_result = ImGui::TreeNodeEx("##tag", flags, "%.4s [%u]", &group_tag_swapped, index);
	}
	render_hover_tooltip();
	if (ImGui::BeginPopupContextItem("##contextmenu"))
	{
		if (ImGui::MenuItem("Open Memory View"))
		{
			group_serialization_context->definition_tweaker.next_memory_view_tag_serialization_context = this;
			ImGui::SeparatorEx(ImGuiSeparatorFlags_Horizontal);
		}
		ImGui::EndPopup();
	}
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	if (tree_node_result)
	{
		if (c_tag_struct_serialization_context* struct_serialization_context = root_struct_serialization_context)
		{
			struct_serialization_context->render_tree();
		}
		if (!memory_intervals.empty())
		{
			if (ImGui::TreeNodeEx("Memory Invervals"))
			{
				for (c_serialization_context* serialization_context : memory_intervals)
				{
					//if (c_memory_hole_serialization_context* memory_hole_serialization_context = dynamic_cast<c_memory_hole_serialization_context*>(serialization_context))
					//{
					//}
					//else
					{
						if (ImGui::TreeNodeEx(serialization_context->name, ImGuiTreeNodeFlags_Leaf))
						{
							ImGui::TreePop();
						}
						debug_point;
					}
				}
				ImGui::TreePop();
			}
		}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
}

ImU32 colors[] =
{
	IM_COL32(0xe6, 0x19, 0x4b, 0x50),
	IM_COL32(0x3c, 0xb4, 0x4b, 0x50),
	IM_COL32(0xff, 0xe1, 0x19, 0x50),
	IM_COL32(0x43, 0x63, 0xd8, 0x50),
	IM_COL32(0xf5, 0x82, 0x31, 0x50),
	IM_COL32(0x91, 0x1e, 0xb4, 0x50),
	IM_COL32(0x46, 0xf0, 0xf0, 0x50),
	IM_COL32(0xf0, 0x32, 0xe6, 0x50),
	IM_COL32(0xbc, 0xf6, 0x0c, 0x50),
	IM_COL32(0xfa, 0xbe, 0xbe, 0x50),
	IM_COL32(0x00, 0x80, 0x80, 0x50),
	IM_COL32(0xe6, 0xbe, 0xff, 0x50),
	IM_COL32(0x9a, 0x63, 0x24, 0x50),
	IM_COL32(0xff, 0xfa, 0xc8, 0x50),
	IM_COL32(0x80, 0x00, 0x00, 0x50),
	IM_COL32(0xaa, 0xff, 0xc3, 0x50),
	IM_COL32(0x80, 0x80, 0x00, 0x50),
	IM_COL32(0xff, 0xd8, 0xb1, 0x50),
	IM_COL32(0x00, 0x00, 0x75, 0x50),
};

ImU32 hole_colors[] =
{
	IM_COL32(0xe6, 0x19, 0x4b, 0x10),
	IM_COL32(0x3c, 0xb4, 0x4b, 0x10),
	IM_COL32(0xff, 0xe1, 0x19, 0x10),
	IM_COL32(0x43, 0x63, 0xd8, 0x10),
	IM_COL32(0xf5, 0x82, 0x31, 0x10),
	IM_COL32(0x91, 0x1e, 0xb4, 0x10),
	IM_COL32(0x46, 0xf0, 0xf0, 0x10),
	IM_COL32(0xf0, 0x32, 0xe6, 0x10),
	IM_COL32(0xbc, 0xf6, 0x0c, 0x10),
	IM_COL32(0xfa, 0xbe, 0xbe, 0x10),
	IM_COL32(0x00, 0x80, 0x80, 0x10),
	IM_COL32(0xe6, 0xbe, 0xff, 0x10),
	IM_COL32(0x9a, 0x63, 0x24, 0x10),
	IM_COL32(0xff, 0xfa, 0xc8, 0x10),
	IM_COL32(0x80, 0x00, 0x00, 0x10),
	IM_COL32(0xaa, 0xff, 0xc3, 0x10),
	IM_COL32(0x80, 0x80, 0x00, 0x10),
	IM_COL32(0xff, 0xd8, 0xb1, 0x10),
	IM_COL32(0x00, 0x00, 0x75, 0x10),
};

ImU32 border_colors[] =
{
	IM_COL32(0xe6, 0x19, 0x4b, 0xFF),
	IM_COL32(0x3c, 0xb4, 0x4b, 0xFF),
	IM_COL32(0xff, 0xe1, 0x19, 0xFF),
	IM_COL32(0x43, 0x63, 0xd8, 0xFF),
	IM_COL32(0xf5, 0x82, 0x31, 0xFF),
	IM_COL32(0x91, 0x1e, 0xb4, 0xFF),
	IM_COL32(0x46, 0xf0, 0xf0, 0xFF),
	IM_COL32(0xf0, 0x32, 0xe6, 0xFF),
	IM_COL32(0xbc, 0xf6, 0x0c, 0xFF),
	IM_COL32(0xfa, 0xbe, 0xbe, 0xFF),
	IM_COL32(0x00, 0x80, 0x80, 0xFF),
	IM_COL32(0xe6, 0xbe, 0xff, 0xFF),
	IM_COL32(0x9a, 0x63, 0x24, 0xFF),
	IM_COL32(0xff, 0xfa, 0xc8, 0xFF),
	IM_COL32(0x80, 0x00, 0x00, 0xFF),
	IM_COL32(0xaa, 0xff, 0xc3, 0xFF),
	IM_COL32(0x80, 0x80, 0x00, 0xFF),
	IM_COL32(0xff, 0xd8, 0xb1, 0xFF),
	IM_COL32(0x00, 0x00, 0x75, 0xFF),
};

struct s_interval
{
	const char* name;
	const char* start;
	const char* end;
	bool is_hole;
};

unsigned int byte_hover_index = UINT_MAX;

static ImVec2& operator-=(ImVec2& a, ImVec2& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

static ImVec2& operator+=(ImVec2& a, ImVec2& b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

static ImVec2 operator*(ImVec2 a, float b)
{
	a.x *= b;
	a.y *= b;
	return a;
}

static ImVec2& operator*=(ImVec2& a, float b)
{
	a.x *= b;
	a.y *= b;
	return a;
}

void c_tag_serialization_context::draw_memory_explorer()
{
	static int display_items_start = 0;
	static int display_items_end = 0;

	ImGuiStyle& style = ImGui::GetStyle();
	ImDrawList& draw_list = *ImGui::GetWindowDrawList();

	const char* const bytes = static_cast<const char*>(data_start);
	unsigned int num_bytes = static_cast<const char*>(data_end) - static_cast<const char*>(data_start);

	//std::vector<s_interval> intervals;
	//intervals.push_back({ "test1", bytes, bytes + 5 });
	//intervals.push_back({ "test2", bytes + 5, bytes + 10 });
	//intervals.push_back({ "test3", bytes + 10, bytes + 10 });
	//intervals.push_back({ "test4", bytes + 1, bytes + 3 });
	//intervals.push_back({ "test4", bytes + 20, bytes + 30 });

	unsigned int tick_byte_hover_index = byte_hover_index;
	byte_hover_index = UINT_MAX;

	unsigned int num_columns = 16;
	unsigned int num_rows = ROUND_UP_VALUE(num_bytes, num_columns) / num_columns;

	ImGui::Text("%i %i", display_items_start, display_items_end);

	// std::sort(intervals.begin(), intervals.end(), [](s_interval& a, s_interval& b) { return a.start < b.start; });

	if (tick_byte_hover_index == UINT_MAX)
	{
		ImGui::Text("Index: -");
	}
	else
	{
		if (num_bytes < 0x100)
		{
			ImGui::Text("Index: 0x%02X", tick_byte_hover_index);
		}
		else if (num_bytes < 0x1000)
		{
			ImGui::Text("Index: 0x%03X", tick_byte_hover_index);
		}
		else if (num_bytes < 0x10000)
		{
			ImGui::Text("Index: 0x%04X", tick_byte_hover_index);
		}
		else if (num_bytes < 0x1000000)
		{
			ImGui::Text("Index: 0x%06X", tick_byte_hover_index);
		}
		else
		{
			ImGui::Text("Index: 0x%08X", tick_byte_hover_index);
		}
	}

	if (ImGui::BeginChild("test", {}, false, ImGuiWindowFlags_AlwaysVerticalScrollbar))
	{
		ImVec2 character_size = ImGui::CalcTextSize("X") + style.ItemSpacing;
		ImGui::CalcListClipping(num_rows, character_size.y, &display_items_start, &display_items_end);

		unsigned int byte_index = 0;
		for (unsigned int row_index = 0; row_index < num_rows; row_index++)
		{
			if (row_index >= static_cast<unsigned int>(display_items_start) && row_index < static_cast<unsigned int>(display_items_end))
			{

				unsigned int address = row_index * num_columns;

				unsigned int hover_row_index = tick_byte_hover_index / num_columns;
				if (hover_row_index == row_index)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.6f));
				}

				if (num_bytes < 0x100)
				{
					ImGui::Text("0x%02X", address);
				}
				else if (num_bytes < 0x1000)
				{
					ImGui::Text("0x%03X", address);
				}
				else if (num_bytes < 0x10000)
				{
					ImGui::Text("0x%04X", address);
				}
				else if (num_bytes < 0x1000000)
				{
					ImGui::Text("0x%06X", address);
				}
				else
				{
					ImGui::Text("0x%08X", address);
				}

				ImGui::PopStyleColor();

				ImGui::SameLine();
				unsigned int const column_byte_index_start = byte_index;
				for (unsigned int column_index = 0; column_index < num_columns; column_index++, byte_index++)
				{
					if (byte_index < num_bytes)
					{
						s_per_byte_context_association& per_byte_context_association = per_byte_context_associations[byte_index];
						c_serialization_context** per_byte_serialization_contexts = per_byte_memory_intervals.data() + per_byte_context_association.per_byte_memory_intervals_offset;

						char byte = bytes[byte_index];

						ImVec2 cursor_pos = ImGui::GetCursorPos();
						ImGui::PushStyleColor(ImGuiCol_Text, 0);
						ImGui::Text("%02hhX", byte);
						ImGui::PopStyleColor();

						ImGuiStyle& style = ImGui::GetStyle();
						ImVec2 min_rect = ImGui::GetItemRectMin();
						ImVec2 max_rect = ImGui::GetItemRectMax();
						min_rect -= style.ItemSpacing * 0.5f;
						max_rect += style.ItemSpacing * 0.5f;

						bool is_mouse_hover = ImGui::IsMouseHoveringRect(min_rect, max_rect);
						if (is_mouse_hover)
						{
							byte_hover_index = byte_index;

							ImGui::BeginTooltip();

							for (unsigned int per_byte_serialization_context_index = 0; per_byte_serialization_context_index < per_byte_context_association.per_byte_memory_intervals_count; per_byte_serialization_context_index++)
							{
								c_serialization_context& serialization_context = *per_byte_serialization_contexts[per_byte_serialization_context_index];
								unsigned int color_index = (per_byte_context_association.per_byte_memory_intervals_offset + per_byte_serialization_context_index) % _countof(colors);

								ImU32 color = border_colors[color_index];
								ImGui::PushStyleColor(ImGuiCol_Text, color);

								ImVec2 cursor_pos = ImGui::GetCursorPos();
								ImGui::TextUnformatted(serialization_context.name);
								//ImGui::TextUnformatted(interval.name);
								//ImVec2 cursor_pos_end = ImGui::GetCursorPos();
								//ImGui::SetCursorPos(cursor_pos + ImVec2{ 1.0f, 0.0f });
								//ImGui::TextUnformatted(interval.name);
								//ImGui::SetCursorPos(cursor_pos + ImVec2{ 0.0f, 1.0f });
								//ImGui::TextUnformatted(interval.name);
								//ImGui::SetCursorPos(cursor_pos + ImVec2{ 1.0f, 1.0f });
								//ImGui::TextUnformatted(interval.name);
								//ImGui::SetCursorPos(cursor_pos_end);

								ImGui::PopStyleColor();
							}

							ImGui::EndTooltip();
						}

						for (unsigned int per_byte_serialization_context_index = 0; per_byte_serialization_context_index < per_byte_context_association.per_byte_memory_intervals_count; per_byte_serialization_context_index++)
						{
							c_serialization_context& serialization_context = *per_byte_serialization_contexts[per_byte_serialization_context_index];
							unsigned int color_index = (per_byte_context_association.per_byte_memory_intervals_offset + per_byte_serialization_context_index) % _countof(colors);

							if (c_memory_hole_serialization_context* memory_hold_serialization_context = dynamic_cast<c_memory_hole_serialization_context*>(&serialization_context))
							{
								ImU32 border_color = hole_colors[color_index];
								if (memory_hold_serialization_context->data_start == bytes + byte_index)
								{
									draw_list.AddLine({ min_rect.x, min_rect.y + 1 }, { min_rect.x, max_rect.y - 1 }, border_color);
								}
								if (memory_hold_serialization_context->data_end == bytes + byte_index + 1)
								{
									draw_list.AddLine({ max_rect.x - 1, min_rect.y + 1 }, { max_rect.x - 1, max_rect.y - 1 }, border_color);
								}
								draw_list.AddLine({ min_rect.x, min_rect.y }, { max_rect.x, min_rect.y }, border_color);
								draw_list.AddLine({ min_rect.x, max_rect.y - 1 }, { max_rect.x, max_rect.y - 1 }, border_color);

								ImU32 hole_color = hole_colors[color_index];
								draw_list.AddRectFilled(min_rect, max_rect, hole_color);
							}
							else
							{
								ImU32 color = colors[color_index];
								draw_list.AddRectFilled(min_rect, max_rect, color);
							}
						}

						if (per_byte_context_association.per_byte_memory_intervals_count > 0)
						{
							if (per_byte_context_association.per_byte_memory_intervals_count > 1)
							{
								unsigned int alpha = __clamp(0, 255, 85 * (per_byte_context_association.per_byte_memory_intervals_count - 1));
								draw_list.AddLine({ min_rect.x, max_rect.y }, { max_rect.x, max_rect.y }, IM_COL32(255, 255, 0, alpha));
							}
							else
							{
								c_serialization_context& serialization_context = **per_byte_serialization_contexts;
								if (serialization_context.max_serialization_error_type > _serialization_error_type_ok)
								{
									ImVec4 serialization_error_color = serialization_error_colors[serialization_context.max_serialization_error_type];

									draw_list.AddLine(
										{ min_rect.x, max_rect.y },
										{ max_rect.x, max_rect.y },
										IM_COL32(
											255.0f * serialization_error_color.x,
											255.0f * serialization_error_color.y,
											255.0f * serialization_error_color.z,
											255.0f * serialization_error_color.w));
								}
							}
						}



						if (tick_byte_hover_index == byte_index)
						{
							if (per_byte_context_association.per_byte_memory_intervals_count > 1)
							{
								ImDrawList& draw_list = *ImGui::GetWindowDrawList();
								draw_list.AddRectFilled(min_rect, max_rect, IM_COL32(255, 0, 0, 127));
							}
							else
							{
								ImDrawList& draw_list = *ImGui::GetWindowDrawList();
								draw_list.AddRectFilled(min_rect, max_rect, IM_COL32(255, 255, 255, 50));
							}
						}

						{
							ImGui::SetCursorPos(cursor_pos);

							if (tick_byte_hover_index == byte_index)
							{
								ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
							}

							ImGui::Text("%02hhX", byte);

							if (tick_byte_hover_index == byte_index)
							{
								ImGui::PopStyleColor();
							}
						}
					}
					else
					{
						ImGui::TextUnformatted("  ");
					}
					ImGui::SameLine();
				}
				if (hover_row_index == row_index)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
				}
				else
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.6f));
				}
				ImGui::Text(" | ");
				ImGui::PopStyleColor();
				ImGui::SameLine();
				ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f });
				byte_index = column_byte_index_start;
				for (unsigned int column_index = 0; column_index < num_columns && byte_index < num_bytes; column_index++, byte_index++)
				{
					char byte = bytes[byte_index];

					if (tick_byte_hover_index == byte_index)
					{
						ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(1.00f));
					}
					else if (byte > 0 && isprint(byte))
					{
						ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.6f));
					}
					else
					{
						ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_TEXT(0.3f));
					}

					if (byte > 0 && isprint(byte))
					{
						ImGui::Text("%.1s", &byte);
					}
					else
					{
						ImGui::TextUnformatted(".");
					}

					ImGui::PopStyleColor();

					ImGui::SameLine();
				}
				ImGui::PopStyleVar();
				ImGui::Dummy({});

			}
			else
			{
				byte_index += num_columns;
				ImGui::TextUnformatted("");
			}
		}
	}
	ImGui::EndChild();

}
