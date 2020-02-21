//
// Declaration of the MainUserControl class.
//

#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "MainUserControl.g.h"

namespace OpusUIPrototype
{
	class OpusUIPrototypeMain;
}

namespace winrt::OpusXIApp::implementation
{
    struct MainUserControl : MainUserControlT<MainUserControl>
    {
        MainUserControl();

		std::shared_ptr<DX::DeviceResources> m_deviceResources;
		std::unique_ptr<OpusUIPrototype::OpusUIPrototypeMain> m_main;

    };
}

namespace winrt::OpusXIApp::factory_implementation
{
    struct MainUserControl : MainUserControlT<MainUserControl, implementation::MainUserControl>
    {
    };
}
