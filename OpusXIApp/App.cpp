#include "pch.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;

namespace winrt::OpusXIApp::implementation
{
    App::App()
    {
        Initialize();

        AddRef();
        m_inner.as<::IUnknown>()->Release();
    }

    App::~App()
    {
        Close();
    }
}
