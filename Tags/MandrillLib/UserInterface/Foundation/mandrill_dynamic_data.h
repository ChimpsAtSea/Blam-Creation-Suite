#pragma once

class s_mandrill_dynamic_data
{
public:
	non_copyable(s_mandrill_dynamic_data);

	// #WARN This structure should be kept as small as possible
	// to avoid excessive cache misses. Maybe it is worth looking
	// into a way to allocate these in multiples of smaller 
	// allocations?
	// #NOTE Make the assumption that cache lines are 64bytes
	// (512 bits) wide. 64, 128, 192, 256, 320 etc.

	using c_imgui_dynamic_data = std::pair<void*, char[256 - sizeof(intptr_t)]>;
	static_assert(sizeof(c_imgui_dynamic_data) == 256);

	// #TODO Replace this with a virtual memory container
	// that allocates in 4KB pages. Most of the allocations
	// made to this vector are in their own 4KB pages, meaning
	// that a 256KB structure has only 6.25% efficiency
	std::vector<c_imgui_dynamic_data*> imgui_dynamic_data;

	inline c_imgui_dynamic_data& get_dynamic_data(void* pPosition, bool& rWasAllocated);
	template<typename T>
	inline T& get_dynamic_data(void* pPosition)
	{
	
		bool wasAllocated = false;
		c_imgui_dynamic_data& rDynamicData = get_dynamic_data(pPosition, wasAllocated);
		if (wasAllocated)
		{
			static_assert(sizeof(T) <= sizeof(rDynamicData.second), "Dynamic data exceeds allocated space");
			new(rDynamicData.second) T(); // initialize value
		}
		T& rDynamicTagBlockData = *reinterpret_cast<T*>(rDynamicData.second);
		return rDynamicTagBlockData;
	}
	template<typename T, typename ...Tconstructor>
	inline T& get_dynamic_data(void* pPosition, bool& rWasAllocated)
	{
		c_imgui_dynamic_data& rDynamicData = get_dynamic_data(pPosition, rWasAllocated);
		static_assert(sizeof(T) <= sizeof(rDynamicData.second), "Dynamic data exceeds allocated space");
		T& rDynamicTagBlockData = *reinterpret_cast<T*>(rDynamicData.second);
		return rDynamicTagBlockData;
	}
};

inline s_mandrill_dynamic_data::c_imgui_dynamic_data& s_mandrill_dynamic_data::get_dynamic_data(void* pPosition, bool& rWasAllocated)
{
	for (c_imgui_dynamic_data* pDynamicData : imgui_dynamic_data)
	{
		if (pDynamicData->first == pPosition)
		{
			rWasAllocated = false;
			return *pDynamicData;
		}
	}

	//c_console::write_line_verbose("Adding new dynamic data @ %p", pPosition);

	rWasAllocated = true;
	c_imgui_dynamic_data& rDynamicData = *imgui_dynamic_data.emplace_back(new c_imgui_dynamic_data{});
	rDynamicData.first = pPosition;
	return rDynamicData;
}
