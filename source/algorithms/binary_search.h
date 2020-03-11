#pragma once

/* ---------- prototypes/BINARY_SEARCH.CPP */

long binary_search_elements(
	void *,
	void *base_ptr,
	long count,
	unsigned long element_size,
	long(*search_function)(void *, void *, void *),
	void *);
