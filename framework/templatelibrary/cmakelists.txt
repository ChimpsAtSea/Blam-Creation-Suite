add_library(TemplateLibrary ${BCS_LIBRARY_TYPE}
	atomic_lock.h
	auto_delete.h
	benchmark.h
	binary_search.h
	bitfield_allocator.h
	byteswap.h
	compile_time_accumulator.h
	fast_ascii_lookup.h
	fixed_string.h
	macros.h
	pointers.h
	runtime_task.h
	stack_string.h
	templatelibrary-private-pch.h
	templatelibrary-public-pch.h
	thread_safe_queue.h
	virtual.h
	xxhash_cx.h
	member_to_static_function.h
	string_lookup.h
	atomic_lock.cpp
	benchmark.cpp
	bitfield_allocator.cpp
	byteswap.cpp
	runtime_task.cpp
	stack_string.cpp
	# templatelibrary-private-pch.cpp
	virtual.cpp)

bcs_set_common_properties(TemplateLibrary)

target_link_libraries(TemplateLibrary PRIVATE
	Platform)

target_precompile_headers(TemplateLibrary PRIVATE
	"$<$<COMPILE_LANGUAGE:CXX>:templatelibrary-private-pch.h>")
	
set_target_properties(TemplateLibrary PROPERTIES
	FOLDER "!Framework")
