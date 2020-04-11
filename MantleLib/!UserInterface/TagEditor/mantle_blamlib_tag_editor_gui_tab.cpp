#include "mantlelib-private-pch.h"

// REFLECTION V2 EXAMPLE CONTENT

enum e_some_enum : uint16_t
{
	_some_enum_value0
};

struct s_some_structure
{
	e_some_enum some_value0;
	int32_t some_value1;
	int32_t some_value2;
};

struct s_some_other_structure
{
	int32_t some_value0;
	int32_t some_value1;
};

union s_some_union
{
	s_some_structure some_structure;
	s_some_other_structure some_other_structure;
};

// approximately... a big contiguous chunk of all types (who knows what the compilers gonna do?)
const s_reflection_type int32_t_type_info = s_reflection_type(_reflection_type_class_int, sizeof(int32_t), "int32_t", "Int32", "32bit Signed Integer");
const s_reflection_enum e_some_enum_type_info = s_reflection_enum(_reflection_type_class_enum, sizeof(e_some_enum), "e_some_enum", "Some Enum", "An enum of some sort", &g_enum_names[0], 1);
const s_reflection_structure s_some_structure_type_info = s_reflection_structure(_reflection_type_class_structure, sizeof(s_some_structure), "s_some_structure", "Some Structure", "A structure of some kind that does a thing", nullptr, &g_fields[0], 3);
const s_reflection_structure s_some_other_structure_type_info = s_reflection_structure(_reflection_type_class_structure, sizeof(s_some_structure), "s_some_other_structure", "Some Other Structure", "A structure of some kind that does a thing that isn't that other thing", nullptr, &g_fields[3], 2);
const s_reflection_structure s_some_union_type_info = s_reflection_structure(_reflection_type_class_structure, sizeof(s_some_union), "s_some_union", "Some Union", "A union that holds a couple of structures", nullptr, &g_fields[5], 2);

#define memberoffset(s,m) (uint32_t)((size_t)&(((s*)0)->m))

// big contiguous chunk of all fields
const s_reflection_member g_fields[] =
{
	// s_some_structure (3 fields)
	s_reflection_member(s_some_structure_type_info, sizeof(uint16_t), memberoffset(s_some_structure, some_value0), e_some_enum_type_info, "some_value0", "Some Value 0", "A value that stores something"), // enum with a different underlying size
	s_reflection_member(s_some_structure_type_info, sizeof(int32_t), memberoffset(s_some_structure, some_value1), int32_t_type_info, "some_value1", "Some Value 1", "A value that stores something"),
	s_reflection_member(s_some_structure_type_info, sizeof(int32_t), memberoffset(s_some_structure, some_value1), int32_t_type_info, "some_value2", "Some Value 2", "A value that stores something"),

	// s_some_other_structure (2 fields)
	s_reflection_member(s_some_other_structure_type_info, sizeof(int32_t), memberoffset(s_some_other_structure, some_value1), int32_t_type_info, "some_value0", "Some Value 0", "A value that stores something"),
	s_reflection_member(s_some_other_structure_type_info, sizeof(int32_t), memberoffset(s_some_other_structure, some_value1), int32_t_type_info, "some_value1", "Some Value 1", "A value that stores something"),

	// s_some_union (2 fields)
	s_reflection_member(s_some_union_type_info, sizeof(s_some_structure), memberoffset(s_some_other_structure, some_value1), s_some_structure_type_info, "some_value0", "Union Value A", "A value that stores something"),
	s_reflection_member(s_some_union_type_info, sizeof(s_some_other_structure), memberoffset(s_some_other_structure, some_value1), s_some_other_structure_type_info, "some_value1", "Union Value B", "A value that stores something"),

};

#undef memberoffset

// big contiguous chunk of all enum names
const s_reflection_enum_name g_enum_names[] =
{
	// e_some_enum_type_info (1 name)
	s_reflection_enum_name(e_some_enum_type_info, 100, "_some_enum_value_a", "Value A", "The first value of an enum"),
};

template<> const s_reflection_enum& enum_reflection<e_some_enum>() { return e_some_enum_type_info; }
template<> const s_reflection_structure& structure_reflection<s_some_structure>() { return s_some_structure_type_info; }
template<> const s_reflection_structure& structure_reflection<s_some_other_structure>() { return s_some_other_structure_type_info; }
template<> const s_reflection_structure& structure_reflection<s_some_union>() { return s_some_union_type_info; }

// REFLECTION V2 EXAMPLE CONTENT


c_mantle_blamlib_tag_editor_gui_tab::c_mantle_blamlib_tag_editor_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, c_tag_interface& tag_interface) :
	c_mantle_gui_tab("Blamlib Tag Editor", "Blamlib Tag Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	tag_interface(tag_interface)
{
	allow_close = false;
}

c_mantle_blamlib_tag_editor_gui_tab::~c_mantle_blamlib_tag_editor_gui_tab()
{

}

void c_mantle_blamlib_tag_editor_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Hello Blamlib!");

	static s_some_union union_data{};
	char* data_ptr = reinterpret_cast<char*>(&union_data);

	const s_reflection_structure& union_reflection = reflection<s_some_union>();

	for (const s_reflection_member& member : union_reflection)
	{
		ImGui::Text("%s '%s'", member.type->nice_name, member.nice_name);
	}
}
