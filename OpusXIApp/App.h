//
// Declaration of the App class.
//

#pragma once

#include "App.g.h"
#include "App.base.h"

namespace winrt::OpusXIApp::implementation
{
    class App : public AppT2<App>
    {
    public:
        App();
        ~App();
    };
}

namespace winrt::OpusXIApp::factory_implementation
{
    class App : public AppT<App, implementation::App>
    {
    };
}
