#pragma once

class MantleMapLoadTask;
class MantleMapTab : public MantleTab
{
public:
	MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath);
	virtual ~MantleMapTab();
protected:
	virtual void RenderContents(bool setSelected);
	void LoadMap(const std::wstring& mapFilePath);

	char* m_pMapData;
	size_t m_mapDataLength;
	volatile bool m_isMapLoading;
};

