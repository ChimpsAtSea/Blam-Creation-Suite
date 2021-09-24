#pragma once
class SystemPatch
{
public:
	/*
		This patch prevents EnumWindows from enumerating a console window
	*/
	static void PatchEnumWindows();

private:
	static bool s_patchedEnumWindows;
};
