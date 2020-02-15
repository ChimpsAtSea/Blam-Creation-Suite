#pragma once

class Halo1GameHost : public IOpusGameEngineHost
{
public:
	Halo1GameHost();
	virtual ~Halo1GameHost();

	// MCC Functionality
	void FrameEnd(IDXGISwapChain* pSwapChain, _QWORD) override;



	// Opus Functionality
	virtual void RenderUI() const;
	virtual IGameEngine* GetGameEngine() const;

private:
	static void updateCamera();
	static void cameraDebugUI();
	IGameEngine* m_pGameEngine;

	// static
public:
	static IDataAccess* GetDataAccess() { return s_halo1GameRuntime->GetDataAccess(); }
	static GameRuntime& GetGameRuntime();
	static void InitModifications(BuildVersion buildVersion);
	static void DeinitModifications(BuildVersion buildVersion);
private:
	static GameRuntime* s_halo1GameRuntime;
};

