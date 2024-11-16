#pragma once

#ifdef CIE_PLATFORM_WINDOWS
    #ifdef CIE_BUILD_DLL
        #define CIENGINE_API __declspec(dllexport)
    #else
        #define CIENGINE_API __declspec(dllimport)
    #endif
#else
    #error The Cyberpunk Interactive Engine only supports Windows
#endif