#pragma once

class h_field :
	public h_type
{
public:

#ifndef BCS_IS_HIGH_LEVEL_BUILD_PROJECT
	explicit h_field() = delete;
	explicit h_field(h_prototype& parent) = delete;
	explicit h_field(h_field const&) = delete;
	virtual ~h_field();
#else
	explicit h_field() = delete;
	explicit h_field(h_prototype& parent);
	explicit h_field(h_field const&) = delete;
	virtual ~h_field() = default;
#endif

	virtual void const* get_data() const = 0;
	virtual void* get_data() = 0;
};
