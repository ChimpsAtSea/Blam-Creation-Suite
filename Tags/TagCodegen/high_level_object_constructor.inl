
#ifdef HIGH_LEVEL_NO_TAG_CONSTRUCTORS

h_tag* create_high_level_tag(h_group& group, const char* tag_filepath)
{
	return nullptr;
}

#else

static h_tag* create_high_level_tag_binary_search(h_group& group, const char* tag_filepath)
{
	t_create_high_level_tag_ctor* binary_search_result = nullptr;
	unsigned long search_index = 0;
	unsigned long search_end = _countof(tag_ctors) - 1;
	while (search_index <= search_end)
	{
		unsigned long search_middle = (search_index + search_end) / 2;

		const blofeld::s_tag_group* middle_tag_group = tag_ctors[search_middle].tag_group;
		if (middle_tag_group == &group.tag_group)
		{
			binary_search_result = tag_ctors[search_middle].ctor;
			break;
		}
		else if (middle_tag_group < &group.tag_group)
		{
			search_index = search_middle + 1;
		}
		else //if (middle_tag_struct_definition > &tag_struct_definition)
		{
			search_end = search_middle - 1;
		}
	}

	if (binary_search_result != nullptr)
	{
		h_tag* tag = binary_search_result(group, tag_filepath);
		return tag;
	}

	return nullptr;
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

h_object* create_high_level_object(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	return nullptr;
}

#else

static h_object* create_high_level_object_binary_search(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	t_create_high_level_object_ctor* binary_search_result = nullptr;
	unsigned long search_index = 0;
	unsigned long search_end = _countof(object_ctors) - 1;
	while (search_index <= search_end)
	{
		unsigned long search_middle = (search_index + search_end) / 2;

		blofeld::s_tag_struct_definition* middle_tag_struct_definition = object_ctors[search_middle].tag_struct_definition;
		if (middle_tag_struct_definition == &tag_struct_definition)
		{
			binary_search_result = object_ctors[search_middle].ctor;
			break;
		}
		else if (middle_tag_struct_definition < &tag_struct_definition)
		{
			search_index = search_middle + 1;
		}
		else //if (middle_tag_struct_definition > &tag_struct_definition)
		{
			search_end = search_middle - 1;
		}
	}

	if (binary_search_result != nullptr)
	{
		h_object* object = binary_search_result();
		return object;
	}

	return nullptr;
}

static h_object* create_high_level_object_firstrun(const blofeld::s_tag_struct_definition& tag_struct_definition);
static h_object* (* volatile create_high_level_object_pointer)(const blofeld::s_tag_struct_definition& tag_struct_definition) = create_high_level_object_firstrun;

static h_object* create_high_level_object_wait_for_sort(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	while (create_high_level_object_pointer == create_high_level_object_wait_for_sort);
	return create_high_level_object_pointer(tag_struct_definition);
}

static bool object_ctor_pair_sort(s_object_ctor_pair& a, s_object_ctor_pair& b)
{
	return a.tag_struct_definition <= b.tag_struct_definition;
}

static h_object* create_high_level_object_firstrun(const blofeld::s_tag_struct_definition& tag_struct_definition)
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

h_object* create_high_level_object(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	return create_high_level_object_pointer(tag_struct_definition);
}

#endif





