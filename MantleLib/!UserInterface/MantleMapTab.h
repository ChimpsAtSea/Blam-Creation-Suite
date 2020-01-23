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

	CacheFile* m_pCacheFile;
};

