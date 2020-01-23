#pragma once

class CacheFile;
class MantleMapLoadTask;
class MantleMapTab : public MantleTab
{
public:
	void DisplayMapTabUI();
	MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath);
	virtual ~MantleMapTab();

protected:
	virtual void RenderContents(bool setSelected);

	void AddTabItem(MantleTab& rMantleTab);
	void RemoveTabItem(MantleTab& rMantleTab);

	CacheFile* m_pCacheFile;
	std::vector<MantleTab*> m_tabs;
	TabClosedCallback m_tabClosedCallback;
};

