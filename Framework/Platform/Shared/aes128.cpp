#include "platform-private-pch.h"

static __m128i aes_128_key_expansion(__m128i key, __m128i keygened)
{
	keygened = _mm_shuffle_epi32(keygened, _MM_SHUFFLE(3, 3, 3, 3));
	key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
	key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
	key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
	return _mm_xor_si128(key, keygened);
}

static void aes128_generate_key_schedule(const __m128i* key, __m128i* key_schedule)
{
#define _aes_128_key_expansion(k, rcon) aes_128_key_expansion(k, _mm_aeskeygenassist_si128(k, rcon))

	key_schedule[0] = _mm_loadu_si128(key);
	key_schedule[1] = _aes_128_key_expansion(key_schedule[0], 0x01);
	key_schedule[2] = _aes_128_key_expansion(key_schedule[1], 0x02);
	key_schedule[3] = _aes_128_key_expansion(key_schedule[2], 0x04);
	key_schedule[4] = _aes_128_key_expansion(key_schedule[3], 0x08);
	key_schedule[5] = _aes_128_key_expansion(key_schedule[4], 0x10);
	key_schedule[6] = _aes_128_key_expansion(key_schedule[5], 0x20);
	key_schedule[7] = _aes_128_key_expansion(key_schedule[6], 0x40);
	key_schedule[8] = _aes_128_key_expansion(key_schedule[7], 0x80);
	key_schedule[9] = _aes_128_key_expansion(key_schedule[8], 0x1B);
	key_schedule[10] = _aes_128_key_expansion(key_schedule[9], 0x36);

#undef AES_128_key_exp
}

static void aes128_load_key(const __m128i* enc_key, __m128i* enc_key_schedule, __m128i* dec_key_schedule) {
	aes128_generate_key_schedule(enc_key, enc_key_schedule);

	dec_key_schedule[0] = enc_key_schedule[10];
	dec_key_schedule[1] = _mm_aesimc_si128(enc_key_schedule[9]);
	dec_key_schedule[2] = _mm_aesimc_si128(enc_key_schedule[8]);
	dec_key_schedule[3] = _mm_aesimc_si128(enc_key_schedule[7]);
	dec_key_schedule[4] = _mm_aesimc_si128(enc_key_schedule[6]);
	dec_key_schedule[5] = _mm_aesimc_si128(enc_key_schedule[5]);
	dec_key_schedule[6] = _mm_aesimc_si128(enc_key_schedule[4]);
	dec_key_schedule[7] = _mm_aesimc_si128(enc_key_schedule[3]);
	dec_key_schedule[8] = _mm_aesimc_si128(enc_key_schedule[2]);
	dec_key_schedule[9] = _mm_aesimc_si128(enc_key_schedule[1]);
	dec_key_schedule[10] = enc_key_schedule[0];
}

static void aes128_decrypt(const void* input, void* output, size_t bytes, const __m128i* key_schedule, const __m128i* iv)
{
#define AES128_DECRYPT() \
	result = _mm_xor_si128(result, key_schedule[0]); \
	result = _mm_aesdec_si128(result, key_schedule[1]); \
	result = _mm_aesdec_si128(result, key_schedule[2]); \
	result = _mm_aesdec_si128(result, key_schedule[3]); \
	result = _mm_aesdec_si128(result, key_schedule[4]); \
	result = _mm_aesdec_si128(result, key_schedule[5]); \
	result = _mm_aesdec_si128(result, key_schedule[6]); \
	result = _mm_aesdec_si128(result, key_schedule[7]); \
	result = _mm_aesdec_si128(result, key_schedule[8]); \
	result = _mm_aesdec_si128(result, key_schedule[9]); \
	result = _mm_aesdeclast_si128(result, key_schedule[10]); \
	result = _mm_xor_si128(result, previous_encrypted_value); \
	previous_encrypted_value = encrypted_value;

	__m128i previous_encrypted_value = {};
	if (iv != nullptr)
	{
		previous_encrypted_value = _mm_loadu_si128(iv);
	}

	constexpr uintptr_t unaligned_mask = (sizeof(__m128i) - 1);

	const __m128i* const input_vector_begin = static_cast<const __m128i*>(input);
	const __m128i* const input_vector_end = input_vector_begin + (bytes + unaligned_mask) / sizeof(__m128i);

	const __m128i* input_vector = input_vector_begin;
	__m128i* output_vector = static_cast<__m128i*>(output);

	if ((reinterpret_cast<uintptr_t>(input) | reinterpret_cast<uintptr_t>(output)) & unaligned_mask) // check if memory is aligned
	{
		// memory is not aligned

		while (input_vector < input_vector_end)
		{
			__m128i encrypted_value = _mm_loadu_si128(input_vector++);
			__m128i result = encrypted_value;
			AES128_DECRYPT();
			_mm_storeu_si128(output_vector++, result);
		}
	}
	else
	{
		// memory is aligned

		while (input_vector < input_vector_end)
		{
			__m128i encrypted_value = _mm_load_si128(input_vector++);
			__m128i result = encrypted_value;
			AES128_DECRYPT();
			//_mm_store_si128(output_vector++, result);
			_mm_stream_si128(output_vector++, result); // nontemporal memory store
		}

		_mm_sfence(); // wait for stores to complete
	}
#undef AES128_DECRYPT
}

void aes128_decrypt(const void* input, void* output, size_t bytes, const char* _iv)
{
	__m128i key = _mm_xor_si128(_mm_loadu_epi8(_iv), _mm_set1_epi8(0xA5i8));
	__m128i iv = _mm_xor_si128(key, _mm_set1_epi8(0x3Ci8));

	__m128i enc_key[11];
	__m128i dec_key[11];
	aes128_load_key(&key, enc_key, dec_key);

	aes128_decrypt(input, output, bytes, dec_key, &iv);
}
