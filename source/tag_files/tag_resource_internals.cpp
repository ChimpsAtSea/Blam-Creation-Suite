#include "tag_resource_internals.h"

/* ---------- code */

c_tag_resource_fixup::c_tag_resource_fixup()
{
	m_designator.set_raw_designator(0);
}

dword c_tag_resource_fixup::get_fixup_value() const
{
	auto fixup_value = m_designator.get_primary_index();
	assert(IN_RANGE_INCLUSIVE(fixup_value, 0, k_maximum_resource_fixup_value));
	return static_cast<dword>(fixup_value);
}

e_tag_resource_fixup_type c_tag_resource_fixup::get_type() const
{
	return static_cast<e_tag_resource_fixup_type>(
		m_designator.get_secondary_index());
}

void c_tag_resource_fixup::set_fixup_value(
	dword new_fixup_value)
{
	m_designator.set_primary_index(
		static_cast<long>(new_fixup_value));
}

void c_tag_resource_fixup::set_type(
	e_tag_resource_fixup_type new_type)
{
	m_designator.set_secondary_index(
		static_cast<long>(new_type));
}

c_tag_resource_priority_iterator::c_tag_resource_priority_iterator(
	e_tag_resource_priority priority) :
	m_priority(priority)
{
}

e_tag_resource_priority c_tag_resource_priority_iterator::get_priority() const
{
	return m_priority;
}

bool c_tag_resource_priority_iterator::is_valid() const
{
	return m_priority < k_number_of_tag_resource_priorities;
}

c_tag_resource_priority_iterator &c_tag_resource_priority_iterator::next()
{
	m_priority++;
	return *this;
}
