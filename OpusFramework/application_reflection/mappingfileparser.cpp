#include "opusframework-private-pch.h"

MappingFileParser MappingFileParser::g_mappingFileParser;

std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	return ltrim(rtrim(str, chars), chars);
}

int parse_hex_int32(std::string& string)
{
	return strtol(string.c_str(), NULL, 16);
}

uint64_t parse_hex_uint64(std::string& string)
{
	return strtoull(string.c_str(), NULL, 16);
}

void parse_section_and_address(std::string& rSectionAndAddress, int& rSectionIndex, int& rSectionOffset)
{
	std::string indexStr = rSectionAndAddress.substr(0, 4);
	std::string offsetStr = rSectionAndAddress.substr(5, 8);
	rSectionIndex = parse_hex_int32(indexStr) - 1; // subtract 1 because these indices start at 1
	rSectionOffset = parse_hex_int32(offsetStr);
}

/*
 * It will iterate through all the lines in file and
 * put them in given vector
 */
bool getFileContent(std::string fileName, std::vector<std::string>& vecOfStrs)
{

	// Open the File
	std::ifstream in(fileName.c_str());

	// Check if object is valid
	if (!in)
	{
		std::cerr << "Cannot open the File : " << fileName << std::endl;
		return false;
	}

	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
			vecOfStrs.push_back(str);
	}
	//Close The File
	in.close();
	return true;
}

SectionRegion::SectionRegion(MapEntry& rMapEntry)
{
	parse_section_and_address(rMapEntry.second[0], m_sectionIndex, m_sectionOffset);

	std::string Length = rMapEntry.second[1];
	m_sectionLength = strtol(Length.c_str(), NULL, 16);
	m_name = rMapEntry.second[2];
	m_class = rMapEntry.second[3];
}

PublicSymbol::PublicSymbol(MapEntry& rMapEntry)
{
	parse_section_and_address(rMapEntry.second[0], m_sectionIndex, m_sectionOffset);
	m_name = rMapEntry.second[1];
	m_virtualAddress = parse_hex_uint64(rMapEntry.second[2]);
}

StaticSymbol::StaticSymbol(MapEntry& rMapEntry)
{
	parse_section_and_address(rMapEntry.second[0], m_sectionIndex, m_sectionOffset);
	m_name = rMapEntry.second[1];
	m_runtimeOffset = parse_hex_int32(rMapEntry.second[2]);
	size_t numExtraBits = rMapEntry.second.size() - 4;

	m_objectName = rMapEntry.second[3 + numExtraBits];
}

Section::Section(int index, SectionRegions& rSectionRegions)
	: m_sectionIndex(0)
	, m_sectionLength(0)
{
	m_sectionIndex = index;
	for (SectionRegion& rSectionRegion : rSectionRegions)
	{
		if (rSectionRegion.m_sectionIndex != index)
		{
			continue;
		}

		if (m_name.empty())
		{
			m_name = rSectionRegion.m_name;
		}
		if (m_class.empty())
		{
			m_class = rSectionRegion.m_class;
		}

		m_sectionLength += rSectionRegion.m_sectionLength;
		m_sectionRegions.push_back(rSectionRegion);
	}
}

MappingFileParser::MappingFileParser()
{
	CHAR currentModuleNameBuffer[MAX_PATH] = {};
	GetModuleFileNameA(GetModuleHandleA(NULL), currentModuleNameBuffer, sizeof(currentModuleNameBuffer));
	PathRemoveExtensionA(currentModuleNameBuffer);
	PathAddExtension(currentModuleNameBuffer, ".bin");
	Parse(currentModuleNameBuffer);
}

