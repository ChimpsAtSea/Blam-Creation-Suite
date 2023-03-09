#include "tagreflection-private-pch.h"

h_tag_instance::h_tag_instance(
	h_prototype& _prototype,
	h_tag_group& _tag_group,
	const char* _relative_filepath_without_extension,
	const wchar_t* _filesystem_path) :
	prototype(_prototype),
	tag_group(_tag_group),
	relative_file_path(),
	relative_file_path_without_extension(),
	filesystem_path()
{
	generate_filepaths(_relative_filepath_without_extension, _filesystem_path);
}

h_tag_instance::~h_tag_instance()
{
	trivial_free(relative_file_path);
	untracked_free(relative_file_path_without_extension);
	untracked_free(filesystem_path);
}

const char* h_tag_instance::get_file_path() const
{
	return relative_file_path;
}

const char* h_tag_instance::get_file_name() const
{
	return filesystem_extract_filepath_filename(relative_file_path);
}

const char* h_tag_instance::get_file_extension() const
{
	return filesystem_extract_filepath_extension(relative_file_path);
}

const char* h_tag_instance::get_file_path_without_extension() const
{
	return relative_file_path_without_extension;
}

const char* h_tag_instance::get_file_name_without_extension() const
{
	return filesystem_extract_filepath_filename(relative_file_path_without_extension);
}

const wchar_t* h_tag_instance::get_filesystem_path() const
{
	return filesystem_path;
}

void h_tag_instance::generate_filepaths(const char* _relative_filepath_without_extension, const wchar_t* _filesystem_path)
{
	blofeld::s_tag_group const& blofeld_tag_group = tag_group.blofeld_tag_group;

	trivial_free(relative_file_path);
	untracked_free(relative_file_path_without_extension);
	untracked_free(filesystem_path);

	relative_file_path = nullptr;
	relative_file_path_without_extension = nullptr;
	filesystem_path = nullptr;

	char* relative_file_path_without_extension_buffer = _strdup(_relative_filepath_without_extension);
	filesystem_remove_filepath_extension(relative_file_path_without_extension_buffer); // make sure file extension is removed

	relative_file_path_without_extension = relative_file_path_without_extension_buffer;

	int relative_file_path_characters = snprintf(nullptr, 0, "%s.%s", relative_file_path_without_extension, blofeld_tag_group.name);
	char* relative_file_path_buffer = trivial_malloc(char, relative_file_path_characters + 1);
	snprintf(relative_file_path_buffer, relative_file_path_characters + 1, "%s.%s", relative_file_path_without_extension, blofeld_tag_group.name);
	relative_file_path = relative_file_path_buffer;

	if (filesystem_path)
	{
		filesystem_path = _wcsdup(_filesystem_path);
	}
}
