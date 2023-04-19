
#ifdef __INTELLISENSE__
struct s_prototype_serialization_info_pair
{
	blofeld::s_tag_struct_definition const* tag_struct_definition;
	h_prototype_serialization_info const* prototype_serialization_info;
};
static s_prototype_serialization_info_pair prototype_serialization_infos[1] = {};
#endif

#ifdef HIGH_LEVEL_NO_PROTOTYPES

h_prototype_serialization_info const* get_high_level_prototype_serialization_info(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	throw; // why request a prototype when they're aren't any???
}

#else

h_prototype_serialization_info const* get_high_level_prototype_serialization_info_binary_search(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
#define get_prototype_serialization_info_tag_struct_definition(prototype_serialization_infos, index) prototype_serialization_infos[search_middle].tag_struct_definition

	s_prototype_serialization_info_pair* prototype_serialization_info_search_result = nullptr;
	_binary_search(
		prototype_serialization_infos,
		_countof(prototype_serialization_infos),
		get_prototype_serialization_info_tag_struct_definition,
		&tag_struct_definition,
		prototype_serialization_info_search_result);

	if (prototype_serialization_info_search_result != nullptr)
	{
		return prototype_serialization_info_search_result->prototype_serialization_info;
	}

	return nullptr;

#undef get_prototype_serialization_info_tag_struct_definition
}

static h_prototype_serialization_info const* get_high_level_prototype_serialization_info_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition);
static h_prototype_serialization_info const* (* volatile get_high_level_prototype_serialization_info_pointer)(blofeld::s_tag_struct_definition const& tag_struct_definition) = get_high_level_prototype_serialization_info_firstrun;

static h_prototype_serialization_info const* get_high_level_prototype_serialization_info_wait_for_sort(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	while (get_high_level_prototype_serialization_info_pointer == get_high_level_prototype_serialization_info_wait_for_sort);
	return get_high_level_prototype_serialization_info_pointer(tag_struct_definition);
}

static bool prototype_serialization_info_pair_sort(s_prototype_serialization_info_pair& a, s_prototype_serialization_info_pair& b)
{
	return a.tag_struct_definition <= b.tag_struct_definition;
}

static h_prototype_serialization_info const* get_high_level_prototype_serialization_info_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	void* exchanged_value0 = _InterlockedCompareExchangePointer(
		reinterpret_cast<void* volatile*>(&get_high_level_prototype_serialization_info_pointer),
		reinterpret_cast<void*>(&get_high_level_prototype_serialization_info_wait_for_sort),
		reinterpret_cast<void*>(&get_high_level_prototype_serialization_info_firstrun));
	bool first_run = exchanged_value0 == get_high_level_prototype_serialization_info_firstrun;
	if (first_run)
	{
		std::sort(prototype_serialization_infos, prototype_serialization_infos + _countof(prototype_serialization_infos), prototype_serialization_info_pair_sort);

		void* exchanged_value1 = _InterlockedCompareExchangePointer(
			reinterpret_cast<void* volatile*>(&get_high_level_prototype_serialization_info_pointer),
			reinterpret_cast<void*>(&get_high_level_prototype_serialization_info_binary_search),
			reinterpret_cast<void*>(&get_high_level_prototype_serialization_info_wait_for_sort));
		ASSERT(exchanged_value1 == get_high_level_prototype_serialization_info_wait_for_sort); // sanity
		ASSERT(get_high_level_prototype_serialization_info_pointer == get_high_level_prototype_serialization_info_binary_search); // sanity

		return get_high_level_prototype_serialization_info_pointer(tag_struct_definition);
	}
	else
	{
		return get_high_level_prototype_serialization_info_wait_for_sort(tag_struct_definition);
	}
}

h_prototype_serialization_info const* get_high_level_prototype_serialization_info(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	return get_high_level_prototype_serialization_info_pointer(tag_struct_definition);
}

#endif
