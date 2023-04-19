
#ifdef __INTELLISENSE__
using t_create_high_level_prototype_constructor = h_prototype * (h_prototype* copy_from_prototype);
struct s_prototype_constructor_pair
{
	blofeld::s_tag_struct_definition const* tag_struct_definition;
	t_create_high_level_prototype_constructor* constructor;
};
static s_prototype_constructor_pair prototype_constructors[1] = {};
#endif

#ifdef HIGH_LEVEL_NO_PROTOTYPES

h_prototype* create_high_level_prototype(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	return nullptr;
}

#else

static h_prototype* create_high_level_prototype_binary_search(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
#define get_prototype_constructor_tag_struct_definition(prototype_constructors, index) prototype_constructors[search_middle].tag_struct_definition

	s_prototype_constructor_pair* prototype_constructor_search_result = nullptr;
	_binary_search(
		prototype_constructors,
		_countof(prototype_constructors),
		get_prototype_constructor_tag_struct_definition,
		&tag_struct_definition,
		prototype_constructor_search_result);

	if (prototype_constructor_search_result != nullptr)
	{
		h_prototype* prototype = prototype_constructor_search_result->constructor(copy_from_prototype);
		return prototype;
	}

	return nullptr;

#undef get_prototype_constructor_tag_struct_definition
}

static h_prototype* create_high_level_prototype_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype);
static h_prototype* (* volatile create_high_level_prototype_pointer)(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype) = create_high_level_prototype_firstrun;

static h_prototype* create_high_level_prototype_wait_for_sort(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	while (create_high_level_prototype_pointer == create_high_level_prototype_wait_for_sort);
	return create_high_level_prototype_pointer(tag_struct_definition, copy_from_prototype);
}

static bool prototype_constructor_pair_sort(s_prototype_constructor_pair& a, s_prototype_constructor_pair& b)
{
	return a.tag_struct_definition <= b.tag_struct_definition;
}

static h_prototype* create_high_level_prototype_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	void* exchanged_value0 = _InterlockedCompareExchangePointer(
		reinterpret_cast<void* volatile*>(&create_high_level_prototype_pointer),
		reinterpret_cast<void*>(&create_high_level_prototype_wait_for_sort),
		reinterpret_cast<void*>(&create_high_level_prototype_firstrun));
	bool first_run = exchanged_value0 == create_high_level_prototype_firstrun;
	if (first_run)
	{
		std::sort(prototype_constructors, prototype_constructors + _countof(prototype_constructors), prototype_constructor_pair_sort);

		void* exchanged_value1 = _InterlockedCompareExchangePointer(
			reinterpret_cast<void* volatile*>(&create_high_level_prototype_pointer),
			reinterpret_cast<void*>(&create_high_level_prototype_binary_search),
			reinterpret_cast<void*>(&create_high_level_prototype_wait_for_sort));
		DEBUG_ASSERT(exchanged_value1 == create_high_level_prototype_wait_for_sort); // sanity
		DEBUG_ASSERT(create_high_level_prototype_pointer == create_high_level_prototype_binary_search); // sanity

		return create_high_level_prototype_pointer(tag_struct_definition, copy_from_prototype);
	}
	else
	{
		return create_high_level_prototype_wait_for_sort(tag_struct_definition, copy_from_prototype);
	}
}

h_prototype* create_high_level_prototype(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	return create_high_level_prototype_pointer(tag_struct_definition, copy_from_prototype);
}

#endif





