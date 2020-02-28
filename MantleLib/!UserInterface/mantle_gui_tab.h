#pragma once

class c_mantle_gui_tab
{
public:
	c_mantle_gui_tab(const char* title, const char* description);
	virtual ~c_mantle_gui_tab();

	virtual void render_in_game_gui();
	virtual void render_gui(bool setSelected);

	inline const char* get_title() const { return m_title.c_str(); }
	inline const char* get_description() const { return m_description.c_str(); }

	using TabClosedCallback = std::function<void(c_mantle_gui_tab&)>;
	void AddTabClosedCallback(TabClosedCallback);
protected:
	virtual void RenderContents(bool setSelected) = 0;

	bool m_isOpen;
	std::string m_title;
	std::string m_description;
	std::vector<TabClosedCallback> tabClosedCallback;

	using ImGUIDynamicData = std::pair<void*, char[120]>;
	std::vector<ImGUIDynamicData*> m_imGuiDynamicData;

	inline ImGUIDynamicData& GetDynamicData(void* pPosition, bool& rWasAllocated);
	template<typename T>
	inline T& GetDynamicData(void* pPosition)
	{

		bool wasAllocated = false;
		ImGUIDynamicData& rDynamicData = GetDynamicData(pPosition, wasAllocated);
		if (wasAllocated)
		{
			static_assert(sizeof(T) <= sizeof(rDynamicData.second), "Dynamic data exceeds allocated space");
			new(rDynamicData.second) T(); // initialize value
		}
		T& rDynamicTagBlockData = *reinterpret_cast<T*>(rDynamicData.second);
		return rDynamicTagBlockData;
	}
	template<typename T, typename ...Tconstructor>
	inline T& GetDynamicData(void* pPosition, bool& rWasAllocated)
	{
		ImGUIDynamicData& rDynamicData = GetDynamicData(pPosition, rWasAllocated);
		static_assert(sizeof(T) <= sizeof(rDynamicData.second), "Dynamic data exceeds allocated space");
		T& rDynamicTagBlockData = *reinterpret_cast<T*>(rDynamicData.second);
		return rDynamicTagBlockData;
	}
	

};

inline c_mantle_gui_tab::ImGUIDynamicData& c_mantle_gui_tab::GetDynamicData(void* pPosition, bool& rWasAllocated)
{
	for (ImGUIDynamicData* pDynamicData : m_imGuiDynamicData)
	{
		if (pDynamicData->first == pPosition)
		{
			rWasAllocated = false;
			return *pDynamicData;
		}
	}

	//write_line_verbose("Adding new dynamic data @ %p", pPosition);

	rWasAllocated = true;
	ImGUIDynamicData& rDynamicData = *m_imGuiDynamicData.emplace_back(new ImGUIDynamicData{});
	rDynamicData.first = pPosition;
	return rDynamicData;
}

