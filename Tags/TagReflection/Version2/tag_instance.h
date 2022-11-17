#pragma once

class h_tag_group;

class h_tag_instance
{
public:
	h_tag_instance(h_tag_instance const&) = delete;
	BCS_SHARED h_tag_instance(
		h_prototype& prototype,
		h_tag_group& tag_group,
		const char* relative_filepath_without_extension,
		const wchar_t* filesystem_path = nullptr);

public:
	virtual ~h_tag_instance();

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

public:
	h_prototype& prototype;
	h_tag_group& tag_group;
private:
	const char* relative_file_path;
	const char* relative_file_path_without_extension;
	const wchar_t* filesystem_path;
};
