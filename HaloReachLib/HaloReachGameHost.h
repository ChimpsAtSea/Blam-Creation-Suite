#pragma once

class HaloReachGameHost : public IOpusGameEngineHost
{
public:
	HaloReachGameHost();
	virtual ~HaloReachGameHost();

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
	static IDataAccess* GetDataAccess() { return s_haloReachGameRuntime.GetDataAccess(); }
	static GameRuntime& GetGameRuntime() { return s_haloReachGameRuntime; }
private:
	static GameRuntime s_haloReachGameRuntime;
};

