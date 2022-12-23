#pragma once

class h_type :
	public t_virtual
{
public:

	BCS_SHARED h_type(h_type* parent = nullptr);
	BCS_SHARED virtual ~h_type();

#if !defined(__INTELLISENSE__) || defined(BCS_IS_HIGH_LEVEL_BUILD_PROJECT)
	BCS_SHARED void _set_parent(h_type* parent); // hack for h_array constructor
#endif

protected:
	h_type(h_type const&) = default;

	h_type* parent;
};
