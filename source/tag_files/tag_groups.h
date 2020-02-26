/*
TAG_GROUPS.H
Saturday, February 22, 2020 2:18:21 PM
*/

#pragma once

#include <stddef.h>

#include <datatypes/flags.h>
#include <datatypes/tag.h>

#include <memory/ptr32.h>

/* ---------- types */

struct s_tag_block_definition
{
    __pragma(message("TODO: implement s_tag_block_definition"))
};

struct s_tag_block
{
    long count;
    c_ptr32<unsigned char> address;
    c_ptr32<s_tag_block_definition> definition;
};

struct s_tag_data_definition
{
    __pragma(message("TODO: implement s_tag_data_definition"))
};

enum e_tag_data_stream_flags
{
    __pragma(message("TODO: implement e_tag_data_stream_flags"))
    k_number_of_tag_data_stream_flags
};

struct s_tag_data
{
    long size;

    c_flags<e_tag_data_stream_flags, unsigned long,
        k_number_of_tag_data_stream_flags> stream_flags;

    unsigned long stream_position;

    c_ptr32<unsigned char> address;
    c_ptr32<s_tag_block_definition> definition;
};

struct s_tag_reference
{
    tag group_tag;
    c_ptr32<char> name;
    long name_length;
    long index;
};
