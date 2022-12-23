#pragma once

/* ---------- prototypes/BINARY_SEARCH.CPP */

int binary_search_elements(
	void *,
	void *base_ptr,
	int count,
	unsigned int element_size,
	long(*search_function)(void *, void *, void *),
	void *);
