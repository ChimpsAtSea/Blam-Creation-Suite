#pragma once

typedef std::string MapLine;
typedef std::string MapToken;
typedef std::vector<MapToken> MapTokens;
typedef std::pair<MapLine, MapTokens> MapEntry;
typedef std::vector<MapEntry> MapFileEntries;

class SectionRegion
{
public:
	SectionRegion(MapEntry& rMapEntry);

	int m_sectionIndex;
	int m_sectionOffset;
	int m_sectionLength;
	std::string m_name;
	std::string m_class;
};
typedef std::vector<SectionRegion> SectionRegions;


class PublicSymbol
{
public:
	PublicSymbol(MapEntry& rMapEntry);

	int m_sectionIndex;
	int m_sectionOffset;
	std::string m_name;
	uint64_t m_virtualAddress;
};

class StaticSymbol
{
public:
	StaticSymbol(MapEntry& rMapEntry);

	int m_sectionIndex;
	int m_sectionOffset;
	std::string m_name;
	int m_runtimeOffset;
	std::string m_objectName;

};

class Section
{
public:
	Section(int index, SectionRegions& rSectionRegions);

	std::string m_name;
	int m_sectionIndex;
	int m_sectionLength;
	std::string m_class;
	std::vector<SectionRegion> m_sectionRegions;

};

class MappingFileParser
{
public:
	static PublicSymbol* GetPublicSymbolByName(std::string rName);
private:
	MappingFileParser();

	enum class CurrentParserMode
	{
		ReadingTitle,
		ReadingTimestamp,
		ReadingPreferredLoadAddress,
		LookingForSectionBegin,
		ReadingSections,
		ReadingPublics,
		LookingForEntryPoint,
		LookingForStaticsBegin,
		ReadingStatics,
		Finished
	};
	CurrentParserMode current_mode;

	static MappingFileParser g_mappingFileParser;
	std::string title;
	std::string timestamp;
	uint64_t m_baseVirtualAddress;
	std::vector<Section> m_sections;
	std::vector<PublicSymbol> m_publicSymbols;
	std::string	entry_point;
	std::vector<StaticSymbol> statics_info;

	PublicSymbol* getPublicSymbolByName(std::string rName);
	void Parse(std::string filename);
};

