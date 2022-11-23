#pragma once

class h_resource;

class h_resource_field :
	public h_field
{
public:
	BCS_SHARED h_resource_field() = delete;
	BCS_SHARED h_resource_field(h_prototype& parent);
	//BCS_SHARED h_resource_field(h_resource* resource);
	BCS_SHARED h_resource_field(h_resource_field const& resource) = delete;
	BCS_SHARED ~h_resource_field();

public:
	BCS_SHARED h_resource* get_resource() const;
	BCS_SHARED void set_resource(h_resource* resource);
	BCS_SHARED void clear();
	BCS_SHARED h_resource_field& operator=(h_resource_field const& resource_field);
	BCS_SHARED h_resource_field& operator=(h_resource* const& resource);
	BCS_SHARED bool operator==(h_resource_field const& resource_field) const;
	BCS_SHARED bool operator==(h_resource* const& resource) const;
	BCS_SHARED bool operator!=(h_resource_field const& resource_field) const;
	BCS_SHARED bool operator!=(h_resource* const& resource) const;

protected:
	virtual void const* get_data() const override;
	virtual void* get_data() override;
	h_resource* resource;
};

#ifdef BCS_HIGH_LEVEL_USE_TRIVIAL_FIELDS

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_resource_field = h_resource_field;

#else

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_resource_field = h_resource_field;

#endif
