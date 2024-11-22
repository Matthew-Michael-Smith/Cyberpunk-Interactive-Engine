#pragma once

#include "CIEngine/Core/Base.h"
#include "CIEngine/Core/Log.h"
#include <filesystem>

#ifdef CIE_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define CIE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CIE##type##ERROR(msg, __VA_ARGS__); CIE_DEBUGBREAK(); } }
	#define CIE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CIE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define CIE_INTERNAL_ASSERT_NO_MSG(type, check) CIE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", CIE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define CIE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define CIE_INTERNAL_ASSERT_GET_MACRO(...) CIE_EXPAND_MACRO( CIE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CIE_INTERNAL_ASSERT_WITH_MSG, CIE_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define CIE_ASSERT(...) CIE_EXPAND_MACRO( CIE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define CIE_CORE_ASSERT(...) CIE_EXPAND_MACRO( CIE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define CIE_ASSERT(...)
	#define CIE_CORE_ASSERT(...)
#endif
