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
	virtual void set_unqualified_file_path_without_extension(tag group_tag, const char* unqualified_path);
	virtual h_tag* get_tag() const;
	virtual h_group* get_group() const;
	virtual const char* get_file_path_without_extension() const;
	virtual tag get_group_tag() const;
	virtual bool is_tag_qualified() const;
	virtual bool is_null() const;
	virtual bool is_unqualified() const;
	virtual void clear();

	virtual void _set_unqualified_userdata(tag group_tag, void* userdata); // tag parsing only!
	virtual void* _get_userdata() const; // tag parsing only!


private:
	bool tag_qualified : 1;
	bool tag_userdata : 1;
	union
	{
		struct
		{
			const char* file_path_without_extension;
			void* userdata;
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
