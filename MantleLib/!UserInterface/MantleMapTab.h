#pragma once

class CacheFile;
class MantleMapLoadTask;
class MantleMapTab : public MantleTab
{
public:
	friend class MantleTagTab;

	void DisplayMapTabUI();
	MantleMapTab(std::shared_ptr<CacheFile> pCacheFile);
	MantleMapTab(const wchar_t* szMapFilePath);
	virtual ~MantleMapTab();

	std::shared_ptr<CacheFile> GetCacheFile() const { return m_pCacheFile; }
protected:
	void openTagTab(TagInterface& rTagInterface);
	MantleMapTab(const char* pTitle, const char* pDescription);
	virtual void GameRender() override;
	virtual void RenderContents(bool setSelected) override;

	void AddTabItem(MantleTab& rMantleTab);
	void RemoveTabItem(MantleTab& rMantleTab);


	char m_pSearchBuffer[1024];
	TagInterface* m_pSelectedSearchTagInterface;
	MantleTab* m_pNextSelectedTab;
	bool m_renderTriggerVolumes;
	std::shared_ptr<CacheFile> m_pCacheFile;
	std::vector<MantleTab*> m_tabs;
	TabClosedCallback m_tabClosedCallback;
};

