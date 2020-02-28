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

	void RenderButtons();
protected:
	virtual void RenderContents(bool setSelected);
	void RenderContentsImpl(char* pCurrentStructureData, const ReflectionType& rReflectionType, int recursionDepth);

	bool m_isSelected;
	TagInterface& m_rTagInterface;
	CacheFile& m_rCacheFile;
	c_mantle_gui_tab* m_pParentTab;
};
