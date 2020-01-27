#pragma once

class TagInterface;
class CacheFile;
class MantleTagTab : public MantleTab
{
public:
	MantleTagTab(CacheFile& rCacheFile, TagInterface& rTagInterface, MantleTab* pParentTab);
	virtual ~MantleTagTab();

	void CopyDataRecursively(const ReflectionType& rReflectionType, char* pSrc, char* pDest);
	void Poke();
	TagInterface& GetTagInterface() const { return m_rTagInterface; };
	CacheFile& GetCacheFile() const { return m_rCacheFile; };

protected:
	virtual void RenderContents(bool setSelected);
	void RenderContentsImpl(char* pCurrentStructureData, const ReflectionType& rReflectionType, int recursionDepth);

	TagInterface& m_rTagInterface;
	CacheFile& m_rCacheFile;
	MantleTab* m_pParentTab;
};
