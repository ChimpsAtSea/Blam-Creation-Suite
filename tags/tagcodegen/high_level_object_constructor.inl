
#ifdef __INTELLISENSE__
using t_create_high_level_object_ctor = h_prototype * (h_prototype* copy_from_prototype);
struct s_object_ctor_pair
{
	blofeld::s_tag_struct_definition* tag_struct_definition;
	t_create_high_level_object_ctor* ctor;
};
static s_object_ctor_pair object_ctors[1];
#endif

#ifdef HIGH_LEVEL_NO_OBJECT_CONSTRUCTORS

h_prototype* create_high_level_object(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	return nullptr;
}

#else

static h_prototype* create_high_level_object_binary_search(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
#define get_object_ctor_tag_struct_definition(object_ctors, index) object_ctors[search_middle].tag_struct_definition

	s_object_ctor_pair* object_ctor_search_result = nullptr;
	_binary_search(
		object_ctors,
		_countof(object_ctors),
		get_object_ctor_tag_struct_definition,
		&tag_struct_definition,
		object_ctor_search_result);

	if (object_ctor_search_result != nullptr)
	{
		h_prototype* object = object_ctor_search_result->ctor(copy_from_prototype);
		return object;
	}

	return nullptr;

#undef get_object_ctor_tag_struct_definition
}

static h_prototype* create_high_level_object_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype);
static h_prototype* (* volatile create_high_level_object_pointer)(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype) = create_high_level_object_firstrun;

static h_prototype* create_high_level_object_wait_for_sort(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	while (create_high_level_object_pointer == create_high_level_object_wait_for_sort);
	return create_high_level_object_pointer(tag_struct_definition, copy_from_prototype);
}

static bool object_ctor_pair_sort(s_object_ctor_pair& a, s_object_ctor_pair& b)
{
	return a.tag_struct_definition <= b.tag_struct_definition;
}

static h_prototype* create_high_level_object_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	void* exchanged_value0 = _InterlockedCompareExchangePointer(
		reinterpret_cast<void* volatile*>(&create_high_level_object_pointer),
		reinterpret_cast<void*>(&create_high_level_object_wait_for_sort),
		reinterpret_cast<void*>(&create_high_level_object_firstrun));
	bool first_run = exchanged_value0 == create_high_level_object_firstrun;
	if (first_run)
	{
		std::sort(object_ctors, object_ctors + _countof(object_ctors), object_ctor_pair_sort);

		void* exchanged_value1 = _InterlockedCompareExchangePointer(
			reinterpret_cast<void* volatile*>(&create_high_level_object_pointer),
			reinterpret_cast<void*>(&create_high_level_object_binary_search),
			reinterpret_cast<void*>(&create_high_level_object_wait_for_sort));
		ASSERT(exchanged_value1 == create_high_level_object_wait_for_sort); // sanity
		ASSERT(create_high_level_object_pointer == create_high_level_object_binary_search); // sanity

		return create_high_level_object_pointer(tag_struct_definition, copy_from_prototype);
	}
	else
	{
		return create_high_level_object_wait_for_sort(tag_struct_definition, copy_from_prototype);
	}
}

h_prototype* create_high_level_object(blofeld::s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype)
{
	return create_high_level_object_pointer(tag_struct_definition, copy_from_prototype);
}

#endif





