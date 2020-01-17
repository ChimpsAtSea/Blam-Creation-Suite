#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\Sample3DSceneRenderer.h"
#include "Content\SampleFpsTextRenderer.h"

// Renders Direct2D and 3D content on the screen.
namespace OpusUIPrototype
{
	class OpusUIPrototypeMain : public DX::IDeviceNotify
	{
	public:
		OpusUIPrototypeMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~OpusUIPrototypeMain();
		void CreateWindowSizeDependentResources();
		void TrackingUpdate(float positionX) { m_pointerLocationX = positionX; }
		Concurrency::critical_section& GetCriticalSection() { return m_criticalSection; }

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		void ProcessInput();
		void Update();
		bool Render();

		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		Concurrency::critical_section m_criticalSection;

		// Track current input pointer position.
		float m_pointerLocationX;
	};
}