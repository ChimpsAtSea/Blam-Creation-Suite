
#ifdef __INTELLISENSE__
using t_create_high_level_tag_ctor = h_tag * (h_group& group, const char* tag_filepath);
struct s_tag_ctor_pair
{
	blofeld::s_tag_group* tag_group;
	t_create_high_level_tag_ctor* ctor;
};
static s_tag_ctor_pair tag_ctors[1];

using t_create_high_level_object_ctor = h_prototype * ();
struct s_object_ctor_pair
{
	blofeld::s_tag_struct_definition* tag_struct_definition;
	t_create_high_level_object_ctor* ctor;
};
static s_object_ctor_pair object_ctors[1];
#endif

#ifdef HIGH_LEVEL_NO_TAG_CONSTRUCTORS

h_tag* create_high_level_tag(h_group& group, const char* tag_filepath)
{
	return nullptr;
}

#else


static h_tag* create_high_level_tag_binary_search(h_group& group, const char* tag_filepath)
{
#define get_tag_ctor_tag_group(tag_ctors, index) tag_ctors[search_middle].tag_group

	blofeld::s_tag_group const* tag_group = &group.tag_group;

	s_tag_ctor_pair* tag_ctor_search_result = nullptr;
	_binary_search(
		tag_ctors,
		_countof(tag_ctors),
		get_tag_ctor_tag_group,
		tag_group,
		tag_ctor_search_result);

	if (tag_ctor_search_result != nullptr)
	{
		h_tag* tag = tag_ctor_search_result->ctor(group, tag_filepath);
		return tag;
	}

	return nullptr;

#undef get_tag_ctor_tag_group
}

static h_tag* create_high_level_tag_firstrun(h_group& group, const char* tag_filepath);
static h_tag* (* volatile create_high_level_tag_pointer)(h_group& group, const char* tag_filepath) = create_high_level_tag_firstrun;

static h_tag* create_high_level_tag_wait_for_sort(h_group& group, const char* tag_filepath)
{
	while (create_high_level_tag_pointer == create_high_level_tag_wait_for_sort);
	return create_high_level_tag_pointer(group, tag_filepath);
}

static bool tag_ctor_pair_sort(s_tag_ctor_pair& a, s_tag_ctor_pair& b)
{
	return a.tag_group <= b.tag_group;
}

static h_tag* create_high_level_tag_firstrun(h_group& group, const char* tag_filepath)
{
	void* exchanged_value0 = _InterlockedCompareExchangePointer(
		reinterpret_cast<void* volatile*>(&create_high_level_tag_pointer),
		create_high_level_tag_wait_for_sort,
		create_high_level_tag_firstrun);
	bool first_run = exchanged_value0 == create_high_level_tag_firstrun;
	if (first_run)
	{
		std::sort(tag_ctors, tag_ctors + _countof(tag_ctors), tag_ctor_pair_sort);

		void* exchanged_value1 = _InterlockedCompareExchangePointer(
			reinterpret_cast<void* volatile*>(&create_high_level_tag_pointer),
			create_high_level_tag_binary_search,
			create_high_level_tag_wait_for_sort);
		ASSERT(exchanged_value1 == create_high_level_tag_wait_for_sort); // sanity
		ASSERT(create_high_level_tag_pointer == create_high_level_tag_binary_search); // sanity

		return create_high_level_tag_pointer(group, tag_filepath);
	}
	else
	{
		return create_high_level_tag_wait_for_sort(group, tag_filepath);
	}
}

h_tag* create_high_level_tag(h_group& group, const char* tag_filepath)
{
	return create_high_level_tag_pointer(group, tag_filepath);
}

#endif

#ifdef HIGH_LEVEL_NO_OBJECT_CONSTRUCTORS

h_prototype* create_high_level_object(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	return nullptr;
}

#else

static h_prototype* create_high_level_object_binary_search(blofeld::s_tag_struct_definition const& tag_struct_definition)
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
		h_prototype* object = object_ctor_search_result->ctor();
		return object;
	}

	return nullptr;

#undef get_object_ctor_tag_struct_definition
}

static h_prototype* create_high_level_object_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition);
static h_prototype* (* volatile create_high_level_object_pointer)(blofeld::s_tag_struct_definition const& tag_struct_definition) = create_high_level_object_firstrun;

static h_prototype* create_high_level_object_wait_for_sort(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	while (create_high_level_object_pointer == create_high_level_object_wait_for_sort);
	return create_high_level_object_pointer(tag_struct_definition);
}

static bool object_ctor_pair_sort(s_object_ctor_pair& a, s_object_ctor_pair& b)
{
	return a.tag_struct_definition <= b.tag_struct_definition;
}

static h_prototype* create_high_level_object_firstrun(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	void* exchanged_value0 = _InterlockedCompareExchangePointer(
		reinterpret_cast<void* volatile*>(&create_high_level_object_pointer),
		create_high_level_object_wait_for_sort,
		create_high_level_object_firstrun);
	bool first_run = exchanged_value0 == create_high_level_object_firstrun;
	if (first_run)
	{
		std::sort(object_ctors, object_ctors + _countof(object_ctors), object_ctor_pair_sort);

		void* exchanged_value1 = _InterlockedCompareExchangePointer(
			reinterpret_cast<void* volatile*>(&create_high_level_object_pointer),
			create_high_level_object_binary_search,
			create_high_level_object_wait_for_sort);
		ASSERT(exchanged_value1 == create_high_level_object_wait_for_sort); // sanity
		ASSERT(create_high_level_object_pointer == create_high_level_object_binary_search); // sanity

		return create_high_level_object_pointer(tag_struct_definition);
	}
	else
	{
		return create_high_level_object_wait_for_sort(tag_struct_definition);
	}
}

h_prototype* create_high_level_object(blofeld::s_tag_struct_definition const& tag_struct_definition)
{
	return create_high_level_object_pointer(tag_struct_definition);
}

#endif





