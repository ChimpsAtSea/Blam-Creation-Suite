#include "tagreflection-private-pch.h"

h_tag::h_tag(h_group* group, const char* tag_filepath) :
	h_object(nullptr),
	tag_filepath(),
	tag_filename(),
	group(group)
{
	if (group != nullptr)
	{
		DEBUG_ASSERT(tag_filepath != nullptr);
		this->tag_filepath = tag_filepath;
		const char* tag_filename = filesystem_extract_filepath_filename(tag_filepath);
		this->tag_filename = tag_filename;
	}
}

h_tag::h_tag(h_type* parent) :
	h_object(parent),
	tag_filepath(),
	tag_filename(),
	group(nullptr)
{
}

h_tag::~h_tag()
{

}
