
intptr_t sub_1801FE1B0_offset(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (engineVersion == EngineVersion::Halo1)
	{
		switch (buildVersion)
		{
		case BuildVersion::Build_1_1350_0_0: return 0x1801FE1B0;
		}
	}
	return ~intptr_t();
}
FunctionHookEx<sub_1801FE1B0_offset, __int64 __fastcall (int a1, int a2)> sub_1801FE1B0 = { "sub_1801FE1B0", [](int a1, int a2)
{
	a1 = 3072;
	a2 = 1728;
	__int64 result = sub_1801FE1B0(a1, a2);
	return result;
} };

