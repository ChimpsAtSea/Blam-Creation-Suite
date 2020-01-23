#pragma once

class CacheFile;
class MantleTagTab : public MantleTab
{
public:
	void PrintReflectionInfoGUI3(char* const pData, const ReflectionType& reflectionData, int recursionDepth);
	MantleTagTab(const char* pTitle, const char* pDescription, CacheFile* pCacheFile, int tagIndex);
	virtual ~MantleTagTab();
protected:
	virtual void RenderContents(bool setSelected);

	char* m_pTagData;
	int m_tagIndex;
	struct s_cache_file_tag_instance* m_pTagInstance;
	CacheFile* m_pCacheFile;
};
