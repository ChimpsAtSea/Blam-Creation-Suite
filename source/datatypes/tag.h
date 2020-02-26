/*
TAG.H
Monday, February 24, 2020 9:16:15 AM

    A 32-bit human-readable identifier.
*/

#pragma once

/* ---------- types */

using tag = unsigned long;
static_assert(sizeof(tag) == 0x4);

/* ---------- prototypes/TAG.CPP */

char *tag_to_string(tag value, char (&string)[4]);
tag string_to_tag(const char *string);
