#pragma once

class HaloReachGameHost : public c_opus_game_engine_host
{
public:
	HaloReachGameHost();
	virtual ~HaloReachGameHost();

	// MCC Functionality
	void FrameEnd(IDXGISwapChain* pSwapChain, _QWORD) override;



	// Opus Functionality
	virtual void render_ui() const override;
	virtual IGameEngine* get_game_engine() const override;

private:
	static void updateCamera();
	static void cameraDebugUI();
	static void scriptDebugUI();
	IGameEngine* m_pGameEngine;

	// static
public:
	static IDataAccess* GetDataAccess() { return s_haloReachGameRuntime.GetDataAccess(); }
	static c_game_runtime& GetGameRuntime() { return s_haloReachGameRuntime; }
	static void InitModifications(e_build build);
	static void DeinitModifications(e_build build);
private:
	static c_game_runtime s_haloReachGameRuntime;
};

