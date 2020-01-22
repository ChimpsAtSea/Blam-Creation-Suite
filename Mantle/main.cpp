#include "mantle-private-pch.h"

template<typename TagType>
inline const ReflectionType& GetTagReflectionData()
{
	return GetTagReflectionData(TagType::kTagGroupName);
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
inline const ReflectionType& GetReflectionType(const T& member)
{
	return GetReflectionType<T>();
}

void PrintReflectionInfo(const ReflectionType& reflectionData)
{
	printf("struct %s {\n", reflectionData.m_pTypeName);
	for (size_t i = 0; i < reflectionData.m_count; i++)
	{
		const ReflectionField& ReflectionField = reflectionData.m_members[i];

		if (ReflectionField.m_arraySize)
		{
			printf("\t%s %s[%u]; // size:0x%X offset:0x%X\n", ReflectionField.m_typeInfo.m_pTypeName, ReflectionField.m_pMemberName, ReflectionField.m_arraySize, ReflectionField.m_size, ReflectionField.m_offset);
		}
		else
		{
			printf("\t%s %s; // size:0x%X offset:0x%X\n", ReflectionField.m_typeInfo.m_pTypeName, ReflectionField.m_pMemberName, ReflectionField.m_size, ReflectionField.m_offset);
		}
	}

	printf("};\n");
}

void PrintReflectionInfoGUI(const ReflectionType& reflectionData)
{
	ImGui::Text("struct %s {\n", reflectionData.m_pTypeName);
	for (size_t i = 0; i < reflectionData.m_count; i++)
	{
		const ReflectionField& ReflectionField = reflectionData.m_members[i];

		if (ReflectionField.m_arraySize)
		{
			ImGui::Text("\t%s %s[%u]; // size:0x%X offset:0x%X\n", ReflectionField.m_typeInfo.m_pTypeName, ReflectionField.m_pMemberName, ReflectionField.m_arraySize, ReflectionField.m_size, ReflectionField.m_offset);
		}
		else
		{
			ImGui::Text("\t%s %s; // size:0x%X offset:0x%X\n", ReflectionField.m_typeInfo.m_pTypeName, ReflectionField.m_pMemberName, ReflectionField.m_size, ReflectionField.m_offset);
		}
	}

	ImGui::Text("};\n");
}

int main()
{
	void(*UICallback)() = []()
	{
		ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
		SIZE size = {};
		CustomWindow::GetWindowSize(size);
		ImGui::SetNextWindowSize(ImVec2(size.cx, size.cy), ImGuiCond_Always);

		// Main body of the Demo window starts here.
		static bool isReachDebugWindowOpen = true;

		ImGuiWindowFlags windowFlags = 0;
		windowFlags |= ImGuiWindowFlags_NoCollapse;
		windowFlags |= ImGuiWindowFlags_NoTitleBar;
		windowFlags |= ImGuiWindowFlags_NoMove;
		windowFlags |= ImGuiWindowFlags_NoResize;
		windowFlags |= ImGuiWindowFlags_NoSavedSettings;

		if (ImGui::Begin("Mantle", &isReachDebugWindowOpen, windowFlags))
		{
			s_scenario_definition scenario;

			const ReflectionType& scenarioReflectionData = GetTagReflectionData<s_scenario_definition>();
			const ReflectionType& biped_palette_blockReflectionData = GetReflectionType(scenario.biped_palette_block);
			PrintReflectionInfoGUI(scenarioReflectionData);

		}
		ImGui::End();
	};

	static bool s_running = true;
	void(*UpdateCallback)() = []()
	{
		static float clearColor[] = { 0.25f, 0.25f, 0.25f, 1.0f };
		GameRender::BeginFrame(clearColor);
		GameRender::EndFrame();
	};
	CustomWindow::Init();
	GameRender::Init(NULL);
	DebugUI::Show();
	DebugUI::RegisterCallback(UICallback);
	CustomWindow::SetOnUpdateCallback(UpdateCallback);
	CustomWindow::SetOnDestroyCallback([]() { s_running = false; });
	while (s_running) CustomWindow::Update();
	DebugUI::UnregisterCallback(UICallback);
	GameRender::Deinit();
	CustomWindow::Deinit();

	return 0;
}
