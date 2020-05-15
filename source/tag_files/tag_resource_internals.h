#pragma once

#include <cseries/cseries.h>
#include <memory/allocation_interface.h>
#include <memory/data.h>
#include <memory/wrapped_arrays.h>
#include <tag_files/tag_api_interop.h>
#include <tag_files/tag_vertex_buffers.h>

/* ---------- types */

enum e_tag_resource_priority
{
	// TODO
	k_number_of_tag_resource_priorities
};

inline e_tag_resource_priority &operator++(e_tag_resource_priority &priority)
{
	return priority = static_cast<e_tag_resource_priority>(static_cast<long>(priority) + 1);
}

inline e_tag_resource_priority &operator++(e_tag_resource_priority &priority, int)
{
	return priority = static_cast<e_tag_resource_priority>(static_cast<long>(priority) + 1);
}

enum e_tag_resource_fixup_type
{
	_tag_resource_fixup_type_unknown0,
	_tag_resource_fixup_type_unknown1,
	_tag_resource_fixup_type_unknown2,
	_tag_resource_fixup_type_unknown3,
	_tag_resource_fixup_type_unknown4,
	_tag_resource_fixup_type_unknown5,
	_tag_resource_fixup_type_unknown6,
	_tag_resource_fixup_type_unknown7,
	k_number_of_tag_resource_fixup_types
};

struct s_tag_resource_fixup_location
{
	dword block_offset;
	dword address;
};
static_assert(sizeof(s_tag_resource_fixup_location) == 0x8);

struct s_tag_resource_fixup_setup {};

struct s_tag_resource_interop_location
{
	dword address;
	long definition_index;
};
static_assert(sizeof(s_tag_resource_interop_location) == 0x8);

struct s_tag_resource_interop_fixup_setup {};

struct s_tag_resource
{
	c_datum_handle resource_handle;
	dword definition_address;
};
static_assert(sizeof(s_tag_resource) == 0x8);

/* ---------- classes */

class c_tag_resource_priority_iterator
{
private:
	e_tag_resource_priority m_priority;

public:
	c_tag_resource_priority_iterator(
		e_tag_resource_priority priority);

	e_tag_resource_priority get_priority() const;

	bool is_valid() const;

	c_tag_resource_priority_iterator &next();
};

class c_tag_resource_fixup
{
	enum
	{
		k_maximum_resource_fixup_value = 0x1FFFFFFF
	};

private:
	c_long_designator<k_number_of_tag_resource_fixup_types, 0> m_designator;

public:
	c_tag_resource_fixup();

	dword get_fixup_value() const;

	e_tag_resource_fixup_type get_type() const;

	void set_fixup_value(
		dword new_fixup_value);

	void set_type(
		e_tag_resource_fixup_type new_type);
};

class c_tag_resource_fixup_aligned_allocator :
	public c_aligned_allocator
{
private:
	c_basic_buffer<void> m_allocation_buffer;

public:
	c_tag_resource_fixup_aligned_allocator(
		c_basic_buffer<void> allocation_buffer);

	virtual ~c_tag_resource_fixup_aligned_allocator();

	void *allocate(
		dword size,
		dword alignment_bits);

	void deallocate(
		void *address,
		dword alignment_bits);
};

class c_tag_resource_interop_verifier :
	public c_tag_interop_verifier
{
public:
	c_tag_resource_interop_verifier(
		c_basic_buffer<void> buffer,
		c_static_array<c_basic_buffer<void>, 3> &array);

	virtual ~c_tag_resource_interop_verifier();

	bool valid_buffer(
		c_basic_buffer<void> buffer);
};

class c_tag_resource_page_handle
{
	// TODO
};

