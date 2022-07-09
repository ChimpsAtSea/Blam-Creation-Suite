#pragma once

class h_group;

#define high_level_tag_ctor(...)
#define high_level_tag_dtor(...)

class h_tag :
	public h_prototype
{
protected:
	h_tag(h_group* group, const char* tag_filepath);
	h_tag(h_type* parent);

public:
	virtual ~h_tag();
	virtual const blofeld::s_tag_group& get_blofeld_group_definition() const = 0;

public: // #TODO: protected
	c_fixed_path tag_filepath;
	c_fixed_path tag_filename;
	h_group* group;

	//protected:
	//	h_tag(h_tag const&) = default;
};