void MappingFileParser::Parse(std::string filename)
{
	// Get the contents of file in a vector
	std::vector<MapLine> RawLines;
	bool result = getFileContent(filename.c_str(), RawLines);
	if (!result)
	{
#if _DEBUG
		FATAL_ERROR("Failed to open mapping file %s", filename);
#else
		MessageBox(NULL, "Fatal Error - Opus.bin not found", "Fatal Error", MB_OK | MB_ICONWARNING);
		exit(1);
#endif
	}
	
	MapFileEntries entry_list;
	for (MapLine& line : RawLines)
	{
		trim(line);
		if (!line.empty())
		{
			MapEntry entry;
			entry.first = line;
			{ // read tokens
				MapTokens tokens;
				std::stringstream ss(line);
				MapToken current_token;
				while (ss >> current_token)
				{
					tokens.push_back(current_token);
				}
				entry.second = tokens;
			}
			entry_list.push_back(entry);
		}
	}

	std::vector<SectionRegion> sectionRegions;
	CurrentParserMode next_mode = CurrentParserMode::ReadingTitle;
	if (entry_list.size() == 0)
	{
		FATAL_ERROR("Failed to parse mapping file");
	}
	for (MapEntry& current_entry : entry_list)
	{
		current_mode = next_mode;
		switch (current_mode)
		{
		case CurrentParserMode::ReadingTitle:
			if (current_entry.second.empty()) continue;
			title = current_entry.first;
			next_mode = CurrentParserMode::ReadingTimestamp;
			break;
		case CurrentParserMode::ReadingTimestamp:
			if (current_entry.second.empty()) continue;
			timestamp = current_entry.first;
			next_mode = CurrentParserMode::ReadingPreferredLoadAddress;
			break;
		case CurrentParserMode::ReadingPreferredLoadAddress:
			if (current_entry.second.empty()) continue;
			m_baseVirtualAddress = parse_hex_uint64(current_entry.second[4]);
			next_mode = CurrentParserMode::LookingForSectionBegin;
			break;
		case CurrentParserMode::LookingForSectionBegin:
			if (!current_entry.second.empty() && current_entry.second[0] == "Start")
			{
				next_mode = CurrentParserMode::ReadingSections;
			}
			break;
		case CurrentParserMode::ReadingSections:
			if (!current_entry.second.empty() && current_entry.second[0] == "Address")
			{
				next_mode = CurrentParserMode::ReadingPublics;
				break;
			}
			sectionRegions.emplace_back(current_entry);
			break;
		case CurrentParserMode::ReadingPublics:
			if (!current_entry.second.empty() && current_entry.second[0] == "entry")
			{
				next_mode = CurrentParserMode::LookingForEntryPoint;
				goto LookingForEntryPoint;
				break;
			}
			m_publicSymbols.emplace_back(current_entry);
			break;
		case CurrentParserMode::LookingForEntryPoint:
		LookingForEntryPoint:
			entry_point = current_entry.first;
			next_mode = CurrentParserMode::LookingForStaticsBegin;
			break;
		case CurrentParserMode::LookingForStaticsBegin:
			if (!current_entry.second.empty() && current_entry.second[0] == "Static")
			{
				next_mode = CurrentParserMode::ReadingStatics;
			}
			break;
		case CurrentParserMode::ReadingStatics:
			if (!current_entry.second.empty() && current_entry.second[0] == "entry")
			{
				next_mode = CurrentParserMode::Finished;
				break;
			}
			statics_info.emplace_back(current_entry);
			break;
		}
	}
	assert(current_mode == CurrentParserMode::ReadingStatics);
	current_mode = CurrentParserMode::Finished;

	int numSections = -1;
	for (SectionRegion& rSectionRegion : sectionRegions)
	{
		numSections = __max(numSections, rSectionRegion.m_sectionIndex);
	}
	for (int currentSectionIndex = 0; currentSectionIndex <= numSections; currentSectionIndex++)
	{
		m_sections.emplace_back(currentSectionIndex, sectionRegions);
	}

	WriteLineVerbose("MappingFileParser: Found %llu sections\n", uint64_t(m_sections.size()));
	for (Section& rSection : m_sections)
	{
		WriteLineVerbose("MappingFileParser:  %x %s %s\n", rSection.m_sectionIndex, rSection.m_name.c_str(), rSection.m_class.c_str());
	}

	WriteLineVerbose("MappingFileParser: Found %llu public symbols\n", uint64_t(m_publicSymbols.size()));
	for (PublicSymbol& rPublicSymbol : m_publicSymbols)
	{
		//printf("%x %s %llx\n", rPublicSymbol.m_sectionIndex, rPublicSymbol.m_name.c_str(), uint64_t(rPublicSymbol.m_virtualAddress));
	}
}

uint64_t MappingFileParser::GetBaseVirtualAddress()
{
	return g_mappingFileParser.m_baseVirtualAddress;
}

PublicSymbol* MappingFileParser::GetPublicSymbolByName(std::string rName)
{
	return g_mappingFileParser.getPublicSymbolByName(rName);
}

PublicSymbol* MappingFileParser::getPublicSymbolByName(std::string rName)
{
	// exact search
	
	for (PublicSymbol& rPublicSymbol : m_publicSymbols)
	{
		if (rPublicSymbol.m_name == rName)
		{
			return &rPublicSymbol;
		}
	}
	// lazy search where rPublicSymbol.m_name begins with rName with a question mark out the front (most likely use case of this function)
	std::string lazySearch1 = "?";
	lazySearch1 += rName;
	lazySearch1 += "@";
	for (PublicSymbol& rPublicSymbol : m_publicSymbols)
	{
		if (rPublicSymbol.m_name.find(lazySearch1) != std::string::npos)
		{
			return &rPublicSymbol;
		}
	}

	// lazy search where rPublicSymbol.m_name begins with rName with a question mark out the front (likely use case of this function)
	std::string lazySearch2 = "?";
	lazySearch2 += rName;
	for (PublicSymbol& rPublicSymbol : m_publicSymbols)
	{
		if (rPublicSymbol.m_name.find(lazySearch2) != std::string::npos)
		{
			return &rPublicSymbol;
		}
	}

	// lazy search where rPublicSymbol.m_name contains rName
	for (PublicSymbol& rPublicSymbol : m_publicSymbols)
	{
		if (rPublicSymbol.m_name.find(rName) != std::string::npos)
		{
			return &rPublicSymbol;
		}
	}
	return nullptr;
}
