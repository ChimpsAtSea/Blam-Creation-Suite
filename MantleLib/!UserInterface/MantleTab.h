#pragma once

class MantleTab
{
public:
	MantleTab(const char* pTitle, const char* pDescription)
		: m_title(pTitle)
		, m_description(pDescription)
		, m_isOpen(true)
	{

	}
	virtual ~MantleTab();

	void Render(bool setSelected);
	inline const char* GetTitle() const { return m_title.c_str(); }
	inline const char* GetDescription() const { return m_description.c_str(); }

	typedef void(*TabClosedCallback)(MantleTab&);
	void AddTabClosedCallback(TabClosedCallback);
protected:
	virtual void RenderContents(bool setSelected) = 0;

	bool m_isOpen;
	std::string m_title;
	std::string m_description;
	std::vector<TabClosedCallback> tabClosedCallback;
};

