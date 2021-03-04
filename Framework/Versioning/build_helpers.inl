#pragma once

#define MAKE_FILE_VERSION(a, b, c, d) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 16) | (uint64_t(d) << 0))
#define MAKE_PRODUCT_VERSION(a, b, c) ((uint64_t(a) << 48) | (uint64_t(b) << 32) | (uint64_t(c) << 0))
#define MAKE_TOOL_VERSION(a, b, c, d, file_description, product_name) (MAKE_FILE_VERSION(a, b, c, d) ^ (file_description##product_name##_xxh64))
#define HASH_VERSION(a) (a)
