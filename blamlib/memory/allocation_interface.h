#pragma once

/* ---------- classes */

class __declspec(novtable) c_allocation_interface
{
public:
	virtual void *allocate(
		unsigned long size,
		char const *file,
		long line,
		char const *variable,
		char const *type,
		char const *name) = 0;

	virtual void deallocate(
		void *address,
		char const *file,
		long line) = 0;
};

class __declspec(novtable) c_aligned_allocator
{
public:
	virtual void *allocate(
		dword size,
		dword alignment_bits) = 0;

	virtual void deallocate(
		void *address,
		dword alignment_bits) = 0;
};