class c_tag_resource_page_table
{
public:
	/* TODO:
	try_to_load_more_looming_pages
	update_async_requests
	is_page_valid_but_not_loaded
	touch_page
	is_page_usable
	get_page_instance_from_handle
	update_status_lines
	is_page_loading
	get_page_cache
	initialize
	dispose
	allocate_storage
	initialize_for_new_map
	free_storage
	dispose_from_old_map
	prepare_for_disposal_from_old_map
	begin_tracking_page
	end_tracking_page
	add_page_control_reference
	remove_page_control_reference
	run_page_table_visitor
	quick_dump_memory_usage
	get_in_memory
	report_memory_usage
	persist_pages
	restore_pages
	restore_page
	load_required_pages_synchronous_io
	load_required_pages_nonblocking_io
	reserve_required_pages
	load_required_pages
	resize
	ensure_required_space
	get_total_available_size
	request_page_internal
	is_looming
	idle
	verify_internal_ready_state
	verify_all_internal_ready_states
	validate_all_pages
	request_page_async
	demand_page
	stitch_pages
	has_page_failed_to_load
	get_necessary_and_allocated_resource_space
	get_necessary_resource_space
	can_demand_more_pages_for_io
	can_demand_more_pages
	lock_prefetch_pages
	reset_due_to_zone_state_changes
	get_prefetch_paging_size
	prefetch_paging_progress
	are_all_prefetches_processed
	advance_to_next_unread_allocated_looming_page
	signal_stop_prefetching
	restart_prefetching
	is_prefetching_idle
	set_page_state
	mark_valid_page
	mark_valid_page_internal
	mark_prefetch_pages
	are_async_requests_done
	block_until_async_requests_done
	build_page_read_request
	flush_all_unnecessary_pages
	flush_optional_pages
	flush_unlocked_pages
	try_to_buyback_memory_from_unused_blocks
	try_to_reclaim_memory
	compact_pages
	shrink_to_used_size
	release_physical_allocation
	move_page_data
	clone_page_data
	get_page_instance_from_page_iterator
	cancel_async_and_block_until_async_done
	align_to_page_size
	can_get_page_data
	get_page_data_slow
	get_block_index
	get_page_size
	get_ready_pages
	advance_cache_frame
	reserve_page_data
	allocate_page_data
	flush_page_data
	flush_page_data_no_notification
	get_page_reservation
	set_page_reservation
	is_page_reservation_at_least
	is_page_reservation_at_most
	pin_page
	unpin_page
	is_page_pinned
	publish_segment
	delete_page_from_segment_cache
	is_page_locked_in_segment_cache
	get_page_lock_reason
	get_page_rank
	set_page_rank
	move_page_in_segment_cache
	clone_page_in_segment_cache
	can_move_page
	flag_page_for_defrag
	*/
};

/* ---------- prototypes/TAG_RESOURCE_INTERNALS.CPP */

bool tag_resource_not_empty(
	s_tag_resource *resource);

void tag_resource_fixup_data_references(
	c_basic_buffer<void> data_to_fixup,
	c_basic_buffer<void>,
	c_basic_buffer<void> *,
	c_basic_buffer<void> *,
	c_basic_buffer<void> *,
	c_wrapped_array<s_tag_resource_fixup_location> fixup_locations);

void tag_resource_fixup_cache_data_references(
	s_tag_resource_fixup_setup *fixup_setup,
	e_tag_resource_priority,
	c_basic_buffer<void> *,
	c_basic_buffer<void> *);

void tag_resource_tear_down_data_references(
	c_basic_buffer<void> data_to_fixup,
	c_wrapped_array<s_tag_resource_fixup_location> fixup_locations);

void tag_resource_tear_down_cache_data_references(
	s_tag_resource_fixup_setup *fixup_setup);

bool tag_resource_fixup_interops(
	s_tag_resource_interop_fixup_setup *interop_fixup_setup);

void tag_resource_teardown_interops(
	s_tag_resource_interop_fixup_setup *interop_fixup_setup);

void tag_resource_verify_not_locked(
	s_tag_resource_interop_fixup_setup *interop_fixup_setup);

/* ---------- templates */

template <typename t_element>
class c_typed_tag_resource :
	public s_tag_resource
{
public:
	bool is_not_empty() const
	{
		return tag_resource_not_empty(this);
	}
};
