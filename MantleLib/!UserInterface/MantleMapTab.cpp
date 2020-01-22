#include "mantlelib-private-pch.h"


template<typename TagType>
inline const ReflectionType& GetTagReflectionData()
{
	return GetTagReflectionData(TagType::kTagGroupName);
}

template<typename T>
inline const ReflectionType& GetReflectionType(const T& member)
{
	return GetReflectionType<T>();
}

void PrintReflectionInfoGUI3(char* pData, const ReflectionType& reflectionData)
{
	ImGui::Text("struct %s {\n", reflectionData.m_pTypeName);
	for (size_t i = 0; i < reflectionData.m_count; i++)
	{
		const ReflectionField& reflectionField = reflectionData.m_members[i];

		if (!reflectionField.m_arraySize)
		{
			if (reflectionField.m_typeInfo.m_primitiveTypeIndex == PrimitiveType::Float)
			{
				float* pFloat = reinterpret_cast<float*>(pData + reflectionField.m_offset);
				ImGui::InputFloat(reflectionField.m_pMemberNiceName, pFloat, 0, 0, 7, 0);
			}

			if (reflectionField.m_typeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::Structure)
			{
				const ReflectionStructureInfo& rReflectionStructureInfo = reflectionField.m_structureInfo;
				const ReflectionType& reflectionData2 = *rReflectionStructureInfo.m_pReflectionTypeInfo;
				assert(&reflectionData2);

				char* pStructure = reinterpret_cast<char*>(pData + reflectionField.m_offset);

				PrintReflectionInfoGUI3(pStructure, reflectionData2);
			}
		}
	}

	ImGui::Text("};\n");
}

inline const ReflectionType& GetTagReflectionData(TagGroupName tagGroupName)
{
	switch (tagGroupName)
	{
	case TagGroupName::Scenario: return GetReflectionType<s_scenario_definition>();
	}
	assert(!"Failed to find tag reflection data");
	throw;
}

template<typename T>
void DisplayTag(T* pTagData)
{
	char* pData = reinterpret_cast<char*>(pTagData);
	const ReflectionType& reflectionData = GetTagReflectionData<T>();

	PrintReflectionInfoGUI3(pData, reflectionData);
}

void FileSystemReadToBufferImpl(FILE* pFileHandle, char* pBuffer, size_t readLength)
{
	uint32_t iterations = 0;
	for (size_t currentPosition = 0; currentPosition < readLength; iterations++)
	{
		// prevent this from running into a madness number of iterations
		assert(iterations != UINT32_MAX);

		size_t remainingDataLength = readLength - currentPosition;
		currentPosition += fread(&pBuffer[currentPosition], 1, remainingDataLength, pFileHandle);
	}
}

char* FileSystemReadToMemory(const wchar_t* pFilePath, size_t* pAllocatedSize)
{
	FILE* pFileHandle = _wfopen(pFilePath, L"rb");
	if (pFileHandle == nullptr)
	{
		return nullptr;
	}

	fseek(pFileHandle, 0, SEEK_END);
	size_t fileSize = static_cast<size_t>(_ftelli64(pFileHandle));
	fseek(pFileHandle, 0, SEEK_SET);

	char* pBuffer = new char[fileSize] {};
	if (pAllocatedSize)
	{
		*pAllocatedSize = fileSize;
	}

	FileSystemReadToBufferImpl(pFileHandle, pBuffer, fileSize);

	int fcloseResult = fclose(pFileHandle);
	assert(fcloseResult == 0);

	return pBuffer;
}

MantleMapTab::MantleMapTab(const char* pTitle, const char* pDescription, const wchar_t* szMapFilePath)
	:MantleTab(pTitle, pDescription)
	, m_pMapData(nullptr)
	, m_mapDataLength(0)
	, m_isMapLoading(false)
{
	LoadMap(szMapFilePath);
}

void MantleMapTab::LoadMap(const std::wstring& mapFilePath)
{
	m_isMapLoading = true;

	tbb::task::enqueue(*lambda_task([=]() {

		m_pMapData = FileSystemReadToMemory(mapFilePath.c_str(), &m_mapDataLength);

		if (m_pMapData)
		{
			s_cache_file_header* pHeader = reinterpret_cast<s_cache_file_header*>(m_pMapData);

			WriteLineVerbose("");
		}

		m_isMapLoading = false;

		}));
}


void MantleMapTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(GetTitle(), &m_isOpen, tabFlags))
	{
		if (m_isMapLoading)
		{
			ImGui::Text("Loading...");
		}
		else
		{
			static s_scenario_definition scenario;
			static bool once = true;
			if (once)
			{
				once = false;
				scenario.TEST.something_else = 1.0f;
			}

			const ReflectionType& scenarioReflectionData = GetTagReflectionData<s_scenario_definition>();
			const ReflectionType& biped_palette_blockReflectionData = GetReflectionType(scenario.biped_palette_block);
			DisplayTag(&scenario);
		}

		ImGui::EndTabItem();
	}
	ImGui::PopID();
}
