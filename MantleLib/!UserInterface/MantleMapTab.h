#pragma once

class CacheFile;
class MantleMapLoadTask;
class MantleMapTab : public MantleTab
{
public:
	void DisplayMapTabUI();
	MantleMapTab(const char* pTitle, const char* pDescription, CacheFile& rCacheFile);
	MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath);
	virtual ~MantleMapTab();

protected:
	MantleMapTab(const char* pTitle, const char* pDescription);
	virtual void RenderContents(bool setSelected);

	void AddTabItem(MantleTab& rMantleTab);
	void RemoveTabItem(MantleTab& rMantleTab);

	bool m_ownsCacheFileMemory;
	CacheFile* m_pCacheFile;
	std::vector<MantleTab*> m_tabs;
	TabClosedCallback m_tabClosedCallback;
};

