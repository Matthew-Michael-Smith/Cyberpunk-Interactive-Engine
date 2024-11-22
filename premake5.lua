workspace "CIEngine"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CIEngine"
	location "CIEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendors/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

	defines
	{
		"CIE_PLATFORM_WINDOWS",
		"CIE_BUILD_DLL"
	}
	
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/DaredevilSOTH")
	}

filter "configurations:Debug"
	defines "CIE_DEBUG"
	symbols "On"

filter "configurations:Release"
	defines "CIE_RELEASE"
	optimize "On"

filter "configurations:Dist"
	defines "CIE_DIST"
	optimize "On"

project "DaredevilSOTH"
	location "DaredevilSOTH"
	kind "ConsoleApp"
	language "C++"

    targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CIEngine/vendors/spdlog/include",
	    "CIEngine/src"
	}

	links
	{
		"CIEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

	defines
	{
		"CIE_PLATFORM_WINDOWS"
	}
	
filter "configurations:Debug"
	defines "CIE_DEBUG"
	symbols "On"

filter "configurations:Release"
	defines "CIE_RELEASE"
	optimize "On"

filter "configurations:Dist"
	defines "CIE_DIST"
	optimize "On"