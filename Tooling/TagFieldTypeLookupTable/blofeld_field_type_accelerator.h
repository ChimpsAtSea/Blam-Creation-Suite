#pragma once

namespace blofeld
{
	// djb2 http://www.cse.yorku.ca/~oz/hash.html
#define blofeld_field_type_accelerator_hash(hash_name, string, seed) \
	uint32_t hash_name = seed; \
	{ \
		unsigned char const* str = reinterpret_cast<const unsigned char*>(string); \
		unsigned char c; \
		while (c = *str++) \
			hash = ((hash << 5) + hash) + c; /* hash * 33 + c */  \
	}

	class c_blofeld_field_type_accelerator
	{
	public:
		static constexpr uint32_t k_accelerator_seed = 1lu;
		static constexpr uint32_t k_accelerator_bits = 10lu;
		static constexpr uint32_t k_accelerator_table_size = 1lu << k_accelerator_bits;
		static constexpr uint32_t k_accelerator_bit_mask = k_accelerator_table_size - 1;
		static constexpr uint32_t k_expected_fields_count = 71lu;
#ifndef ALLOW_BLOFELD_FIELD_TYPE_ACCELERATOR_OUT_OF_DATE
		static_assert(k_number_of_blofeld_field_types == k_expected_fields_count);
#endif
		static_assert(k_number_of_blofeld_field_types < UCHAR_MAX);

		c_blofeld_field_type_accelerator();

		unsigned char field_type_by_index[k_accelerator_table_size];
		uint32_t hash_by_field_type[k_number_of_blofeld_field_types];

		BCS_RESULT get_value(const char* tag_field_type, e_field& field);
	};
}
