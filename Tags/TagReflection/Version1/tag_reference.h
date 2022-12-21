#pragma once

class h_tag_reference :
	public h_type
{
public:
	BCS_SHARED h_tag_reference(h_type* parent = nullptr);
	BCS_SHARED h_tag_reference(const h_tag_reference&);
	BCS_SHARED virtual ~h_tag_reference();

	virtual void set_tag(h_tag_instance* tag);
	virtual void set_group(h_tag_group* group);
	virtual void set_unqualified_file_path_without_extension(tag group_tag, const char* unqualified_path);
	virtual h_tag_instance* get_tag() const;
	virtual h_tag_group* get_group() const;
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
	bool group_qualified : 1;
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
			h_tag_instance* tag;
			h_tag_group* group;
		};
	};
};

template<typename t_parent_type, uint32_t _field_index>
using h_prototype_reference = h_tag_reference;
