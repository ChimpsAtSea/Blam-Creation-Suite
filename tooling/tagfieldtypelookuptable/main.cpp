#include "tagfieldtypelookuptable-private-pch.h"

#include "blofeld_field_type_accelerator.inl"

using namespace blofeld;

union u_encoded_best_bits_and_seed
{
	struct
	{
		uint32_t seed;
		uint32_t bits;
	};
	uint64_t encoded;
};

const char* tag_field_type_strings[blofeld::k_number_of_blofeld_field_types];
volatile u_encoded_best_bits_and_seed g_encoded_best_bits_and_seed;
volatile uint64_t g_seed = 0;

uint32_t test_hash(uint32_t seed, uint32_t best_bits)
{
	uint32_t hashes[_countof(tag_field_type_strings)];

	for (uint32_t string_index = 0; string_index < _countof(tag_field_type_strings); string_index++)
	{
		const char* tag_field_type = tag_field_type_strings[string_index];
		blofeld_field_type_accelerator_hash(hash, tag_field_type, seed);
		hashes[string_index] = hash;
	}

	uint32_t bits = 1;
	do
	{
		uint32_t bit_mask = (1ul << bits) - 1;
		for (uint32_t i = 0; i < _countof(tag_field_type_strings); i++)
		{
			uint32_t bits_i = hashes[i] & bit_mask;
			for (uint32_t j = 0; j < _countof(tag_field_type_strings); j++)
			{
				uint32_t bits_j = hashes[j] & bit_mask;
				if (seed == 2 && i == blofeld::_field_string_id && j == blofeld::_field_real_point_2d)
				{
					debug_point;
				}
				if (bits_i == bits_j && i != j)
				{
					goto _continue;
				}
			}
		}
		break;
	_continue:;
	} while (++bits <= best_bits);

	debug_point;

	return bits;
}

DWORD WINAPI THREAD_START_ROUTINE(LPVOID lpThreadParameter)
{
#define WORKER_INCREMENT 0x20000
#define WORKER_RANGE 0x100000000
	uint64_t start_seed = atomic_addu64(&g_seed, WORKER_INCREMENT) - WORKER_INCREMENT;
	while (start_seed < 0x100000000 && g_encoded_best_bits_and_seed.bits > c_blofeld_field_type_accelerator::k_accelerator_bits)
	{
		uint32_t seed = static_cast<unsigned long>(start_seed);
		for (uint32_t j = 0; j < WORKER_INCREMENT; j++, seed++)
		{
			uint32_t bits = test_hash(seed, g_encoded_best_bits_and_seed.bits);
			while (bits < g_encoded_best_bits_and_seed.bits)
			{
				u_encoded_best_bits_and_seed encoded_best_bits_and_seed;
				encoded_best_bits_and_seed.seed = seed;
				encoded_best_bits_and_seed.bits = bits;

				uint64_t replace = g_encoded_best_bits_and_seed.encoded;
				uint64_t result = atomic_cmpxchgu64(
					&g_encoded_best_bits_and_seed.encoded,
					encoded_best_bits_and_seed.encoded,
					replace);

				if (result == replace)
				{
					console_write_line("Found new best seed 0x%lX for bits %lu", seed, bits);
				}
			}
		}
		console_write_line("Completed 0x%08llX -> 0x%08llX", start_seed, start_seed + WORKER_INCREMENT);

		start_seed = atomic_addu64(&g_seed, WORKER_INCREMENT) - WORKER_INCREMENT;
	}
	return 0;
}



int main()
{
	BCS_RESULT rs = BCS_S_OK;

	for (uint32_t field_index = 0; field_index < blofeld::k_number_of_blofeld_field_types; field_index++)
	{
		if (BCS_FAILED(rs = blofeld::field_to_tagfile_field_type(static_cast<blofeld::e_field>(field_index), tag_field_type_strings[field_index])))
		{
			return rs;
		}
	}

	g_encoded_best_bits_and_seed.seed = c_blofeld_field_type_accelerator::k_accelerator_seed;
	g_encoded_best_bits_and_seed.bits = test_hash(g_encoded_best_bits_and_seed.seed, 32);

	uint32_t thread_count = get_processors_thread_count();
	HANDLE* threads = static_cast<HANDLE*>(alloca(sizeof(HANDLE) * thread_count));
	for (uint32_t i = 0; i < thread_count; i++)
	{
		threads[i] = CreateThread(NULL, 0, THREAD_START_ROUTINE, 0, 0, NULL);
	}
	WaitForMultipleObjects(thread_count, threads, TRUE, INFINITE);

	console_write_line("Calculated accelerator parameters seed:0x%08lX bits:%lu", g_encoded_best_bits_and_seed.seed, g_encoded_best_bits_and_seed.bits);

	if (
		g_encoded_best_bits_and_seed.seed != c_blofeld_field_type_accelerator::k_accelerator_seed ||
		g_encoded_best_bits_and_seed.bits != c_blofeld_field_type_accelerator::k_accelerator_bits)
	{
		console_write_line("c_blofeld_field_type_accelerator needs update!");
		return BCS_E_FAIL; // return error code, make the need to change this visible
	}

	return rs;
}
