#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/cache/cache_files.h>
#include <blamlib/memory/allocation_interface.h>
#include <blamlib/memory/wrapped_arrays.h>

/* ---------- types */

struct s_tag_interop
{
	dword descriptor;
	dword address;
	dword definition_address;
};
static_assert(sizeof(s_tag_interop) == 0xC);

/* ---------- classes */

class __declspec(novtable) c_tag_interop_verifier
{
public:
	virtual bool valid_buffer(
		c_basic_buffer<void> buffer) = 0;
};

/* ---------- prototypes/TAG_API_INTEROP.CPP */

bool tag_interop_fixup_manually_for_cache(
	s_tag_interop *interop_object,
	long cache_file_type_index,
	c_aligned_allocator *allocator,
	c_tag_interop_verifier *verifier);

void tag_interop_teardown_manually_for_cache(
	s_tag_interop *interop_object,
	long cache_file_type_index,
	c_aligned_allocator *allocator);

void *tag_interop_descriptor_get_with_size(
	s_tag_interop *interop_object,
	dword size);

void *tag_interop_descriptor_get(
	s_tag_interop *interop_object);

bool tag_interop_object_exists(
	s_tag_interop *interop_object);

/* ---------- templates */

template <typename t_element>
class c_typed_tag_interop :
	public s_tag_interop
{
};
