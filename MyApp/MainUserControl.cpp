#include "pch.h"
#include "MainUserControl.h"
#include "OpusUIPrototypeMain.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace Concurrency;

namespace winrt::MyApp::implementation
{
	MainUserControl::MainUserControl()
	{
		InitializeComponent();

		::winrt::Windows::UI::Xaml::Controls::SwapChainPanel swapChainPanel = SwapChainPanelControl();

		m_deviceResources = std::make_shared<DX::DeviceResources>();
		m_deviceResources->SetSwapChainPanel(swapChainPanel);

		m_main = std::unique_ptr<OpusUIPrototype::OpusUIPrototypeMain>(new OpusUIPrototype::OpusUIPrototypeMain(m_deviceResources));

		//// Register event handlers for page lifecycle.
		//CoreWindow^ window = Window::Current->CoreWindow;

		//window->VisibilityChanged +=
		//	ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &DirectXPage::OnVisibilityChanged);

		//DisplayInformation^ currentDisplayInformation = DisplayInformation::GetForCurrentView();

		//currentDisplayInformation->DpiChanged +=
		//	ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXPage::OnDpiChanged);

		//currentDisplayInformation->OrientationChanged +=
		//	ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXPage::OnOrientationChanged);

		//DisplayInformation::DisplayContentsInvalidated +=
		//	ref new TypedEventHandler<DisplayInformation^, Object^>(this, &DirectXPage::OnDisplayContentsInvalidated);

		//swapChainPanel->CompositionScaleChanged +=
		//	ref new TypedEventHandler<SwapChainPanel^, Object^>(this, &DirectXPage::OnCompositionScaleChanged);

		swapChainPanel.SizeChanged([=](winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::SizeChangedEventArgs const& e) {

			critical_section::scoped_lock lock(m_main->GetCriticalSection());
			m_deviceResources->SetLogicalSize(e.NewSize());
			m_main->CreateWindowSizeDependentResources();

			});
	}






	winrt::hstring MainUserControl::MyProperty()
	{
		return userControl().MyProperty();
	}

	void MainUserControl::MyProperty(winrt::hstring value)
	{
		userControl().MyProperty(value);
	}
}
