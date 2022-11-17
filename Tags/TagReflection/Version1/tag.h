#pragma once

class h_group;

#define high_level_tag_ctor(...)
#define high_level_tag_dtor(...)

class h_tag :
	public h_prototype
{
protected:
	h_tag(
		h_group* group,
		const char* relative_filepath_without_extension,
		const wchar_t* filesystem_path = nullptr);
	h_tag(h_type* parent);

public:
	virtual ~h_tag();
	virtual blofeld::s_tag_group const& get_blofeld_group_definition() const = 0;

	// subfolder\\example.group
	virtual const char* get_file_path() const;
	
	// example.group
	virtual const char* get_file_name() const;
	
	// .group
	virtual const char* get_file_extension() const;

	// subfolder\\example
	virtual const char* get_file_path_without_extension() const;
	
	// example
	virtual const char* get_file_name_without_extension() const;

	// C:\\tags\\subfolder\\example.group
	virtual const wchar_t* get_filesystem_path() const;

	virtual void generate_filepaths(const char* relative_filepath_without_extension, const wchar_t* filesystem_path = nullptr);

	h_group* group;
private:
	const char* relative_file_path;
	const char* relative_file_path_without_extension;
	const wchar_t* filesystem_path;
};
