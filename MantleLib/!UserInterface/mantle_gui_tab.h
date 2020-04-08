#pragma once

class c_mantle_gui_tab :
	public c_mantle_event_queue
{
public:
	c_mantle_gui_tab() = delete;
	c_mantle_gui_tab(const c_mantle_gui_tab&) = delete;
	c_mantle_gui_tab& operator=(const c_mantle_gui_tab&) = delete;

	c_mantle_gui_tab(const char* title, const char* description);
	virtual ~c_mantle_gui_tab();

	virtual void render_in_game_gui();
	virtual void render_gui(bool set_selected) final;
	virtual void render_menu_gui() final;
	virtual void render_file_dialogue_gui();

	inline const char* get_title() const { return m_title.c_str(); }
	inline const char* get_description() const { return m_description.c_str(); }

	using on_tab_closed_callback = std::function<void(c_mantle_gui_tab&)>;
	void add_tab_closed_callback(on_tab_closed_callback);
protected:
	void add_tab(c_mantle_gui_tab& tab);
	void remove_tab(c_mantle_gui_tab& tab);
	void tab_closed_callback(c_mantle_gui_tab& tab);

	virtual void render_tab_contents_gui() = 0;
	virtual void render_tab_menu_gui();

	bool allow_close;
	bool is_open;
public:
	bool is_selected;
protected:
	std::string m_title;
	std::string m_description;
	std::vector<on_tab_closed_callback> on_tab_closed_callbacks;
	std::vector<c_mantle_gui_tab*> child_tabs;

public:
	using c_imgui_dynamic_data = std::pair<void*, char[120]>;
	std::vector<c_imgui_dynamic_data*> imgui_dynamic_data;

	inline c_imgui_dynamic_data& GetDynamicData(void* pPosition, bool& rWasAllocated);
	template<typename T>
	inline T& GetDynamicData(void* pPosition)
	{

		bool wasAllocated = false;
		c_imgui_dynamic_data& rDynamicData = GetDynamicData(pPosition, wasAllocated);
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
		c_imgui_dynamic_data& rDynamicData = GetDynamicData(pPosition, rWasAllocated);
		static_assert(sizeof(T) <= sizeof(rDynamicData.second), "Dynamic data exceeds allocated space");
		T& rDynamicTagBlockData = *reinterpret_cast<T*>(rDynamicData.second);
		return rDynamicTagBlockData;
	}
};

inline c_mantle_gui_tab::c_imgui_dynamic_data& c_mantle_gui_tab::GetDynamicData(void* pPosition, bool& rWasAllocated)
{
	for (c_imgui_dynamic_data* pDynamicData : imgui_dynamic_data)
	{
		if (pDynamicData->first == pPosition)
		{
			rWasAllocated = false;
			return *pDynamicData;
		}
	}

	//write_line_verbose("Adding new dynamic data @ %p", pPosition);

	rWasAllocated = true;
	c_imgui_dynamic_data& rDynamicData = *imgui_dynamic_data.emplace_back(new c_imgui_dynamic_data{});
	rDynamicData.first = pPosition;
	return rDynamicData;
}

