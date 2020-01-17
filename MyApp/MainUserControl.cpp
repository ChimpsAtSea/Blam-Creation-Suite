#include "pch.h"
#include "MainUserControl.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;

namespace winrt::MyApp::implementation
{
    MainUserControl::MainUserControl()
    {
        InitializeComponent();

        ::winrt::Windows::UI::Xaml::Controls::SwapChainPanel swapChainPanel = SwapChainPanelControl();

        m_deviceResources = std::make_shared<DX::DeviceResources>();
        m_deviceResources->SetSwapChainPanel(swapChainPanel);


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
