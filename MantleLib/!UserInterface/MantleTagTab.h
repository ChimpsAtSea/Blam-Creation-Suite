#pragma once

class TagInterface;
class CacheFile;
class MantleTagTab : public c_mantle_gui_tab
{
public:
	MantleTagTab(CacheFile& rCacheFile, TagInterface& rTagInterface, c_mantle_gui_tab* pParentTab);
	virtual ~MantleTagTab();

	void CopyDataRecursively(const ReflectionType& rReflectionType, char* pStartSrc, char* pStartDest, char* pSrc, char* pDest);
	void Poke();
	TagInterface& GetTagInterface() const { return m_rTagInterface; };
	CacheFile& GetCacheFile() const { return m_rCacheFile; };
	c_mantle_gui_tab* GetParentTab() const { return m_pParentTab; };

	void RenderButtons();
protected:
	virtual void RenderContents(bool setSelected);

	bool m_isSelected;
	TagInterface& m_rTagInterface;
	CacheFile& m_rCacheFile;
	c_mantle_gui_tab* m_pParentTab;
};
