#pragma once

#include "CIEngine/Core/PlatformDetection.h"

#include <memory>

#ifdef CIE_DEBUG
	#if defined(CIE_PLATFORM_WINDOWS)
		#define CIE_DEBUGBREAK() __debugbreak()
	#elif defined(CIE_PLATFORM_LINUX)
		#include <signal.h>
		#define CIE_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define CIE_ENABLE_ASSERTS
#else
	#define CIE_DEBUGBREAK()
#endif

#define CIE_EXPAND_MACRO(x) x
#define CIE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define CIE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Hazel {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "CIEngine/Core/Log.h"
#include "CIEngine/Core/Assert.h"
