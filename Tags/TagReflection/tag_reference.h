#pragma once

class h_tag_reference :
	public h_type
{
public:
	h_tag_reference(h_type* parent = nullptr);
	h_tag_reference(const h_tag_reference&);
	virtual ~h_tag_reference();

	virtual void set_tag(h_tag* tag);
	virtual void set_group(h_group* group);
	virtual void set_unqualified_path(tag group_tag, const char* unqualified_path);
	virtual h_tag* get_tag() const;
	virtual h_group* get_group() const;
	virtual const char* get_tag_path() const;
	virtual tag get_group_tag() const;
	virtual bool is_tag_qualified() const;
	virtual bool is_null() const;
	virtual bool is_unqualified() const;
	virtual void clear();

private:
	bool tag_qualified : 1;
	union
	{
		struct
		{
			const char* unqualified_path;
			tag group_tag;
		};
		struct
		{
			h_tag* tag;
			h_group* group;
		};
	};
};

template<typename parent_type, unsigned long _field_index>
class h_tag_reference_field :
	public h_tag_reference
{
public:
	h_tag_reference_field(h_type* parent = nullptr) :
		h_tag_reference(parent)
	{

	}
};
